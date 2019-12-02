#ifndef GALE_SHAPLEY_H
#define GALE_SHAPLEY_H

#include "List_Of_Matching_Objects.h"
using namespace std;

// Gale-Shapley Algorithm
// in: L1, L2
// out: write to cout the pairs engaged / return set S (array of tuples?)
class Gale_Shapley
{
public:
	Gale_Shapley();
	~Gale_Shapley();

	// accessors
	List& get_L1();
	List& get_L2();

	bool all_are_free(List& L);
	unsigned there_exists_a_free_man(List& L);	
	bool has_not_proposed_to_every_woman(unsigned id);
	bool has_not_proposed_to_this_woman(Matchable_Object& MO, unsigned id);
	bool prefers(Matchable_Object& MO, unsigned id1, unsigned id2); // w1 > w2 > ..., m1 > m2 > ...

	void propose(unsigned id);
	void become_engaged(unsigned id1, unsigned id2);
	void become_free(unsigned id, bool gender);

	void Stable_Matching(List& L1, List& L2);
private:
	List L1, L2;
};

#endif // GALE_SHAPLEY_H