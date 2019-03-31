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

struct TreeNode
{
	int Data;
	TreeNode* left;
	TreeNode* right;
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

//反转链表
//返回头指针
Node* reverseList(Node* head)
{
	Node* p;
	p = head->next;
	free(head);
	Node* temp;
	temp = p;
	p = p->next;
	temp->next = NULL;
	Node* per;
	per = temp;
	Node* q;
	while (p->next != NULL)
	{
		q = p->next;
		p->next = per;
		per = p;
		p = q;
	}
	p->next = per;
	Node *h = (Node*)malloc(sizeof(Node));
	h->next = p;
	return h;
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
//用单向链表创建空栈
//返回头指针
Node* createStack()
{
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	return head;
}

//判断是否空栈
//空栈返回true，否则返回false
bool stackIsEmpty(Node* head)
{
	if (head->next == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//压栈
//成功返回true
bool stackPush(Node* head, int Value)
{
	Node* node = (Node*)malloc(sizeof(Node));
	Node* temp;
	if (head->next == NULL)
	{
		head->next = node;
		node->Data = Value;
		node->next = NULL;
	}
	else
	{
		temp = head->next;
		head->next = node;
		node->Data = Value;
		node->next = temp;
	}
	return true;
}

//出栈
//返回出栈节点值
int stackPop(Node* head)
{
	Node* temp;
	int value;
	if (!stackIsEmpty(head))
	{
		temp = head->next;
		value = temp->Data;
		head->next = temp->next;
		free(temp);
		return value;
	}
}

//先序创建二叉树
//返回根节点
TreeNode* createTree()
{
	int val;
	scanf("%d",&val);
	if (val == -1)
	{
		return NULL;
	}
	else
	{
		TreeNode* head = (TreeNode*)malloc(sizeof(TreeNode));
		head->Data = val;
		head->left = createTree();
		head->right = createTree();
		return head;
	}
}

//二叉树先序遍历
void perOrder(TreeNode* head)
{
	if (head != NULL)
	{
		printf("%d ", head->Data);
		perOrder(head->left);
		perOrder(head->right);
	}
}

//二叉树中序遍历
void inOrder(TreeNode* head)
{
	if (head != NULL)
	{
		inOrder(head->left);
		printf("%d ", head->Data);
		inOrder(head->right);
	}
}

//二叉树后序遍历
void lastOrder(TreeNode* head)
{
	if (head != NULL)
	{
		lastOrder(head->left);
		lastOrder(head->right);
		printf("%d ", head->Data);
	}
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
	Node* re = reverseList(head);
	ShowListInConsole(re);
	Node* stack = createStack();
	if (stackIsEmpty(stack))
	{
		printf("Yes\n");
	}
	stackPush(stack, 1);
	stackPush(stack, 2);
	ShowListInConsole(stack);
	printf("%d\n",stackPop(stack));
	printf("%d\n", stackPop(stack));

	TreeNode* tree = createTree();
	perOrder(tree);
	printf("\n");
	inOrder(tree);
	printf("\n");
	lastOrder(tree);
	printf("\n");

    return 0; 
}

