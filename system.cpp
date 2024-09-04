#include "system.h"

#include <iostream>
#include <limits>

void ignoreline() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

char npcChoice() {
    srand((unsigned) time(NULL));

    int moves = 1 + (rand() % 3);

    switch (moves) {
        case 1: return 'R';
        case 2: return 'S';
        case 3: return 'P';

        default: return 'R';
    }
}

char playerChoice() {
    while (true) {
        char temp{};
        std::cout << "Choose between P,R,S only." << '\n';
        std::cout << "Your Turn: ";

        std::cin >> temp;

        if (!std::cin) {
            std::cin.clear();
            ignoreline();
        }

        switch (temp) {
            case 'R':   return 'R';
            case 'P':   return 'P';
            case 'S':   return 'S';

            default:    std::cout << "Please choose (R,P,S) only."; continue;
        }

    }
}

void checkWinner(char player, char npc) {
    std::cout << "You chosen " << player << " and NPC chosen " << npc << '\n';
    
    if (player == npc) 
        std::cout << "Tied, no one win!";
    else if ((player == 'R' && npc == 'P') || (player == 'P' && npc == 'R') || (player == 'S' && npc == 'P'))
        std::cout << "You Win!";
    else 
        std::cout << "You Lose!";
}

void initGame() {
    char player{};
    char npc{};

    std::cout << "Rock Paper Scissor Game" << '\n';
    std::cout << "Please Choose between R,S,P" << '\n';
    std::cout << "NPC Chosen a move." << '\n';

    npc = npcChoice();
    player = playerChoice();

    checkWinner(player, npc);
}


