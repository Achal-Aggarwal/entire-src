//sg
#include<stdio.h>
int a[101][101],x[101],n,m,count=0;
void next(int k)
{
int j;
while(1)
{
x[k]=(x[k]+1)%(m+1);
if(x[k]==0)
return;
for(j=1;j<=n;j++)
if(a[k][j]!=0&&x[k]==x[j])
break;
if(j==n+1)
return;
}
}

void mcolor(int k)
{
int j;
while(1)
{
next(k);
if(x[k]==0)
return;
if(k==n)
{
((count++)%100000007);

}
else
mcolor(k+1);
}
return ;
}

int main()
{
int i,u,v,cases,Q,edges,ch;
//freopen("colordata","r",stdin);

scanf("%d",&cases);
for(int C=0;C<cases;C++)
{
scanf("%d",&n);
scanf("%d",&edges);
scanf("%d",&Q);
for(i=1;i<=edges;i++)
{
scanf("%d%d",&u,&v);
a[u+1][v+1]=a[v+1][u+1]=1;
}
//loop for each query
for(int q=0;q<Q;q++)
{
scanf("%d",&ch);
switch(ch)
{
case 0:
scanf("%d%d",&u,&v);
//printf("Joining  EDGE %d - %d",u,v);
a[u+1][v+1]=a[v+1][u+1]=1;
break;
case 1:
scanf("%d%d",&u,&v);
//printf("REMOVING EDGE %d - %d",u,v);
a[u+1][v+1]=a[v+1][u+1]=0;
break;
default :
m=ch;
mcolor(1);
printf("\n%d",count);

count=0;
break;

}
}  //end loop query 
}// end loop case 
return 0;
}
