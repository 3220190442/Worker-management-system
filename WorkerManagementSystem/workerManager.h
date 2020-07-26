#pragma once
#include<iostream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "EmpFile.txt"
using namespace std;

class WorkManager
{
public:

	WorkManager();//���캯��

	void Show_Menu();//��ʾ�˵�

	void Exit();//�˳�ϵͳ

	int m_EmpNum;//��¼ְ������

	Worker** m_EmpArray;//ְ������ָ��

	void Add_Emp();//���ְ��

	void save();//�����ļ�

	bool m_FileIsEmpty;//�ж��ļ��Ƿ�Ϊ��

	int get_EmpNum();//ͳ���ļ����Ѿ���¼������

	void init_Emp();//��ʼ��Ա�������ļ���������

	void Show_Emp();//��ʾְ����Ϣ

	void Del_Emp();//ɾ��ְ��

	int SomeOneIsExist(int id);//�ж�ְ���Ƿ���ڣ����򷵻�����λ�ã������ڷ���-1

	void Mod_Emp();//�޸�ְ����Ϣ

	void Find_Emp();//����ĳְ��

	void Sort_Emp();//����

	void Clean_File();//����ļ�

	~WorkManager();//��������

};
