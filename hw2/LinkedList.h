/*
 *  COMP 15 HW 2 Cheshire ConCATenation - Time to linked up in Fur
 *
 *  LinkedList.h
 *
 *  PURPOSE: Header file for the LinkedList.cpp class
 *
 *  Modified By: Dylan Maloy
 *           On: Sep 23 2020
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <typename E>
class LinkedList
{
public:
	LinkedList();
	LinkedList(E element);
	LinkedList(E elements[], int len);
	LinkedList(const LinkedList &other); // copy constructor
	~LinkedList();
	LinkedList &operator=(const LinkedList &rhs)
	{ // assignment operator
		length = rhs.length;
		curr_pos = nullptr;

		if (this == &rhs)
			return *this;
		if (rhs.front == nullptr)
		{
			front = nullptr;
			back = nullptr;
		}
		else
		{
			front = new Node;
			front->val = rhs.front->val;
			Node *curr = front;
			Node *orig = rhs.front;

			while (orig->next != nullptr)
			{
				curr->next = new Node;
				curr->next->val = orig->next->val;
				orig = orig->next;
				curr = curr->next;
			}
			back = curr;
		}

		return *this;
	}

	// METHODS
	bool isEmpty();
	void clear();
	int size();
	E first();							// can throw runtime err
	E last();								// can throw runtime err
	E elementAt(int index); // can throw range err
	void print();
	void pushAtBack(E element);
	void pushAtFront(E element);
	void insertAt(E element, int index);	// can throw range err
	void insertInOrder(E element);				// assumes alphabetical order
	void popFromFront();									// runtime err on empty
	void popFromBack();										// runtime err on empty
	void removeAt(int index);							// can throw range err
	void replaceAt(E element, int index); // can throw range err
	void concatenate(LinkedList *list2);
	void shrink();
	bool find(E element); // must be a recursive algo

private:
	struct Node
	{
		E val;
		Node *prev;
		Node *next;
	};
	int length;
	Node *front;
	Node *back;
	Node *curr_pos;
	int occurances(E element, int i);
};

#endif
