//
// Created by alex on 16.09.2021.
//

#ifndef GEMES_BLOCK_H
#define GEMES_BLOCK_H
#include <SFML/Graphics.hpp>
using namespace sf;
class block : public Sprite {
public:
    int kind{};
};
class bomb : public block {
public:
    
};


#endif //GEMES_BLOCK_H
