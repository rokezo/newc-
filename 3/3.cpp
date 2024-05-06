#include <iostream>
#include <vector>

class TicTacToe {
private:
    static const int SIZE = 3;
    char board[SIZE][SIZE];
    char currentPlayer;
public:
    TicTacToe() {
        reset();
    }

    void reset() {
        currentPlayer = 'X';
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                board[i][j] = '-';
            }
        }
    }

    void display() {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != '-')
            return false;
        board[row][col] = currentPlayer;
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        return true;
    }

    bool checkWin() {
        for (int i = 0; i < SIZE; ++i) {
            if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
                return true;
            if (board[0][i] != '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
                return true;
        }
        if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
            return true;
        if (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
            return true;
        return false;
    }

    bool isDraw() {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (board[i][j] == '-')
                    return false;
            }
        }
        return true;
    }
};

int main() {
    TicTacToe game;
    int row, col;
    std::cout << "Welcome to Tic Tac Toe!" << std::endl;
    while (!game.checkWin() && !game.isDraw()) {
        std::cout << "Current board:" << std::endl;
        game.display();
        std::cout << "Player " << game.getCurrentPlayer() << "'s turn. Enter row and column (0-2): ";
        std::cin >> row >> col;
        if (!game.makeMove(row, col)) {
            std::cout << "Invalid move! Try again." << std::endl;
        }
    }
    std::cout << "Final board:" << std::endl;
    game.display();
    if (game.checkWin()) {
        std::cout << "Player " << game.getCurrentPlayer() << " wins!" << std::endl;
    }
    else {
        std::cout << "It's a draw!" << std::endl;
    }
    return 0;
}
