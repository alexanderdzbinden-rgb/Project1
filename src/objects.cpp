#include "objects.hpp"
#include "inventory.hpp"
#include <cstdlib>

object::object(){
    obj_pos.x = ((rand() % 20)*20 + 360);
    obj_pos.y = ((rand() % 50)*20 + 360); 
    obj_size.x = 20;
    obj_size.y = 20;
    breakable = true;
}

object::~object(){
    dontdraw = true;
    obj_pos.x = 0;
    obj_pos.y = 0;
    obj_size.x = 0;
    obj_size.y = 0;
}

object::object(object &obj){
    obj_pos.x = obj.obj_pos.x;
    obj_pos.y = obj.obj_pos.y;
    breakable = obj.breakable;
    dontdraw = obj.dontdraw;
    ininv = obj.ininv;
}

void object::draw_obj(){
    if (dontdraw == false){
        DrawRectangleV(obj_pos, obj_size, GREEN);
    }
    else{
        ininv = true;
        return;
    }
}

void object::draw_in_inv(Vector2 position, Vector2 size){
    if (ininv == true){
        DrawRectangleV(position, size, GREEN);
    }
    return;
}

void object::update_obj(){
    DrawRectangleV(obj_pos, obj_size, RED);
    dontdraw = true;
    
}

Rectangle object::get_obj_rect(){
    return Rectangle{obj_pos.x, obj_pos.y, obj_size.x, obj_size.y};
}

bool object::isbreakable(){
    return breakable;
}

bool object::ininventory()
{
    return ininv;
}
