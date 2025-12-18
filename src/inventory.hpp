#pragma once
#include "raylib.h"
#include "raymath.h"
#include "objects.hpp"

class inventory {
    public:
        inventory();
        ~inventory();
        void Draw_Inventory();
        int get_slot(int index);
        void Update_slot(object& obj);
        void Update_selected_slot();
        object* slots[5];
        bool isfull;
    private:
        Vector2 slot_id[5];
        Vector2 inv_slot_size;
        int selected_slot;
        bool individual[5];
};

// This file defines the players inventory, we create an inventory with 5 slots, which copy the objects that are picked up.