#ifndef STRUCTURE_H 
#define STRUCTURE_H
#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
#include <unistd.h>
#include <string>
using namespace std;

/////////////////////////////////// User structure to store user information//////////////////////////////////////
struct User
{
    string name;
    int money;
};


// globallay declared choice
bool isEnd = false;
User user; // defining only

//////////////////////////////////////////// mentioning all functions///////////////////////////////////////////
User welcomeUser();
void displayUserInfo(const User &user);
void displayMainMenu();
void earnMenu();
void spendMenu();
void guessingNumberProgram(User &user);
void rockPaperScissorsProgram(User &user);
void carRentalProgram(User &user);
void airplaneTicketProgram(User &user);
void hotelManagementProgram(User &user);
void Goodbye(void){
	cout<<"\033[1;36m\t\t\t\tThank you for using the Multifunctional Interactive Program. Goodbye!\n\033[0m\n";
	sleep(1);
}



///////////////////////////////////////// Function to welcome the user and ask for registration:
User welcomeUser()
{
    User user;
    cout<< "\033[1;36m\t\t\t\tWelcome to the Multifunctional Interactive Program!\033[0m\n"; // Yellow color for welcome message
   	cout << "\n\n\033[1m\033[37m\t\tHi There,\n"
    "\t\tThis is a Multifunctional Program, With the The goal of this program is to create provide open-world interactive\n"
    "\t\tThat provides users with a diverse range of activities and challenges to explore and conquer.\n"
    "\t\tTo precede, follow the below command!\033[0m\n";
    cout<<endl;
    sleep(11);
	cout<< "\033[1;37mPress 1 To Register\n\033[0m\n";
   	int choice;
    cin >> choice;

    if (choice == 1)
    {
        cout << "\033[1mEnter your name: \033[0m\n";
        cin >> user.name;

        cout << "\033[1;33mYou are registering. Please wait...\033[0m\n"; // Yellow color for registration message
        sleep(2); 
		
        user.money = 1000;
    }
    else
    {
        cout << "\033[1;31mInvalid choice. Exiting program.\033[0m\n"; // Red color for error message
        exit(0);
    }

    return user;
}

////////////////////// Function to display user information//////////////////////////////////////////////

void displayUserInfo(const User &user)
{
    cout << "\033[1;32mWelcome, " << user.name << "!\033[0m\n"; // Green color for user name
    cout << "\033[1;32mMoney: $" << user.money << "\033[0m\n";   // Green color for money
	sleep(1); 
}
// //////////////////////////Function to display the main menu//////////////////////////////////////////
void displayMainMenu()
{
    int choice;
    cout << "\n\033[37mWhat would you like to do?\033[0m\n";
    sleep(1);
    cout << "\033[32m1. Earn Money\033[0m\n";
    cout << "\033[36m2. Spend Money\033[0m\n";
    cout << "\033[31m0. Exit\033[0m\n";
    cin >> choice;
    if (choice == 1)
    {
        earnMenu();
    }
    else if (choice == 2)
    {
        spendMenu();
    }
    else if (choice == 0)
    {
    	Goodbye();
	    isEnd = true;
    }
    else
    {
        cout << "\033[1;31mInvalid Command\033[0m\n"; // Red color for error message
    }
     sleep(1); 
    return;
}

////////////////////////////////////// Function To Display Earn menu///////////////////////////////
void earnMenu()
{
	sleep(1);
    cout << "\033[1m1. Guessing Number\033[0m\n";
    cout << "\033[1m2. Rock and Paper\033[0m\n";
    cout << "\033[31m0. Exit\033[0m\n";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 0:
       Goodbye();
		isEnd = true;
        break;

    case 1:
        guessingNumberProgram(user);
        break;

    case 2:
        rockPaperScissorsProgram(user);
        break;

    default:
        cout << "\033[1;31mInvalid Command\033[0m\n"; // Red color for error message
        break;
    }
    sleep(1); 
    return;
}

