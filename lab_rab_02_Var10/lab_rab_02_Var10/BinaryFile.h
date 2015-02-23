#pragma once

#include <fstream>

using namespace std;

//obyavlenie structure passagir
struct Passenger
{
	char FIO[30];	//name
	int M;			//kolichestvo veshey
	double W;		//obshiy ves
};


//class kotoruy otvechaet za rabotu s binarnum faylom
class BinaryFile{
private:
	string BinaryOutName; //name binary file
public:
	BinaryFile(); //constructor
	~BinaryFile();//destructor
	
	void CreateBinaryFile(string InFileName); // function kotoraya sozdaet i zapolnyaet binary file
	void Print();//vuvod binary file

private:
	bool IsTrue(Passenger& passenger, double Average); //proverka na uslovie
};