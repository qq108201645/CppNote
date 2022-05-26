/*
#include<iostream>
using namespace std;

class Base
{
public:
	virtual void Fun1()
	{
		cout<<"Base::Fun1()..."<<endl;
	}
	virtual void Fun2()
	{
		cout<<"Base::Fun2()..."<<endl;
	}

	void Fun3()
	{
		cout<<"Base::Fun3()..."<<endl;
	}
	
};

class Derived:public Base
{
public:
	 void Fun1()
	{
		cout<<"Derived::Fun1()..."<<endl;
	}
	void Fun2()
	{
		cout<<"Derived::Fun2()..."<<endl;
	}
	void Fun3()
	{
		cout<<"Derived::Fun3()..."<<endl;
	}
	
};





int main()
{
	
	Base *p;
	Derived d;
	p=&d;
	p->Fun1();//Fun1���麯��,�����ָ��ָ�����������ʱ,���õ���������Ķ�����麯��
	p->Fun2();
	p->Fun3();//Fun3���麯��,����pָ��ʵ��������������Ӧ����
	return 0;
}
*/
//�ڶ�������������
/*
#include<iostream>
using namespace std;

class Base
{
public:
	virtual void Fun1()
	{
		cout<<"Base::Fun1()..."<<endl;
	}
	virtual void Fun2()
	{
		cout<<"Base::Fun2()..."<<endl;
	}

	void Fun3()
	{
		cout<<"Base::Fun3()..."<<endl;
	}
	Base()
	{
		cout<<"Base()..."<<endl;
	}
	//���һ����Ҫ��Ϊ��̬����,Ҫ�����������������������������
	virtual ~Base()//�������virtual��֤p����Ϊ���õ���p ��ָ��������ͣ�������,
		//�����������������ֹ�ڴ�й¶
	{
		cout<<"~Base()..."<<endl;
	}
//���һ������Զ���ᱻ������̳�.��Ҳû�б�Ҫ�������������������
	//����ͨ������ָ��ɾ������������ʱ��,���û��������������.��ֻ����û������������.//
	//����������������������
};

class Derived:public Base
{
public:
	void Fun1()
	{
		cout<<"Derived::Fun1()..."<<endl;
	}
	void Fun2()
	{
		cout<<"Derived::Fun2()..."<<endl;
	}
	void Fun3()
	{
		cout<<"Derived::Fun3()..."<<endl;
	}
	Derived()
	{
		cout<<"Derived()..."<<endl;
	}

	~Derived()
	{
		cout<<"~Derived()..."<<endl;
	}

};





int main()
{
	Base* p;
	p=new Derived;//����ָ��ָ�����������.����һ�����������
	p->Fun1();//����ָ��ָ�����������,�����麯�����϶��������������麯��
	delete p;//�����������������ģ��������p���������������������
	//p���ڻ������͡�����Ȼ�͵��û������͡�
	//���������������ģ�p����Ϊ���õ���p ��ָ��������ͣ�������
	

	return 0;
}
*/
//�����������ָ��

#include<iostream>
using namespace std;

class Base//ͷ�ĸ��ֽ���ָ������ָ��
{//
public:
/*private:*///�麯�����Ա����˽���޹�
	virtual void Fun1()
	{
		cout<<"Base::Fun1()..."<<endl;
	}
	virtual void Fun2()
	{
		cout<<"Base::Fun2()..."<<endl;
	}
	

	int data1_;
	
};

class Derived:public Base
{
public:
	
	void Fun2()
	{
		cout<<"Derived::Fun2()..."<<endl;
	}
	virtual void Fun3()
	{
		cout<<"Derived::Fun3()..."<<endl;
	}
	int data2_;

};


typedef void(*Func)();//����һ������ָ��


int main()
{
	//vptr->vbtl�麯����ڵ�ַbase::Fun1,Base::Fun2

	cout<<sizeof(Base)<<endl;
	cout<<sizeof(Derived)<<endl;
	Base b;
	long ** p=(long **)&b;

	Func fun=(Func)p[0][0];//�����ָ��ǿ��ת����Func,���ָ�����ָ�������麯��
	fun();//����һ��.
	fun=(Func)p[0][1];
	fun();
	Derived d;
	p=(long**)&d;

	//��һ���ǻ����.�ڶ��������������fun
	fun=(Func)p[0][0];
	fun();
	fun=(Func)p[0][1];
	fun();
	fun=(Func)p[0][2];
	fun();

	Base *pp=&d;
	pp->Fun2();
	Base *pb=new Derived;
	pb->Fun2();
	return 0;
}