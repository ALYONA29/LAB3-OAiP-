//---------------------------------------------------------------------------

#pragma hdrstop

#include "List.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Node* List::Add(String s, String n, String f, int num, int h, float t, float p, Node* node = NULL)
{
	Node *elem = new Node();
	elem->surname = s;
	elem->name = n;
	elem->fathername = f;
	elem->field = num;
	elem->hours = h;
	elem->tarif = t;
    elem->pay = p;
	count++;
	if (count == 1)
	{
        node = NULL;
	}
	if (node == NULL)
	{
		if (head == NULL)
		{
			elem->ptr = NULL;
			head = elem;
		}
		else
		{
			elem->ptr = head;
			head = elem;
		}
		return elem;
	}
	elem->ptr = node->ptr;
	node->ptr = elem;
	return elem;
}

Node* List::Delete(Node* node)
{
	if (node == NULL)
	{
		return NULL;
	}
	count--;
	if (node == head)
	{
		head = node->ptr;
		delete node;
		return head;
	}
	Node* prev = Prev(node);
	prev->ptr = node->ptr;
	delete node;
	node = prev->ptr;
	return prev;
}

Node* List::getLast()
{
	Node* p = head;
	while (Next(p) != NULL)
	{
		p = Next(p);
	}
	return p;
}

Node* List::Next(Node* node)
{
	if (isEmpty())
	{
		return NULL;
	}
	return node->ptr;
}

Node* List::Prev(Node* node)
{
	if (isEmpty())
	{
		return NULL;
	}
	if (node == head)
	{
		return NULL;
	}
	Node *p = head;
	while (p->ptr != node)
	{
		p = p->ptr;
    }
	return p;
}

