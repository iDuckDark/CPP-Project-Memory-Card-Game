//
// Created by iDarkDuck on 2018-10-19.
//

#ifndef CPP_PROJECT_MEMORY_GAME_BOARD_H
#define CPP_PROJECT_MEMORY_GAME_BOARD_H

//Design a class Board which holds an array of strings corresponding to the screen display of the game.
class Board {
    bool isFaceUp(const char &Letter, const int &Number) const;

    bool turnFaceUp(const char &Letter, const int &Number);
};

#endif //CPP_PROJECT_MEMORY_GAME_BOARD_H
