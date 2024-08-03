#include <stdio.h>
#include "raylib.h" 
#include <time.h>
#include <stdlib.h>

#define PHYSAC_IMPLEMENTATION
#include "physac.h"

#define VELOCITY    0.7f

int main()
{
    float screenWidth = 500.0;
    float screenHeight = 500.0; 
    float RectangleWidth = screenWidth / 20.0; 
    float RectangleHeight = screenHeight / 20.0; 
    float tileHeight = RectangleHeight; 
    float tileWidth = RectangleWidth; 
    //pixels 
    //INITIAL POSITION VECTOR IN WINDOW: 
    float x0 = screenWidth / 2 - (RectangleWidth / 2); 
    float y0 = screenHeight / 2 - (RectangleHeight / 2); 
    float x1 = x0; 
    float y1 = y0; 
    int scoreCounter = 0;



    InitWindow(screenWidth, screenHeight, "raygame");

    
    
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing(); 
        Color clearColor = BLACK;
        if (IsKeyDown(KEY_SPACE)){
            clearColor = WHITE;
        } 
        if (IsKeyDown(KEY_ENTER)){ 
            clearColor = RED;
        } 
        ClearBackground(clearColor);

        for (int i=1; i <= (screenHeight/tileHeight - 1); i++){ 
            DrawLine(0, i*tileHeight, screenWidth, i*tileHeight, WHITE);
        }
        for (int i=1; i <= (screenWidth/tileWidth - 1); i++){ 
            DrawLine(i*tileWidth, 0, i*tileWidth, screenHeight, WHITE);
        }

        
        //"Use 'WASD' to move player" 
        //DRAW SQUARE, MOVEMENT AND BORDER CHECK PART:  
        DrawRectangle(x1, y1, RectangleWidth, RectangleHeight, SKYBLUE);
        if (IsKeyDown(KEY_W) && (y1 - (RectangleHeight / 2) >= 0)){ 
            y1 = y1 - (RectangleHeight / 2); 
            x1 = x1;
        }  if (IsKeyDown(KEY_S) && (y1 + RectangleHeight < screenHeight)){ 
            y1 = y1 + (RectangleHeight / 2); 
            x1 = x1;
        }  if (IsKeyDown(KEY_A) && (x1 - (RectangleWidth / 2) >= 0)){ 
            y1 = y1; 
            x1 = x1 - (RectangleWidth / 2);
        } if (IsKeyDown(KEY_D) && (x1 + RectangleWidth < screenWidth)){ 
            y1 = y1; 
            x1 = x1 + (RectangleWidth / 2);
        }
           
        //--------------------------
        EndDrawing();
    }

    CloseWindow(); 

    return 0;
} 