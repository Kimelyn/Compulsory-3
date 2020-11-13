
#include <iostream>
#include <ctime>

int numberOfShips = 11;
const int M = 6, N = 6;
const char BLANK = ' ';
const char SHIP = 'S';
const char MISS = 'M';
const char HIT = 'H';
char board[M][N]; // 2d array with M rows and N columns
int numberOfHits;
int numberOfShots;
void writeLetters();
void menu();
int letterToNumber(char letter) // convert only big letters to number
{
    return static_cast<int>(letter) - 65;
}

void makeEmptyBoard() { 
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            board[i][j] = 0;
        }
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            board[i][j] = 0;
        } std::cout << "\n";
    } 
    std::cout << "\n";
}

int randomRow() {
    int Mrandom = rand() % M;
    return Mrandom;
}
int randomColumn() {
    int Nrandom = rand() % N;
    return Nrandom;
}
void writeLetters() { // appearance
    std::cout << "\n";
    std::cout << "  |A|B|C|D|E|F|\n";
    std::cout << "  -------------\n";
}

void makeBoard() {
    int s = 0;

    while (s < numberOfShips) { //set ships to random places
        int x = randomRow();
        int y = randomColumn();
        if (board[x][y] != SHIP)
            s++;
            board[x][y] = SHIP;
        }
}
 
void printBoard() {
makeBoard();
   for (int i = 0; i < 6; i++)
    {
       std::cout << i;  //print row number and spaces before new row
        std::cout << " ";
        
        for (int j = 0; j < 6; j++) //print more design
        {
            std::cout << board[i][j] << "|";
        } std::cout << "\n";
       
    } writeLetters();
    
    std::cout << "\n";
}
void printPlayerBoard() {  //print better lookin table without seeing the ships

    writeLetters();
    for (int i = 0; i < M; i++) {

        for (int j = 0; j < N; j++) {

            if (j == 0)
            {
                std::cout << i;
                std::cout << " |";
            }

            if (board[i][j] == HIT || board[i][j] == MISS)
            {
                std::cout << board[i][j];
            }

            else
            {
                std::cout << " ";
            }
            std::cout << "|";
        }std::cout << "\n";
    }
}
void shoot() {
    std::cout << "Which cell do you want to shoot?" << "\t" << "Write with a letter and then a number(A1)\n";
    char XX = '1'; //letters
    int x;
    int y;
   
   while (numberOfShots > 0 && numberOfShips > 0) {
       std::cout << "Enter: ";
        
           std::cin >> XX >> x; //check which letter you wrote
         
               if (XX >= 97 && XX <= 122) {//only small letter
                   XX = XX - 32;
               }
               else if (XX <= 65 && XX >= 90) { //only big letter
                   XX;
               }

               y = letterToNumber(XX);
          
        if (board[x][y] == SHIP) {
            std::cout << "You shot one ship\n";
            board[x][y] = HIT;
            numberOfHits++;
            numberOfShips--;
            numberOfShots--;
        }
        else if (board[x][y] == HIT || board[x][y] == MISS) {
            std::cout << "Already shot\n";
            numberOfShots--;
        }
        else if (board[x][y] != SHIP){
            std::cout << "No ship\n";
            board[x][y] = MISS;
            numberOfShots--;
        }
       /////* else {
       ////    */ std::cout << "wrong input";
        ////}
        
        std::cout << "You have " << numberOfHits << " numberOfHits and " << numberOfShots << " numberOfShots\n";
        printPlayerBoard();
        system("pause");
        system("cls");
    }
   
   
}
void play() {
    srand(time(NULL));
    printBoard();
    system("cls");
    std::cout << "How many shots do you want to start with?: ";
    std::cin >> numberOfShots;
    std::cout << "The Battleship game will begin with " << numberOfShots << " shots.\n";
    shoot();
    if (numberOfShips == 0) {
        std::cout << "You have shot down all the ships with " << numberOfShots<< " remaining of shots! Congratulations\n";
        std::cout << "Thank you for playing!\n";
        system("pause");
        menu();
    }
    if (numberOfShots == 0 && numberOfShips > 0) {
        std::cout << "You have lost all of your shots. You have " << numberOfShips <<" remaining of ships.\n";
        std::cout << "Thank you for playing!\n";
        system("pause");
        menu();
    }
    
}




