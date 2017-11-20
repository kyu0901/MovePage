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

	string fileName;	//string ��ü fileName ����
	cout<<"���� �̸� : ";
	cin>>fileName;		//fileName�� �Է��� ���ڿ��� �����ȴ�

	ifstream fin;				//ifstream ��ü fin ����
	fin.open(fileName.c_str());	//���� ���� (������ �ϴ� ������ fileName�� �����Ǿ� �ִ� ���ڿ�)
									//.c_str() �� ���ڿ��� C ��Ÿ���� ���ڿ��� ��ȯ
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
			cout<<"�Է��� �� �� �Ǿ����ϴ�."<<endl;
		}

		fin>>process;

	}

	fin.close();			//���� �ݱ�
	return 0;
}
