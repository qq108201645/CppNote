#include<iostream>
#include<string>
using namespace std;

class Student
{
public:
	char name_[100];
	int num_;
	int age_;
	int score_;
	Student *head_, *saved_, *next_;
public:
	Student()
	{
		head_ = saved_ = next_ = NULL;
	}
	virtual void Input(char* name, int num, int age, int score) = 0;
	virtual void Out(int &sav) = 0;
	virtual void Display(Student * node, int &sav) = 0;
};

class Queue:public Student
{
public:
	void Input(char* name, int num, int age, int score);
	void Out(int &sav);
	void Display(Student * node, int &sav);
};
void Queue::Input(char* name, int num, int age, int score)
{
	Student *node = new Queue;
	if (!node)
	{
		cout << "��������" << endl;
		exit(1);
	}
	memset(node->name_,0,strlen(node->name_));
	strcpy(node->name_ , name);
	node->num_ = num;
	node->age_ = age;
	node->score_ = score;
	if (saved_)
		saved_->next_ = node;
	saved_ = node;
	if (!head_)
		head_ = saved_;
}

void Queue::Out(int &sav)
{
	Student *tmp;
	if (!head_)
	{
		cout << "ͷ�ڵ�Ϊ��" << endl;
		exit(1);
	}

	Display(head_, sav);
	tmp = head_;
	head_ = head_->next_;
	delete[]tmp;
}

void Queue::Display(Student * node, int &sav)
{
	cout << "���:" << node->num_ << " ����:" << node->name_ << " ����:" << node->
		age_ << " ����:" << node->score_ << endl;
	if (node->score_ < 60)
		sav++;
}

int main()
{
	Student *p;
	Queue queue;
	p = &queue;
	int member, i, sav;
	char Enter;
	while (1)
	{
		cout << "������ѧ������:" << endl;
		cin >> member;
		char name[100];
		int num, age, score;
		for (i = 0; i < member; i++)
		{
			cout << "�������" << i + 1 << "��ѧ����Ϣ" << endl;
			cout << "������:";
			cin >> num;
			cout << "��������:";
			cin >> name;

			cout << "�������:";
			cin >> age;
			cout << "�������:";
			cin >> score;
			p->Input(name, num, age, score);
			cout << endl;
		}
		sav = 0;
		for (i = 0; i < member; i++)
			p->Out(sav);
		cout << "��������" << sav << "��" << endl;
		cout << "�Ƿ����¿�ʼY/N:" << endl;
		cin >> Enter;
		while (Enter != 'y'  &&Enter != 'Y' &&Enter != 'n' &&Enter != 'N')
		{
			cout << "�����������������" << endl;
			cout << "�Ƿ����¿�ʼY/N:" << endl;
			cin >> Enter;

		}
		if (Enter != 'y' && Enter != 'Y')	
			break;

		system("cls");
	}
	cout<<"�˳��ɹ�"<<endl;
}
