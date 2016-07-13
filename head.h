#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
#define MaxSize 100
//结点定义
//1. 设计两个任意长的整数加减法的运算器_马腾
typedef struct node{
	int data[4];
	struct node *next,*prior;
}Lnum;

//2. 线性表的查找_曾轩
#define O 10
typedef struct
 {  int key;
    int other;
}table;
struct idtable
{
	int key;
	int addr;
};
struct idtable id[3];                      

//3. 表达式的计算_海洋                      
#define maxi 100
struct
{
	char ch;
	int pri;
}
lpri[]={{'=',0},{'(',1},{'+',3},{'-',3},{'*',5},{'/',5},{')',6}},
rpri[]={{'=',0},{'(',6},{'+',2},{'-',2},{'*',4},{'/',4},{')',1}};

//4. 有向图十字链表的操作_李伟康 
#define M 5//稀疏矩阵行数
#define N 5//稀疏矩阵列数
#define Max ((M)>(N)? (M):(N))
typedef int ElemType;
//十字链表类型定义
typedef struct mtxn{
	int row;//行号
	int col;//列号
	struct mtxn *right;//向右的指针
	struct mtxn *down;//向下的指针
	union{
		ElemType value;
		struct mtxn *link;
	}tag;
}MatNode;
//全局变量
MatNode *t;
ElemType A[M][N];

