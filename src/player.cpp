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
    if(IsKeyPressed(KEY_RIGHT)){
			position.x += 20;
			prev_position.x = position.x - 20;
			prev_position.y = position.y;
			ray_pos.x = position.x + 20;
			ray_pos.y = position.y;
			orientation = 1;
		}
		else if(IsKeyPressed(KEY_LEFT)){
			position.x -= 20;
			prev_position.x = position.x + 20;
			prev_position.y = position.y;
			ray_pos.x = position.x - 20;
			ray_pos.y = position.y;
			orientation = 2;
		}
		else if(IsKeyPressed(KEY_UP)){
			position.y -= 20;
			prev_position.y = position.y + 20;
			prev_position.x = position.x;
			ray_pos.x = position.x;
			ray_pos.y = position.y - 20;
			orientation = 3;
		}
		else if(IsKeyPressed(KEY_DOWN)){
			position.y += 20;
			prev_position.y = position.y - 20;
			prev_position.x = position.x;
			ray_pos.x = position.x;
			ray_pos.y = position.y + 20;
			orientation = 4;
		}
}

bool player::UpdateKey(bool isnear, bool breakable){
	if (IsKeyPressed(KEY_R) && isnear == true && breakable == true){
		return true;
	}
	else{
		return false;
	}
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
		ray_pos.x = position.x + 20;
		ray_pos.y = position.y;
		break;
	case 2:
		ray_pos.x = position.x - 20;
		ray_pos.y = position.y;
		break;
	case 3:
		ray_pos.x = position.x;
		ray_pos.y = position.y - 20;
		break;
	case 4:
		ray_pos.x = position.x;
		ray_pos.y = position.y + 20;
		break;
	
	default:
		break;
	}
}

int player::get_orientation(){
    return orientation;
}
