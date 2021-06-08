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
   /* int heightSubTree(Node * soot, int count)
    {
        if(soot == nullptr)
            return 0;
        count++;
        if(soot->left != nullptr)
            {heightSubTree(soot->left, count);
                cout<<soot->value<<endl;
            }
        if(soot->right !=nullptr)
            {
            heightSubTree(soot->right,count);
            }
        return count;
    }
    */int heightSubTree(Node * soot,int count)
    {   count++;
        if(soot == nullptr)
            return 0;
        if(soot->left != nullptr)
            cout<<"\tL"<<count<<" "<<soot->left->value<<"\t";
        if(soot->right !=nullptr)
            {cout<<"L"<<count<<" "<<soot->right->value<<"\t";}
        heightSubTree(soot->left,count);
        heightSubTree(soot->right,count);



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

  bool isBalanced(Node * root)
    {  
         if(root == nullptr)
        {
            return true;
        }
        int count = 0;
        int heightLeft= heightSubTree(root->left,count);
        int heightRight= heightSubTree(root->right,count);


        if(abs(heightLeft-heightRight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
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

    cout<<endl;
   if(t1.isBalanced(t1.getRoot()))
        cout<<"YES";
    else
        cout<<"NO";


    return 0;
}
