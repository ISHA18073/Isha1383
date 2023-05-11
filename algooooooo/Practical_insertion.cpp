#include<iostream>
using namespace std;
int main(){
int a[]={8,5,4,3,21,3};
int n=6,count=0,key;
for(int i=1;i<n;i++){
int j=i-1;
key=a[i];
count=count+1;
while (j>=0 and key<a[j]){
     	          count++;
a[j+1]=a[j];
j=j-1;
   }
  a[j+1]=key;
}
cout<<"total number of comparison is:";
cout<<count;
cout<<endl;
cout<<"Sorted array is:";
cout<<endl;
for(int p=0;p<n;p++){
    cout<<a[p]<<" ";
}
return 0;}
