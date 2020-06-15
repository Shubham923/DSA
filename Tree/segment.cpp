#include<bits/stdc++.h>
using namespace std;
#define FI1 ios_base::sync_with_stdio(false)
#define FI2  cin.tie(NULL)
#define ll long long
void buildTree(int node,int start, int end, int arr[], int segTree[])
{
    if(start==end)
    {
        segTree[node]=arr[start];
    }
    else
    {
        int mid=(start+end)/2;

        buildTree(2*node+1, start, mid,arr, segTree);

        buildTree(2*node+2, mid+1, end, arr, segTree);

        segTree[node]=segTree[2*node+1]+segTree[2*node+2];
    }
    
    
}
/*index represents the index of original array over which we intend to make change/update*/
void updateTree(int node, int val, int index, int start, int end, int arr[], int segTree[])
{
    if(start==end)
    {
        arr[index]+=val;
        segTree[node]+=val;
    }
    else
    {
       
        int mid=(start+end)/2;

        if(start<=index && index<=mid)
        {
            updateTree(2*node+1, val , index, start, mid, arr, segTree);
        }
        else
        {
            updateTree(2*node+2, val , index, mid+1, end, arr, segTree);
        }

        segTree[node]=segTree[2*node+1]+segTree[2*node+2];
    }
    
}

int query(int node, int start, int end, int l, int r,int segTree[])
{
    /*completely out of range*/
    if(start>r || end< l)
    return 0;

    if(l<=start && r>=end)
    return segTree[node];

    int mid=(start+end)/2;

    int no1=query(2*node+1, start, mid, l, r, segTree);
    int no2=query(2*node+2, mid+1,end, l, r, segTree);

    return (no1+no2);

}
int main()
{
   int n=6;
   int arr[]={1,3,5,7,9,11};
   int segTree[2*n];
   int start=0, end=n-1;
   for (int i = 0; i < 2*n; i++)
   {
       segTree[i]=0;
   }
   
   buildTree(0,start, end ,arr,segTree); 

   for(int i=0;i<=2*n;i++)
   cout<<segTree[i]<<" ";


   while (true)
   {
       cout<<"\n1.Query\n2.Update\n3.Display\n";
       int ch;
       cin>>ch;
       switch (ch)
       {
       case 1:
            int l,r;
            cin>>l>>r;
            cout<<query(0, start, end, l, r,segTree);
            cout<<endl;
           break;
        case 2:
            int index,val;
            cin>>index>>val;
            val=val-arr[index];
            updateTree(0,val,index,start,end,arr,segTree);
            break;
        case 3:
            for(int i=0;i<=2*n;i++)
            cout<<segTree[i]<<" ";
            break;

       default:
           break;
       }

       /* code */
     
   }
   
}