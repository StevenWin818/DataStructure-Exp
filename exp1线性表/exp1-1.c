#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#define ElemType int 
typedef struct LNode{ 
   
	ElemType Data;
	struct LNode *Next;
}LNode,*LinkList;

//ͷ�巨
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
	}//����䲹������
	return L;
}
//β�巨 
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
	}//����䲹������
	r->Next=NULL;
	return L;
 } 


void PrintList(LinkList L)
{ 
   
    LinkList p;
    p=L->Next; 
    printf("����Ԫ�����£�\n");
    while(p!=NULL)
    { 
   
        printf("%d ",p->Data);
        p=p->Next;
    }
    printf("\n");
}
int main()
{ 
   
	LinkList L;//�ṹ����L����ʾ��������Ҳ��ͷָ��ָ��ͷ���
	printf("β�巨��������������ֵ��������0�������룩\n"); 
	L=CreateList_Tail(L);
    PrintList(L);
    printf("ͷ�巨��������������ֵ��������0�������룩\n");
    L=CreateList_Head(L);
    PrintList(L);
	return 0;
}
