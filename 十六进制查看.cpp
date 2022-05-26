#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<conio.h>
#include <cstdlib>
using namespace std;
const int N = 0x100;
int sav;
void Display(fstream & f, int &locat, int length)
{
	char data[N];
	memset(data, 0, N);
	system("cls");
	int m = 0;
	f.seekg(locat, ios_base::beg);
	streampos sp = f.tellg();
	cout<<sp<<endl;
	if ((length - locat )< N)
		sav = m = N - (length - locat);
	f.read((char *)data, N - m);
	f.clear();
	for (int i = 0; i < N - m; i++)
	{
		if (i > 0 && i % 16 == 0)
			cout << endl << hex << locat << "\t";
		else if (locat == 0)
			cout << hex << "0" << locat << "\t";
		else if (i == 0)
			cout << hex << locat << "\t";
		cout << setw(3) << setiosflags(ios::uppercase);
		if (data[i] < 0x10)
			cout << hex << setw(2) << '0' << (int)data[i];
		else
			cout << hex << (int)data[i];
		locat++;
	}
	
}



int main()
{
	string buf = "1.txt";
	fstream open(buf.c_str());
	if (open.fail())
		exit(1);
	open.seekg(0, ios::end);
	auto length = open.tellg();
	int locat = 0;
	Display(open, locat, length);
	char c;
	while (c = _getch())
	{
		switch (c)
		{
		case '2':
			int t;
			if (sav == 0)
				 t = N * 2;
			else
			{
				t = N +(N- sav);
			}
			if (locat - t >= 0)
			{
				locat = locat -t ;
				sav = 0;
				Display(open, locat, length);
			}
			break;
		case '8':
			if (locat < length)
			{
				Display(open, locat, length);
			}
			break;
		default:
			break;
			if (c == 'n')
				break;
		}
	}
	cout << "½áÊø!" << endl;
	system("pause");
	return 0;
}