////////////////////Function To Display Spend Menu/////////////////////////////////////////
void spendMenu()
{
	sleep(1);
    cout << "\033[1m1. Car Rental\033[0m\n";
    cout << "\033[1m2. Airplane Ticket\033[0m\n";
    cout << "\033[1m3. Hotel Management\033[0m\n";
    cout << "\033[1;31m0. Exit\033[0m\n";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 0:
		Goodbye();
    	isEnd = true;
        break;

    case 1:
        carRentalProgram(user);
        break;

    case 2:
        airplaneTicketProgram(user);
        break;

    case 3:
        hotelManagementProgram(user);
        break;

    default:
        cout << "\033[1;31mInvalid Command\033[0m\n"; // Red color for error message
        break;
    }
    sleep(1); 
    return;
}

///////////////////////// Function to handle the guessing number game///////////////////////////
void guessingNumberProgram(User &user)
{
	sleep(1);
    cout << "\033[1;34mGuessing Number Game\033[0m\n"; // Blue color for game title

    // Generate a random number between 1 and 100
    srand(time(0));
    int randomNumber = rand() % 100 + 1;

    int guess;
    int attempts = 0;
    bool guessedCorrectly = false;

    while (!guessedCorrectly)
    {
        cout << "\033[1mEnter your guess (between 1 and 100): \033[0m\n";
        cin >> guess;
        attempts++;

        if (guess == randomNumber)
        {
            guessedCorrectly = true;
            break;
        }
        else if (guess < randomNumber)
        {
            cout << "\033[36mToo low! Try Some Higher Number.\033[0m\n";
        }
        else
        {
            cout << "\033[36mToo high! Try Lower Number.\033[0m\n";
        }
    }
	cout<<endl<<endl<<endl;
    cout << "\033[32mCongratulations! You guessed the correct number.\033[0m\n";
    cout << "\033[37mNumber of attempts: \033[0m\n" << attempts << "\n";
	sleep(2);
    int reward = 1000 / attempts;
    user.money += reward;
    cout << "\033[1;32mYou earned $" << reward << "\033[0m\n"; // Green color for reward message
    cout << "\033[1;32mCurrent balance: $" << user.money << "\033[0m\n"; // Green color for balance
	sleep(1);
}

////////////////// Function to handle the rock-paper-scissors game/////////////////////////////
void rockPaperScissorsProgram(User &user)
{
	sleep(1);
    cout << "\033[1;34mRock-Paper-Scissors Game\033[0m\n"; // Blue color for game title
    cout << "\033[37mSelect your move:\033[0m\n";
    cout << "\033[37m1. Rock\033[0m\n";
    cout << "\033[37m2. Paper\033[0m\n";
    cout << "\033[37m3. Scissors\033[0m\n";
    int userMove;
    cin >> userMove;
    srand(time(0));
    int computerMove = rand() % 3 + 1;

    string userMoveStr, computerMoveStr;
    int reward = 0;

    switch (userMove)
    {
    case 1:
        userMoveStr = "Rock";
        if (computerMove == 1)
        {
            computerMoveStr = "Rock";
            sleep(1);
            cout << "\033[33mIt's a tie!\033[0m\n";
        }
        else if (computerMove == 2)
        {
            computerMoveStr = "Paper";
             sleep(1);
            cout << "\033[1;31mYou lose!\033[0m\n Paper beats Rock.\n";
        }
        else
        {
            computerMoveStr = "Scissors";
             sleep(1);
            cout << "\033[1;32mYou win!\033[0m\n Rock beats Scissors.\n";
            reward = 100;
        }
        break;
    case 2:
        userMoveStr = "Paper";
        if (computerMove == 1)
        {
            computerMoveStr = "Rock";
             sleep(1);
            cout << "\033[1;32mYou win!\033[0m\n Paper beats Rock.\n";
            reward = 100;
        }
        else if (computerMove == 2)
        {
            computerMoveStr = "Paper";
             sleep(1);
            cout << "\033[33mIt's a tie!\033[0m\n";
        }
        else
        {
            computerMoveStr = "Scissors";
             sleep(1);
            cout << "\033[1;31mYou lose!\033[0m\n Scissors beat Paper.\n";
        }
        break;
    case 3:
        userMoveStr = "Scissors";
        if (computerMove == 1)
        {
            computerMoveStr = "Rock";
             sleep(1);
            cout << "\033[1;31mYou lose!\033[0m\n Rock beats Scissors.\n";
        }
        else if (computerMove == 2)
        {
            computerMoveStr = "Paper";
             sleep(1);
            cout << "\033[1;32mYou win!\033[0m\n Scissors beat Paper.\n";
            reward = 100;
        }
        else
        {
            computerMoveStr = "Scissors";
             sleep(1);
            cout << "\033[33mIt's a tie!\033[0m\n";
        }
        break;
    default:
        cout << "\033[1;31mInvalid move. Returning to main menu.\033[0m\n"; // Red color for error message
        sleep(1);
        return;
    }

    cout << "Your move: " << userMoveStr << "\n";
    cout << "Computer's move: " << computerMoveStr << "\n";
	 sleep(1);
    user.money += reward;
    cout << "\033[1;32mYou earned $" << reward << "\033[0m\n"; // Green color for reward message
    cout << "\033[1;32mCurrent balance: $" << user.money << "\033[0m\n"; // Green color for balance
	 sleep(1);
}

