#pragma once
#include"boss.h"

Boss::Boss(int id, string name, int did)
{
	this->w_id = id;
	this->w_name = name;
	this->w_did = did;
}
void Boss::showInfo()
{
	cout << "职工编号：" << this->w_id
		<< "\t职工姓名: " << this->w_name
		<< "\t岗位：" << this->w_did
		<< "\t给经理分发任务" << endl;
}
string Boss::getDid()
{
	return string("老板");
}