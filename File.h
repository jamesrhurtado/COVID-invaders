#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>

using namespace System;
using namespace std;


class File
{
private:
	ofstream fileWrite;
	ifstream fileRead;
	string text;

public:
	File();
	void writeData(vector<string> data);
	vector<string> readData();

};

