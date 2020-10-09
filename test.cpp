#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<iostream>
void test()
{
	Worker* worker = NULL;

	worker = new Employee(1, "aa", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "bb", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "cc", 3);
	worker->showInfo();
	delete worker;
}