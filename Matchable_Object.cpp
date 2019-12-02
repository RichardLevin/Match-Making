#include "Matchable_Object.h"
#include "constants.h"
#include <vector>
#include <iostream>
using namespace std;

// constructors-----------------------------------------------------------------------------
Matchable_Object::Matchable_Object()
	: m_id(0), m_so_id(0), m_proposal_count(0)
{
	for (int i = 0; i < N; i++)
	{
		m_pref_list[i] = 0;
		m_proposals[i] = false;
	}
}

// destructor-----------------------------------------------------------------------------
Matchable_Object::~Matchable_Object()
{
}

// mutators-----------------------------------------------------------------------------
void Matchable_Object::set_PrefList(unsigned* pref_list)
{
	for (int i = 0; i < N; i++)
	{
		m_pref_list[i] = pref_list[i];
	}
}

void Matchable_Object::set_id(unsigned id)
{
	m_id = id;
}

void Matchable_Object::set_so_id(unsigned so_id)
{
	m_so_id = so_id;
}

unsigned Matchable_Object::set_manProposal()
{

	// 1 1 0 0 0 (trailing 0s format)

	unsigned i = 0;
	while (m_proposals[i] != false && i < N)
	{
		i++;
	}
	m_proposals[i] = true;

	m_proposal_count++;

	return m_pref_list[i]; // return highest-ranked woman to whom m has not yet proposed
}

unsigned Matchable_Object::get_highest_ranked_woman() const
{
	unsigned i = 0;
	while (m_proposals[i] != false && i < N)
	{
		i++;
	}

	if (i == N)
	{
		return 0;
	}
	else
	{
		return m_pref_list[i]; // strictly returns highest-ranked woman to whom m has not yet proposed
	}
}

void Matchable_Object::set_womanProposal(unsigned id) // can't be generic id, must be = highest-ranked w's id of m not proposed to yet
{
	// 0 0 1 0 1 (hash format)

	if (! is_free())
	{
		return;
	}

	unsigned i = 0;
	while (m_pref_list[i] != id && i < N)
	{
		i++;
	}

	m_proposals[i] = true;

	m_proposal_count++;
 }

/* // move this up an abstraction
void Matchable_Object::set_Proposal(unsigned id)
{
	set_manProposal();
	set_womanProposal(id);
}
*/

// accessors-----------------------------------------------------------------------------
unsigned* Matchable_Object::get_PrefList()
{
	return m_pref_list;
}

unsigned Matchable_Object::get_id() const
{
	return m_id;
}

unsigned Matchable_Object::get_so_id() const
{
	return m_so_id;
}

bool* Matchable_Object::get_Proposals()
{
	return m_proposals;
}

unsigned Matchable_Object::get_proposal_count() const
{
	return m_proposal_count;
}

// conditionals-----------------------------------------------------------------------------
bool Matchable_Object::is_free() const
{
	return !m_so_id;
}

// overloaded operators
Matchable_Object& Matchable_Object::operator=(const Matchable_Object& MO)
{
	m_id = MO.m_id;
	m_so_id = MO.m_so_id;
	for (int i = 0; i < N; i++)
	{
		m_pref_list[i] = MO.m_pref_list[i];
	}
	return *this;
}

bool Matchable_Object::operator==(const Matchable_Object& MO)
{
	if (m_id != MO.m_id || m_so_id != MO.m_so_id)
	{
		return false;
	}

	for (int i = 0; i < N; i++)
	{
		if (m_pref_list[i] != MO.m_pref_list[i])
		{
			return false;
		}
	}

	return true;
}

// output-----------------------------------------------------------------------------
void Matchable_Object::print()
{
	cout << m_id << ": ";
	for (int i = 0; i < N - 1; i++)
	{
		cout << m_pref_list[i] << ' ';
	}
	cout << m_pref_list[N - 1];

	cout << " | ";

	for (int i = 0; i < N - 1; i++)
	{
		cout << m_proposals[i] << ' ';
	}
	cout << m_proposals[N - 1];

	cout << " | ";

	cout << m_so_id;
}