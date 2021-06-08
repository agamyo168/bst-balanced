#include <bits/stdc++.h>
using namespace std;
class Node
{   int value;
    Node * left;
    Node * right;
    public:
    Node(){
        value = 0;
        left = nullptr;
        right = nullptr;
    }
    Node(int d):value(d),left(nullptr),right(nullptr){}
    friend class Tree;
};
class Tree
{
    Node * root;
    void insertNode(int x,Node * t)
    {
        if(x < t->value&&t->left == nullptr)
            {   
                t->left = new Node(x);}
        else if(x > t->value && t->right == nullptr)
            {
             t->right = new Node(x);}
        else if(x > t->value)
            insertNode(x,t->right);
        else
            insertNode(x,t->left);


    }
   int heightLeft(Node * soot)
    {   
        if(soot == nullptr)
            return 0;
        int count = 0;
        if(soot->left!= nullptr)
          count = 1+ heightLeft(soot->left);
        return count;
    }
    int heightRight(Node * soot)
    {   
        
        if(soot == nullptr)
            return 0;
        int count = 0;
        if(soot ->right !=nullptr)
            count = 1+heightRight(soot->right);
        return count;
    }
    
    public:
    Tree()
    {
        root = nullptr;
    }
    Node * getRoot()
        {
            return root;
        }
    void insert(int x)
    {
        Node * p = root;
        if(p == nullptr)
           {   //cout<<x<<"\t";
               root = new Node(x);
               return;
           }
        insertNode(x,p);

    }

    bool isBalanced(Node * soot)
    {   if(soot == nullptr)
            return true;
        int leftHeight = heightLeft(soot);
        int rightHeight = heightRight(soot);
        if(abs(leftHeight - rightHeight)<= 1 &&isBalanced(soot->left) && isBalanced(soot->right))
            return true;
        
        return false;
    }
};
   
int main()
{
    Tree t1;
    //int level;
    int size;
    cin>>size;
    int x;
    for(int i = 0; i < size; ++i)
    {
        cin>>x;
        t1.insert(x);

    }
    if(t1.isBalanced(t1.getRoot()))
        {cout<<"YES";
        return 0;}
    cout<<"NO";
    return 0;
}
