/*
 * BinarySearchTree.cpp
 * COMP15
 * Spring 2020
 *
 * Implementation of the Binary Search Tree class.
 * Behaves like a standard BST except that it handles multiplicity
 * If you insert a number twice  and then remove it once, then it will
 * still be in the data structure
 */

#include <cstring>
#include <iostream>
#include <limits>

#include "BinarySearchTree.h"

using namespace std;

// default constructor
BinarySearchTree::BinarySearchTree()
{
        root = nullptr; // initialize the root of the tree
}

// default destructor
BinarySearchTree::~BinarySearchTree()
{
        // walk tree in post-order traversal and delete
        post_order_delete(root);
        root = nullptr; // not really necessary, since the tree is going
                        // away, but might want to guard against someone
                        // using a pointer after deleting
}

/**
FUNCTION: post_order_delete
PURPOSE: deletes the entire tree (using a post order recursive method)
PARAMETERS: Node *node (usually the root)
RETURN: void
MISC: N/A
**/
void BinarySearchTree::post_order_delete(Node *node)
{
        if (node == nullptr)
                return;
        post_order_delete(node->left);
        post_order_delete(node->right);
        delete node;
}

// copy constructor
BinarySearchTree::BinarySearchTree(const BinarySearchTree &source)
{
        root = pre_order_copy(source.root);
}

// assignment overload
BinarySearchTree &BinarySearchTree::operator=(const BinarySearchTree &source)
{
        if (this != &source)
        {
                if (root != nullptr)
                        post_order_delete(root);
                root = pre_order_copy(source.root);
        }
        return *this;
}

/**
FUNCTION: pre_order_copy
PURPOSE: creates a deep copy of a tree
PARAMETERS: Node *node (usually the root)
RETURN: Node (root of the new copy)
MISC: N/A
**/
BinarySearchTree::Node *BinarySearchTree::pre_order_copy(Node *node) const
{
        if (node == nullptr)
                return node;

        Node *newRoot = new Node();
        newRoot->data = node->data;
        newRoot->count = node->count;

        newRoot->left = pre_order_copy(node->left);
        newRoot->right = pre_order_copy(node->right);

        return newRoot;
}

/**
FUNCTION: find_min
PURPOSE: wrapper for the find_min(node) function
PARAMETERS: N/A
RETURN: int (smallest element value)
MISC: N/A
**/
int BinarySearchTree::find_min() const
{
        if (root == nullptr)
                return numeric_limits<int>::max(); // INT_MAX

        return find_min(root)->data;
}

/**
FUNCTION: find_min
PURPOSE: fetches the node with the smallest value in the tree
PARAMETERS: Node *node (usually the root)
RETURN: Node (smallest node)
MISC: N/A
**/
BinarySearchTree::Node *BinarySearchTree::find_min(Node *node) const
{
        while (node->left)
                node = node->left;
        return node;
}

/**
FUNCTION: find_max
PURPOSE: wrapper for the find_max(node) function
PARAMETERS: N/A
RETURN: int (largest element value)
MISC: N/A
**/
int BinarySearchTree::find_max() const
{
        if (root == nullptr)
                return numeric_limits<int>::min(); // INT_MIN
        return find_max(root)->data;
}

/**
FUNCTION: find_max
PURPOSE: fetches the node with the largest value in the tree
PARAMETERS: Node *node (usually the root)
RETURN: Node (largest node)
MISC: N/A
**/
BinarySearchTree::Node *BinarySearchTree::find_max(Node *node) const
{
        while (node->right)
                node = node->right;
        return node;
}

/**
FUNCTION: contains
PURPOSE: wrapper for the contains (node, int) function
PARAMETERS: int value (value we are trying to find)
RETURN: bool (true if found)
MISC: N/A
**/
bool BinarySearchTree::contains(int value) const
{
        if (root == nullptr)
                return false;
        return contains(root, value);
}

/**
FUNCTION: contains
PURPOSE: checks if the tree contains the value 
PARAMETERS: Node *node (node for recursion) int value (value in question)
RETURN: bool (true if found)
MISC: N/A
**/
bool BinarySearchTree::contains(Node *node, int value) const
{
        if (node == nullptr)
                return false;

        if (value < node->data)
        {
                return contains(node->left, value);
        }
        else if (value > node->data)
        {
                return contains(node->right, value);
        }
        else
        {
                return true;
        }
}

