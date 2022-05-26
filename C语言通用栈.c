#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define STACK_INIT_SIZE 20

typedef void* ElemType;
typedef struct  
{
	ElemType elem;
	int elemSize;//ÿ��Ԫ�صĴ�С
	int destLen;//��ǰ��ռ��λ��
	int stackSize;//ջ�Ĵ�С
}Stack,*pStack;

void StackInit(pStack s, int elemSize)
{
	/* �õ����ʹ�С */
	s->elemSize = elemSize;
	/* ��ǰջ��С */
	s->destLen = 0;
	/* ʵ��ջ�Ĵ�С20 */
	s->stackSize = 4;
	/* ����Ԫ�ش�С(ջ��С * Ԫ�ش�С) */
	s->elem = (ElemType)malloc(s->stackSize * s->elemSize);
	if (!s->elem)
		exit(0);
}
void StackDestroy(pStack s)
{
	/* �ͷ��ڴ� */
	free(s->elem);
}
/* ��ȡ��ǰ��С */
int StackLen(pStack s)
{
	return s->destLen;
}

void StackPush(pStack s,ElemType e)
{
	/* �жϵ�ǰ��С��ջ��С�ǲ���һ�� */
	if (s->destLen ==s->stackSize)
	{
		s->stackSize *= 2;
		s->elem = realloc(s->elem, s->stackSize * s->elemSize);
		if (!s->elem)
			exit(0);
	}
	/* ����һ��Ԫ��λ�� */
	void *t = (char*)s->elem + s->destLen * s->elemSize;
	/* �������� */
	memcpy(t, e, s->elemSize);
	/* ��ǰ��С���� */
	++s->destLen;
}
void StackPop(pStack s, ElemType e)
{
	if (!StackLen(s))
		exit(0);
	/* ���Լ���ǰջ��λ�� */
	--s->destLen;
	/* ��ȡ����λ�� */
	void *source = (char*)s->elem + s->destLen * s->elemSize;
	/* ����Ԫ�� */
	memcpy(e, source, s->elemSize);
}

int main()
{
	Stack s;
	const char* str[] = { "hello","world","good" };
	/* ��ʼ���ַ���Ԫ�ش�СΪ 10 */
	StackInit(&s, sizeof(char*));
	for (int i = 0; i < 3; i++) {
		StackPush(&s, (char*)&str[i]);
	}
	for (int i = 0; i < 3; i++) {
		char *getS;
		StackPop(&s, &getS);
		printf("The string %d is %s.\n", i, getS);
	}
	StackDestroy(&s);

	StackInit(&s, sizeof(int));
	int arr[3] = { 5,6,7 };
	for (int i = 0; i < 3; i++) {
		StackPush(&s, (char*)&arr[i]);
	}
	for (int i = 0; i < 3; i++) {
		int num;
		StackPop(&s, &num);
		printf("The string %d is %d.\n", i, num);
	}
	StackDestroy(&s);
	return 0;
}