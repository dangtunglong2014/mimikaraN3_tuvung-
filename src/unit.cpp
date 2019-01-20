#include "unit.h"
#include "text_list.h"
#include "answer.h"
#include "node.h"
#include "task.h"

#include <string>
#include <iostream>

unit::unit(){
	list_question = new text_list();
	list_answer   = new text_list();
}
void unit::import(std::string questionFile, std::string answerFile){
	list_question->import(questionFile);
	list_answer->import(answerFile);
}
void unit::round(){
	list_question->round();
	list_answer->round();
}
void unit::empty(){
	list_question->empty();
	list_answer->empty();
}
void unit::learn(){
	int num = 1;
	char key;
	node* question = list_question->randNode();
	do{
		int id = question->getID();
		node* nodeA = list_answer->getNodeByID(id);
		node* nodeB = list_answer->randNode();
		while(nodeB->getID() == nodeA->getID()){
		 	nodeB = list_answer->randNode();
		}
		node* nodeC = list_answer->randNode();
		while(nodeC->getID() == nodeA->getID() || nodeC->getID() == nodeB->getID()){
			nodeC = list_answer->randNode();
		}
		node* nodeD = list_answer->randNode();
		while(nodeD->getID() == nodeA->getID() || nodeD->getID() == nodeB->getID() || nodeD->getID() == nodeC->getID()){
			nodeD = list_answer->randNode();
		}

		answer* answerA = new answer(nodeA,1);
		answer* answerB = new answer(nodeB,0);
		answer* answerC = new answer(nodeC,0);
		answer* answerD = new answer(nodeD,0);

		task* t = new task(num, question,answerA,answerB,answerC,answerD);
		t->ask();
		std::cin >> key;
		if(t->isTrue(key)){
			std::cout << "すごいね!" << std::endl;
		}
		else{
			t->remind();
		}
		std::cout << std::endl;
		num = num + 1;
		question = question->getNext();
	}while(key != 'q');
}

void unit::test(){
	std::string questionFile = "";
	std::string answerFile   = "";
	std::cout << "a. ベトナム語 -> 漢字" << std::endl;
	std::cout << "b. ベトナム語 -> ひらがな" << std::endl; 
	std::cout << "a/b/q 押してください ";
	char key; std::cin >> key;
	switch(key){
		case 'a': 
			questionFile = "vie.dat";
			answerFile   = "kanji.dat";
			break;
		case 'b':
			questionFile = "vie.dat";
			answerFile   = "hiragana.dat";
			break;
		default:
			return;
			break;
	}
	int unitFolder = 0;
	while (unitFolder < 1 || unitFolder > 12) {
		std::cout << "Unit 1/2/3/4/5/6/7/8/9/10/11/12 押してください ";
		std::cin >> unitFolder;
	}
	questionFile = "dat/Unit" + std::to_string(unitFolder) + "/" + questionFile;
	answerFile   = "dat/Unit" + std::to_string(unitFolder) + "/" + answerFile;
	import(questionFile,answerFile);
	std::cout << "始めましょう" << std::endl;
	round();
	learn();
	empty();
	std::cout << "ありがとう ございました" << std::endl;
}
