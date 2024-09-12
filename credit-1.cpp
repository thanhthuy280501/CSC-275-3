//*********************************
// This is the credit record file.
//*********************************
class CreditRecord {
  public:
    CreditRecord();		// initialize my score to 0.

    void EconomicActivity();	// simulate a year of credit activity
    void printScore();		// prints the credit score
    static void findAvg();	// finds the average credit score in the
				// population, assigns to avg_score

    static void printAvg();	// prints the average credit score

    int getScore() const { return score; }	// return the score
    string getLname() const { return lname; }	// return the lname
    string getFname() const { return fname; }	// return the fname
    int getNaccts() const { return Naccts; }	// return the # of accts

    void setLname(string);
    void setFname(string);

    void output( );		// This prints the person's record
    void input( );		// This reads the person's record

// Here's a freebie: this operator<< would replace the output() function
// the overloaded operator>> declaration is somewhat similar
//
//   friend ostream& operator<<(ostream&, const CreditRecord&);

  private:
    string lname;		// Last name
    string fname;		// First name
    int Naccts;			// Number of credit accounts
    int score;			// A number between 300 and 850,
				// according to the Goog.

    // Static class variables:

    static int avgScore;	// Since the FICO and Vantage scores are
				// integers, we'll keep this as an int
				// and just use truncating/rounding maths.

    static int totalOfScores;	// total of scores, used in computing the
				// average

    static int nScores;		// How many credit records there are
};

int CreditRecord::avgScore = 0;	// this needs to be done once, and only once
int CreditRecord::totalOfScores = 0;
int CreditRecord::nScores = 0;

// This is where the implementation starts

//*********************************************************************
// Construct the credit record.  The baseline score is 300, from which
// the economic activity will modify the score.  The number of accounts
// this person has is always assumed to be 10, for this demo program.
//*********************************************************************
CreditRecord::CreditRecord() : score(300), Naccts(10) {}

//*********************************************************************
// This simulates a 12-month period of economic activity for
// a person who has 10 credit accounts.  Every time they make
// an on-time payment, it adds 4 points to their score.  Every
// time they make a late payment, it subtracts 10 points.  Every
// time they miss a payment (mutually exclusive to the above two),
// it subtracts 30 points from their score.
//*********************************************************************
void CreditRecord::EconomicActivity() {

  int i, j;
  int month;
  int miss;
  int late;

  nScores++;			// I am another person, so increment the
				// number of scores static class variable

  //******************************************************************
  // Each month:  each payment made on-time represents a +4 to their
  //              credit score.
  //
  //              Each missed payment represents a -30
  //              Each late payment represents a -10
  //******************************************************************
  for (month = 1; month <= 12; month++) {
    for (i = 0; i < Naccts; i++) {

    // Compute two rand values between 1 and 100, to determine a
    // probability.  Probability of missing payment:  2 %
    // Probability of late payment:  4%.  Don't penalize for both.

      miss = 1 + (int) (100.0 * (rand() / (RAND_MAX + 1.0)));
      late = 1 + (int) (100.0 * (rand() / (RAND_MAX + 1.0)));

      if (late <= 4) {		// late pmt
        score = score - 10;
      }
      else if (miss <= 2) {	// missed pmt
        score = score - 30;
      }
      else score = score + 4;	// good pmt
    }
  }
  totalOfScores += score;	// adding my score to the static class
				// variable totalOfScores
}

//*********************************************************************
// Just prints out the credit score for a credit record
//*********************************************************************
void CreditRecord::printScore() {
  cout << "individual credit score is " << score << endl;
}

void CreditRecord::findAvg() {
  CreditRecord::avgScore = totalOfScores / nScores;
}

void CreditRecord::printAvg() {
  cout << "The average credit score is " << CreditRecord::avgScore << endl;
}

void CreditRecord::setLname(string inLname) {
  lname = inLname;
}

void CreditRecord::setFname(string inFname) {
  fname = inFname;
}


//*********************************************************
// This is already "not a friend or member of the class".
//*********************************************************
bool isEqual(const CreditRecord &c1, const CreditRecord &c2) {
  return (c1.getScore() == c2.getScore());
}


void CreditRecord::output( ) {
  cout << lname << ", " << fname << ", no. of accounts " << Naccts << ", and credit score " << score;
}

void CreditRecord::input( ) {
  cout << "Last name? ";
  cin >> lname;
  cout << "First name? ";
  cin >> fname;
  cout << "No. of accounts? ";
  cin >> Naccts;
  cout << "Initial credit score? ";
  cin >> score;
}
