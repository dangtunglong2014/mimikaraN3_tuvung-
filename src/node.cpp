#include "node.h"

#include <iostream>
#include <string>

node::node(){
	data = "";
	id = 0;
	next = NULL;
}
node::node(std::string data){
	this->data = data;
	this->next = NULL;
}
std::string node::getData(){
	return data;
}
int node::getID(){
	return id;
}
node* node::getNext(){
	return next;
}
void node::setData(std::string data){
	this->data = data;
}
void node::setID(int id){
	this->id = id;
}
void node::setNext(node* next){
	this->next = next;
}
void node::display(){
	std::cout << data << std::endl;
}
