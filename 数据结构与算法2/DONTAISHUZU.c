//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <malloc.h>
//
//struct donshuzu
//{
//	int* shuzu;
//	unsigned int RonLiang;
//	unsigned int ShuLiang;
//};
//void shuru(struct donshuzu* p);
//void ZenJia(struct donshuzu* pshuzu, int Nshuju);
//void ChaRu(struct donshuzu* pshuzu, int ShuJu, unsigned int XiaBiao);
//void shuchu(struct donshuzu* p);
//void BianDa(struct donshuzu* pshuzu);
////void ZenJiaDuoGe(struct donshuzu* pshuzu, int* a, int* b, int c);
//void ShanChuWeiBu(struct donshuzu* pshuzu);
//void ShanChuQuanBu(struct donshuzu* pshuzu);
//void ShanChuZhonJian(struct donshuzu* pshuzu, unsigned int ilocation);
//
//int main(void)
//{
//	struct donshuzu  moveshuzu;
//
//	shuru(&moveshuzu);
//	ZenJia(&moveshuzu, 3);
//	ZenJia(&moveshuzu, 2);
//	ZenJia(&moveshuzu, 1);
//	
//	ChaRu(&moveshuzu, 5, 11);
//
//	shuchu(&moveshuzu);
//
//	//ShanChuZhonJian(&moveshuzu, 3);删除中间一个数据
//	//shuchu(&moveshuzu);
//	//ShanChuWeiBu(&moveshuzu);删除尾部一个数据
//	//shuchu(&moveshuzu);
//	//ShanChuQuanBu(&moveshuzu);删除全部数据
//	//shuchu(&moveshuzu);
//
//	free(moveshuzu.shuzu);
//	system("pause");
//	return 0;
//}
//void ShanChuZhonJian(struct donshuzu* pshuzu, unsigned int ilocation)
//{
//	if (NULL == pshuzu || ilocation>pshuzu->ShuLiang)
//		{
//			printf("输入参数错误！\n");
//			return;
//		}
//	//循环挪位置
//	for (unsigned int i = ilocation - 1; i < pshuzu->ShuLiang-1; i++)
//	{
//		pshuzu->shuzu[i] = pshuzu->shuzu[i + 1];
//	}
//	//数量-1
//	pshuzu->ShuLiang--;
//}
//void ShanChuQuanBu(struct donshuzu* pshuzu)
//{
//	if (NULL == pshuzu)
//	{
//		printf("输入参数错误！");
//		return;
//	}
//	pshuzu->ShuLiang = 0;
//	pshuzu->RonLiang = 0;
//	free(pshuzu->shuzu);
//	pshuzu->shuzu = NULL;
//}
//void ShanChuWeiBu(struct donshuzu* pshuzu)
//{
//	if (NULL == pshuzu)
//	{
//		printf("输入参数错误！");
//		return;
//	}
//	pshuzu->ShuLiang--;
//}
//
//
//
//void shuru(struct donshuzu* p)
//{
//	if (NULL == p)
//	{
//		printf("输入参数错误！");
//		return;
//	}
//	p->RonLiang = 5;
//	p->shuzu = (int*)malloc(sizeof(int) * p->RonLiang);
//	p->ShuLiang = 0;
//}
//void ZenJia(struct donshuzu* pshuzu, int Nshuju)
//{
//	if (NULL == pshuzu)
//	{
//		printf("输入参数错误！");
//		return;
//	}
//	//判断是否已经满了
//	if (pshuzu->RonLiang == pshuzu->ShuLiang)
//	{
//		BianDa(pshuzu);
//
//	}
//	//把数据装进去，数量++
//	pshuzu->shuzu[pshuzu->ShuLiang] = Nshuju;
//	pshuzu->ShuLiang++;
//	return;
//}
//void BianDa(struct donshuzu* pshuzu)
//{
//	if (NULL == pshuzu)
//	{
//		printf("输入参数错误！");
//		return;
//	}
//	//容量变大
//	pshuzu->RonLiang += 10;
//	//申请空间
//	int* New = (int*)malloc(sizeof(int) * pshuzu->RonLiang);
//	//memset(New, 0, sizeof(int) * pshuzu->RonLiang);
//	//复制原数据
//	for (unsigned int i = 0; i < pshuzu->ShuLiang; i++)
//	{
//		New[i] = pshuzu->shuzu[i];
//	}
//	//将原空间释放
//	free(pshuzu->shuzu);
//	//将原空间指向新空间
//	pshuzu->shuzu = New;
//
//
//}
//void ChaRu(struct donshuzu* pshuzu, int ShuJu, unsigned int XiaBiao)
//{
//	if (NULL == pshuzu)
//	{
//		printf("输入参数错误！");
//		return;
//	}
//	//如果下标大于数量。就把数据加在后面
//	if (XiaBiao > pshuzu->ShuLiang)
//	{
//		XiaBiao = pshuzu->ShuLiang;
//		
//
//	}
//
//	//循环挪位置
//	for (unsigned int i = pshuzu->ShuLiang; i >= XiaBiao; i--)
//	{
//		pshuzu->shuzu[i] = pshuzu->shuzu[i - 1];
//	}
//	//把值赋值到指定位置
//	pshuzu->shuzu[XiaBiao] = ShuJu;
//	//数量增加
//	pshuzu->ShuLiang++;
//}
//
//
//
//
//
//void shuchu(struct donshuzu* p)
//{
//	if (NULL == p)
//	{
//		printf("输入参数错误！");
//		return;
//	}
//	printf("容量：%u 数量：%u", p->RonLiang, p->ShuLiang);
//	printf("\n数据： ");
//	for (unsigned int i = 0; i < p->ShuLiang; i++)
//	{
//		printf("%d ", p->shuzu[i]);
//	}
//	printf("\n");
//}
//void ZenJiaDuoGe(struct donshuzu* pshuzu,int*a,int*b,int c)
//{
//	for (int i = 0; i < c; i++)
//	{
//		for (int j = 0; j < c; j++)
//		{
//			ChaRu(pshuzu, a[i], b[i]);
//		}
//	}
//}