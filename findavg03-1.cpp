#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

#include "credit.cpp"

//*******************************************************************
// This program just does a find average from values generated into
// an array of float.
//*******************************************************************
int main( )
{

  CreditRecord people[20];		// 20 simulated people's credit records
  CreditRecord newperson;
  int i, j;				// iterator variables.
  int lidx;				// last name index
  int fidx;				// first name index

  string lnames[10] = {"Johnson","Jones","Anderson","Chester","Edwards","Smith","Eaton","Jackson","Sinjinfrinjinson","Doe"};
  string fnames[10] = {"Sia","Michael","Ophelia","Aloysius","Mergatroid","Winona","Tedrick","Harold","Ula","Joe"};

  srand(42);

  for (i = 0; i < 20; i++) {
    cout << "For person " << setw(2) << i << ", ";
    people[i].EconomicActivity();
    people[i].printScore();

    lidx = (int) (10.0 * (rand() / (RAND_MAX + 1.0)));
    fidx = (int) (10.0 * (rand() / (RAND_MAX + 1.0)));

    people[i].setLname(lnames[lidx]);
    people[i].setFname(fnames[fidx]);
  }

  // Find and print the average score.

  cout << endl;
  CreditRecord::findAvg();
  CreditRecord::printAvg();
  cout << endl << endl;

  
  //*******************************************************************
  // Now, let's find all pairs of scores that are equal.  Requires
  // an overloaded operator ==. Or an isEqual function.
  //
  // the cout statement nested in the if, nested in the loops, has a deliberate
  // typo with the name of the array.  Change a[i] to people[i] in the
  // cout statements, and watch the error messages explode.
  //*******************************************************************
  for (i = 0; i < 20; i++)
    for (j = i+1; j < 20; j++) {
      if (isEqual(people[i],people[j])) {
          cout << "people[" << i << "] and people[" << j << "] are equal:" << endl;

          people[i].output();
	  cout << endl;
          people[j].output();
	  cout << endl;
	  cout << endl;

      }
    }
  
  // These calls to input( ) and output( ) can be used to overload
  // into using operator>> and operator<<.

  cout << "Just for testing purposes, I'm asking for a new person." << endl;
  newperson.input();
  cout << "You told me:" << endl;
  newperson.output();
  cout << endl;
  cout << endl;

  // These can also be used for overloaded input and output operators.
  //
  cout << "Before operator=, people[5] and newperson contain:" << endl;
  people[5].output();
  cout << endl;
  newperson.output();
  cout << endl;
  cout << endl;

  // Here's where you'd overload the assignment operator. Note
  // that this already works, but not the way it's specified
  // in the exercise.
  people[5] = newperson;

  cout << "After operator=, people[5] and newperson contain:" << endl;
  people[5].output();
  cout << endl;
  newperson.output();
  cout << endl;

  return 0;
}

