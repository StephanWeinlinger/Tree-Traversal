#include <iostream>
#include <string>
#include <vector>

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
	int getAvl(pnode root, bool &isAvl);
	pnode searchKey(pnode root, std::vector<int>& searchList, int key);
	pnode searchKeyWithoutList(pnode root, int key);
	int searchSubTree(pnode m_root, pnode sub_root, bool &error);
private:
	void deleteTree(pnode root);
	pnode createNode(int value);
	int countNodes(pnode root);
	int sumNodes(pnode root);
	
	
};