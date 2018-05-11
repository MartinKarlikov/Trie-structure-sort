#pragma once
#include <stack>
#include "helperFunctions.h"

class Trie
{

public:

	//default constructor
	Trie();
	
	//destructor - reuses TriNode destructor
	~Trie();
	
	//Adds a given string to the Trie by checking for 
	//already contained prefixes
	//by induction on the string length
	void add(string);

	//checks if a given string is contained
	//in the Trie
	bool contains(string) const;

	//returns the size of the trie
	//in bytes
	size_t size() const;

	//prints the sorted collection of strings
	//that the Trie contains
	void print() const;

	//returns the number of strings contained
	//in the Trie
	size_t count()const;

	//template function returning the collection of strings
	//in sorted order in the container type given to the template
	template<typename T>
	T sortedConvert()const;

private:

	//traverses the Trie with a dfs search 
	//sorting the strings in the Trie through the dfs
	//can be widely reused with the convenience 
	//of pointers to functions - to select what the function does
	//when it finds a contained word
	//and void pointers to specify the container type
	//or it can be given a numerical value to count the contained strings
	void traverse(void (*action)(string,void*),void*) const;

	//returns the index in the TrieNode of the given letter
	int parseChar(char) const;

	//returns the letter to a specified index
	char parseIndex(size_t) const;

	struct TrieNode;

	//the elements that fill the nodes of the Trie
	//each of them has a pointer to the next node(if such exists)
	//the number of times the word is added to the Trie
	//and the index used to build the word through the dfs search
	struct TNElement
	{
		~TNElement();
		
		TrieNode* next;

		short count;

		short index;

	};

	//The actual nodes of the Trie
	//arrays are used so the structure is cache friendly
	struct TrieNode
	{

		TrieNode();

		~TrieNode();

		TNElement* container;

	};

	//fills the stack of the dfs with the significant for the search TNelements
	void fillStack(TrieNode*, stack<TNElement>&) const;

	//size in bytes of the Trie
	size_t sizeInBytes;
	
	//the root of the Trie
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
