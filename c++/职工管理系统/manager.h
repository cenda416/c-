#pragma once
#include<iostream>
using namespace std;
#include "worker.h"
//经理类
class manager :public Worker 
{
public:
	manager(int id, string name, int did);
	//显示个人信息
	virtual void showinf();
	//获取岗位名称
	virtual string getdeptname();
	
};