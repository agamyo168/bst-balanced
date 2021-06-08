//Tree
//Binary Tree
//Binary Search Tree and it's complexity

//Height: How far a node is from leaf(farest node)
//Depth: how far a node is from root
//Directed Tree: Only Parents are aware of children (i.e parents have child left and child right)
//Undirected Tree: Parents and children are awaren of each other
//given nodes how many edges? ->n-1 edges This means that there's only one unique path for the root to reach a node

//TreeNode:
#define MAX_NUMBER_OF_CHILDREN 100  //Each node can have max 100 children. This is also how you define a constant
class TreeNode
{
    int data;
    TreeNode * children [MAX_NUMBER_OF_CHILDREN];
    //Or LinkedList 
    //list<Node *> children the <> is for template to use any datatype you want ignore it.
};

//Binary Tree can have 0, 1 or, 2 children only
class BinaryTreeNode
{
    int value;
    BinaryTreeNode * left;
    BinaryTreeNode * right;
};
//Binary Tree is balanced if
//1-the height of the two sub tree differ by utmost one
//2-both sub trees are balanced --go back to 1

//Sheet 5 Q1
//Traverse in-order, pre-order,post-order

//in-order -> Parent Mid
//LeftsubTree - currentNode - RightsubTree
//(L-child(so on) Parent R-Child(so on))subtreeLeft root (L-child(so on) Parent R-Child(so on))subtreeRight
//Therefore, go to the deepest left child and start from there

//Pre-order -> Parent First
//Parent L-subtree R-subtree

//Post-Order -> Parent Last
//L-subtree R-subtree parent 

//When creating a tree, Precedence is decided by the depth of node

//Binary Search Tree

//Each node has key and value 
//Parent has Key = KP, L-child key = KL and R-child key = KR
//Condition: KP > KL , KP < KR
//BST is used for two applications set<singledatatype> and map<key,value>
//All left sub tree keys is smaller than parent key

//BST insertion
//number of levels to number of nodes relation is levels = log(nodes) ?
//number of levels to number of nodes in a complete balanced tree = 1+2+2(2) +2(2(2))... = 2^L -1 Geometric Series
//complexity : Best case -> log(n) Worst case - >O(n)
//12, 5, 7, 9, 13,100, 80, 16, 18, 55, 10, 11
//12->Root
//5<12 therefore 5 goes left to 12
//7<12 and >5 therefore goes right to 5
//9<12 and >5 and >7 therefore goes right to 7
//13>12 therefore goes right to 12
//100>12 and > 13 therefore goes right to 13
//80>12 and >13 and <100 therefore goes left to 100
//16>12 and >13 and <100 and <80 therefore goes left to 80
//18>12 and >13 and <100 and <80 and >16 therefore goes right to 16
//55>12 and >13 and <100 and <80 and >16 >18 therefore goes right to 18
//10<12 and >5 and >7 >9 therefore goes right to 9
//11<12 and >5 and >7 >9 >10 therefore goes right to 10

//BST remove
////complexity : Best case -> log(n) Worst case - >O(n)
//Leaf Trivial just remove it and make parent point to null
//Single Child: child will replace the parent 
//Two child: search for the biggest node on left sub tree or smallest node on right sub tree to replace it



//BST balanced insertion
//First sort values
//Then the root will be the middle number
//then move left and do the same or right and do the same (find median)

//BST write a fn that gets maximum or minumum from node
int treeMax(BinaryTreeNode * root)
{
    if(root->right == nullptr)
        return root->value
return treeMax(root->right)
}   
//BST Sort Array
//1-Insert all values into BST using for loop
//2-Use in-order traversal to generate sorted version of the array

