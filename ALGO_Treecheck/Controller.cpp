#include "Controller.h"

void Controller::firstTask(/*char** argv*/) {
	readTree(/*argv[1]*/);
	//checkAVL
	// m_tree.printTree(m_tree.m_root);
	printAvl();
	printStatistics();	
}

void Controller::secondTask(char** argv) {
	readTree(/*argv[1]*/);
}

void Controller::readTree(/*std::string filename*/) {
	int tmp[10] = { 5, 3, 17, 9, 23, 54, 11, 79, 30, 12 };
	for(int i = 0; i < 10; ++i) {
		m_tree.addNode(tmp[i], m_tree.m_root);
	}
	
	/*std::string line;
	std::ifstream source(filename);
	if(source.is_open()) {
		while(getline(source, line)) {
			m_tree.addNode(std::stoi(line), m_tree.m_root);
		}
		source.close();
	}
	else {
		std::cout << "File is opened or not existent!" << std::endl;
	}*/
}

void Controller::printAvl() {
	bool isAvl = true;
	m_tree.getAvl(m_tree.m_root, isAvl);
	if (isAvl) {
		std::cout << "AVL: YES" << std::endl;
	}
	else {
		std::cout << "AVL: NO" << std::endl;
	}
}

void Controller::printStatistics() {
	std::cout << "min: " << m_tree.getMinimum(m_tree.m_root) << ", ";
	std::cout << "max: " << m_tree.getMaximum(m_tree.m_root) << ", ";
	std::cout << "avg: " << m_tree.getAverage(m_tree.m_root) << std::endl;
}

void Controller::searchKey() {

}

