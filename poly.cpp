
#include <iostream>
#include <cstring>
using namespace std;

class Transportation {
  public:
      virtual int getFare() const = 0; // 순수 가상 함수
      virtual ~Transportation() {}
  };



  class Taxi : public Transportation {
    private:
        char companyName[100];
        int totalDistance;
    public:
        Taxi(const char* companyName, int totalDistance) {
            strcpy_s(this->companyName, sizeof(this->companyName), companyName);
            this->totalDistance = totalDistance;
        }

        char* getCompanyName() const {
            return const_cast<char*>(companyName);
        }
        int getFare() const override {
            return totalDistance * 1000;
        }
    };

    class Bus : public Transportation {
      private:
          char companyName[100];
          int numBoarding;
      public:
          Bus(const char* companyName, int numBoarding) {
              strcpy_s(this->companyName, sizeof(this->companyName), companyName);
              this->numBoarding = numBoarding;
          }

          char* getCompanyName() const {
              return const_cast<char*>(companyName);
          }
          int getFare() const override {
              return numBoarding * 1500;
          }
      };


      class CreditCardCompany {
        private:
            Transportation* transportationList[100];
            int numTransportations;
        public:
			CreditCardCompany() : numTransportations(0) {} // 생성자
            ~CreditCardCompany() {
                for (int i = 0; i < numTransportations; i++) {
					delete transportationList[i]; // 동적 할당된 객체 삭제
                }
            }
            void addTransportation(Transportation* transportation) {
                transportationList[numTransportations++] = transportation;
            }
            int getTotalFare() const {
                int totalFare = 0;
                for (int i = 0; i < numTransportations; i++) {
                    totalFare += transportationList[i]->getFare();
                }
                return totalFare;
            }
        };

          int main() {
            CreditCardCompany* pCreditCardCompany = new CreditCardCompany;
            Transportation* pNewTransportation = nullptr;
        
            pNewTransportation = new Taxi("Hongik Taxi", 1200);
            pCreditCardCompany->addTransportation(pNewTransportation);
        
            pNewTransportation = new Taxi("Sangsu Taxi", 2300);
            pCreditCardCompany->addTransportation(pNewTransportation);
        
            pNewTransportation = new Bus("Seogyo Bus", 130);
            pCreditCardCompany->addTransportation(pNewTransportation);
        
            pNewTransportation = new Bus("Donggyo Bus", 220);
            pCreditCardCompany->addTransportation(pNewTransportation);
        
            cout << "Total transportation fare is: " << pCreditCardCompany->getTotalFare() << endl;
        
            delete pCreditCardCompany;
            return 0;
        }