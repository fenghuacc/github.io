#include"employee.h"

Employee::Employee(int id,string name,int did)
{
	this->w_id=id;
	this->w_name=name;
	this->w_did=did;
}
void Employee::showInfo()
{
	cout << "ְ����ţ�" << this->w_id
		<< "\tְ������: " << this->w_name
		<< "\t��λ��" << this->w_did
		<< "\t��ɾ��������" << endl;
}
string Employee::getDid()
{
	return string("Ա��");
}
void Employee::addEmp(Employee *emp)
{
	cout << "������Ҫ��ӵ�Ա�����: " << endl;
	int id=0;
	cin >> id;
	emp->w_id = id;

	cout << "������Ҫ��ӵ�Ա������: " << endl;
	string name;
	cin >> name;
	emp->w_name=name;

	cout << "������Ҫ��ӵ�Ա����λ���: " << endl;
	int did = 0;
	cin >> did;
	emp->w_did = did;
}
