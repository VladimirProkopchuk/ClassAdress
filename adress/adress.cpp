#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class adress {
private:
	string town;
	string street;
	int number_house;
	int number_apartament;
public:
	adress() {}
	adress(string _town, string _street, int _numberHouse, int _numberApartament) : town(_town), street(_street), number_house(_numberHouse), number_apartament(_numberApartament){}
	string getOutAdress() {
		return town + " " + street + " " + std::to_string(number_house) + " " + std::to_string(number_apartament);
	}
};


int main() {
	setlocale(LC_ALL, "russian");
	ifstream file("in.txt");
	 int n;
	 if (!file.is_open()) {
		 cout << "ERROR!" << endl;
		 return 1;
	 }
		 int number;
		 file >> number;
		 adress* adressList = new adress[number];
		 string town; string street;
		 int numberHouse; int numberApartament;
		 
		 for (int i = 0; i < number; i++) {
			 file >> town >> street >> numberHouse >> numberApartament;
			 adressList[i] = adress (town,street,numberHouse,numberApartament) ;
		 }
		 ofstream outFile("out.txt");
		 for (int i = (number-1); i >=0 ; i--) {
			 outFile << adressList[i].getOutAdress() << endl;
		 }
		 return 0;
		 delete[] adressList;
	}