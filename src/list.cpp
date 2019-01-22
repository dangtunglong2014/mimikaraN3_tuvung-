#include "list.h"
#include "node.h"

#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>

list::list(){
	root = NULL;
	top = NULL;
	number = 0;
}

void list::enlist(node* new_node){
	if (root == NULL){
		root = new_node;
		top = new_node;
	}
	else{
		top->setNext(new_node);
		top = top->getNext();
	}
	number++;
	top->setID(number);
}

node* list::randNode(){
	int id = 0;
	srand (time(NULL));
	id = rand()% (number + 1);
	node* itr = root;
	for (int i = 0; i < id; i++){
		itr = itr->getNext();
	} 
	return itr;
}

node* list::getNodeByID(int id){
	if(root == NULL) return NULL;
	node* itr = root;
	do{
		if(itr->getID() == id){
			return itr;
		}
		itr = itr->getNext();
	}while(itr != top->getNext());
	return NULL;
}

void list::round(){
	if(top == NULL) return;
	top->setNext(root);
}
	
void list::unround(){
	if(top == NULL) return;
	top->setNext(NULL);
}
	
void list::display(){
	if(root == NULL){
		std::cout << "EMPTY" << std::endl;
	}
	else{
		node* itr = root;
		do {
			std::cout << itr->getData() << std::endl;
			itr = itr->getNext();
		} while(itr != top->getNext());
	}
}

void list::empty(){
	if (root == NULL) return;
	node* itr = root;
	node* itr_next = root->getNext();
	while(itr_next->getNext() != NULL){
		itr->setNext(itr_next->getNext());
		free(itr_next);
		itr_next = itr->getNext();
	}
	free(root);
}

// void list::test(){
// 	this->display();
// 	node* node1 = new node("node1");
// 	node* node2 = new node("node2");
// 	node* node3 = new node("node3");
// 	node* node4 = new node("node4");
// 	node* node5 = new node("node5");
// 	node* node6 = new node("node6");
// 	this->enlist(node1);
// 	this->enlist(node2);
// 	this->enlist(node3);
// 	this->enlist(node4);
// 	this->enlist(node5);
// 	this->enlist(node6);
// 	this->display();
// 	this->empty();
// 	this->display();
// }
