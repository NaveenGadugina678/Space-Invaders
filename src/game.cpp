#include "game.h"

Game::Game() {
}

Game::~Game() {
}

void Game::Draw() {
    spaceship.Draw();
}

void Game::HandleInput() {
    if (IsKeyDown(KEY_H)) {
        spaceship.MoveLeft();
    }else if (IsKeyDown(KEY_L)) {
        spaceship.MoveRight();
    }
}
