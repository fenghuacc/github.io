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
		cout<<"请输入你的选项："<<endl;
		cin>>choice;

		switch(choice)
		{
		case 0://退出职工管理系统
			wm.exitSystem();
			break;
		case 1://添加员工
			wm.addEmp();
			break;
		case 2://显示员工
			wm.showEmp();
			break;
		case 3://删除员工
			wm.delEmp();
			break;
		case 4://修改员工信息
			wm.udEmp();
			break;
		case 5://查找员工
			wm.findEmp();
			break;
		case 6://对员工按照编号排序
			wm.sortEmp();
			break;
		case 7://清空职工文件
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