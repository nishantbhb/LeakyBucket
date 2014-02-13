#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
 int b,f,a[20],ns,nb=0,nd=0,tp=0,pr,pd;
 int i,n;
 cout<<"Enter bucket size:";
 cin>>b;
 cout<<"Enter max output flow rate:";
 cin>>f;
 cout<<"Enter no. of sequence:";
 cin>>n;
 cout<<"Enter input packets for each second upto "<<n<<" sequences:";
 for(i=0;i<n;i++)
 cin>>a[i];
 cout<<"Time Seq\tPkt_Rec\t\tPkt_Snt\t\tPkt_In_Bkt\tPkt_Drpd\n";
 for(i=0;i<n;i++)
 {
  tp=nb+a[i];
  pr=0;
 
  if(tp>=f)
  {
   pr=tp-f;
   ns=f;
   if(pr>=b)
   {
    pd=pr-b;
    nb=b;
   }
   else
   {
    pd=0;
    nb=pr;
   }
  }
 
  else
  {
   ns=tp;
   nb=0;
   pd=0;
  }
  cout<<i+1<<"\t\t"<<a[i]<<"\t\t"<<ns<<"\t\t"<<nb<<"\t\t"<<pd<<"\n";
 }
 
 if(nb>0)
 {
  while(nb!=0)
  {
   if(nb<=f)
   {
    ns=nb;
    nb=0;
   }
   else
   {
    ns=f;
    nb-=f;
   }
   cout<<++i<<"\t\t"<<0<<"\t\t"<<ns<<"\t\t"<<nb<<"\t\t"<<0<<"\n";
  }
 }
}  
