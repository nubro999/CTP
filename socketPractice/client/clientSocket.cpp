#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iomanip>
#pragma comment(lib, "ws2_32.lib")
using namespace std;

char* encryptBytes(const char* input, const char* key);
char* decryptBytes(const char* input, const char* key, size_t length);
void printMenu();
void printEncryptedBytes(const char* data, size_t length);
string bytesToHex(const char* data, size_t length);
vector<char> hexToBytes(const string& hex);

int main() {
  // 1. Winsock 초기화
  WSADATA wsaData;
  const char* key = "nubroo";
  
  int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
  if (result != 0) {
      cerr << "WSAStartup failed: " << result << endl;
      return 1;
  }
  cout << "Winsock initialized successfully!" << endl;

  // 2. 클라이언트 소켓 생성
  SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (clientSocket == INVALID_SOCKET) {
      cerr << "Socket creation failed" << endl;
      WSACleanup();
      return 1;
  }
  cout << "Client socket created!" << endl;

  // 3. 서버 주소 설정
  sockaddr_in serverAddr;
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(8080);
  
  if (inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr) <= 0) {
      cerr << "Invalid address" << endl;
      closesocket(clientSocket);
      WSACleanup();
      return 1;
  }

  // 4. 서버에 연결
  cout << "Connecting to server..." << endl;
  if (connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
      cerr << "Connection failed with error: " << WSAGetLastError() << endl;
      closesocket(clientSocket);
      WSACleanup();
      return 1;
  }
  cout << "Connected to server successfully!" << endl;
  cout << "=== Connection established ===" << endl;

  // 5. 지속적 메시지 송수신
  string message;
  char buffer[1024];
  bool connected = true;
  
  printMenu();
  
  while (connected) {
      cout << "\n> ";
      if (!getline(cin, message)) {
          cout << "\nInput stream closed. Exiting..." << endl;
          break;
      }
      
      // 명령어 처리
      if (message == "quit" || message == "exit") {
          cout << "Disconnecting from server..." << endl;
          send(clientSocket, "quit", 4, 0);
          break;
      }
      else if (message == "help" || message == "?") {
          printMenu();
          continue;
      }
      else if (message == "clear" || message == "cls") {
          system("cls");
          printMenu();
          continue;
      }
      else if (message.substr(0, 8) == "encrypt ") {
          // encrypt 명령어: "encrypt hello world"
          string textToEncrypt = message.substr(8);
          if (!textToEncrypt.empty()) {
              char* encrypted = encryptBytes(textToEncrypt.c_str(), key);
              if (encrypted) {
                  cout << "Original: " << textToEncrypt << endl;
                  cout << "Encrypted (raw): ";
                  printEncryptedBytes(encrypted, textToEncrypt.length());
                  cout << endl;
                  cout << "Encrypted (hex): " << bytesToHex(encrypted, textToEncrypt.length()) << endl;
                  delete[] encrypted;
              } else {
                  cout << "Encryption failed!" << endl;
              }
          } else {
              cout << "Usage: encrypt <message>" << endl;
          }
          continue;
      }
      else if (message.substr(0, 8) == "decrypt ") {
          // decrypt 명령어: 16진수 문자열로 입력받기
          string hexInput = message.substr(8);
          if (!hexInput.empty()) {
              try {
                  vector<char> encryptedBytes = hexToBytes(hexInput);
                  if (!encryptedBytes.empty()) {
                      char* decrypted = decryptBytes(encryptedBytes.data(), key, encryptedBytes.size());
                      if (decrypted) {
                          cout << "Encrypted (hex): " << hexInput << endl;
                          cout << "Decrypted: " << string(decrypted, encryptedBytes.size()) << endl;
                          delete[] decrypted;
                      } else {
                          cout << "Decryption failed!" << endl;
                      }
                  } else {
                      cout << "Invalid hex format!" << endl;
                  }
              } catch (const exception& e) {
                  cout << "Error parsing hex: " << e.what() << endl;
              }
          } else {
              cout << "Usage: decrypt <hex_string>" << endl;
              cout << "Example: decrypt 020e0c0c0f1f13" << endl;
          }
          continue;
      }
      else if (message.empty()) {
          continue;
      }

      // 일반 메시지를 서버로 전송
      cout << "Sending to server: " << message << endl;
      int bytesSent = send(clientSocket, message.c_str(), message.length(), 0);
      if (bytesSent == SOCKET_ERROR) {
          cerr << "Send failed with error: " << WSAGetLastError() << endl;
          connected = false;
          break;
      }

      // 서버로부터 응답 받기
      int bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
      if (bytesReceived > 0) {
          cout << "Server encrypted response (raw): ";
          printEncryptedBytes(buffer, bytesReceived);
          cout << endl;
          cout << "Server encrypted response (hex): " << bytesToHex(buffer, bytesReceived) << endl;
          
          // 서버 응답 복호화
          char* decrypted = decryptBytes(buffer, key, bytesReceived);
          if (decrypted) {
              cout << "Decrypted response: " << string(decrypted, bytesReceived) << endl;
              delete[] decrypted;
          } else {
              cout << "Failed to decrypt server response" << endl;
          }
      }
      else if (bytesReceived == 0) {
          cout << "Server disconnected" << endl;
          connected = false;
      }
      else {
          cerr << "Recv failed with error: " << WSAGetLastError() << endl;
          connected = false;
      }
  }

  // 6. 정리
  closesocket(clientSocket);
  WSACleanup();
  cout << "Client disconnected and cleaned up" << endl;
  return 0;
}

