#include "raylib.h"

#define PHYSAC_IMPLEMENTATION
#include "physac.h"

#define VELOCITY    0.7f

int main()
{
    int screenWidth = 1024;
    int screenHeight = 768;


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
        

        //DrawText("Use 'ARROWS' to move player", 10, 10, 10, WHITE);
        EndDrawing();
    }

    CloseWindow(); 

    return 0;
}