#include"workManager.h"
workManager::workManager()
{
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件
	if (!ifs.is_open()) 
	{
		//cout << "文件不存在" << endl;
		//初始化属性
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组指针为空
		this->m_empArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.文件存在 数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) 
	{
		//文件为空
		//cout << "文件为空" << endl;
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组指针为空
		this->m_empArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.当文件存在，并且记录数据
	int num = this->get_Empnum();
	//cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num;
	//开辟空间
	this->m_empArray = new Worker * [this->m_EmpNum];
	//将文件中的数据，存到数组中
	this->init_Emp();
	/*for (int i = 0;i < this->m_EmpNum;i++) 
	{
		cout << "职工编号：" << this->m_empArray[i]->m_id << " "
			<< "姓名：" << this->m_empArray[i]->m_name << " "
			<< "部门编号" << this->m_empArray[i]->m_dept << endl;
	}*/
	
	
}
workManager::~workManager()
{
	if(this->m_empArray==NULL)
	{
		delete[] this->m_empArray;
		this->m_empArray = NULL;
	}
}
void workManager::show_Menu() 
{
	cout << "******************************" << endl;
	cout << "****欢迎使用职工管理系统！****" << endl;
	cout << "*******0.退出管理程序*********" << endl;
	cout << "*******1.增加职工信息*********" << endl;
	cout << "*******2.显示职工信息*********" << endl;
	cout << "*******3.删除离职职工*********" << endl;
	cout << "*******4.修改职工信息*********" << endl;
	cout << "*******5.查找职工信息*********" << endl;
	cout << "*******6.按照编号排序*********" << endl;
	cout << "*******7.清空所有文档*********" << endl;
	cout << "******************************" << endl;
	cout << endl;

}
void workManager::exitSystem() //退出系统
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);

}
//添加职工
void workManager::Add_Emp() 
{
	cout << "请输入添加职工的数量：" << endl;
	int addNum = 0;//保存用户的输入数量
	cin >> addNum;
	if (addNum > 0) 
	{
		//添加
		//计算添加新空间大小
		int newSize = this->m_EmpNum + addNum;//新空间的大小=原来记录人数+新增人数
		//开辟新空间
		Worker** newSpace = new Worker * [newSize];
		//将原来空间的数据拷贝到新空间
		if (this->m_empArray != NULL) 
		{
			for (int i = 0;i < this->m_EmpNum;i++) 
			{
				newSpace[i] = this->m_empArray[i];
			}
		}
		//添加新数据
		for (int i = 0;i < addNum;i++) 
		{
			int id;//职工编号
			string name;//职工姓名
			int dSelect;//部门选择
			cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;
			cout << "请选择该职工的岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect) 
			{
			case 1:
				worker = new Employee(id, name, 1);break;
			case 2:
				worker = new manager(id, name, 2);break;
			case 3:
				worker = new boss(id, name, 3);break;
			default:
				break;
			}
			//将创建职工指针，保存到数组
			newSpace[this->m_EmpNum + i] = worker;

		}
		//释放原有的空间
		delete[] this->m_empArray;
		//更改新空间的指向
		this->m_empArray = newSpace;
		//更新新的职工人数
		this->m_EmpNum = newSize;
		//更新职工不为空的标志
		this->m_FileIsEmpty = false;
		//添加成功
		cout << "成功添加" << addNum<<"名新职工" << endl;
		this->save();

	}
	else {
		cout << "输入有误" << endl;
	}
	//按任意键清屏
	system("pause");
	system("cls");
}
//保存文件
void workManager::save() 
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//用输出的方式来打开文件--写文件
	//将每个人的数据写入到文件中
	for (int i = 0;i < this->m_EmpNum;i++) 
	{
		ofs << this->m_empArray[i]->m_id << " "
			<< this->m_empArray[i]->m_name << " "
			<< this->m_empArray[i]->m_dept << endl;
	}
	//关闭文件
	ofs.close();
}
//统计文件中人数
int workManager::get_Empnum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//打开文件 读文件
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did) 
	{
		//统计人数变量
		num++;
	}
	return num;

}
//初始化员工
void workManager::init_Emp() 
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did) 
	{
		Worker* worker = NULL;
		if (did == 1) //普通职工
		{
			worker = new Employee(id, name, did);
		}
		else if (did == 2)//经理
		{
			worker = new manager(id, name, did);
		}
		else if (did == 3)//老板
		{
			worker = new boss(id, name, did);
		}
		this->m_empArray[index] = worker;
		index++;
	}
	ifs.close();
}//显示职工
//显示职工
void workManager::Show_Emp() 
{
	if (this->m_FileIsEmpty) 
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else 
	{
		for (int i = 0;i < this->m_EmpNum;i++) 
		{
			//利用多态调用程序接口
			this->m_empArray[i]->showinf();
		}
	}
	system("pause");
	system("cls");
}
//删除职工
void workManager::Del_Emp() 
{
	if (this->m_FileIsEmpty) 
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else 
	{
		//按照职工的编号删除职工
		cout << "请输入想要删除职工的编号" << endl;
		int id = 0;
		cin >> id;
		int index=this->IsExist(id);
		if (index != -1) //说明职工存在，并且删除掉index位置上的员工
		{
			//数据前移
			for (int i = index;i < this->m_EmpNum-1;i++) 
			{
				this->m_empArray[i] = this->m_empArray[i + 1];
			}
			this->m_EmpNum--;//更新一下数组中记录人员个数
			//数据同步更新到文件中
			this->save();
			cout << "删除成功" << endl;
		}
		else 
		{
			cout << "删除失败，未找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");
}
//判断职工是否存在 如果存在返回职工所在数组中的位置，不存在返回-1；
int workManager::IsExist(int id) 
{
	int index = -1;
	for (int i = 0;i < this->m_EmpNum;i++) 
	{
		if (this->m_empArray[i]->m_id == id) 
		{
			//找到职工
			index = i;
			break;
		}
	}
	return index;
}
//修改职工
void workManager::Mod_Emp()
{
	if (this->m_FileIsEmpty) 
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号：" << endl;
		int id;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			//查找到编号的职工
			delete this->m_empArray[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;
			cout << "查到：" << id << "号职工，请输入新职工号：" << endl;
			cin >> newId;
			cout << "请输入新的姓名：" << endl;
			cin >> newName;
			cout << "请输入岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2. 经理" << endl;
			cout << "3. 老板" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect) 
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);break;
			case 2:
				worker = new manager(newId, newName, dSelect);break;
			case 3:
				worker = new boss(newId, newName, dSelect);break;
			default:
				break;
			}
			//更新数据到数组中
			this->m_empArray[ret] = worker;
			cout << "修改成功" << endl;
			//保存文件中
			this->save();
		}
		else 
		{
			cout << "修改失败，查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}
//查找职工
void workManager::Find_Emp() 
{
	if (this->m_FileIsEmpty) 
	{
		cout << "文件不存在或文件为空" << endl;
	}
	else 
	{
		cout << "请输入查找的方法：" << endl;
		cout << "1.按照职工编号查找" << endl;
		cout << "2.按照职工姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//按照编号查
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1) 
			{
				//找到职工
				cout << "查找成功！该职工信息如下" << endl;
				this->m_empArray[ret]->showinf();
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else if (select == 2)
		{
			//按照姓名查
			string name;
			cout << "请输入查找的姓名：" << endl;
			cin >> name;
			//加入判断是否查到的标志
			bool flag = false;
			for (int i = 0;i < m_EmpNum;i++) 
			{
				if (this->m_empArray[i]->m_name == name) 
				{
					cout << "查找成功，职工编号为：" << this->m_empArray[i]->m_id << "职工信息如下：" << endl;
					this->m_empArray[i]->showinf();
					flag = true;
				}
			}
			if (flag == false) 
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else
		{
			cout << "输入选项有误" << endl;
		}
	}
	system("pause");
	system("cls");
}
//按照编号排序
void workManager::Sort_Emp() 
{
	if (this->m_FileIsEmpty) 
	{
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");

	}
	else 
	{
		cout << "请选择排序方式：" << endl;
		cout << "1.按职工号进行升序" << endl;
		cout << "2.按职工号进行降序" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0;i < m_EmpNum;i++) 
		{
			int minOrMax = i;//声明最小值或最大值下标
			for (int j = i + 1;j < this->m_EmpNum;j++)
			{
				if (select == 1)//升序 
				{
					if (this->m_empArray[minOrMax]->m_id > this->m_empArray[j]->m_id) 
					{
						minOrMax= j;
					}
				}
				else //降序
				{
					if (this->m_empArray[minOrMax]->m_id < this->m_empArray[j]->m_id) 
					{
						minOrMax = j;
					}
				}
			}
			//判断一开始认定最小值或最大值是不是计算的最小值或最大值，如果不是 交换数据
			if(i!=minOrMax)
			{
				Worker* temp = this->m_empArray[i];
				this->m_empArray[i] = this->m_empArray[minOrMax];
				this->m_empArray[minOrMax] = temp;
			}
			
		}
		cout << "排序成功！排序的结果为：" << endl;
		this->save();
		this->Show_Emp();
	}
}
//清空文件
void workManager::Clean_File() 
{
	cout << "确定清空？" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) 
	{
		//清空文件
		ofstream ofs(FILENAME, ios::trunc);//删除文件再重新创建
		ofs.close();
		if (this->m_empArray != NULL) 
		{
			//删除堆区的每个职工对象
			for (int i = 0;i < this->m_EmpNum;i++) 
			{
				delete this->m_empArray[i];
				this->m_empArray[i] = NULL;

			}
			//删除堆区的数组指针
			delete[] this->m_empArray;
			this->m_empArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;

		}
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}