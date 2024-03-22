#ifndef _SSLINKLIST_H_
#define _SSLINKLIST_H_

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXSIZE 10

// 系数与指数构成有序对
typedef struct OPair{
    // 系数
    int coefficient; 
    // 指数
    int index;
}OPair;

typedef OPair ElemType;


// cur = 0代表node是尾节点, cur = -1代表此数据已被删除, 或者此空间未被占用
typedef struct
{
    ElemType data;
    int cur;
}SLNode, SLinkList[MAXSIZE];

// 初始化操作
void InitList(SLinkList SL, ElemType* arr, int length);

// 打印列表
void PrintList(SLinkList SL);

// 结构销毁操作
void DestroyList(SLinkList SL);

// 顺序表判空
bool ListEmpty(SLinkList SL);

// 求顺序表的长度
int ListLength(SLinkList SL);

// 求数据元素前驱
ElemType PriorElem(SLinkList SL, ElemType cur_e, ElemType* pre_e);

// 求数据元素后继
ElemType NextElem(SLinkList SL, ElemType cur_e, ElemType* next_e);

// 求链表中的第i个数据元素
ElemType GetElem(SLinkList SL, int i, ElemType* e);

// 定位函数
int LocateElem(SLinkList SL, ElemType e, bool (*compare)(ElemType, ElemType));

// 遍历顺序表
bool ListTraverse(SLinkList SL, bool (*visit)(ElemType));

// 线性表置空
void ClearList(SLinkList SL);

// 改变数据元素的值
void PutElem(SLinkList SL, int i, ElemType* e);

// 插入数据元素
void ListInsert(SLinkList SL, int i, ElemType e);

// 删除数据元素
ElemType ListDelete(SLinkList SL, int i, ElemType* e);

/*
    以下为上面函数的实现
*/

// 初始化操作
void InitList(SLinkList SL, ElemType* arr, int length)
{
    if(length > MAXSIZE - 1)
    {
        printf("超出静态链表范围！\n");
        return;
    }
    ElemType ZeroPair = {0, 0};
    SL[0].data = ZeroPair;
    for(int i = 1; i < MAXSIZE - 1; i++)
    {
        SL[i].data = ZeroPair;
        SL[i].cur = -1;
    }

    if(length == 0){
        SL[0].cur = 0;
        return;
    }
    
    for(int i = 0; i < length; i++)
    {
        SL[i + 1].data = arr[i];
        SL[i].cur = i + 1;
    }
}

// 打印列表
void PrintList(SLinkList SL)
{
    int i = 0;
    if(SL[i].cur == 0)
    {
        printf("该链表为空链表!\n");
        return;
    }
    int j = 1;
    while(SL[i].cur && SL[i].cur != -1)
    {       
        i = SL[i].cur;
        printf("第%d：<%d, %d>\n", j++, SL[i].data.coefficient, SL[i].data.index); 
    }
}

// 结构销毁操作
void DestroyList(SLinkList SL)
{
    ElemType ZeroPair = {0, 0};
    SL[0].data = ZeroPair;
    for(int i = 1; i < MAXSIZE - 1; i++)
    {
        SL[i].data = ZeroPair;
        SL[i].cur = -1;
    }
    SL[0].cur = 0;
    return;
}

// 顺序表判空
bool ListEmpty(SLinkList SL)
{
    if(SL[0].cur == 0)
    {
        return true;
    }
    return false;
}

// 求顺序表的长度
int ListLength(SLinkList SL)
{
    int i = 0;
    while(SL[i].cur && SL[i].cur != -1)
    {       
        i = SL[i].cur; 
    }
    return i;
}

// 求数据元素前驱
ElemType PriorElem(SLinkList SL, ElemType cur_e, ElemType* pre_e)
{
    int i = 0;
    ElemType ZeroPair = {0, 0};
    int pre_i;
    while(SL[i].cur && SL[i].cur != -1)
    {   
        pre_i = i;
        i = SL[i].cur; 
        if(SL[i].data.coefficient == cur_e.coefficient && SL[i].data.index == cur_e.index)
        {
            *pre_e = SL[pre_i].data;
            return *pre_e;
        }
    }
    return ZeroPair;
}

// 求数据元素后继
ElemType NextElem(SLinkList SL, ElemType cur_e, ElemType* next_e)
{
    int i = 0;
    ElemType ZeroPair = {0, 0};
    while(SL[i].cur && SL[i].cur != -1)
    {   
        i = SL[i].cur; 
        if(SL[i].data.coefficient == cur_e.coefficient && SL[i].data.index == cur_e.index)
        {
            *next_e = SL[SL[i].cur].data;
            return *next_e;
        }
    }
    return ZeroPair;
}

// 求链表中的第i个数据元素
ElemType GetElem(SLinkList SL, int i, ElemType* e)
{
    *e = SL[i].data;
    return *e;
}

// 定位函数
int LocateElem(SLinkList SL, ElemType e, bool (*compare)(ElemType, ElemType))
{
    int i = 0;
    while(SL[i].cur && SL[i].cur != -1)
    {       
        i = SL[i].cur;
        if(compare(SL[i].data, e))
            return i;
    }
    return -1;
}

// 遍历顺序表
bool ListTraverse(SLinkList SL, bool (*visit)(ElemType))
{
    int i = 0;
    while(SL[i].cur && SL[i].cur != -1)
    {       
        i = SL[i].cur;
        if(!visit(SL[i].data))
            return false;
    }
    return true;
}

// 线性表置空
void ClearList(SLinkList SL)
{
    ElemType ZeroPair = {0, 0};
    SL[0].data = ZeroPair;
    for(int i = 1; i < MAXSIZE - 1; i++)
    {
        SL[i].data = ZeroPair;
        SL[i].cur = -1;
    }
    SL[0].cur = 0;
    return;
}

// 改变数据元素的值
void PutElem(SLinkList SL, int i, ElemType* e)
{
    SL[i].data = *e;
}

// 插入数据元素(可优化)
void ListInsert(SLinkList SL, int i, ElemType e)
{
    int ind = ListLength(SL) + 1;
    if(i >= ind)
    {
        SL[ind - 1].cur = i;
        SL[i].data = e;
        SL[i].cur = 0;
        return;
    }
    
    SL[ind].cur = i;
    SL[ind].data = e;
    SL[i - 1].cur = ind;
  
}

// 删除数据元素
ElemType ListDelete(SLinkList SL, int j, ElemType* e)
{
    int i = 0;
    ElemType ZeroPair = {0, 0};
    int pre_i;
    while(SL[i].cur && SL[i].cur != -1)
    {   
        pre_i = i;
        i = SL[i].cur; 
        if(i == j)
        {
            SL[pre_i].cur = SL[i].cur;
            SL[i].cur = -1;
        }
    }
    *e = SL[j].data;
    return *e;
}

#endif