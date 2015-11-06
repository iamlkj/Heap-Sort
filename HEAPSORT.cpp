#include<stdio.h>
#include<stdlib.h>
#define MAX 1000005 
int a[MAX],all,atmp[MAX];;
void output(); 
int meargesort(int*,int,int);
void heapsort(int*,int,int) ; 
void readinput()
{
	int c=0,cs=0,now=0,tmp=0;
	scanf("%d",&cs);
	//printf("(%d cases)\n",cs);
	for(int i=0;i<cs;i++)
	{
		scanf("%d",&c);
		//printf("(%d nums)\n",c);
		now=tmp; 
		for(int j=0;j<c;j++)
		{
			scanf("%d",&a[tmp]);
			//printf("(%d has read)\n",a[tmp]);
			tmp++;
		}
		heapsort(a,now,tmp);
	}
	all=tmp;
}
void test()
{
	int tmp=0; 
	for(int i=1000000;i>0;i--)
	{
		a[tmp]=rand();
		tmp++;	
	}
	heapsort(a,0,1000000-1);
	all=1000000-1; 
	
} 
void output()
{
	if(all)printf("%d",a[0]);
	for(int i=1;i<all;i++)
	{
		printf("\n%d",a[i]);
	}
	printf("\n"); 
}
void change(int &a,int &b )
{
	int tmp=a;
	a=b;
	b=tmp; 
} 
int buildheap(int *a,int h,int b,int m)
{
	if(h>m)return 0; 
	int x=h; 
	int l=(2*(h-b))+1+b;
	int r=(2*(h-b))+2+b;  
	if(l<=m&&a[l]>a[h])
	{
		x=l; 
	}
	if(r<=m&&a[r]>a[x])
	{
		x=r; 
	}
	if(x!=h)
	{
		change(a[x],a[h]);
		buildheap(a,x,b,m); 
	} 
}
void heapsort(int *a,int s,int c)
{
	//printf("sOrted!\n");
	c--;
	for(int i=c;i>=s;i--)
	{
		buildheap(a,i,s,c);
	}
	while(c>=s)
	{

		
		change(a[s],a[c]);
		c--; 
		buildheap(a,s,s,c);
		 
	}
	//printf("sorted!\n"); 
} 
int meargesort(int*a,int s,int c)
{
	if(s>=c-1){	return 0;}
	else
	{
		
		int i=s,j=(c+s)/2,count=0;
		meargesort(a,i,j);
		meargesort(a,j,c);
		
		while(count<c-s)
		{
			while((a[i]<=a[j]||j==c)&&count<c-s)
			{
				if(i<(c+s)/2)
				{
					atmp[count]=a[i];
					count++;
					i++;
				}
				else break;
			}
			while((a[i]>a[j]||i==(c+s)/2)&&count<c-s)
			{
				if(j<c)
				{
					atmp[count]=a[j];
					count++;
					j++;
				}
				else break;
			} 
		}
		int l=s;
		for(int k=0;k<count;k++)
		{
			a[l]=atmp[k];
			l++;
		}
	}
	return 0;
}
int main()
{
	//test(); 
	readinput();
//	system("pause");
	output();
//printf("Sorted!\n");

	system("pause"); 
}
