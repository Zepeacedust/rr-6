#include "BinTree.h"
#include <iostream>
BinTree::BinTree() 
{
	this->Root = nullptr;
}
bool BinTree::find(int data) 
{
	if (this->Root == nullptr) return false;
	return this->Root->find(data);
}
bool BinTree::insert(int data)
{
	if (this->Root == nullptr) { 
		this->Root = new Node(data);
		return true;
	}
	return this->Root->insert(data);
}
void BinTree::preOrderPrint()
{
	if (this->Root == nullptr)
	{
		std::cout << "empty list" << std::endl;
		return;
	}
	this->Root->postOrderPrint();
	std::cout << std::endl;
}
void BinTree::postOrderPrint()
{
	if (this->Root == nullptr) 
	{
		std::cout << "empty list" << std::endl; 
		return;
	}
	this->Root->postOrderPrint();
	std::cout << std::endl;
}
void BinTree::inOrderPrint()
{
	if (this->Root == nullptr)
	{
		std::cout << "empty list" << std::endl;
		return;
	}
	this->Root->inOrderPrint();
	std::cout << std::endl;
}
bool BinTree::deleteNode(int data)
{
	this->Root->deleteNode(data);
	return true;
}