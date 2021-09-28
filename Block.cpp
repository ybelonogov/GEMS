//
// Created by alex on 16.09.2021.
//

#include "Block.h"

bool Classic::del(shared_ptr<Block> field[10][10], vector<Texture> kinds,int x,int y) {
    return true;
}

bool Bomb::del(shared_ptr<Block> field[10][10], vector<Texture> kinds,int x,int y) {
    for (int i = 0; i < 5; i++) {
        int x = rand() % 10;
        int y = rand() % 10;
        if (field[x][y])
            i--;
        field[x][y] =nullptr;
    }
    return true;
}

bool Recolor::del(shared_ptr<Block> field[10][10], vector<Texture> kinds,int x,int y) {
    for (int i = 0; i < 2; i++) {
        int xx = rand() % 10;
        int yy = rand() % 10;
        if (abs(x - xx) < 2 and abs(y - yy) < 2)
            i--;
        else if (field[xx][yy]) {
            int new_type = (kind + rand() % 4) % 5;
            field[xx][yy]->kind = new_type;
            field[xx][yy]->setTexture(kinds[new_type]);
        }
    }
    if (field[x][y]) {
        int new_type = (kind + rand() % 4) % 5;
        field[x][y]->kind = new_type;
        field[x][y]->setTexture(kinds[new_type]);
    }

    return true;
}



