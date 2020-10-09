#pragma once
#include<fstream>
#include"worker.h"
#include<iostream>
#define FileName "emp.txt"
using namespace std;

class WorkerManager
{
public:
	//构造函数
	WorkerManager();
	//交互菜单
	void ShowMenu();
	//析构函数
	~WorkerManager();
	//退出管理系统
	void exitSystem();
	//测试员工多态
	void test();
	//添加职工
	void addEmp();
	//对文件进行保存
	void save();
	//获取职工人数
	int getEmpNum();
	//显示职工信息
	void showEmp();
	//初始化职工数组
	void initEmp();
	//删除职工
	void delEmp();
	//获取职工索引
	int getIndex(int id);
	//修改职工信息
	void udEmp();
	//查找职工
	void findEmp();
	//按编号排序
	void sortEmp();
	//清空职工文件
	void clEmp();

	int m_EmpNum;
	Worker ** m_EmpArray;
	bool m_FileEmpty;//标志文件是否为空
};