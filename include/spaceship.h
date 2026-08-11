#pragma once
#include <raylib.h>
#include "laser.h"
#include <vector>

class Spaceship {
    public:
        Spaceship(); // constructor.
        ~Spaceship();
        void Draw();
        void MoveLeft();
        void MoveRight();
        void FireLaser();
        Rectangle getRect();
        std::vector<Laser> lasers;
        void Reset();
    private:
        Texture2D image;
        Vector2 position;
        double lastFireTime;
        Sound laserSound;
};
