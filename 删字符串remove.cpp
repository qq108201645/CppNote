#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	cout<<"请输入多少个字符串数量"<<endl;
	int n, i;
	cin >> n;
	getchar();
	string *buf=new string[n];
	for (i=0;i<n;i++)
	{
		cout<<"请输入第"<<i+1<<"个字符串"<<endl;
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
		cout <<"第"<<i+1<<"个字符串输出:";
		cout<<buf[i]<<endl;
	}
	delete[] buf;
	cout<<"回车结束"<<endl;
	getchar();
	
	return 0;
}