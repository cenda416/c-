#include"workManager.h"
workManager::workManager()
{
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�
	if (!ifs.is_open()) 
	{
		//cout << "�ļ�������" << endl;
		//��ʼ������
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ������ָ��Ϊ��
		this->m_empArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.�ļ����� ����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) 
	{
		//�ļ�Ϊ��
		//cout << "�ļ�Ϊ��" << endl;
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ������ָ��Ϊ��
		this->m_empArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.���ļ����ڣ����Ҽ�¼����
	int num = this->get_Empnum();
	//cout << "ְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;
	//���ٿռ�
	this->m_empArray = new Worker * [this->m_EmpNum];
	//���ļ��е����ݣ��浽������
	this->init_Emp();
	/*for (int i = 0;i < this->m_EmpNum;i++) 
	{
		cout << "ְ����ţ�" << this->m_empArray[i]->m_id << " "
			<< "������" << this->m_empArray[i]->m_name << " "
			<< "���ű��" << this->m_empArray[i]->m_dept << endl;
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
	cout << "****��ӭʹ��ְ������ϵͳ��****" << endl;
	cout << "*******0.�˳��������*********" << endl;
	cout << "*******1.����ְ����Ϣ*********" << endl;
	cout << "*******2.��ʾְ����Ϣ*********" << endl;
	cout << "*******3.ɾ����ְְ��*********" << endl;
	cout << "*******4.�޸�ְ����Ϣ*********" << endl;
	cout << "*******5.����ְ����Ϣ*********" << endl;
	cout << "*******6.���ձ������*********" << endl;
	cout << "*******7.��������ĵ�*********" << endl;
	cout << "******************************" << endl;
	cout << endl;

}
void workManager::exitSystem() //�˳�ϵͳ
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);

}
//���ְ��
void workManager::Add_Emp() 
{
	cout << "���������ְ����������" << endl;
	int addNum = 0;//�����û�����������
	cin >> addNum;
	if (addNum > 0) 
	{
		//���
		//��������¿ռ��С
		int newSize = this->m_EmpNum + addNum;//�¿ռ�Ĵ�С=ԭ����¼����+��������
		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];
		//��ԭ���ռ�����ݿ������¿ռ�
		if (this->m_empArray != NULL) 
		{
			for (int i = 0;i < this->m_EmpNum;i++) 
			{
				newSpace[i] = this->m_empArray[i];
			}
		}
		//���������
		for (int i = 0;i < addNum;i++) 
		{
			int id;//ְ�����
			string name;//ְ������
			int dSelect;//����ѡ��
			cout << "�������" << i + 1 << "����ְ����ţ�" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
			//������ְ��ָ�룬���浽����
			newSpace[this->m_EmpNum + i] = worker;

		}
		//�ͷ�ԭ�еĿռ�
		delete[] this->m_empArray;
		//�����¿ռ��ָ��
		this->m_empArray = newSpace;
		//�����µ�ְ������
		this->m_EmpNum = newSize;
		//����ְ����Ϊ�յı�־
		this->m_FileIsEmpty = false;
		//��ӳɹ�
		cout << "�ɹ����" << addNum<<"����ְ��" << endl;
		this->save();

	}
	else {
		cout << "��������" << endl;
	}
	//�����������
	system("pause");
	system("cls");
}
//�����ļ�
void workManager::save() 
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//������ķ�ʽ�����ļ�--д�ļ�
	//��ÿ���˵�����д�뵽�ļ���
	for (int i = 0;i < this->m_EmpNum;i++) 
	{
		ofs << this->m_empArray[i]->m_id << " "
			<< this->m_empArray[i]->m_name << " "
			<< this->m_empArray[i]->m_dept << endl;
	}
	//�ر��ļ�
	ofs.close();
}
//ͳ���ļ�������
int workManager::get_Empnum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ� ���ļ�
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did) 
	{
		//ͳ����������
		num++;
	}
	return num;

}
//��ʼ��Ա��
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
		if (did == 1) //��ְͨ��
		{
			worker = new Employee(id, name, did);
		}
		else if (did == 2)//����
		{
			worker = new manager(id, name, did);
		}
		else if (did == 3)//�ϰ�
		{
			worker = new boss(id, name, did);
		}
		this->m_empArray[index] = worker;
		index++;
	}
	ifs.close();
}//��ʾְ��
//��ʾְ��
void workManager::Show_Emp() 
{
	if (this->m_FileIsEmpty) 
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else 
	{
		for (int i = 0;i < this->m_EmpNum;i++) 
		{
			//���ö�̬���ó���ӿ�
			this->m_empArray[i]->showinf();
		}
	}
	system("pause");
	system("cls");
}
//ɾ��ְ��
void workManager::Del_Emp() 
{
	if (this->m_FileIsEmpty) 
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else 
	{
		//����ְ���ı��ɾ��ְ��
		cout << "��������Ҫɾ��ְ���ı��" << endl;
		int id = 0;
		cin >> id;
		int index=this->IsExist(id);
		if (index != -1) //˵��ְ�����ڣ�����ɾ����indexλ���ϵ�Ա��
		{
			//����ǰ��
			for (int i = index;i < this->m_EmpNum-1;i++) 
			{
				this->m_empArray[i] = this->m_empArray[i + 1];
			}
			this->m_EmpNum--;//����һ�������м�¼��Ա����
			//����ͬ�����µ��ļ���
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
		else 
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
	}
	system("pause");
	system("cls");
}
//�ж�ְ���Ƿ���� ������ڷ���ְ�����������е�λ�ã������ڷ���-1��
int workManager::IsExist(int id) 
{
	int index = -1;
	for (int i = 0;i < this->m_EmpNum;i++) 
	{
		if (this->m_empArray[i]->m_id == id) 
		{
			//�ҵ�ְ��
			index = i;
			break;
		}
	}
	return index;
}
//�޸�ְ��
void workManager::Mod_Emp()
{
	if (this->m_FileIsEmpty) 
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı�ţ�" << endl;
		int id;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			//���ҵ���ŵ�ְ��
			delete this->m_empArray[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;
			cout << "�鵽��" << id << "��ְ������������ְ���ţ�" << endl;
			cin >> newId;
			cout << "�������µ�������" << endl;
			cin >> newName;
			cout << "�������λ��" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2. ����" << endl;
			cout << "3. �ϰ�" << endl;
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
			//�������ݵ�������
			this->m_empArray[ret] = worker;
			cout << "�޸ĳɹ�" << endl;
			//�����ļ���
			this->save();
		}
		else 
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
	}
	system("pause");
	system("cls");
}
//����ְ��
void workManager::Find_Emp() 
{
	if (this->m_FileIsEmpty) 
	{
		cout << "�ļ������ڻ��ļ�Ϊ��" << endl;
	}
	else 
	{
		cout << "��������ҵķ�����" << endl;
		cout << "1.����ְ����Ų���" << endl;
		cout << "2.����ְ����������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//���ձ�Ų�
			int id;
			cout << "��������ҵ�ְ����ţ�" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1) 
			{
				//�ҵ�ְ��
				cout << "���ҳɹ�����ְ����Ϣ����" << endl;
				this->m_empArray[ret]->showinf();
			}
			else
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else if (select == 2)
		{
			//����������
			string name;
			cout << "��������ҵ�������" << endl;
			cin >> name;
			//�����ж��Ƿ�鵽�ı�־
			bool flag = false;
			for (int i = 0;i < m_EmpNum;i++) 
			{
				if (this->m_empArray[i]->m_name == name) 
				{
					cout << "���ҳɹ���ְ�����Ϊ��" << this->m_empArray[i]->m_id << "ְ����Ϣ���£�" << endl;
					this->m_empArray[i]->showinf();
					flag = true;
				}
			}
			if (flag == false) 
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else
		{
			cout << "����ѡ������" << endl;
		}
	}
	system("pause");
	system("cls");
}
//���ձ������
void workManager::Sort_Emp() 
{
	if (this->m_FileIsEmpty) 
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		system("pause");
		system("cls");

	}
	else 
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1.��ְ���Ž�������" << endl;
		cout << "2.��ְ���Ž��н���" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0;i < m_EmpNum;i++) 
		{
			int minOrMax = i;//������Сֵ�����ֵ�±�
			for (int j = i + 1;j < this->m_EmpNum;j++)
			{
				if (select == 1)//���� 
				{
					if (this->m_empArray[minOrMax]->m_id > this->m_empArray[j]->m_id) 
					{
						minOrMax= j;
					}
				}
				else //����
				{
					if (this->m_empArray[minOrMax]->m_id < this->m_empArray[j]->m_id) 
					{
						minOrMax = j;
					}
				}
			}
			//�ж�һ��ʼ�϶���Сֵ�����ֵ�ǲ��Ǽ������Сֵ�����ֵ��������� ��������
			if(i!=minOrMax)
			{
				Worker* temp = this->m_empArray[i];
				this->m_empArray[i] = this->m_empArray[minOrMax];
				this->m_empArray[minOrMax] = temp;
			}
			
		}
		cout << "����ɹ�������Ľ��Ϊ��" << endl;
		this->save();
		this->Show_Emp();
	}
}
//����ļ�
void workManager::Clean_File() 
{
	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) 
	{
		//����ļ�
		ofstream ofs(FILENAME, ios::trunc);//ɾ���ļ������´���
		ofs.close();
		if (this->m_empArray != NULL) 
		{
			//ɾ��������ÿ��ְ������
			for (int i = 0;i < this->m_EmpNum;i++) 
			{
				delete this->m_empArray[i];
				this->m_empArray[i] = NULL;

			}
			//ɾ������������ָ��
			delete[] this->m_empArray;
			this->m_empArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;

		}
		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");
}