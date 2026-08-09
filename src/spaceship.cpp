#include "spaceship.h"

Spaceship::Spaceship() {
    image = LoadTexture("Graphics/spaceship.png");
    position.x = (GetScreenWidth() - image.width * 0.1f) / 2;
    position.y = GetScreenHeight() - image.height * 0.1f;
}

Spaceship::~Spaceship() {
    UnloadTexture(image);
}

void Spaceship::Draw() {
    DrawTextureEx(image, position, 0.0f, 0.1f, WHITE);
}

void Spaceship::MoveLeft() {
    position.x -= 7;
    if (position.x < 0) position.x = 0;
}

void Spaceship::MoveRight() {
    position.x += 7;
    if (position.x > GetScreenWidth() - image.width * 0.1f) position.x = GetScreenWidth() - image.width * 0.1f;
}
