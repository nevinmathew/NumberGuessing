#include <iostream>
#include <string> 
// for random numbers
#include <cstdlib> 
#include <ctime>

using namespace std;
void rules();
int main(int argc, char **argv)
{
    string playerName;
    int balance;
    int bettingAmount;
    int guess;
    int dice; 
    char choice;

    srand(time(0)); 
    cout<<"\n\t\t******** WELCOME TO THE CASINO *******\n\n";
    cout<<"\n\nWhat's your Name : ";
    getline(cin, playerName);
    cout<<"\n\nEnter the starting balance to play game : ₹";
    cin>>balance;
    do
    {
        // to clear the screen (windows)
        system("cls");
        // to display the rules
        rules();
        cout << "\n\nYour current balance is ₹ " << balance <<endl;
        
        // to get the betting amount
        do
        {
            cout << "Hey, " << playerName<<", enter amount to bet : ₹";
            cin >> bettingAmount;
            if(bettingAmount > balance)
                cout << "Betting amount can't be more than your balance!\n"<<"\nRe-enter balance\n ";
        } while(bettingAmount > balance);
        
        // to get the player's numbers
        do
        {
            cout<<"Guess any number between 1 and 10 :";
            cin >> guess;

            if(guess <= 0 || guess > 10)
                cout << endl<<"Number should be between 1 to 10"<<endl<<"Re-enter number:\n ";
        } while(guess <= 0 || guess > 10);

        //to get the random number
        dice = rand()%10 + 1;
        if(dice == guess)
        {
            cout << "\n\nYou are in luck!! You have won Rs." << bettingAmount * 10;
            balance = balance + bettingAmount * 10;
        }
        else
        {
            cout << "Oops, better luck next time !! You lost ₹ "<< bettingAmount <<endl;
            balance -= bettingAmount;
        }

        cout<< "\nThe winning number was : " << dice <<"\n";
        cout << "\n"<<playerName<<", Your balance is ₹ " << balance << "\n";

        if(balance == 0)
        {
            cout << "You have no money to play ";
            break;
        }

        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
    } while(choice =='Y'|| choice=='y');

    cout << "\n\n\n";
    cout << "\n\nThanks for playing the game. Your balance is ₹ " << balance << "\n\n";
    return 0;
}
void rules()
{
    system("cls");
    cout << "\t\t****** RULES! *****\n";
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. Winner gets 10 times of the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";
}