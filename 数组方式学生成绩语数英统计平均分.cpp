#include <iostream>
#include <string>
using namespace std;
#define N 5
#define M 3
int main()
{
	int score[N][M] = {
		{88,70,90},
	{80,80,60},
	{89,60,85},
	{80,75,78},
	{70,80,80}
	};
	int total = 0;
	string name = "����������";
	size_t len = name.size() / N;
	size_t sum[N] = { 0 };
	for (int i = 0,j; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			total += score[i][j];//ͳ������Ӣ�ɼ�
			sum[j] += score[i][j];//ͳ����ѧ,����,Ӣ�����
		}
		string buf = name.substr(i*len, len);
		cout<<buf<<"ͬѧ�ܼ�:"<<total<<"�� ƽ������:"<<total/M<<endl;
		
	}
	string s1 = "��ѧ����Ӣ��";
	for (int i=0;i<3;i++)
	cout<<s1.substr(i*len*2,len*2)<<"�ܳɼ�:"<<sum[i]<<" ƽ���ɼ�:"<< sum[i]/N<<endl;

	system("pause");
	return 0;
}