#pragma once
#include <string>
#include <iostream>
using namespace std;

namespace
{
	void helperPrint(string toPrint, void* sample)
	{
		cout << toPrint << endl;
	}

	void countHelper(string arbitrary, void* count)
	{
		*((size_t*)count) += 1;
	}

	template<typename T>
	void helperAdd(string toAdd, void* container)
	{
		static_cast<T*>(container)->push_back(toAdd);
	}
}
