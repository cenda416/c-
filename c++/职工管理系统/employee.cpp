#include"employee.h"
Employee::Employee(int id,string name,int did) 
{
	this->m_id = id;
	this->m_name = name;
	this->m_dept = did;
}
//显示个人信息
void Employee::showinf() 
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位：" << this->getdeptname() 
		<<"\t岗位职责：完成经理交给的任务" << endl;
}
//获取岗位名称
string Employee::getdeptname() 
{
	return string("员工");
}