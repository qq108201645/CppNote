#include <stdio.h>
int length_(char ch[])
{
	// ��������
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
		ch[i] = ch[i + deletelen];	// ���ڵ�ǰ����+λ��
	
		if (i >= len - deletelen)	// ��������ܳ��ȵ���ȥ�����ݳ��ȣ��������0
			ch[i] = '\0';
	}
}

// 121214
// 12
int main()
{
	char ch[1024], key[10];
	printf("�����뵥���ÿո�����");
	gets(ch);
	// ����ch����
	int i, j, t, location, len = length_(ch);

	printf("����Ҫɾ�����ַ�");

	gets(key);
	int keylen = length_(key);
	for (int i = 0; i < len; i++)
	{
		t = i;
		j = 0;
		// �ж��ǲ���һ��
		while (j < keylen && ch[t] == key[j])
		{
			t++, j++;
		}
		if (j == keylen)
		{
			// һ���Ļ���������
			sort(ch, len, i, j);
			i -= j;				// ���ص�ǰλ�ã���ֹ��������
		}
	}
	printf("%s", ch);
	return 0;
}
