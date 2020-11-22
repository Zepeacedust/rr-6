#include "Node.h"
#include <iostream>
Node::Node() 
{
	this->left = nullptr;
	this->right = nullptr;
	this->data = 0;
}
Node::Node(int data)
{
	this->left = nullptr;
	this->right = nullptr;
	this->data = data;
}
bool Node::find(int data) 
{
	if (data > this->data)
	{
		if (this->right == nullptr)
			return false;
		else
			return this->right->find(data);
	}
	else if (data < this->data) 
	{
		if (this->left == nullptr)
			return false;
		else
			return this->left->find(data);
	}
	return true;
}
bool Node::insert(int data)
{
	if (data > this->data)
	{
		if (this->right == nullptr) 
		{
			this->right = new Node(data);
			return true;
		}
		else 
		{
			return this->right->insert(data);
		}
	} else if (this->left == nullptr)
	{
		this->left = new Node(data);
		return true;
	}
	else
	{
		return this->left->insert(data);
	}
	return false;
}
Node* Node::findNode(int data) 
{
	if (data > this->data)
	{
		if (this->right == nullptr)
			return nullptr;
		else
			return this->right->findNode(data);
	}
	else if (data < this->data)
	{
		if (this->left == nullptr)
			return nullptr;
		else
			return this->left->findNode(data);
	}
	return this;
}
/*bool Node::deleteNode()
{
	if (this->left != nullptr && this->right != nullptr) 
	{
		Node* op = this->left;
		Node* parent = this;
		while (op->right != nullptr) 
		{
			parent = op;
			op = op->right;
		}
		this->data = op->data;
		if (op->left == nullptr) 
		{
			delete op;
			parent->right = nullptr;
			return true;
		} else 
		{
			parent->right = op->left;
			delete op;
			return true;
		}
	}
	Node* op = nullptr;
	if (this->left != nullptr) { op = this->left; }
	else if (this->right != nullptr) { op = this->right; }
	this->data = op->data;
	this->left = op->left;
	this->right = op->right;
	delete op;
	return true;
}*/

Node* Node::deleteNode(int key) 
{
	if (key > this->data)
	{
		if (this->right == nullptr)
			return false;
		else
			this->right = this->right->deleteNode(key);
	}
	else if (key < this->data)
	{
		if (this->left == nullptr)
			return false;
		else
			this->left = this->left->deleteNode(key);
	}else {
		// node with only one child or no child
		if (this->left == nullptr) {
			Node* temp = this->right;
			delete this;
			return temp;
		}
		else if (this->right == nullptr) {
			Node* temp = this->left;
			delete this;
			return temp;
		}

		// node with two children: Get the inorder successor
		// (smallest in the right subtree)
		Node* temp = this->right;
		while (temp->left != nullptr) temp = temp->left;

		// Copy the inorder successor's content to this node
		this->data = temp->data;

		// Delete the inorder successor
		this->right = this->right->deleteNode(temp->data);
	}
	return this;
}


void Node::preOrderPrint() 
{
	std::cout << this->data << " ";
	if (this->left != nullptr) this->left->preOrderPrint();
	if (this->right != nullptr)this->right->preOrderPrint();
}
void Node::postOrderPrint() 
{
	if (this->left != nullptr) this->left->postOrderPrint();
	if (this->right != nullptr)this->right->postOrderPrint();
	std::cout << this->data << " ";
}
void Node::inOrderPrint()
{
	if (this->left != nullptr) this->left->inOrderPrint();
	std::cout << this->data << " ";
	if (this->right != nullptr)this->right->inOrderPrint();
}