/*
HANGMAN - GUESSING GAME
Members:
SE_B_9 Mehulsingh Charak
SE_B_11 Sakshi Ganesh Danej
SE_B_15 Pruthvij Prakash Desai
SE_B_25 Chaitali Arun Kapse 
*/

#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <ctime>
#pragma GCC diagnostic ignored "-Wwrite-strings"
#define WRONGTRIES 5
using namespace std;
class GameManager
{
private:
    const int MAX_TRIES;
    string word;
    string words[10];
    string player_name;

public:
    GameManager();
    void showRules()
    {
        // welcome the user
        cout << endl;
        cout << "\t\t\t HOW TO PLAY" << endl;
        cout << "\t\t\t-------------" << endl;
        cout << "\n\n";

        cout << "\t\tWelcome to HANGMAN." << endl;
        cout << "\n";
        cout << "\t\tYou have to guess a country Name." << endl;
        cout << "\t\tEach letter is represented by a ( _ )." << endl;
        cout << "\t\tYou have to type only one letter in one try." << endl;
        cout << "\t\tYou have maximum" << WRONGTRIES << " tries to guess the word." << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "\n\nPress 1 to continue." << endl;
        cin.ignore();
        cin.get();
    }

    void DrawMan(int tries)
    {
        switch (tries)
        {
        case 0:
            circle(200, 150, 50);     // head
            line(100, 430, 100, 80);  // stand
            line(100, 80, 200, 80);   // stand
            line(200, 80, 200, 100);  // stand
            line(200, 200, 200, 350); // torso
            line(200, 200, 150, 250); // left-hand
            line(200, 200, 250, 250); // right-hand
            line(200, 350, 150, 400); // left-leg
            line(200, 350, 250, 400); // right-leg
            break;
        case 1:
            circle(200, 150, 50);     // head
            line(100, 430, 100, 80);  // stand
            line(100, 80, 200, 80);   // stand
            line(200, 80, 200, 100);  // stand
            line(200, 200, 200, 350); // torso
            line(200, 200, 150, 250); // left-hand
            line(200, 200, 250, 250); // right-hand
            break;
        case 2:
            circle(200, 150, 50);     // head
            line(100, 430, 100, 80);  // stand
            line(100, 80, 200, 80);   // stand
            line(200, 80, 200, 100);  // stand
            line(200, 200, 200, 350); // torso
            break;
        case 3:
            circle(200, 150, 50);    // head
            line(100, 430, 100, 80); // stand
            line(100, 80, 200, 80);  // stand
            line(200, 80, 200, 100); // stand
            break;
        case 4:
            line(100, 430, 100, 80); // stand
            line(100, 80, 200, 80);  // stand
            line(200, 80, 200, 100); // stand
            break;

        default:
            break;
        }
    }
    int startGame()
    {
        int gd = DETECT, gm;
        initgraph(&gd, &gm, NULL);

        settextstyle(EUROPEAN_FONT, HORIZ_DIR, 3);
        outtextxy(50, 100, "H");
        delay(700);
        outtextxy(130, 100, "A");
        delay(700);
        outtextxy(210, 100, "N");
        delay(700);
        outtextxy(290, 100, "G");
        delay(700);
        outtextxy(370, 100, "M");
        delay(700);
        outtextxy(450, 100, "A");
        delay(700);
        outtextxy(530, 100, "N");
        delay(700);
        cleardevice();
        // char op;
        //                cout<<"do you want to try again";
        //          cin>>op;
        //         cout<<"thnakyou";
        // do{
        settextstyle(EUROPEAN_FONT, HORIZ_DIR, 2);
        outtextxy(200, 15, " ::HANGMAN:: ");
        string word;
        int options;
        string hint;
        cout << "\n---------------------------------------------------------------";
        cout << "\n\n";
        cout << "\tWELCOME TO HANGMAN GAME";
        cout << "\n";
        cout << "\n---------------------------------------------------------------";
        cout << "\n\tPLEASE CHOOSE THE DIFFICULTY LEVEL" << endl;
        cout << "\n\t1.Easy\n\t2.Medium\n\t3.Hard" << endl;
        cout << "\nENTER THE LEVEL YOU WANT TO PLAY: ";
        cin >> options;
        switch (options)
        {
        case 1:
        {
            string words[] = {"japan", "india", "brazil",
                              "egypt", "china", "belgium",
                              "canada", "nepal", "spain", "qatar"};
            srand(time(NULL));
            int n = rand() % 10;
            word = words[n];
            switch (n)
            {
            case 0:
                hint = "Hint: The country in which anime was created";
                settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
                outtextxy(2, 50, "Hint: The country in which anime was created");
                break;
            case 1:
                hint = "Hint: country having one of the seven wonders";
                settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
                outtextxy(2, 50, "Hint: country having one of the seven wonders");
                break;
            case 2:
                hint = "Hinht : famous for football";
                settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
                outtextxy(2, 50, "Hint : famous for football");
                break;
            case 3:
                hint = "Hint: This country has giant pyramids";
                settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
                outtextxy(2, 50, "Hint: This country has giant pyramids");
                break;
            case 4:
                hint = "Hint: This country has a place called Beijing.";
                settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
                outtextxy(2, 50, "Hint: This country has a place called Beijing.");
                break;
            case 5:
                hint = "Hint : This country is world famous for its chocolate";
                settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
                outtextxy(2, 50, "Hint : This country is world famous for its chocolate");
                break;
            case 6:
                hint = "Hint: Niagara Falls";
                settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
                outtextxy(2, 50, "Hint: Niagara Falls");
                break;
            case 7:
                hint = "Hint :Birthplace of Lord Gautam Buddha";
                settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
                outtextxy(2, 50, "Hint: Birthplace of Lord Gautam Buddha");
                break;
            case 8:
                hint = "Hint :UNESCO's third largest heritage country.";
                settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
                outtextxy(2, 50, "Hint: UNESCO's third largest heritage country.");
                break;
            case 9:
                hint = "Hint :First Arab Country to Host FIFA World Cup";
                settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
                outtextxy(2, 50, "Hint: First Arab Country to Host FIFA World Cup");
                break;
            }
            break;
        }
        case 2:
        {
            string op[] = {"australia", "argentina", "switzerland", "southafrica", "singapore",
                           "russia", "mexico", "srilanka", "malaysia", "barbados"};
            srand(time(NULL));
            int s = rand() % 10;
            word = op[s];
            switch (s)
            {
            case 0:
                hint = "Hint: This country has kangaroos";
                settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
                outtextxy(2, 50, "Hint: This country has kangaroos");
                break;
            case 1:
                hint = "Hint: Birth Place Of a LIONEL MESSI";
                settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
                outtextxy(2, 50, "Hint: Birth Place Of LIONEL MESSI");
                break;
            case 2:
                hint = "Hint : Mostly known for their knives and banks";
                settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
                outtextxy(2, 50, "Hint :Mostly known for their knives and banks");
                break;
            case 3:
                hint = " Hint: The country in which nelson Mandela was born";
                settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
                outtextxy(2, 50, " Hint: The country in which nelson Mandela was born");
                break;
            case 4:
                hint = "Hint: This country has airport called  Changi Airport";
                settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
                outtextxy(2, 50, "Hint: This country has airport called  Changi Airport");
                break;
            case 5:
                hint = "Hint :one of the largest country in the world";
                settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
                outtextxy(2, 50, "Hint :one of the largest country in the world");
                break;
            case 6:
                hint = "Hint: This country shares a border with the USA";
                settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
                outtextxy(2, 50, "Hint: This country shares a border with the USA");
                break;
            case 7:
                hint = "Hint: Known as pearl of Indian ocean";
                settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
                outtextxy(2, 50, "Hint :Known as pearl of Indian ocean");
                break;
            case 8:
                hint = "Hint: Food capital of the world";
                settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
                outtextxy(2, 50, "Hint :Food capital of the world");
                break;
            case 9:
                hint = " Hint : First Caribbean island to have piped water";
                settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
                outtextxy(2, 50, "Hint :First Caribbean island to have piped water");
                break;
            }
            break;
        }
        case 3:
        {
            string we[] = {"portugal", "kuwait", "netherlands", "belarus", "cambodia", "zimbabwe", "Madagascar", "denmark", "portugal", "srilanka"};
            srand(time(NULL));
            int z = rand() % 10;
            word = we[z];
            switch (z)
            {
            case 0:
                hint = "Hint:  Home to several explorers, like Vasco da Gama and Ferdinand Magellan.";
                settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
                outtextxy(2, 50, "Hint:  Home to several explorers, like Vasco da Gama.");
                break;
            case 1:
                hint = "Hint : Highest currency in the world ";
                settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
                outtextxy(2, 50, "Hint : Highest currency in the world ");
                break;
            case 2:
                hint = "Hint: Amsterdam";
                settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
                outtextxy(2, 50, "Hint: Amsterdam");
                break;
            case 3:
                hint = "Hint :not a aprt of russia but is also called as white russia ";
                settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
                outtextxy(2, 50, "Hint :Not a part of russia but is also called as white russia");
                break;
            case 4:
                hint = "Hint: First country to have building on their flag";
                settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
                outtextxy(2, 50, "Hint :First country to have building on their flag");
                break;
            case 5:
                hint = "Hint :  The world's largest waterfall.";
                settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
                outtextxy(2, 50, "Hint: The world's largest waterfall");
                break;
            case 6:
                hint = "Hint :Fourth largest island on the Earth";
                settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
                outtextxy(2, 50, "Hint: Fourth largest island on the Earth");
                break;
            case 7:
                hint = "Hint :One of the hppiest countries in the world";
                settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
                outtextxy(2, 50, "Hint: One of the happiest countries in the world");
                break;
            case 8:
                hint = "Hint: Oldest country in Europe.";
                settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
                outtextxy(2, 50, "Hint: Oldest country in Europe.");
                break;
            case 9:
                hint = "Hint :Pearl of the Indian Ocean and teardrop of India";
                settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
                outtextxy(2, 50, "Hint: Pearl of the Indian Ocean and teardrop of India");
                break;
            }
            break;
        }
        }
        string guessed;
        srand(time(NULL));
        int n = rand() % 10;
        int wordLength = word.length();
        string displayWord(wordLength, '_');
        int found = 0;
        char guess = ' ';
        int tries = 5;
        int wordFound = 0;
        while (tries >= 0)
        {
            system("cls");

            cout << "\n\n\tWelcome to the HANGMAN game...Guess a country Name"<<endl;
            cout << "\n\n\tEach letter is represented by a (__)."<<endl;
            cout << "\n\n\tYou have to type only one letter in one try"<<endl;
            cout << "\n\n\tYou have " << WRONGTRIES << " tries to try and guess the word.";
            cout << "\n\n\t*************************************************************"<<endl;
            cout << endl;
            cout << "\n\t-------------------------------------------";
            cout << "\n\t" << hint;
            cout << "\n\t-------------------------------------------";
            settextstyle(EUROPEAN_FONT, HORIZ_DIR, 2);
            outtextxy(300, 150, "Guess the country name:");
            cout << "\n\tGuess the country name:" << endl;
            for (int i = 0; i < wordLength; i++)
                cout << "\t"
                     << " " << displayWord[i] << " ";
            cout << "\n\tWrong Attempts:\n"
                 << tries << " / " << WRONGTRIES << endl;
            cout << "\tGuessed Leters:" << endl
                 << "\t" << guessed << endl;
            DrawMan(tries);
            if (displayWord == word)
            {
                cout << endl;
                cout << "\tYAHOO!! YOU WIN" << endl;
                settextstyle(EUROPEAN_FONT, HORIZ_DIR, 2);
                outtextxy(300, 230, "YAHOO!! You Win");
                int an;
                cout << "\n-----------------------------------------------------------------------";
                cout << " \n \t\tWANT TO PLAY AGAIN (yes/no): " << endl;
                cout << "\t\t If Yes press (1) Else press (0) :\t";
                cin >> an;
                cout << "\n__________________________________________________________________________";
                if (an == 1)
                {
                    startGame();
                }
                else
                {
                    cout << "\n\t\tTHANKS FOR PLAYING  ." << endl;
                    exit(0);
                }
            }
            if (tries == 0)
                break;
            cout << "\tPick a letter : ";
            guess = getche();
            guessed = guessed + " " + guess;
            if (displayWord.find(guess) != string::npos)
                tries++;
            wordFound = 0;
            for (int i = 0; i < wordLength; i++)
            {
                if (word[i] == guess && displayWord[i] == '_')
                {
                    displayWord[i] = guess;
                    wordFound = 1;
                }
            }
            if (!wordFound)
                tries--;
        }
        if (tries == 0)
        {
            cout << "OOPSS You lose" << endl;
            cout << "The word was " << word << endl;
            outtextxy(300, 230, "oops You Lose");
            int an;
            cout << "________________________________________________________________________" << endl;
            cout << " \n \tWANT TO PLAY AGAIN (yes/no): " << endl;
            cout << "\t\t If Yes press (1) Else press 0 :";
            cin >> an;
            cout << "___________________________________________________________________________" << endl;
            if (an == 1)
            {
                startGame();
            }
            else
            {
                cout << "\t\tTHANKS FOR PLAYINFG  ." << endl;
            }
        }

        getch();
        closegraph();

        return 0;
    }
    void showTitle()
    {
        cout << "\t *    *     **     **    *  *****   **   **     **     **    *" << endl;
        cout << "\t *    *    *  *    * *   * *        * * * *    *  *    * *   *" << endl;
        cout << "\t ******   ******   *  *  * *  ***** *  *  *   ******   *  *  *" << endl;
        cout << "\t *    *  *      *  *   * * *      * *     *  *      *  *   * *" << endl;
        cout << "\t *    * *        * *    ** ******** *     * *        * *    **" << endl;
    }
};
GameManager::GameManager() : MAX_TRIES(5)
{
    player_name = "default";
}
int main()
{
    GameManager game;

    int choice;
    do
    {
        system("cls");
        game.showTitle();

        cout << endl;
        cout << "\t1. PLAY\n";
        cout << "\t2. RULES OF GAME\n";
        cout << "\t3. EXIT\n";
        cout << "\n----------------------------------------------";
        cout << "\n";
        cout << "Enter your choice (1/2/3): ";
        cin >> choice;

        if (choice == 1)
        {
            char ch;
            game.startGame();
        }
        else if (choice == 2)
        {
            game.showRules();
        }
        else if (choice == 3)
        {
            cout << "Bye bye" 
            
            << endl;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    } while (choice != 3);

    return 0;
}
