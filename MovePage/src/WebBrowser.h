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
	WebBrowser();	//������ �ʱ�ȭ
	void StartPage(string page); //�ʱ� �ּ� ���Ϸ���
	void Go(string page);		// ���� �ּҸ� �Է¹��� �ּҷ� �ٲٰ� �̸� ����Ѵ�.
	void Forward();// ���� �ּҷ� �̵��ϰ�(�����ּҸ� �����ּҷ� �ٲٰ�) �� �ּҸ� ����Ѵ�.
	void Backward();// ���� �ּҷ� �̵��ϰ�(�����ּҸ� �����ּҷ� �ٲٰ�) �� �ּҸ� ����Ѵ�.
	void Home();     // ���� �ּҸ� Ȩ �ּҷ� �̵��ϰ� �� �ּҸ� ����Ѵ�.
	void Set_home(string page); // Ȩ �ּҸ� �Է¹��� �ּҷ� ����
					// ���� �ּҴ� �ٲ��� ������ ��°���� ����
	void History(); // ���ݱ��� �湮�� �� ������ �ּҸ� ���ĺ� ������������ ����Ѵ�.
					// ������ �ּҴ� �ϳ��� ���

private:
	Page wb[MAX]; //���� ������ ��Ÿ�� �� �ְ��ϴ� ��ü
	Page list[MAX]; //�ٳ�� �������� ���� ��Ÿ���� ��ü
	Page as[MAX]; //�������� ��� �� ����� ��ü

	string home_page; //Ȩ ������
	string last_page;//������ ������

	int size; //��ü ������ ���� ����
	int set; //����Ű�� ��
};




#endif /* WEBBROWSER_H_ */
