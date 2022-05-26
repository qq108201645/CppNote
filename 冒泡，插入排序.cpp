#include <iostream>
#include <ctime>
#include <string>
//ð������
int* Bubble_sort(int data[], int len)
{
	std::cout << "˳���С����:";
	for (int i = 0; i < len - 1; i++)//i��ʼ��0��ѭ�������ȼ�1
		for (int j = i + 1; j < len; ++j)//j��ʼ��������һ��λ�ã���������Ƚ���
			if (data[i] > data[j])//�����ǰ����һ��λ�ô������Ե�//�������϶Ե���iλ�õ�ֵ��С
			{
				int t = data[i];
				data[i] = data[j];
				data[j] = t;
			}
	return data;
}
//��������
int *Insert_Sort(int data[], int len)
{
	std::cout << "˳��Ӵ�С:";
	for (int i = 1; i < len; ++i)
	{
		int temp = data[i];//��ʼ������i��ǰλ��
		int j = i - 1;//j����ǰһ��λ��
		while (data[j]<temp&&j>=0)//����һ��С�ڵ�ǰλ�õ�ֵ,����j>=0�����ѭ��
								  //ֱ���ҵ���ǰ���ֵ����j<0
		{
			data[j + 1] = data[j];//��ǰ������һ��λ�õ�ֵ
			j--;
		}
		data[j + 1] = temp;//j--��������j+1�ǵ������С��temp��λ��
		//�������whileѭ��,����ǰ��С��temp��ֵ�滻�����ֵ
		//���δ����,��iλ���Լ���ֵ
	}
	return data;
}

int main()
{
	void Display(int data[], int len);
	int data[] = { 11,44,2,35,68,94,14,20 };
	int len = sizeof(data) / sizeof(int);
	int data1[8];
	memcpy(data1, data, 4*8);
	clock_t start_, end_;//����һ��time����
	start_ = clock();//��ʼʱ��
	Display(Bubble_sort(data, len), len);//����ð������
	end_ = clock();//����ʱ��
	std::cout << "����ð����������" << (double)(end_ - start_) / CLOCKS_PER_SEC << "��" << std::endl;
	memcpy(data, data1, 4 * 8);
	start_ = clock();//��ʼʱ��
	Display(Insert_Sort(data, len), len);//���ò�������
	end_ = clock();//����ʱ��
	std::cout << "���ò�����������" << (double)(end_ - start_) / CLOCKS_PER_SEC << "��" << std::endl;
	system("pause");
	return 0;
}
void Display(int data[], int len)
{
	for (int i = 0; i < len; i++)
	{
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}