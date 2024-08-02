#include <stdio.h>
#include "raylib.h" 

#define PHYSAC_IMPLEMENTATION
#include "physac.h"

#define VELOCITY    0.7f

int main()
{
    int screenWidth = 800;
    int screenHeight = 600; 
    int RectangleWidth = screenWidth / 20; 
    int RectangleHeight = screenHeight / 20;
    //pixels 
    //INITIAL POSITION VECTOR IN WINDOW: 
    int x0 = screenWidth / 2 - (RectangleWidth / 2); 
    int y0 = screenHeight / 2 - (RectangleHeight / 2); 
    //MOVEMENT X,Y: /better in float, maybe?
    int x1 = x0; 
    int y1 = y0;


    InitWindow(screenWidth, screenHeight, "raygame");

    
    
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing(); 
        if (IsKeyDown(KEY_SPACE)){
            ClearBackground(WHITE);
        } 
        else{ 
            if (IsKeyDown(KEY_ENTER)){ 
                ClearBackground(RED);
            } 
            else{ 
                ClearBackground(BLACK);
            }
            }
        
        //"Use 'WASD' to move player" 
        //DRAW SQUARE, MOVEMENT AND BORDER CHECK PART:  
        DrawRectangle(x1, y1, RectangleWidth, RectangleHeight, SKYBLUE);
        if (IsKeyDown(KEY_W) && (y1 - (RectangleHeight / 2) >= 0)){ 
            y1 = y1 - (RectangleHeight / 2); 
            x1 = x1;
        } else if (IsKeyDown(KEY_S) && (y1 + RectangleHeight < screenHeight)){ 
            y1 = y1 + (RectangleHeight / 2); 
            x1 = x1;
        } else if (IsKeyDown(KEY_A) && (x1 - (RectangleWidth / 2) >= 0)){ 
            y1 = y1; 
            x1 = x1 - (RectangleWidth / 2);
        } else if (IsKeyDown(KEY_D) && (x1 + RectangleWidth < screenWidth)){ 
            y1 = y1; 
            x1 = x1 + (RectangleWidth / 2);
        }


        //--------------------------
        EndDrawing();
    }

    CloseWindow(); 

    return 0;
} 