/**
FUNCTION: insert
PURPOSE: wrapper for the insert(Node, Node, int) function
PARAMETERS: int value (value to be inserted)
RETURN: void
MISC: N/A
**/
void BinarySearchTree::insert(int value)
{
        insert(root, nullptr, value);
}

/**
FUNCTION: insert
PURPOSE: inserts node with value into tree
PARAMETERS: Node* node (curNode), Node *parent (parent of curNode), 
            int value (value to be inserted)
RETURN: void
MISC: N/A
**/
void BinarySearchTree::insert(Node *node, Node *parent, int value)
{
        if (root == nullptr)
        {
                root = createNode(node, value);
        }
        else
        {
                if (node == nullptr)
                {
                        value < parent->data ? 
                                parent->left = createNode(node, value) : 
                                parent->right = createNode(node, value);
                }
                else
                {
                        if (value < node->data)
                        {
                                insert(node->left, node, value);
                        }
                        else if (value > node->data)
                        {
                                insert(node->right, node, value);
                        }
                        else
                        {
                                node->count++;
                        }
                }
        }
}

/**
FUNCTION: createNode
PURPOSE: populates the node given
PARAMETERS: Node *node (empty node ptr), int value (value to be given)
RETURN: bool (true if found)
MISC: N/A
**/
BinarySearchTree::Node *BinarySearchTree::createNode(Node *node, int value)
{
        node = new Node();
        node->data = value;
        node->count = 1;
        node->left = nullptr;
        node->right = nullptr;
        return node;
}

/**
FUNCTION: remove
PURPOSE: wrapper for the remove(Node, Node, int) function
PARAMETERS: int value (value to be removed)
RETURN: bool (true if removed/decremented)
MISC: N/A
**/
bool BinarySearchTree::remove(int value)
{
        return remove(root, nullptr, value);
}

/**
FUNCTION: remove
PURPOSE: removes the node from the tree, decrements count, or returns false
PARAMETERS: Node *node (curNode), Node *parent (parent of curNode), 
            int value (value to be removed)
RETURN: bool (true if removed/decremented)
MISC: N/A
**/
bool BinarySearchTree::remove(Node *node, Node *parent, int value)
{
        if (node == nullptr) return false;
        if (value < node->data)
        {
                return remove(node->left, node, value);
        }
        else if (value > node->data)
        {
                return remove(node->right, node, value);
        }
        else
        {
                if (node->count > 1)
                {
                        node->count--;
                }
                else
                {
                        if (node_count() == 1)
                        {
                                delete node;
                                root = nullptr;
                        }
                        else
                        {
                                swapSuccessor(node, parent);
                        }
                }
                return true;
        }
}

/**
FUNCTION: swapSuccessor
PURPOSE: replaces the node with its successor
PARAMETERS: Node *node (the input node that is being removed)
RETURN: void
MISC: N/A
**/
void BinarySearchTree::swapSuccessor(Node *node, Node *parent)
{
        if (node->right)
        {
                Node *nr = node->right;
                while (nr->left)
                {
                        parent = nr;
                        nr = nr->left;
                }
                if (parent != nullptr) parent->left = nr->right;
                if (node->right == nr) node->right = nullptr;
                node->count = nr->count;
                node->data = nr->data;
                delete nr;
        }
        else if (node->left)
        {
                Node *nl = node->left;
                if (node->left == nl) node->left = nullptr;
                clone_node(nl, node);
                delete nl;
        }
        else
        {
                parent && parent->left == node ? 
                        parent->left = nullptr : 
                        parent->right = nullptr;
                delete node;
        }
}

/**
FUNCTION: clone_node
PURPOSE: clones the node
PARAMETERS: Node *node1 (node being cloned) Node *node2 (node to be cloned to)
RETURN: void
MISC: N/A
**/

void BinarySearchTree::clone_node(Node *node1, Node *node2) {
        node2->count = node1->count;
        node2->data = node1->data;
        node2->left = node1->left;
        node2->right = node1->right;
}

/**
FUNCTION: tree_height
PURPOSE: wrapper for the tree_height(Node) function
PARAMETERS: N/A
RETURN: int (height of tree)
MISC: N/A
**/
int BinarySearchTree::tree_height() const
{
        return tree_height(root);
}

