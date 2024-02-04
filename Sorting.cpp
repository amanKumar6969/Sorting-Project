// commads

// Sort a given set of elements of a file using Insertion, quick, and Merge sorting
// technique and determine the time required to sort the elements. Repeat the experiment for
// different values of n, the number of elements in the list to be sorted and plot a graph of the
// time taken versus n. The elements can be read from a file or can be generated using the
// random number generator.

//commands


#include<bits/stdc++.h>
#include<chrono>
#include<algorithm>
using namespace std;
using namespace std::chrono;
int partition(int *arr,int s,int e){
int pivot=arr[s];
int count=0;
for(int i=s+1;i<=e;i++){
if(arr[i]<= pivot){
count++;
}
}
//shift of pivot at right position
int pivotIndex=s+count;
swap(arr[pivotIndex],arr[s]);
int i=s;
int j=e;
while (i<pivotIndex && j>pivotIndex){
while(arr[i]<=pivot){
i++;
}
while(arr[j]>pivot){
j--;
}
if(i<pivotIndex && j>pivotIndex){
swap(arr[i++],arr[j--]);
}
}
return pivotIndex;
}
void QuickSort(int *arr,int s,int e){
//if array have zero or one element
if(s>=e)
return;
//partition
int p=partition(arr,s,e);
// for left part
QuickSort(arr,s,p-1);
//for right part
QuickSort(arr,p+1,e);
}
void merge(int *arr,int s,int mid,int e){
int l1=mid-s+1;
int l2=e-mid;
int a[l1];
int b[l2];
for(int i=0;i<l1;i++){
a[i]=arr[s+i];
}
for(int i=0;i<l2;i++){
b[i]=arr[mid+1+i];
}
int i=0;
int j=0;
int k=s;
while(i< l1 && j< l2){
if(a[i]<b[j]){
arr[k]=a[i];
k++;
i++;
}
else{
arr[k]=b[j];
k++;
j++;
}
}
while(i<l1){
arr[k]=a[i];
k++;
i++;
}
while(j<l2){
arr[k]=b[j];
k++;
j++;
}
}
void Mergesort(int *arr,int s,int e){
if(s<e){
int mid=(s+e)/2;
Mergesort(arr,s,mid);
Mergesort(arr,mid+1,e);
merge(arr,s,mid,e);
}
}
int insertionsort(int *arr,int n){
for(int i=1;i<n;i++){
int temp=arr[i];
int j=i-1;
while(j>=0 && arr[j]>temp){
if(arr[j]>temp){
arr[j+1]=arr[j];
}
else{
break;
}
j--;
}
arr[j+1]=temp;
}
}
int main(){
int arr[1000];
int n1=100;
int n2=200;
int n3=400;
int n4=600;
cout<<"The random numbers are "<<endl;
for(int i=0;i<n1;i++){
arr[i]=rand();
}
for(int i=0;i<n2;i++){
arr[i]=rand();
}
for(int i=0;i<n3;i++){
arr[i]=rand();
}
for(int i=0;i<n4;i++){
arr[i]=rand();
}
cout<<endl;
auto start = chrono::steady_clock::now();
QuickSort(arr,0,n1-1);
auto end = chrono::steady_clock::now();
long a=chrono::duration_cast<chrono::nanoseconds>(end-start).count();
cout<<endl;
auto s = chrono::steady_clock::now();
insertionsort(arr,n1);
auto e = chrono::steady_clock::now();
long b=chrono::duration_cast<chrono::nanoseconds>(e-s).count();
cout<<endl;
auto st = chrono::steady_clock::now();
Mergesort(arr,0,n1-1);
auto et = chrono::steady_clock::now();
long c=chrono::duration_cast<chrono::nanoseconds>(et-st).count();
cout<<endl;
auto stt = chrono::steady_clock::now();
QuickSort(arr,0,n2-1);
auto ed = chrono::steady_clock::now();
long d=chrono::duration_cast<chrono::nanoseconds>(ed-stt).count();
cout<<endl;
auto be = chrono::steady_clock::now();
insertionsort(arr,n2);
auto en = chrono::steady_clock::now();
long f=chrono::duration_cast<chrono::nanoseconds>(en-be).count();
cout<<endl;
auto p = chrono::steady_clock::now();
Mergesort(arr,0,n2-1);
auto ab = chrono::steady_clock::now();
long g=chrono::duration_cast<chrono::nanoseconds>(ab-p).count();
cout<<endl;
auto sc = chrono::steady_clock::now();
QuickSort(arr,0,n3-1);
auto cl = chrono::steady_clock::now();
long h=chrono::duration_cast<chrono::nanoseconds>(cl-sc).count();
cout<<endl;
auto m = chrono::steady_clock::now();
insertionsort(arr,n3);
auto n = chrono::steady_clock::now();
long j=chrono::duration_cast<chrono::nanoseconds>(n-m).count();
cout<<endl;
auto x = chrono::steady_clock::now();
Mergesort(arr,0,n3-1);
auto z = chrono::steady_clock::now();
long k=chrono::duration_cast<chrono::nanoseconds>(z-x).count();
cout<<endl;
auto ka = chrono::steady_clock::now();
QuickSort(arr,0,n4-1);
auto gn = chrono::steady_clock::now();
long l=chrono::duration_cast<chrono::nanoseconds>(gn-ka).count();
cout<<endl;
auto aa = chrono::steady_clock::now();
insertionsort(arr,n4);
auto ah = chrono::steady_clock::now();
long o=chrono::duration_cast<chrono::nanoseconds>(ah-aa).count();
cout<<endl;
auto aaa = chrono::steady_clock::now();
Mergesort(arr,0,n4-1);
auto zzz = chrono::steady_clock::now();
long yy=chrono::duration_cast<chrono::nanoseconds>(zzz-aaa).count();
cout<<endl;
cout<<endl;
cout<<"\t\tTime Taken";
cout<<endl;
cout<<"Size \tQuick Sort \tMerge Sort \t Insertion Sort "<<endl;
cout<<endl;
cout<<n1<<" \t"<<a<<" ns"<<" \t"<<b<<" ns"<<" \t\t"<<c<<" ns"<<endl;
cout<<n2<<" \t"<<d<<" ns"<<" \t"<<f<<" ns"<<" \t\t"<<g<<" ns"<<endl;
cout<<n3<<" \t"<<h<<" ns"<<" \t"<<j<<" ns"<<" \t\t"<<k<<" ns"<<endl;
cout<<n4<<" \t"<<l<<" ns"<<" \t"<<o<<" ns"<<" \t\t"<<yy<<" ns"<<endl;
return 0;
}