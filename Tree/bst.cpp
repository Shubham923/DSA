#include<bits/stdc++.h>
using namespace std;
#define FI1 ios_base::sync_with_stdio(false)
#define FI2  cin.tie(NULL)

typedef struct node
{
    int val;
    struct node * left;
    struct node * right;
} Node;
class Tree
{
    public :
    Node * root;
    Node * createNode(int x)
    {
        Node *temp=new Node;

        temp->val=x;
        temp->left=NULL;
        temp->right=NULL;

        return temp;
    }
    void buildTree(int x)
    {
        if(root==NULL)
        {
            root=createNode(x);
        }
        else
        {
            Node *p=root;
            while(p!=NULL)
            {
                if(p->val>=x && p->left!=NULL)
                {
                    p=p->left;
                }
                else if(p->val>=x && p->left==NULL)
                {
                    p->left=createNode(x);  
                    break;
                }
                else if(p->val<x && p->right!=NULL)
                {
                    p=p->right;
                }
                else if(p->val<x && p->right==NULL)
                {
                   p->right=createNode(x);
                   break;
                }
                
            }        
        }
        
        
    }

    void inorder(Node *root)
    {
        if(root!=NULL){
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
        }
    }

};
void solve()
{
    
}
int main()
{
 
 Tree *t=new Tree();

 int ch;
 while (true)
 {      
     /* code */
   
     cout<<"\n1.Insert\n"<<"2.Display"<<endl;
     cin>>ch;
     switch(ch)
     {
        
         case 1:
         int x;
         cin>>x;
         t->buildTree(x);
         break;

         case 2:
         t->inorder(t->root);
         break;


         case 3:
         //t->deleteNode();
     }

 }
 

}
