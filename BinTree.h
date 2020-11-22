#pragma once
#include "Node.h"
class BinTree
{
public:
	BinTree();
	bool find(int data);
	bool insert(int data);
	void preOrderPrint();
	void postOrderPrint();
	void inOrderPrint();
	bool deleteNode(int data);


	Node* Root;
};

