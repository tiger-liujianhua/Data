/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
	int ivalue;
	struct Node* site;//另一个节点的地址
};
void Look(struct Node* pHead);
struct Node* FindByDate(struct Node* pHead, int iDate);
void ShowDate(struct Node* Find);
struct Node* FindByIndex(struct Node* pHead, int iIndex);
int DateNums(struct Node* pHead, int iDate);
void SameDate(struct Node*pHead,struct Node* *arr, int iDate);
void ChangeByDate(struct Node* pHead, int iDate,int NewDate);
void ChangeByIndex(struct Node* pHead, int iIndex, int NewDate);
int main(void)
{
	struct Node a = { 1,NULL },
		        b = { 2, NULL}, 
				c = { 3,NULL },
				d = { 4,NULL };
	a.site = &b;
	b.site = &c;
	c.site = &d;
	Look(&a);
	//putchar('\n');
	//ChangeByIndex(&a, 0, 22);
	//Look(&a);

	//struct Node* Find = FindByDate(&a, 2);
	//ShowDate(Find);
	//ShowDate(FindByIndex(&a, 3));

	//struct Node* arr[4] = { NULL };
	//SameDate(&a, arr, 2);

	//printf("该数据的个数为：%d", DateNums(&a, 2));
	
	system("pause");
	return 0;
}
void ChangeByIndex(struct Node* pHead, int iIndex, int NewDate)//通过下标查找数据并改变它

{
	struct Node* Change = FindByIndex(pHead, iIndex);
	if (Change != NULL)
	{
		Change->ivalue = NewDate;
	}
	else
    printf("无此数据！\n");
}

void ChangeByDate(struct Node* pHead, int iDate, int NewDate)//通过数据查找数据并改变它
{
	struct Node* Change = FindByDate(pHead, iDate);
	if (Change != NULL)
	{
		Change->ivalue = NewDate;
	}
	else
		printf("无此数据！\n");


}

void SameDate(struct Node* pHead, struct Node** arr, int iDate)
{
	int i = 0;
	while (pHead != NULL)
	{
		if (pHead->ivalue == iDate)
		{
			arr[i++] = pHead;
		}

		pHead = pHead->site;
	}
	printf("数据为：");
	for (int i=0 ; i < 4 && arr[i] != NULL; i++)
	{
		printf("%d  ", arr[i]->ivalue);
		
	}
}

int DateNums(struct Node* pHead, int iDate)//查找指定数据的个数
{
	int count = 0;
	while (pHead != NULL)
	{
		if (pHead->ivalue == iDate)
			count++;
		pHead = pHead->site;
	}
	return count;
}

struct Node* FindByIndex(struct Node* pHead, int iIndex)//根据下标查找节点
{
	int i=0;//当i=0，根据下标；当i=1，根据位置；
	while (pHead != NULL)
		{
			if (i == iIndex)
				return pHead;
			pHead = pHead->site;
			
			i++;
			
		}
	return NULL;
}
void ShowDate(struct Node* Find)//判断
{
if (Find == NULL)
	{
		printf("无此节点!\n");
	}
	else
		printf("此节点地址%p\n此节点数据%d\n", Find, Find->ivalue);
		
}
struct Node* FindByDate(struct Node* pHead, int iDate)//根据数据查找节点
{
	while (pHead != NULL)
	{
		if (pHead->ivalue == iDate)
			return pHead;
		pHead = pHead->site;
	}
	return NULL;
}
void Look(struct Node* pHead)//遍历所有节点数据
{
	while (pHead != NULL)
	{
	printf("%d\n", pHead->ivalue);
	pHead = pHead->site;
	}
}*/