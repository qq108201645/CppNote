#include<iostream>
using namespace std;

class CObject
{
public:
	virtual void Serialize()
	{
		cout<<"Object::Serialize()..."<<endl;
	}
};

class CDocument:public CObject
{
	int data1_;
public:
	void func()
	{
		cout<<"CDocument::func()..."<<endl;
		Serialize();
	}
	void Serialize()
	{
		cout<<"CDocument::Serialize()..."<<endl;
	}
};
class CMydoc:public CDocument
{
public:
	int data2_;
	void Serialize()
	{
		cout<<"CMyodc::Serialize()..."<<endl;
	}
};

int main()
{
	CMydoc mydoc;
	CMydoc * pmydoc=new CMydoc;
	cout<<"#1 testing"<<endl;
	mydoc.func();

	cout<<"#2 testing"<<endl;
	((CDocument*)(&mydoc))->func();//ȡ��ַǿ��ת���ɻ����ָ��

	cout<<"#3 testing"<<endl;
	pmydoc->func();

	cout<<"#4 testing"<<endl;
	((CDocument)mydoc).func();//mydoc����ǿ��ת��ΪCDocument����



	return 0;
}