//函数声明
/***********************************************附属函数构建***********************************************/
//界面函数
void Menu(){
	printf("☆☆☆☆☆☆☆☆《数据结构》课程设计2014☆☆☆☆☆☆☆☆☆\n");
	printf("*1. 设计两个任意长的整数加减法的运算器_马腾             *\n");
	printf("*2. 线性表的查找_曾轩                                   *\n");
	printf("*3. 表达式的计算_海洋                                   *\n");
	printf("*4. 有向图十字链表的操作_李伟康                         *\n");
	printf("*5. 退出                                                *\n");
	printf("☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
}
//返回主菜单
int Returnmain(){
	char choose;
	printf("\n\n");
	printf("****************************\n");
	printf("是否继续进行？(Y:yes;N:no)\n");
	printf("请输入您的选择：");
	fflush(stdin);
	scanf("%c",&choose);
	if(choose=='y'||choose=='Y')
	{
		system("cls");
		return 1;
	}
	else
	{
		exit(0);
	}
	return 0;
}
//子界面函数
void Menu_1(){
	printf("☆☆☆☆☆两个任意长的整数加减法的运算器☆☆☆☆☆\n");
	printf("*1. 两个数的加法                                 *\n");
	printf("*2. 两个数的加法                                 *\n");
	printf("*3. 两个数的加减法                               *\n");
	printf("*4. 退出                                         *\n");
	printf("☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
}
//返回子菜单
int Returnmain_4(){
	char choose;
	char c;
	printf("\n\n");
	printf("********************************************************************************\n");
	printf("是否继续进行？(Y:yes;N:no)\n");
	printf("请输入您的选择：");
	c=getchar();
	scanf("%c",&choose);
	if(choose=='y'||choose=='Y')
	{
		system("cls");
		return 1;
	}
	else
	{
		exit(0);
	}
	return 0;
}
//子界面函数
void Menu_4(){
	printf("☆☆☆☆☆有向图十字链表的操作☆☆☆☆☆☆\n");
	printf("*1. 从一个二维矩阵创建十字链表表示     *\n");
	printf("*2. 输出十字链表                         *\n");
	printf("*3. 求出指定结点的度（出度和入度）       *\n");
	printf("*4. 插入边（u,v）                        *\n");
	printf("*5. 删除边（u,v）                        *\n");
	printf("*6. 退出                                 *\n");
	printf("☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
}

/***********************************************附属函数构建***********************************************/

/***********************************************主要函数构建***********************************************/
//1. 设计两个任意长的整数加减法的运算器_马腾 
void CreatLum(Lnum *&L,int a[],int n)
{
	 Lnum *s;
	 int i=0,j;
	 L=(Lnum *)malloc(sizeof(Lnum));
	 L->prior=L->next=L;
	 while(i<n)  
	 {
		  s=(Lnum *)malloc(sizeof(Lnum));
		  for(j=3;j>=0;j--)
				s->data[j]=a[i++];
		  s->next=L->next;
		  s->prior=L;		
		  L->next->prior=s; 
		  L->next=s;	  
	 }
}

void print(Lnum *L)
{
	 Lnum *p=L->next;
	 int i=0;
	 while(p->data[i]==0)i++;
	 while(i<4)
	 {
		 cout<<p->data[i];
		 i++;
	 }
	 p=p->next;
	 while(p!=L)
	 {
		  for(i=0;i<4;i++)
		  cout<<p->data[i];
		  p=p->next;
	 }
	 cout<<endl;
}
//加法
void plus(Lnum *L1,Lnum *L2,Lnum *&Lp)
{
	Lnum *p1=L1->prior;
	Lnum *p2=L2->prior;
	Lnum *s;
	int x=0;
	int j;
	Lp=(Lnum *)malloc(sizeof(Lnum));
	Lp->prior=Lp->next=Lp;
	while(p1!=L1&&p2!=L2)
	{
		s=(Lnum *)malloc(sizeof(Lnum));
		for(j=3;j>=0;j--)
		{
			s->data[j]=(p1->data[j]+p2->data[j]+x)%10;
			x=(p1->data[j]+p2->data[j]+x)/10;
		}
		s->next=Lp->next;
		s->prior=Lp;
		Lp->next=s;
		p1=p1->prior;
		p2=p2->prior;
	}
	while(p1!=L1)
	{
		s=(Lnum *)malloc(sizeof(Lnum));
		for(j=3;j>=0;j--)
		{
			s->data[j]=p1->data[j];
		}
		s->next=Lp->next;
		s->prior=Lp;
		Lp->next=s;
		p1=p1->prior;
	}
	while(p2!=L2)
	{
		s=(Lnum *)malloc(sizeof(Lnum));
		for(j=3;j>=0;j++)
		{
			s->data[j]=p2->data[j];
		}
		s->next=Lp->next;
		s->prior=Lp;
		Lp->next=s;
		p2=p2->prior;
	}
}


//减法
void minus(Lnum *L1,Lnum *L2,Lnum *&Lm)
{
	Lnum *p1=L1->prior;
	Lnum *p2=L2->prior;
	Lnum *s;
	int j;
	Lm=(Lnum *)malloc(sizeof(Lnum));
	Lm->prior=Lm->next=Lm;
	while(p1!=L1&&p2!=L2)
	{
		s=(Lnum *)malloc(sizeof(Lnum));
		for(j=3;j>=0;j--)
		{
			if(p1->data[j]>=p2->data[j])
			{
				s->data[j]=p1->data[j]-p2->data[j];
			}
			if(p1->data[j]<p2->data[j])
			{
				s->data[j]=p1->data[j]+10-p2->data[j];
				if(j==0)
				{
					p1->prior->data[3]=p1->prior->data[3]-1;
				}
				p1->data[j-1]=p1->data[j-1]-1;

			}
		}
		s->next=Lm->next;
		s->prior=Lm;
		Lm->next=s;
		p1=p1->prior;
		p2=p2->prior;
	}
	while(p1!=L1)
	{
		s=(Lnum *)malloc(sizeof(Lnum));
		for(j=3;j>=0;j--)
		{
			s->data[j]=p1->data[j];
		}
		s->next=Lm->next;
		s->prior=Lm;
		Lm->next=s;
		p1=p1->prior;
	}
	while(p2!=L2)
	{
		s=(Lnum *)malloc(sizeof(Lnum));
		for(j=3;j>=0;j--)
		{
			s->data[j]=p2->data[j];
		}
		s->next=Lm->next;
		s->prior=Lm;
		Lm->next=s;
		p2=p2->prior;
	}
}
//加法输出
void plusout()
{
	Lnum *L1;
	Lnum *L2;
	Lnum *Lp;
	int a[MaxSize];
	int n=0;
	int n1=0;
	memset(a,0,sizeof(a));
	char aa[MaxSize];
	char bb[MaxSize];
	char string1[MaxSize];
	char string2[MaxSize];
	char *p;
	cout<<"请输入该整数:";
	cin>>string1;
	p=string1;
	while(*p)
	{
		n++;
		p++;
	}
	p=string1;
	for(int i=n-1;i>=0;i--)
	{
		aa[i]=*p;
		a[i]=aa[i]-48;
		p++;
	}
	CreatLum(L1,a,n);
	print(L1);
	memset(a,0,sizeof(a));//将a[]清零
	n1=0;
	cout<<"请输入该整数:";
	cin>>string2;
	p=string2;
	while(*p)
	{
		 n1++;
		 p++;
	}
	p=string2;
	for(i=n1-1;i>=0;i--)
	{
		bb[i]=*p;
		a[i]=bb[i]-48;
		p++;
	}
	CreatLum(L2,a,n1);
	print(L2);
	plus(L1,L2,Lp);
	cout<<string1<<"+"<<string2<<"=";
	print(Lp);
}
//减法输出
void minusout()
{
	Lnum *L1;
	Lnum *L2;
	Lnum *Lm;
	int a[MaxSize];
	int n;
	int n1;
	n=0;
	n1=0;
	memset(a,0,sizeof(a));
	char aa[MaxSize];
	char bb[MaxSize];
	char string1[MaxSize];
	char string2[MaxSize];
	char *p;
	cout<<"请输入整数：";
	cin>>string1;
	p=string1;
	while(*p)
	{
		n++;
		p++;
	}
	p=string1;
	for(int i=n-1;i>=0;i--)
	{
		aa[i]=*p;
		a[i]=aa[i]-48;
		p++;
	}
	CreatLum(L1,a,n);
	print(L1);
	memset(a,0,sizeof(a));
	n1=0;
	cout<<"请输入另一整数：";
	cin>>string2;
	p=string2;
	while(*p)
	{
		n1++;
		p++;
	}
	p=string2;
	for(i=n1-1;i>=0;i--)
	{
		bb[i]=*p;
		a[i]=bb[i]-48;
		p++;
	}
	CreatLum(L2,a,n1);
	print(L2);
	cout<<string1<<"-"<<string2<<"=";
	if(n==n1&&strcmp(string1,string2)==0)
	{
		cout<<"0"<<endl;
	}
	else if(n==n1&&strcmp(string1,string2)>0||n>n1)
	{
		minus(L1,L2,Lm);
		print(Lm);
	}
	else
	{
		minus(L2,L1,Lm);
		cout<<"-";
		print(Lm);
	}
}
//加减法输出
void allout()
{
	Lnum *L1,*L2,*Lp,*Lm;
	 int a[MaxSize],n=0,n1=0;
	 memset(a,0,sizeof(a));
	 char aa[MaxSize],bb[MaxSize],string1[MaxSize],string2[MaxSize];
	 char *p;
	 cout<<"请输入该整数:";
	 cin>>string1;
	 p=string1;
	 while(*p)
		{
			n++;
			p++;
		}
	 p=string1;
	 for(int i=n-1;i>=0;i--)
		{
			aa[i]=*p;
			a[i]=aa[i]-48;
			p++;
		}
	 CreatLum(L1,a,n);
	 print(L1);
	 memset(a,0,sizeof(a));
	 n1=0;
	 cout<<"请输入该整数:";
	 cin>>string2;
	 p=string2;
	 while(*p)
		{
			 n1++;
			 p++;
		}
	 p=string2;
	 for(i=n1-1;i>=0;i--)
		 {
			  bb[i]=*p;
			  a[i]=bb[i]-48;
			  p++;
		 }
	 CreatLum(L2,a,n1);
	 print(L2);
	 plus(L1,L2,Lp);
	 cout<<string1<<"+"<<string2<<"=";
	 print(Lp);
	 cout<<string1<<"-"<<string2<<"=";
	 if(strcmp(string1,string2)==0)
	 {
	  cout<<"0"<<endl;
	 }
	 else if(n==n1 && strcmp(string1,string2)>0 || n>n1)
	 {
	  minus(L1,L2,Lm);
	  print(Lm);
	 }
	 else	
	 {
	  minus(L2,L1,Lm);
	  cout<<"-";
	  print(Lm);
	 }

}

void plus_minus_clarify_mt(){
printf("☆☆☆设计两个任意长的整数加减法的运算器_马腾☆☆☆\n");
printf("基本功能要求：\n");
printf("*******************************************************\n");
printf("*（1）输入两个长整数。                                *\n");
printf("*（2）利用双向循环链表存储长整数，每个结点存储四位数。*\n");
printf("*（3）计算结果存储于双向循环链表。                    *\n");
printf("*（4）输出运算式子及结果。                            *\n");
printf("*******************************************************\n\n");
}

int main_1()
{
	plus_minus_clarify_mt();
	int c=1;
	while(c<4 && c>0)
	{
		Menu_1();
		printf("请输入您的选择:\n");
		cin>>c;
		switch(c)
		{
		case 1:	system("cls");
				plusout();
				break;

		case 2:	system("cls");
				minusout();
				break;

		case 3:	system("cls");
				allout();
				break;

		case 4:	break;
		}
	}
	 return 0;
}

//2. 线性表的查找_曾轩    
void search_clarify_mt(){
printf("☆☆☆线性表的查找_曾轩☆☆☆\n");
printf("基本功能要求：自动生成一组随机数并输出，分别按下面要求建立查找表并实现查找，并计算平均查找长度。\n");
printf("*******************************************************\n");
printf("*（1）顺序查找                                        *\n");
printf("*（2）二分查找（递归实现）                            *\n");
printf("*（3）分块查找                                        *\n");
printf("*******************************************************\n\n");
} 

int seqsearch(table R[], int k)
{
	int i=0;
	while(i<12&&R[i].key!=k) i++;
	if(i>=12)
		return -1;
	else
		return i;
}

int binsearch(table R[ ],int k)
{	
	int low,mid,high;
	low=0;high=11;
	while( low<=high )
    {  
		mid=(low+high)/2;
        if(R[mid].key==k)
			return(mid);
        if(R[mid].key>k)
			high=mid-1 ;     
		else
			low=mid+1;    
     }
	return(-1);
}

int search(table R[],struct idtable id[],int k)
{
	int i,low1,low2,high1,high2,mid;
	low1=0;high1=4-1; 
	while(low1<=high1)
	{
		mid=(low1+high1)/2;
		if(k<=id[mid].key)
			high1=mid-1;
		else
			low1=mid+1;
	}
	if(low1<4)
	{
		low2=id[low1].addr;
		if(low1==4-1)
			high2=O+1;
		else
			high2=id[low1].addr-1;
		for(i=low2;i<=high2;i++)
			if(R[i].key==k)
				return(i);
	}
	else
		return(0);
	return(0);
}

void SelectSort(table R[])   
{ 
	int i,j,index;
	table tmp;
    for (i=0; i<11; i++)              
	{  
		index=i;   
		for (j=i+1; j<12; j++)            
           if (R[j].key<R[index].key)   
			   index=j;
		if (index!=i) 
		{
			tmp=R[i];
		R[i]=R[index];
		R[index]=tmp;
		}
	}   
}

void main_2()
{
	int i;
	int j;
	int k;
	int max;
	search_clarify_mt();
	table R[100];
	printf("输入12个数\n");
	for(i=0;i<=11;i++)
	{
		scanf("%d",&R[i].key);
	}
	for(i=0;i<=11;i++)
	{
		printf("%d ",R[i].key);
	}
	for(j=0;j<=3;j++)
	{
		max=R[3*j].key;	
		for(i=j*3;i<=2+j*3;i++)
		{
			if(R[i].key>max)
				max=R[i].key;
		}
		id[j].key=max;
	}
	for(j=0;j<=3;j++)
	{
		id[j].addr=j*3;
	}
	printf("\n ");
	for(i=0;i<=3;i++)
	{
		printf("%d ",id[i].addr);
	}
		
	printf("\n ");
	for(i=0;i<=3;i++)
	{
		printf("%d ",id[i].key);
	}

	printf("\n ");
	printf("\n ");
	
	printf("输入要查找的关键字");
	scanf("%d",&k);
	printf("顺序查找");	
	printf("\n ");

	printf("要求关键字地址是%d",seqsearch(R, k));
	printf("\n ");

	printf("平均成功查找长度是%d，平均失败查找长度是%d",(O+2)/2,O+2);
	printf("\n ");
	printf("\n ");

	printf("分块查找");
	printf("\n ");

	printf("要求关键字地址是%d", search(R,id,k));
	printf("\n ");

	printf("平均成功查找长度是9");
	
	 
	printf("\n ");

	SelectSort(R);
	
	for(i=0;i<=11;i++)
	{
		printf("%d ",R[i].key);
	}

		printf("二分查找");
			printf("\n ");


	printf("要求关键字地址是%d", binsearch(R,k));
	printf("\n ");

	printf("平均成功查找长度是3.08，平均失败查找长度是4.77");
	printf("\n ");
}
                   
//3. 表达式的计算_海洋
void hy_clarify_mt(){
printf("☆☆☆表达式的计算_海洋☆☆☆\n");
printf("基本功能要求：\n");
printf("****************************************************************\n");
printf("*（1）以字符串形式输入后缀表达式（包含有“+、-、×、/”运算）。*\n");
printf("*（2）计算结果并输出。                                         *\n");
printf("****************************************************************\n\n");
}
int Inop(char a)
{
	if(a=='(' || a=='+' || a=='-' || a=='*' || a=='/' || a==')')
		return 1;
	else return 0;
}

int leftpri(char op)
{
	int i;
	for(i=0;i<7;i++)
	{
		if(lpri[i].ch==op)
			return lpri[i].pri;
	}
	return 0;
}

int rightpri(char op)
{
	int i;
	for(i=0;i<7;i++)
	{
		if(rpri[i].ch==op)
			return rpri[i].pri;
	}
	return 0;
}

int precede(char a,char b)
{
	if(leftpri(a)==rightpri(b))
		return 0;
	else
	{
		if(leftpri(a)>rightpri(b))
			return 1;
		else return -1;
	}
}

void trans(char *a,char b[])
{
	struct operate
	{
		char ch[maxi];
		int top;
	}op;
	int i;
	i=0;

	op.top=-1;
	op.top++;
	op.ch[op.top]='=';
	while(*a!='\0')
	{
		if(Inop(*a))
		{
			switch(precede(op.ch[op.top],*a))
			{
				case -1:
				{
					op.top++;
					op.ch[op.top]=*a;
					a++;
					break;
				}
				case 0:
				{
					op.top--;
					a++;
					break;
				}
				case 1:
				{
					b[i]=op.ch[op.top];
					i++;
					op.top--;
					break;
				}
			}
		}
		else
		{
			while(*a<='9' && *a>='0')
			{
				b[i]=*a;
				i++;
				a++;
			}
			b[i]='#';
			i++;
			
		}
	}
	while(op.ch[op.top]!='=')
	{
		b[i]=op.ch[op.top];
		i++;
		op.top--;
	}
	b[i]='\0';
}

float operate(char *code)
{
	struct num
	{
		float data[maxi];
		int top;
	}st;

	float a;
	float b;
	float c;								//记录运算结果
	float d;								//记录字符转成的数字

	st.top=-1;

	
	while(*code!='\0')
	{
		switch(*code)
		{
			case '+':
			{
				a=st.data[st.top];
				st.top--;
				b=st.data[st.top];
				st.top--;
				c=a+b;
				st.top++;
				st.data[st.top]=c;
				break;
			}
			case '-':
			{
				a=st.data[st.top];
				st.top--;
				b=st.data[st.top];
				st.top--;
				c=b-a;
				st.top++;
				st.data[st.top]=c;
				break;
			}
			case '*':
			{
				a=st.data[st.top];
				st.top--;
				b=st.data[st.top];
				st.top--;
				c=a*b;
				st.top++;
				st.data[st.top]=c;
				break;
			}
			case '/':
			{
				a=st.data[st.top];
				st.top--;
				b=st.data[st.top];
				st.top--;
				if(a==0)
				{
					printf("表达式有错误!\n");
					exit(0);
				}
				else 
				{
					c=b/a;
					st.top++;
					st.data[st.top]=c;
				}
				break;
			}
			default:
			{
				d=0;
				while(*code>='0' && *code<='9')
				{
					d=10*d+*code-'0';
					code++;
				}
				st.top++;
				st.data[st.top]=d;
				
				break;
			}
		}
		code++;
	}
	return(st.data[st.top]);
}

void main_3(){
	hy_clarify_mt();
	char exp[maxi]="(56-20)/(4+2)";
	char postexp[maxi];
	int i;
	char ch;
	char cha;//用于吸收多余字符
	i=0;
	cha=getchar();//吸收多余字符
	printf("请输入中缀表达式\n");
	ch=getchar();
	while(ch!='\n')
	{
		exp[i]=ch;
		i++;
		ch=getchar();
	}
	exp[i]='\0';

	trans(exp,postexp);
	printf("中缀表达式：%s\n",exp);
	printf("后缀表达式：%s\n",postexp);
	printf("表达式的值：%.2f\n",operate(postexp));
}

//4. 有向图十字链表的操作_李伟康
void tenlinks_clarify_mt(){
printf("☆☆☆有向图十字链表的操作_李伟康☆☆☆\n");
printf("基本功能要求：\n");
printf("*******************************************************\n");
printf("*（1）有向图以十字链表方式存储。                      *\n");
printf("*（2）求出指定结点的度（出度和入度），插入边（u,v）， *\n");
printf("*     删除边(u,v)。                                   *\n");
printf("*******************************************************\n\n");
}                         
//1. 从一个二维矩阵创建其十字链表表示
void CreatMat(MatNode *&mh,ElemType a[M][N]){
	int i,j;
	MatNode *h[Max];
	MatNode *p;//内容指针
	MatNode *q;//循环指针
	MatNode *r;//头指针
	mh=(MatNode *)malloc(sizeof(MatNode));//创建十字链表的头结点
	mh->row=M;
	mh->col=N;
	r=mh;//r指向尾结点
	//采用尾插法创建行列表头结点h1,h2,...的循环链表
	for(i=0;i<Max;i++){
		h[i]=(MatNode *)malloc(sizeof(MatNode));
		h[i]->down=h[i]->right=h[i];
		h[i]->row=h[i]->col=-1;
		r->tag.link=h[i];
		r=h[i];
	}
	r->tag.link=mh;


	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			if(a[i][j]!=0){
				//构造待插入的结点
				p=(MatNode *)malloc(sizeof(MatNode));
				p->row=i;
				p->col=j;
				p->tag.value=a[i][j];
			//插入结点
				//横向插入结点
				q=h[i];
				while(q->right!=h[i]&&q->right->col<j){
					q=q->right;
				}
				p->right=q->right;
				q->right=p;
				
				//纵向插入结点
				q=h[j];
				while(q->down!=h[j]&&q->down->row<i){
					q=q->down;
				}
				p->down=q->down;
				q->down=p;				
			}
		}
	}
}
//2. 输出十字链表
void DispMat(MatNode *mh){
	MatNode *p;
	MatNode *q;
	printf("行=%d 列=%d\n",mh->row,mh->col);
	p=mh->tag.link;
	while(p!=mh){
		q=p->right;
		while(p!=q){
			printf("%d\t%d\t%d\n",q->row,q->col,q->tag.value);
			q=q->right;
		}
		p=p->tag.link;
	}
}
//3. 求出指定结点的度（出度和入度）
void lengthofnode(MatNode *mh){
	MatNode *p;
	MatNode *q;
	int location=0;
	int length_c=0;
	int length_r=0;
	printf("行=%d 列=%d\n",mh->row,mh->col);
	printf("请输入您想查看的节点(0-%d):\n",Max-1);
	scanf("%d",&location);
	p=mh->tag.link;
	while(p!=mh){
		q=p->right;
		while(p!=q){
			//出度
			if(q->row==location&&q->col!=location){
				length_c++;
			}
			//入度
			if(q->col==location&&q->row!=location){
				length_r++;
			}
			q=q->right;
		}
		p=p->tag.link;
	}
	printf("该节点的出度为:%d\n",length_c);
	printf("该节点的出度为:%d\n",length_r);
}
//4. 插入边（u,v）                 
void PlantLine(MatNode *mh){

	int location_c=0;//终点
	int location_r=0;//起点
	int heavy=0;//权值

	printf("行=%d 列=%d\n",mh->row,mh->col);
	printf("请输入您想插入的边(0-%d):\n",Max-1);
	printf("边起点:");
	scanf("%d",&location_r);
	printf("边终点:");
	scanf("%d",&location_c);
	printf("边权重:");
	scanf("%d",&heavy);
	
	if(A[location_r][location_c]==0){
		A[location_r][location_c]=heavy;
		CreatMat(t,A);
		printf("\n恭喜，您的插入已成功！新图输出如下：\n");
		DispMat(t);
	}
	else{
		printf("对不起，该边已存在，您插入的位置不正确!\n");
		exit(0);
	}
	
}
//5. 删除边（u,v）                 
void DeleteLine(MatNode *mh){
	MatNode *p;//循环指针->定位
	MatNode *q;//循环指针->定位
	MatNode *s;//循环指针->定位
	int location_c=0;//终点
	int location_r=0;//起点

	printf("行=%d 列=%d\n",mh->row,mh->col);
	printf("请输入您想删除的边(0-%d):\n",Max-1);
	printf("边起点:");
	scanf("%d",&location_r);
	printf("边终点:");
	scanf("%d",&location_c);
	//待删除位置的前一位置
	p=mh->tag.link;
	while(p!=mh){
		q=p;
		while(p!=q->right){
			if(q->right->row==location_r&&q->right->col==location_c){
				goto flag_2;
			}
			q=q->right;
		}
		p=p->tag.link;
	}
flag_2:
	//查找成功
	if(q->right->row==location_r&&q->right->col==location_c){
		s=q->right;
		//横向删除结点
		q->right=s->right;
		//纵向删除结点
		q->down=s->down;		
		free(s);
		printf("\n恭喜，您的删除已完成！新图输出如下：\n");
		DispMat(t);
	}
	else{
		printf("您删除的位置不正确！\n");
	}
}
void main_4(){
	int i,j=0;//循环变量
	int val;
	tenlinks_clarify_mt();
	Menu_4();
	int choose=0;
	printf("请输入您的选择：");
	scanf("%d",&choose);
	switch(choose)
	{
		case 1:	system("cls");
				printf("请输入一个%d*%d二维数组来表示您的有向图:\n",M,N);
				for(i=0;i<M;i++){
					for(j=0;j<N;j++){
						scanf("%d",&val);
						A[i][j]=val;
					}
				}
				CreatMat(t,A);
				Returnmain_4();
				main_4();
				break;
		
		case 2:	system("cls");
				DispMat(t);
				Returnmain_4();
				main_4();
				break;

		case 3:	system("cls");
				lengthofnode(t);
				Returnmain_4();
				main_4();
				break;

		case 4:	system("cls");
				PlantLine(t);
				Returnmain_4();
				main_4();
				break;
		
		case 5:	system("cls");
				DeleteLine(t);
				Returnmain_4();
				main_4();
				break;

		case 6:	system("cls");
				break;

		default:system("CLS");
				printf("警告：\a\a\a\a\a\a\a\a\n");
				printf("您的输入有误，请重新输入!\n");
				Sleep(3000);
				system("CLS");
				main_4();
	}
}
/***********************************************主要函数构建***********************************************/