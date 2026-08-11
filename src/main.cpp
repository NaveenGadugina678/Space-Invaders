#include "raylib.h"
#include "game.h"
#include <string>

std::string FormatWithLeadingZeros(int num, int width) {
    std::string numText = std::to_string(num);
    int leadingZeros = width - numText.length();
    numText = std::string(leadingZeros, '0') + numText;
    
    return numText;
}

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
            DrawTextEx(font, "LEVEL 01", {600, 700}, 20, 1.0f, yellow);
        }else {
            DrawTextEx(font, "GAME OVER", {600, 700}, 20, 1.0f, yellow);
        }
        
        float x = 50.0f;
        for (int i = 0 ; i < game.lives ; i++) {
            DrawTextureV(life, {x, 700}, WHITE);
            x += 50.0f;
        }

        DrawTextEx(font, "SCORE", {50, 15}, 34, 2.0f, yellow);
        std::string scoreText = FormatWithLeadingZeros(game.score, 5);
        DrawTextEx(font, scoreText.c_str(), {58, 40}, 34, 2.0f, yellow);

        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}
