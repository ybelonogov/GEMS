#include <iostream>
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <time.h>
//#include "Block.h"
#include "Game.h"

const int M = 10;
const int N = 10;

void test(shared_ptr<Block> filed[10][10]) {
    for (int x = 0; x < M; x++) {
        for (int y = 0; y < N; y++) {
            filed[x][y] = nullptr;
        }
    }
}

int main() {
    srand(time(nullptr));
    Game GEMS;
    GEMS.start();
    GEMS.play();
    return 0;
}

