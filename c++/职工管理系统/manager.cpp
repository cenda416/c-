#include "manager.h"
manager::manager(int id, string name, int did) 
{
	this->m_id = id;
	this->m_name = name;
	this->m_dept = did;
}
//��ʾ������Ϣ
void manager::showinf() 
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->getdeptname()
		<< "\t��λְ������ϰ彻�������񣬲����·������Ա��" << endl;
}
//��ȡ��λ����
string manager::getdeptname() 
{
	return string("����");
}