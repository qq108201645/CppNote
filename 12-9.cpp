#include<iostream>
#include<stdlib.h>
#include<ctype.h>
using namespace std;
class list
{
public:
	list *head;
	list *tail;
	list *next;
	int num;
	list()
	{  
		head=tail=next=NULL; 
	}
	virtual void store(int i)=0;
	virtual int retrieve()=0;
};   
class queue:public list
{
public:
	void store(int i);
	int retrieve();
};
void queue::store(int i)
{
	list *item;
	item=new queue;
	if(! item)
	{
		cout<<"Allocation error\n";
		exit(1);
	}
	item->num=i;
	if(tail)
		tail->next=item;
    tail=item;
    item->next=NULL;
    if(! head)
		head=tail;
}
int queue::retrieve()
{
    int i;
    list *p;
    if(! head)
    {
		cout<<"list empty\n";
		return 0;
    }
    i=head->num;
    p=head;
    head=head->next;
    delete p;
    return i;
}
class stack:public list
{
public:
    void store(int i);
    int retrieve();
};
void stack::store(int i)
{
	list *item;
	item=new stack;
	if(! item)
	{
		cout<<"Allocation error\n";
		exit(1);
	}
	item->num=i;
	if(head)
		item->next=head;
    head=item;
    if(! tail)
		tail=head;
}
int stack::retrieve()
{
    int i;
    list *p;
    if(! head)
    {
		cout<<"list empty\n";
		return 0;
    }
    i=head->num;
    p=head;
    head=head->next;
    delete p;
    return i;
}
int main()
{
	list *p;
	queue qb;
	p=&qb;
	p->store(1);
	p->store(2);
	p->store(3);
	cout<<"Queue:";
	cout<<p->retrieve();
	cout<<p->retrieve();
	cout<<p->retrieve();
	cout<<'\n';
	stack sb;
	p=&sb;
	p->store(1);
	p->store(2);
	p->store(3);
	cout<<"Stack:";
	cout<<p->retrieve();
	cout<<p->retrieve();
	cout<<p->retrieve();
	cout<<'\n';
}