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
	cout << "ְ����ţ�" << this->w_id
		<< "\tְ������: " << this->w_name
		<< "\t��λ��" << this->w_did
		<< "\t������ַ�����" << endl;
}
string Boss::getDid()
{
	return string("�ϰ�");
}