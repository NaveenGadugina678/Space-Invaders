#include "raylib.h"
#include "game.h"

int main() {
    Color grey = {29, 29, 27, 255};
    Color yellow = {243, 216, 63, 255};
    int offset = 30;
    int windowWidth = 750;
    int windowHeight = 700;

    InitWindow(windowWidth + offset, windowHeight + 2 * offset, "Space-Invaders");
    SetTargetFPS(60);
    
    Font font = LoadFontEx("font/dogica.ttf", 64, 0, 0);
    Texture2D background = LoadTexture("graphics/background.jpg");
    Texture2D life = LoadTexture("graphics/life.png");

    Game game;

    while(WindowShouldClose() == false) {
        game.HandleInput();
        game.Update();
        BeginDrawing();
        DrawTexture(background, 0, 0, WHITE);
        DrawRectangleRoundedLines({10, 10, 760, 740}, 0.18f, 20, yellow);
        DrawLineEx({20, 670}, {760, 670}, 3, yellow);
        if (game.run) {
            DrawTextEx(font, "LEVEL 01", {600, 700}, 20, 1f, yellow);
        }else {
            DrawTextEx(font, "GAME OVER", {600, 700}, 20, 1f, yellow);
        }
        
        float x = 50.0f;
        for (int i = 0 ; i < game.lives ; i++) {
            DrawTextureV(life, {x, 700}, WHITE);
            x += 50.0f;
        }
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}
