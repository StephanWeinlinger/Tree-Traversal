#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Tree.h"

class Controller {
public:
	void firstTask(/*char **argv*/);
	void secondTask(char **argv);
private:
	Tree m_tree;
	Tree sub_tree;
	void readTree(/*std::string filename*/ Tree &tree);
	void printStatistics();
	void printAvl();
	void printKeySearch(int key);
	void printSubTreeSearch(std::vector<int>& subTree);
};
