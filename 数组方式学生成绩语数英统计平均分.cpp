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
	string name = "张王李赵周";
	size_t len = name.size() / N;
	size_t sum[N] = { 0 };
	for (int i = 0,j; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			total += score[i][j];//统计语数英成绩
			sum[j] += score[i][j];//统计数学,语文,英语成线
		}
		string buf = name.substr(i*len, len);
		cout<<buf<<"同学总计:"<<total<<"分 平均分是:"<<total/M<<endl;
		
	}
	string s1 = "数学语文英语";
	for (int i=0;i<3;i++)
	cout<<s1.substr(i*len*2,len*2)<<"总成绩:"<<sum[i]<<" 平均成绩:"<< sum[i]/N<<endl;

	system("pause");
	return 0;
}