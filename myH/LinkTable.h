#ifndef _LINKTABLE_H                
#define _LINKTABLE_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef long long int ElemType;
static int LinkLength;

typedef struct  LNode
{
    ElemType data;
    struct LNode* next;
}LNode,* LinkList;

// 判断内存是否分配成功
bool IsAlloMemSucc(LNode* node);

// 初始化操作
LinkList InitList(LinkList SL, ElemType* arr, int length);

// 打印列表
void PrintList(LinkList SL);

// 结构销毁操作
void DestroyList(LinkList SL);

// 顺序表判空
bool ListEmpty(LinkList SL);

// 求顺序表的长度
int ListLength(LinkList SL);

// 求数据元素前驱
ElemType PriorElem(LinkList SL, ElemType cur_e, ElemType* pre_e);

// 求数据元素后继
ElemType NextElem(LinkList SL, ElemType cur_e, ElemType* next_e);

// 求链表中的第i个数据元素
ElemType GetElem(LinkList SL, int i, ElemType* e);

// 定位函数
int LocateElem(LinkList SL, ElemType e, bool (*compare)(ElemType, ElemType));

// 遍历顺序表
bool ListTraverse(LinkList SL, bool (*visit)(ElemType));

// 线性表置空
void ClearList(LinkList SL);

// 改变数据元素的值
void PutElem(LinkList SL, int i, ElemType* e);

// 插入数据元素
void ListInsert(LinkList SL, int i, ElemType e);

// 删除数据元素
ElemType ListDelete(LinkList SL, int i, ElemType* e);

/*
    以下为上面函数的实现
*/

// 判断内存是否分配成功
bool IsAlloMemSucc(LNode* node)
{
    if(node == NULL){
        printf("创建链表时分配内存失败！\n");
        return false;
    }
    return true;
}

// 初始化操作
LinkList InitList(LinkList SL, ElemType* arr, int length)
{
    SL = (LNode*)malloc(sizeof(LNode));
    LNode* head, * node, * end;

    if(!IsAlloMemSucc(SL))
    {
        return NULL;
    }

    head = SL;
    end = head;
    LinkLength = length;

    for(int i = 0; i < LinkLength; i++)
    {
        node = (LNode*)malloc(sizeof(LNode));
        node->data = arr[i];
        if(!IsAlloMemSucc(node))
            return NULL;
        end->next = node;
        end = node;
    }

    end->next = NULL;
    return head;
}

// 结构销毁操作
void DestroyList(LinkList SL)
{
    LNode* head, * node;
    head = SL->next;
    
    while (head != NULL) 
    {
        node = head;
        head = head->next;
        free(node);
    }

    free(SL);
    LinkLength = 0;
}

// 顺序表判空
bool ListEmpty(LinkList SL)
{
    if(SL == NULL)
        return true;
    return false;
}

// 打印列表
void PrintList(LinkList SL)
{
    if(ListEmpty(SL))
    {
        printf("该链表没有初始化！\n");
        return;
    }
    // 注意 头节点没有数据
    LNode* node = SL->next;
    int index = 1;
    
    while(node != NULL)
    {
        printf("第%d项：%lld\n", index, node->data);
        node = node->next;
        index++;
    }
}

// 求顺序表的长度
int ListLength(LinkList SL)
{
    return LinkLength;
}

// 求数据元素前驱
ElemType PriorElem(LinkList SL, ElemType cur_e, ElemType* pre_e)
{
    LNode* pre_node, * node;
    if(SL->next->data == cur_e)
    {
        printf("此元素为首元素，没有前驱！\n");
        return NULL;
    }
    pre_node = SL->next;
    node = pre_node->next;

    while(node != NULL && node->data != cur_e )
    {
        pre_node = node;
        node = node->next;
    }

    if(node == NULL)
    {
        printf("未在链表中找到该元素！\n");
        return NULL;
    }

    *pre_e = pre_node->data;

    return *pre_e;
}

// 求数据元素后继
ElemType NextElem(LinkList SL, ElemType cur_e, ElemType* next_e)
{
    LNode * node;
    node = SL->next;

    while(node != NULL && node->data != cur_e )
    {
        node = node->next;
    }

    if(node == NULL)
    {
        printf("未在链表中找到该元素！\n");
        return NULL;
    }

    if(node->next == NULL)
    {
        printf("此元素为尾元素，没有后继！\n");
        return NULL;
    }

    *next_e = node->next->data;
    return *next_e;
}

// 求链表中的第i个数据元素
ElemType GetElem(LinkList SL, int i, ElemType* e)
{
    if(i < 1 || i > LinkLength)
    {
        printf("查找超出范围！\n");
        return NULL;
    }

    LNode* node = SL->next;
    int j = 1;
    while (j != i) 
    {
        node = node->next;
        j++;
    }

    *e = node->data;
    return *e;
}

// 定位函数(可能有问题？)
int LocateElem(LinkList SL, ElemType e, bool (*compare)(ElemType, ElemType))
{
    LNode* node = SL->next;
    int i = 1;
    while(node != NULL)
    {
        if(compare(node->data,e))
        {
            return i;
        }
        node = node->next;
        i++;
    }
    return NULL;
}

// 遍历顺序表
bool ListTraverse(LinkList SL, bool (*visit)(ElemType))
{
    LNode* node = SL->next;
    while(node != NULL)
    {
        if(!visit(node->data))
        {
            return false;
        }
        node = node->next;
    }
    return true;
}

// 线性表置空
void ClearList(LinkList SL)
{
    LNode* head, * node;
    head = SL->next;
    
    while (head != NULL) 
    {
        node = head;
        head = head->next;
        free(node);
    }

    SL->next = NULL;
    LinkLength = 0;
}

// 改变第i个数据元素的值
void PutElem(LinkList SL, int i, ElemType* e)
{
    if(i < 1 || i > LinkLength)
    {
        printf("未找到第i个元素，无法操作！\n");
        return;
    }

    LNode* node = SL->next;
    int j = 1;
    while (j != i) 
    {
        node = node->next;
        j++;
    }

    node->data = *e;
}

// 插入数据元素
void ListInsert(LinkList SL, int i, ElemType e)
{
    if(i < 1 || i > LinkLength + 1)
    {
        printf("不存在此位置，无法操作！\n");
        return;
    }
    LNode* head, * node;
    node = (LNode*)malloc(sizeof(LNode));

    if(!IsAlloMemSucc(SL))
    {
        return;
    }

    node->data = e;
    head = SL;

    int j = 1;
    while (j != i) 
    {
        head = head->next;
        j++;
    }

    node->next = head->next;
    head->next = node;        
    LinkLength++;

}

// 删除数据元素
ElemType ListDelete(LinkList SL, int i, ElemType* e)
{
    if(i < 1 || i > LinkLength)
    {
        printf("不存在此位置，无法操作！\n");
        return NULL;
    }
    LNode* head, * node;
    head = SL;
    node = head->next;

    int j = 1;
    while (j != i) 
    {
        head = head->next;
        node = node->next;
        j++;
    }

    head->next = node->next;
    *e = node->data;
    free(node);      
    LinkLength--;
    return *e;
}

#endif