///////////////////////////////////Car Rental Program//////////////////////////////
void carRentalProgram(User &user)
{
    int car_choice;

    cout << "\033[1;34mCar Rental Program\033[0m\n"
         << endl;
    cout << "\033[37mSelect One option:\033[0m\n" << endl;
    sleep(1);
    cout << "\033[34m1. Ford: 300$ \033[0m\n" << endl;
    cout << "\033[36m2. Bugatti: 1000$ \033[0m\n" << endl;
    cout << "\033[37m3. Tesla: 500$\033[0m\n" << endl;
    cin >> car_choice;

    if (car_choice == 1)
    {
        int rentalCost = 300;
        if (user.money < rentalCost)
        {
        	 sleep(1);
            cout << "\033[1;31mInsufficient funds to rent a car.\033[0m\n"; // Red color for error message
            cout << "\033[35mPlay some games to earn more money?\033[0m\n";
            return;
        }
        user.money -= rentalCost;
    }
    else if (car_choice == 2)
    {
        int rentalCost = 1000;
        if (user.money < rentalCost)
        {
        	 sleep(1);
            cout << "\033[1;31mInsufficient funds to rent a car.\033[0m\n"; // Red color for error message
    		sleep(1);
	        cout << "\033[35mPlay some games to earn more money?\033[0m\n";
            return;
        }
        user.money -= rentalCost;
    }
    else if (car_choice == 3)
    {
        int rentalCost = 500;
        if (user.money < rentalCost)
        {
        	 sleep(1);
            cout << "\033[1;31mInsufficient funds to rent a car.\033[0m\n"; // Red color for error message
            cout << "\033[35mPlay some games to earn more money?\033[0m\n";
            return;
        }
        user.money -= rentalCost;
    }
    else
    {
    	 sleep(1);
        cout << "\033[1;31mWrong Choice: Returning to Menu\033[0m" << endl; // Red color for error message
        sleep(2);
		return;
        
    }
    cout << "\033[1;32mYou rented a car!\033[0m\n"; // Green color for success message
     sleep(1);
    cout << "Enjoy your trip!\n";
     sleep(1);
    cout << "\033[1;32mCurrent balance: $" << user.money << "\033[0m\n"; // Green color for balance
}

