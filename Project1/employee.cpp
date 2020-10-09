#include"employee.h"

Employee::Employee(int id,string name,int did)
{
	this->w_id=id;
	this->w_name=name;
	this->w_did=did;
}
void Employee::showInfo()
{
	cout << "职工编号：" << this->w_id
		<< "\t职工姓名: " << this->w_name
		<< "\t岗位：" << this->w_did
		<< "\t完成经理的任务" << endl;
}
string Employee::getDid()
{
	return string("员工");
}
void Employee::addEmp(Employee *emp)
{
	cout << "请输入要添加的员工编号: " << endl;
	int id=0;
	cin >> id;
	emp->w_id = id;

	cout << "请输入要添加的员工姓名: " << endl;
	string name;
	cin >> name;
	emp->w_name=name;

	cout << "请输入要添加的员工岗位编号: " << endl;
	int did = 0;
	cin >> did;
	emp->w_did = did;
}
