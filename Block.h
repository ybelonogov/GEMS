//
// Created by alex on 16.09.2021.
//

#ifndef GEMES_BLOCK_H
#define GEMES_BLOCK_H
#include <SFML/Graphics.hpp>
#include <memory>

using namespace sf;
using namespace std;
class Block : public Sprite {
public:
    int kind{};
    int x;
    int y;
    virtual bool del( shared_ptr<Block>  field[10][10], vector<Texture> kinds) = 0;
};

class Classic : public Block {
public:
    bool del(shared_ptr<Block>  field[10][10], vector<Texture> kinds);
};

class Bomb : public Block {
public:
    bool del(shared_ptr<Block>  field[10][10], vector<Texture> kinds);
};
class Recolor : public Block {
public:
    bool del(shared_ptr<Block>  field[10][10], vector<Texture> kinds);
};



#endif //GEMES_BLOCK_H
