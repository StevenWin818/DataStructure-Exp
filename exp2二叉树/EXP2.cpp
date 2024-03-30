#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
enum BOOL{False,True};
typedef struct  BiTNode           //定义二叉树节点结构
{char  data;                     //数据域
 struct BiTNode *lchild,*rchild; //左右孩子指针域
}BiTNode,*BiTree;

void CreateBiTree(BiTree &);    //生成一个二叉树
void PreOrder(BiTree);         //先序递归遍历二叉树
void InOrder(BiTree);         //中序递归遍历二叉树
void PostOrder(BiTree);      //后序递归遍历二叉树

int main()
{BiTree T;
 char ch,j;
 int flag=1;
 BOOL temp;
 //---------------------程序解说-----------------------
 printf("实验2-二叉树\n");
 printf("建立二叉树，递归先序、中序、后序遍历等操作。\n");
 //----------------------------------------------------
 printf("请将先序遍历二叉树的结果输入以建立二叉树。\n");
 printf("对于叶子结点以空格表示。\n");
 //printf("例如:abc  de g  f   (回车)，建立如下二叉树：\n");
 printf("           a      \n");
 printf("          /       \n");
 printf("         b        \n");
 printf("        / \\       \n");
 printf("       c   d      \n");
 printf("          / \\     \n");
 printf("         e   f    \n");
 printf("          \\       \n");
 printf("           g      \n");
 CreateBiTree(T);       //初始化队列
 getchar();
 while(flag)
    { printf("请选择: \n");
      printf("1.递归先序遍历\n");
      printf("2.递归中序遍历\n");
      printf("3.递归后序遍历\n");
      printf("4.退出程序\n");
      scanf(" %c",&j);
      switch(j)
	{case '1':if(T)
		     {printf("先序遍历二叉树:");
		      PreOrder(T);
		      printf("\n");
		     }
		  else printf("二叉树为空!\n");
		  break;
	 case '2':if(T)
		    {printf("中序遍历二叉树:");
		     InOrder(T);
		     printf("\n");
		    }
		  else printf("二叉树为空!\n");
		  break;
	 case '3':if(T)
		    {printf("后序遍历二叉树:");
		     PostOrder(T);
		     printf("\n");
		    }
		  else printf("二叉树为空!\n");
		  break;
	 default:flag=0;printf("程序运行结束，按任意键退出!\n");
	}
    }
getch();
}

void CreateBiTree(BiTree &T)   //独立完成“创建二叉树”模块代码
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
void PreOrder(BiTree T) // 独立完成“先序遍历”模块代码
{
	if (T)
	{
		printf("%c ", T->data); 
		PreOrder(T->lchild);	
		PreOrder(T->rchild);
	}
}

void InOrder(BiTree T)  //独立完成“中序遍历”模块代码
{if(T)
  {
	  InOrder(T->lchild);	  
	  printf("%c ", T->data); 
	  InOrder(T->rchild);	 
  }
}
void PostOrder(BiTree T)  //独立完成“后序遍历”模块代码
{
 if(T)
  {
	  PostOrder(T->lchild);	  
	  PostOrder(T->rchild);	  
	  printf("%c ", T->data); 
  }
}
