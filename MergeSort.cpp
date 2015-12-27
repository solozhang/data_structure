#include<iostream>
#include<string.h>
using namespace std;
void merge(int a[], int first, int mid, int last)
{
    int count = last - first + 1;
    int n = mid - first + 1;
    int m = last - mid;
    int *tmp = new int[count];
    int i,j,k,ii,jj;
    i=j=k=0;
    ii=first+i;
    jj=mid+1+j;
    while(i<n&&j<m){
        if(a[ii]<=a[jj])
            {tmp[k++]=a[ii++];i++;}
        else
            {tmp[k++]=a[jj++];j++;}
    }
    while(i<n){
        tmp[k++]=a[ii++];
        i++;
    }
    while(j<m){ 
        tmp[k++]=a[jj++];
        j++;
    }
    memcpy(a + first, tmp, sizeof(int)*count);
    delete tmp;
}
void merge_sort(int a[], int first, int last)
{
    if(first < last){
        int mid = (first+last)/2;
        merge_sort(a, first, mid);
        merge_sort(a, mid+1, last);
        merge(a, first, mid, last);
    }
}
int main(void)
{
//    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int a[10]={3,5,6,8,7,2,3,1,9,10};
    merge_sort(a, 0, 9);
    for(int i=0;i<10;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
