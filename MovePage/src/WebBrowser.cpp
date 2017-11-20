/*
 * WebBrowser.cpp
 *
 *  Created on: 2016. 3. 17.
 *      Author: hyk
 */
#include "WebBrowser.h"

/*������ �� size�� set�� 0���� ������
 ù ��° �������� http;//ces.hufs.ac.kr�� �Ѵ�*/
WebBrowser::WebBrowser(){
	size = 0;
	set = 0;
	wb[0].input_page="http://ces.hufs.ac.kr"; //ù �������� http://ces.hufs.ac.kr
	list[0].input_page="http://ces.hufs.ac.kr"; //ù �������� http://ces.hufs.ac.kr
	StartPage(wb[0].input_page);
}

//������ ���ÿ� ù ������ ����� ����
void WebBrowser::StartPage(string page){
	home_page=page;
	cout<<home_page<<endl; //ó�� Ȩ ������ ���
}

//������ �̵��� ���� �Լ�
void WebBrowser::Go(string page){

	size++; //���� �迭
	set++; //����Ű�� ���� ���� �迭

	wb[set].input_page=page;	//�������� ���� �������� �޴´�
	list[size].input_page=page; //�������� ����Ʈ�� �޴´�
	cout<< wb[set].input_page<<endl;

	last_page =  wb[set].input_page; //���� �������� ������ �������� �Ѵ�
}

//������ ����
void WebBrowser::Forward(){
	//������ �������� ��� Forward�Է½� ���� ������ ������ ���ǹ� ���
	if( wb[set].input_page == last_page)
		cout<< wb[set].input_page<<endl;
	else{
	size++; //�����迭
	set+=1; //����Ű�� ���� ������ ����Ų ���� ��ġ�� �迭
	list[size].input_page = wb[set].input_page;

	cout<< wb[set].input_page<<endl;
	}
}

//�ڷΰ���
void WebBrowser::Backward(){

	size++;
	//���� ó�� �������� �� backward�Է� �� ���� ������ ���
	if(set-1 < 0)
		cout<< wb[set].input_page<<endl;
	else
	{
	set = set-1; //����Ű�� ���� ������ ����Ų ���� ���� ��ġ�� �迭
	list[size].input_page = wb[set].input_page;
	cout<< wb[set].input_page<<endl;
	}

}

//Ȩ���� ����
void WebBrowser::Home(){

	size++; //�����迭
	set++; //����Ű�� ���� ���� �迭
	wb[set].input_page=home_page; //Ȩ�������� ���� ��������
	list[size].input_page =  wb[set].input_page;
	cout<<  wb[set].input_page<<endl;
	last_page= wb[set].input_page; //���� �������� ������ �������� �Ѵ�
}

//Ȩ �����ϱ�
void WebBrowser::Set_home(string page){
	home_page = page;
}

//�湮�ߴ� �������� �ߺ����� ������������ ���̱�
void WebBrowser::History(){

	int n=0;
	int j;
	//�ߺ� �����ֱ�
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
	//�������� ����

	for(int i=0; i<n; i++){
		list[i].page = list[i].input_page.c_str();
		//c_str()�� ���� string�� const char* ���� ��ȯ
	}
	for(int i=0; i<n; i++){
			for(j=0; j<n-1; j++){
				if(strcmp(list[j].page, list[j+1].page)>0)
					//strcmp�� �������� ����
					{
					as[k].page = list[j].page;
					list[j].page = list[j+1].page;
					list[j+1].page = as[k].page;
					k++;
					}
			}
		}

	cout<<"����Ʈ ���";
	for(int i=0; i<n; i++){
		cout<<list[i].page<<endl;
	}

}
