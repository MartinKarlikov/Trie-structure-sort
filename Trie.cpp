#include "Trie.h"

Trie::Trie()
{

	root = new TrieNode;

}

Trie::~Trie()
{

	delete root;

}

void Trie::add(string toAdd)
{

	char letter = parseChar(toAdd[0]);

	TrieNode* current = root;

	while (toAdd.size() > 0)
	{

		letter = parseChar(toAdd[0]);

		if (toAdd.size() == 1)
		{

			current->container[letter].count++;
			return;

		}

		if (current->container[letter].next == nullptr)
		{

			current->container[letter].next = new TrieNode;

		}

		toAdd.erase(0, 1);

		current = current->container[letter].next;
	}

}

void Trie::traverse(void(*action)(string, void*), void* container) const
{

	stack<TNElement> dfsStack;

	string cString;

	fillStack(root, dfsStack);

	TNElement current;

	while (!dfsStack.empty())
	{

		current = dfsStack.top();
		dfsStack.pop();

		if (current.index == 52 && cString.size() != 0)
		{

			cString.erase(cString.size() - 1, 1);
			continue;

		}

		cString.append(1, parseIndex(current.index));

		for (int i = current.count; i > 0; --i)
		{

			action(cString, container);

		}

		if (current.next != nullptr)
		{

			fillStack(current.next, dfsStack);

		}

		else
		{
			cString.erase(cString.size() - 1, 1);
		}

	}

}

bool Trie::contains(string str) const
{
	int index = parseChar(str[0]);

	TNElement current = root->container[index];

	while (str.size() > 1)
	{

		if (current.next == nullptr)
		{

			return false;

		}

		str.erase(0, 1);

		index = parseChar(str[0]);

		current = current.next->container[index];

	}

	return current.count > 0;
}

size_t Trie::size() const
{
	stack<TNElement> stack;
	size_t size=0;
	TNElement current;

	fillStack(root, stack);

	while (!stack.empty())
	{
		current = stack.top();
		stack.pop();
		if (current.next)
		{
			fillStack(current.next, stack);
		}
		size += sizeof(current);
	}
	return size;
}


void Trie::print() const
{
	void(*printFunc)(string, void*) = helperPrint;
	traverse(printFunc, nullptr);
}



size_t Trie::count() const
{
	size_t count = 0;

	void* countAdr = &count;

	traverse(countHelper, countAdr);

	return count;

}

int Trie::parseChar(char toParse) const
{
	return (toParse >= 'A' && toParse <= 'Z') ?
		(int)toParse - 65 :
		(int)toParse - 71;
}

char Trie::parseIndex(size_t index) const
{
	return (index >= 0 && index <= 25) ?
		(char)index + 65 : 
		(char)index + 71;
}


void Trie::fillStack(TrieNode * current, stack<TNElement>& stack) const
{
	TNElement temp;

	for (int i = 52; i >= 0; --i)
	{

		temp = current->container[i];

		if (temp.next != nullptr || temp.count != 0 || temp.index == 52)
		{

			stack.push(current->container[i]);

		}

	}

}

Trie::TrieNode::TrieNode()
{
	container = new TNElement[53];

	for (size_t i = 0; i <= 52; i++)
	{

		container[i].index = i;
		container[i].next = nullptr;
		container[i].count = 0;

	}
}

Trie::TrieNode::~TrieNode()
{

	delete[] container;

}

