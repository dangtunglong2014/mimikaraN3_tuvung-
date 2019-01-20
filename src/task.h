#ifndef TASK_H
#define TASK_H

#include "answer.h"
#include "node.h"

class task
{
private:
	int num;
	node* question;
	answer* a;
	answer* b;
	answer* c;
	answer* d;
	answer* getRightAnswer();
public:
	task();
	task(int num, node* question, answer* a, answer* b, answer* c, answer* d);
	int isTrue(char key);
	void ask();
	void remind();
};

#endif
