#ifndef _SEQTABLE_H                
#define _SEQTABLE_H

#include<stdio.h>
#include<stdbool.h>

// 将int定义为元素类型
typedef long long int ElementType ;

// 顺序表的最大容量
#define Max_Capacity 100

// 构造顺序表结构体
typedef struct SeqList
{
    ElementType list[Max_Capacity];
    int length;
}SeqList;

// 初始化操作
void InitList(SeqList* SL, ElementType* arr, int length);

// 结构销毁操作
void DestroyList(SeqList* SL);

// 顺序表判空
bool ListEmpty(SeqList SL);

// 求顺序表的长度
int ListLength(SeqList SL);

// 求数据元素前驱
ElementType PriorElem(SeqList SL, ElementType cur_e, ElementType* pre_e);

// 求数据元素后继
ElementType NextElem(SeqList SL, ElementType cur_e, ElementType* next_e);

// 求顺序表中的某个数据元素
ElementType GetElem(SeqList SL, int i, ElementType* e);

// 定位函数
int LocateElem(SeqList SL, ElementType e, bool (*compare)(ElementType, ElementType));

// 遍历顺序表
bool ListTraverse(SeqList SL, bool (*visit)(ElementType));

// 线性表置空
void ClearList(SeqList* SL);

// 改变数据元素的值
void PutElem(SeqList* SL, int i, ElementType* e);

// 插入数据元素
void ListInsert(SeqList* SL, int i, ElementType e);

// 删除数据元素
ElementType ListDelete(SeqList* SL, int i, ElementType* e);

/*
*   以下为上面函数的实现
*/

// 初始化操作
void InitList(SeqList* SL, ElementType* arr, int length)
{
    SL->length = length;
    for(int i = 0; i < length; i++)
    {
        SL->list[i] = arr[i];
    }
}

// 结构销毁操作
void DestroyList(SeqList* SL)
{
    SL->length = 0;
}

// 顺序表判空
bool ListEmpty(SeqList SL)
{
    if(SL.length == 0)
        return true;
    return false;
}

// 求顺序表的长度
int ListLength(SeqList SL)
{
    return SL.length;
}

// 求数据元素前驱
ElementType PriorElem(SeqList SL, ElementType cur_e, ElementType* pre_e)
{
    
    if(SL.list[0] == cur_e)
    {
        printf("该元素为首元素，没有前驱！\n");
        return NULL;
    }

    for(int i = 1; i < SL.length; i++)
    {
        if(SL.list[i] == cur_e)
        {
            *pre_e = SL.list[i-1];
            return *pre_e;
        }
    }

    // 未找到该元素
    return NULL;
}

// 求数据元素后继
ElementType NextElem(SeqList SL, ElementType cur_e, ElementType* next_e)
{

    if(SL.list[SL.length - 1] == cur_e)
    {
        printf("该元素为尾元素，没有后继！\n");
        return NULL;
    }

    for(int i = 0; i < SL.length - 1; i++)
    {
        if(SL.list[i] == cur_e)
        {
            *next_e = SL.list[i+1];
            return *next_e;
        }
    }
    
    // 未找到该元素
    return NULL;
}

// 求顺序表中的某个数据元素
ElementType GetElem(SeqList SL, int i, ElementType* e)
{
    if(i >= 0 && i < SL.length)
        return SL.list[i];
    else
     return NULL;
}

// 定位函数
int LocateElem(SeqList SL, ElementType e, bool (*compare)(ElementType, ElementType))
{
    for(int i = 0; i < SL.length; i++)
    {
        if(compare(SL.list[i], e))
            return i;
    }
    // 如果没有找到满足条件的元素，返回下标值为-1
    return -1;
}

// 遍历顺序表
bool ListTraverse(SeqList SL, bool (*visit)(ElementType))
{
    for(int i = 0; i < SL.length; i++)
    {
        if(!visit(SL.list[i]))
            return false;
    }
    return true;
}

// 线性表置空
void ClearList(SeqList* SL)
{
    SL->length = 0;
}

// 改变数据元素的值
void PutElem(SeqList* SL, int i, ElementType* e)
{
    if(i >= 0 && i < SL->length)
        SL->list[i] = *e;
    else
        printf("未找到第i个元素，无法操作！\n");
}

// 插入数据元素
void ListInsert(SeqList* SL, int i, ElementType e)
{
    if(SL->length + 1 > Max_Capacity)
    {
        printf("超出做大容量，无法操作！\n");
        return;
    }

    for(int j = SL->length; j >= i; j--)
    {
        SL->list[j+1] = SL->list[j];
    }

    SL->length++;
    SL->list[i] = e;
}

// 删除数据元素
ElementType ListDelete(SeqList* SL, int i, ElementType* e)
{
    if(!(i >= 0 && i < SL->length))
    {
        printf("未找到第i个元素，删除失败！\n");
        return NULL;
    }

    *e = SL->list[i];

    for(int j = i; j < SL->length; j++)
    {
        SL->list[j] = SL->list[j+1];
    }

    SL->length--;

    return *e;
}

#endif