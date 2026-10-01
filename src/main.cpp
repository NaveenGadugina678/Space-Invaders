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
    InitAudioDevice();

    SetTargetFPS(60);
    
    Font font = LoadFontEx("fonts/VPPixel.otf", 64, 0, 0);
    Texture2D background = LoadTexture("graphics/background.jpg");
    Texture2D life = LoadTexture("graphics/life.png");

    Game game;

    while(WindowShouldClose() == false) {
        UpdateMusicStream(game.music);
        game.HandleInput();
        game.Update();
        BeginDrawing();
        DrawTexture(background, 0, 0, WHITE);
        DrawRectangleRoundedLines({10, 10, 760, 740}, 0.18f, 20, yellow);
        DrawLineEx({20, 670}, {760, 670}, 3, yellow);
        if (game.run) {
            std::string curr_level = "LEVEL " + std::to_string(game.level);
            DrawTextEx(font, curr_level.c_str(), {600, 700}, 30, 1.0f, yellow);
        }else {
            DrawTextEx(font, "GAME OVER", {600, 700}, 30, 1.0f, yellow);
        }
        
        float x = 50.0f;
        for (int i = 0 ; i < game.lives ; i++) {
            DrawTextureV(life, {x, 700}, WHITE);
            x += 50.0f;
        }

        DrawTextEx(font, "SCORE", {50, 15}, 34, 2.0f, yellow);
        std::string scoreText = FormatWithLeadingZeros(game.score, 5);
        DrawTextEx(font, scoreText.c_str(), {55, 50}, 34, 2.0f, yellow);
        
        DrawTextEx(font, "HIGH-SCORE", {590, 15}, 34, 2.0f, yellow);
        std::string highscoreText = FormatWithLeadingZeros(game.highscore, 5);
        DrawTextEx(font, highscoreText.c_str(), {630, 50}, 34, 2.0f, yellow);

        game.Draw();
        EndDrawing();
    }

    CloseWindow();
    CloseAudioDevice();
}
