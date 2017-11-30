#pragma once
#include <vector>

using namespace std;

struct Node {
	int key;
	int64_t value;

	//pointers to successor nodes
	vector<Node*> forward;

	Node(int k, int64_t v, int level) :
		key(k), value(v), forward(level, nullptr)
	{}
};

class SkipList
{
public:
	SkipList(vector<int64_t> const &x);
	size_t numElem();
	bool find(int64_t const x);
	bool insert(int64_t const x);
	bool remove(int64_t const x);

	int getRandomLevel();

private:
	// pointer to first node
	Node* head;
	// last node
	Node* NIL;

	// data members  
	float probability = 0.5;
	int maxLevel = 1;
};