/**
FUNCTION: tree_height
PURPOSE: fetches the height of the tree recursively
PARAMETERS: Node *node (curNode for recursive purposes)
RETURN: int (height of tree)
MISC: N/A
**/
int BinarySearchTree::tree_height(Node *node) const
{
        if (node == nullptr)
                return -1;
        int heightLeft = tree_height(node->left);
        int heightRight = tree_height(node->right);
        if (heightLeft > heightRight)
        {
                return heightLeft + 1;
        }
        else
        {
                return heightRight + 1;
        }
}

/**
FUNCTION: node_count
PURPOSE: wrapper for the node_count(Node) function
PARAMETERS: N/A
RETURN: int (total amount of nodes)
MISC: N/A
**/
int BinarySearchTree::node_count() const
{
        return node_count(root);
}

/**
FUNCTION: node_count
PURPOSE: recursively fetches the amount of nodes in the tree
PARAMETERS: Node *node (curNode for recursive purposes) 
RETURN: int (total amount of nodes)
MISC: N/A
**/
int BinarySearchTree::node_count(Node *node) const
{
        if (node == nullptr)
                return 0;
        int count = 1;
        count += node_count(node->left);
        count += node_count(node->right);
        return count;
}

/**
FUNCTION: count_total
PURPOSE: wrapper for the count_total(Node) function
PARAMETERS: N/A
RETURN: int (sum of node values)
MISC: N/A
**/
int BinarySearchTree::count_total() const
{
        return count_total(root);
}

/**
FUNCTION: count_total
PURPOSE: recursively fetches the sum of all nodes in the tree
PARAMETERS: Node *node (curNode for recursive purposes) 
RETURN: int (sum of node values)
MISC: N/A
**/
int BinarySearchTree::count_total(Node *node) const
{
        if (node == nullptr)
                return 0;
        int count = node->data * node->count;
        count += count_total(node->left);
        count += count_total(node->right);
        return count;
}

// finds the parent of the node
BinarySearchTree::Node *BinarySearchTree::find_parent(Node *node,
                                                      Node *child) const
{
        if (node == nullptr)
                return nullptr;

        // if either the left or right is equal to the child,
        // we have found the parent
        if (node->left == child or node->right == child)
        {
                return node;
        }

        // Use the binary search tree invariant to walk the tree
        if (child->data > node->data)
        {
                return find_parent(node->right, child);
        }
        else
        {
                return find_parent(node->left, child);
        }
}

// use the printPretty helper to make the tree look nice
void BinarySearchTree::print_tree() const
{
        size_t numLayers = tree_height() + 1;
        size_t levelWidth = 4;
        const char *rootPrefix = "-> ";

        // Need numLayers * levelWidth characters for each layer of tree.
        // Add an extra levelWidth characters at front to avoid if statement
        // 1 extra char for nul character at end
        char *start = new char[(numLayers + 1) * levelWidth + 1];

        print_tree(root, start + levelWidth, start + levelWidth, rootPrefix);
        delete[] start;
}

// Logic and Output Reference:
// https://www.techiedelight.com/c-program-print-binary-tree/
void BinarySearchTree::print_tree(Node *node, char *const currPos,
                                  const char *const fullLine,
                                  const char *const branch) const
{
        if (node == nullptr)
                return;

        // 4 characters + 1 for nul terminator
        using TreeLevel = char[5];
        static const int levelLength = sizeof(TreeLevel) - 1;
        static const TreeLevel UP = ".-- ", DOWN = "`-- ", EMPTY = "    ",
                               CONNECT = "   |";
        // Copies prev into dest and advances dest by strlen(prev)
        auto set = [](char *dest, const char *prev) {
                size_t p = strlen(prev);
                return (char *)memcpy(dest, prev, p) + p;
        };

        print_tree(node->right, set(currPos, EMPTY), fullLine, UP);

        // Clear any characters that would immediate precede the "branch"
        // Don't need to check for root (i.e start of array),fullLine is padded
        set(currPos - levelLength, EMPTY);

        // Terminate fullLine at current level
        *currPos = '\0';

        std::cerr << fullLine << branch << node->data
                  << (node->count > 1 ? "*" : "") << endl;

        // Connect upper branch to parent
        if (branch == UP)
                set(currPos - levelLength, CONNECT);

        // Connect lower branch to parent
        print_tree(node->left, set(currPos, CONNECT), fullLine, DOWN);
}
