#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
int main()
{
	char buf[1024];	
	memset(buf,0,1024);// ="123 456";
	printf("ÊäÈëÒ»¶Ñ×Ö·û´®\n");
	gets(buf);
	char tmp[1024][30]={0};
	int i=0;
	char ch[] = " 1234567890,./~!@#$%^&*()_+-=';";
	for (char *p = strtok((char *)buf, ch); p != NULL; p = strtok(0, ch))
	{
		strcpy(tmp[i++],p);
	}
	

	for (i=0;tmp[i][0]!='\0';i++)
	{
		for (int j=i+1;tmp[j][0]!='\0';j++)
		{
			if (!strcmp(tmp[i],tmp[j]))
			{
				int t;
				for (t=j;tmp[t][0]!='\0';t++)
				{
					strcpy(tmp[t],tmp[t+1]);
				}
				memset(tmp[t],0,30);
				j--;
			}
			memset(ch,0,strlen(ch));
			if (tmp[i][0]>tmp[j][0])
			{
				strcpy(ch,tmp[i]);
				strcpy(tmp[i],tmp[j]);
				strcpy(tmp[j],ch);
			}
		}
	}
	
	for (i=0;tmp[i][0]!='\0';i++)
	{
		printf("%s\n",tmp[i]);
	}
	return 0;
}
