#ifndef MATCHABLE_OBJECT_H
#define MATCHABLE_OBJECT_H

#include "constants.h"
#include <vector>

class Matchable_Object
{
public:
	// constructors
	Matchable_Object();

	// destructor
	~Matchable_Object();

	// mutators
	void set_PrefList(unsigned* pref_list);
	void set_id(unsigned id);
	void set_so_id(unsigned so_id);

	//void set_Proposal(unsigned id); // move this up an abstraction
	unsigned set_manProposal(); // helper ^^
	void     set_womanProposal(unsigned id); // helper ^^
	unsigned get_highest_ranked_woman() const;

	// accessors
	unsigned* get_PrefList();
	unsigned  get_id() const;
	unsigned  get_so_id() const;
	bool*     get_Proposals();
	unsigned  get_proposal_count() const;

	// conditionals
	bool is_free() const;

	// output
	void print();

	// overloaded operators
	Matchable_Object& operator=(const Matchable_Object& MO);
	bool operator==(const Matchable_Object& MO);

private:
	unsigned m_pref_list[N]; // m_pref_list[i] = 0 uninitialized
	unsigned m_id;           // m_id = 0 uninitialized, m_id > 0 otherwise
	unsigned m_so_id;        // m_so_id = 0 if m_id is free,
	                         // m_so_id > 0 if m_id is engaged

	bool     m_proposals[N];
	unsigned m_proposal_count;
};



#endif // MATCHABLE_OBJECT_H