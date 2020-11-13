#include <iostream>
void play();
void login();
void newPassword();
void menu();
int main() {
    
        login();
        menu();
return 0;
}

void menu()
{
bool flag = true;
    int option = 0;

    
   do{   system("cls");
    std::cout << "   Welcome to compulsory 3\n";
    std::cout << "----------------------------\n";
    
    std::cout << "\tMain menu\n";
    std::cout << "      ------------\n";
    std::cout << "  1. Change password\n";
    std::cout << "  2. Play battleship\n";
    std::cout << "  3. Quit\n";
    std::cout << "     Select an option (1-3)";
    std::cin >> option;
       switch (option) {
    case 1:
        std::cout << "You want change your password.\n";
        newPassword();
        break;
    case 2:
        std::cout << "Welcome to Battleship!\n";
            system("Pause");
        play();
        break;
    case 3:
        std::cout << "Thanks for checking here. Have a nice day!\n";
        flag = false;
        break;
    default:
        std::cout << "invalid input\n";
        break;
    }
}
while (flag == true);
    
}