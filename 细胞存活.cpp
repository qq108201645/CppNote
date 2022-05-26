#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <windows.h>
using namespace std;
#define random(N) rand()%N
#define rand random(100)
template<unsigned H,unsigned W>
class Screen
{
public:
	using size_type = string::size_type;
	Screen() { clear_str(); }
	Screen(char c) :contents(height * width, c) {}
	void clear_str(){contents = string(height*width, ' ');}
	char get()const { return contents[cursor]; }
	Screen& move(size_type, size_type);
	Screen& operator<<(const char&);
	Screen& operator>>(char&);
	friend istream& operator<<(istream& is, const Screen<H, W> &rhs)
	{
		char c;
		cin >> c;
		string temp(H * W, c);
		rhs.contents = temp;
		return is;
	}
	friend ostream& operator<<(ostream& os, const Screen<H, W> &rhs)
	{
		Sleep(800);
		system("cls");
		cout << "Ö÷Ï¸°û´æ»î×Ö·û%\t ¸±´æ»î×Ö·û:#\t ËÀÍö×Ö·û*" << endl;
		for (size_t i=0;i<rhs.height;++i)
		{
			for (size_t j=0;j<rhs.width;++j)
			{
				cout << setw(2) << rhs.contents[i*rhs.width + j];
			}
			cout << endl;
		}
		return os;
	}
private:
	size_type cursor = 0, height = H, width = W;
	string contents;
};
template<unsigned H, unsigned W>
Screen<H, W>& Screen<H, W>::move(size_type r, size_type c)
{
	size_type row = r * width;
	cursor = row + c;
	return *this;
}
template<unsigned H,unsigned W>
Screen<H, W>& Screen<H, W>::operator<<(const char& c)
{
	contents[cursor] = c;
	return *this;
}
template<unsigned H, unsigned W>
Screen<H, W>& Screen<H, W>::operator>>(char& c)
{
	c = contents[cursor];
	return *this;
}

class ProcessMap
{
public:
	ProcessMap() = default;
	void range()
	{
		cnt = 0;
		for (size_t i=height-1;i<height+2;i++)
		{
			for (size_t j=width-1;j<width+2;j++)
			{
				if (!(i == height && j == width)) {
					
					bool c = rand&1;
					scr.move(i, j) << (c ? '#' : '*');
					if (c)
						cnt++;
				}
			}
		}
		if (cnt == 3)
		{
			scr.move(height, width) << '%';
		}
		else if (cnt != 2)
			scr.move(height, width) << '*';
	}
	void mov(char c, size_t h, size_t w)
	{
		scr.clear_str();
		height = h, width = w;
		scr.move(h, w) << c;

	}
	void process()
	{
		srand((int)time(nullptr));
		range();
		cout << scr;
	}
private:
	size_t height = 0, width = 0, cnt = 0;
	Screen<10, 10> scr;
};
int main()
{
	ProcessMap pr;
	
	bool flag = true;
	int i = 3 ,j = 5;
	while(1)
	{
		pr.mov('%', j, i);
		pr.process();
		if (flag)
		{
			i++;
			if (i >= 8)flag = false;
		}
		else
		{
			i--;
			if (i <= 3)flag = true;
		}
	}
	return 0;
}