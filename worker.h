#pragma once
#include<iostream>
#include<string>
using namespace std;

class Worker
{
public:
	virtual void showInfo()=0;
	virtual string getDid()=0;

	int w_id;
	string w_name;
	int w_did;
};

