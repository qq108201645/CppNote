#include<iostream>
#include<iomanip>
using namespace std;

void Display(double **XN2,int X,int N)
{
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout <<setiosflags(ios::left)<< setw(3) << XN2[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	int X=2,N,i,j;
	/*cout<<"请输入二维数组第二行数量"<<endl;
	cin >> N;*/
	N = 20;
	cout<<"二维数组长度:"<<N<<endl;
	double** XN2 = new double*[X];
	for (i = 0; i < X; i++)
	{
		XN2[i] = new double[N];//遂个分配内存长度20
	}
	int num = rand();//接收一个随机数
	for (j = 0; j < N; j++)
	{
		XN2[0][j] = num++;//接收顺序数
		XN2[1][j] = (rand()%1==0&& rand() % 2 != 0);//随机接收0或1
		if (j==N-1)
		{
			XN2[1][j] = 1;
		}
	}
	//临时测试类型，
	double tmp1[2][20] = { {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20},
	{ 0,0,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,1} };
	for (j = 0; j < N; j++)//测试给值到XN2
	{
		XN2[0][j] = tmp1[0][j];
		XN2[1][j] = tmp1[1][j];
	}
	Display(XN2,X,N);//显示
	//测试
	double arr[5][4] = { {1,2,0,0},{5,7,0,0},{16,2,0,0}, {17,18,0,0},{12,11,10,0} }, (*m)[4] = arr;
	for (i=0;i<5;i++)
	{
		cout << "m[" << i+1 << "]={";
		for (j=0;j<4;j++)
		{
			if (*(*(m + i) + j) != 0)
			{
				cout << setw(3) << *(*(m + i) + j) << " ";
			}
		}
		cout<<"}"<<endl;
	}

	//查找功能

	int flag;
	for (int i = 0; i < N; i++)
	{
		int l = 0;
		while (l<5)//循环查找五个元素
		{
			int t = i;
			j = 0;
			flag = 0;
			if (j<1&&m[l][j]==XN2[0][t])
			{
				
					if (m[l][j] - m[l][j + 1] <= 1 || m[l][j+1] - m[l][j] >= -1)//控制在1与-1
					{
						j++;
					}
					if ((XN2[0][t] - XN2[0][t + 1] <= 1 || XN2[0][t+1] - XN2[0][t] >= -1)&&XN2[1][t]==0)//后一位相减控制在1或-1
					{
						flag++;
					}
					else if ((XN2[0][t] - XN2[0][t - 1] <= 1 || XN2[0][t-1] - XN2[0][t] >= -1)&&XN2[1][t] != 0)//前一位相减控制在1或-1
					{
						flag++;
					}
					
			}
			if (flag == j&&flag==1)
			{
				cout << l + 1 << " ";
				while (XN2[1][t] != 1)
				{
					t++;
				}
				i = t + 1;//保存位置
				break;//如果找到则退出循环
			}
			l++;
		}
	}

	//释放内存
	for (i = 0; i < X; i++)
	{
		delete[] XN2[i];
	}

	delete[] XN2;
	cout << endl;
	system("pause");
	
	return 0;
}