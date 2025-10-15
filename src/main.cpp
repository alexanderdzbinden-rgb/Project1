#include "player.hpp"
#include "objects.hpp"
#include "inventory.hpp"
#include <vector>


int main()
{	
	Color bg = {0, 45, 27, 255};
	InitWindow(1280, 720, "Template-4.0.0");
	SetTargetFPS(60);

	player player;
	inventory inventory;
	Rectangle obstacle = Rectangle{400, 500, 20, 20};
	object block[20];
	std::vector<object> bob;
	bob.emplace_back();
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
		bob[0].draw_obj();
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

/*  TO DO  */

/* Check when inventory is full, so when objects are broken they will sit on the screen instead of
	going into the inventory or disappearing. 
	
	We can also start to work on placing objects out of the inventory based on the selected slot.
	
	Furthermore would like to store objects in vectors instead, as this will be less storage usage or ram usage.  
*/