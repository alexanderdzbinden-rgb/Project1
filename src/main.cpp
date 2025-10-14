#include "player.hpp"
#include "objects.hpp"
#include "inventory.hpp"


int main()
{	
	Color bg = {0, 45, 27, 255};
	InitWindow(1280, 720, "Template-4.0.0");
	SetTargetFPS(60);

	player player;
	inventory inventory;
	Rectangle obstacle = Rectangle{400, 500, 20, 20};
	object block[20];
	bool isColliding = false;
	bool isNear = false;
	
	while (!WindowShouldClose()) {
		player.Update(); // updates player position
		inventory.Update_selected_slot(); // updates what slot is selected in the inventory

		for (int j=0; j<20; j++){
			isColliding = CheckCollisionRecs(player.getRect(), block[j].get_obj_rect()); // checks every object to see if colliding
			isNear = CheckCollisionRecs(player.getNRect(), block[j].get_obj_rect()); // checks the single block raycast to see if it is colliding with a block
			if (isNear == true){
				player.DrawHB(isNear); // if raycast is in block check if we try to break the block
				if (player.UpdateKey(isNear, block[j].isbreakable()) == true){
					block[j].~object(); // destroys the object
					inventory.Update_slot(block[j]); // if we break it, this puts it in our inventory
				}
				break;
			}
			if (isColliding == true){
				player.Set_prev_pos(); // if we collide with an object, set the player back so it doesn't go into object
				break;
			}
		}
        BeginDrawing();
        ClearBackground(bg);
		for (int i=0; i < 20; i++){
			block[i].draw_obj(); // draws all objects
		}
		player.Draw_player();
		player.DrawHB(isNear);
		inventory.Draw_Inventory();
        EndDrawing();
    }
   	CloseWindow();
   	return 0;
}