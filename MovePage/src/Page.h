/*
 * Page.h
 *
 *  Created on: 2016. 3. 17.
 *      Author: hyk
 */

#ifndef PAGE_H_
#define PAGE_H_
#include <string>
#include <cstring> //strcmp 함수사용을 위해
#include <iostream>
using namespace std;
// Page 구조체
struct Page{
	string input_page; //현재 주소를 넣기 위해
	const char* page; // strcmp를 사용하기 위해
};




#endif /* PAGE_H_ */
