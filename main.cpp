// Richard Levin, all rights reserved (C)
// 11/11/2019
// Test Drive

// 11/17/2019 UI for Gale Shapley class ->            FINISHED
// 11/18/2019 Design Stable_Matching -> INCOMPLETE -> FINISHED
// 11/21/2019 Implement Stable Matching ->            FINISHED
// 11/22/2019 FULLY TESTED GS ->                      FINISHED
// 11/26/2019 EXPANDING w/ SQL DATABASE SERVER

#include <cassert>

#include <iostream>
using namespace std;

#include "Gale_Shapley.h"
#include "constants.h"

int main()
{
	// read from file. . .or sql database
	Gale_Shapley GS;

	assert(GS.all_are_free(GS.get_L1()));
	assert(GS.there_exists_a_free_man(GS.get_L1()));
	//assert(GS.has_not_proposed_to_every_woman(GS.get_L1().get_Matchable_Object(0)));

	Matchable_Object MO; // external variable

	unsigned pref_lists1[N][N] = {
		{ 4, 2, 3, 1, 5 },
		{ 5, 3, 2, 1, 4 },
		{ 2, 5, 1, 4, 3 },
		{ 5, 2, 4, 3, 1 },
		{ 4, 1, 2, 3, 5 }
	};

	unsigned pref_lists2[N][N] = {
		{ 4, 2, 5, 3, 1 },
		{ 2, 1, 4, 3, 5 },
		{ 1, 3, 5, 4, 2 },
		{ 4, 1, 3, 2, 5 },
		{ 2, 5, 1, 3, 4 }
	};


	for (int i = 0; i < N; i++)
	{
		MO.set_id(i + 1);
		MO.set_so_id(0);
		MO.set_PrefList(pref_lists1[i]);
		GS.get_L1().set_Matchable_Object(i, MO);
	}
	for (int i = 0; i < N; i++)
	{
		MO.set_id(i + 1);
		MO.set_so_id(0);
		MO.set_PrefList(pref_lists2[i]);
		GS.get_L2().set_Matchable_Object(i, MO);
	}

	assert(MO.is_free());


	GS.get_L1().print(); cout << endl;
	GS.get_L2().print(); cout << endl;

	cout << "----------------------------------\n\n";

	//------------------------------------------------------------------------------
	// Testing UI

	/*
	for (int i = 0; i < N; i++)
	{
		GS.propose(i + 1);
	}

	for (int i = 0; i < N; i++)
	{
		if (i < 2)
		{
			GS.propose(1);
		}
		else
		{
			GS.propose(4);
		}
	}
	*/

	GS.Stable_Matching(GS.get_L1(), GS.get_L2());
	


	// TESTING STABLE MATCHING - FINISHED

	


	GS.get_L1().print(); cout << endl;
	GS.get_L2().print(); cout << endl;

	//------------------------------------------------------------------------------


	GS.~Gale_Shapley();
}

// Some initial tests.
/*
	Matchable_Object m; // m E M

	m.print(); cout << endl;

	int pref_list[N] = { 1, 2, 3, 4, 5 };
	m.set_PrefList(pref_list);
	m.set_isFree(false); // is engaged
	m.print(); cout << endl;
	m.~Matchable_Object();

	cout << endl;

	List L1;
	L1.print();
	L1.~List();
*/

// Matchable_Object class tested.
/*
	Matchable_Object m;

	assert(m.get_id() == 0);    // checked
	assert(m.get_so_id() == 0); // checked
	assert(m.is_free() == 0);   // checked
	for (int i = 0; i < N; i++)
	{
		assert(m.get_PrefList()[i] == 0);
	}

	m.set_id(1);
	assert(m.get_id() == 1);

	m.set_so_id(5);
	assert(m.get_so_id() == 5);
	assert(m.is_free() == 1);

	unsigned pref_list[N] = { 1, 2, 3, 4, 5 };
	m.set_PrefList(pref_list);
	for (int i = 0; i < N; i++)
	{
		assert(m.get_PrefList()[i] == pref_list[i]);
	}

	m.print();
	m.~Matchable_Object();
*/

/*
	/*
	// Finalize List interface and test.
	List L1, L2;

	Matchable_Object MO;

	unsigned pref_lists1[N][N] = {
		{ 1, 2, 3, 4, 5 },
		{ 3, 2, 4, 5, 1 },
		{ 2, 4, 5, 3, 1 },
		{ 4, 5, 3, 2, 1 },
		{ 5, 4, 3, 2, 1 }
	};

	unsigned pref_lists2[N][N] = {
		{ 2, 3, 4, 5, 1 },
		{ 1, 2, 3, 4, 5 },
		{ 3, 5, 4, 2, 1 },
		{ 1, 2, 3, 4, 5 },
		{ 5, 1, 4, 2, 3 }
	};


	for (int i = 0; i < N; i++)
	{
		MO.set_id(i + 1);
		MO.set_so_id(0);
		MO.set_PrefList(pref_lists1[i]);
		L1.set_Matchable_Object(i, MO);
	}
	for (int i = 0; i < N; i++)
	{
		MO.set_id(i + 1);
		MO.set_so_id(0);
		MO.set_PrefList(pref_lists2[i]);
		L2.set_Matchable_Object(i, MO);
	}



	L1.print(); cout << endl;
	L2.print(); cout << endl;

	L1.~List();
	L2.~List();
*/