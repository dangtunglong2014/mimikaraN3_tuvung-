#include "answer.h"
#include "node.h"

answer::answer(){
	content = NULL;
	right   = 0;
}
answer::answer(node* content, int right){
	this->content = content;
	this->right   = right;
}
int answer::getRight(){
	return right;
}
node* answer::getContent(){
	return content;
}
