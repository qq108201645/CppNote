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
	while ([&]() {cout << "����һ�������ȴ���3:" << endl;
	while (cin >> s&& s.size() <= 2)
	{
			cout << "�����������������:" << endl;
	}
	 return s != "end"; }())
	{
		cout << s << (Process(s) ? "�ǻ�����" : "���ǻ�����") << endl;
	}
	 system("pause");
	 return 0;
}