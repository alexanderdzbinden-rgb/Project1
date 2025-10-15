#include "inventory.hpp"

inventory::inventory(){
    for (int i=0; i<5; i++){
        slot_id[i].x = 7 + i*20;
        slot_id[i].y = 367;
    }
    inv_slot_size.x = 16;
    inv_slot_size.y = 16;
}

// Defines the inventory visually

inventory::~inventory(){
}

void inventory::Draw_Inventory(){
    DrawRectangleLines(5, 365, 100, 20, WHITE);
    for (int i=0; i<5; i++){
        if (slots[i] == NULL){
            if (selected_slot == i+1){
                DrawRectangleLines(5+i*20, 365, 20, 20, RED);
            }
            continue;
        }
        else if (slots[i]->ininventory() == true){
            slots[i]->draw_in_inv(slot_id[i], inv_slot_size);
        }
    }
}

//Continuously Draws the inventory, and checks to see if there should be an object in a given slot, and displays the inventory as such

int inventory::get_slot(int index){
    return 0;
}

void inventory::Update_slot(object& obj){
    for (int i=0;i<5;i++){
        if (slots[i] == NULL){
            slots[i] = &obj;
            break;
        }
    }
}

// Updates the slot by copying an object into it, only called when player destroys an object.

void inventory::Update_selected_slot(){
    if (IsKeyPressed(KEY_ONE)){
        selected_slot = 1;
    }
    else if (IsKeyPressed(KEY_TWO)){
        selected_slot = 2;
    }
    else if (IsKeyPressed(KEY_THREE)){
        selected_slot = 3;
    }
    else if (IsKeyPressed(KEY_FOUR)){
        selected_slot = 4;
    }
    else if (IsKeyPressed(KEY_FIVE)){
        selected_slot = 5;
    }
}

// Selects the slot by checking which matching key is pressed, and will select the item in that slot.