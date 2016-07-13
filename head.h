#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
#define MaxSize 100
//��㶨��
//1. ����������ⳤ�������Ӽ�����������_����
typedef struct node{
	int data[4];
	struct node *next,*prior;
}Lnum;

//2. ���Ա�Ĳ���_����
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

//3. ���ʽ�ļ���_����                      
#define maxi 100
struct
{
	char ch;
	int pri;
}
lpri[]={{'=',0},{'(',1},{'+',3},{'-',3},{'*',5},{'/',5},{')',6}},
rpri[]={{'=',0},{'(',6},{'+',2},{'-',2},{'*',4},{'/',4},{')',1}};

//4. ����ͼʮ������Ĳ���_��ΰ�� 
#define M 5//ϡ���������
#define N 5//ϡ���������
#define Max ((M)>(N)? (M):(N))
typedef int ElemType;
//ʮ���������Ͷ���
typedef struct mtxn{
	int row;//�к�
	int col;//�к�
	struct mtxn *right;//���ҵ�ָ��
	struct mtxn *down;//���µ�ָ��
	union{
		ElemType value;
		struct mtxn *link;
	}tag;
}MatNode;
//ȫ�ֱ���
MatNode *t;
ElemType A[M][N];

//��������
/***********************************************������������***********************************************/
//���溯��
void Menu(){
	printf("�����������ݽṹ���γ����2014����������\n");
	printf("*1. ����������ⳤ�������Ӽ�����������_����             *\n");
	printf("*2. ���Ա�Ĳ���_����                                   *\n");
	printf("*3. ���ʽ�ļ���_����                                   *\n");
	printf("*4. ����ͼʮ������Ĳ���_��ΰ��                         *\n");
	printf("*5. �˳�                                                *\n");
	printf("������������������������������\n");
}
//�������˵�
int Returnmain(){
	char choose;
	printf("\n\n");
	printf("****************************\n");
	printf("�Ƿ�������У�(Y:yes;N:no)\n");
	printf("����������ѡ��");
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
//�ӽ��溯��
void Menu_1(){
	printf("�������������ⳤ�������Ӽ�����������������\n");
	printf("*1. �������ļӷ�                                 *\n");
	printf("*2. �������ļӷ�                                 *\n");
	printf("*3. �������ļӼ���                               *\n");
	printf("*4. �˳�                                         *\n");
	printf("��������������������������\n");
}
//�����Ӳ˵�
int Returnmain_4(){
	char choose;
	char c;
	printf("\n\n");
	printf("********************************************************************************\n");
	printf("�Ƿ�������У�(Y:yes;N:no)\n");
	printf("����������ѡ��");
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
//�ӽ��溯��
void Menu_4(){
	printf("����������ͼʮ������Ĳ����������\n");
	printf("*1. ��һ����ά���󴴽�ʮ�������ʾ     *\n");
	printf("*2. ���ʮ������                         *\n");
	printf("*3. ���ָ�����Ķȣ����Ⱥ���ȣ�       *\n");
	printf("*4. ����ߣ�u,v��                        *\n");
	printf("*5. ɾ���ߣ�u,v��                        *\n");
	printf("*6. �˳�                                 *\n");
	printf("����������������������\n");
}

/***********************************************������������***********************************************/

/***********************************************��Ҫ��������***********************************************/
//1. ����������ⳤ�������Ӽ�����������_���� 
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
//�ӷ�
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


//����
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
//�ӷ����
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
	cout<<"�����������:";
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
	memset(a,0,sizeof(a));//��a[]����
	n1=0;
	cout<<"�����������:";
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
//�������
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
	cout<<"������������";
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
	cout<<"��������һ������";
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
//�Ӽ������
void allout()
{
	Lnum *L1,*L2,*Lp,*Lm;
	 int a[MaxSize],n=0,n1=0;
	 memset(a,0,sizeof(a));
	 char aa[MaxSize],bb[MaxSize],string1[MaxSize],string2[MaxSize];
	 char *p;
	 cout<<"�����������:";
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
	 cout<<"�����������:";
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
printf("��������������ⳤ�������Ӽ�����������_���ڡ���\n");
printf("��������Ҫ��\n");
printf("*******************************************************\n");
printf("*��1������������������                                *\n");
printf("*��2������˫��ѭ������洢��������ÿ�����洢��λ����*\n");
printf("*��3���������洢��˫��ѭ������                    *\n");
printf("*��4���������ʽ�Ӽ������                            *\n");
printf("*******************************************************\n\n");
}

int main_1()
{
	plus_minus_clarify_mt();
	int c=1;
	while(c<4 && c>0)
	{
		Menu_1();
		printf("����������ѡ��:\n");
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

//2. ���Ա�Ĳ���_����    
void search_clarify_mt(){
printf("�������Ա�Ĳ���_��������\n");
printf("��������Ҫ���Զ�����һ���������������ֱ�����Ҫ�������ұ�ʵ�ֲ��ң�������ƽ�����ҳ��ȡ�\n");
printf("*******************************************************\n");
printf("*��1��˳�����                                        *\n");
printf("*��2�����ֲ��ң��ݹ�ʵ�֣�                            *\n");
printf("*��3���ֿ����                                        *\n");
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
	printf("����12����\n");
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
	
	printf("����Ҫ���ҵĹؼ���");
	scanf("%d",&k);
	printf("˳�����");	
	printf("\n ");

	printf("Ҫ��ؼ��ֵ�ַ��%d",seqsearch(R, k));
	printf("\n ");

	printf("ƽ���ɹ����ҳ�����%d��ƽ��ʧ�ܲ��ҳ�����%d",(O+2)/2,O+2);
	printf("\n ");
	printf("\n ");

	printf("�ֿ����");
	printf("\n ");

	printf("Ҫ��ؼ��ֵ�ַ��%d", search(R,id,k));
	printf("\n ");

	printf("ƽ���ɹ����ҳ�����9");
	
	 
	printf("\n ");

	SelectSort(R);
	
	for(i=0;i<=11;i++)
	{
		printf("%d ",R[i].key);
	}

		printf("���ֲ���");
			printf("\n ");


	printf("Ҫ��ؼ��ֵ�ַ��%d", binsearch(R,k));
	printf("\n ");

	printf("ƽ���ɹ����ҳ�����3.08��ƽ��ʧ�ܲ��ҳ�����4.77");
	printf("\n ");
}
                   
//3. ���ʽ�ļ���_����
void hy_clarify_mt(){
printf("������ʽ�ļ���_�������\n");
printf("��������Ҫ��\n");
printf("****************************************************************\n");
printf("*��1�����ַ�����ʽ�����׺���ʽ�������С�+��-������/�����㣩��*\n");
printf("*��2���������������                                         *\n");
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
	float c;								//��¼������
	float d;								//��¼�ַ�ת�ɵ�����

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
					printf("���ʽ�д���!\n");
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
	char cha;//�������ն����ַ�
	i=0;
	cha=getchar();//���ն����ַ�
	printf("��������׺���ʽ\n");
	ch=getchar();
	while(ch!='\n')
	{
		exp[i]=ch;
		i++;
		ch=getchar();
	}
	exp[i]='\0';

	trans(exp,postexp);
	printf("��׺���ʽ��%s\n",exp);
	printf("��׺���ʽ��%s\n",postexp);
	printf("���ʽ��ֵ��%.2f\n",operate(postexp));
}

//4. ����ͼʮ������Ĳ���_��ΰ��
void tenlinks_clarify_mt(){
printf("��������ͼʮ������Ĳ���_��ΰ������\n");
printf("��������Ҫ��\n");
printf("*******************************************************\n");
printf("*��1������ͼ��ʮ������ʽ�洢��                      *\n");
printf("*��2�����ָ�����Ķȣ����Ⱥ���ȣ�������ߣ�u,v���� *\n");
printf("*     ɾ����(u,v)��                                   *\n");
printf("*******************************************************\n\n");
}                         
//1. ��һ����ά���󴴽���ʮ�������ʾ
void CreatMat(MatNode *&mh,ElemType a[M][N]){
	int i,j;
	MatNode *h[Max];
	MatNode *p;//����ָ��
	MatNode *q;//ѭ��ָ��
	MatNode *r;//ͷָ��
	mh=(MatNode *)malloc(sizeof(MatNode));//����ʮ�������ͷ���
	mh->row=M;
	mh->col=N;
	r=mh;//rָ��β���
	//����β�巨�������б�ͷ���h1,h2,...��ѭ������
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
				//���������Ľ��
				p=(MatNode *)malloc(sizeof(MatNode));
				p->row=i;
				p->col=j;
				p->tag.value=a[i][j];
			//������
				//���������
				q=h[i];
				while(q->right!=h[i]&&q->right->col<j){
					q=q->right;
				}
				p->right=q->right;
				q->right=p;
				
				//���������
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
//2. ���ʮ������
void DispMat(MatNode *mh){
	MatNode *p;
	MatNode *q;
	printf("��=%d ��=%d\n",mh->row,mh->col);
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
//3. ���ָ�����Ķȣ����Ⱥ���ȣ�
void lengthofnode(MatNode *mh){
	MatNode *p;
	MatNode *q;
	int location=0;
	int length_c=0;
	int length_r=0;
	printf("��=%d ��=%d\n",mh->row,mh->col);
	printf("����������鿴�Ľڵ�(0-%d):\n",Max-1);
	scanf("%d",&location);
	p=mh->tag.link;
	while(p!=mh){
		q=p->right;
		while(p!=q){
			//����
			if(q->row==location&&q->col!=location){
				length_c++;
			}
			//���
			if(q->col==location&&q->row!=location){
				length_r++;
			}
			q=q->right;
		}
		p=p->tag.link;
	}
	printf("�ýڵ�ĳ���Ϊ:%d\n",length_c);
	printf("�ýڵ�ĳ���Ϊ:%d\n",length_r);
}
//4. ����ߣ�u,v��                 
void PlantLine(MatNode *mh){

	int location_c=0;//�յ�
	int location_r=0;//���
	int heavy=0;//Ȩֵ

	printf("��=%d ��=%d\n",mh->row,mh->col);
	printf("�������������ı�(0-%d):\n",Max-1);
	printf("�����:");
	scanf("%d",&location_r);
	printf("���յ�:");
	scanf("%d",&location_c);
	printf("��Ȩ��:");
	scanf("%d",&heavy);
	
	if(A[location_r][location_c]==0){
		A[location_r][location_c]=heavy;
		CreatMat(t,A);
		printf("\n��ϲ�����Ĳ����ѳɹ�����ͼ������£�\n");
		DispMat(t);
	}
	else{
		printf("�Բ��𣬸ñ��Ѵ��ڣ��������λ�ò���ȷ!\n");
		exit(0);
	}
	
}
//5. ɾ���ߣ�u,v��                 
void DeleteLine(MatNode *mh){
	MatNode *p;//ѭ��ָ��->��λ
	MatNode *q;//ѭ��ָ��->��λ
	MatNode *s;//ѭ��ָ��->��λ
	int location_c=0;//�յ�
	int location_r=0;//���

	printf("��=%d ��=%d\n",mh->row,mh->col);
	printf("����������ɾ���ı�(0-%d):\n",Max-1);
	printf("�����:");
	scanf("%d",&location_r);
	printf("���յ�:");
	scanf("%d",&location_c);
	//��ɾ��λ�õ�ǰһλ��
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
	//���ҳɹ�
	if(q->right->row==location_r&&q->right->col==location_c){
		s=q->right;
		//����ɾ�����
		q->right=s->right;
		//����ɾ�����
		q->down=s->down;		
		free(s);
		printf("\n��ϲ������ɾ������ɣ���ͼ������£�\n");
		DispMat(t);
	}
	else{
		printf("��ɾ����λ�ò���ȷ��\n");
	}
}
void main_4(){
	int i,j=0;//ѭ������
	int val;
	tenlinks_clarify_mt();
	Menu_4();
	int choose=0;
	printf("����������ѡ��");
	scanf("%d",&choose);
	switch(choose)
	{
		case 1:	system("cls");
				printf("������һ��%d*%d��ά��������ʾ��������ͼ:\n",M,N);
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
				printf("���棺\a\a\a\a\a\a\a\a\n");
				printf("����������������������!\n");
				Sleep(3000);
				system("CLS");
				main_4();
	}
}
/***********************************************��Ҫ��������***********************************************/