#pragma once
#include<fstream>
#include"worker.h"
#include<iostream>
#define FileName "emp.txt"
using namespace std;

class WorkerManager
{
public:
	//���캯��
	WorkerManager();
	//�����˵�
	void ShowMenu();
	//��������
	~WorkerManager();
	//�˳�����ϵͳ
	void exitSystem();
	//����Ա����̬
	void test();
	//���ְ��
	void addEmp();
	//���ļ����б���
	void save();
	//��ȡְ������
	int getEmpNum();
	//��ʾְ����Ϣ
	void showEmp();
	//��ʼ��ְ������
	void initEmp();
	//ɾ��ְ��
	void delEmp();
	//��ȡְ������
	int getIndex(int id);
	//�޸�ְ����Ϣ
	void udEmp();
	//����ְ��
	void findEmp();
	//���������
	void sortEmp();
	//���ְ���ļ�
	void clEmp();

	int m_EmpNum;
	Worker ** m_EmpArray;
	bool m_FileEmpty;//��־�ļ��Ƿ�Ϊ��
};