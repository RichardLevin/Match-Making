#include "Gale_Shapley.h"
#include <cassert>

Gale_Shapley::Gale_Shapley()
{
}

Gale_Shapley::~Gale_Shapley()
{
}

bool Gale_Shapley::all_are_free(List& L)
{
	for (int i = 0; i < N; i++)
	{
		if (! L.get_Matchable_Object(i).is_free())
		{
			return false;
		}
	}

	return true;
}

List& Gale_Shapley::get_L1()
{
	return L1;
}

List& Gale_Shapley::get_L2()
{
	return L2;
}

/*
Matchable_Object& Gale_Shapley::highest_ranked_woman(unsigned id)
{
	unsigned i = 0;
	while (get_L1().get_Matchable_Object(id - 1).get_Proposals()[i] != false && i < N)
	{
		i++;
	}

	return get_L2().get_Matchable_Object(i + 1);
}
*/

unsigned Gale_Shapley::there_exists_a_free_man(List& L)
{
	unsigned i = 0;
	while (i < N && ! L.get_Matchable_Object(i).is_free())
	{
		i++;
	}

	if (i == N)
	{
		return 0;
	}
	else
	{
		return i + 1;
	}
}

bool Gale_Shapley::has_not_proposed_to_every_woman(unsigned id)
{
	return get_L1().get_Matchable_Object(id - 1).get_proposal_count() < N;
}

bool Gale_Shapley::has_not_proposed_to_this_woman(Matchable_Object& MO, unsigned id)
{
	unsigned i = 0;
	while (MO.get_PrefList()[i] != id && i < N)
	{
		i++;
	}

	return !!MO.get_PrefList()[i] != MO.get_Proposals()[i];
}

bool Gale_Shapley::prefers(Matchable_Object& MO, unsigned id1, unsigned id2)
{
	unsigned i = 0;
	while (MO.get_PrefList()[i] != id1 && i < N)
	{
		i++;
	}
	
	unsigned j = 0;
	while (MO.get_PrefList()[j] != id2 && j < N)
	{
		j++;
	}

	return i < j;
}

void Gale_Shapley::propose(unsigned id)
{
	if (get_L1().get_Matchable_Object(id - 1).get_proposal_count() >= N)
	{
		return;
	}

	unsigned p_id = get_L1().get_Matchable_Object(id - 1).set_manProposal();
	get_L2().get_Matchable_Object(p_id - 1).set_womanProposal(id);
}

void Gale_Shapley::become_engaged(unsigned id1, unsigned id2)
{
	get_L1().get_Matchable_Object(id1 - 1).set_so_id(id2);
	get_L2().get_Matchable_Object(id2 - 1).set_so_id(id1);
}

void Gale_Shapley::become_free(unsigned id, bool gender) // 1 for male, 0 for female
{
	if (gender)
	{
		get_L1().get_Matchable_Object(id - 1).set_so_id(0);
	}
	else // is female
	{
		get_L2().get_Matchable_Object(id - 1).set_so_id(0);
	}
}






void Gale_Shapley::Stable_Matching(List& L1, List& L2)
{
	assert(all_are_free(L1) && all_are_free(L2));

	while (there_exists_a_free_man(L1) && has_not_proposed_to_every_woman(there_exists_a_free_man(L1)))
	{
		unsigned id = there_exists_a_free_man(L1);
		unsigned x_id = get_L1().get_Matchable_Object(id - 1).get_highest_ranked_woman(); // highest-ranked woman to whom m has not yet proposed

		propose(id);

		if (L2.get_Matchable_Object(x_id - 1).is_free())
		{
			become_engaged(id, x_id);
		}
		else // w is currently engaged to m'
		{
			if (prefers(L2.get_Matchable_Object(x_id - 1), L2.get_Matchable_Object(x_id - 1).get_so_id(), id))
			{
				// m remains free
			}
			else // w prefers m to m'
			{
				become_free(get_L2().get_Matchable_Object(x_id - 1).get_so_id(), 1);
				become_engaged(id, x_id);
			}
		}
	}
}