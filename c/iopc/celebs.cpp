//sg
#include<iostream>
#include<stdio.h>
#include<set>
using namespace std;
int ADMIRES[1000][1000];
set<int> admirers[1000];
set<int> designer[1000];
 bool hasDesigner[1000];
main()
{

 long noOfCelebs,relns,i,j,noOfDesigners=0,cases;

 bool flag=true; 
 int answer[10];
scanf("%d",&cases);
for(int w=0;w<cases;w++)
{
scanf("%d",&noOfCelebs);
scanf("%d",&relns);
//________________init()____________
if(w==0)
{
for(int i1=0;i1<1000;i1++)
{
  hasDesigner[i1]=false;
}
}
//____________________________________
for(int k=0;k<relns;k++)
{
scanf("%d%d",&i,&j);
ADMIRES[i][j]=1;   //an edge from i to j means that i admires j
admirers[j].insert(i);  //admirers(i) : list of people who admire i
}

for(int i=0;i<noOfCelebs;i++)
{

  for(set<int>::iterator itr=admirers[i].begin();itr!=admirers[i].end();itr++)
{
  
for(set<int>::iterator jtr=admirers[*itr].begin();jtr!=admirers[*itr].end();jtr++)
{
  //cout<<"adding "<<*jtr<<" to "<<i<<endl;
admirers[i].insert(*jtr);  //admirers(i) : list of people who admire i

}
}
}

//for each list of celebrities 
for(int i=0;i<noOfCelebs;i++)
{

if(!hasDesigner[i])  //no designer yet
{
noOfDesigners++;
//cout<<"adding a designer for "<<i<<"/"<<noOfCelebs<<"\n";
hasDesigner[i]=true;
designer[i].insert(i);
//for each celebrity
for(int j=0;j<noOfCelebs;j++)
{
  if(!hasDesigner[j])
  {

   flag=true;
//  cout<<"checking is addable for "<<i<<","<<j<<"\n";
   for(set<int>::iterator itr=designer[i].begin();itr!=designer[i].end();itr++)  
  {
  for(int o=0;o<noOfCelebs;o++)
  {
  if((ADMIRES[*itr][j]==1)||(ADMIRES[j][*itr]==1))  //does any element in the list admires ele?
   {
   // cout<<"HERE for "<<*itr<<" & "<< ele;
    flag= false;
    break;
  }
 }
if(!flag)
  break;
}

   if(flag)
   {
     
     designer[i].insert(j);
     hasDesigner[j]=true;
   }
     
}
}
  }
}
answer[w]=noOfDesigners;
for(int i=0;i<noOfCelebs;i++)
{
  hasDesigner[i]=false;
admirers[i].clear();}
noOfDesigners=0;
}

for(int w=0;w<cases;w++)
{
  printf("%d\n",answer[w]);
}
}