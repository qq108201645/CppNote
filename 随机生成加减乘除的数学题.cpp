#include <iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include<string>
using namespace std;


typedef int(*Func)(int, int);
#define random(N) rand()%N
const int Num = 100;
#define rand random(Num)
const string s = "�Ӽ��˳�";


void inputHandle()
{
	auto add = [](int a, int b) {return a + b; };
	auto sub = [](int a, int b) {return a - b; };
	auto mul = [](int a, int b) {return a * b; };
	auto div = [](int a, int b) {return a / b; };

	vector<Func> calc{ add,sub,mul,div };

	string sizestr = "��";
	int a = rand, b = rand, flag = rand & 3, result;
	cout << a << s.substr(flag*sizestr.size(), sizestr.size()) << b << "������:";
	cin >> result;
	cout << "����" << ((*(calc.begin() + flag))(a, b) == result ? "��ȷ" : "����") << endl;
}
int main()
{
	srand((int)time(nullptr));

	while (1)
	{
		inputHandle();
		char c;
		cout << "�Ƿ����y/n" << endl;
		cin >> c;
		if (c != 'y'&&c != 'Y')
			break;

	}
	cout << "�˳�����" << endl;
	return 0;
}
