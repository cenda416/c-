#include<iostream>
using namespace std;
#include"workManager.h"
#include"employee.h"
#include "worker.h"
#include "manager.h"
#include"boss.h"
int main() 
{
	//����
	/*Worker* worker = NULL;
	worker = new Employee(1, "a", 1);
	worker->showinf();
	delete worker;
	worker = new manager(2, "b", 2);
	worker->showinf();
	delete worker;
	worker = new boss(3, "c", 3);
	worker->showinf();
	delete worker;*/
	//ʵ���������߶���
	workManager wm;
	int choice;
	
	while (true) 
	{
		//����չʾ�˵���Ա����
		wm.show_Menu();
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1://���ְ��
			wm.Add_Emp();
			break;
		case 2://��ʾְ��
			wm.Show_Emp();
			break;
		case 3://ɾ��ְ��
		//	//����
		//{int ret = wm.IsExist(5);
		//if (ret != -1)
		//{
		//	cout << "ְ������" << endl;
		//}
		//else
		//{
		//	cout << "ְ��������" << endl;
		//}
		//break;}
			wm.Del_Emp();
			break;
		case 4://�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5://����ְ��
			wm.Find_Emp();
			break;
		case 6://����ְ��
			wm.Sort_Emp();
			break;
		case 7://����ļ�
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}
	

	system("pause");
	return 0;
}