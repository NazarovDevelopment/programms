#include "BinaryFile.h"
#include <vector>
#include <iostream>
#include <math.h>
BinaryFile::BinaryFile(){
	BinaryOutName = "BinFile.txt";	

}
BinaryFile::~BinaryFile(){
}

void BinaryFile::CreateBinaryFile(string InFileName){


	vector<Passenger> passengers;
	ifstream TxtInFile;
	TxtInFile.open(InFileName, ios::in);

	while (!TxtInFile.eof()){
		Passenger passenger;
		TxtInFile >> passenger.FIO;
		TxtInFile >> passenger.M;
		TxtInFile >> passenger.W;
		passengers.push_back(passenger);
	}
	int FullAmount = 0;
	double FullWeight = 0;
	for (int i = 0; i < passengers.size(); i++){
		FullAmount += passengers[i].M;
		FullWeight += passengers[i].W;
	}

	double GeneralAverageWeight = FullWeight / FullAmount;


	ofstream Out("BinFile.txt", ios::binary | ios::out);
	for (int i = 0; i < passengers.size(); i++){
		if (IsTrue(passengers[i], GeneralAverageWeight))
		{
			Out.write((char*)&passengers[i], sizeof(Passenger));
		}
	}

	Out.close();
	TxtInFile.close();
}


bool BinaryFile::IsTrue(Passenger& passenger, double Average){
	double PersonalAverage = passenger.W / passenger.M;

	if (abs(PersonalAverage - Average) <= 0.3)
	{
		return true;
	}
	return false;
}

void BinaryFile::Print(){
	Passenger pas;
	char* str = new char[sizeof(Passenger)];
	ifstream In("BinFile.txt", ios::binary | ios::in);

	In.read((char*)&pas, sizeof(Passenger));

	while (!In.eof()){
		cout << pas.FIO << "\t" << pas.M << "\t" << pas.W << endl;
		In.read((char*)&pas, sizeof(Passenger));
	}
	
}