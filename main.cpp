#include "BinTree.h" 
#include <iostream>
int main () 
 {

	BinTree tree = BinTree();
	tree.postOrderPrint();
	tree.insert(11);
	tree.insert(12);
	tree.insert(10);
	tree.insert(16);
	tree.insert(1);
	tree.insert(5);
	tree.insert(7);
	tree.insert(4);
	tree.inOrderPrint();
	tree.deleteNode(5);
	tree.inOrderPrint();

 }