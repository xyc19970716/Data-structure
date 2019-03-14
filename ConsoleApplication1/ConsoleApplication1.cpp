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

//创建链表
Node* createList()
{
	Node* p = (Node*)malloc(sizeof(Node));	//游标
	Node* head;	//头指针
	head = p;
	while (1)
	{
		Node* temp = (Node*)malloc(sizeof(Node));
		scanf("%d", &temp->Data);
		if (temp->Data == -1)
		{
			p->next = NULL;
			free(temp);
			break;
		}
		else
		{
			p->next = temp;
			p = p->next;
		}
	}
	
	return head;
}

//获取链表长度
int getListLengh(Node* head)
{
	Node* p = head;
	int temp = 0;
	while (p->next != NULL)
	{
		temp++;
		p = p->next;
	}
	return temp;
}

//查找元素
//找到返回指针，没找到返回空指针
Node* getPositionForValue(Node* head, int Value)
{
	while (head->next != NULL)
	{
		if (head->Data == Value)
		{
			return head;
		}
		else
		{
			head = head->next;
		}
	}
	return NULL;
}

//删除链表的节点
//成功返回true，失败返回false
bool deleteValueForList(Node* head, int Value)
{
	 
	Node* p = head;
	Node* per;
	while (p->next != NULL)
	{
		per = p;
		p = p->next;
		if (p->Data == Value)
		{
			per->next = p->next;
			return true;
		}
	}
	return false;
}

//插入节点（在某个节点后插入）
//成功返回true，失败返回false
bool insertValueInList(Node* node, int Value)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->Data = Value;
	temp->next = node->next;
	node->next = temp;
	return true;
}

//在控制台上遍历显示链表
void ShowListInConsole(Node* head)
{
	while (head->next != NULL)
	{
		head = head->next;
		printf("%d ", head->Data);
	}
	printf("\n");

}

int main()
{

	Node* head = createList();
	ShowListInConsole(head);
	printf("%d\n", getListLengh(head));
	Node* find = getPositionForValue(head, 2);
	printf("%d\n", find->Data);
	deleteValueForList(head, 2);
	ShowListInConsole(head);
	insertValueInList(getPositionForValue(head, 1), 2);
	ShowListInConsole(head);
    return 0; 
}

