/*
 * testing.h
 * COMP15
 * hw4
 *
 * header file for the testing class
 */

#ifndef TESTING_H_
#define TESTING_H_

#include "BinarySearchTree.h"

class Testing {

friend class BinarySearchTree;

public:
        void run();

private:
        void populateTree(BinarySearchTree &tree);
        void find_min();
        void find_max();
        void contains();
        void insert();
        void remove();
        void tree_height();
        void node_count();
        void count_total();
        void copy_constructor();
        void assignment_operator();
};

#endif