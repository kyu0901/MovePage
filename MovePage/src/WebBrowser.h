/*
 * WebBrowser.h
 *
 *  Created on: 2016. 3. 17.
 *      Author: hyk
 */

#ifndef WEBBROWSER_H_
#define WEBBROWSER_H_
#include "Page.h"
#define MAX 100
//webBrowser class
class WebBrowser{
public:
	WebBrowser();	//생성자 초기화
	void StartPage(string page); //초기 주소 정하려고
	void Go(string page);		// 현재 주소를 입력받은 주소로 바꾸고 이를 출력한다.
	void Forward();// 다음 주소로 이동하고(현재주소를 다음주소로 바꾸고) 이 주소를 출력한다.
	void Backward();// 이전 주소로 이동하고(현재주소를 이전주소로 바꾸고) 이 주소를 출력한다.
	void Home();     // 현재 주소를 홈 주소로 이동하고 이 주소를 출력한다.
	void Set_home(string page); // 홈 주소를 입력받은 주소로 변경
					// 현재 주소는 바뀌지 않으며 출력결과도 없음
	void History(); // 지금까지 방문한 웹 페이지 주소를 알파벳 오름차순으로 출력한다.
					// 동일한 주소는 하나만 출력

private:
	Page wb[MAX]; //현재 페이지 나타낼 수 있게하는 객체
	Page list[MAX]; //다녀온 페이지를 전부 나타내는 객체
	Page as[MAX]; //오름차순 사용 시 사용할 객체

	string home_page; //홈 페이지
	string last_page;//마지막 페이지

	int size; //전체 페이지 수를 위해
	int set; //가르키는 곳
};




#endif /* WEBBROWSER_H_ */
