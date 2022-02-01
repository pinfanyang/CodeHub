#include<stdio.h>
#define MAX 101
int Post_office(int P[],int H[],int n)
{
    P[1]=H[1]+100;  //第一个邮局位置
	int m=1;
	int i;
	for(i=2;i<=n;i++){
        if(H[i]>P[m]+100)
        {
            m++;
			P[m]=H[i]+100;
		}
	}
	if(P[m]>H[n])
	    P[m]=H[n];  //最后一个邮局不需要在最后一户人家之外
	return m;
}

int main(){
    int P[MAX];
	int H[MAX];
	int n=0;
	int m=0;
	printf("Please input the quantity:\n");
	scanf("%d",&n);
	printf("Please input the family`s distance:\n");
	for(int i=1;i<=n;i++)
        scanf("%d",&H[i]);
	m=Post_office(P,H,n);
    printf("There are %d post office,there are:\n",m);
	for(int i=1;i<=m;i++)
	    printf("%d ",P[i]);
	return 0; 
}
