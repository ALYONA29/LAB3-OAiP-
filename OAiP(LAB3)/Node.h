//---------------------------------------------------------------------------
#ifndef NodeH
#define NodeH
//---------------------------------------------------------------------------
#endif

class Node
{
	String surname;
	String name;
	String fathername;
	int field;
	int hours;
	float tarif;
    float pay;
	class Node *ptr;
	friend class List;
};