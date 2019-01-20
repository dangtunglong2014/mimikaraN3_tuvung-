#ifndef NODE_H
#define NODE_H

#include <string>

class node
{
private:
	std::string data;
	int id;
	node* next;
public:
	node();
	node(std::string data);
	std::string getData();
	int getID();
	node* getNext();
	void setData(std::string data);
	void setID(int id);
	void setNext(node* next);
	void display();
};

#endif
