#include<iostream>
using namespace std;
const int day_month[]={31,28,31,30,31,30,31,31,30,31,30,31};
void month_(int &days,int month,int i)
{
	int j;
	for(j=0;j<month;j++)
	{
		days+=day_month[j];
	}
	if((i%4==0)&&(i%100!=0)||i==2000&&(i%400==0))
	{
		days++;
	}

}
int days_of_year(int year,int month,int day)
{
	int i,j;
	int days=0;
	for (i=1;i<=year;i++)
		month_(days,12,i);
	month_(days,month-1,0);
	days+=day;

	return days;
}
int main()
{
	int y,m,d,sum_days=0;
	char c;
	int weekday=0;
	do 
	{
		cout<<"������������: ";
		cin>>y>>m>>d;
		sum_days=days_of_year(y,m,d);
		weekday=sum_days%7;
		switch(weekday)
		{
		case 0:cout<<"������"<<endl;break;
		case 1:cout<<"������"<<endl;break;
		case 2:cout<<"������"<<endl;break;
		case 3:cout<<"������"<<endl;break;
		case 4:cout<<"������"<<endl;break;
		case 5:cout<<"����һ"<<endl;break;
		case 6:cout<<"���ڶ�"<<endl;break;
		}
		cout<<"�Ƿ����y/n"<<endl;
		cin>>c;
		while(c!='y'&&c!='Y'&&c!='n'&&c!='N')
		{
			cout<<"�������!����������"<<endl;
			cout<<"�Ƿ����y/n"<<endl;
			cin>>c;
		}
		if (c!='y'&&c!='Y')
		{
			break;
		}
	} while (1);
}
