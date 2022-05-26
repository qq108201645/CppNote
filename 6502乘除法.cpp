#include <stdio.h>
#include <string.h>
int flag_c=false;//��־λ
//6502�˳���by��ȻС��
void ROL(unsigned char &val)//ѭ������
{
    unsigned char ret=val>>7;//�������λ
    val<<=1;//����λ
    val|=flag_c;//��1�����
    flag_c=false;//�����־λ
    flag_c|=ret;//��ȡ���λ�Ƿ���1
}
void ASL(unsigned char &val)//��������
{
    flag_c=false;//�����־λ
    unsigned char ret=val>>7;//�������λ
    val<<=1;//����λ
    flag_c|=ret;//��ȡ���λ�Ƿ���1
}

unsigned char ADC(unsigned char& a, unsigned char& b)
{
    unsigned short ret=a+b+(flag_c&1);
    //����1��1�����1��ʾ�ϴ����н�λ��
    flag_c=false;//�����־λ

    flag_c|=(ret>>8)&1;//�ж�01 00��λ��û�н�λ
    return ret;
}
unsigned char SBC(unsigned char& a, unsigned char& b)
{
    unsigned short ret=a-b-((flag_c&1)^1);
    //����1��1�����1����1����0����ʾ��һ��flag_cδ�䣬��������֮������
    flag_c=false;//�����־λ
    flag_c|=((ret>>8)&1)^1;//�ж�ff 00��λ��û�����(����1�������1������0)
    return ret;
}
//24��8λ
void mul(int &a,int &b)
{
    int len=10;
    unsigned char arr[10];
    memset(arr,0,len);
    //��ʼ��arr[2]��ʼ�������ֽڣ�����arr[6]����
    strncpy((char*)arr+2, (char*)&a, 3);
    strncpy((char*)arr + 6, (char*)&b, 1);
    for(arr[7]=24; arr[7]!=0; --arr[7])
    {
        ASL(arr[0]);
        ROL(arr[1]);
        ROL(arr[2]);
        ROL(arr[3]);
        ROL(arr[4]);

        if(flag_c)
        {
            flag_c=false;//�����λ��־
            arr[0]=ADC(arr[0],arr[5]);
            arr[1]=ADC(arr[1],arr[6]);
            if(flag_c)
            {
                arr[2]++;
            }
        }
    }
    strncpy((char*)arr, (char*)arr+1, 3);
    strncpy((char*)&a, (char*)arr, 3);
}
//24��16λ
void div(int &a,int &b)
{
    int len=10;
    unsigned char arr[10];
    memset(arr,0,len);

    //��ʼ��arr[0]��ʼ�������ֽڣ�����arr[6]��ʼ����������
    strncpy((char*)arr, (char*)&a, 3);
    strncpy((char*)arr + 6, (char*)&b, 3);

    arr[9]=24;
    while(arr[9])
    {
        ASL(arr[0]);//�������ƣ�ASL��λ�����ǽ��ֽ��ڸ�λ����������1λ,���λ�ƽ���־λC��,���λ��0
        ROL(arr[1]);//ѭ�����ƣ���λ�����ǽ��ֽ�������ͬ��λCһ������������1λ
        ROL(arr[2]);//����
        ROL(arr[3]);//����
        ROL(arr[4]);//����
        ROL(arr[5]);//����
        unsigned char t1 = arr[3];//��ʱ����
        flag_c=1;//��֮ǰ��־λ��1
        arr[3]=SBC(arr[3], arr[6]);
        unsigned char t2 = arr[4];
        arr[4]=SBC(arr[4], arr[7]);
        unsigned char t3=SBC(arr[5], arr[8]);//t3����arr[5]�����ֵ,������Ƿ����
        if(flag_c)
        {
            arr[5]=t3;
            arr[0]++;
        }
        else
        {
            arr[3]=t1;
            arr[4]=t2;
        }
        arr[9]--;
    }
    strncpy((char*)&a, (char*)arr, 3);
    strncpy((char*)&b, (char*)arr + 3, 3);
}
void multest(int a,int b)//24��8λ
{
    printf("%d ��%d", a, b);
    mul(a, b);
    printf(" = %d\t\n", a);
}
void divtest(int a, int b)//24��16λ
{
    printf("%d ��%d", a, b);
    div(a, b);
    printf(" = %d\t����Ϊ��%d\n", a, b);
}
int main()
{
    multest(80, 6);
    multest(120, 23);
    divtest(99, 8);
    divtest(70, 23);
    divtest(30, 6);

    return 0;
}
