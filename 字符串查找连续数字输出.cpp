#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const string num = "1234567890";
int main()
{
	fstream infile("JKampf.txt", ios::in);
	if (infile.fail())
		cerr << "�򿪴���" << endl;
	string s;
	while (getline(infile,s))
	{
		size_t beg = 0, end = 0;
		while ((beg=s.find_first_of(num,beg))!=string::npos)//��beg��ʼ���ҵ�һ��������
		{
			if ((end = s.find_first_not_of(num, beg)) != string::npos)//��begλ�ÿ�ʼ���ҵ�һ���������ֵ�λ��
			{
				if (end - beg - 1 >= 2)//���������ִ���2��ʱ,ȷ��Ϊ����
				{
					cout << s.substr(beg, end - beg) <<"\t";
					beg = end;//�����һ����ʼ�ĵ�ַ
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