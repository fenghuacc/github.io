#include"workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

WorkerManager::WorkerManager()//构造函数
{
	this->m_EmpNum = 0;
	this->m_EmpArray = NULL;

	ifstream ifs;
	ifs.open(FileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在!!!  " << endl;
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
		cout << "文件为空!!!  " << endl;
		this->m_FileEmpty = true;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}
	int num = this->getEmpNum();
	cout << "职工人数为: " << num << endl;
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//初始化职工
	initEmp();

	this->m_FileEmpty = false;
}
WorkerManager::~WorkerManager()//析构函数
{
	if (this->m_EmpArray!=NULL)
	{
		delete[] this->m_EmpArray;
	}
}
void WorkerManager::ShowMenu()//显示菜单
{
	cout << "\t\t\t\t\t----------------------------\n" << endl;
	cout << "\t\t\t\t\t|---欢迎使用职工管理系统---|\n" << endl;
	cout << "\t\t\t\t\t|   1、添加职工信息        |\n" << endl;
	cout << "\t\t\t\t\t|   2、显示职工信息        |\n" << endl;
	cout << "\t\t\t\t\t|   3、删除职工信息        |\n" << endl;
	cout << "\t\t\t\t\t|   4、修改职工信息        |\n" << endl;
	cout << "\t\t\t\t\t|   5、查找职工信息        |\n" << endl;
	cout << "\t\t\t\t\t|   6、按职工编号进行排序  |\n" << endl;
	cout << "\t\t\t\t\t|   7、清空职工文件       |\n" << endl;
	cout << "\t\t\t\t\t|   0、退出管理系统        |\n" << endl;
	cout << "\t\t\t\t\t----------------------------\n" << endl;
}
void WorkerManager::exitSystem()//退出管理系统
{
	cout << "欢迎下次使用!!" << endl;
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

	cout << "请输入要添加职工的人数: " << endl;
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

			cout << "请输入第" << i + 1 << "个职工的编号:" << endl;
			cin >> id;
			
			cout << "请输入第" << i + 1 << "个职工的姓名:" << endl;
			cin >> name;

			cout << "请输入职工的岗位: " << endl;
			cout << "1,普通员工" << endl;
			cout << "2,经理" << endl;
			cout << "3,老板" << endl;
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
		cout << "成功添加" << addNum << "名员工!" << endl;
		this->save();
	}
	else
	{
		cout << "输入错误!" << endl;
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
		cout << "文件不存在或为空!!!" << endl;
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
		//根据不同的部门Id创建不同对象
		if (dId == 1)  // 1普通员工
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2) //2经理
		{
			worker = new Manager(id, name, dId);
		}
		else //总裁
		{
			worker = new Boss(id, name, dId);
		}
		//存放在数组中
		this->m_EmpArray[index] = worker;
		index++;
	}
}

void WorkerManager::delEmp()
{
	cout << "请输入要删除职工的编号: " << endl;
	int id=0;
	cin >> id;
	int index = getIndex(id);
	
	if (this->m_FileEmpty)
	{
		cout << "文件为空或不存在!!!" << endl;
	}
	else
	{
		if (index == -1)
		{
			cout << "没有该职工!!!" << endl;
		}
		else
		{
			for (int i = index; i < this->m_EmpNum; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->save();
			cout << "删除成功!!!" << endl;
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
	cout << "请输入要修改职工的编号: " << endl;
	int id = 0;
	cin >> id;
	int index = getIndex(id);

	if (this->m_FileEmpty)
	{
		cout << "文件为空或不存在!!!" << endl;
	}
	else
	{
		if (index == -1)
		{
			cout << "没有该职工!!!" << endl;
		}
		else
		{
			/*int id=0;
			cout << "请输入修改后的id: " << endl;
			cin >> id;
			this->m_EmpArray[index]->w_id = id;

			string name;
			cout << "请输入修改后的name: " << endl;
			cin >> name;
			this->m_EmpArray[index]->w_name=name;

			int did = 0;
			cout << "请输入修改后的did: " << endl;
			cin >> did;
			this->m_EmpArray[index]->w_did = did;

			this->save();
			cout << "修改成功!!!" << endl;*/
			int nid = 0;
			string nname = "";
			int ndid = 0;

			cout << "查到" << id << "号职工,请输入修改后的职工号:" << endl;
			cin >> nid;

			cout << "请输入修改后的姓名:" << endl;
			cin >> nname;

			cout << "请输入修改后的部门:" << endl;
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
			cout << "修改成功" << endl;
			this->save();
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::findEmp()
{
	cout << "请输入要查找职工的编号: " << endl;
	int id = 0;
	cin >> id;
	int index = getIndex(id);

	if (this->m_FileEmpty)
	{
		cout << "文件为空或不存在!!!" << endl;
	}
	else
	{
		if (index == -1)
		{
			cout << "没有该职工!!!" << endl;
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
	cout << "成功排序" << endl;*/
	if (this->m_FileEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
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
		cout << "文件不存在或已清空!!!" << endl;
	}
	else
	{
		int choice = -1;
		cout << "是否清空职工文件:" << endl;
		cout << "1:确认" << endl;
		cout << "0:取消" << endl;
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
			cout << "清空职工文件!!!" << endl;
		}
		
	}
}

