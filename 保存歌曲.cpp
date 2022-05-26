#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
void read_(fstream& f, string& name, vector<string>& v)
{
	v.clear();
	string s;
	f.open(name,ios::in);
	if (!f)
	{
		cerr << "����" << endl;
	}
	while (!f.eof())
	{
		getline(f, s);
		if (f.eof())
			break;
		s.push_back('\n');
		v.push_back(s);
	}
	f.close();
}
void write_(fstream& f,string& name,vector<string>& v)
{
	if (remove(name.c_str()) == 0)
		cout << "д��ɹ�" << endl;
	f.open(name,ios::out);
	for (vector<string>::iterator it = v.begin(); it != v.end(); ++it)
		f.write((char*)it->c_str(), it->size());
	f.close();
}
void ShowVec(vector<string>&v)
{
	system("cls");
	int i = 1;
	cout << "------------------" << endl;
	for_each(v.begin(), v.end(), [&](string& s)
	{cout <<i++<< s; });
}
int main()
{
	string s = "------------------\n1�����ļ�\n2��ȡ�ļ�\n3����µĸ��������桢��ȡ\n4ɾ�����������桢��ȡ\n------------------\n";
	vector<string> svec;
	char c;
	while (true)
	{
		string filename = "1.txt",data;
		fstream file; 
		ShowVec(svec);
		cout << s;
		cin >> c;
		size_t t;
		switch (c)
		{
		case '1':
			write_(file, filename, svec);
			break;
		case '2':
			read_(file, filename, svec);
			break;
		case '3':
			cout << "���������Ϣ" << endl;

			cin.get();
			getline(cin, data);
			data.push_back('\n');
			svec.push_back(data);
			write_(file, filename, svec);
			read_(file, filename, svec);
			break;
		case '4':
			if (svec.size() > 0)
			{
				cout << "ɾ���ڼ��׸裨����)" << endl;
				
				while (cin >> t && t > svec.size())
				{
					cout << "���ڸ����,��������" << endl;
				}
				if (t > 0)
				{
					svec.erase(svec.begin() + (t - 1));
					write_(file, filename, svec);
					read_(file, filename, svec);
				}
				else
				{
					cout << "�Ƿ�����" << endl;
				}
			}
			else
				cout << "û�и���" << endl;
			break;
		default:
			cout << "�������" << endl;
		}
	}
	system("pause");
	return 0;
}
