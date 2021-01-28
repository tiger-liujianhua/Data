#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
	int iValue;
	struct Node* Site;

};
void AddToEnd(struct Node** pHead, struct Node** pEnd, int iDate);
void AddToEndNoEnd(struct Node** pHead, int iDate);
void FreeList(struct Node* pHead);
void Look(struct Node* pHead);
void AddToHead(struct Node** pHead, struct Node** pEnd,int iDate);
struct Node* FindNodeByIndex(struct Node* pHead, int iIndex);
void InsertNodeByIndex(struct Node** pHead, struct Node** pEnd, int iIndex, int iData);
struct Node* FindNodeByData(struct Node* pHead, int iData);
void ChangeDataByData(struct Node* pHead, int oldData, int newData);
void ChangeSameData(struct Node* pHead,int oldData,int newData);//存在缺陷，找不到数据无法返回提示信息
void ChangeSameDataTest(struct Node* pHead, int oldData, int newData);
void DeleteHead(struct Node** pHead, struct Node** pEnd);
void DeleteEnd(struct Node** pHead, struct Node** pEnd);
struct Node* DeleteOneDateByData(struct Node** pHead, struct Node** pEnd, int iData);
void DeleteAllDateByData(struct Node** pHead, struct Node** pEnd, int iData);
void DeleteDateIndex(struct Node** pHead, struct Node** pEnd, int iIndex);
void SwapByData(struct Node* pHead, int iData1, int iData2);
void SwapTowNode(struct Node** pHead, struct Node** pEnd, int iIndex1, int iIndex2);
int GetNodeNums(struct Node* pHead);
void ReverseByData(struct Node** pHead, struct Node** pEnd);
void ReverseByHelpSpace(struct Node** pHead, struct Node** pEnd);
int main(void)
{
	struct Node* pHead = NULL;
	struct Node* pEnd = NULL;
	
	
	//AddToEnd(&pHead,&pEnd, 1);
	//AddToHead(&pHead, &pEnd, 4);
	AddToHead(&pHead, &pEnd, 3);
	AddToHead(&pHead, &pEnd, 2);
	AddToHead(&pHead, &pEnd, 1);
	AddToEnd(&pHead, &pEnd, 2);
	
	AddToEnd(&pHead, &pEnd, 3);
	AddToEnd(&pHead, &pEnd, 4);
	InsertNodeByIndex(&pHead, &pEnd, 4, 1234);
	Look(pHead);
	for (int i = 0; i < 5; i++)
	{
		AddToEnd(&pHead, &pEnd, 5);
	}
	/*AddToEnd(&pHead, &pEnd, 6);
	Look(pHead);
	ChangeSameData(pHead, 5, 8);*/
	Look(pHead);
	/*ChangeSameDataTest(pHead,55, 15);
	DeleteEnd(&pHead, &pEnd);
	DeleteOneDateByData(&pHead, &pEnd, 3);
	DeleteOneDateByData(&pHead, &pEnd, 2);
	DeleteOneDateByData(&pHead, &pEnd, 5);*/
	//DeleteAllDateByData(&pHead, &pEnd, 4);
	//DeleteDateIndex(&pHead, &pEnd, 0);
	//SwapByData(pHead, 3,4);
	//SwapTowNode(&pHead, &pEnd, 1, 6); 

	/*printf("%d", GetNodeNums(pHead));
	putchar('c');*/
	ReverseByData(&pHead, &pEnd);
	Look(pHead);
	ReverseByHelpSpace(&pHead, &pEnd);
	Look(pHead);
	
	

	system("pause");
	return 0;

}
void ReverseByHelpSpace(struct Node** pHead, struct Node** pEnd)//翻转链表__辅助空间
{

	if (*pHead == NULL || NULL == (*pHead)->Site)
	{
		return;
	}
	else 
	{
		struct Node* pt = *pHead;
		struct Node* pNewHead=NULL;
		struct Node* pNewEnd=NULL;
		while (pt != NULL)
		{
			AddToHead(&pNewHead, &pNewEnd, pt->iValue);
			pt = pt->Site;
		}
		*pHead = pNewHead;
		*pEnd = pNewEnd;
		FreeList(pt);
	}
}
void ReverseByData(struct Node** pHead, struct Node** pEnd)//翻转链表__原地翻转
{
	if (*pHead == NULL || NULL == (*pHead)->Site)
		{
			return;
		}
	else
	{
		
		int i = 0;
		int j = GetNodeNums(*pHead)-1;
		for (; i < j; i++, j--)
		{
			SwapTowNode(pHead, pEnd, i, j);
		}
		return;
	}
}
int GetNodeNums(struct Node* pHead)//统计节点个数
{
	
	int i = 0;
		while (pHead != NULL)
		{
			i++;
			pHead = pHead->Site;
		}
		return i;
	
	
}
void SwapTowNode(struct Node** pHead, struct Node** pEnd, int iIndex1, int iIndex2)//交换两个节点
{
	if (iIndex1==iIndex2 || (*pHead)->Site==NULL || *pHead==NULL || iIndex1<0 || iIndex2<0)
			{
				printf("参数错误!\n");
				return;
			}
	else
	{
		int iMin = iIndex1;
		int iMax = iIndex2;
		if (iIndex1 > iIndex2)
		{
			 iMin = iIndex2;
			 iMax = iIndex1;
		}
		struct Node* pMin=FindNodeByIndex(*pHead, iMin);
		struct Node* pMax = FindNodeByIndex(*pHead, iMax);
		if (NULL == pMin || NULL == pMax)
		{

			return;
		}
		if (pMin == *pHead && pMax == *pEnd)//节点是首尾
		{   //两个节点
			if ((*pHead)->Site == *pEnd)
			{
				pMax->Site = *pHead;
				pMin->Site = NULL;
				*pHead = *pEnd;
				*pEnd = (*pHead)->Site;
			}
			else//三个及以上节点
			{
				struct Node* pMaxa = FindNodeByIndex(*pHead, iMax - 1);
				pMax->Site = (*pHead)->Site;
				pMaxa->Site = *pHead;
				(*pHead)->Site = NULL;
				*pHead = *pEnd;
				*pEnd = pMaxa->Site;
			}
		}
		else if (pMin == *pHead && pMax != *pEnd)//节点是头与中间
		{
			if ((*pHead)->Site == pMax)//两节点相邻，即一二节点
			{
				 
				(*pHead)->Site=pMax->Site;
				pMax->Site=*pHead;
				*pHead = pMax;
				
			}
			else//两节点不相邻
			{
				struct Node* pMaxb = FindNodeByIndex(*pHead, iMax - 1);
				struct Node* pt = pMin->Site;
				pMin->Site = pMax->Site;
				pMaxb->Site = pMin;
				pMax->Site = pt;
				*pHead = pMax;
				
			}
		}
		else if(pMax == *pEnd && pMin != *pHead)//节点是尾部与中间
		{
			struct Node* pMina = FindNodeByIndex(*pHead, iMin - 1);
			struct Node* pMaxc = FindNodeByIndex(*pHead, iMax - 1);
			if (pMin->Site == *pEnd)//相邻
			{
				(*pEnd)->Site = pMin;
				pMina->Site = *pEnd;
				pMin->Site = NULL;
			}
			else//不相邻
			{
				 pMaxc->Site= pMin;
				(*pEnd)->Site = pMin -> Site;
				pMina->Site = *pEnd;
				*pEnd=pMin;
				pMin->Site = NULL;

			}
		}
		else//节点是中间和中间
		{
			struct Node* pMinb = FindNodeByIndex(*pHead, iMin - 1);
			struct Node* pMaxd = FindNodeByIndex(*pHead, iMax - 1);
			if (pMin->Site == pMax)//相邻
			{
				
				pMin->Site = pMax->Site;
				pMax->Site = pMin;
				pMinb->Site = pMax;
			}
			else//不相邻
			{
				struct Node* i = pMin->Site;
				pMin->Site = pMax->Site;
				pMaxd->Site = pMin;
				pMax->Site = i;
				pMinb->Site = pMax;
			}
		}

	}

}
void SwapByData(struct Node* pHead, int iData1, int iData2)//交换两个节点的数据
{
	if (pHead == NULL)
		{
			printf("参数错误!\n");
			return;
		}
	else
	{
		//找到数据
		struct Node* pt = FindNodeByData(pHead, iData1);
		struct Node* pa = FindNodeByData(pHead, iData2);
		if (pt != NULL && pa != NULL)
		{
			//交换
			int i = pt->iValue;
			pt->iValue = pa->iValue;
			pa->iValue = i;
			//使用函数解决
			/*struct Node pb = *pt;
			memcpy(pt, pa,4);
			memcpy(pa, &pb, 4);*/
		}
	}
}
void DeleteDateIndex(struct Node** pHead, struct Node** pEnd, int iIndex)//依照下标删除节点
{
	if (*pHead == NULL)
	{
		printf("参数错误!\n");
		return;
	}
	if (iIndex == 0)
	{
		DeleteHead(pHead, pEnd);//1  2  3  4
	}
	else
	{
		struct Node* pt = FindNodeByIndex(*pHead, iIndex-1);
		if (pt != NULL)
		{
			struct Node* pa = pt->Site;
           pt->Site = pa->Site;
		   free(pa);
		}
		else
		{
			return;
		}
		
		
	}
}
void DeleteAllDateByData(struct Node** pHead, struct Node** pEnd, int iData)//删除所有数据Data的节点
{
	if (*pHead == NULL)
	{
		printf("参数错误！");
		return ;
	}
	else
	{
		struct Node* pt = DeleteOneDateByData(pHead, pEnd, iData);
		while (pt != NULL)
		{
			/*DeleteOneDateByData(&pt, pEnd, iData);*/
			pt = DeleteOneDateByData(&pt, pEnd, iData);

		}
	}
}

