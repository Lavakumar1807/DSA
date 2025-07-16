/* 
class Node {
    public:
        int data;
        Node* first_child;
        Node* second_child;
        Node* third_child;
        .
        .
        .
        Node* nth_child;
    }; 
*/

/*
  Tree data structure is a hierarchical structure that is used to represent and organize data in the form of parent child relationship

  Parent Node :  The node which is an immediate predecessor of a node is called the parent node of that node. {B} is the parent node of {D, E}.
  Child Node :  The node which is the immediate successor of a node is called the child node of that node. Examples: {D, E} are the child nodes of {B}.
  Root Node :  The topmost node of a tree or the node which does not have any parent node is called the root node. {A} is the root node of the tree. A non-empty tree must contain exactly one root node and exactly one path from the root to all other nodes of the tree.
  Leaf Node or External Node :  The nodes which do not have any child nodes are called leaf nodes. {I, J, K, F, G, H} are the leaf nodes of the tree.
  Ancestor of a Node :  Any predecessor nodes on the path of the root to that node are called Ancestors of that node. {A,B} are the ancestor nodes of the node {E}
  Descendant :  A node x is a descendant of another node y if and only if y is an ancestor of x.
  Sibling :  Children of the same parent node are called siblings. {D,E} are called siblings.
  Level of a node :  The count of edges on the path from the root node to that node. The root node has level 0.
  Internal node :  A node with at least one child is called Internal Node.
  Neighbour of a Node :  Parent or child nodes of that node are called neighbors of that node.
  Subtree :  Any node of the tree along with its descendant.

  Number of edges :  An edge can be defined as the connection between two nodes. If a tree has N nodes then it will have (N-1) edges. There is only one path from each node to any other node of the tree.
  Depth of a node :  The depth of a node is defined as the length of the path from the root to that node. Each edge adds 1 unit of length to the path. So, it can also be defined as the number of edges in the path from the root of the tree to the node.
  Height of a node :  The height of a node can be defined as the length of the longest path from the node to a leaf node of the tree.
  Height of the Tree :  The height of a tree is the length of the longest path from the root of the tree to a leaf node of the tree.
  Degree of a Node :  The total count of subtrees attached to that node is called the degree of the node. The degree of a leaf node must be 0. The degree of a tree is the maximum degree of a node among all the nodes in the tree.

=>Binary Tree :  A binary tree is a tree data structure where each node has at most two children. These two children are usually referred to as the left child and right child
  Complete Binary Tree :  A binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible. 
  Full Binary Tree :  A binary tree where every node has either 0 or 2 children.
  Degenerate Binary Tree (or Pathological Tree) :  A tree in which each parent node has only one child. This essentially forms a linked list, which leads to inefficient operations.
  Binary Search Tree (BST) and its Variations :  A BST is a binary tree where each node has at most two children, and for each node, the left child’s value is smaller than the node’s value, and the right child’s value is greater.
  Binary Indexed Tree (Fenwick Tree): A data structure that uses a binary tree to efficiently compute and update prefix sums in an array.
  Perfect Binary Tree :  A binary tree where all internal nodes have two children and all leaf nodes are at the same level. 
  Balanced Binary Tree :  A binary tree where the difference in heights between the left and right subtrees of any node is minimal (often defined as at most 1)
  Segment Tree :  A segment tree is a binary tree used for storing intervals or segments. It allows efficient querying and updating of ranges of values, making it particularly useful for problems that involve finding the sum, minimum, maximum, or other operations over a range of elements in an array.

=>Ternary Tree : A Ternary Tree is a tree data structure in which each node has at most three child nodes, usually distinguished as “left”, “mid” and “right”.

=>N-ary Tree (Generic Tree)
  Generic trees are a collection of nodes where each node is a data structure that consists of records and a list of references to its children(duplicate references are not allowed). Unlike the linked list, each node stores the address of multiple nodes. 
  Every node stores the addresses of its children and the very first node’s address will be stored in a separate pointer called root.
    1. Many children at every node.
    2. The number of nodes for each node is not known in advance.
   Examples of N-ary Trees:
    B-tree: A self-balancing search tree where nodes can have multiple children, usually used for indexing large databases.
    B+ Tree: A B+ tree is a variation of the B-tree that only stores data in the leaf nodes, making range queries more efficient.
    Trie (Prefix Tree): A tree where each node represents a character, and paths from the root to leaves represent strings. It can have a variable number of children for each node, making it an N-ary tree.
*/