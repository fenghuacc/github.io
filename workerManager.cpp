#include"workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

WorkerManager::WorkerManager()//���캯��
{
	this->m_EmpNum = 0;
	this->m_EmpArray = NULL;

	ifstream ifs;
	ifs.open(FileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������!!!  " << endl;
		this->m_FileEmpty = true;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��!!!  " << endl;
		this->m_FileEmpty = true;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}
	int num = this->getEmpNum();
	cout << "ְ������Ϊ: " << num << endl;
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//��ʼ��ְ��
	initEmp();

	this->m_FileEmpty = false;
}
WorkerManager::~WorkerManager()//��������
{
	if (this->m_EmpArray!=NULL)
	{
		delete[] this->m_EmpArray;
	}
}
void WorkerManager::ShowMenu()//��ʾ�˵�
{
	cout << "\t\t\t\t\t----------------------------\n" << endl;
	cout << "\t\t\t\t\t|---��ӭʹ��ְ������ϵͳ---|\n" << endl;
	cout << "\t\t\t\t\t|   1�����ְ����Ϣ        |\n" << endl;
	cout << "\t\t\t\t\t|   2����ʾְ����Ϣ        |\n" << endl;
	cout << "\t\t\t\t\t|   3��ɾ��ְ����Ϣ        |\n" << endl;
	cout << "\t\t\t\t\t|   4���޸�ְ����Ϣ        |\n" << endl;
	cout << "\t\t\t\t\t|   5������ְ����Ϣ        |\n" << endl;
	cout << "\t\t\t\t\t|   6����ְ����Ž�������  |\n" << endl;
	cout << "\t\t\t\t\t|   7�����ְ���ļ�       |\n" << endl;
	cout << "\t\t\t\t\t|   0���˳�����ϵͳ        |\n" << endl;
	cout << "\t\t\t\t\t----------------------------\n" << endl;
}
void WorkerManager::exitSystem()//�˳�����ϵͳ
{
	cout << "��ӭ�´�ʹ��!!" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::test()
{
	Worker* worker = NULL;

	worker = new Employee(1,"aa",1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2,"bb",2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3,"cc",3);
	worker->showInfo();
	delete worker;
}

void WorkerManager::addEmp()
{

	cout << "������Ҫ���ְ��������: " << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum>0)
	{
		int newSize = this->m_EmpNum + addNum;
		Worker** newSpace = new Worker * [newSize];
		if (this->m_EmpArray!=NULL)
		{
			for (int i = 0; i<this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int did;

			cout << "�������" << i + 1 << "��ְ���ı��:" << endl;
			cin >> id;
			
			cout << "�������" << i + 1 << "��ְ��������:" << endl;
			cin >> name;

			cout << "������ְ���ĸ�λ: " << endl;
			cout << "1,��ͨԱ��" << endl;
			cout << "2,����" << endl;
			cout << "3,�ϰ�" << endl;
			cin >> did;

			Worker* worker = NULL;
			switch (did)
			{
			case 1:
				worker = new Employee(id,name,1);
				break;
			case 2:
				worker = new Manager(id,name,2);
				break;
			case 3:
				worker = new Boss(id,name,3);
				break;
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;
		}
		
		delete[] this->m_EmpArray;
		this->m_EmpArray = newSpace;
		this->m_EmpNum = newSize;

		this->m_FileEmpty = false;
		cout << "�ɹ����" << addNum << "��Ա��!" << endl;
		this->save();
	}
	else
	{
		cout << "�������!" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FileName,ios::out);

	for (int i = 0; i <this->m_EmpNum ; i++)
	{
		ofs <<  this->m_EmpArray[i]->w_did << " "
			<<  this->m_EmpArray[i]->w_name << " "
			<<  this->m_EmpArray[i]->w_did << endl;
	}
	ofs.close();
}

int WorkerManager::getEmpNum()
{
	ifstream ifs;
	ifs.open(FileName,ios::in);

	int id;
	string name;
	int did;

	int num = 0;
	while (ifs >> id  &&  ifs >> name &&  ifs >> did)
	{
		num++;
	}
	ifs.close();
	return num;
}

void WorkerManager::showEmp()
{
	if (this->m_FileEmpty)
	{
		cout << "�ļ������ڻ�Ϊ��!!!" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::initEmp()
{
	ifstream ifs;
	ifs.open(FileName, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		//���ݲ�ͬ�Ĳ���Id������ͬ����
		if (dId == 1)  // 1��ͨԱ��
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2) //2����
		{
			worker = new Manager(id, name, dId);
		}
		else //�ܲ�
		{
			worker = new Boss(id, name, dId);
		}
		//�����������
		this->m_EmpArray[index] = worker;
		index++;
	}
}

void WorkerManager::delEmp()
{
	cout << "������Ҫɾ��ְ���ı��: " << endl;
	int id=0;
	cin >> id;
	int index = getIndex(id);
	
	if (this->m_FileEmpty)
	{
		cout << "�ļ�Ϊ�ջ򲻴���!!!" << endl;
	}
	else
	{
		if (index == -1)
		{
			cout << "û�и�ְ��!!!" << endl;
		}
		else
		{
			for (int i = index; i < this->m_EmpNum; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->save();
			cout << "ɾ���ɹ�!!!" << endl;
		}
	}
	system("pause");
	system("cls");
	
}

int WorkerManager::getIndex(int id)
{
	int index = -1;
	for (int i = 0; i < m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->w_id==id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::udEmp()
{
	cout << "������Ҫ�޸�ְ���ı��: " << endl;
	int id = 0;
	cin >> id;
	int index = getIndex(id);

	if (this->m_FileEmpty)
	{
		cout << "�ļ�Ϊ�ջ򲻴���!!!" << endl;
	}
	else
	{
		if (index == -1)
		{
			cout << "û�и�ְ��!!!" << endl;
		}
		else
		{
			/*int id=0;
			cout << "�������޸ĺ��id: " << endl;
			cin >> id;
			this->m_EmpArray[index]->w_id = id;

			string name;
			cout << "�������޸ĺ��name: " << endl;
			cin >> name;
			this->m_EmpArray[index]->w_name=name;

			int did = 0;
			cout << "�������޸ĺ��did: " << endl;
			cin >> did;
			this->m_EmpArray[index]->w_did = did;

			this->save();
			cout << "�޸ĳɹ�!!!" << endl;*/
			int nid = 0;
			string nname = "";
			int ndid = 0;

			cout << "�鵽" << id << "��ְ��,�������޸ĺ��ְ����:" << endl;
			cin >> nid;

			cout << "�������޸ĺ������:" << endl;
			cin >> nname;

			cout << "�������޸ĺ�Ĳ���:" << endl;
			cin >> ndid;

			Worker* worker = NULL;
			switch (ndid)
			{
			case 1:
				worker = new Employee(nid,nname,ndid);
				break;
			case 2:
				worker = new Manager(nid, nname, ndid);
				break;
			case 3:
				worker = new Boss(nid, nname, ndid);
				break;
			default:
				break;
			}
			this->m_EmpArray[id] = worker;
			cout << "�޸ĳɹ�" << endl;
			this->save();
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::findEmp()
{
	cout << "������Ҫ����ְ���ı��: " << endl;
	int id = 0;
	cin >> id;
	int index = getIndex(id);

	if (this->m_FileEmpty)
	{
		cout << "�ļ�Ϊ�ջ򲻴���!!!" << endl;
	}
	else
	{
		if (index == -1)
		{
			cout << "û�и�ְ��!!!" << endl;
		}
		else
		{
			this->m_EmpArray[index]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::sortEmp()
{
	/*for (int i = 0; i < m_EmpNum-1; i++)
	{
		for (int j = 0; j < m_EmpNum-i-1; i++)
		{
			if (this->m_EmpArray[j]->w_id > this->m_EmpArray[j+1]->w_id)
			{
				Worker *tmp=this->m_EmpArray[j];
				this->m_EmpArray[j] = this->m_EmpArray[j + 1];
				this->m_EmpArray[j + 1] = tmp;
			}
		}
	}
	showEmp();
	cout << "�ɹ�����" << endl;*/
	if (this->m_FileEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			for (int j = 0; j < this->m_EmpNum - 1; j++)
			{
				if (this->m_EmpArray[j]->w_id > this->m_EmpArray[j + 1]->w_id)
				{
					Worker* tmp = this->m_EmpArray[j];
					this->m_EmpArray[j] = this->m_EmpArray[j + 1];
					this->m_EmpArray[j + 1] = tmp;
				}
			}
		}
		this->save();
		this->showEmp();
	}
}

void WorkerManager::clEmp()
{
	if (this->m_FileEmpty)
	{
		cout << "�ļ������ڻ������!!!" << endl;
	}
	else
	{
		int choice = -1;
		cout << "�Ƿ����ְ���ļ�:" << endl;
		cout << "1:ȷ��" << endl;
		cout << "0:ȡ��" << endl;
		cin >> choice;

		if (choice==1)
		{
			ofstream ofs;
			ofs.open(FileName, ios::trunc);
			this->m_FileEmpty = true;
			this->m_EmpNum = 0;
			this->m_EmpArray = NULL;
			this->save();
			ofs.close();
			cout << "���ְ���ļ�!!!" << endl;
		}
		
	}
}

