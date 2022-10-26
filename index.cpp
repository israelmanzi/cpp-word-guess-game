#include <iostream>
#include <ctime>
using namespace std;

string teams[] = {"arsenal", "mancity", "spurs", "newcastle", "chelsea", "manutd", "fulham", "liverpool", "brighton", "westham", "brentford", "everton", "crystalpalace", "bournemouth", "astonvilla", "southampton", "leicester", "leeds", "wolves", "nottingham"};
string animals[] = {"elephant", "giraffe", "lion", "tiger", "zebra", "monkey", "panda", "penguin", "koala", "hippo"};
string footballers[] = {"messi", "ronaldo", "neymar", "mbappe", "kane", "debruyne", "salah", "aguero", "suarez", "hazard"};

int random(int low, int high)
{
    return rand() % (high - low) + low;
}

string placeHold(string selected, int length)
{
    for (int i = 0; i < length; i++)
    {
        selected[i] = '_';
    }

    return selected;
}

void guessChar(string &word, int length)
{
    int lives = length * 2 - 5;

    string retString = placeHold(word, length);

    char guess;

    for (int i = lives; i >= 0; i--)
    {
        cout << "You have " << i << " lives left" << endl << endl;
        cout << "Guess a letter: ";
        cin >> guess;

        for (int j = 0; j < length; j++)
        {
            if (guess == word[j])
            {
                retString[j] = guess;
            }
        }

        if (retString == word)
        {
            cout << "==============================OUTPUT==============================" << endl << endl;
            cout << "You win!" << endl;
            cout << "The word was " << word << endl;

            break;
        }

        cout << retString << endl <<endl;
    }

    if (retString != word)
    {
        cout << "==============================OUTPUT==============================" << endl << endl;
        cout << "You lose!" << endl;
        cout << "The word was " << word << endl;
    }
}

bool performGuess(string *arr, int length)
{
    string selected;

    int randomNumber = random(0, length);

    for (int i = 0; i < length; i++)
    {
        selected = arr[randomNumber];
    }

    string placeholder = placeHold(selected, selected.length());

    // cout << "Selected: " << selected << endl;
    cout << "Word to guess(length): " << selected.length() << endl
         << endl;
    cout << "Place holder: " << placeholder << endl
         << endl;

    guessChar(selected, selected.length());

    cout << "Do you want to play again? (y/n): ";
    char choice;
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void loopPerform(string *arrSelect, int arrLength)
{
    bool playAgain = true;

    while (playAgain)
    {
        playAgain = performGuess(arrSelect, arrLength);
    }

    cout << "==============================GOODBYE==============================" << endl << endl;
}

void returnStringItems(string *arr, int length){
    string retString = "";

    for (int i = 0; i < length; i++)
    {
        retString += arr[i] + ", ";
    }

    cout << "Category items: {" << retString << "}" << endl << endl;
}

int main()
{
    srand(time(NULL));

    cout << "==============================WELCOME==============================" << endl << endl;

    int length;

    int category;

    cout << "Categories: " << endl << endl;

    cout << "1. Epl Teams" << endl;
    cout << "2. Animals" << endl;
    cout << "3. Footballers" << endl << endl;

    cout << "Select a category: ";

    cin >> category;

    switch (category)
    {
    case 1:
        length = sizeof(teams) / sizeof(teams[0]);

        returnStringItems(teams, length);

        loopPerform(teams, length);

        break;
    case 2:
        length = sizeof(animals) / sizeof(animals[0]);
        
        returnStringItems(animals, length);
        
        loopPerform(animals, length);

        break;
    case 3:
        length = sizeof(footballers) / sizeof(footballers[0]);

        returnStringItems(footballers, length);

        loopPerform(footballers, length);

        break;
    default:
        cout << "Invalid category" << endl;
        break;
    }

    return 0;
}