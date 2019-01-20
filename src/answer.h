#ifndef ANSWER_H
#define ANSWER_H

#include "node.h"

class answer
{
private:
	node* content;
	int right;
public:
	answer();
	answer(node* content, int right);
	int getRight();
	node* getContent();
};

#endif
