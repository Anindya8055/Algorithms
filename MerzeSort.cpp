#include<bits/stdc++.h>
using namespace std;
void merge(int l[],int nl, int r[],int nr, int a[], int n)
{
   // int nl = l.size();
    //int nr = r.size();
    int i,j,k;
    i=0;
    j=0;
    k=0;

    while(i<nl &&  j<nr)
    {
        if(l[i]<=r[j]){

            a[k] = l[i];
            i=i+1;
        }
        else{
            a[k] = r[j];
            j = j+1;
        }
        k = k+1;
    }
    while(i<nl)
    {
        a[k]= l[i];
        i=i+1;
        k = k+1;
    }
    while(j<nr)
    {
       a[k]=r[j];
       j = j+1;
       k = k+1;
    }
}
void mergeSort(int a[], int n)
{
    if(n<2){
        return;
    }
   int  mid = n/2;
    int l[mid];
    int r[n-mid];
    for(int  i=0; i<mid; i++)
    {
        l[i]=a[i];
    }
    for(int i=mid; i<n; i++)
    {
        r[i-mid] = a[i];
    }
    mergeSort(l,mid);
    mergeSort(r,(n-mid));
    merge(l, mid,r,(n-mid),a,n);

}


int main()
{
    int n= 8;
    int arr[n]={6,2,76,43,24,65,12,16};
    cout<<"GIVEN ARRAY: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    mergeSort(arr, n);

cout<<"AFTER SORTING: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

}

