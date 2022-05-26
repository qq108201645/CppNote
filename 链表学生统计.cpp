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
		cout << "创建出错" << endl;
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
		cout << "头节点为空" << endl;
		exit(1);
	}

	Display(head_, sav);
	tmp = head_;
	head_ = head_->next_;
	delete[]tmp;
}

void Queue::Display(Student * node, int &sav)
{
	cout << "编号:" << node->num_ << " 姓名:" << node->name_ << " 年龄:" << node->
		age_ << " 分数:" << node->score_ << endl;
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
		cout << "请输入学生数量:" << endl;
		cin >> member;
		char name[100];
		int num, age, score;
		for (i = 0; i < member; i++)
		{
			cout << "请输入第" << i + 1 << "个学生信息" << endl;
			cout << "输入编号:";
			cin >> num;
			cout << "输入姓名:";
			cin >> name;

			cout << "输入年纪:";
			cin >> age;
			cout << "输入分数:";
			cin >> score;
			p->Input(name, num, age, score);
			cout << endl;
		}
		sav = 0;
		for (i = 0; i < member; i++)
			p->Out(sav);
		cout << "不及格有" << sav << "个" << endl;
		cout << "是否重新开始Y/N:" << endl;
		cin >> Enter;
		while (Enter != 'y'  &&Enter != 'Y' &&Enter != 'n' &&Enter != 'N')
		{
			cout << "输入错误请重新输入" << endl;
			cout << "是否重新开始Y/N:" << endl;
			cin >> Enter;

		}
		if (Enter != 'y' && Enter != 'Y')	
			break;

		system("cls");
	}
	cout<<"退出成功"<<endl;
}
