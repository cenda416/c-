#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>
using namespace std;
#include"worker.h"
#include "employee.h"
#include "boss.h"
#include"manager.h"
#include<fstream>
#define FILENAME "emoFile.txt"
class workManager 
{
public:
	workManager();
	
	void show_Menu();//չʾ�˵��ĺ���
	void exitSystem();
	//��¼ְ������
	int m_EmpNum;
	//ְ�������ָ��
	Worker** m_empArray;
	//���ְ��
	void Add_Emp();
	//�����ļ�
	void save();
	//�ж��ļ��Ƿ�Ϊ�յı�־
	bool m_FileIsEmpty;
	//ͳ���ļ�������
	int get_Empnum();
	//��ʼ��Ա��
	void init_Emp();
	//��ʾְ��
	void Show_Emp();
	//ɾ��ְ��
	void Del_Emp();
	//�ж�ְ���Ƿ���� ������ڷ���ְ�����������е�λ�ã������ڷ���-1��
	int IsExist(int id);
	//�޸�ְ��
	void Mod_Emp();
	//����ְ��
	void Find_Emp();
	//���ձ������
	void Sort_Emp();
	//����ļ�
	void Clean_File();
	~workManager();
};
