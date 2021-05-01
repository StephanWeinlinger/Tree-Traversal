#include "Tree.h"

void Tree::addNode(int value, pnode& root) {
	if(root == nullptr) {
		root = createNode(value);
	}
	else if(root->value > value) {
		addNode(value, root->left);
	}
	else if(root->value < value) {
		addNode(value, root->right);
	}
	// Same values don't get inserted!
}

Tree::~Tree() {
	deleteTree(m_root);
}

void Tree::deleteTree(pnode root) {
	if(root != nullptr) {
		if(root->left != nullptr) {
			deleteTree(root->left);
		}
		if(root->right != nullptr) {
			deleteTree(root->right);
		}
		delete root;
	}
}

pnode Tree::createNode(int value) {
	pnode newnode = new node;
	newnode->value = value;
	newnode->left = nullptr;
	newnode->right = nullptr;
	return newnode;
}

int Tree::getMinimum(pnode root) {
	if(root->left == nullptr) {
		return root->value;
	}
	else {
		return getMinimum(root->left);
	}
}

int Tree::getMaximum(pnode root) {
	if(root->right == nullptr) {
		return root->value;
	}
	else {
		return getMaximum(root->right);
	}
}

double Tree::getAverage(pnode root) {
	int count = countNodes(root);
	int sum = sumNodes(root);
	return (double) sum / (double) count;
}

int Tree::sumNodes(pnode root) {
	if(root->left == nullptr && root->right == nullptr) {
		return root->value;
	}
	else if(root->left == nullptr) {
		return root->value + sumNodes(root->right);
	}
	else if(root->right == nullptr) {
		return root->value + sumNodes(root->left);
	}
	return root->value + sumNodes(root->left) + sumNodes(root->right);
}

int Tree::countNodes(pnode root) {
	if(root->left == nullptr && root->right == nullptr) {
		return 1;
	}
	else if(root->left == nullptr) {
		return 1 + countNodes(root->right);
	}
	else if(root->right == nullptr) {
		return 1 + countNodes(root->left);
	}
	return 1 + countNodes(root->left) + countNodes(root->right);
}

void Tree::printTree(pnode root) {
	if(root == nullptr) {
		return;
	}
	if(root->left != nullptr) {
		printTree(root->left);
	}
	std::cout << root->value << std::endl;
	if(root->right != nullptr) {
		printTree(root->right);
	}
}

 int Tree::getAvl(pnode root, bool &isAvl) {
	 {
		 if (root == nullptr)
			 return 0;

		 int left = getAvl(root->left, isAvl);
		 int right = getAvl(root->right, isAvl);

		 int balance = right - left;
		 std::string avlViolation = "";
		 if (balance == 2) {
			avlViolation = " (AVL violation!)";
			isAvl = false;
		 }
		 std::cout << "bal(" << root->value << ") = " << balance << avlViolation << std::endl;
		 return 1 + std::max(left, right);
	 }

	 
}

pnode Tree::searchKey(pnode root, std::vector<int> &searchList, int key)
 {
	if (root == nullptr) {
		searchList.clear();
		return nullptr;
	}
	if (root->value > key) {
		 searchList.push_back(root->value);
		 searchKey(root->left, searchList, key);
	}
	else if (root->value < key) {
		 searchList.push_back(root->value);
		 searchKey(root->right, searchList, key);
	}
	else if (root->value == key) {
		 searchList.push_back(root->value);
		 return root;
	}
	else {
		 searchList.clear();
		 return nullptr;
	}
 }

pnode Tree::searchKeyWithoutList(pnode root, int key)
{
	if (root == nullptr) {
		return nullptr;
	}
	if (root->value > key) {
		searchKeyWithoutList(root->left, key);
	}
	else if (root->value < key) {
		searchKeyWithoutList(root->right, key);
	}
	else if (root->value == key) {
		return root;
	}
	else {
		return nullptr;
	}
}

/*
pnode Tree::searchSubTree(pnode m_root, pnode sub_root) {

	if (m_root == nullptr || sub_root == nullptr) {
		return nullptr;
	}

	if (m_root->value == sub_root->value) {
		searchSubTree(m_root->left, sub_root->left);
		searchSubTree(m_root->right, sub_root->right);
	}
	searchSubTree(searchKeyWithoutList(m_root, sub_root->value), sub_root);
} */