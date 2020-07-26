#include "workerManager.h"

WorkManager::WorkManager()//��ɹ��캯��
{
	//1�����ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		//��ʼ����¼����Ϊ0
		this->m_EmpNum = 0;
		//��ʼ������ָ��Ϊ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2���ļ����ڣ���Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//�ļ�Ϊ��
		cout << "�ļ������ݣ�" << endl;
		//��ʼ����¼����Ϊ0
		this->m_EmpNum = 0;
		//��ʼ������ָ��Ϊ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3���ļ������Ҳ�Ϊ��
	int num = this->get_EmpNum();
	cout <<  endl;
	cout << "\t\tְ������ϵͳ" << endl;
	cout << endl;
	cout << "\t\t *��ϢԤ��*" << endl;
	cout << endl;
	cout << "�ӱ����ļ��ж�ȡ�õ�ǰ��ְ������" << num << "\t��ϸ�������£�" << endl << endl;
	this->m_EmpNum = num;
	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//���ó�ʼ�����������ļ��е����ݶ�ȡ��������
	this->init_Emp();
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "ְ����ţ�" << this->m_EmpArray[i]->m_ID
			<< "\tְ��������" << this->m_EmpArray[i]->m_Name
			<< "\t���ű�ţ�" << this->m_EmpArray[i]->m_DeptID << endl;
	}
	cout << endl << endl << "�����˵���" << endl;
}

void WorkManager::Show_Menu()//��ʾ�˵�
{
	cout << "***********************************************" << endl;
	cout << "**********   ��ӭʹ��ְ������ϵͳ��  **********" << endl;
	cout << "*************   0.�˳��������   **************" << endl;
	cout << "*************   1.���ְ����Ϣ   **************" << endl;
	cout << "*************   2.��ʾְ����Ϣ   **************" << endl;
	cout << "*************   3.ɾ����ְԱ��   **************" << endl;
	cout << "*************   4.�༭ְ����Ϣ   **************" << endl;
	cout << "*************   5.����ְ����Ϣ   **************" << endl;
	cout << "*************   6.���ձ������   **************" << endl;
	cout << "*************   7.�����Ϣ�ĵ�   **************" << endl;
	cout << "***********************************************" << endl;
	cout << endl;
}

void WorkManager::Exit()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

void WorkManager::Add_Emp()//���ְ��
{
	cout << "�������������ְ��������" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0) {
		//����ռ�Ĵ�С
		int newSize = this->m_EmpNum + addNum;//�¿ռ�����=ԭ����¼��+������
		Worker** newSpace = new Worker * [newSize];
		//��ԭ���ռ��µ����ݣ��������¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//���������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;//����
			cout << "�������" << i + 1 << "����ְ���� ��ţ�" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ���� ������" << endl;
			cin >> name;
			cout << "��ѡ���" << i + 1 << "����ְ���� ��λ��" << endl;
			cout << "1.Ա��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//������ְ��ְ�𣬱��浽������
			newSpace[this->m_EmpNum + i] = worker;
		}
		//�ͷ�ԭ�ռ�
		delete[] this->m_EmpArray;
		//��ָ��ָ���¿��ٵĿռ�
		this->m_EmpArray = newSpace;
		//���´�ʱԱ��������
		this->m_EmpNum = newSize;
		//����ɹ���ӵ���Ϣ
		cout << "�ɹ������" << addNum << "����ְ����" << endl;
		//�ļ�Ϊ�ձ�־����
		this->m_FileIsEmpty = false;
		//���浽�ļ���
		this->save();
	}
	else
	{
		cout << "�Ƿ�����" << endl;
	}
	//������������������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");

}

void WorkManager::save()//�����ļ�
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//�������ʽ�Ĵ��ļ�����д�ļ�
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptID << endl;
	}
	ofs.close();
}

int WorkManager::get_EmpNum()//ͳ���ļ��м�¼������
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;//�ļ��ж���һ����ͳ��һ������
	}
	return num;
}

void WorkManager::init_Emp()//��ʼ��Ա�������ļ��е��˷����ض���һ��������
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)//��ͨԱ��
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)//����
		{
			worker = new Manager(id, name, dId);
		}
		else//�ϰ�
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();


}

void WorkManager::Show_Emp()//��ʾְ����Ϣ
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "����ʾ���������⣺�ļ�Ϊ�գ��ļ�������/�ļ������ݣ���" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();//���ö�̬��ӡÿ�����Ա����Ϣ
		}
	}
	//�����������
	system("pause");
	system("cls");

}


void WorkManager::Del_Emp()//ɾ��ְ����������ɾ������ǰ�ƣ���Ҫ���������¼������1
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������Ҫɾ����ְ���ı�ţ�" << endl;
		int id = 0;
		cin >> id;
		int index = this->SomeOneIsExist(id);
		string del_name = this->m_EmpArray[index]->m_Name;
		if (index != -1)
		{
			//������-1˵��ְ�����ڣ�����Ҫ��ָ��λ�ÿ�ʼǰ�Ƹ���
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;

			//�������Ѿ�ɾ���ˣ���������-1��������Ҫ�ѽ���������ļ���
			this->save();
			cout << "�ѳɹ�ɾ����" << del_name << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�û�иñ��ְ��" << endl;
		}
	}
	//�����������
	system("pause");
	system("cls");


}

int WorkManager::SomeOneIsExist(int id)//�ж�ְ���Ƿ���ڣ���ɾ�������ã����򷵻�����λ�ã������ڷ���-1
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_ID == id)
		{
			//�ҵ���ָ����ŵ�ְ��
			index = i;
			break;
		}
	}
	return index;
}

