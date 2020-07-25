#include <cstdlib>
#include <iostream>
#include <limits>

using namespace std;

char square[] = {' ', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int m, n, p, q;

void grid()
{
    // PRINT THE GRID
    system("clear");
    cout << "*** TIC TAC TOE ***" << endl;
    // cout << "Player 1-> x  Player 2-> o" << endl << endl;
    cout << "Player 1-> x  Computer-> o" << endl
         << endl;
    for (int a = 1; a < 10; a++)
    {
        cout << square[a] << " ";
        if (a % 3 == 0)
            cout << endl;
    }
    cout << endl;
}

void player1()
{
    // PLAYER1's SIGN
    cin >> m;
    if (square[m] == 'o' || square[m] == 'x')
    {
        cout << "Invalid number, try again: ";
        player1();
    }
    else
        square[m] = 'x';
    if (m < 1 || m > 9)
    {
        cout << "Enter a number from 1-9: ";
        player1();
    }
}

void player2()
{
    // PLAYER2's SIGN
    cin >> n;
    if (square[n] == 'o' || square[n] == 'x')
    {
        cout << "Invalid number, try again: ";
        player2();
    }
    else
        square[n] = 'o';
    if (n < 1 || n > 9)
    {
        cout << "Enter a number from 1-9: ";
        player2();
    }
}

void computer_easy()
{
    p = rand() % 9 + 1;
    if (square[p] == 'o' || square[p] == 'x')
    {
        computer_easy();
    }
    else
        square[p] = 'o';
}

//***EMPLEMENT MINIMAX***
// float bestscore = -1.0 / 0.0;
// float worstscore = 1.0 / 0.0;
// int score;
// if (win_check(square[m]) == true)
//   score = -1;
// if (win_check(square[q]) == true)
//   score = 1;
// if (win_check(square[m]) == false && win_check(square[q]) == false)
//   score = 0;

// int maxer(int z) {
//   q = z % 9 + 1;
//   if (score > bestscore) bestscore = score;
//   return bestscore;
// }

// int miner(int w) {
//   q = w % 9 + 1;
//   if (score < worstscore) worstscore = score;
//   return worstscore;
// }

// void computer_hard() {
//   if (square[q] == 'o' || square[q] == 'x') {
//     computer_hard();
//   } else
//     square[q] = 'o';
// }

bool win_check(int)
{
    bool status;
    // WIN CHECK FOR PLAYER 1- CHECKING THE Xs

    // ROWS CHECK

    if (square[1] == 'x' && square[2] == 'x' && square[3] == 'x')
        status = true;

    else if (square[4] == 'x' && square[5] == 'x' && square[6] == 'x')
        status = true;

    else if (square[7] == 'x' && square[8] == 'x' && square[9] == 'x')
        status = true;

    // COLLUMS CHECK

    if (square[1] == 'x' && square[4] == 'x' && square[7] == 'x')
        status = true;

    else if (square[2] == 'x' && square[5] == 'x' && square[8] == 'x')
        status = true;

    else if (square[3] == 'x' && square[6] == 'x' && square[9] == 'x')
        status = true;

    // DIAGONAL LEFT-RIGHT CHECK

    else if (square[1] == 'x' && square[5] == 'x' && square[9] == 'x')
        status = true;

    // DIAGONAL RIGHT-LEFT CHECK

    else if (square[3] == 'x' && square[5] == 'x' && square[7] == 'x')
        status = true;

    // WIN CHECK FOR PLAYERS 2- CHECKING THE Os

    // ROWS CHECK

    else if (square[1] == 'o' && square[2] == 'o' && square[3] == 'o')
        status = true;

    else if (square[4] == 'o' && square[5] == 'o' && square[6] == 'o')
        status = true;

    else if (square[7] == 'o' && square[8] == 'o' && square[9] == 'o')
        status = true;

    // COLLUMS CHECK

    else if (square[1] == 'o' && square[4] == 'o' && square[7] == 'o')
        status = true;

    else if (square[2] == 'o' && square[5] == 'o' && square[8] == 'o')
        status = true;

    else if (square[3] == 'o' && square[6] == 'o' && square[9] == 'o')
        status = true;

    // DIAGONAL LEFT-RIGHT CHECK

    else if (square[1] == 'o' && square[5] == 'o' && square[9] == 'o')
        status = true;

    // DIAGONAL RIGHT-LEFT CHECK

    else if (square[3] == 'o' && square[5] == 'o' && square[7] == 'o')
        status = true;

    return status;
}

int main()
{
    grid();
    cout << "Enter number: ";
    player1();

    grid();

    int h = 0;

    while (h < 4)
    {
        cout << "Enter number: ";
        // player2();
        computer_easy();
        grid();
        if (win_check(square[m]) == true && win_check(square[q]) == true)
        {
            // cout << "Player 2 wins!" << endl;
            cout << "Computer wins!" << endl;
            break;
        }
        cout << "Enter number: ";
        player1();

        grid();
        if (win_check(square[m]) == true && win_check(square[q]) == true)
        {
            cout << "Player 1 wins!" << endl;
            break;
        }
        h++;
    }
    if (win_check(square[m]) == false && win_check(square[q]) == false)
        cout << "DRAW!" << endl;

    return 0;
}
