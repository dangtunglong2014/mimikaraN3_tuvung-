#include "task.h"
#include "answer.h"
#include "node.h"

#include <iostream>
#include <stdlib.h>
#include <ctime>

answer* task::getRightAnswer(){
	if(a->getRight()) return a;
	else
		if(b->getRight()) return b;
		else 
			if(c->getRight()) return c;
			else
				return d;
}

task::task(){
	num      = 0;
	question = NULL;
	a        = NULL;
	b        = NULL;
	c        = NULL;
	d        = NULL;
}

task::task(int num, node* question, answer* a, answer* b, answer* c, answer* d){
	this->num      = num;
	this->question = question;
	srand (time(NULL));
	int r = rand() % 4 + 1;
	switch(r){
		case 1:
			this->a        = a;
			this->b        = b;
			this->c        = c;
			this->d        = d;
			break;
		case 2:
			this->a        = d;
			this->b        = a;
			this->c        = b;
			this->d        = c;
			break;
		case 3:
			this->a        = c;
			this->b        = d;
			this->c        = a;
			this->d        = b;
			break;
		case 4:
			this->a        = b;
			this->b        = c;
			this->c        = d;
			this->d        = a;
			break;
		default:
			break;
	}
}
int task::isTrue(char key){
	int t = 0;
	switch(key){
		case 'a':
			if(a->getRight()) t = 1;
			break;
		case 'b':
			if(b->getRight()) t = 1;
			break;
		case 'c':
			if(c->getRight()) t = 1;
			break;
		case 'd':
			if(d->getRight()) t = 1;
			break;
		default:
			break;
	}
	return t;
}
void task::ask(){
	std::cout << "問題 " << num << ": " << question->getData() << std::endl;
	std::cout << "a. " << a->getContent()->getData() << std::endl;
	std::cout << "b. " << b->getContent()->getData() << std::endl;
	std::cout << "c. " << c->getContent()->getData() << std::endl;
	std::cout << "d. " << d->getContent()->getData() << std::endl;
	std::cout << "答え(a/b/c/d/q 押してください) "; 
}
void task::remind(){
	std::cout << question->getData() << " は " << this->getRightAnswer()->getContent()->getData() << " です. 覚えてください!" << std::endl;
}
