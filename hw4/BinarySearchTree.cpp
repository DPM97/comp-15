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

BinarySearchTree::BinarySearchTree()
{
        root = nullptr; // initialize the root of the tree
}

BinarySearchTree::~BinarySearchTree()
{
        // walk tree in post-order traversal and delete
        post_order_delete(root);
        root = nullptr; // not really necessary, since the tree is going
                        // away, but might want to guard against someone
                        // using a pointer after deleting
}

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
        // use pre-order traversal to copy the tree
        root = pre_order_copy(source.root);
}

// assignment overload
BinarySearchTree &BinarySearchTree::operator=(const BinarySearchTree &source)
{
        // TODO: Students write code here
        // check for self-assignment

        // delete current tree if it exists

        // use pre-order traversal to copy the tree

        // don't forget to "return *this"
}

BinarySearchTree::Node *BinarySearchTree::pre_order_copy(Node *node) const
{
        // TODO: Students write code here
        // (hint: use a pre-order traversal to copy details from the
        // node to a new node)
}

int BinarySearchTree::find_min() const
{
        if (root == nullptr)
                return numeric_limits<int>::max(); // INT_MAX

        return find_min(root)->data;
}

BinarySearchTree::Node *BinarySearchTree::find_min(Node *node) const
{
        while (node->left)
                node = node->left;
        return node;
}

int BinarySearchTree::find_max() const
{
        if (root == nullptr)
                return numeric_limits<int>::min(); // INT_MIN
        return find_max(root)->data;
}

BinarySearchTree::Node *BinarySearchTree::find_max(Node *node) const
{
        while (node->right)
                node = node->right;
        return node;
}

bool BinarySearchTree::contains(int value) const
{
        if (root == nullptr)
                return false;
        return contains(root, value);
}

bool BinarySearchTree::contains(Node *node, int value) const
{
        if (node == nullptr)
                return false;
        if (node->data == value)
                return true;
        if (node->data > value)
                return contains(node->right, value);
        if (node->data < value)
                return contains(node->left, value);
        return false;
}

void BinarySearchTree::insert(int value)
{
        insert(root, nullptr, value);
}

void BinarySearchTree::insert(Node *node, Node *parent, int value)
{
        if (root == nullptr)
        {
                root = createNode(node, value);
                return;
        }
        else
        {
                if (node == nullptr)
                {
                        if (value < parent->data)
                        {
                                parent->left = createNode(node, value);
                        }
                        else
                        {
                                parent->right = createNode(node, value);
                        }
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

BinarySearchTree::Node *BinarySearchTree::createNode(Node *node, int value) 
{
        node = new Node();
        node->data = value;
        node->count = 1;
        node->left = nullptr;
        node->right = nullptr;
        return node;
}

bool BinarySearchTree::remove(int value)
{
        return remove(root, nullptr, value);
}

bool BinarySearchTree::remove(Node *node, Node *parent, int value)
{
        if (node == nullptr)
                return false;

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
                        return true;
                }
                else
                {
                        if (node->right)
                        {
                                Node *nr = node->right;
                                while (nr->left)
                                        nr = nr->left;
                                node->count = nr->count;
                                node->data = nr->data;
                                delete nr;
                        }
                        else if (node->left)
                        {
                                Node *nl = node->left;
                                node->count = nl->count;
                                node->data = nl->data;
                                node->left = nl->left;
                                node->right = nl->right;
                                delete nl;
                        }
                        else
                        {
                                delete node;
                        }
                }
        }
}

int BinarySearchTree::tree_height() const
{
        return tree_height(root);
}

int BinarySearchTree::tree_height(Node *node) const
{
        if (node == nullptr)
                return 0;
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

// returns the total number of nodes
int BinarySearchTree::node_count() const
{
        return node_count(root);
}

int BinarySearchTree::node_count(Node *node) const
{
        if (node == nullptr)
                return 0;
        int count = 1;
        count += node_count(node->left);
        count += node_count(node->right);
        return count;
}

// return the sum of all the node values (including duplicates)
int BinarySearchTree::count_total() const
{
        return count_total(root);
}

int BinarySearchTree::count_total(Node *node) const
{
        if (node == nullptr)
                return 0;
        int count = node->data * node->count;
        count += count_total(node->left);
        count += count_total(node->right);
        return count;
}

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
