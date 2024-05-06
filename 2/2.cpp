#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

class FifteenPuzzle {
private:
    static const int SIZE = 4;
    char board[SIZE][SIZE];
    int emptyRow, emptyCol;
public:
    FifteenPuzzle() {
        srand(time(0));
        reset();
    }

    void reset() {
        char num = '1';
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                board[i][j] = num++;
            }
        }
        board[SIZE - 1][SIZE - 1] = ' ';
        emptyRow = SIZE - 1;
        emptyCol = SIZE - 1;

        for (int i = 0; i < SIZE * SIZE; ++i) {
            int randRow = rand() % SIZE;
            int randCol = rand() % SIZE;
            char temp = board[randRow][randCol];
            board[randRow][randCol] = board[emptyRow][emptyCol];
            board[emptyRow][emptyCol] = temp;
            emptyRow = randRow;
            emptyCol = randCol;
        }
    }

    void display() {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                std::cout << std::setw(3) << board[i][j];
            }
            std::cout << std::endl;
        }
    }

    bool moveTile(char tile) {
        int dx[] = { -1, 1, 0, 0 };
        int dy[] = { 0, 0, -1, 1 };

        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (board[i][j] == tile) {
                    for (int k = 0; k < 4; ++k) {
                        int newRow = i + dx[k];
                        int newCol = j + dy[k];
                        if (newRow >= 0 && newRow < SIZE && newCol >= 0 && newCol < SIZE &&
                            board[newRow][newCol] == ' ') {
                            board[newRow][newCol] = tile;
                            board[i][j] = ' ';
                            emptyRow = i;
                            emptyCol = j;
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    bool isSolved() {
        char num = '1';
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (board[i][j] != num % (SIZE * SIZE))
                    return false;
                num++;
            }
        }
        return true;
    }
};

int main() {
    FifteenPuzzle puzzle;
    char tile;
    while (!puzzle.isSolved()) {
        puzzle.display();
        std::cout << "Enter the number of tile to move (1-15): ";
        std::cin >> tile;
        if (tile < '1' || tile > '9' + FifteenPuzzle::SIZE * FifteenPuzzle::SIZE) {
            std::cout << "Invalid input!" << std::endl;
            continue;
        }
        if (!puzzle.moveTile(tile))
            std::cout << "Invalid move!" << std::endl;
    }
    std::cout << "Congratulations! You solved the puzzle!" << std::endl;
    return 0;
}
