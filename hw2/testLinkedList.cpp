/*
 *  COMP 15 HW 2 Cheshire ConCATenation - Time to linked up in Fur
 *
 *  testLinkedList<E>.cpp
 *
 *  PURPOSE: Tests the LinkedList<E> class
 *
 *  Modified By: Dylan Maloy
 *           On: Sep 23 2020
 */

#include <iostream>
#include "LinkedList.h"

typedef char E;

using namespace std;

void isEmpty();
void clear();
void size();
void first();
void last();
void elementAt();
void print();
void pushAtBack();
void pushAtFront();
void insertAt();
void insertInOrder();
void popFromFront();
void popFromBack();
void removeAt();
void replaceAt();
void concatenate();
void find();

int main()
{
    isEmpty();
    clear();
    size();
    first();
    last();
    elementAt();
    print();
    pushAtBack();
    pushAtFront();
    insertAt();
    insertInOrder();
    popFromFront();
    popFromBack();
    removeAt();
    replaceAt();
    concatenate();
    find();
}

/**
     * FUNCTION: isEmpty
     * 
     * PURPOSE: test isEmpty method
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void isEmpty() {
    LinkedList<E> list;
    cout << "testing isEmpty on empty arr..." << endl;
    cout << boolalpha << list.isEmpty() << endl;
    cout << "testing isEmpty on list w/ one element..." << endl;
    list.pushAtBack('a');
    cout << boolalpha << list.isEmpty() << endl;
    cout << endl;
}

/**
     * FUNCTION: clear
     * 
     * PURPOSE: test clear method
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void clear() {
    LinkedList<E> list(new char[3]{'a', 'b', 'c'}, 3);
    list.print();
    cout << "testing clear on list..." << endl;
    list.clear();
    list.print();
    cout << endl;
}

/**
     * FUNCTION: size
     * 
     * PURPOSE: test size method
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void size() {
    LinkedList<E> list(new char[3]{'a', 'b', 'c'}, 3);
    list.print();
    cout << "testing size on list..." << endl;
    cout << list.size() << endl;
    cout << endl;
}

/**
     * FUNCTION: first
     * 
     * PURPOSE: test first method
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void first() {
    LinkedList<E> list(new char[3]{'a', 'b', 'c'}, 3);
    list.print();
    cout << "testing first on list..." << endl;
    cout << list.first() << endl;
    list.clear();
    cout << "clearing list" << endl;
    try {
        list.first();
    } catch (runtime_error e) {
        cerr << e.what() << endl;
    }
    cout << endl;
}

/**
     * FUNCTION: last
     * 
     * PURPOSE: test last method
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void last() {
    LinkedList<E> list(new char[3]{'a', 'b', 'c'}, 3);
    list.print();
    cout << "testing last on list..." << endl;
    cout << list.last() << endl;
    list.clear();
    cout << "clearing list" << endl;
    try {
        list.last();
    } catch (runtime_error e) {
        cerr << e.what() << endl;
    }
    cout << endl;
}

/**
     * FUNCTION: elementAt
     * 
     * PURPOSE: test elementAt method
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void elementAt() {
    LinkedList<E> list(new char[3]{'a', 'b', 'c'}, 3);
    list.print();
    cout << "testing elementAt(1) on list..." << endl;
    cout << list.elementAt(1) << endl;
    try {
        cout << "testing with index 40" << endl;
        list.elementAt(40);
    } catch (range_error e) {
        cerr << e.what() << endl;
    }
    cout << endl;
}

/**
     * FUNCTION: print
     * 
     * PURPOSE: test print method
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void print() {
    LinkedList<E> list(new char[3]{'a', 'b', 'c'}, 3);
    cout << "testing print on list..." << endl;
    list.print();
    cout << endl;
}

/**
     * FUNCTION: pushAtBack
     * 
     * PURPOSE: test pushAtBack method
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void pushAtBack() {
    LinkedList<E> list(new char[3]{'a', 'b', 'c'}, 3);
    list.print();
    cout << "testing pushAtBack on list..." << endl;
    list.pushAtBack('r');
    list.print();
    cout << endl;
}

/**
     * FUNCTION: pushAtFront
     * 
     * PURPOSE: test pushAtFront method
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void pushAtFront() {
    LinkedList<E> list(new char[3]{'a', 'b', 'c'}, 3);
    list.print();
    cout << "testing pushAtFront on list..." << endl;
    list.pushAtFront('r');
    list.print();
    cout << endl;
}

/**
     * FUNCTION: insertAt
     * 
     * PURPOSE: test insertAt method
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void insertAt() {
    LinkedList<E> list(new char[3]{'a', 'b', 'c'}, 3);
    list.print();
    cout << "testing insertAt('r', 1) on list..." << endl;
    list.insertAt('r', 1);
    list.print();
    try {
        cout << "testing with index 40" << endl;
        list.insertAt('r', 40);
    } catch (range_error e) {
        cerr << e.what() << endl;
    }
    cout << endl;
}

/**
     * FUNCTION: insertInOrder
     * 
     * PURPOSE: test insertInOrder method
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void insertInOrder() {
    LinkedList<E> list(new char[3]{'a', 'b', 'c'}, 3);
    list.print();
    cout << "testing insertInOrder('b') on list..." << endl;
    list.insertInOrder('b');
    list.print();
    cout << endl;
}

/**
     * FUNCTION: popFromFront
     * 
     * PURPOSE: test popFromFront method
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void popFromFront() {
    LinkedList<E> list(new char[3]{'a', 'b', 'c'}, 3);
    list.print();
    cout << "testing popFromFront on list..." << endl;
    list.popFromFront();
    list.print();
    list.clear();
    cout << "clearing list" << endl;
    try {
        list.popFromFront();
    } catch (runtime_error e) {
        cerr << e.what() << endl;
    }
    cout << endl;
}

/**
     * FUNCTION: popFromBack
     * 
     * PURPOSE: test popFromBack method
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void popFromBack() {
    LinkedList<E> list(new char[3]{'a', 'b', 'c'}, 3);
    list.print();
    cout << "testing popFromBack on list..." << endl;
    list.popFromBack();
    list.print();
    list.clear();
    cout << "clearing list" << endl;
    try {
        list.popFromBack();
    } catch (runtime_error e) {
        cerr << e.what() << endl;
    }
    cout << endl;
}

/**
     * FUNCTION: removeAt
     * 
     * PURPOSE: test removeAt method
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void removeAt() {
    LinkedList<E> list(new char[3]{'a', 'b', 'c'}, 3);
    list.print();
    cout << "testing removeAt(1) on list..." << endl;
    list.removeAt(1);
    list.print();
    try {
        cout << "testing with index 40" << endl;
        list.removeAt(40);
    } catch (range_error e) {
        cerr << e.what() << endl;
    }
    cout << endl;
}


/**
     * FUNCTION: replaceAt
     * 
     * PURPOSE: test replaceAt method
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void replaceAt() {
    LinkedList<E> list(new char[3]{'a', 'b', 'c'}, 3);
    list.print();
    cout << "testing replaceAt('v', 1) on list..." << endl;
    list.replaceAt('v', 1);
    list.print();
    try {
        cout << "testing with index 40" << endl;
        list.replaceAt('v', 40);
    } catch (range_error e) {
        cerr << e.what() << endl;
    }
    cout << endl;
}

/**
     * FUNCTION: concatenate
     * 
     * PURPOSE: test concatenate method
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void concatenate() {
    LinkedList<E> list(new char[3]{'a', 'b', 'c'}, 3);
    LinkedList<E> list2(new char[2]{'x','y'}, 2);
    list.print();
    list2.print();
    cout << "concatenating the two lists..." << endl;
    list.concatenate(&list2);
    list.print();
    cout << endl;
}

/**
     * FUNCTION: find
     * 
     * PURPOSE: test find method
     *  
     * PARAMETERS: N/A
     * 
     * RETURN: void
     * 
     * MISC: N/A
     **/

void find() {
    LinkedList<E> list(new char[3]{'a', 'b', 'c'}, 3);
    cout << "finding a in a --> b --> c" << endl;
    cout << boolalpha << list.find('a') << endl;
    cout << "finding r in a --> b --> c" << endl;
    cout << boolalpha << list.find('r') << endl;
    cout << endl;
}

