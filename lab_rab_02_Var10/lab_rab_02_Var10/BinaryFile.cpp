#include "BinaryFile.h"
#include <vector>
BinaryFile::BinaryFile(){
	BinaryOut.open("BinFile.txt", ios::binary | ios::out);

}
BinaryFile::~BinaryFile(){
	BinaryOut.close();
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
		//BinaryOut.write((char*)&passenger,sizeof(Passenger));
	}
	


	TxtInFile.close();
}


bool BinaryFile::IsTrue(Passenger& passenger){

	return true;
}