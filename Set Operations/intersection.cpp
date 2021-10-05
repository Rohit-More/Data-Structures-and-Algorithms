#include<iostream>
using namespace std;
int main(){
        int A[10],B[10],num1,num2,i;

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
    
    int j = 0, k = 0;

  while(j < num1 && k < num2) {
    if (A[j] < B[k])

      j++;
    else if (B[k] < A[j])
  
      k++;
    else {
      cout<<"Intersection of set A and B is:-\n";
      cout<<B[k]<<" ";
      j++;
      k++;
    }
  }
 
    return 0;
}