#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <stack>
using namespace std;

bool readStackLineFromFile (ifstream & fileStreamObj, stack<uint32_t> & inputStack);
void copyDeepStack(stack <uint32_t> & sourceStack, stack <uint32_t> & destinationStack);
void displayStack(stack <uint32_t> & stackInt);
void sortStack(stack <uint32_t> & stackInt);

