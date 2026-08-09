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
        std::vector<Laser> lasers;
    private:
        Texture2D image;
        Vector2 position;
        double lastFireTime;
};
