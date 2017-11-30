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
	printf("\n");
	for (int currentLevel = maxLevel; currentLevel > 0; currentLevel--)
	{

		for (Node* i = head; i != nullptr; i = (*i).forward[currentLevel - 1])
		{
			printf("%d->", (*i).value);
		}
		printf("\n");
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
	Node* newNode = new Node(0, x, level);
	for (int currentLevel = level; currentLevel > 0; currentLevel--)
	{
		for (i = head; i != nullptr && (*i).value < x; i = (*i).forward[currentLevel-1])
		{
			lastNode = i;
		}

		(*newNode).forward[currentLevel - 1] = i;
		(*lastNode).forward[currentLevel - 1] = newNode;
	}

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

		//update head
		(*head).forward.emplace_back(nullptr);
	}

	return abs(level);
}