//////////////////////////// Function to handle the airplane ticket program////////////
void airplaneTicketProgram(User &user)
{
    int air_choice;
    cout << "\033[1;34mAirplane Ticket Program\033[0m\n"
         << endl;
    cout << " \033[37mSelect One option:\033[0m\n" << endl;
    sleep(1);
    cout << "\033[37m1. United States: 200$ \033[0m\n" << endl;
    cout << "\033[37m2. Canada: 100$ \033[0m\n" << endl;
    cout << "\033[37m3. France: 150$\033[0m\n" << endl;
    cin >> air_choice;

    if (air_choice == 1)
    {
        int airticket = 200;
        if (user.money < airticket)
        {
        	 sleep(1);
            cout << "\033[1;31mInsufficient funds to buy an airplane ticket.\033[0m\n"; // Red color for error message
            cout << "\033[35mPlay some games to earn more money.\033[0m\n";
            return;
        }
        user.money -= airticket;
    }
    else if (air_choice == 2)
    {
        int airticket = 100;
        if (user.money < airticket)
        {
        	 sleep(1);
            cout << "\033[1;31mInsufficient funds to buy an airplane ticket.\033[0m\n"; // Red color for error message
            cout << "\033[35mPlay some games to earn more money.\033[0m\n";
            return;
        }
        user.money -= airticket;
    }
    else if (air_choice == 3)
    {
        int airticket = 150;
        if (user.money < airticket)
        {
        	 sleep(1);
            cout << "\033[1;31mInsufficient funds to buy an airplane ticket.\033[0m\n"; // Red color for error message
            cout << "\033[35mPlay some games to earn more money.\033[0m\n";
            return;
        }
        user.money -= airticket;
    }
    else
    {
    	 sleep(1);
        cout << "\033[1;31mWrong Choice: Returning to Menu\033[0m" << endl; // Red color for error message
        return;
    }
     sleep(1);
    cout << "\033[1;32mTicket purchased successfully.\033[0m\n"; // Green color for success message
    cout << "\033[1;32mCurrent balance: $" << user.money << "\033[0m\n"; // Green color for balance
	sleep(2);
}

///////////////////////////// Function to handle the hotel management program///////////////////////
void hotelManagementProgram(User &user)
{
    int hotel_choice;
    cout << "\033[1;34mHotel Management Program\033[0m\n";
     sleep(1);
    cout << "\033[1;34mSelect One option:\033[0m\n" << endl;
    sleep(1);
    cout << "\033[37m1. Raffles, Singapore: 100$ \033[0m\n" << endl;
    cout << "\033[37m2. The Waldorf Astoria, New York: 200$ \033[0m\n " << endl;
    cout << "\033[37m3. The Ritz, Paris: 150$ \033[0m\n" << endl;
    cin >> hotel_choice;

    if (hotel_choice == 1)
    {
        int hotelticket = 100;
        if (user.money < hotelticket)
        {
        	 sleep(1);
            cout << "\033[1;31mInsufficient funds to book a hotel.\033[0m\n"; // Red color for error message
            cout << "\033[35mPlay some games to earn more money.\033[0m\n";
            return;
        }
        user.money -= hotelticket;
    }
    else if (hotel_choice == 2)
    {
        int hotelticket = 200;
        if (user.money < hotelticket)
        {
        	 sleep(1);
            cout << "\033[1;31mInsufficient funds to book a hotel.\033[0m\n"; // Red color for error message
            cout << "\033[35mPlay some games to earn more money.\033[0m\n";
            return;
        }
        user.money -= hotelticket;
    }
    else if (hotel_choice == 3)
    {
        int hotelticket = 150;
        if (user.money < hotelticket)
        {
        	 sleep(1);
            cout << "\033[1;31mInsufficient funds to book a hotel.\033[0m\n"; // Red color for error message
            cout << "\033[35mPlay some games to earn more money.\033[0m\n";
            return;
        }
        user.money -= hotelticket;
    }
    else
    {
    	 sleep(1);
        cout << "\033[1;31mWrong Choice: Returning to Menu\033[0m" << endl; // Red color for error message
        return;
    }
     sleep(1);
    cout << "\033[1;32mHotel booked successfully.\033[0m\n"; // Green color for success message
    cout << "\033[1;32mCurrent balance: $" << user.money << "\033[0m\n"; // Green color for balance
	sleep(2); 
}


#endif
