#include<stdio.h>
int a[10000];
int *mallocint();
void freeint(int *p);
void memsetint(int *p,int n,int size);
int main()
{
	int *p;
	int test[3][4];
	int i,j,n=1;
	for(i=0;i<3;++i)				//1,2,3,4;5,6,7,8;9,10,11,12;
		for(j=0;j<4;++j)
		{
			test[i][j]=n;
			++n;
		}
	p=test[0];
	printf("%d\n%d\n%d\n",*p,*(p+1),*(p+4));
	printf("%d\n%d\n%d\n",**test,*(*test+1),*(*(test+1)));
	memsetint(a,0,sizeof(a));
	p=mallocint();
	*p=100;
	freeint(p);
	return 0;
}
int *mallocint()
{
	int *p=a;
	while(p<=&a[10000])
	{
		if(*p==0)
			break;
		++p;
	}
	return p;
}
void freeint(int *p)
{
	*p=0;
}
void memsetint(int *p,int n,int size)
{
	int *tmp=p+size/sizeof(int);
	while(p<tmp)
	{
		*p=n;
		++p;
	}
}
