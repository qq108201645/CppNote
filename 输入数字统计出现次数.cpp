#include<iostream>
#include <string>
#include <map>
using namespace std;

typedef map<int ,int> INTVER;
typedef map<char,int> INTVER_;
//int main()
//{
//	INTVER num;
//	int i;
//	cout<<"������������0����"<<endl;
//	while(cin>>i&&i!=0)
//	{
//		++num[i];
//	}
//	INTVER::const_iterator it;
//	int sum=0;
//	for (it=num.begin();it!=num.end();++it)
//	{
//		cout<<it->first<<"���� "<<it->second<<"��"<<endl;
//		sum+=it->first;
//	}
//	cout<<"ͳ����������ܺ�:"<<sum<<endl;
//}

int main()
{
	char number;
	cout<<"������һ��������y����"<<endl;
	

	INTVER_ num;
	while(cin>>number&&number!='y')
	{
		++num[number];
	}
	INTVER_::const_iterator it;
	for (it=num.begin();it!=num.end();++it)
	{
		cout<<it->first<<"���� "<<it->second<<"��"<<endl;
		
	}
}