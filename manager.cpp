#pragma once
#include"manager.h"

Manager::Manager(int id, string name, int did)
{
	this->w_id = id;
	this->w_name = name;
	this->w_did = did;
}
void Manager::showInfo()
{
	cout << "职工编号：" << this->w_id 
	     << "\t职工姓名: " << this->w_name 
		 << "\t岗位：" << this->w_did 
		 << "\t完成老板的任务,给员工分发任务" << endl;
}
string Manager::getDid()
{
	return string("经理");
}