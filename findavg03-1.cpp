#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string> 
using namespace std;

#include "credit.cpp" // Assuming the CreditRecord class is defined in "credit 1.cpp"

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

  srand(42);				// Seed the random number generator

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
      if ( people[i] == people[j] ) {
          cout << "people" << i << " and people" << j << " are equal:" << endl;

          cout << people[i];
	  cout << endl;
          cout << people[j];
	  cout << endl;
	  cout << endl;

      }
    }
  
  // These calls to input( ) and output( ) can be used to overload
  // into using operator>> and operator<<.

  cout << "Just for testing purposes, I'm asking for a new person." << endl;
  cin >> newPerson;
  cout << "You told me:" << endl;
  cout << newperson;
  cout << endl;
  cout << endl;



  // These can also be used for overloaded input and output operators.
  //
  cout << "Before operator=," << people[5] << "and" << newperson << "contain:" << endl;
  cout << people[5];
  cout << endl;
  cout << newperson;
  cout << endl;
  cout << endl;

  // Here's where you'd overload the assignment operator. Note
  // that this already works, but not the way it's specified
  // in the exercise.

  // Overloaded assignment operator
    CreditRecord& operator=(const CreditRecord &other) {
        if (this != &other) {  // Check for self-assignment
            this->Naccts = other.Naccts;  // Copy the number of accounts
            this->score = other.score;    // Copy the credit score
            // Do NOT copy lname and fname
        }
        return *this;
    }
  people[5] = newperson;

  cout << "After operator=, "<< people[5]<< "and" <<newperson<< "contain:" << endl;
  cout << people[5];
  cout << endl;
  cout << newperson;
  cout << endl;



  return 0;
}

