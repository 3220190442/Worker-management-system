//普通员工，继承worker.h
#pragma once
#include"worker.h"
#include<iostream>
using namespace std;

class Employee :public Worker
{
public:
	Employee(int id,string name,int dId);//构造函数
	virtual void showInfo();//显示职工所有信息
	virtual string getDeptName();//获取岗位名称
};
