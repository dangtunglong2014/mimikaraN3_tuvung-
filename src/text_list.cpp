#include "text_list.h"
#include "list.h"

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

void text_list::import(std::string file_name){
	std::ifstream file;
	file.open(file_name.c_str());
	if (!file){
		std::cout << "Can not find " << file_name << std::endl;
		return; 
	}
	std::string line;
	while(getline(file,line)){
		this->enlist(new node(line));
	}
	file.close();
}
// void text_list::test(){
// 	this->display();
// 	this->import("number.dat");
// 	this->display();
// 	this->empty();
// 	this->display();
// }