struct Node* DeleteOneDateByData(struct Node** pHead, struct Node** pEnd, int iData)//删除特定数据节点
{
	if (*pHead == NULL)
		{
			printf("参数错误！");
			return NULL;
		}
	if ((*pHead)->iValue == iData)//数据在头部
	{
		DeleteHead(pHead, pEnd);
		return *pHead;
	}
	else if ((*pEnd)->iValue == iData)//数据在尾部
	{
		DeleteEnd( pHead, pEnd);
		return *pHead;

	}
	else
	{
		struct Node* pt = *pHead;
			while(pt->Site !=NULL)//寻找该数据的前一个节点
			{
				if (pt->Site->iValue == iData)
				{
					//pt->Site = pt->Site->Site;
					break;
				}
					
				/*else
					printf("无此数据！\n");*/
				pt = pt->Site;
			}
			if (pt->Site != NULL)
			{
				struct Node* pa = pt->Site;
					pt->Site = pa->Site;
					free(pa);	
					return pt->Site;
			}
			else
			{
				printf("无此数据！\n");
				return NULL;
			}
			
			

	}
}
void DeleteEnd(struct Node** pHead, struct Node** pEnd)//删除尾
{
	
	if ((*pHead)->Site == NULL)
	{
		free(*pHead);
		*pHead = NULL;
		*pEnd = NULL;
	}
	else
	{
		struct Node* pt = *pHead;
		while (pt->Site != *pEnd)
		{
			pt = pt->Site;
		}
		free(*pEnd);
		*pEnd = pt;
		pt->Site = NULL;
	}
}
void DeleteHead(struct Node** pHead, struct Node** pEnd)//删除头，缺陷（使用AddToEnd函数赋值第一个节点会报错）已解决2021年1月18日15:46:08
{
	if (*pHead == NULL)
	{
		printf("参数错误！");
		return;
	}
	if ((*pHead)->Site == NULL)
	{
		free(*pHead);
		*pHead = NULL;
		*pEnd = NULL;
	}
	else
	{
		struct Node* pt = *pHead;
		*pHead = (*pHead)->Site;
			free(pt);
	}

}
void ChangeSameDataTest(struct Node* pHead, int oldData, int newData)//找到所有相同节点，并改变它(效率低）
{
	if (pHead == NULL)
	{
		printf("参数错误！");
		return;
	}
	else
	{
		struct Node* pt = FindNodeByData(pHead, oldData);
		while (pt != NULL)
		{
			ChangeDataByData(pHead, oldData, newData);
			pt = pt->Site;
		}
	}
}
void ChangeSameData(struct Node* pHead, int oldData, int newData)//找到所有相同节点，并改变它
{
	if (pHead == NULL)
		{
			printf("参数错误！");
			return ;
		}
	else
	{
		while (pHead != NULL)
		{
			if (pHead->iValue == oldData)
				pHead->iValue = newData;
			pHead = pHead->Site;
		}
	}
}
void ChangeDataByData(struct Node* pHead, int oldData, int newData)//用数据找到节点，并改变它的数据
{
	struct Node* pt = FindNodeByData(pHead, oldData);
	if (pt != NULL)
	{
	
	pt->iValue = newData;
	}
}
struct Node* FindNodeByData(struct Node* pHead, int iData)//根据数据找节点，并返回该节点
{
	if (pHead == NULL)
	{
		printf("参数错误！");
		return NULL;
	}
	else
	{
		while (pHead != NULL)
		{
			if (pHead->iValue == iData)
			{
				return pHead;
			}
			pHead=pHead->Site;
		}
	}
	printf("无此数据！\n");
	return NULL;
}
void InsertNodeByIndex(struct Node** pHead, struct Node** pEnd, int iIndex, int iData)//指定节点插入数据(可在结尾插入)
{//参数检验
	if (iIndex < 0 )
	{
		printf("参数错误！\n");
		return;
	}
//创建节点
	
	if (iIndex == 0)
	{
		AddToHead(pHead, pEnd, iData);
		return;
	}
	else
	{
		struct Node* pt = (struct Node*)malloc(sizeof(struct Node));
		pt->iValue = iData;
		pt->Site = NULL;
		struct Node* pa=FindNodeByIndex(*pHead, iIndex-1);
		if (pa != NULL)
		{
			pt->Site = pa->Site;
			pa->Site = pt;
			
		}
		else
		{
			printf("无此节点");
		}
		
		
	}
	
}
struct Node* FindNodeByIndex(struct Node* pHead, int iIndex)//根据下标查找数据，并返回该节点
{//参数检验
	if (pHead == NULL || iIndex < 0)
	{
		printf("输入参数错误！\n");
		return NULL;
	}
	int i = 0;
	while (pHead != NULL)
	{
		if (iIndex == i)
		{
			return pHead;
		}
		i++;
		pHead = pHead->Site;
	}
	printf("参数过大/无此数据\n");
	return NULL;

}
void AddToHead(struct Node** pHead, struct Node** pEnd,int iDate)//添加头部节点（空链表）
{
	//创建节点

	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
	//赋值
	pTemp->iValue = iDate;
	pTemp->Site = NULL;
	//判断创建成功
	if (pTemp != NULL)
	{
		if (*pHead == NULL)
		{
			*pHead = pTemp;
			*pEnd = pTemp;
		}
		else
		{
			pTemp->Site = *pHead;
			*pHead = pTemp;

			
		}
	}
}
void Look(struct Node* pHead)//查看数据

