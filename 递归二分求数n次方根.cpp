#include<iostream>
using namespace std;
#include<string.h>
int main()
{
	double s(double key, double num, double low, double higt);
	double key, num, result;	// low,high;
	char c;
	do
	{
		cout<<"==========���ַ���һ������n�η���============\n";
		cout << "����һ����:";
		cin >> key;
		cout << "��������ļ��η�: ";
		cin >> num;
		result = s(key, num, 0, key);
		cout << key << "��" << num << "�η���=" << result << endl;
		cout << "�Ƿ����(Y/N)?" ;
		cin >> c;
		if (c != 'y' && c != 'Y')
			break;
		cout<<endl;
	}
	while (true);
	return 0;
}
double s(double key, double num, double low, double higt)
{
	double mid = (low + higt) / 2, square, sq = mid;
	for (int i = 0; i < num - 1; i++)
		sq *= mid;
	square = sq;
	if (key == square || (key - square) > 0 && (key - square) < 0.0001 || (key - square) < 0
		&& (key - square) > -0.0001)
		return mid;
	
	else
	{
		if (key > square)
			low = mid;
		else
			higt = mid;
	}
	return s(key, num, low, higt);
}
