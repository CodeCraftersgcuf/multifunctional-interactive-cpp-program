#include "Structure.h"
#include <iostream>
#include <ctime>
#include <unistd.h>
#include <string>
using namespace std;

// Main function
int main()
{
    user = welcomeUser();
    while (true)
    {
        if (isEnd == true)
        {
            break;
        }
        displayUserInfo(user);
        displayMainMenu();
    }

    return 0;
}

