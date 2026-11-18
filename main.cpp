#include <iostream>
#include <string>

using namespace std;

// Function prototypes
void left(int &humanity);
void middle(int &humanity);
void right(int &humanity);
void upperRoom(int &humanity);
void underGround(int &humanity);

int main()
{
    // Variables declared inside int main()
    string name;
    string surname;
    int age;
    string covenName;
    int option;
    int humanity = 5; // Starting humanity progress
    int lives = 5;     // Starting with 5 lives

    // Arrays for menu options and history tracking
    string menuOptions[6] = {
        "Enter 1 to show mercy to a mortal enemy",
        "Enter 2 to drink blood from an innocent",
        "Enter 3 to share your ancient knowledge to help someone",
        "Enter 4 to give in to your dark bloodlust",
        "Enter 5 to step briefly into the morning sunlight",
        "Enter 6 to EXIT the quest"
    };

    string actionHistory[50];
    int moveCount = 0;

    cout << "________________________________________________________" << endl;
    cout << "WELCOME TO THE VAMPIRE'S REDEMPTION QUEST" << endl;
    cout << "________________________________________________________" << endl;
    cout << " " << endl;

    cout << "Please provide your Vampire name: ";
    getline(cin, name);
    cout << "Please provide your Vampire Surname: ";
    getline(cin, surname);
    cout << "Please provide your mortal Age: ";
    cin >> age;
    cout << "Please provide your Coven Name: " << endl;
    cin >> covenName;

    cout << "Blessed night, " << name << endl;
    cout << " " << endl;
    cout << "YOU ARE A VAMPIRE ON A QUEST TO BECOME HUMAN. CHOOSE WISELY TO REGAIN YOUR HUMANITY, OR LOSE LIVES AND PERISH!" << endl;
    cout << " " << endl;

    // Main Game Loop
    do
    {
        // Check if humanity dropped too low (failure)
        if (humanity <= 0)
        {
            lives--; // Lose a life
            cout << endl;
            cout << "________________________________________________________" << endl;
            cout << "YOUR HUMANITY FADED AWAY! YOU STAYED A VAMPIRE AND LOST A LIFE." << endl;
            cout << "Lives remaining: " << lives << endl;
            cout << "________________________________________________________" << endl;
            cout << endl;

            if (lives > 0)
            {
                humanity = 5; // Reset progress for the next life
                cout << "A dark power revives you for another attempt. Try again!" << endl;
                cout << endl;
            }
            else
            {
                break; // Game over if all 5 lives are gone
            }
        }

        // Check if user successfully reached full humanity (10 points)
        if (humanity >= 10)
        {
            cout << endl;
            cout << "________________________________________________________" << endl;
            cout << "CONGRATULATIONS! YOU REACHED FULL HUMANITY AND BECAME HUMAN!" << endl;
            cout << "________________________________________________________" << endl;
            break;
        }

        cout << "VAMPIRE STATS :" << endl;
        cout << "________________________________________________________" << endl;
        cout << "NAME: " << name << " " << surname << " (Coven: " << covenName << ")" << endl;
        cout << "HUMANITY PROGRESS: " << humanity << " / 10" << endl;
        cout << "LIVES REMAINING: " << lives << endl;
        cout << "________________________________________________________" << endl;
        cout << " " << endl;

        // Loop to display menu options from array
        for (int i = 0; i < 6; i++)
        {
            cout << menuOptions[i] << endl;
        }

        cin >> option;

        switch(option)
        {
            case 1:
                left(humanity); // Correct choice (+ humanity)
                if (moveCount < 50) actionHistory[moveCount++] = "Showed mercy (+1 humanity)";
                break;
            case 2:
                middle(humanity); // Incorrect choice (- humanity)
                if (moveCount < 50) actionHistory[moveCount++] = "Drank blood (-2 humanity)";
                break;
            case 3:
                right(humanity); // Correct choice (+ humanity)
                if (moveCount < 50) actionHistory[moveCount++] = "Helped someone (+1 humanity)";
                break;
            case 4:
                upperRoom(humanity); // Incorrect choice (- humanity)
                if (moveCount < 50) actionHistory[moveCount++] = "Gave in to bloodlust (-2 humanity)";
                break;
            case 5:
                underGround(humanity); // Correct choice (+ humanity)
                if (moveCount < 50) actionHistory[moveCount++] = "Faced the sunlight (+1 humanity)";
                break;
            case 6:
                cout << "Exiting quest. Darkness claims you." << endl;
                break;
            default:
                cout << "Invalid option " << endl;
                break;
        }

    } while (option != 6 && lives > 0 && humanity < 10);

    // Final Summary
    cout << endl;
    cout << "________________________________________________________" << endl;
    if (lives <= 0)
    {
        cout << "GAME OVER: YOU LOST ALL 5 LIVES AND TURNED COMPLETELY TO DUST!" << endl;
    }
    else if (humanity >= 10)
    {
        cout << "VICTORY: YOU COMPLETED THE REDEMPTION!" << endl;
    }

    cout << "YOUR JOURNEY HISTORY:" << endl;
    for (int i = 0; i < moveCount; i++)
    {
        cout << i + 1 << ". " << actionHistory[i] << endl;
    }
    cout << "________________________________________________________" << endl;

    return 0;
}

// Function Definitions for Correct & Incorrect Choices
void left(int &humanity)
{
    cout << "CORRECT CHOICE: YOU SHOWED MERCY AND FORGAVE YOUR ENEMY." << endl;
    cout << "Your soul feels lighter +1 humanity rank" << endl;
    humanity = humanity + 1;
}

void middle(int &humanity)
{
    cout << "INCORRECT CHOICE: YOU GAVE IN TO HUNGER AND DRANK FROM AN INNOCENT." << endl;
    cout << "Darkness consumes you -2 humanity rank" << endl;
    humanity = humanity - 2;
}

void right(int &humanity)
{
    cout << "CORRECT CHOICE: YOU USED YOUR ANCIENT KNOWLEDGE TO SAVE A LIFE." << endl;
    cout << "You are stepping closer to mortality +1 humanity rank" << endl;
    humanity = humanity + 1;
}

void upperRoom(int &humanity)
{
    cout << "INCORRECT CHOICE: YOU SURRENDERED TO YOUR BLOODLUST AT THE RITUAL." << endl;
    cout << "You sink deeper into monstrosity -2 humanity rank" << endl;
    humanity = humanity - 2;
}

void underGround(int &humanity)
{
    cout << "CORRECT CHOICE: YOU FACED THE MORNING LIGHT AND PROVED YOUR BRAVERY." << endl;
    cout << "The light purifies your spirit +1 humanity rank" << endl;
    humanity = humanity + 1;
}


