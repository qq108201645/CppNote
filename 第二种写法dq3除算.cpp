#include<iostream>
using namespace std;
const unsigned N=0x80;
/*c++�»�����*/
bool And(char a)
{
	return a&0x80?true:false;
}
int main()
{
	unsigned char chars[6];

	unsigned short *num=(unsigned short*)chars,*divisor=(unsigned short*)(chars+2),
		*other=(unsigned short*)(chars+4);
	while (cin>>*num&&cin>>*divisor)
	{
		chars[4]=chars[5]='\0';//��ʼ����0
		char t1,t2;

		for (int i=16;i!=0;i--)
		{
			size_t flag=0;

			t1=chars[0];
			chars[0]<<=1;

			t2=t1,t1=chars[1];
			chars[1]<<=1;
			chars[1]+=And(t2);//��λ����

			
			t2=t1,t1=chars[4];
			chars[4]<<=1;
			chars[4]+=And(t2);//��λ����

			t2=t1;
			chars[5]<<=1;
			chars[5]+=And(t2);//��λ����
			
			chars[0]++;

			if (chars[4]<chars[2])
			{
				if (chars[5]<=chars[3])
					flag=1;
				chars[5]--;
			}

			chars[4]-=chars[2];
			if (chars[5]<chars[3])
				flag=1;
			chars[5]-=chars[3];
			if (flag==1)//�����������
			{
				chars[4]>=chars[2]?(t1=chars[4],t2=chars[2]):(t1=chars[2],t2=chars[4]);//ȡ���ֵ
				
				
				chars[4]+=chars[2];
				chars[5]+=chars[3];
				if (t1>=N)//������ֵ����0x80���ȥ���ֵ
				{
					t1-=N;
					if (t1+t2>=N)//�ж���ӵ�ֵ�Ƿ񳬹��޷������͵�0x80
						chars[5]++;
				}

				//����2
				/*short adi=chars[4];//�����ж��Ƿ��н�λ
				adi+=chars[2];

				chars[4]+=chars[2];
				chars[5]+=chars[3];
				if (adi>255)
					chars[5]++;*/
				chars[0]--;
			}

		}
		cout<<"���:"<<*num<<"\t ����"<<*other<<endl;
	}
	system("pause");
	return 0;
}