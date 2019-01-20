#include "include.h"
#include <iostream>

// void test_list(){
// 	list* my_list = new list();
// 	my_list->test();
// }

// void test_text_list(){
// 	text_list* my_list = new text_list();
// 	my_list->test();
// }

void test_unit(){
	unit* my_unit = new unit();
	my_unit->test();
}

int main(){
	std::cout << "Phần mềm học từ vựng tiếng Nhật 耳から 覚える N3 miễn phí tạo bởi Long Đặng" << std::endl;
	//test_list();
	//test_text_list();
	test_unit();
	return 0;
}
