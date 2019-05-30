//=========================================================//
/*
Course      : Programming Fundamentals III (C++) COSC 2336
Name        : Muhammad S Munir
Assignment  : Lab Assiggnment 2
Chapter		: 4
Page		: N/A
Title       : Stack Sort
*/
//==========================================================//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <stack>
#include "StackSort.h"

using namespace std;

string      inputFileNameStr = "stackloader.txt";


int main()
{
	ifstream indata;

	indata.open(inputFileNameStr);
  	if (!indata)
	{
		cout << "The input file does not exist. Program terminates!"
			<< endl;
		return -1;
	}

	stack <uint32_t> processStack;

	do {

		if ( readStackLineFromFile (indata, processStack)) break;

		displayStack (processStack);
		sortStack    (processStack);
		displayStack (processStack);

		system("pause");
		system("cls");
	} while (true);

	indata.close();

	return 0;
}