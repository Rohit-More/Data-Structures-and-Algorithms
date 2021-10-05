#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
   int A[10],B[10],U[10],num1,num2,i,j;
   int k=0;

   cout<<"Enter number of elements in set A :"<<endl;
   cin>>num1;
   cout<<"Enter the elements of set A"<<endl;
   for(i=0;i<num1;i++)
      cin>>A[i];

   cout<<"Enter number of element in set B :"<<endl;
   cin>>num2;
   cout<<"Enter the elements of set B"<<endl;
   for(i=0;i<num2;i++)
     cin>>B[i];

   for(i=0;i<num1;i++)
   {
      for(j=0;j<k;j++)
      {
         if(U[j]==A[i]) 
            break;
       }
       if(j==k) 
       {
          U[k]=A[i];
          k++;
       }
    }
   for(i=0;i<num2;i++)
   {
      for(j=0;j<k;j++)
      {
         if(U[j]==B[i])
           break;
      }
     if(j==k) 
     {
       U[k]=B[i];
       k++;
     }
   }
   
   cout<<"Union of set A and B is:-\n";
    for(i=0;i<k;i++)
        {
            sort(U,U+k);
            cout<<U[i]<<" ";
        }
}