#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#define Size_ 20
using namespace std;

int main()
{
	string buf = "00000", tmp = buf, s1 = ".txt";
	string::size_type sp = buf.find('0');
	int buflen = buf.size();
	unsigned int num;
	cout << "�������ٸ�" << Size_ << "M�ļ�" << endl;
	cin >> num;
	for (unsigned int i = 0, j = 0; i < num; i++)
	{
		buf = buf.substr(0, buflen);
		buf[buflen - 1]++;
		for (j = buf.size(); j > sp; j--)
		{
			buf[j] > '9' ? buf[j - 1]++, buf[j] = '0' : buf[j];
		}
		buf.append(s1);
		cout << buf << endl;
		fstream CreateFile(buf.c_str());

		if (CreateFile.fail())
		{
			cout << "û���ļ�,�����ļ�" << buf << endl;
			CreateFile.close();
			CreateFile.clear();
			CreateFile.open(buf.c_str(), ios::out | ios::binary);
		}
		else
		{
			CreateFile.close();
			continue;
		}
		char *str = new char[1024];
		memset(str, 0, 1024);

		for (unsigned temp = 0; temp < Size_; temp++)
		{
			for (int k = 0; k < 1024; k++)
			{
				CreateFile.write((char*)str, 1024);
			}
		}
		delete[] str;
		CreateFile.close();
	}

	cout << "�س�ɾ��" << endl;
	cin.get();
	cin.get();
	for (unsigned int i = 0, j = 0; i < num; i++)
	{
		tmp = tmp.substr(0, buflen);
		tmp[buflen - 1]++;
		for (j = tmp.size(); j > sp; j--)
		{
			tmp[j] > '9' ? tmp[j - 1]++, tmp[j] = '0' : tmp[j];
		}
		tmp.append(s1);
		fstream OpenFile(tmp.c_str(), ios::in | ios::out);

		if (OpenFile.fail())
		{
			cout << "û�� " << tmp << endl;
			continue;
		}

		buf = tmp;
		OpenFile.seekg(0, ios::end);
		streampos si = OpenFile.tellg();
		OpenFile.close();
		if (remove(tmp.c_str()) == 0)
		{
			cout << buf << "  ��С:" << si << " B\tɾ���ɹ�" << endl;
		}

	}
	return 0;
}