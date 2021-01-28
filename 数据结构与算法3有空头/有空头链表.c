#include <stdio.h>
#include <stdlib.h>
	struct Node
	{
		int iValue;
		struct Node* Site;
	};
void AddToTail(struct Node* stHead, int iData);
void FreeList(struct Node* stHead);
void Look(struct Node* stHead);
void AddToHead(struct Node* stHead, int iData);
void AddBehandData(struct Node* stHead, int iOriginalData,int iData);
void AddByIndexSelf(struct Node* stHead, int iOriginalIndex, int iData);
void AddByIndex(struct Node* stHead, int iOriginalIndex, int iData);
void AddBySomeIndex(struct Node* stHead, int iOriginalIndex, int iCycleNums,int iData);
struct Node* FindNodeByData(struct Node* stHead, int iData);
struct Node* FindNodeByIndex(struct Node* stHead, int iIndex);
void ChangeNodeByData(struct Node* stHead, int iOriginalData, int iData);
void ChangeNodeByIndex(struct Node* stHead, int iOriginalIndex, int iData);
void DeleteSameData(struct Node* stHead);



int main(void)
{
	int iNodeCounts = 0;
	struct Node stHead = { 0,NULL };
	
	AddToTail(&stHead,  2);
	AddToTail(&stHead,  3);
	AddToTail(&stHead,  4);
	AddToTail(&stHead,  5);
	//
	////FreeList(&stHead);
	//AddToHead(&stHead, 1);
	//Look(&stHead);
	//AddBehandData(&stHead, 5, 6);
	//AddByIndex(&stHead, 6, 7);
	//Look(&stHead);
	//AddByIndex(&stHead, 7, 8);
	Look(&stHead);
	//ChangeNodeByData(&stHead, 1, 66);
	DeleteSameData(&stHead);
	//ChangeNodeByIndex(&stHead, 7, 2);
	//AddBySomeIndex(&stHead, 0,3, 8);
	Look(&stHead);
	//struct Node* pt = FindNodeByData(&stHead, 66);
	//struct Node* pt = FindNodeByIndex(&stHead,1);
	/*if (NULL != pt)
	{
		printf("%d\n", pt->iValue);
	}
	else
	{
		printf("查无此数据！\n");
	}*/
	system("pause");
	return 0;
}
void DeleteSameData(struct Node* stHead)//删除相同数据节点
{
	if (NULL == stHead || stHead->iValue <= 1)
		return;
	struct Node* pt = stHead->Site;
	while (NULL != pt)
	{
		struct Node* pa = pt;
		while (NULL != pa->Site)
		{
			if (pa->Site->iValue == pt->iValue)
			{
				struct Node* pb = pa->Site;
				pa->Site = pa->Site->Site;
				stHead->iValue -= 1;
				free(pb);
				continue;
				
			}
			pa = pa->Site;
		}
		pt = pt->Site;
	}

}
void ChangeNodeByIndex(struct Node* stHead, int iOriginalIndex, int iData)//改变指定节点数据————下标
{
	if (NULL == stHead || stHead->iValue <= 0 || iOriginalIndex<0 || iData<0 ||iOriginalIndex>stHead->iValue || iData>stHead->iValue)
		return ;
	else
	{
		struct Node* pt = FindNodeByIndex(stHead, iOriginalIndex);//可使用循环，不使用函数
		if (NULL != pt)
		{
			pt->iValue = iData;
		}
		else
		{
			printf("查无此数据！\n");
		}

	}
}
void ChangeNodeByData(struct Node* stHead, int iOriginalData, int iData)//改变指定节点数据————数据
{
	if (NULL == stHead || stHead->iValue <= 0)
		return ;
	else
	{
		struct Node* pt = stHead->Site;//可使用函数
		for (int i = 0; i < stHead->iValue; i++)
		{
			if (iOriginalData == pt->iValue)
			{
				pt->iValue = iData;
			}
			pt = pt->Site;
		}
		
		
	}
}
struct Node* FindNodeByIndex(struct Node* stHead, int iIndex)//查找节点————下标
{
	if (NULL == stHead || iIndex < 0)
		return NULL;
	else
	{
		struct Node* pt = stHead->Site;
		int i = 0;
		while (NULL != pt)
		{
			if (iIndex == i)
				break;
			i++;
			pt = pt->Site;
		}
		return pt;
	}
}
struct Node* FindNodeByData(struct Node* stHead, int iData)//查找节点————数据
{
	if (NULL == stHead || stHead->iValue<=0)
		return NULL;
	else
	{
		struct Node* pt = stHead->Site;
		while (pt != NULL)
		{
			if (iData == pt->iValue)
				break;
			pt = pt->Site;
		}
		return pt;
	}
		
}
void AddBySomeIndex(struct Node* stHead, int iOriginalIndex, int iCycleNums, int iData)//插入多个数据
{
	if (NULL == stHead || iOriginalIndex < 0 || iOriginalIndex>stHead->iValue)
	{
		return;
	}
	else
	{
		struct Node* pt = stHead;
		int i = 0;
		while (i < iOriginalIndex)
		{
			i++;
			pt = pt->Site;
		}
		for (int i = 0; i < iCycleNums; i++)
		{
		AddToHead(pt, iData);
				pt->iValue -= 1;
				stHead->iValue += 1;
		}
		
	}
}
void AddByIndex(struct Node* stHead, int iOriginalIndex, int iData)//在指定下标位置插入节点
{
	if (NULL == stHead || iOriginalIndex < 0 || iOriginalIndex>stHead->iValue)
	{
		return;
	}
	else
	{
		struct Node* pt = stHead;
		int i = 0;
		while (i < iOriginalIndex)
		{
			i++;
			pt = pt->Site;
		}
		AddToHead(pt, iData);
		pt->iValue -= 1;
		stHead->iValue += 1;
	}
}
void AddByIndexSelf(struct Node* stHead, int iOriginalIndex, int iData)//在指定下标位置插入节点
{
	if (NULL == stHead || iOriginalIndex < 0 )//|| iOriginalIndex+1>stHead->iValue
	{
		return;
	}
	else if (0 == iOriginalIndex)
	{
		AddToHead(stHead, iData);
		return;
	}
	else 
	{
		struct Node* pt = stHead->Site;
		int i = 0;
		while (pt != NULL)
		{
			if (i == iOriginalIndex-1)
				break;
			i++;
			pt = pt->Site;
		}
		if (NULL == pt)
		{
			printf("查无此节点\n");
			return;
		}
		else
		{
			struct Node* pa = (struct Node*)malloc(sizeof(struct Node));
			if (NULL == pa)
				return;
			pa->iValue = iData;
			pa->Site = NULL;
			pa->Site = pt->Site;
			pt->Site = pa;
			stHead->iValue++;
		}
	}
}
void AddBehandData(struct Node* stHead, int iOriginalData,int iData)//在指定数据后面插入数据
{
	if (NULL == stHead || iOriginalData < 0 || stHead->iValue <= 0)
	{
		return;
	}
	else
	{
		struct Node* pt = stHead->Site;
		while (pt != NULL)
		{
			if (pt->iValue == iOriginalData)
				break;
			pt = pt->Site;
		}
		if (NULL == pt)
		{
			printf("查无此数据\n");
		}
		else
		{
			struct Node* pa = (struct Node*)malloc(sizeof(struct Node));
			if (pa == NULL)
				return;
			pa->iValue = iData;
			pa->Site = NULL;
			pa->Site = pt->Site;
			pt->Site = pa;
			stHead->iValue++;
			/*AddToHead(pt, iData);
			pt->iValue--;
			stHead->iValue++;*///第二种方法，调用函数
		}
	}
}
void AddToHead(struct Node* stHead, int iData)//链表头添加
{
	if (NULL == stHead || iData < 0)
		return;
	struct Node* pt = (struct Node*)malloc(sizeof(struct Node*));
	if (NULL == pt)
		return;
	pt->iValue = iData;
	pt->Site = NULL;
	pt->Site = stHead->Site;
	stHead->Site = pt;
	stHead->iValue++;
}
void Look(struct Node* stHead)//遍历链表并输出至控制台
{
	if (NULL == stHead || stHead->iValue <= 0)
	{
		printf("参数错误/链表无数据\n");
		return;
	}
	else 
	{
		struct Node* pt = stHead->Site;
		printf("共有 %d 个数据\n", stHead->iValue);
		while (pt != NULL)
		{
			printf("%d ", pt->iValue);
			pt = pt->Site;
		}
		putchar('\n');
	}
}
void FreeList(struct Node* stHead)//释放链表
{
	if (NULL == stHead || 0 == stHead->iValue)
		return;
	struct Node* pt = stHead->Site;
	while (pt->Site != NULL)
	{
		struct Node* pa = pt;
		pt = pt->Site;
		free(pa);

	}
	stHead->iValue = 0;
	stHead->Site = NULL;
	stHead->iValue = 0;
}
void AddToTail(struct Node* stHead,  int iData)//链表尾添加
{
	if (stHead == NULL ||  stHead->iValue < 0)
	{
		return;
	}
	else
	{
		struct Node* pt = (struct Node*)malloc(sizeof(struct Node));
		if (pt != NULL)
		{
			pt->iValue = iData;
			pt->Site = NULL;
			struct Node* pa = stHead;
			while (pa->Site != NULL)
				pa = pa->Site;
			pa->Site = pt;
			(stHead->iValue)++;
			//free(pt);
		}
	}
}