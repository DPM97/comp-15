/*
 * testing.cpp
 *
 *  Created on: Oct 31, 202
 *      Author: Dylan Maloy
 *    
 * Main testing file for the BinarySearchTree class & runs tests on all of the
 * important core-pieces of the BinarySearchTree class
 */

#include <iostream>
#include "testing.h"
using namespace std;

/**
FUNCTION: run
PURPOSE: function that calls all of the tests
PARAMETERS: N/A
RETURN: void
MISC: N/A
**/
void Testing::run() {
        find_min();
        find_max();
        contains();
        insert();
        remove();
        tree_height();
        node_count();
        count_total();
        copy_constructor();
        assignment_operator();
}

/**
FUNCTION: populateTree
PURPOSE: populates the tree with test data
PARAMETERS: N/A
RETURN: void
MISC: N/A
**/
void Testing::populateTree(BinarySearchTree &tree) {
        int values[]  = {4, 2, 11, 15, 9, 1, -6, 5, 3, 15, 2, 5, 13, 14};
        int numValues = sizeof(values) / sizeof(int);
        for (int i = 0; i < numValues; i++) tree.insert(values[i]);
}

/**
FUNCTION: find_min
PURPOSE: tests the find_min function
PARAMETERS: N/A
RETURN: void
MISC: N/A
**/
void Testing::find_min() {
        BinarySearchTree tree;
        populateTree(tree);
        tree.print_tree();
        cout << "Min value: " << tree.find_min() << endl;
        tree.post_order_delete(tree.root);
        tree.root = nullptr;
        cout << "Clearing tree" << endl;
        cout << "Min value (empty tree): " << tree.find_min() << endl;
        cout << endl;
}

/**
FUNCTION: find_max
PURPOSE: tests the find_max function
PARAMETERS: N/A
RETURN: void
MISC: N/A
**/
void Testing::find_max() {
        BinarySearchTree tree;
        populateTree(tree);
        tree.print_tree();
        cout << "Max value: " << tree.find_max() << endl;
        tree.post_order_delete(tree.root);
        tree.root = nullptr;
        cout << "Clearing tree" << endl;
        cout << "Max value (empty tree): " << tree.find_max() << endl;
        cout << endl;
}

/**
FUNCTION: contains
PURPOSE: tests the contains function
PARAMETERS: N/A
RETURN: void
MISC: N/A
**/
void Testing::contains() {
        BinarySearchTree tree;
        populateTree(tree);
        tree.print_tree();
        cout << "Contains (3): " << boolalpha << tree.contains(3) << endl;
        cout << "Contains (14): " << boolalpha << tree.contains(14) << endl;
        cout << "Contains (232): " << boolalpha << tree.contains(232) << endl;
        cout << "Contains (-6): " << boolalpha << tree.contains(-6) << endl;
        cout << endl;
}


/**
FUNCTION: insert
PURPOSE: tests the insert function
PARAMETERS: N/A
RETURN: void
MISC: N/A
**/
void Testing::insert() {
        BinarySearchTree tree;
        cout << "Inserting in order: 2 3 1 1" << endl;
        tree.insert(2);
        tree.insert(3);
        tree.insert(1);
        tree.insert(1);
        tree.print_tree();
        cout << endl;
}

/**
FUNCTION: remove
PURPOSE: tests the remove function
PARAMETERS: N/A
RETURN: void
MISC: N/A
**/
void Testing::remove() {
        BinarySearchTree tree;
        cout << "Inserting in order: 2 3 1 1" << endl;
        tree.insert(2);
        tree.insert(3);
        tree.insert(1);
        tree.insert(1);
        tree.remove(2);
        cout << "removing 2" << endl;
        tree.print_tree();
        cout << "removing 1" << endl;
        tree.remove(1);
        tree.print_tree();
        cout << "removing 1" << endl;
        tree.remove(1);
        tree.print_tree();
        cout << "removing 3" << endl;
        tree.remove(3);
        tree.print_tree();
        cout << endl;
}


/**
FUNCTION: tree_height
PURPOSE: tests the tree_height function
PARAMETERS: N/A
RETURN: void
MISC: N/A
**/
void Testing::tree_height() {
        BinarySearchTree tree;
        populateTree(tree);
        tree.print_tree();
        cout << "Getting tree height on tree: " << tree.tree_height() << endl;
        tree.post_order_delete(tree.root);
        tree.root = nullptr;
        cout << "Getting tree height on empty tree: " << 
        tree.tree_height() << endl;
        cout << endl;
}

/**
FUNCTION: node_count
PURPOSE: tests the node_count function
PARAMETERS: N/A
RETURN: void
MISC: N/A
**/
void Testing::node_count() {
        BinarySearchTree tree;
        populateTree(tree);
        tree.print_tree();
        cout << "Node count: " << tree.node_count() << endl;
        tree.post_order_delete(tree.root);
        tree.root = nullptr;
        cout << "Node count (empty tree): " << tree.node_count() << endl;
        cout << endl; 
}

/**
FUNCTION: count_total
PURPOSE: tests the count_total function
PARAMETERS: N/A
RETURN: void
MISC: N/A
**/
void Testing::count_total() {
        BinarySearchTree tree;
        populateTree(tree);
        tree.print_tree();
        cout << "Total count: " << tree.count_total() << endl;
        tree.post_order_delete(tree.root);
        tree.root = nullptr;
        cout << "Total count (empty tree): " << tree.count_total() << endl;
        cout << endl; 
}

/**
FUNCTION: copy_constructor
PURPOSE: tests the copy constructor
PARAMETERS: N/A
RETURN: void
MISC: N/A
**/
void Testing::copy_constructor() {
        BinarySearchTree tree;
        populateTree(tree);
        tree.print_tree();
        cout << "Copying to tree2..." << endl;
        BinarySearchTree tree2(tree);
        tree2.print_tree();
        cout << endl;
}

/**
FUNCTION: assignment_operator
PURPOSE: tests the assignment operator
PARAMETERS: N/A
RETURN: void
MISC: N/A
**/
void Testing::assignment_operator() {
        BinarySearchTree tree;
        populateTree(tree);
        tree.print_tree();
        cout << "Assigning to tree2..." << endl;
        BinarySearchTree tree2 = tree;
        tree2.print_tree();
        cout << endl;
}

