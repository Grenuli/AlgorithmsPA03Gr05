#include "SkipList.h"
#include <iostream>
#include <ctime>
using namespace std;

SkipList::SkipList(vector<int64_t> const &x)
{
	Node * newNode = new Node(NULL, NULL, 1);

	head = newNode;

	for (int i = 0; i < x.size(); i++)
	{
		insert(x[i]);
	}
	
	for (Node* i = head; i != nullptr; i = (*i).forward[0])
	{
		printf("%d->", (*i).value);
	}
}

size_t SkipList::numElem()
{
	return size_t();
}

bool SkipList::find(int64_t const x)
{
	return false;
}

bool SkipList::insert(int64_t const x)
{
	int level = getRandomLevel();

	printf("%d ", level);

	Node* lastNode;
	Node* i;
	for (i = head; i != nullptr && (*i).value < x; i = (*i).forward[0])
	{
		lastNode = i;
	}

	Node* newNode = new Node(0, x, 1);
	(*newNode).forward[0] = i;
	(*lastNode).forward[0] = newNode;

	return false;
}

bool SkipList::remove(int64_t const x)
{
	return false;
}

int SkipList::getRandomLevel()
{
	int level = 1;

	while ((((double)rand() / RAND_MAX)) < probability &&
		abs(level) < maxLevel) {

		level += 1;
	}

	if (abs(level) == maxLevel) {
		maxLevel = maxLevel++;
	}

	return abs(level);
}
