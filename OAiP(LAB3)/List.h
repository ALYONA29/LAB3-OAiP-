//---------------------------------------------------------------------------

#ifndef ListH
#define ListH
//---------------------------------------------------------------------------
#endif
#include "Node.h"

class List
{
public:
	Node *head;
	int count = 0;
	Node* Prev(Node *);
	List()
	{
		head = NULL;
	}
	public:
	int getCount()
	{
		return count;
	}
	bool isEmpty()
	{
		return head == NULL;
	}
	int getValue(Node* p)
	{
		return p->field;
	}
	void setValue(Node *p, int val)
	{
		p->field = val;
	}
	int getHours(Node* p)
	{
		return p->hours;
	}
	void setHours(Node *p, int val)
	{
		p->field = val;
	}
	float getTarif(Node* p)
	{
		return p->tarif;
	}
	void setTarif(Node *p, float val)
	{
		p->tarif = val;
	}
	float getPay(Node* p)
	{
		return p->pay;
	}
	void setPay(Node *p, float val)
	{
		p->pay = val;
	}
	String getSurname(Node* p)
	{
		return p->surname;
	}
	void setSurname(Node *p, String val)
	{
		p->surname = val;
	}
	String getName(Node* p)
	{
		return p->name;
	}
	void setName(Node *p, String val)
	{
		p->name = val;
	}
	String getFathername(Node* p)
	{
		return p->fathername;
	}
	void setFathername(Node *p, String val)
	{
		p->fathername = val;
	}
	Node* getFirst()
	{
		return head;
	}
	Node* getLast();
	Node* Next(Node *);
	Node* Add(String, String, String, int, int, float, float, Node*);
	Node* Delete(Node*);
};