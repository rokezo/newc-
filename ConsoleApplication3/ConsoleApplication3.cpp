#include <iostream>
#include <vector>

class Chessboard {
private:
    static const int SIZE = 8;
    int board[SIZE][SIZE];
    int moves[8][2] = { {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1} };
public:
    Chessboard() {
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                board[i][j] = 0;
    }

    void display() {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j)
                std::cout << board[i][j] << " ";
            std::cout << std::endl;
        }
    }

    bool solveKnightTour(int x, int y, int moveCount) {
        if (moveCount == SIZE * SIZE) {
            board[x][y] = moveCount;
            display();
            return true;
        }
        for (int i = 0; i < 8; ++i) {
            int nextX = x + moves[i][0];
            int nextY = y + moves[i][1];
            if (isValidMove(nextX, nextY) && board[nextX][nextY] == 0) {
                board[x][y] = moveCount;
                if (solveKnightTour(nextX, nextY, moveCount + 1))
                    return true;
                board[x][y] = 0;
            }
        }
        return false;
    }

    bool isValidMove(int x, int y) {
        return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
    }
};

int main() {
    Chessboard chessboard;
    int startX, startY;
    std::cout << "Enter starting position of knight (x y): ";
    std::cin >> startX >> startY;
    if (startX < 0 || startX >= Chessboard::SIZE || startY < 0 || startY >= Chessboard::SIZE) {
        std::cout << "Invalid starting position!" << std::endl;
        return 1;
    }
    chessboard.solveKnightTour(startX, startY, 1);

    return 0;
}
