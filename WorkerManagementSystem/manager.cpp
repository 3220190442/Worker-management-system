#include"manager.h"

Manager::Manager(int id, string name, int dId)//���캯��
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = dId;
}
void Manager::showInfo()//��ʾְ��������Ϣ
{
	cout << "ְ����ţ�" << this->m_ID
		<< "\tְ��������" << this->m_Name
		<< "\tְ����λ��" << this->getDeptName()
		<< "\t��λְ��" << "��������" << endl;
}
string Manager::getDeptName()//��ȡ��λ����
{
	return string("����");
}