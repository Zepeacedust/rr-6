#pragma once
class Node
{
private:
	Node* left;
	Node* right;
	int data;
public:
	Node();
	Node(int data);
	bool find(int data);
	bool insert(int data);
	void preOrderPrint();
	void postOrderPrint();
	void inOrderPrint();
	Node* findNode(int data);
	bool deleteNode();
	Node* deleteNode(int key);

};