void WorkManager::Mod_Emp()//�޸�ְ����Ϣ
{
	if (this->m_FileIsEmpty) { cout << "�ļ������ڻ�����Ϊ��" << endl; }
	else {
		cout << "��������Ҫ�޸ĵ�ְ���ı�ţ�" << endl;
		int id;
		cin >> id;
		int result = this->SomeOneIsExist(id);
		if (result != -1)
		{
			//����ô����
			delete this->m_EmpArray[result];//��ԭ������ɾ�������½�һ��
			int newId = 0;
			string newName = "";
			int newdSelect = 0;
			cout << "�Բ�ѯ����ְ�����������µı�ţ�" << endl;
			cin >> newId;
			cout << "�������µ�������" << endl;
			cin >> newName;
			cout << "��ѡ���µĸ�λ��1.Ա�� 2.���� 3.�ϰ�" << endl;
			cin >> newdSelect;
			//���ݲ�ͬ�ĸ�λѡ�񣬽�����������ͬ�Ķ���
			//�ȴ���һ�������ָ��
			Worker* worker = NULL;
			switch (newdSelect)
			{
			case 1:
				worker = new Employee(newId, newName, newdSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, newdSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, newdSelect);
				break;
			default:
				break;
			}

			//���µ�������
			this->m_EmpArray[result] = worker;
			cout << "�޸ĳɹ�" << endl;
			//�����ļ�
			this->save();
		}
		else
		{
			cout << "�ñ��ְ�������ڣ�" << endl;
		}
	}
	//�����������
	system("pause");
	system("cls");
}

void WorkManager::Find_Emp()//����ĳְ��
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�������" << endl;
	}
	else
	{
		cout << "��ѡ����ҷ�ʽ��" << endl;
		cout << "1.��ְ���ı�Ų�ѯ" << endl;
		cout << "2.��ְ����������ѯ" << endl;
		int select;
		cin >> select;
		if (select == 1)
		{
			//�û�ѡ���˰���Ų���
			int id;
			cout << "��������Ҫ���ҵ�ְ����ţ�" << endl;
			cin >> id;
			int result = SomeOneIsExist(id);
			if (result != -1)
			{
				cout << "��ѯ�ɹ�����Ϣ���£�" << endl;
				this->m_EmpArray[result]->showInfo();
			}
			else {
				cout << "û���ҵ��ñ���û���" << endl;
			}
		}
		else if (select == 2)
		{
			//����������
			string name;
			cout << "��������Ҫ���ҵ�ְ��������" << endl;
			cin >> name;
			bool flag = false;//����һ����־��Ĭ��false����û���ҵ�
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҵ����Ϊ"
						<< this->m_EmpArray[i]->m_ID
						<< "��Ա������Ϣ���£�" << endl;

					flag = true;//һ������if�У��͸�Ϊtrue����������һ����������������

					this->m_EmpArray[i]->showInfo();//������ʾ��Ϣ�Ľӿ�
				}
			}
			if (flag == false)//ѭ�������˻���false��־�Ļ�...
			{
				cout << "û���ҵ��������û���" << endl;
			}
		}
		else
		{
			cout << "�Ƿ����룡" << endl;
		}
	}
	//�����������
	system("pause");
	system("cls");
}


void WorkManager::Sort_Emp()//����
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�������" << endl;
		//�����������
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ�񰴱������ķ�ʽ��1.���� 2.����" << endl;
		int select = 0;
		cin >> select;

		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;//������Сֵ�����ֵ���±꣨��ȷ��������

			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)//����
				{
					if (this->m_EmpArray[minOrMax]->m_ID > this->m_EmpArray[j]->m_ID)
					{
						minOrMax = j;
					}
				}
				else if (select == 2)//����
				{
					if (this->m_EmpArray[minOrMax]->m_ID < this->m_EmpArray[j]->m_ID)
					{
						minOrMax = j;
					}
				}
				else
				{
					cout << "�Ƿ�����" << endl;
				}
			}
			//�ж�һ��ʼ�϶�����ֵ�ǲ�����ʵ����ֵ��������ǣ��򽻻�����
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "���������£�" << endl;
		this->save();//�����Ķ��ļ��е�˳����������У������źõ����鱣�浽�ļ���
		this->Show_Emp();

	}

}


void WorkManager::Clean_File()//����ļ�
{
	cout << "�˲���������ת��ȷ������ļ���" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "���������룺" << endl;
		string key = "";
		cin >> key;
		if (key == "����")
		{
			//����ļ�
			ofstream ofs(FILENAME, ios::trunc);//ɾ���ļ������´���
			ofs.close();

			if (this->m_EmpArray != NULL)//������鲻Ϊ�գ����ÿ�ÿ����Ϊ���Ԫ��
			{
				//ɾ������ÿ��ְ������
				for (int i = 0; i < m_EmpNum; i++)
				{
					delete this->m_EmpArray[i];//ÿ��ְ������ɾ��
					this->m_EmpArray[i] = NULL;//ÿ��ְ��ָ���ÿ�
				}
				//ɾ����������ָ��
				delete[] this->m_EmpArray;//���鱾��ɾ��
				this->m_EmpArray = NULL;//����ָ���ÿ�

				this->m_EmpNum = 0;
				this->m_FileIsEmpty = true;
			}
			cout << "�ļ�����գ�" << endl;

		}
		else
		{
			cout << "�������" << endl;
			return;
		}
		//�����������
		system("pause");
		system("cls");
	}	
	else
	{
		//2 fanhui
		system("cls");
	}
}

WorkManager::~WorkManager()
{
	if (this->m_EmpArray != NULL)//������鲻Ϊ�գ����ÿ�ÿ����Ϊ���Ԫ��
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}