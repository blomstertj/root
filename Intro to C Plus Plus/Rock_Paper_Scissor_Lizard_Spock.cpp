/* Rock/Paper/Scissors/Spock/Lizard
   Written by Tanner Blomster
   v1.0 - Initial Write
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    char startGame;
    char playAgain;
    unsigned int professorChoice;
    unsigned int joshuaChoice;
    double professorWins = 0.0;
    double professorLosses = 0.0;
    double joshuaWins = 0.0;
    double joshuaLosses = 0.0;
    double draws = 0.0;

    cout << "Greetings Professor Falken" << endl;
    cout << "Shall we play a game? (Y/N)" << endl;
    cin >> startGame;

    if (startGame == 'Y' || startGame == 'y') 
    {
        while (playAgain != 'N' && playAgain != 'n')
        {
            // Available options display:
            cout << "Choices:" << endl;
            cout << setw(10) << "(1) ROCK" << setw(15) << "(2) PAPER" << setw(10) << endl;
            cout << setw(10) << "(3) SCISSORS" << setw(15) << "(4) LIZARD" << setw(10) << endl;
            cout << setw(17) << "(5) SPOCK" << setw(17) << endl;
            cout << endl;
            cout << "Enter your choice:" << endl;

            // Store Professor's choice
            cin >> professorChoice;
            // Validate Professor's choice. If valid then continue game
            if (professorChoice >= 1 && professorChoice <= 5)
            {
                // Randomize Joshua's choice
                srand(time(0));
                joshuaChoice = rand() % 5 + 1;

                switch (professorChoice)
                {
                    case 1:
                        cout << "You chose ROCK" << endl;
                        switch (joshuaChoice)
                        {
                            case 1:
                               // Rock vs Rock = Draw
                               cout << "I chose rock too" << endl;
                               cout << "It's a draw!" << endl;
                               draws++;
                               break;
                            case 2:
                               // Rock vs Paper = Loss
                               cout << "Booyah! Paper covers rock!" << endl;
                               cout << "You lose!" << endl;
                               professorLosses++;
                               joshuaWins++;
                               break;
                            case 3:
                               // Rock vs Scissors = Win
                               cout << "Noooo! My beautiful scissors..." << endl;
                               cout << "You win!" << endl;
                               professorWins++;
                               joshuaLosses++;
                               break;
                            case 4:
                               // Rock vs Lizard = Win
                               cout << "Now how will I get car insurance?" << endl;
                               cout << "You win!" << endl;
                               professorWins++;
                               joshuaLosses;
                               break;
                            case 5:
                                // Rock vs Spock = Loss
                                cout << "*rock vaporizes instantly*" << endl;
                                cout << "It was logical." << endl;
                                cout << "You lose!" << endl;
                                professorLosses++;
                                joshuaWins++;
                                break;
                        }
                        break;
                    case 2:
                        cout << "You chose PAPER" << endl;
                        switch (joshuaChoice)
                        {
                            case 1:
                                // Paper vs Rock = Win
                                cout << "What? Where'd my rock go?" << endl;
                                cout << "You win!" << endl;
                                professorWins++;
                                joshuaLosses++;
                                break;
                            case 2:
                                // Paper vs Paper = Draw
                                cout << "Thick enough for a resume" << endl;
                                cout << "It's a draw!" << endl;
                                draws++;
                                break;
                            case 3:
                                // Paper vs Scissors = Loss
                                cout << "Your paper is in a million pieces" << endl;
                                cout << "You lose!" << endl;
                                professorLosses++;
                                joshuaWins++;
                                break;
                            case 4:
                                // Paper vs Lizard = Loss
                                cout << "Om nom nom, your paper is eaten" << endl;
                                cout << "You lose!" << endl;
                                professorLosses++;
                                joshuaWins++;
                                break;
                            case 5:
                                // Paper vs Spock = Win
                                cout << "My logic is illogical? How can this be?!" << endl;
                                cout << "You win!" << endl;
                                professorWins++;
                                joshuaLosses++;
                                break;
                        }
                        break;
                    case 3:
                        cout << "You chose SCISSORS" << endl;
                        switch (joshuaChoice)
                        {
                            case 1:
                                // Scissors vs Rock = Loss
                                cout << "Rock crush you!" << endl;
                                cout << "You lose!" << endl;
                                professorLosses++;
                                joshuaWins++;
                                break;
                            case 2:
                                // Scissors vs Paper = Win
                                cout << "You cut up my resume!" << endl;
                                cout << "You win!" << endl;
                                professorWins++;
                                joshuaLosses++;
                                break;
                            case 3:
                                // Scissors vs Scissors = Draw
                                cout << "The scissor match just made them both dull" << endl;
                                cout << "It's a draw!" << endl;
                                draws++;
                                break;
                            case 4:
                                // Scissors vs Lizard = Win
                                cout << "You murdered my lizard!" << endl;
                                cout << "You win!" << endl;
                                professorWins++;
                                joshuaLosses++;
                                break;
                            case 5:
                                // Scissors vs Spock = Loss
                                cout << "It was logical." << endl;
                                cout << "You lose!" << endl;
                                professorLosses++;
                                joshuaWins++;
                                break;
                        }
                        break;
                    case 4:
                        cout << "You chose LIZARD" << endl;
                        switch (joshuaChoice)
                        {
                            case 1:
                                // Lizard vs Rock = Loss
                                cout << "Your lizard was squashed" << endl;
                                cout << "You lose!" << endl;
                                professorLosses++;
                                joshuaWins++;
                                break;
                            case 2:
                                // Lizard vs Paper = Win
                                cout << "Your lizard ate my homework" << endl;
                                cout << "You win!" << endl;
                                professorWins++;
                                joshuaLosses++;
                                break;
                            case 3:
                                // Lizard vs Scissors = Loss
                                cout << "Snipped your little gecko" << endl;
                                cout << "You lose!" << endl;
                                professorLosses++;
                                joshuaWins++;
                                break;
                            case 4:
                                // Lizard vs Lizard = Draw
                                cout << "The lizards fell in love" << endl;
                                cout << "It's a draw!" << endl;
                                draws++;
                                break;
                            case 5:
                                // Lizard vs Spock = Win
                                cout << "argh... how can this be?  My death is, at least, logical." << endl;
                                cout << "You win!" << endl;
                                professorWins++;
                                joshuaLosses++;
                                break;
                        }
                        break;
                    case 5:
                        cout << "You chose SPOCK" << endl;
                        switch (joshuaChoice)
                        {
                            case 1:
                                // Spock vs Rock = Win
                                cout << "*rock explodes* My... rock!" << endl;
                                cout << "You win!" << endl;
                                professorWins++;
                                joshuaLosses++;
                                break;
                            case 2:
                                // Spock vs Paper = Loss
                                cout << "Your logic is false!" << endl;
                                cout << "You lose!" << endl;
                                professorLosses++;
                                joshuaWins++;
                                break;
                            case 3:
                                // Spock vs Scissors = Win
                                cout << "My scissors... how?!" << endl;
                                cout << "You win!" << endl;
                                professorWins++;
                                joshuaLosses++;
                                break;
                            case 4:
                                // Spock vs Lizard = Loss
                                cout << "Feeling a little light headed?" << endl;
                                cout << "You lose!" << endl;
                                professorLosses++;
                                joshuaWins++;
                                break;
                            case 5:
                                // Spock vs Spock = Draw
                                cout << "We are both logical." << endl;
                                cout << "It's a draw!" << endl;
                                draws++;
                                break;
                        }
                        break;
                }
                
                // Winning/Loosing Spree Messages
                cout << "You've won: " << professorWins << " game(s)" << endl;
                cout << "You've lost: " << professorLosses << " game(s)" << endl;
                cout << endl;
                cout << "I've won: " << joshuaWins << " game(s)" << endl;
                cout << "I've lost: " << joshuaLosses << " game(s)" << endl;
                cout << endl;
                cout << "There has been: " << draws << " draws" << endl;
                cout << endl;
                if (professorWins/joshuaWins >= 1.5)
                {
                    cout << "You are DOMINATING" << endl;
                }
                
                if (joshuaWins/professorWins >= 1.5)
                {
                    cout << "You suck!" << endl;
                }
                

                // Replay prompt
                cout << "Play again? (Y/N)";
                cin >> playAgain;
            }
            else
            {
                // Invalid choice prompt
                cout << "Invalid choice, please try again." << endl;
                cout << endl;
            }
            

        }
    }
    return 0;
}
