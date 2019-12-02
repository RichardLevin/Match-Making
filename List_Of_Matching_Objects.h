#ifndef LIST_OF_MATCHING_OBJECTS_H
#define LIST_OF_MATCHING_OBJECTS_H

#include "Matchable_Object.h"


// User Interface for Gale-Shapley Algorithm
class List
{
public:
	// constructors
	List();

	// destructor
	~List();

	// mutators
	bool set_Matchable_Object(unsigned pos, Matchable_Object& MO); // where MO is an external variable

	// accesors
	Matchable_Object& get_Matchable_Object(unsigned pos); // where MO is an external variable

	// conditionals
	bool contains(unsigned pos, const Matchable_Object& MO);

	// overloaded operators
	//Matchable_Object& operator[](unsigned pos);
	//bool operator==(const List& L);

	// output
	void print();
	 
	
private:
	Matchable_Object m_List[N];
};

/*
	// Functionality to be implemented.

	// mutators
	void set_PrefList(unsigned* pref_list);
	void set_id(unsigned id);
	void set_so_id(unsigned so_id);

	// accessors
	unsigned* get_PrefList();
	unsigned get_id() const;
	unsigned get_so_id() const;

	// conditionals
	bool is_free() const;

	// overloaded operators
	Matchable_Object& operator=(const Matchable_Object& MO);
*/


#endif // LIST_OF_MATCHING_OBJECTS_H