#include <stdio.h>
int length_(char ch[])
{
	// 测量长度
	int i = 0, len = 0;
	while (ch[i] != '\0')
	{
		i++, len++;
	}
	return len;
}

void sort(char ch[], int len, int locat, int deletelen)
{
	int i;
	for (i = locat; i < len; i++)
	{
		ch[i] = ch[i + deletelen];	// 等于当前长度+位置
	
		if (i >= len - deletelen)	// 如果到达总长度到减去的内容长度，则后面置0
			ch[i] = '\0';
	}
}

// 121214
// 12
int main()
{
	char ch[1024], key[10];
	printf("请输入单词用空格区分");
	gets(ch);
	// 测量ch长度
	int i, j, t, location, len = length_(ch);

	printf("输入要删除的字符");

	gets(key);
	int keylen = length_(key);
	for (int i = 0; i < len; i++)
	{
		t = i;
		j = 0;
		// 判断是不是一样
		while (j < keylen && ch[t] == key[j])
		{
			t++, j++;
		}
		if (j == keylen)
		{
			// 一样的话调用排序
			sort(ch, len, i, j);
			i -= j;				// 返回当前位置，防止连续数据
		}
	}
	printf("%s", ch);
	return 0;
}
