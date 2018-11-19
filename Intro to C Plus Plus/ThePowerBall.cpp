/*
This program is used to calculate Powerball winners
Written by Tanner Blomster
v1.0 - Initial Write
*/


#include <iostream>
#include <ctime>
#include <time.h>
#include <stdlib.h>
using namespace std;


// Generate powerball main numbers function prototype
void genRandoNums(int[], int, int);
// Generate The Powerball
int genRandoNum(int);
// User picks function prototype
void getUserNums(int[], int, int, int);
// Processing function prototype
int compareNums(int[], int [], int);
// Powerball Win check prototype
bool powerBallWin(int [], int, int);
// Display the Powerball generated numbers
void displayPbPicks(int [], int, int);
// Calculate monetary reward prototype
void rewardCalc(int, bool);

int main()
{
    // Highest and lowest acceptable numbers
    const int randMax = 99;
    const int randMin = 1;
    
    // Create The Powerball
    int thePowerBall;

    // Amount of numbers to generate
    int size = 5;

    // Hold how many matches there were
    int matches = 0;

    // Initial var to store if the user pick last number matches the Powerball
    bool lastmatch = false;

    // Create Power Ball number list with 5 numbers
    int pbNums[size];
    int userNums[size];

    // Generate 5 random numbers
    genRandoNums(pbNums, size, randMax);
    
    // Generate Powerball
    thePowerBall = genRandoNum(randMax);

    // Get the user picks
    getUserNums(userNums, size, randMin, randMax);
    
    // Calculate how many matches there are
    matches = compareNums(userNums, pbNums, size);
    
    // Check to see if the last user pick matches our Powerball
    lastmatch = powerBallWin(userNums, thePowerBall, size);

    // Display the Powerball main numbers and the Powerball
    displayPbPicks(pbNums, thePowerBall, size);

    // Output reward messages
    rewardCalc(matches, lastmatch);

    return 0;
}


// Generate five random numbers function
void genRandoNums(int numlist[], int size, int maximum)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        numlist[i] = rand() % maximum + 1;
    }
}

// Generate and output random number function
int genRandoNum(int maximum)
{
    // Keep commented if srand was called before
    //srand(time(0));
    return rand() % maximum + 1;
}

// User picks function function
void getUserNums(int numlist[], int size, int minimum, int maximum)
{
    int num;
    int i = 0;
    while (i < size)
    {
        cout << "Please choose a number for slot " << i + 1 << ":" << endl;
        cin >> num;
        // Check if user input was in the valid range
        if (num <= maximum && num >= minimum)
        {
            numlist[i] = num;
            i++;
        }
        // If number was too high or to low, don't increment i so the number is replaced
        else
        {
            cout << "You enter too high a number!" << endl;
            cout << "Please enter a number lower than " << maximum << endl;
            cout << "and higher than " << minimum << endl;
        }
    }
}

// Processing function prototype
int compareNums(int numlist1[], int numlist2[], int size)
{
    int matches = 0;
    // For each value at position in numlist1, search every position of numlist2 for a match
    // If match is found, keep a tally
    for (int index1 = 0; index1 < size; index1++)
    {
        for (int index2 = 0; index2 < size; index2++)
        {
            if (numlist1[index1] == numlist2[index2])
            {
                matches++;
            }
        }
    }
    return matches;
}

// See if the last number that user picks matches the last number we generated
bool powerBallWin(int userNums[], int thePowerBall, int size)
{
    // Need to use - 1 since we start at position 0
    if (userNums[size - 1] == thePowerBall)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void displayPbPicks(int pbNums[], int thePowerBall, int size)
{
    cout << "The numbers are:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << pbNums[i] << "  ";        
    }
    cout << endl << "And the Powerball pick is: " << thePowerBall << endl;
}

void rewardCalc(int matches, bool lastmatch)
{
    switch (matches)
    {
        case 0:
            if (lastmatch == true)
            {
                cout << "You've won $10 for getting the Powerball! Congratulations!" << endl;
            }
            else
            {
                cout << "Unfortunately, you did not match any numbers. Good luck, next time!" << endl;
            }
            break;
        case 1:
            if (lastmatch == true)
            {
                cout << "You've won $25 for matching one number and the Powerball! Congratulations!" << endl;
            }
            else
            {
                cout << "You've won $5 for matching one number! Congratulations!" << endl;
            }
            break;
        case 2:
            if (lastmatch == true)
            {
                cout << "You've won $75 for matching two numbers and getting the Powerball! Congratulations!" << endl;
            }
            else
            {
                cout << "You've won $15 for matching two numbers! Congratulations!" << endl;
            }
            break;
        case 3:
            if (lastmatch == true)
            {
                cout << "You've won $200 for matching three numbers and getting the Powerball! Congratulations!" << endl;
            }
            else
            {
                cout << "You've won $50 for matching three numbers! Congratulations!" << endl;
            }
            break;
        case 4:
            if (lastmatch == true)
            {
                cout << "You've won $1,000 for matching four numbers and getting the Powerball! Congratulations!" << endl;
            }
            else
            {
                cout << "You've won $100 for matching four numbers! Congratulations!" << endl;
            }
            break;
        case 5:
            if (lastmatch == true)
            {
                cout << "You've won $50,000 for matching five numbers and getting the Powerball! Congratulations!" << endl;
            }
            else
            {
                cout << "You've won $500 for matching five numbers! Congratulations!" << endl;
            }
            break;
    }

}
