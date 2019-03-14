// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include"pch.h"
#include<cstdio>
#include<cstdlib>

struct Node
{
	int Data;
	Node* next;
};

void create()
{

}
int main()
{
	Node* a = (Node*)malloc(sizeof(Node));
	Node* b = (Node*)malloc(sizeof(Node));
	Node* c = (Node*)malloc(sizeof(Node));
	Node* d = (Node*)malloc(sizeof(Node));
	Node* p;
	a->Data = 1;
	a->next = b;
	b->Data = 2;
	b->next = c;
	c->Data = 3;
	c->next = d;
	d->Data = -1;
	d->next = NULL;
	p = a;
	while (p->next != NULL)
	{
		printf("%d", p->Data);
		p = p->next;
	}

	free(a);
	free(b);
	free(c);
	free(d);
    return 0; 
}

