#include "boss.h"
boss::boss(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_dept = did;
}
//��ʾ������Ϣ
void boss::showinf()
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->getdeptname()
		<< "\t��λְ�𣺹���˾���е�����" << endl;
}
//��ȡ��λ����
string boss::getdeptname()
{
	return string("�ܲ�");
}