void printMenu() {
  cout << "\n=== Encrypted Chat Client ===" << endl;
  cout << "Commands:" << endl;
  cout << "  help, ?           - Show this menu" << endl;
  cout << "  encrypt <msg>     - Encrypt a message locally" << endl;
  cout << "  decrypt <hex>     - Decrypt hex string (e.g., 020e0c0c0f)" << endl;
  cout << "  clear, cls        - Clear screen" << endl;
  cout << "  quit, exit        - Disconnect and exit" << endl;
  cout << "  <any message>     - Send to server (will be encrypted)" << endl;
  cout << "=============================" << endl;
}

void printEncryptedBytes(const char* data, size_t length) {
  cout << "\"";
  for (size_t i = 0; i < length; i++) {
      unsigned char byte = static_cast<unsigned char>(data[i]);
      if (byte >= 32 && byte <= 126) {
          cout << static_cast<char>(byte);
      } else {
          cout << "\\x" << hex << setfill('0') << setw(2) << static_cast<int>(byte) << dec;
      }
  }
  cout << "\"";
}

string bytesToHex(const char* data, size_t length) {
  stringstream ss;
  ss << hex << setfill('0');
  for (size_t i = 0; i < length; i++) {
      ss << setw(2) << static_cast<unsigned char>(data[i]);
  }
  return ss.str();
}

vector<char> hexToBytes(const string& hex) {
  vector<char> bytes;
  
  // 공백 제거
  string cleanHex;
  for (char c : hex) {
      if (c != ' ' && c != '\t' && c != '\n') {
          cleanHex += c;
      }
  }
  
  // 홀수 길이면 앞에 0 추가
  if (cleanHex.length() % 2 != 0) {
      cleanHex = "0" + cleanHex;
  }
  
  for (size_t i = 0; i < cleanHex.length(); i += 2) {
      string byteString = cleanHex.substr(i, 2);
      char byte = static_cast<char>(strtol(byteString.c_str(), nullptr, 16));
      bytes.push_back(byte);
  }
  
  return bytes;
}

char* encryptBytes(const char* input, const char* key) {
  if (!input || !key) {
      cerr << "Error: input or key is null" << endl;
      return nullptr;
  }
  
  size_t inputLen = strlen(input);
  size_t keyLen = strlen(key);
  
  if (inputLen == 0 || keyLen == 0) {
      cerr << "Error: input or key is empty" << endl;
      return nullptr;
  }
  
  char* result = new char[inputLen + 1];
  
  for (size_t i = 0; i < inputLen; ++i) {
      result[i] = input[i] ^ key[i % keyLen];
  }
  result[inputLen] = '\0';
  
  return result;
}

char* decryptBytes(const char* input, const char* key, size_t length) {
  if (!input || !key) {
      cerr << "Error: input or key is null" << endl;
      return nullptr;
  }
  
  size_t keyLen = strlen(key);
  
  if (length == 0 || keyLen == 0) {
      cerr << "Error: input or key is empty" << endl;
      return nullptr;
  }
  
  char* result = new char[length + 1];
  
  for (size_t i = 0; i < length; ++i) {
      result[i] = input[i] ^ key[i % keyLen];
  }
  result[length] = '\0';
  
  return result;
}