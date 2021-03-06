// LAB09.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Created 12/3/2018 by Noah Fulton
// The goal of this program is to condense a text file and sort it using a map

#include "pch.h"
#include <string>
#include <map>
#include <fstream>
#include <iostream>
using namespace std;

//store the file in a map
void readToMap(ifstream &readFile, map<string, int> &stringMap)
{
	string temp;
	int tally = 0;
	while (readFile)
	{
		readFile >> temp;
		if (stringMap.count(temp) > 0)
		{
			stringMap[temp] += 1;
		}
		else
		{
			stringMap.insert(pair<string, int>(temp, 1));
		}

	}
}

//output the map data
void outputToFile(map<string, int> stringMap)
{
	ofstream myfile;
	myfile.open("Output.txt");
	for (map<string, int>::iterator it = stringMap.begin(); it != stringMap.end(); ++it)
	{
		for (int i = 0; i < it->second; i++)
		{
			myfile << it->first + " ";
		}
	}
}

//test the code
int main()
{
	ifstream myfile;
	myfile.open("example.txt");
	map<string, int> strMap;
	//see if the file opens
	if (!myfile) {
		cout << "Error: unable to open file";
	}
	else
	{
		readToMap(myfile, strMap);
		outputToFile(strMap);
	}
}
