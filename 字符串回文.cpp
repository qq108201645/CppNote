#include <iostream>
#include <string>
using namespace std;

bool Process(const string &s)
{
	int i = 0;
	int len = s.size() - 1;
	while (i!=s.size()&&s[i]==s[len-i])
	{
		i++;
	}
	return i == s.size() ? true : false;
}
int main()
{
	string s;
	while ([&]() {cout << "输入一个数长度大于3:" << endl;
	while (cin >> s&& s.size() <= 2)
	{
			cout << "输入错误请重新输入:" << endl;
	}
	 return s != "end"; }())
	{
		cout << s << (Process(s) ? "是回文数" : "不是回文数") << endl;
	}
	 system("pause");
	 return 0;
}