#pragma once
#include <cstddef>
#include <iostream>

struct Node
{
	int field;
	Node* ptr;
};

class Forward_List
{
public:
	Forward_List() { Head = NULL; }
	int getCount() { return count; }
	bool isEmpty() { return Head == NULL; } // перевірки чи пустий список
	int getValue(Node* p) { return p->field; }
	void setValue(Node* p, int val) { p->field = val; }
	Node* getFirst() { return Head; }
	Node* getLast()
	{
		Node* p = Head;
		while (Next(p) != NULL)
			p = Next(p);
		return p;
	}
	void Clear()
	{
		Node* p = Head;
		if (p == NULL) return;
		do
		{
			Node* d = p;
			p = Next(p);
			delete d;
		} while (p != NULL);
		count = 0;
		Head = NULL;
	}
	Node* Next(Node* node)
	{
		if (isEmpty()) return NULL;
		return node->ptr;
	}
	Node* Prev(Node* node)
	{
		if (isEmpty()) return NULL;
		if (node == Head) return NULL;
		Node* p = Head;
		while (p->ptr != node)
			p = p->ptr;
		return p;
	}
	Node* Add(int num, Node* node = NULL)
	{
		Node* elem = new Node();
		elem->field = num;
		count++;
		if (node == NULL)
		{
			if (Head == NULL)
			{
				elem->ptr = NULL;
				Head = elem;
			}
			else
			{
				elem->ptr = Head;
				Head = elem;
			}
			return elem;
		}
		elem->ptr = node->ptr;
		node->ptr = elem;
		return elem;
	}
	Node* Delete(Node*node)
	{
		if (node == NULL)
		{
			return NULL; // no node
		}
		count--;
		if (node == Head)
		{
			Head = node->ptr;
			delete node;
			return Head;
		}
		Node* prev = Prev(node);
		prev->ptr = node->ptr;
		delete node;
		return prev;
	}
	void Print()
	{
		if (isEmpty()) { std::cout << "List empty" << std::endl; }
		Node* p = Head;
		do
		{
			std::cout << getValue(p) << "\t" <<  std::endl;
			p = Next(p);
		} while (p != NULL);
		std::cout << std::endl;
	}
	void Swap(Node* node1, Node* node2)
	{
		if (node1 == NULL || node2 == NULL) return; 
		if (node1 == node2) return; 
		if (node2->ptr == node1) 
		{
			Node* p = node1;
			node1 = node2;
			node2 = p;
		}
		Node* prev1 = Prev(node1);
		Node* prev2 = Prev(node2);
		Node* next1 = Next(node1);
		Node* next2 = Next(node2);
		if (next1 == node2) 
		{
			if (prev1 != NULL)
				prev1->ptr = node2;
			else
				Head = node2;
			node2->ptr = node1;
			node1->ptr = next2;
			return;
		}
		if (prev1 != NULL)  
			prev1->ptr = node2;
		else
			Head = node2;
		if (prev2 != NULL)
			prev2->ptr = node1;
		else
			Head = node1;
		node2->ptr = next1;
		node1->ptr = next2;
	}

private:
	Node* Head;
	int count = 0; // к-ть вузлів
	Node* Prev(Node*);
};

