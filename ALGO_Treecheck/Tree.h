#include <iostream>
#include <string>

typedef struct node {
	int value;
	struct node* left;
	struct node* right;
} node;

typedef node* pnode;

class Tree {
public:
	Tree()
		: m_root(nullptr) {};
	~Tree();
	pnode m_root;
	void addNode(int value, pnode& root);
	int getMinimum(pnode root);
	int getMaximum(pnode root);
	double getAverage(pnode root);
	void printTree(pnode root);
	int getAvl(pnode root, bool &isAvl);
private:
	void deleteTree(pnode root);
	pnode createNode(int value);
	int countNodes(pnode root);
	int sumNodes(pnode root);
};