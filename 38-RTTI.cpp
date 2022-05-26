#include<iostream>
#include <string>
using namespace std;

class Shape
{
public:
	virtual void Draw()=0;
	virtual ~Shape(){}
};

class Circle:public Shape
{
public:
	void Draw()
	{
		cout<<"Circle Draw..."<<endl;
	}
};
class Square:public Shape
{
public:
	void Draw()
	{
		cout<<"Square Draw..."<<endl;
	}
};



int main()
{
	Shape* p;
	Circle c;
	p=&c;//����ָ��ָ��������Ķ���
	p->Draw();//���ɻ���ָ������麯��,�����õ�����������麯��
//������ָ���ܾ���dynamic_cast���㡣�ܹ�����ת�������õ�����Circle��ָ��
	//������ָ�룬������ָ���ܹ�ת��������������������Circle�����
	if(dynamic_cast<Circle*>(p))//Ҫ�ڶ�̬��ϵ�ļ̳���ϵ��.���ǻ������麯��
	{
		cout<<"p is point to a Circle Object"<<endl;
		Circle* cp=dynamic_cast<Circle*>(p);//���ʵ�ʾ��ǰ�ȫ������ת��
		cp->Draw();
	}
	else if(dynamic_cast<Square*>(p))
	{
		cout<<"p is point to a Square Object"<<endl;
	}
	else
	{
		cout<<"p is point to a other Object"<<endl;
	}
	cout<<typeid(*p).name()<<endl;//���ص���type_info��name���Ƕ���ʵ�ʵ�����
	int len=strlen(typeid(*p).name())+1;
	char *newstr=new char[len];
	memset(newstr,0,len);
	memcpy(newstr,typeid(*p).name(),len-1);
	cout<<"ת���ɹ�:"<<newstr<<endl;
	delete[] newstr;

	if (typeid(Circle).name()==typeid(*p).name())//�������������ϻ������
	{
		cout<<"p is point to a Circle Object"<<endl;
		((Circle*)p)->Draw();
	}
	else if (typeid(Square).name()==typeid(*p).name())//�������������ϻ������
	{
		cout<<"p is point to a Circle Object"<<endl;
		((Square*)p)->Draw();
	}
	else
	{
		cout<<"p is point to a other Object"<<endl;
	}


	return 0;
}