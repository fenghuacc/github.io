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
	cout << "ְ����ţ�" << this->w_id 
	     << "\tְ������: " << this->w_name 
		 << "\t��λ��" << this->w_did 
		 << "\t����ϰ������,��Ա���ַ�����" << endl;
}
string Manager::getDid()
{
	return string("����");
}