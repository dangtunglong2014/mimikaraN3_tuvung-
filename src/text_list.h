#ifndef TEXT_LIST_H
#define TEXT_LIST_H

#include "list.h"
#include <string>

class text_list: public list{
public:
	void import(std::string file_name);
	// void test();
};

#endif
