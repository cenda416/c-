#include"employee.h"
Employee::Employee(int id,string name,int did) 
{
	this->m_id = id;
	this->m_name = name;
	this->m_dept = did;
}
//��ʾ������Ϣ
void Employee::showinf() 
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->getdeptname() 
		<<"\t��λְ����ɾ�����������" << endl;
}
//��ȡ��λ����
string Employee::getdeptname() 
{
	return string("Ա��");
}