#ifndef UNIT_H
#define UNIT_H

#include "text_list.h"

#include <string>

class unit 
{
private:
	text_list* list_question;
	text_list* list_answer;
public:
	unit();
	void import(std::string questionFile, std::string answerFile);
	void round();
	void empty();
	void learn();
	void test();
};

#endif
