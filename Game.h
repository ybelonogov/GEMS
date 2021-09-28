//
// Created by alex on 17.09.2021.
//

#ifndef GEMS_GAME_H
#define GEMS_GAME_H
#include <SFML/Graphics.hpp>
#include "Block.h"

using namespace sf;
using namespace std;
class Game{
    int left = 0;
    int top = 0;
    static const int M = 10;
    static const int N = 10;
    const int Weight = 111;
    const int Height = 128;
    const int colorCount = 7;
    shared_ptr<Block> field[M][N];
    vector<Texture> kinds;
    bool used[10][10];
    void
    checkBrick(int x, int y,  int kind, vector<pair<int, int>> &way);
    void shift();
    pair<int,int> clickCheck( int mouseX, int mouseY);
    void my_swap(shared_ptr<Block> a,shared_ptr<Block> b);
    void check();
    void fildInfo();
public:
    void start();
    void play();

};

#endif //GEMS_GAME_H
