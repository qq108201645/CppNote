#include <iostream>
using namespace std;

class Rectangle
{
private:
	double width;
	double length;
public:
	Rectangle(double w=0,double l=0)
	{
		width=w;
		length=l;
	}
	~Rectangle()
	{

	}
	void Set_Width_Length(double w,double l)
	{
		width=w;
		length=l;
	}
	void Rectangle_Perimeter()
	{
		cout<<"(��+��)��2 �ܳ�=\t"<<(width+length)*2<<endl;//�����ܳ�
	}
	void Rectangle_area()
	{
		cout<<"���˿�\t���=\t\t"<<width*length<<endl;//�������
	}
};
int main()
{
	Rectangle rectangle;//��������rectangle
	char c;//��������y��n
	double w,l;//���崫ֵ����
	while(1)//����ѭ��
	{
		cout<<"----��������ܳ������-----\n"<<endl;
		cout<<"������Width:\t";cin>>w;//���볤
		cout<<"������Length:\t";cin>>l;//�����
		rectangle.Set_Width_Length(w,l);//���ö����Ա������ֵ
		rectangle.Rectangle_Perimeter();//���ö����Ա���������ܳ�
		rectangle.Rectangle_area();//���ö����Ա�����������
		cout<<"�Ƿ����Y/N"<<endl;
		cin>>c;
		while(c!='y'&&c!='n'&&c!='Y'&&c!='N')//�����Ǵ�д��Сд��y��nʱѭ��ֱ��������ȷ
		{
			cout<<"�������!����������"<<endl;
			cout<<"�Ƿ����Y/N"<<endl;
			cin>>c;
		}
		if (c!='y'&&c!='Y')//������y��Yʱ����,�����˳�
		{
			break;
		}
	}

	cout<<"�˳��ɹ�!"<<endl;
	return 0;
}