//�ϰ壬ͬ���̳�worker.h
#pragma once
#include"worker.h"
#include<iostream>
using namespace std;

class Boss :public Worker
{
public:
	Boss(int id, string name, int dId);//���캯��
	virtual void showInfo();//��ʾְ��������Ϣ
	virtual string getDeptName();//��ȡ��λ����
};