#include<iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

class Packbits
{
public:
	Packbits() = default;
	/* �������� 1:���ݡ�2:��ʽ:code��decode����ʾ�������롣3:��ʼ��λ�ã�Ĭ��0*/
	void move_data(const string&, const string&, int);
	/* ���� */
	void packbits();
	/* ���� */
	void unpackbits();
	string getdata() { return data; }
	string getout_d() { return out_d; }
	string getout_e() { return out_e; }
	size_t cur() { return start_cur; }
	const char* data_c_str()
	{
		return data.c_str();
	}

	/* ����һ�������str */
	const char* out_d_c_str()
	{
		return out_d.c_str();
	}
//private:
	int start_cur = 0;
	string data;
	string out_d;
	string out_e;
};
void Packbits::move_data(const string& str, 
	const string& elem = "", int p = 0)
{
	
	if (elem == "" || elem == "code")
	{
		out_e = str;
		packbits();
	}
	else
	{
		start_cur = p;
		data = str;
		unpackbits();
	}
}
void Packbits::packbits()
{
	int count;
	int Length = out_e.size(), i = 0, t;
	out_d.clear();
	while (i< Length)
	{
		if (i <= (Length - 2) &&
			out_e[i] == out_e[i + 1])
		{
			for (t = i + 2; t < Length&&out_e[t] == out_e[i]
				&&t-i<0x7F;)
				++t;
			count = t - i;
			out_d += count;
			out_d += out_e[i];
		}
		else
		{
			for (t = i; t < Length&&t - i < 0x7F;)
				if (t <= (Length - 3) && out_e[t] == out_e[t + 1]
					&& out_e[t] == out_e[t + 2])
					break;
				else
					++t;
			count = t - i;
			out_d += (count | 0x80);
			out_d += out_e.substr(i, count);
		}
		i += count;
	}
	/* ������ */
	out_d += (char)0xFF;
}
void Packbits::unpackbits()
{
	int len;
	int val, i = start_cur;
	int Length = data.size();
	while (i<Length)
	{
		len = data[i++]&0xFF;
		/* ����0xff���� */
		if (len ==0xFF)
			break;
		if (len < 0x80)
		{
			/* ȡbyte*/
			val = data[i++] & 0xFF;
			/* ��string����len��val����� */
			out_d += string(len, val);
		}
		else
		{
			/* ������λ */
			len &= 0x7F;
			/* ��inp��i��ʼ�ط���ȡ����Ϊlen������ */
			out_d += data.substr(i, len);
			/* ��ַƫ�� */
			i += len;
		}
	}
}
fstream& input(fstream &in, Packbits &rhs, 
	const string& str, int pos)
{
	ostringstream os_n;
	os_n << in.rdbuf();
	rhs.move_data(os_n.str(),str,pos);
	return in;
}
fstream& output(fstream &os, Packbits &rhs)
{
	os.write(rhs.out_d_c_str(), rhs.getout_d().size());
	return os;
}
fstream& outputScoure(fstream &os, Packbits &rhs)
{
	string s = rhs.getdata();
	auto first = s.begin() + rhs.cur(),
		last = s.begin() + (rhs.cur() + rhs.getout_d().size());
	s.replace(first, last, rhs.getout_d());
	os.write(s.c_str(), s.size());
	return os;
}
void Test(Packbits &p,const string &s,int cur)
{
	string fileName,outName;
	if (s == "decode")
		fileName = "1.bin", outName = "2.bin";
	else
		fileName = "2.bin", outName = "3.bin";
	fstream in(fileName, ios::in | ios::binary);
	if (!in)
	{
		cerr << "û��" << fileName << "�����˳�!" << endl;
		cin.get();
		exit(1);
	}
	/* ��ʾ�ļ���fileName������np,���ñ��룬��ʼλ����0 */
	input(in, p, s, cur);
	in.close();

	if (remove(outName.c_str()) == 0)
		cout << "ok" << endl;
	fstream out(outName, ios::out | ios::binary);
	if (!out)
		cerr << "�����ļ�" << endl;
	output(out, p);
	out.close();
	cout << outName<<" ������" << endl;
	if (fileName == "2.bin"&&p.getdata().size()!=0)
	{
		char c;
		cerr << "�Ƿ�д��ԭ�ļ�1.bin? Y/N\n";
		cin >> c;
		while (c != 'N'&&c != 'n')
		{
			if (c == 'N' || c == 'n' || c == 'Y' || c == 'y')
			{
				string tst = "1.bin";
				fstream outfile;
				outfile.open(tst, iostream::out | iostream::binary);
				outputScoure(outfile, p);
				outfile.close();
				cout << "���" << tst <<"���!"<< endl;
				break;
			}
			else
			{
				cerr << "�������,����������!" << endl;
				cin >> c;
			}
		}
	}
}
int main()
{
	string s;

	Packbits p;
	while ([&s]()->bool {
		cout << "===============\n"
			"(ѡ��һ���ļ���:1.bin��Դ�ļ�.����cppĿ¼��\n���뷽ʽ��\n"
			"decode:����(��1.bin���н���,�����2.bin)\n"
			"code:����(��2.bin���б���,�����3.bin,��Ҫ�ȶ�1.bin�����2.bin)\n"
			"end:����!\n"
			"����������:" << endl; 
		std::cin >> s; return s != "end"; }())
	{
		if (s != "code"&&s != "decode")
		{
			cerr << "�������!����������" << endl;
			continue;
		}
		int cur;
		if (s == "decode")
		{
			cout << "���뿪ʼ�����λ��:" << endl;
			while ([&cur]() {cin >> cur; return cur <= -1; }())
			{
				cerr << "�������!����������" << endl;
			}
		}
		else
		{
			cout << "����ģʽλ��Ĭ�ϴ�2.bin��0��ʼ" << endl;
			cur = 0;
		}
		Test(p,s, cur);
	}
	return 0;
}