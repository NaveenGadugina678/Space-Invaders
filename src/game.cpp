#include "game.h"

Game::Game() {
    obstacles = CreateObstacles();
}

Game::~Game() {
}

void Game::Update() {
    for (auto& laser : spaceship.lasers) {
        laser.Update();
    }
    
    DeleteInactiveLasers();
}

void Game::Draw() {
    spaceship.Draw();

    for (auto& laser : spaceship.lasers) {
        laser.Draw();
    }

    for (auto& obstacle : obstacles) {
        obstacle.Draw();
    }
}

void Game::HandleInput() {
    if (IsKeyDown(KEY_H)) {
        spaceship.MoveLeft();
    }else if (IsKeyDown(KEY_L)) {
        spaceship.MoveRight();
    }else if (IsKeyDown(KEY_SPACE)) {
        spaceship.FireLaser();
    }
}

void Game::DeleteInactiveLasers() {
    for (auto it = spaceship.lasers.begin(); it != spaceship.lasers.end();) {
        if (!it -> active) {
            it = spaceship.lasers.erase(it);
        }else {
            ++it;
        }
    }
}

std::vector<Obstacle> Game::CreateObstacles() {
    int obstacleWidth = Obstacle::grid[0].size();
    float gap = (GetScreenWidth() - (4 * obstacleWidth)) / 5;
    for (int i = 0 ; i < 4 ; i++) {
        float offsetX = (i + 1) * gap;
        obstacles.push_back(Obstacle({offsetX, float(GetScreenHeight() - 100)}));
    }

    return obstacles;
}
