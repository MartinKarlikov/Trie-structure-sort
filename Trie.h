#pragma once
#include <stack>
#include "helperFunctions.h"

class Trie
{

public:

	Trie();
	~Trie();

	void add(string);

	bool contains(string) const;

	size_t size() const;

	void print() const;

	size_t count()const;

	template<typename T>
	T sortedConvert()const;

private:

	void traverse(void (*action)(string,void*),void*) const;

	int parseChar(char) const;

	char parseIndex(size_t) const;

	struct TrieNode;

	struct TNElement
	{

		TrieNode* next;

		short count;

		short index;

	};

	struct TrieNode
	{

		TrieNode();

		~TrieNode();

		TNElement* container;

	};
	
	void fillStack(TrieNode*, stack<TNElement>&) const;

	TrieNode* root;
};

template<typename T>
inline T Trie::sortedConvert() const
{

	T tempContainer;

	void* containerAdr = &tempContainer;

	traverse(helperAdd<T>, containerAdr);

	return tempContainer;

}
