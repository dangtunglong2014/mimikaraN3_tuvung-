#ifndef LIST_H
#define LIST_H

#include "node.h"

class list
{
private:
	node* root;
	node* top;
	int number;
public:
	list();
	void enlist(node* new_node);
	node* randNode();
	node* getNodeByID(int id);
	void round();
	void unround();
	void display();
	void empty();
	// void test();
};

#endif
