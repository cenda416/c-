#pragma once
#include<iostream>
using namespace std;
#include<string>
//ְ��������
class Worker
{
public:
		//��ʾ������Ϣ
	virtual void showinf() = 0;
	//��ȡ��λ����
	virtual string getdeptname() = 0;
		//ְ�����
		int m_id;
		//ְ������
		string m_name;
	//���ű��
		int m_dept;
};
