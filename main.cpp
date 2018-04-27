#include <fstream>
#include "Trie.h"
#include <list>
#include <time.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{

	Trie a;

	vector<string> b;

	ifstream file("words.txt");

	size_t cnt = 0;

	char buff[256];

	while (true)
	{
		
		file.getline(buff, sizeof(buff));

		if (file.eof())
		{
			break;
		}

			a.add(buff);

			b.push_back(buff);

			cnt++;

	}
	file.close();
	cout << "Adding done" << endl;
	cout << "Trie size: "<< a.size() << endl;

	size_t vectorSize = 0;

	for (vector<string>::iterator it = b.begin(); it != b.end(); ++it)
	{
		vectorSize += sizeof(*it);
	}

	cout << "Vector size: " << vectorSize << endl;

	cout << "Currently the test is run with : " << cnt << " words" << endl;

}