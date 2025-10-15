#include "objects.hpp"
#include "inventory.hpp"
#include <cstdlib>
#include <vector>

object::object(){
    obj_pos.x = ((rand() % 20)*20 + 360);
    obj_pos.y = ((rand() % 50)*20 + 360); 
    obj_size.x = 20;
    obj_size.y = 20;
    breakable = true;
}

//Constructor for objects, same size for now, and position is randomized. All objects are also breakable right now.

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

// Copy constructor for objects, used to put into inventory slots.

void object::draw_obj(){
    if (dontdraw == false){
        DrawRectangleV(obj_pos, obj_size, GREEN);
    }
    else{
        ininv = true;
        return;
    }
}

// Draws object on screen

void object::draw_in_inv(Vector2 position, Vector2 size){
    if (ininv == true){
        DrawRectangleV(position, size, GREEN);
    }
    return;
}

//This draws the object in the inventory if we have broken the object. Also should check later if inventory is full first.

void object::update_obj(){
    DrawRectangleV(obj_pos, obj_size, RED);
    dontdraw = true;
    
}

// Checks to see if object is broken.

Rectangle object::get_obj_rect(){
    return Rectangle{obj_pos.x, obj_pos.y, obj_size.x, obj_size.y};
}

// Returns the objects dimensions

bool object::isbreakable(){
    return breakable;
}

bool object::ininventory()
{
    return ininv;
}
