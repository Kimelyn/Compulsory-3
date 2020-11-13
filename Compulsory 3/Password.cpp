
#include <conio.h>
#include <iostream>
#include <fstream>
#define KEY_UP 119
#define KEY_DOWN 115
#define KEY_LEFT 97
#define KEY_RIGHT 100
#define KEY_ESC 27
#define Enter 13

void menu();
int main();
void login();
void newPassword();
std::string screen() //screen lock movement
{std::string pass = "A";
    int c = 0;
    char table[4][4]{
         {'A', 'B', 'C', 'D'},
         {'E', 'F', 'G', 'H'},
         {'I', 'J', 'K', 'L'},
         {'M', 'N', 'O', 'P'}
    };
    int x, y;
    x = 0;
    y = 0;

    bool flag = true;
    
    while (c != KEY_ESC && c != Enter) {
        switch ((c = _getch())) {

        case KEY_UP: // key up

            y--;
            pass += table[y][x];
            break;

        case KEY_DOWN:

            y++; // key down
            pass += table[y][x];
            break;

        case KEY_LEFT:

            x--; // key left
            pass += table[y][x];
            break;

        case KEY_RIGHT:

            x++; // key right
            pass += table[y][x];
            break;
        case Enter: case KEY_ESC:
            flag = false;
            break;

        default:

            std::cout << "wrong key\n"; 

            break;

        }
        //print the table
        system("cls");
        std::cout << "Unlock password with WASD\n";

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                // to show where the cursor is
                if (y == i && x == j)

                    std::cout << "* ";

                else
                    std::cout << table[i][j] << " ";
            }
            std::cout << "\n";
        }
        std::cout << pass;
    }
    return pass;
}


void login() {

    std::ifstream outfile;
    std::string passord = "password.txt";

    outfile.open(passord);

    
    std::cout << "Before you can enter this cpp, please enter the password: \n";
    outfile >> passord;
    std::string pass = screen();
    if (passord == pass) { // Check if you have got the correct password before going to the menu
        std::cout << "Correct password\n";
        menu();
    }
    else {
        std::cout << "Wrong password\n";
        login();
        screen().clear();
    }
    outfile.close();
 
    system("pause");
   
}
void newPassword() { //change password
    
    std::ofstream outFile("password.txt", std::ofstream::trunc);
    std::cout << "Enter a text :";
    std::string passord = screen();
    outFile << passord << "\n";
    outFile.close();
    menu();

}