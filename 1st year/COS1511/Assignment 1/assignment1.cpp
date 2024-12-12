#include <iostream>
using namespace std;

int main()
{       //Variables
        int votesForA = 0, votesForB = 0, votesForC = 0, spoiltVotes = 0;
        int i;
        char voteOption;

        //Start of for loop
        for(i = 1; i<5; i++ )
        {
            cout << "Please enter votes for voting station " << i << endl;
            //Start of while loop to get input
            while(voteOption != 'X' && voteOption != 'x')
        {
            cout << "Please enter which candidate you want to vote for using 'A', 'B' or 'C', 'X' terminates voting: " << endl;
            cin >> voteOption;
            cout << endl;
            //Start of switch statement to assign votes gotten from input to variables
            switch(voteOption)

      {

        case 'A':
        case 'a': votesForA++;
            break;

        case 'B':
        case 'b': votesForB++;
            break;

        case'C':
        case'c': votesForC++;
            break;

        default: if (voteOption != 'X' && voteOption != 'x')
                    spoiltVotes++;
            break;

        }
        }
            //voteOption is assigned to 'Z' so when user chooses 'X' it doesnt skip the rest of the voting stations it reinitializes the voteOption variable
            voteOption='Z';

        }
            //Displaying output
            cout << "Total number of votes for candidate A = " << votesForA << endl;
            cout << "Total number of votes for candidate B = " << votesForB << endl;
            cout << "Total number of votes for candidate C = " << votesForC << endl;
            cout << "Total spoilt votes = " << spoiltVotes << endl;

        return 0;
}
