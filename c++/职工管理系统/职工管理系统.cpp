#include<iostream>
using namespace std;
#include"workManager.h"
#include"employee.h"
#include "worker.h"
#include "manager.h"
#include"boss.h"
int main() 
{
	//测试
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
	//实例化管理者对象
	workManager wm;
	int choice;
	
	while (true) 
	{
		//调用展示菜单成员函数
		wm.show_Menu();
		cout << "请输入你的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			wm.exitSystem();
			break;
		case 1://添加职工
			wm.Add_Emp();
			break;
		case 2://显示职工
			wm.Show_Emp();
			break;
		case 3://删除职工
		//	//测试
		//{int ret = wm.IsExist(5);
		//if (ret != -1)
		//{
		//	cout << "职工存在" << endl;
		//}
		//else
		//{
		//	cout << "职工不存在" << endl;
		//}
		//break;}
			wm.Del_Emp();
			break;
		case 4://修改职工
			wm.Mod_Emp();
			break;
		case 5://查找职工
			wm.Find_Emp();
			break;
		case 6://排序职工
			wm.Sort_Emp();
			break;
		case 7://清空文件
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