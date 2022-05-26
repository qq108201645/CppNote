#include<iostream>
#include <string>
using namespace std;

class Manager;
class Manager2;

class Employee
{
  public:
	Employee(const string & name, const int age, const int deptno):name_(name), age_(age),
		deptno_(deptno)
	{

	}
	operator   Manager();
	operator   Manager2();
  private:
	string name_;
	int age_;
	int deptno_;
};

class Manager:public Employee
{
  public:
	Manager(const string & name, const int age, const int deptno, int level):Employee(name, age,
																					  deptno),
		level_(level)
	{

	}
	/* Manager(const Employee& other):Employee(other),level_(-1) {

	   } */
  private:
	int level_;
};

Employee::operator   Manager()
{
	return Manager(name_, age_, deptno_, -1);
}

class Manager2:private Employee
{
  public:
	Manager2(const string & name, const int age, const int deptno, int level):Employee(name, age,
																					   deptno),
		level_(level)
	{

	}
	/* Manager2(const Employee& other):Employee(other),level_(1) {

	   } */
  private:
	int level_;
};

Employee::operator   Manager2()
{
	return Manager2(name_, age_, deptno_, -1);
}

int main()
{
	Employee e1("����", 25, 20);
	Manager m1("����", 38, 20, 10);
	Manager2 m2("����", 40, 15, 8);
	Employee *pe;
	Manager *pm;
	Manager2 *pm2;

	pe = &e1;					// ����ָ��ָ��������(����)
	pm = &m1;					// ������ָ��ָ�����������(����)
	pm2 = &m2;
	// -------------------------------
	pe = &m1;					// ����ָ��ָ���м̳����������(����)//������ָ�����ת���ɻ���ָ��
	pe = pm;					// ����ָ�����ָ���м̳е�������ָ��
	pe = reinterpret_cast < Employee * >(pm2);	// ���಻��ָ��˽�м̳е�������ָ��,
	// ����ָ��ǿ��ת����˽�м̳е�������ָ��

	// ˽�м̳�������ָ�벻��ֱ��ת���ɻ���ָ��,����ǿ��ת��
	// --------------------------------------------------
	// pm=&e1;//���м̳�������ָ���޷�ָ��������(������)//��ָ�벻����ת���ɹ��м̳�������ָ��
	pm = static_cast < Manager * >(&e1);	// ���м̳�������ָ�����ָ��ǿ��ת���Ļ������
	pm = static_cast < Manager * >(pe);	// ����ָ���޷�ת���ɹ��м̳�������ָ��,������ǿ��ת��//����ȫ
	// --------------------------------------------------
	pm2 = reinterpret_cast < Manager2 * >(&e1);	// ˽�м̳�ֻ��ָ��ǿ��ת���Ļ������
	pm2 = reinterpret_cast < Manager2 * >(pe);	// ����ָ���޷�ת����˽�м̳�������ָ��,������ǿ��ת��//����ȫ


	e1 = m1;					// ������������ת���ɻ������//ת���������������еĳ�Ա��ʧ��

	// m1=reinterpret_cast<Manager>(e1);//���������ת�������������,�����������ָ��������


	// e1=static_cast<Employee>(m2);//˽����������󲻿���ת���ɻ������
	cout << "�������ת�����캯����" << endl;
	m1 = e1;					// Manager����ת�����캯��Manager(const 
								// 
	// Employee&
	// other):Employee(other),level_(-1)�����ת��
	m2 = e1;
}
