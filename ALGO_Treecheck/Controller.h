#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "Tree.h"

class Controller {
public:
	void firstTask(/*char **argv*/);
	void secondTask(char **argv);
private:
	Tree m_tree;
	void readTree(/*std::string filename*/);
	void printStatistics();
};
