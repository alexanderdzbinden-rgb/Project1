#pragma once
#include "raylib.h"
#include "raymath.h"
#include <vector>

class object {
    public:
        object();
        ~object();
        object(object& obj);
        void draw_obj();
        void draw_in_inv(Vector2 position, Vector2 size);
        void update_obj();
        Rectangle get_obj_rect();
        bool isbreakable();
        bool ininventory();


    private:
        Vector2 obj_pos;
        Vector2 obj_size;
        bool breakable;
        bool dontdraw = false;
        bool ininv = false;
};