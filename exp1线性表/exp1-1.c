#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#define ElemType int 
typedef struct LNode{ 
   
	ElemType Data;
	struct LNode *Next;
}LNode,*LinkList;

//头插法
LinkList CreateList_Head(LinkList L)
{ 
   
	LinkList s;int x;
	L = (LNode*)malloc(sizeof(LNode));    
	L->Next=NULL;                          
	scanf("%d",&x);                       
	while(x!=0)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->Data = x;
		s->Next = L->Next;
		L->Next = s;
		scanf("%d", &x);
	}//将语句补充完整
	return L;
}
//尾插法 
LinkList CreateList_Tail(LinkList L)
{ 
   
	int x;
	L = (LNode*)malloc(sizeof(LNode));
	LNode *s,*r=L;
	scanf("%d",&x);
	while(x!=0)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->Data = x;
		r->Next = s;
		r = s;
		scanf("%d", &x);
	}//将语句补充完整
	r->Next=NULL;
	return L;
 } 


void PrintList(LinkList L)
{ 
   
    LinkList p;
    p=L->Next; 
    printf("链表元素如下：\n");
    while(p!=NULL)
    { 
   
        printf("%d ",p->Data);
        p=p->Next;
    }
    printf("\n");
}
int main()
{ 
   
	LinkList L;//结构变量L即表示整个链表，也是头指针指向头结点
	printf("尾插法建立单链表，输入值（以数字0结束输入）\n"); 
	L=CreateList_Tail(L);
    PrintList(L);
    printf("头插法建立单链表，输入值（以数字0结束输入）\n");
    L=CreateList_Head(L);
    PrintList(L);
	return 0;
}
