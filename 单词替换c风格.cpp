#include <iostream>
#include <fstream>
#include <string>
#pragma warning(disable:4996)
#define N 1024
using namespace std;
char str[N][N];
typedef char str_N[N];

//c风格单词替换
char* transform(char word[N])
{
	int flag = 0, i = 0;
	while (str[i][0] != '\0')//读取当前是否是空
	{
		int j = 0;
		char ch[N]{ 0 };
		while (str[i][j]!=' ')
		{
				j++;
		}
		strncpy(ch, str[i], j);
		if (strcmp(ch,word)==0)//如果匹配
		{
			int j = 0, t = 0;
			while (str[i][j] != ' ')//略过索引
			{
				j++;
			}
			while (str[i][j] == ' ')
				j++;//跳过空格
			while (str[i][j] != '\0'&&str[i][j] != '\n')
			{//把索引之后匹配到的内容进行转存
				word[t] = str[i][j];
				j++, t++;
			}
			break;
		}
		i++;
	}

	return word;
}

void buildMap(fstream &file)
{
	int i = 0, j = 0;
	char c;
	file.get(c);
	while (!file.eof())
	{
		str[i][j] = c;//读取内容到数组用来匹配
		j++;
		if (c == '\n')//如是换行符则使用下一个位置的数组
			i++, j = 0;
		file.get(c);
	}
}
void TransWordForm(fstream& file, fstream& input)
{
	for (int i = 0; i < N; ++i)
		memset(str[i], 0, N);//清除内容
	buildMap(file);//保存匹配内容
	input.seekg(0, ios::end);//定位到文件尾获取大小
	streampos len = input.tellg();
	input.seekg(0, ios::beg);//重置到文件头

	char c = '\0';


	while (!input.eof())
	{
		int i = 0, j;
		char tmp[N]{ 0 }, tmp1[N]{ 0 };
		//记录每行与每个单词
		while (!input.eof())
		{
			input.get(c);//读取字符
			if (input.eof() || c == '\n')//以换行或读取到末尾结束
				break;
			tmp[i] = c;//赋值给临时对象
			i++;
		}
		bool firstword = true;//第一个单词跳过空格

		i = 0;
		while (tmp[i] != '\0'&&tmp[i] != '\n')
		{//当不是空或换行则进行分解
			while (tmp[i] == ' ')
			{//跳过空格
				i++;
			}
			j = 0;
			while (tmp[i] != '\0'&&tmp[i] != ' ')
			{//统计到单词的长度
				i++;
				j++;
			}
			strncpy(tmp1, tmp + (i - j), j);//把tmp原先单词位置以j的长度写入
			if (firstword)
				firstword = false;
			else
				cout << " ";//第二个单词开始间隔是空格
			cout << transform(tmp1);//查找匹配内容
			memset(tmp1, 0, N);
			//清除内容，方便下次使用
		}
		cout << endl;
		memset(tmp, 0, N);

	}
}

int main()
{
	char s1[] = "1.txt", s2[] = "2.txt";
	if (remove(s1) == 0 || remove(s2) == 0)
		cout << "开始" << endl;
	fstream mapfile(s1, ios::out), input(s2, ios::out);
	if (mapfile.fail() || input.fail())
		cerr << "没有文件并创建" << endl;
	mapfile << "brb be right back\nk okay\ny why\nr are\nu you\npic picture\nthk thanks\n18r later";//写入内容
	input << "where r u\ny dont u send me a pic\nk thk 18r brb";
	mapfile.close();
	input.close();

	mapfile.open(s1);
	input.open(s2);
	TransWordForm(mapfile, input);

	system("pause");
	return 0;
}
