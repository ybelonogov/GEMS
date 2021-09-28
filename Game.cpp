//
// Created by alex on 17.09.2021.
//

#include <iostream>
#include "Game.h"

void Game::check() {

    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            if (field[x][y]) {
                for (int i = 0; i < 10; i++)
                    for (int j = 0; j < 10; j++)
                        used[i][j] = 0;
                vector<pair<int, int>> way;
                checkBrick(x, y,  field[x][y]->kind, way);
                if (way.size() >= 3)
                    for (auto i: way) {
                        if (field[i.first][i.second])
                            if (field[i.first][i.second]->del(field, kinds, i.first, i.second))
                                field[i.first][i.second] = nullptr;
                    }
            }
        }
    }

}

void
Game::checkBrick(int x, int y, int kind, vector<pair<int, int>> &way
) {
    way.push_back(make_pair(x, y));
    used[x][y] = 1;
    if (field[x - 1][y])
        if (x != 0 && field[x - 1][y]->kind == kind && used[x - 1][y] == 0) {
            checkBrick(x - 1, y, kind, way);
        }
    if (field[x + 1][y])
        if (x != 9 && field[x + 1][y]->kind == kind && used[x + 1][y] == 0) {
            checkBrick(x + 1, y,  kind, way);
        }
//
    if (field[x][y - 1])
        if (y != 0 && field[x][y - 1]->kind == kind && used[x][y - 1] == 0) {
            checkBrick(x, y - 1,  kind, way);
        }
    if (field[x][y + 1])
        if (y != 9 && field[x][y + 1]->kind == kind && used[x][y + 1] == 0) {
            checkBrick(x, y + 1,  kind, way);
        }

}


pair<int, int> Game::clickCheck(int mouseX, int mouseY) {
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            if (field[x][y])
                if (FloatRect(mouseX, mouseY, 1, 1).intersects(field[x][y]->getGlobalBounds())) {
                    cout << x << "    " << y << endl;
                    return (make_pair(x, y));
                }
        }
    }
    return (make_pair(-1, -1));
}

void Game::my_swap(shared_ptr<Block> a, shared_ptr<Block> b) {
    shared_ptr<Block> tmp = a;
    a = b;
    b = tmp;
    string s;

}

void Game::start() {

    Image all_textures;
    all_textures.loadFromFile("/home/alex/Desktop/Cplusplus/GEMS/images/allTiles_sheet.png");
    for (int i = 0; i < colorCount; i++) {
        Texture tmp;
        auto area = Rect(left + rand() % 9 * (Weight + 1), top + i * (Height + 1), Weight, Height);
        tmp.loadFromImage(all_textures, area);
        kinds.push_back(tmp);
    }

    for (int x = 0; x < M; x++) {
        for (int y = 0; y < N; y++) {
            int kind = rand() % colorCount;
            int type = rand() % 3;
//            if (type == 1)
            if (true)
                field[x][y] = make_shared<Classic>();
            else if (type == 2)
                field[x][y] = make_shared<Recolor>();
            else
                field[x][y] = make_shared<Bomb>();
            field[x][y]->setTexture(kinds[kind]);
            field[x][y]->setPosition(x * Weight, y * Height);
            field[x][y]->kind = kind;

        }
    }

}

void Game::play() {
    pair<int, int> stack = make_pair(-1, -1);
    RenderWindow app(VideoMode(Weight * M, Height * N), "GEMS");
    app.setFramerateLimit(60);
    while (app.isOpen()) {
        Event event;

        while (app.pollEvent(event)) {
            if (event.type == Event::Closed)
                app.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape)) app.close();
        if (event.type == sf::Event::MouseButtonPressed) {
//            cerr << 1 << endl;
            if (event.mouseButton.button == Mouse::Left) {

                int mouse_x = event.mouseButton.x;
                int mouse_y = event.mouseButton.y;
//                cout << mouse_x << " " << mouse_y << endl;
                pair<int, int> cord = clickCheck(mouse_x, mouse_y);
//                cout << cord.first << " " << cord.second << endl << endl;
                if (stack != make_pair(-1, -1) && stack != cord) {
                    swap(field[cord.first][cord.second], field[stack.first][stack.second]);
//                    my_swap(field[cord.first][cord.second], field[stack.first][stack.second]);
                    cout << cord.first << " " << cord.second << endl;
                    cout << stack.first << " " << stack.second << endl;
                    stack = make_pair(-1, -1);
                    cout << endl;

//                    fildInfo();
                } else
                    stack = cord;
            }
        }
        shift();
        app.clear();
//        fildInfo();
        cout<<endl;
        for (int x = 0; x < M; x++) {
            for (int y = 0; y < N; y++) {
                if (field[x][y]) {
                    field[x][y]->setTexture(kinds[field[x][y]->kind]);
                    app.draw(*field[x][y]);
                    cout << field[y][x]->kind << " ";
                }
            }
            cout<<endl;
        }
        app.display();

    }

}

void Game::shift() {

    bool changes = true;
    int col = 0;
    while (changes) {
        changes = false;

        check();

//        cout << "check " << col << endl;
        col = 0;
        for (int x = 0; x < M; x++) {
            vector<shared_ptr<Block>> newColumn;
            for (int y = 0; y < N; y++) {
                if (field[x][y]) {
                    col++;
                    newColumn.push_back(field[x][y]);
                }
            }
            for (int y = 0; y < newColumn.size(); y++) {
                field[x][y] = newColumn[y];


            }
            for (int y = newColumn.size(); y < N; y++) {
                field[x][y] = nullptr;
            }
            if (newColumn.size() < N)
                changes = true;
            for (int y = newColumn.size(); y < N; y++) {
                int kind = rand() % colorCount;
                int type = rand() % 3;
//                if (type == 1)
                if (true)
                    field[x][y] = make_shared<Classic>();
                else if (type == 2)
                    field[x][y] = make_shared<Recolor>();
                else
                    field[x][y] = make_shared<Bomb>();
                field[x][y]->setTexture(kinds[kind]);
                field[x][y]->setPosition(x * Weight, y * Height);
                field[x][y]->kind = kind;

            }
            vector<shared_ptr<Block>>().swap(newColumn);
        }
    }
//    cout << "shift" << endl;


}

void Game::fildInfo() {
    for (int x = 0; x < 10; x++) {
        cout << endl;
        for (int y = 0; y < 10; y++) {
            if (field[x][y])
//                cout << field[y][x]->getTexture()->getMaximumSize() << " ";
                cout << field[y][x]->kind << " ";
            else
                cout << -1 << " ";
        }
    }
    cout << endl;
};