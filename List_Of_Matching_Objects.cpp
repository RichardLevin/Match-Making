#include "List_Of_Matching_Objects.h"
#include <iostream>
using namespace std;

// constructors-----------------------------------------------------------------------------
List::List()
{
}

// destructor-----------------------------------------------------------------------------
List::~List()
{
}

// mutators-----------------------------------------------------------------------------
bool List::set_Matchable_Object(unsigned pos, Matchable_Object& MO)
{
	if (!contains(pos, MO))
	{
		m_List[pos] = MO;
		return true;
	}
	else
	{
		return false;
	}
}

// accessors-----------------------------------------------------------------------------
// in: legal pos
Matchable_Object& List::get_Matchable_Object(unsigned pos)
{
	return m_List[pos];
}



// conditionals-----------------------------------------------------------------------
bool List::contains(unsigned pos, const Matchable_Object& MO)
{
	unsigned i = 0;
	while (i != pos && i < N)
	{
		i++;
	}
	return m_List[i] == MO;
}


// overloaded operators
/*
Matchable_Object& List::operator[](unsigned pos)
{
	
	return get_Matchable_Object(pos);
	
}
*/

// in: List that contains
/*
Matchable_Object& List::operator[](const List& L)
{
	
}
*/


/*
bool List::operator==(const List& L)
{
	for (int i = 0; i < N; i++)
	{
		if (!(m_List[i] == L.m_List[i]))
		{
			return false;
		}
	}

	return true;
}
*/

// output-----------------------------------------------------------------------------
void List::print()
{
	for (int i = 0; i < N; i++)
	{
		m_List[i].print();
		cout << endl;
	}
}