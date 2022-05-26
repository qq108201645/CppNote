#include<iostream>
#include<map>
#include<fstream>
#include<string>
using namespace std;
void SkipWhite(string &s)
{
	for (auto& i : s)
		if (i >= 'A'&&'Z' >= i)
			i = i - 'A' + 'a';
	string white = ",./;: ";
	int p = 0;	while ((p = s.find_first_of(white, p)) != string::npos)
	{
		s.erase(p, 1);
	}
}
string &transform(string& s, map<string, string> &m)
{
	string buf = s;
	SkipWhite(s);
	auto it = m.find(s);
	if (it != m.end())
		s = "翻译:" + it->second;
	else
		s = "词库没有内容!" + buf;
	return s;
}
void process(fstream& mapfile, string &s)
{
	char c;
	while (!mapfile.eof())
	{
		mapfile.get(c);
		if (mapfile.eof() || c == '\n' || c == '|')
			break;
		s.push_back(c);
	}
}

map<string, string> buildMap(fstream& mapfile)
{
	map<string, string> transMap;
	string key, value;

	while (!mapfile.eof())
	{
		key.clear();
		value.clear();
		process(mapfile, key);
		process(mapfile, value);
		SkipWhite(key);	transMap.insert({ key,value.size() > 1 ? value : value = "没有找到译文" });
	}
	return transMap;
}

void trans_wordform(fstream& mapfile)
{
	auto transMap = buildMap(mapfile);
	string text;
	while ([&]() {getline(cin, text); return text != "结束"; }())
	{
		cout << transform(text, transMap) << endl;
	}
	cout << endl;
}
int main()
{

	fstream mapfile;
	//如果自定义1.txt内容就把ifndef改为ifdef去掉n
#ifndef declaration
//写入文件//开始
	mapfile.open("1.txt", ios::out);
	if (mapfile.fail())
		cout << "没有文件并创建" << endl;
	mapfile << "word |文档|how are you|你好吗|me";
	//写入文件//结束
#endif
	mapfile.close();
	mapfile.open("1.txt", ios::in);
	if (mapfile.fail())
		cout << "没有文件" << endl;
	trans_wordform(mapfile);
	mapfile.close();
	return 0;
}
