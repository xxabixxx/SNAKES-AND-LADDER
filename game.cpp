#include <iostream>
#include <map>
#include <cstdlib> // For rand() function
#include <ctime>   // For srand() function

class SnakeNLadder {
private:
    const static int WINPOINT = 100;
    std::map<int, int> snake;
    std::map<int, int> ladder;

public:
    SnakeNLadder() {
        // Constructor: Initialize snake and ladder positions
        snake[99] = 54;
        snake[70] = 55;
        snake[52] = 42;
        snake[25] = 2;
        snake[95] = 72;

        ladder[6] = 25;
        ladder[11] = 40;
        ladder[60] = 85;
        ladder[46] = 90;
        ladder[17] = 69;

        // Seed the random number generator
        std::srand(std::time(0));
    }

    int rollDice() {
        // Method to generate a random number between 1 to 6 (inclusive)
        return std::rand() % 6 + 1;
    }

    int calculatePlayerValue(int player, int diceValue) {
        // Method to calculate the new position of the player based on dice value
        player += diceValue;

        // Check for ladder
        if (ladder.find(player) != ladder.end()) {
            player = ladder[player];
        }

        // Check for snake
        if (snake.find(player) != snake.end()) {
            player = snake[player];
        }

        // Ensure the player does not go beyond the winning point
        if (player > WINPOINT) {
            player -= diceValue;
        }

        return player;
    }

    bool isWin(int player) {
        // Method to check if a player has reached the winning point
        return player == WINPOINT;
    }

    void startGame() {
        // Method to start the Snake and Ladder game
        int player1 = 0, player2 = 0; // Initial positions of players

        while (true) {
            int diceValue = rollDice(); // Roll the dice
            std::cout << "Dice Value: " << diceValue << std::endl;

            // Calculate new positions for both players
            player1 = calculatePlayerValue(player1, diceValue);
            player2 = calculatePlayerValue(player2, diceValue);

            // Print the current positions of players
            std::cout << "Player 1: " << player1 << ", Player 2: " << player2 << std::endl;

            // Check if any player has won
            if (isWin(player1)) {
                std::cout << "Player 1 Wins!" << std::endl;
                break;
            } else if (isWin(player2)) {
                std::cout << "Player 2 Wins!" << std::endl;
                break;
            }
        }
    }
};

int main() {
    SnakeNLadder s;
    s.startGame();

    return 0;
}
