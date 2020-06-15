
/*

  Time complexity of Fenwick tree 
  
  build tree- O(nlogn)
  search- O(logn)
  update -O(logn)
  space taken is n
  
 */
#include<bits/stdc++.h>
using namespace std;
void updateTree(int no, int index,int n, int FWTree[])
{
    index++;

    while(index<=n)
    {
        FWTree[index]+=no;
        index+=index & (-index);
    }
}
int *buildTree(int arr[],int n)
{
    int *FWTree=new int[n+1];

    for(int i=0;i<n+1;i++)
    FWTree[i]=0;

    for(int i=0;i<n;i++)
    {
        updateTree(arr[i],i,n, FWTree);
    }
    return FWTree;  
}

int main()
{
    int arr[11]={3,2,-1,6,5,4,-3,3,7,2,3};
    int n=11;
    int *FWTree=buildTree(arr,n);


    for(int i=0;i<=n;i++)
        cout<<FWTree[i]<<" ";
    j 
}
 