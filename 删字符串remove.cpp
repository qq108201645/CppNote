#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	cout<<"��������ٸ��ַ�������"<<endl;
	int n, i;
	cin >> n;
	getchar();
	string *buf=new string[n];
	for (i=0;i<n;i++)
	{
		cout<<"�������"<<i+1<<"���ַ���"<<endl;
		getline(cin, buf[i]);
		basic_string<char> s = " \t@.+";
		unsigned int j,len = buf[i].size();
		for (j=0;j<s.size();++j)
		{
			buf[i].erase(remove(buf[i].begin(), buf[i].end(), s[j]), buf[i].end());
		}
	}
	for (i=0;i<n;i++)
	{
		cout <<"��"<<i+1<<"���ַ������:";
		cout<<buf[i]<<endl;
	}
	delete[] buf;
	cout<<"�س�����"<<endl;
	getchar();
	
	return 0;
}