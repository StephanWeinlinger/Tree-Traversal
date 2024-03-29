#include "Controller.h"

void Controller::firstTask(char** argv) {
	printLogo();
	readTree(argv[1], m_tree);
	if(m_tree.m_root != nullptr) {
		printAvl();
		printStatistics();
	}
	else {
		std::cout << "File is empty!" << std::endl;
	}
}

void Controller::secondTask(char** argv) {
	printLogo();
	readTree(argv[1], m_tree);
	readTree(argv[2], sub_tree);
	if(m_tree.m_root != nullptr && sub_tree.m_root != nullptr) {
		if(this->sub_tree.m_root->left == nullptr && this->sub_tree.m_root->right == nullptr) {
			printKeySearch();
		}
		else {
			printSubTreeSearch();
		}
	}
	else {
		std::cout << "At least one file is empty!" << std::endl;
	}
}

void Controller::printLogo() {
	std::cout << "\n"
		"  _____                 ____ _               _    \n"
		" |_   _| __ ___  ___   / ___| |__   ___  ___| | __\n"
		"   | || '__/ _ \\/ _ \\ | |   | '_ \\ / _ \\/ __| |/ /\n"
		"   | || | |  __/  __/ | |___| | | |  __/ (__|   < \n"
		"   |_||_|  \\___|\\___|  \\____|_| |_|\\___|\\___|_|\\_\\\n"
		"                                                  " << std::endl << std::endl;
}

void Controller::readTree(std::string filename, Tree& tree) {
	std::string line;
	std::ifstream source(filename);
	if(source.is_open()) {
		while(getline(source, line)) {
			tree.addNode(std::stoi(line), tree.m_root);
		}
		source.close();
	}
	else {
		std::cout << "File is opened or not existent!" << std::endl;
	}
}

void Controller::tempReadSubTree(Tree& tree) {
	int tmp[1] = {100};
	for(int i = 0; i < 1; ++i) {
		tree.addNode(tmp[i], tree.m_root);
	}
}

void Controller::printAvl() {
	bool isAvl = true;
	std::cout << "Calculate balance:" << std::endl;
	m_tree.getAvl(m_tree.m_root, isAvl);
	std::cout << std::endl << "AVL: " << std::endl;
	if (isAvl) {
		std::cout << " -> YES" << std::endl;
	}
	else {
		std::cout << " -> NO" << std::endl;
	}
}

void Controller::printStatistics() {
	std::cout << "==============================" << std::endl;
	std::cout << "Stats:" << std::endl;
	std::cout << " -> ";
	std::cout << "min: " << m_tree.getMinimum(m_tree.m_root) << ", ";
	std::cout << "max: " << m_tree.getMaximum(m_tree.m_root) << ", ";
	std::cout << "avg: " << m_tree.getAverage(m_tree.m_root) << std::endl;
}

void Controller::printKeySearch() {

	if (this->sub_tree.m_root == nullptr) {
		return;
	}

	std::cout << "==============================" << std::endl;
	std::cout << "Search key:" << std::endl;
	int key = this->sub_tree.m_root->value;
	std::vector<int> searchList;
	pnode searchedKey = m_tree.searchKey(m_tree.m_root, searchList, key);

	if (searchList.empty()) {
		std::cout << " -> " << key << " not found!" << std::endl;
	}
	else {
		std::cout << " -> " << searchedKey->value << " found ";
		for (unsigned int i = 0; i < searchList.size(); i++) {
			if (i == 0)
				std::cout << searchList[i];
			else
				std::cout << ", " << searchList[i];
		}	
		std::cout << std::endl;
	}
	
}


void Controller::printSubTreeSearch() {
	std::cout << "==============================" << std::endl;
	std::cout << "Search SubTree:" << std::endl;
	pnode searchedKey = m_tree.searchKeyWithoutList(m_tree.m_root, sub_tree.m_root->value);
	if (searchedKey == nullptr) {
		std::cout << " -> First Node not found" << std::endl;
	}
	else {
		bool error = false;
		m_tree.searchSubTree(searchedKey, this->sub_tree.m_root, error);
		std::cout << " -> SubTree";
		if (error) {
			std::cout << " not";
		}
		std::cout << " found" << std::endl;
	}
	std::cout << "==============================" << std::endl;
}