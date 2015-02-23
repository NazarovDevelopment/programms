#pragma once

#include <fstream>

using namespace std;

struct Passenger
{
	char FIO[30];
	int M;
	double W;
};



class BinaryFile{
private:
	ofstream BinaryOut;
public:
	BinaryFile();
	~BinaryFile();
	
	void CreateBinaryFile(string InFileName);


private:
	bool IsTrue(Passenger passenger);
};