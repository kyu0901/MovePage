/*
 * WebBrowser.cpp
 *
 *  Created on: 2016. 3. 17.
 *      Author: hyk
 */
#include "WebBrowser.h"

/*생성할 때 size와 set를 0으로 함으로
 첫 번째 페이지는 http;//ces.hufs.ac.kr로 한다*/
WebBrowser::WebBrowser(){
	size = 0;
	set = 0;
	wb[0].input_page="http://ces.hufs.ac.kr"; //첫 페이지는 http://ces.hufs.ac.kr
	list[0].input_page="http://ces.hufs.ac.kr"; //첫 페이지는 http://ces.hufs.ac.kr
	StartPage(wb[0].input_page);
}

//생성과 동시에 첫 페이지 출력을 위해
void WebBrowser::StartPage(string page){
	home_page=page;
	cout<<home_page<<endl; //처음 홈 페이지 출력
}

//페이지 이동을 위한 함수
void WebBrowser::Go(string page){

	size++; //다음 배열
	set++; //가르키는 곳은 다음 배열

	wb[set].input_page=page;	//페이지를 현재 페이지로 받는다
	list[size].input_page=page; //페이지를 리스트에 받는다
	cout<< wb[set].input_page<<endl;

	last_page =  wb[set].input_page; //현재 페이지를 마지막 페이지로 한다
}

//앞으로 가기
void WebBrowser::Forward(){
	//마지막 페이지일 경우 Forward입력시 현재 페이지 나오게 조건문 사용
	if( wb[set].input_page == last_page)
		cout<< wb[set].input_page<<endl;
	else{
	size++; //다음배열
	set+=1; //가르키는 곳은 이전에 가르킨 다음 위치의 배열
	list[size].input_page = wb[set].input_page;

	cout<< wb[set].input_page<<endl;
	}
}

//뒤로가기
void WebBrowser::Backward(){

	size++;
	//제일 처음 페이지일 때 backward입력 시 현재 페이지 출력
	if(set-1 < 0)
		cout<< wb[set].input_page<<endl;
	else
	{
	set = set-1; //가르키는 곳은 이전에 가르킨 곳의 이전 위치의 배열
	list[size].input_page = wb[set].input_page;
	cout<< wb[set].input_page<<endl;
	}

}

//홈으로 가기
void WebBrowser::Home(){

	size++; //다음배열
	set++; //가르키는 곳은 다음 배열
	wb[set].input_page=home_page; //홈페이지를 현재 페이지로
	list[size].input_page =  wb[set].input_page;
	cout<<  wb[set].input_page<<endl;
	last_page= wb[set].input_page; //현재 페이지를 마지막 페이지로 한다
}

//홈 지정하기
void WebBrowser::Set_home(string page){
	home_page = page;
}

//방문했던 페이지들 중복없이 오름차순으로 보이기
void WebBrowser::History(){

	int n=0;
	int j;
	//중복 없애주기
	for(int i=0; i<size+1; i++){
		for(j=0; j<i; j++){
			if(list[i].input_page == list[j].input_page)
				break;
		}
		if(i==j)
		{
		list[n].input_page = list[i].input_page;
		n++;
		}
	}
int k=0;
	//오름차순 정리

	for(int i=0; i<n; i++){
		list[i].page = list[i].input_page.c_str();
		//c_str()을 통해 string을 const char* 으로 변환
	}
	for(int i=0; i<n; i++){
			for(j=0; j<n-1; j++){
				if(strcmp(list[j].page, list[j+1].page)>0)
					//strcmp를 오름차순 정렬
					{
					as[k].page = list[j].page;
					list[j].page = list[j+1].page;
					list[j+1].page = as[k].page;
					k++;
					}
			}
		}

	cout<<"리스트 출력";
	for(int i=0; i<n; i++){
		cout<<list[i].page<<endl;
	}

}
