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
	//��������һ��С��0xff ff ff������һ��0xff���ڵĳ���
	int num_, mulnum_;
	//�ֱ���ת����,���䳤��,������ƫ��,ѭ������
	int number, len, curPos, i;
	//�����λ����תint�õ���ʱָ�루���������ֽ�)
	char* bit, *tmp;
	//���������λ	d7 d6 d5 d4 d3 d2 d1 d0
	BIT_Token bit_token;
	byte2_ b2;
	//��־λ
	int flag;
	int status_;
public:
	Bit_Mul_Div_arithmetic(int num = 0, int mulnum = 0,bool status=0) 
		:num_(num), mulnum_(number), len(10),status_(status)//��ʼ����10
	{
		bit = new char[len];//���䳤��
		NumToStr();
		strNum();			//�������
	}
	void NumToStr()
	{
		flag=curPos = 0;
		memset(bit, 0, len);//��0
		tmp = (char*)&num_;	//��char*ָ������
		strncpy(bit, tmp, 3);//��ȡ�����ֽڸ�char*���ͽ����ֽ�����
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
			number = (byte_)bit[j];//ת��byte�ֽ�
			cout <<setw(4)<< hex << number << " "; //����ʮ���������
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
	cout << "����һ��С����16777215����:";
	while (cin >> other.num_&&other.num_ > 16777215)
	{
		cout << "�����������������!\n����һ��С����16777215����:";
	}

	cout << "����һ����˲� С����255����:";
	while (cin >> other.mulnum_&&other.mulnum_ > 255)
	{
		cout << "�����������������!\n����һ��С����255����:";
	}
	cout << "����һ�����㷽������㡣0=��������1=��С����2=���� С����2����:"<<endl;
	while (cin >> other.status_&&(other.status_ &0x0f) > 2)
	{
		cout << "�����������������!"<<endl;
		cout<<"����һ�����㷽������㡣0=��������1=��С����2=���� С����2����:"<<endl;
	}
	cout << endl;
	other.NumToStr();
	other.strNum();
	return is;

}
ostream& operator<<(ostream& os, Bit_Mul_Div_arithmetic& other)
{
	other.tmp = (char*)&other.number;				//��ʱchar*ָ������
	strncpy(other.tmp, other.bit, 3);				//��ȡ�����ֽڸ�����
	os << "���:" << dec << other.number << endl;	//����ʮ�������
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