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
//菜单界面
void showMenu() {
	cout << "****************************" << endl;
	cout << "*****   1.添加联系人   *****" << endl;
	cout << "*****   2.显示联系人   *****" << endl;
	cout << "*****   3.删除联系人   *****" << endl;
	cout << "*****   4.查找联系人   *****" << endl;
	cout << "*****   5.修改联系人   *****" << endl;
	cout << "*****   6.清空联系人   *****" << endl;
	cout << "*****   0.退出通讯录   *****" << endl;
	cout << "****************************" << endl;
}
//添加联系人
void addperson(Addressbooks* abs) {
	//判断通讯录是否已满，如果满了，不再添加
	if (abs->m_size == max)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else 
	{
		//添加具体联系人；
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personarray[abs->m_size].m_name = name;
		//性别
		cout << "请输入性别：" << endl;
		cout << "1 ---男 2---女" << endl;
		int sex = 0;
		while (true) 
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[abs->m_size].m_sex = sex;break;
			}
			cout << "输入有误,请重新输入" << endl;
		}
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age > 0 && age < 150)
			{
				abs->personarray[abs->m_size].m_age = age;
				break;
			}
			cout << "输入错误，请重新输入" << endl;
		}
		//电话
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personarray[abs->m_size].m_phone = phone;
		//住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personarray[abs->m_size].m_addr = address;
		//更新通讯录的人数：
		abs->m_size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}
//显示所有的联系人
void showperson(Addressbooks* abs) 
{
	//判断通讯录中人数是否为0。如果为0，提示记录为空；
	//如果不为0，显示记录的信息
	if (abs->m_size == 0) 
	{
		cout << "当前的记录为空" << endl;

	}
	else 
	{
		for (int i = 0;i < abs->m_size;i++) 
		{
			cout << "姓名：" << abs->personarray[i].m_name << "性别：" << (abs->personarray[i].m_sex == 1 ? "男":"女");
			cout << "年龄：" << abs->personarray[i].m_age << "电话：" << abs->personarray[i].m_phone;
			cout << "住址：" << abs->personarray[i].m_addr << endl;
		}
	}
	system("pause");//按任意键继续
	system("cls");//清屏

}
//检测联系人是否存在，如果存在，返回联系人所在数组的具体位置,不存再返回-1
int isexist(Addressbooks* abs,string name) 
{
	for (int i = 0;i < abs->m_size;i++) 
	{
		//找到用户输入的姓名了
		if (abs->personarray[i].m_name == name) 
		{
			return i;//找到了返回索引
		}
	}
	return -1;//如果遍历，没有找到,返回-1；
}
//删除指定的联系人
void deleteperson(Addressbooks* abs) 
{
	cout << "请输入你要删除的联系人：" << endl;
	string name;
	cin >> name;
	//ret==-1 未查到
	//ret！=-1 查到了
	int ret=isexist(abs, name);
	if (ret != -1) 
	{
		//查找到人，要进行删除操作；
		for (int i = ret;i < abs->m_size;i++) 
		{
			//数据前移
			abs->personarray[i] = abs->personarray[i + 1];
		}
		abs->m_size--;//更新通讯录的人数
		cout << "删除成功" << endl;
	}
	else 
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//查找联系人
void findperson(Addressbooks* abs) 
{
	cout << "请输入你要查找的联系人" << endl;
	string name;
	cin >> name;
	//判断指定的联系人是否存在通讯录中
	int ret=isexist(abs, name);
	if (ret != -1) //找到联系人；
	{
		cout << "姓名为：" << abs->personarray[ret].m_name << "\t";
		cout << "性别为：" << abs->personarray[ret].m_sex << "\t";
		cout << "年龄为：" << abs->personarray[ret].m_age << "\t";
		cout << "电话为：" << abs->personarray[ret].m_phone << "\t";
		cout << "地址为：" << abs->personarray[ret].m_addr << endl;
	}
	else 
	{
		cout << "查无此人" << endl;
	}
	//按下任意键清屏
	system("pause");
	system("cls");
}
//修改指定的联系人的信息；
void modifyperson(Addressbooks* abs) 
{
	cout << "请输入你要修改的联系人：" << endl;
	string name;
	cin >> name;
	int ret=isexist(abs, name);
	if (ret != -1) 
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personarray[ret].m_name = name;
		//性别
		cout << "请输入性别：" << endl;
		cout << "1--- 男 2--- 女" << endl;
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
				cout << "输入有误，请重新输入：" << endl;
			}
		}
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personarray[ret].m_age = age;
		//电话
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personarray[ret].m_phone = phone;
		//住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personarray[ret].m_addr = address;
		cout << "修改成功" << endl;
	}
	else 
	{
		cout << "查无此人" << endl;
	}
	//按任意键清屏
	system("pause");
	system("cls");
}
//清空联系人
void cleanperson(Addressbooks* abs) 
{
	abs->m_size = 0;//将当期记录联系人数重置为0，做逻辑清空操作
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}
int main() {
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化当前人员个数；
	abs.m_size = 0;
	int select = 0;
	while(true)
	{
		showMenu();
		cin >> select;
		switch (select) {
		case 1:addperson(&abs); //利用地址传递，可以修饰实参
			break;
		case 2:showperson(&abs);
			break;
		case 3:
		/*
			cout << "请输入删除联系人的姓名：" << endl;
			string name;
			cin >> name;
			if (isexist(&abs, name) == -1)
			{
				cout << "查无此人" << endl;
			}
			else
			{
				cout << "找到此人" << endl;
			}
		}*/deleteperson(&abs);
			break;
		case 4:findperson(&abs);
			break;
		case 5:modifyperson(&abs);
			break;
		case 6:cleanperson(&abs);
			break;
		case 0:cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		}
	}
	system("pause");
	return 0;
}