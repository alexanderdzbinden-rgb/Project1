#pragma once
#include "raylib.h"
#include "raymath.h"


int main()
{	
	Color bg = {0, 45, 27, 255};
	InitWindow(1280, 720, "Template-4.0.0");
	SetTargetFPS(60);
	
	while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(bg);
        EndDrawing();
    }
   	CloseWindow();
   	return 0;
}

/*  TO DO  */

/*  
*/