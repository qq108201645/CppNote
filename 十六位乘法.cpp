#include<iostream>
#include <string>
#include<iomanip>
#pragma warning(disable:4996)



typedef unsigned short int byte2_; //65535
typedef unsigned char byte_; //255

using namespace std;

enum BIT_Token
{
	BIT_D0 = 0x01,
	BIT_D1 = 0x02,
	BIT_D2 = 0x04,
	BIT_D3 = 0x08,
	BIT_D4 = 0x10,
	BIT_D5 = 0x20,
	BIT_D6 = 0x40,
	BIT_D7 = 0x80
};
class Bit_Mul_Div_arithmetic
{
	//用来接收一个小于0xff ff ff的数与一个0xff以内的乘数
	int num_, mulnum_;
	//分别是转整数,分配长度,与运算偏移,循环变量
	int number, len, curPos, i;
	//输入的位，与转int用的临时指针（复制整型字节)
	char* bit, *tmp;
	//定义二进制位	d7 d6 d5 d4 d3 d2 d1 d0
	BIT_Token bit_token;
	byte2_ b2;
	//标志位
	int flag;
	int status_;
public:
	Bit_Mul_Div_arithmetic(int num = 0, int mulnum = 0,bool status=0) 
		:num_(num), mulnum_(number), len(10),status_(status)//初始长度10
	{
		bit = new char[len];//分配长度
		NumToStr();
		strNum();			//输出测试
	}
	void NumToStr()
	{
		flag=curPos = 0;
		memset(bit, 0, len);//清0
		tmp = (char*)&num_;	//用char*指向整型
		strncpy(bit, tmp, 3);//截取三个字节给char*类型进行字节运算
		tmp = (char*)&mulnum_;
		if (status_==0)
		{
			strncpy(bit+6, tmp, 1);
		}
		else if(status_ == 1)
		{
			strncpy(bit+5, tmp, 1);
		}
		
	}
	void strNum()
	{
		for (int j = 0; j < len; j++)
		{
			number = (byte_)bit[j];//转换byte字节
			cout <<setw(4)<< hex << number << " "; //整型十六进制输出
		}
		cout << endl;
	}

	~Bit_Mul_Div_arithmetic()
	{
		delete[] bit;
	}
	void ROLdata(int cur)
	{
		char t = bit[cur];
		bit[cur] <<= 1;
		if (flag == 1)
		{
			bit[cur] += (char)flag;
			flag = 0;
		}
		if ((t& (int)BIT_D7) == 0x80)
		{
			flag = 1;
		}
		
		
	}
	void Sum()
	{
		flag = 0;
		b2 = (int)bit[0] & 0xff;
		b2 += (int)bit[5] & 0xff;
		if (b2 > 255)
			bit[1]++;
		bit[0] += bit[5];
		b2 = (int)bit[1] & 0xff;
		b2 += (int)bit[6] & 0xff;
		if (b2 > 255)
		{
			bit[2]++;
		}
		bit[1] += bit[6];
	}
	void Mul()
	{
		if(status_==0)
			bit[5] = 0;
		if (bit[5]!=0)
		{
			bit[2] = 0;
		}
		//c40c
		bit[4] = bit[2], bit[3] = bit[1], bit[2] = bit[0];
		bit[0] = bit[1] = 0;
		for (i=0x18;i!=0;i--)
		{
			ROLdata(0);
			ROLdata(1);
			ROLdata(2);
			ROLdata(3);
			ROLdata(4);
			cout << "~~~~~~" <<i<< endl;
			strNum();
			cout << "~~~~~~" << endl;
			if (flag==1)
			{
				Sum();
				cout << "--------------------" <<i<< endl;
				strNum();
				cout << "--------------------" << endl;
			}
			cout<<endl;
		}
		
		bit[0] = bit[1], bit[1] = bit[2], bit[2] = bit[3];
	}
	friend istream& operator>>(istream& is, Bit_Mul_Div_arithmetic& other);
	friend ostream& operator<<(ostream& os, Bit_Mul_Div_arithmetic& other);


};
istream& operator>>(istream& is, Bit_Mul_Div_arithmetic& other)
{
	cout << "输入一个小等于16777215的数:";
	while (cin >> other.num_&&other.num_ > 16777215)
	{
		cout << "输入错误！请重新输入!\n输入一个小等于16777215的数:";
	}

	cout << "输入一个想乘并 小等于255的数:";
	while (cin >> other.mulnum_&&other.mulnum_ > 255)
	{
		cout << "输入错误！请重新输入!\n输入一个小等于255的数:";
	}
	cout << "输入一个乘算方法或除算。0=乘正数，1=乘小数，2=除法 小等于2的数:"<<endl;
	while (cin >> other.status_&&(other.status_ &0x0f) > 2)
	{
		cout << "输入错误！请重新输入!"<<endl;
		cout<<"输入一个乘算方法或除算。0=乘正数，1=乘小数，2=除法 小等于2的数:"<<endl;
	}
	cout << endl;
	other.NumToStr();
	other.strNum();
	return is;

}
ostream& operator<<(ostream& os, Bit_Mul_Div_arithmetic& other)
{
	other.tmp = (char*)&other.number;				//临时char*指向整型
	strncpy(other.tmp, other.bit, 3);				//截取三个字节给整型
	os << "输出:" << dec << other.number << endl;	//整型十进制输出
	other.strNum();
	return os;
}


int main()
{
	cout << "byte=\t" << sizeof(byte_) << endl;
	cout << "byte2=\t" << sizeof(byte2_) << endl;
	Bit_Mul_Div_arithmetic mul;

	cin >> mul;
	mul.Mul();
	cout<<mul<<endl;
	system("pause");
	return 0;
	
}