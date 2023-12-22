#include <iostream>
#include <vector>
using namespace std;

void displayBoard(const vector<vector<char> >& board) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool checkWin(const vector<vector<char> >& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

bool checkDraw(const vector<vector<char> >& board) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char> > board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';

    do {
        displayBoard(board);

        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;

            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            if (checkDraw(board)) {
                displayBoard(board);
                cout << "It's a draw!\n";
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move. Try again.\n";
        }

    } while (true);

    return 0;
}
