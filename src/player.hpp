#pragma once
#include "raylib.h"
#include "raymath.h"

class player {
    public:
        player();
        ~player();
        void Draw_player();
        void Update();
        bool UpdateKey(bool isnear, bool breakable);
        Rectangle getRect();
        Rectangle getNRect();
        void DrawHB(bool isColliding);
        void Set_prev_pos();
        int get_orientation();
    private:
        Vector2 position;
        Vector2 size;
        Vector2 prev_position;
        Vector2 ray_pos;
        int orientation; // 1 = right, 2 = left, 3 = up, 4 = down
};

