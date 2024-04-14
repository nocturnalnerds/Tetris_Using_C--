#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>
double lastUpdateTime = 0;

bool EventTriggerred(double interval){
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval){
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}



int main(){
    Color black = {0,0,0,0};
    InitWindow(500,620,"My Tetris");
    SetTargetFPS(60);
    Game game = Game();
    Font font = LoadFontEx("Font/monogram.ttf",64,0,0);
    
    int keyStart;
    int state = 1;
    while(WindowShouldClose() == false){
        UpdateMusicStream(game.Music);
        BeginDrawing();
        ClearBackground(black);
        // if(state == 1){
        //     DrawTextEx(font,"TETRIS", {120,250}, 80, 2, WHITE);
        //     if(!EventTriggerred(0.3)){
        //         DrawTextEx(font, "Press Enter To Play", {120, 330}, 30, 1.5, GREEN);
        //     }
        //     // DrawTextEx(font, "Press Enter To Play", {110, 330}, 30, 1.5, WHITE);
        //     keyStart = GetKeyPressed();
        //     if(keyStart == KEY_ENTER){
        //         state = 2;
        //     }else if(keyStart == KEY_T){
        //         state = 3;
        //     }
        // }else if(state == 3){
        //     DrawTextEx(font, "INI TUTORIAL", {110,330}, 30, 1.5, WHITE);
        // }else if(state`  == 2){
            game.HandleInput();
            if(game.Paused == false){
                if(EventTriggerred(0.2)){
                    game.MoveBlockDown();
                }
            }
            
            DrawTextEx(font,"Score", {365,10}, 38, 2, WHITE);
            DrawTextEx(font,"Next", {370,175}, 38, 2, WHITE);
            if(game.gameOver){
                DrawTextEx(font, "GAME OVER", {320, 450}, 38, 2, WHITE);
            }
            DrawRectangleRounded({320,60,170,60}, 0.3, 6, lightBlue);
            char scoreText[10];
            sprintf(scoreText, "%d", game.score);
            Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
            DrawTextEx(font,scoreText, {320 + (170 - textSize.x)/2,65}, 38, 2, WHITE);
            DrawRectangleRounded({320,220,170,180}, 0.3, 6, lightBlue);
            game.Draw();
        // }
        
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
