#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const string num = "1234567890";
int main()
{
	fstream infile("JKampf.txt", ios::in);
	if (infile.fail())
		cerr << "打开错误" << endl;
	string s;
	while (getline(infile,s))
	{
		size_t beg = 0, end = 0;
		while ((beg=s.find_first_of(num,beg))!=string::npos)//从beg开始查找第一个是数字
		{
			if ((end = s.find_first_not_of(num, beg)) != string::npos)//从beg位置开始查找第一个不是数字的位置
			{
				if (end - beg - 1 >= 2)//当连续数字大于2个时,确定为数字
				{
					cout << s.substr(beg, end - beg) <<"\t";
					beg = end;//获得下一个开始的地址
				}
			}
			beg++;
		}
		cout << endl;
	}
	infile.close();
	system("pause");
	return 0;
}