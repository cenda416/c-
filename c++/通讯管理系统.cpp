#include<iostream>
#include<string>
#define max 1000
using namespace std;
struct Person {
	string m_name;
	int m_sex;
	int m_age;
	string m_phone;
	string m_addr;
};
struct Addressbooks {
	struct Person personarray[max];
	int m_size;
};
//�˵�����
void showMenu() {
	cout << "****************************" << endl;
	cout << "*****   1.�����ϵ��   *****" << endl;
	cout << "*****   2.��ʾ��ϵ��   *****" << endl;
	cout << "*****   3.ɾ����ϵ��   *****" << endl;
	cout << "*****   4.������ϵ��   *****" << endl;
	cout << "*****   5.�޸���ϵ��   *****" << endl;
	cout << "*****   6.�����ϵ��   *****" << endl;
	cout << "*****   0.�˳�ͨѶ¼   *****" << endl;
	cout << "****************************" << endl;
}
//�����ϵ��
void addperson(Addressbooks* abs) {
	//�ж�ͨѶ¼�Ƿ�������������ˣ��������
	if (abs->m_size == max)
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else 
	{
		//��Ӿ�����ϵ�ˣ�
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personarray[abs->m_size].m_name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1 ---�� 2---Ů" << endl;
		int sex = 0;
		while (true) 
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[abs->m_size].m_sex = sex;break;
			}
			cout << "��������,����������" << endl;
		}
		//����
		cout << "���������䣺" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age > 0 && age < 150)
			{
				abs->personarray[abs->m_size].m_age = age;
				break;
			}
			cout << "�����������������" << endl;
		}
		//�绰
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personarray[abs->m_size].m_phone = phone;
		//סַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personarray[abs->m_size].m_addr = address;
		//����ͨѶ¼��������
		abs->m_size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}
//��ʾ���е���ϵ��
void showperson(Addressbooks* abs) 
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ0�����Ϊ0����ʾ��¼Ϊ�գ�
	//�����Ϊ0����ʾ��¼����Ϣ
	if (abs->m_size == 0) 
	{
		cout << "��ǰ�ļ�¼Ϊ��" << endl;

	}
	else 
	{
		for (int i = 0;i < abs->m_size;i++) 
		{
			cout << "������" << abs->personarray[i].m_name << "�Ա�" << (abs->personarray[i].m_sex == 1 ? "��":"Ů");
			cout << "���䣺" << abs->personarray[i].m_age << "�绰��" << abs->personarray[i].m_phone;
			cout << "סַ��" << abs->personarray[i].m_addr << endl;
		}
	}
	system("pause");//�����������
	system("cls");//����

}
//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ����������ľ���λ��,�����ٷ���-1
int isexist(Addressbooks* abs,string name) 
{
	for (int i = 0;i < abs->m_size;i++) 
	{
		//�ҵ��û������������
		if (abs->personarray[i].m_name == name) 
		{
			return i;//�ҵ��˷�������
		}
	}
	return -1;//���������û���ҵ�,����-1��
}
//ɾ��ָ������ϵ��
void deleteperson(Addressbooks* abs) 
{
	cout << "��������Ҫɾ������ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	//ret==-1 δ�鵽
	//ret��=-1 �鵽��
	int ret=isexist(abs, name);
	if (ret != -1) 
	{
		//���ҵ��ˣ�Ҫ����ɾ��������
		for (int i = ret;i < abs->m_size;i++) 
		{
			//����ǰ��
			abs->personarray[i] = abs->personarray[i + 1];
		}
		abs->m_size--;//����ͨѶ¼������
		cout << "ɾ���ɹ�" << endl;
	}
	else 
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//������ϵ��
void findperson(Addressbooks* abs) 
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	//�ж�ָ������ϵ���Ƿ����ͨѶ¼��
	int ret=isexist(abs, name);
	if (ret != -1) //�ҵ���ϵ�ˣ�
	{
		cout << "����Ϊ��" << abs->personarray[ret].m_name << "\t";
		cout << "�Ա�Ϊ��" << abs->personarray[ret].m_sex << "\t";
		cout << "����Ϊ��" << abs->personarray[ret].m_age << "\t";
		cout << "�绰Ϊ��" << abs->personarray[ret].m_phone << "\t";
		cout << "��ַΪ��" << abs->personarray[ret].m_addr << endl;
	}
	else 
	{
		cout << "���޴���" << endl;
	}
	//�������������
	system("pause");
	system("cls");
}
//�޸�ָ������ϵ�˵���Ϣ��
void modifyperson(Addressbooks* abs) 
{
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret=isexist(abs, name);
	if (ret != -1) 
	{
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personarray[ret].m_name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1--- �� 2--- Ů" << endl;
		int sex = 0;
		while (true) 
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[ret].m_sex = sex;break;
			}
			else 
			{
				cout << "�����������������룺" << endl;
			}
		}
		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personarray[ret].m_age = age;
		//�绰
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personarray[ret].m_phone = phone;
		//סַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personarray[ret].m_addr = address;
		cout << "�޸ĳɹ�" << endl;
	}
	else 
	{
		cout << "���޴���" << endl;
	}
	//�����������
	system("pause");
	system("cls");
}
//�����ϵ��
void cleanperson(Addressbooks* abs) 
{
	abs->m_size = 0;//�����ڼ�¼��ϵ��������Ϊ0�����߼���ղ���
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}
int main() {
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ����ǰ��Ա������
	abs.m_size = 0;
	int select = 0;
	while(true)
	{
		showMenu();
		cin >> select;
		switch (select) {
		case 1:addperson(&abs); //���õ�ַ���ݣ���������ʵ��
			break;
		case 2:showperson(&abs);
			break;
		case 3:
		/*
			cout << "������ɾ����ϵ�˵�������" << endl;
			string name;
			cin >> name;
			if (isexist(&abs, name) == -1)
			{
				cout << "���޴���" << endl;
			}
			else
			{
				cout << "�ҵ�����" << endl;
			}
		}*/deleteperson(&abs);
			break;
		case 4:findperson(&abs);
			break;
		case 5:modifyperson(&abs);
			break;
		case 6:cleanperson(&abs);
			break;
		case 0:cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		}
	}
	system("pause");
	return 0;
}