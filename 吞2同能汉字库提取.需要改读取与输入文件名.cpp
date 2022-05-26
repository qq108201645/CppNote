#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<windows.h>
using namespace std;

#define byte unsigned char
const int Size = 16;
int flag_c = 0;
//����������ز���ֵ�Ļ�������ı�
//ROL����λ�����ǽ��ֽ�������ͬ��λCһ������������1λ
byte ROL(byte val)//ѭ������
{
    byte ret = val >> 7;//�������λ
    val <<= 1;//����λ
    val |= flag_c;//��1�����
    flag_c = false;//�����־λ
    flag_c |= ret;//��ȡ���λ�Ƿ���1
    return val;
}

//ASL��λ�����ǽ��ֽ��ڸ�λ����������1λ,���λ�ƽ���־λC��,���λ��0
byte ASL(byte val)//��������
{
    flag_c = false;//�����־λ
    byte ret = val >> 7;//�������λ
    val <<= 1;//����λ
    flag_c |= ret;//��ȡ���λ�Ƿ���1
    return val;
}

//��ָ����ǽ��ֽ��ڸ�λ����������1λ,���λ�ƽ���־λC,���λ��0.
byte LSR(byte val)//�߼�����
{
    flag_c = false;//�����־λ
    flag_c |= val & 1;//�õ���λ��־
    val >>= 1;//����λ
    return val;
}

bool Empty(byte arr[], int sz)
{
    int cnt = 0, i;
    for (i = 0; i < sz; i++) //�ж���ȡ���Ƿ���0,�ǵĻ�����
    {

        if (arr[i] == '\0')
        {
            ++cnt;
        }
    }
    return cnt == i;
}

byte DataResult(byte arr[],byte &elem,byte &re, int &cnt_0, int &cnt_1, int &SetAddr, int cnt_x)
{
    do
    {
        if (!(--SetAddr))
        {
            elem = arr[cnt_1++];
            SetAddr = 8;
        }
        elem = LSR(elem);//�߼�����
        re = ROL(re);//ѭ������
    }
    while (--cnt_x);
    return  re;
}
void ElemProcess(byte data[],byte tmp[])
{
    //cnt_0=51f8,cnt_1=51f9,SetAddr=51fa,elem=51fb, re=result


    byte elem = '\0', re = '\0';


    int cnt_0 = 5, cnt_1 = 0, SetAddr = 1;
    do
    {
        re = '\0';
        byte c = DataResult(data, elem,re,cnt_0, cnt_1, SetAddr, 8);
        tmp[cnt_0] = c;//��һ��
        c = DataResult(data, elem, re, cnt_0, cnt_1, SetAddr, 3);

        c <<= 5;

        tmp[cnt_0 + 0x10] = c;//�ڶ��е�
        ++cnt_0;
    }
    while (cnt_0 != 16);

}
int main()
{
    byte data[16] ={
        0x88, 0x40, 0x04, 0x22, 0x15, 0xA5, 0x1B, 0x45, 0x28, 0x42, 0x11, 0xBA, 0x74, 0xE4, 0xE0, 0xF9
    };


    ifstream fpr("1.dat",ios::binary|ios::in);
    if (!fpr)
    {
        cout<<"δ�����ļ��˳�"<<endl;
        exit(1);
    }
    else//90410��ǰ�����ֿ�
        fpr.seekg(0x91010,ios::beg);
    ofstream fpw("2.dat",ios::binary|ios::out);
    if (!fpw)
    {
        cout<<"δ�����ļ�������"<<endl;
    }
    fpw.close();
    fpw.open("2.dat",ios::binary|ios::out|ios::in);
    cout<<"�����ɹ�"<<endl;
    byte tmp[Size * 2] { 0 }, out[Size * 4] { 0 };


    while(1)
    {
        //memset((char*)data,0,Size);

        fpr.read((char*)data,Size);
        if (Empty(data, Size))//��ȡ����Ϊ�����˳�
            break;
        ElemProcess(data,tmp);
        int i=0,j=0,k=0;
        while(k<Size*2/8)
        {
            memcpy((char*)out+i,(char*)tmp+j,8);
            k++;
            i+=0x10,j+=0x8;
        }
        fpw.write((char*)out,Size*4);
    }
    fpw.close();
    fpr.close();

    cout<<"д��2.dat���"<<endl;
    return 0;
}
