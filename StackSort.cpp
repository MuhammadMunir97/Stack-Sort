#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <stack>
#include "StackSort.h"

using namespace std;

bool readStackLineFromFile (ifstream & fileStreamObj, stack<uint32_t> & inputStack)
{
	const bool EOF_ENCOUNTERED = true, MORE_DATA = false;

	while (!inputStack.empty()) inputStack.pop();

	string inputLineStr;

	if (getline(fileStreamObj, inputLineStr))
	{
		istringstream lineStringStream(inputLineStr);
		for (uint32_t i; lineStringStream >> i; inputStack.push(i));
		return MORE_DATA;
	}

	return EOF_ENCOUNTERED;
}

void copyDeepStack(stack <uint32_t> & sourceStack, stack <uint32_t> & destinationStack)
{
	stack <uint32_t> transferStack;
	while (!(destinationStack.empty()))  destinationStack.pop();
	while (!(sourceStack.empty())) { transferStack.push(sourceStack.top()); sourceStack.pop(); }
	while (!(transferStack.empty()))
	{
		sourceStack.push(transferStack.top());
		destinationStack.push(transferStack.top());
		transferStack.pop();
	}
}

void displayStack(stack <uint32_t> & stackInt)
{
	stack <uint32_t> displayStack;

	copyDeepStack(stackInt, displayStack);

	while (!(displayStack.empty()))
	{
		cout << setw(3) << setfill('0') << displayStack.top() << " ";
		displayStack.pop();
	}
	cout << string(2, '\n');
}

void sortStack(stack <uint32_t> & stackInt)
{
	if (stackInt.empty()) return;

	
	stack <uint32_t>  sortedStackInt;
	uint32_t compareValue;

	sortedStackInt.push(stackInt.top()); stackInt.pop();
	
	while (!stackInt.empty())
	{
		compareValue = stackInt.top(); 
		stackInt.pop();
		while ((!sortedStackInt.empty()) && (compareValue > sortedStackInt.top()))
		{
			stackInt.push(sortedStackInt.top());
			sortedStackInt.pop();
		}
		sortedStackInt.push(compareValue);
	}
	copyDeepStack(sortedStackInt, stackInt);
	
}
