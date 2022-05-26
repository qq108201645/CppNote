#include<iostream>
using namespace std;

class BB
{
public:
	int bb_;

};
class B1:virtual public BB
{
public:
	int b1_;

};

class B2:virtual public BB
{
public:
	int b2_;
};

class DD:public B1,public B2
{
public:
	int dd_;
};

int main()
{
	cout<<sizeof(BB)<<endl;
	cout<<sizeof(B1)<<endl;
	cout<<sizeof(DD)<<endl;
		
		
	B1 b1;
	cout<<&b1<<endl;	
	cout<<&b1.bb_<<endl;
	cout<<&b1.b1_<<endl;
	//&b1		001AFE4C//������׵�ַvirtual base table pointer//�����ַ
	//vbptr������ָ��1��vbtl�����ַ��������ָ���ַ�Ĳ�0	
	//2:������ַ��������ָ���ַ�Ĳ�8
	
	//&b1.b1_	001AFE50
	//������ַ
	//&b1.bb_	001AFE54//����ಿ��	BB

	long** p=(long**)&b1;
	cout<<p[0][0]<<endl;//p[0][0]=vbptrȡ����0��
	cout<<p[0][1]<<endl;//ȡ����һ��

	DD dd;
	cout<<&dd<<endl;
	cout<<&dd.bb_<<endl;
	cout<<&dd.b1_<<endl;
	cout<<&dd.b2_<<endl;
	cout<<&dd.dd_<<endl;
	//&dd		002AF830	������׵�ַvirtual base table pointer//�����ַb1������ַ�������ָ���ָ���ַ���5
	//&dd.b1_	002AF834	b1
	//vbptr		002AF838	b2������ַ�������ָ���ָ���ַ���3
	//&dd.b2_	002AF83C	b2
	//&dd.dd_	002AF840
	//&dd.bb_	002AF844	BB����b1,b2

	p=(long**)&dd;
	cout<<p[0][0]<<endl;
	cout<<p[0][1]<<endl;
	cout<<p[2][0]<<endl;
	cout<<p[2][1]<<endl;

	BB* pp;
	pp=&dd;
	pp->bb_;//����BBָ�����������Ա//ͨ����ӷ���,��Ҫ����ʱ֧��
	return 0;
}
