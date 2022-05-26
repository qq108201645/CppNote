#include <iostream>
#include <fstream>
#include <string>
#pragma warning(disable:4996)
#define N 1024
using namespace std;
char str[N][N];
typedef char str_N[N];

//c��񵥴��滻
char* transform(char word[N])
{
	int flag = 0, i = 0;
	while (str[i][0] != '\0')//��ȡ��ǰ�Ƿ��ǿ�
	{
		int j = 0;
		char ch[N]{ 0 };
		while (str[i][j]!=' ')
		{
				j++;
		}
		strncpy(ch, str[i], j);
		if (strcmp(ch,word)==0)//���ƥ��
		{
			int j = 0, t = 0;
			while (str[i][j] != ' ')//�Թ�����
			{
				j++;
			}
			while (str[i][j] == ' ')
				j++;//�����ո�
			while (str[i][j] != '\0'&&str[i][j] != '\n')
			{//������֮��ƥ�䵽�����ݽ���ת��
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
		str[i][j] = c;//��ȡ���ݵ���������ƥ��
		j++;
		if (c == '\n')//���ǻ��з���ʹ����һ��λ�õ�����
			i++, j = 0;
		file.get(c);
	}
}
void TransWordForm(fstream& file, fstream& input)
{
	for (int i = 0; i < N; ++i)
		memset(str[i], 0, N);//�������
	buildMap(file);//����ƥ������
	input.seekg(0, ios::end);//��λ���ļ�β��ȡ��С
	streampos len = input.tellg();
	input.seekg(0, ios::beg);//���õ��ļ�ͷ

	char c = '\0';


	while (!input.eof())
	{
		int i = 0, j;
		char tmp[N]{ 0 }, tmp1[N]{ 0 };
		//��¼ÿ����ÿ������
		while (!input.eof())
		{
			input.get(c);//��ȡ�ַ�
			if (input.eof() || c == '\n')//�Ի��л��ȡ��ĩβ����
				break;
			tmp[i] = c;//��ֵ����ʱ����
			i++;
		}
		bool firstword = true;//��һ�����������ո�

		i = 0;
		while (tmp[i] != '\0'&&tmp[i] != '\n')
		{//�����ǿջ�������зֽ�
			while (tmp[i] == ' ')
			{//�����ո�
				i++;
			}
			j = 0;
			while (tmp[i] != '\0'&&tmp[i] != ' ')
			{//ͳ�Ƶ����ʵĳ���
				i++;
				j++;
			}
			strncpy(tmp1, tmp + (i - j), j);//��tmpԭ�ȵ���λ����j�ĳ���д��
			if (firstword)
				firstword = false;
			else
				cout << " ";//�ڶ������ʿ�ʼ����ǿո�
			cout << transform(tmp1);//����ƥ������
			memset(tmp1, 0, N);
			//������ݣ������´�ʹ��
		}
		cout << endl;
		memset(tmp, 0, N);

	}
}

int main()
{
	char s1[] = "1.txt", s2[] = "2.txt";
	if (remove(s1) == 0 || remove(s2) == 0)
		cout << "��ʼ" << endl;
	fstream mapfile(s1, ios::out), input(s2, ios::out);
	if (mapfile.fail() || input.fail())
		cerr << "û���ļ�������" << endl;
	mapfile << "brb be right back\nk okay\ny why\nr are\nu you\npic picture\nthk thanks\n18r later";//д������
	input << "where r u\ny dont u send me a pic\nk thk 18r brb";
	mapfile.close();
	input.close();

	mapfile.open(s1);
	input.open(s2);
	TransWordForm(mapfile, input);

	system("pause");
	return 0;
}
