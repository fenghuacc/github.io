#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<iostream>
using namespace std;

int main()
{
	WorkerManager wm;
	//wm.test();
	int choice=0;
	while(true)
	{
		wm.ShowMenu();
		cout<<"���������ѡ�"<<endl;
		cin>>choice;

		switch(choice)
		{
		case 0://�˳�ְ������ϵͳ
			wm.exitSystem();
			break;
		case 1://���Ա��
			wm.addEmp();
			break;
		case 2://��ʾԱ��
			wm.showEmp();
			break;
		case 3://ɾ��Ա��
			wm.delEmp();
			break;
		case 4://�޸�Ա����Ϣ
			wm.udEmp();
			break;
		case 5://����Ա��
			wm.findEmp();
			break;
		case 6://��Ա�����ձ������
			wm.sortEmp();
			break;
		case 7://���ְ���ļ�
			wm.clEmp();
			break;
		default:
			system("cls");
			break;
		}
		
	}
	system("pause");
	return 0;
}