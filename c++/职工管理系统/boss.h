#pragma once
#include<iostream>
using namespace std;
#include "worker.h"
//�ϰ���
class boss :public Worker
{
public:
	boss(int id, string name, int did);
	//��ʾ������Ϣ
	virtual void showinf();
	//��ȡ��λ����
	virtual string getdeptname();

};