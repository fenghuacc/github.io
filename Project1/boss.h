#pragma once
#include"worker.h"
#include<iostream>
using namespace std;

class  Boss:public Worker
{
public:
	Boss(int id, string name, int did);
	virtual void showInfo();
	virtual string getDid();
};

