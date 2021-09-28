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
//    int left = 0;
//    int top = 0;
////    const int M = 10;
////    const int N = 10;
//    const int Weight = 111;
//    const int Height = 128;
//    const int color_count = 6;
//    RenderWindow app(VideoMode(Weight * M, Height * N), "GEMS");
//    app.setFramerateLimit(60);
//    Image all_textures;
//    all_textures.loadFromFile("/home/alex/Desktop/Cplusplus/GEMS/images/allTiles_sheet.png");
//    vector<Texture> kinds;
//    for (int i = 0; i < color_count; i++) {
//        Texture tmp;
//        auto area = Rect(left + rand() % 9 * (Weight + 1), top + i * (Height + 1), Weight, Height);
//        tmp.loadFromImage(all_textures, area);
//        kinds.push_back(tmp);
//    }
//    shared_ptr<Block> field[M][N];
//    for (int x = 0; x < M; x++) {
//        for (int y = 0; y < N; y++) {
//            int kind = rand() % color_count;
//            int type = rand() % 3;
//            if (type == 1)
//                field[x][y] = make_shared<Bomb>();
//            else if (type == 2)
//                field[x][y] = make_shared<Recolor>();
//            else
//                field[x][y] = make_shared<Classic>();
//            field[x][y]->setTexture(kinds[kind]);
//            field[x][y]->setPosition(x * Weight, y * Height);
//            field[x][y]->kind = kind;
//            field[x][y]->x = x;
//            field[x][y]->y = y;
//        }
//    }
////    cout<<(1300+420)/4;
//    pair<int, int> stack = make_pair(-1, -1);
//    while (app.isOpen()) {
//        Event event;
//
//        while (app.pollEvent(event)) {
//            if (event.type == Event::Closed)
//                app.close();
//        }
//        if (Keyboard::isKeyPressed(Keyboard::Escape)) app.close();
//        if (event.type == sf::Event::MouseButtonPressed) {
////            cerr << 1 << endl;
//            if (event.mouseButton.button == Mouse::Left) {
//
//                int mouse_x = event.mouseButton.x;
//                int mouse_y = event.mouseButton.y;
//                cout <<  mouse_x<< " " <<  mouse_y << endl;
//                pair<int, int> cord = clickCheck(field, mouse_x, mouse_y);
//                cout << cord.first << " " << cord.second << endl<<endl;
//                if (stack != make_pair(-1, -1) && stack != cord) {
//                    swap(field[cord.first][cord.second], field[stack.first][stack.second]);
////                    my_swap(field[cord.first][cord.second], field[stack.first][stack.second]);
//                    cout << cord.first << " " << cord.second << endl;
//                    cout << stack.first << " " << stack.second << endl;
//                    stack = make_pair(-1, -1);
//                    cout << endl;
//                } else
//                    stack = cord;
//            }
//        }
//        check(field, kinds);
//        app.clear();
////        field[2][3]->del(field,kinds);
//
//        for (int x = 0; x < M; x++) {
//            for (int y = 0; y < N; y++) {
//                if (field[x][y])
//                    //                if (x!=5 or y!=5 )
//                    app.draw(*field[x][y]);
//            }
//        }
////        test( field);
//        app.display();
//
//    }
//    return 0;
//}
