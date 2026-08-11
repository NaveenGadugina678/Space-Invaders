#include "spaceship.h"

Spaceship::Spaceship() {
    image = LoadTexture("Graphics/spaceship.png");
    position.x = (GetScreenWidth() - image.width * 0.1f) / 2;
    position.y = GetScreenHeight() - image.height * 0.1f - 100;
    lastFireTime = 0.0;
    laserSound = LoadSound("sound/laser.ogg");
}

Spaceship::~Spaceship() {
    UnloadTexture(image);
    UnloadSound(laserSound);
}

void Spaceship::Draw() {
    DrawTextureEx(image, position, 0.0f, 0.1f, WHITE);
}

void Spaceship::MoveLeft() {
    position.x -= 7;
    if (position.x < 10) position.x = 10;
}

void Spaceship::MoveRight() {
    position.x += 7;
    if (position.x + 10 > GetScreenWidth() - image.width * 0.1f) position.x = GetScreenWidth() - image.width * 0.1f - 10; 
}

void Spaceship::FireLaser() {
    if (GetTime() - lastFireTime >= 0.35) {
        lasers.push_back(Laser({position.x + (image.width * 0.1f) / 2 - 2, position.y}, -6));
        lastFireTime = GetTime();
        PlaySound(laserSound);
    }
}

Rectangle Spaceship::getRect() {
    return {position.x, position.y, float(image.width * 0.1f), float(image.height * 0.1f)};
}

void Spaceship::Reset() {
    position.x = (GetScreenWidth() - image.width * 0.1f) / 2.0f;
    position.y = GetScreenHeight() - image.height * 0.1f - 100;
    lasers.clear();
}
