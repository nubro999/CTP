#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>  // strlen을 위해 추가
#pragma comment(lib, "ws2_32.lib")
using namespace std;

char* encryptBytes(const char* input, const char* key);
// Function prototype for encryptBytes
int main() {
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);

    if (result != 0) {
        cerr << "WSAStartup failed with error: " << result << endl;
        return 1;
    } cout << "WSAStartup successful" << endl;

    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == INVALID_SOCKET) {
        cerr << "Socket creation failed with error: " << WSAGetLastError() << endl;
        WSACleanup();
        return 1;
    } cout << "Socket created successfully" << endl;

    //주소 설정
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        cerr << "Bind failed with error: " << WSAGetLastError() << endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    } cout << "Bind successful" << endl;


    //리슨
    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        cerr << "Listen failed with error: " << WSAGetLastError() << endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }   cout << "Listening for connections..." << endl;


    // 클라이언트 연결 대기
    while (true) {
    std::cout << "Waiting for client connection..." << std::endl;
    
    // 클라이언트 정보를 받기 위한 구조체
    sockaddr_in clientAddr;
    int clientAddrSize = sizeof(clientAddr);
    
    SOCKET clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &clientAddrSize);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Accept failed" << std::endl;
        continue;
    }

    char clientIP[INET_ADDRSTRLEN]; // 클라이언트 IP 주소를 저장할 버퍼
      inet_ntop(AF_INET, &clientAddr.sin_addr, clientIP, INET_ADDRSTRLEN); // IP 주소 문자열로 변환
      std::cout << "Client connected from " << clientIP 
                << ":" << ntohs(clientAddr.sin_port) << std::endl; // 클라이언트 IP와 포트 출력
    // 메세지 송수신
    char buffer[1024];
      bool clientConnected = true;
      
      while (clientConnected) {
          int bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
          
          if (bytesReceived > 0) {
              buffer[bytesReceived] = '\0';
              cout << "Received message: " << buffer << endl;
              
              // 종료 명령 확인
              if (strcmp(buffer, "quit") == 0) {
                  cout << "Client requested disconnect" << endl;
                  break;
              }
              
              // 메시지 암호화
              char* encryptedBuffer = encryptBytes(buffer, "nubroo");
              if (encryptedBuffer) {
                  int sendResult = send(clientSocket, encryptedBuffer, bytesReceived, 0);
                  if (sendResult == SOCKET_ERROR) {
                      cerr << "Send failed with error: " << WSAGetLastError() << endl;
                      delete[] encryptedBuffer;
                      break;
                  }
                  cout << "Sent encrypted message back to client" << endl;
                  delete[] encryptedBuffer;
              } else {
                  cerr << "Encryption failed" << endl;
                  break;
              }
          }
          else if (bytesReceived == 0) {
              cout << "Client disconnected gracefully" << endl;
              clientConnected = false;
          }
          else {
              cerr << "Receive failed with error: " << WSAGetLastError() << endl;
              clientConnected = false;
          }
      }
      
      // 클라이언트 소켓 닫기 (중요!)
      cout << "Closing client connection" << endl;
      closesocket(clientSocket);
  }

    // 소켓 닫기
    closesocket(serverSocket);
    WSACleanup(); // Winsock 정리
    return 0;
}

char* encryptBytes(const char* input, const char* key) {
  if (!input || !key) {
      std::cerr << "Error: input or key is null" << std::endl;
      return nullptr;
  }
  
  size_t inputLen = strlen(input);
  size_t keyLen = strlen(key);
  
  if (inputLen == 0 || keyLen == 0) {
      std::cerr << "Error: input or key is empty" << std::endl;
      return nullptr;
  }
  
  char* result = new char[inputLen + 1];
  
  for (size_t i = 0; i < inputLen; ++i) {
      result[i] = input[i] ^ key[i % keyLen];
  }
  result[inputLen] = '\0';
  
  return result;
}




