//TREE
#include <bits/stdc++.h>

using namespace std;
//Tree is similar to linked lists
//Parent and children or ancestor and descendants relation 
//Tree traverse
//Applicaiton : 
//Binary Search Tree - Parse Tree - Syntax Tree - Folder Tree  - Decision Tree(ML-VN)
//Expression Tree
//Post Traverse => Children to Parents Traverse
//Rooted vs Unrooted Tree (Spanning Tree)
//Height of Tree : max number of descendants
//Depth: how far node is from root. Depth of tree is the farest terminal
//Complete Tree: number of nodes = b^((height)+1) - 1
//Balanced Tree: Depth left - Depth right <= 1
//Binary Tree: Each Node has two children only

//Binary Tree Implementation

class TreeNode
{  // datatype data;
    int data;
    TreeNode *left;
    TreeNode *right;

    public:
    TreeNode(int d = 0, TreeNode * left = NULL, TreeNode * right = NULL)
    {
        data = d;
        this->left = left;
        this->right = right;

    }
    int getData(){
        return data;
    }

    TreeNode * getLeft()
    {
        return left;
    }
    TreeNode * getRight()
    {
        return right;
    }
    void setData(int d)
    {
        data =d;
    }
    void setLeft(TreeNode * a)
    {
       left = a;
    }
    void setRight(TreeNode * b)
    {
        right = b;
    }

};
class Tree
{   
    private:
    TreeNode * rootPtr;
    public:
    Tree(TreeNode*rootPtr = NULL)
    {
        this -> rootPtr = rootPtr;

    }
    TreeNode * search(int x);
    bool insert(int x);
    TreeNode * remove(int x);
    TreeNode * getRoot()
    {
        return rootPtr;
    }
    bool isEmpty()
    {
        return rootPtr == NULL;
    }
    Tree getLeftSubTree(); Tree getRightSubTree();

   

};
/*
//General Tree Implementation:
template <class T> class tnode //What's Template? <class T>? tnode?
    {T Data;
    tnode * children[MAX]; //Array of pointers What's MAX?
    //Alternative tnode ** children (Dynamic Array of Pointers)
    //Two Stars means array to pointers
    //Also LinkedList of pointers List children and data in node is *tnode
}*/

//Traverse
//Know Parent and children
//Pre-Order in-Order Post-Order -> ways of traverse

//Pre-Order moves from up to down
//print Parent then print Left Child then right child and so on..

//In-Order only applicable in binary tree: node between two children
//Print Left then Print Node then Print Right

//Post - Order: down to up deal with children then parents
//children from left to right followed by parent


//Binary Search Tree
//Search for a number x
//compare x with the root
//if x  = root return
//if x > root go right
//if x < root go left
//repeat until you find it

//Search Code Binary Search Tree
TreeNode * Tree::search(int x)
{   
    if(isEmpty()) 
        return NULL;
    TreeNode * p = rootPtr;
    //Recursion is good if we need previous values but we don't need it here.
    //so we use iterative.
    while (p!=NULL) 
    {   
        int a = p->getData();
        if(a == x)
        return p; // FOUND
        else if (a > x)
        p = p->getRight();
        else
        p = p->getLeft();
    }
    return NULL; // NOT FOUND
}
//insertion
//tweak search and get it

//Deletion from BST
//Leaaf Node Easy 
//Parent Node with one child Easy > move the parent of the parent to the parent place
//Parent Node with two children Thinking> Move left and get the largest node
//>Move right and get the smallest node


//BST Remove

TreeNode * Tree:: remove(int x)
{
    if(isEmpty()) return NULL;
    TreeNode * p = rootPtr;
    TreeNode * parent = NULL; // Parent of Root is null duhh
    char whatChild; //is L if p is a left child and R if P is a right child

    while(p!= NULL)
    {
        int a = p->getData();
        if(a == x) break; // x found

        else if (x < a) //go left
            {
                parent = p; 
                whatChild = 'L';
                p = p->getLeft();
            }
        else //go right 
        {
            parent = p;
            whatChild = 'R';
            p = p->getRight();
        }

    }
    //Case 1: Node is Leaf:(EASY)
    //JUST DELETE NODE
    if(p->getLeft()==NULL && p->getRight()==NULL )
    {
        if(parent!=NULL)
            if(whatChild == 'L')
                parent->setLeft(NULL);
                
            else 
               parent->setRight(NULL);
        else 
        rootPtr = NULL;
    }
    
    //delete p; void function

    return p; //idk why man
    //Case 2:



    
}











int main()
{
    return 0;
}