{
	while (pHead != NULL)
	{
		printf("%d ", pHead->iValue);
		pHead = pHead->Site;
	}
	putchar('\n');
}
void FreeList(struct Node* pHead)//释放空间
{
	while (pHead != NULL)
	{
		struct Node* pt = pHead;
		pHead = pHead->Site;
		free(pt);
	}
}
void AddToEnd(struct Node** pHead, struct Node** pEnd, int iDate)//添加尾部节点（空链表）
{
	//创建节点
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
	if (pTemp != NULL)
	{
	//节点成员赋值
	pTemp->iValue = iDate;
	pTemp->Site = NULL;
	//连上去
	if (*pHead == NULL)//空链表
	{
		*pHead = pTemp;
		*pEnd = pTemp;
	}
	else
	{
		(*pEnd)->Site = pTemp;
		*pEnd = pTemp;
	}
	}
}
void AddToEndNoEnd(struct Node** pHead, int iDate)//增加节点
{
	//创建节点
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
	if (NULL != pTemp)
	{
		//成员赋值
		pTemp->iValue = iDate;
		pTemp->Site = NULL;
		if (*pHead == NULL)
		{
			*pHead = pTemp;
		}
		else
		{
			struct Node* pt = *pHead;
			while (pt->Site !=NULL)//寻找最后一个节点
			{
				pt = pt->Site;
				
			}
			pt->Site = pTemp;
		}

	}
}