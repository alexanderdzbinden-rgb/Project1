#include "player.hpp"

player::player(){
    position.x = 320;
    position.y = 540;
    size.x = 20;
    size.y = 20;

}

player::~player(){

}

void player::Draw_player(){
    DrawRectangleV(position, size, WHITE);
}

void player::Update(){
    if(IsKeyDown(KEY_RIGHT)){
			position.x += 1;
			prev_position.x = position.x - 1;
			prev_position.y = position.y;
			ray_pos.x = position.x + 1;
			ray_pos.y = position.y;
			orientation = 1;
		}
		else if(IsKeyDown(KEY_LEFT)){
			position.x -= 1;
			prev_position.x = position.x + 1;
			prev_position.y = position.y;
			ray_pos.x = position.x - 1;
			ray_pos.y = position.y;
			orientation = 2;
		}
		else if(IsKeyDown(KEY_UP)){
			position.y -= 1;
			prev_position.y = position.y + 1;
			prev_position.x = position.x;
			ray_pos.x = position.x;
			ray_pos.y = position.y - 1;
			orientation = 3;
		}
		else if(IsKeyDown(KEY_DOWN)){
			position.y += 1;
			prev_position.y = position.y - 1;
			prev_position.x = position.x;
			ray_pos.x = position.x;
			ray_pos.y = position.y + 1;
			orientation = 4;
		}
}

bool player::UpdateKey(bool isnear, bool breakable, bool isfull){
	if (IsKeyPressed(KEY_R) && isnear == true && breakable == true){
		if(isfull == true){
			return false;
		}
		else{
			return true;
		}
	}
	else{
		return false;
	}
}

bool player::PlaceObj(bool isNear, bool isfull){
	if(IsKeyPressed(KEY_T) && isNear == false && isfull == true){
		return true;
		//need to access inventory here and delete the object from selected slot, and also add it to the object list.
		//Should use vectors for the objects now so we can append, and keep track of that length to iterate accordingly each instance.
	}
    return false;
}

Rectangle player::getRect(){
    return Rectangle{position.x, position.y, 20, 20};
}

Rectangle player::getNRect(){
    return Rectangle{ray_pos.x, ray_pos.y, 20, 20};
}

void player::DrawHB(bool isColliding){
	Color outline = isColliding ? RED : BLACK;
	DrawRectangleLinesEx(getNRect(), 3, outline);
}

void player::Set_prev_pos(){
	position.x = prev_position.x;
	position.y = prev_position.y;
	switch (orientation)
	{
	case 1:
		ray_pos.x = position.x + 1;
		ray_pos.y = position.y;
		break;
	case 2:
		ray_pos.x = position.x - 1;
		ray_pos.y = position.y;
		break;
	case 3:
		ray_pos.x = position.x;
		ray_pos.y = position.y - 1;
		break;
	case 4:
		ray_pos.x = position.x;
		ray_pos.y = position.y + 1;
		break;
	
	default:
		break;
	}
}

int player::get_orientation(){
    return orientation;
}
