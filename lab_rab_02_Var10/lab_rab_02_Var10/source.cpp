#include "BinaryFile.h"
#include <iostream>
using namespace std;

int main()
{
	BinaryFile BFile;//peremennaya file
	BFile.CreateBinaryFile("InputData.txt"); //sozdali
	
	ifstream inFile("InputData.txt", ios::in);//otkruli file
	char * str = new char[50];
	while (!inFile.eof())//vuvod txt file
	{
		
		inFile.getline(str, 50);
		cout << str << endl;
	}

	cout << endl;
	cout << endl;
	cout << endl;

	BFile.Print();//vuvod binary file

	inFile.close();//Close
	return 0;
}