//============================================================================
// Name        : test2-2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include "WebBrowser.h"
using namespace std;

int main() {


	string page;
	string process;

	string fileName;	//string 객체 fileName 생성
	cout<<"파일 이름 : ";
	cin>>fileName;		//fileName은 입력한 문자열로 구성된다

	ifstream fin;				//ifstream 객체 fin 생성
	fin.open(fileName.c_str());	//파일 열기 (열고자 하는 파일은 fileName에 구성되어 있는 문자열)
									//.c_str() 은 문자열을 C 스타일의 문자열로 변환
	WebBrowser WB;
	const string EXITCMD = "quit";
	fin>>process;
	while(process!=EXITCMD){
		if(process=="go"||process=="set_home"){
			fin>>page;
		}

		if(process=="go"){
			WB.Go(page);
		}
		else if(process=="forward"){
			WB.Forward();
		}
		else if(process=="backward"){
			 WB.Backward();
		}
		else if(process=="home"){
			WB.Home();
		}
		else if(process=="set_home"){
			WB.Set_home(page);
		}
		else if(process=="history"){
			WB.History();
		}
		else{
			cout<<"입력이 잘 못 되었습니다."<<endl;
		}

		fin>>process;

	}

	fin.close();			//파일 닫기
	return 0;
}
