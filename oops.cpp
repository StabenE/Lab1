#include "stdafx.h"
#include <iostream>
#include <fstream>
using std::ifstream;
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	ifstream file;
	string filename;
	double reallyNotLast = 0,
		sortaNotLast = 0,
		almostLast = 0,
		last = 0,
		inBuff = 0;
	int count = 0;
	cout << "Enter file name:\n";
	cin >> filename;       //store filename
	file.open(filename);   //opens file from stored name
	if (file.is_open())    //test for open file (for testing purposes)
	{
		while (!file.eof())   //ends loop once file is done
		{
			file >> inBuff;  //stores input in temp string
			if (!file.fail())  //checks input for double, ignores if not
			{
				if (count == 0)  //stores first entry in double
				{
					reallyNotLast = inBuff;
				}
				if (count == 1)   //stores seccond entry in double
				{
					sortaNotLast = inBuff;
				}
				almostLast = last;   //stores the entry before current entry, will contain seccond-to-last entry upon end of file
				last = inBuff;       //stores current entry, will contain end upon end of file.
				count++;             //increment count
			}
			else     //clear flags and skips invalid input (white space)
			{
				file.clear();
				file.ignore();  
			}
		}
	}
	file.close();
	cout << "first number: " << reallyNotLast << endl;
	cout << "seccond number: "<<sortaNotLast << endl;
	cout << "seccond to last number: " << almostLast << endl;
	cout << "last number: " << last << endl;
	cout << "number of entries: " << (count);  //prints out all data
}

