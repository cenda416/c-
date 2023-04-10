#include "manager.h"
manager::manager(int id, string name, int did) 
{
	this->m_id = id;
	this->m_name = name;
	this->m_dept = did;
}
//显示个人信息
void manager::showinf() 
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位：" << this->getdeptname()
		<< "\t岗位职责：完成老板交给的任务，并且下发任务给员工" << endl;
}
//获取岗位名称
string manager::getdeptname() 
{
	return string("经理");
}