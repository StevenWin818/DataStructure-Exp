#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
enum BOOL{False,True};
typedef struct  BiTNode           //����������ڵ�ṹ
{char  data;                     //������
 struct BiTNode *lchild,*rchild; //���Һ���ָ����
}BiTNode,*BiTree;

void CreateBiTree(BiTree &);    //����һ��������
void PreOrder(BiTree);         //����ݹ����������
void InOrder(BiTree);         //����ݹ����������
void PostOrder(BiTree);      //����ݹ����������

int main()
{BiTree T;
 char ch,j;
 int flag=1;
 BOOL temp;
 //---------------------�����˵-----------------------
 printf("ʵ��2-������\n");
 printf("�������������ݹ��������򡢺�������Ȳ�����\n");
 //----------------------------------------------------
 printf("�뽫��������������Ľ�������Խ�����������\n");
 printf("����Ҷ�ӽ���Կո��ʾ��\n");
 //printf("����:abc  de g  f   (�س�)���������¶�������\n");
 printf("           a      \n");
 printf("          /       \n");
 printf("         b        \n");
 printf("        / \\       \n");
 printf("       c   d      \n");
 printf("          / \\     \n");
 printf("         e   f    \n");
 printf("          \\       \n");
 printf("           g      \n");
 CreateBiTree(T);       //��ʼ������
 getchar();
 while(flag)
    { printf("��ѡ��: \n");
      printf("1.�ݹ��������\n");
      printf("2.�ݹ��������\n");
      printf("3.�ݹ�������\n");
      printf("4.�˳�����\n");
      scanf(" %c",&j);
      switch(j)
	{case '1':if(T)
		     {printf("�������������:");
		      PreOrder(T);
		      printf("\n");
		     }
		  else printf("������Ϊ��!\n");
		  break;
	 case '2':if(T)
		    {printf("�������������:");
		     InOrder(T);
		     printf("\n");
		    }
		  else printf("������Ϊ��!\n");
		  break;
	 case '3':if(T)
		    {printf("�������������:");
		     PostOrder(T);
		     printf("\n");
		    }
		  else printf("������Ϊ��!\n");
		  break;
	 default:flag=0;printf("�������н�������������˳�!\n");
	}
    }
getch();
}

void CreateBiTree(BiTree &T)   //������ɡ�������������ģ�����
{
	char ch;
	scanf("%c",&ch);
	if(ch == ' ')    T = NULL;
	else
	{
		T = (BiTNode *)malloc(sizeof(BiTNode));
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}
void PreOrder(BiTree T) // ������ɡ����������ģ�����
{
	if (T)
	{
		printf("%c ", T->data); 
		PreOrder(T->lchild);	
		PreOrder(T->rchild);
	}
}

void InOrder(BiTree T)  //������ɡ����������ģ�����
{if(T)
  {
	  InOrder(T->lchild);	  
	  printf("%c ", T->data); 
	  InOrder(T->rchild);	 
  }
}
void PostOrder(BiTree T)  //������ɡ����������ģ�����
{
 if(T)
  {
	  PostOrder(T->lchild);	  
	  PostOrder(T->rchild);	  
	  printf("%c ", T->data); 
  }
}
