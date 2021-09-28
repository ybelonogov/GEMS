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
    int kind;
    virtual bool del( shared_ptr<Block>  field[10][10], vector<Texture> kinds,int x,int y) = 0;
};

class Classic : public Block {
public:
    bool del(shared_ptr<Block>  field[10][10], vector<Texture> kinds,int x,int y);
};

class Bomb : public Block {
public:
    bool del(shared_ptr<Block>  field[10][10], vector<Texture> kinds,int x,int y);
};
class Recolor : public Block {
public:
    bool del(shared_ptr<Block>  field[10][10], vector<Texture> kinds,int x,int y);
};



#endif //GEMES_BLOCK_H
