#include <gb/gb.h>
#include <stdio.h>

#include "../assets/oldSprites/DuckWalkIV.c"
#include "../include/controller.h"

#define TILE_WIDTH 8
#define TILE_HEIGHT 8

#define CONTINUE_GAME 1


void printBinary(uint8_t data) {
    for (uint8_t i = 0; i < 8; i++) {
        printf("%u", data >> (7 - i) & 1);
    }
    printf("\n");
}

void character_move(uint8_t initial_sprite_number, uint8_t x_coord, uint8_t y_coord) {
    for (uint8_t i = 0; i < 4; i++) {
        uint8_t unit_x = i & 1;
        uint8_t unit_y = i >> 1;

        uint8_t offset_x = unit_x * TILE_WIDTH;
        uint8_t offset_y = unit_y * TILE_HEIGHT;

        move_sprite(initial_sprite_number + i, x_coord + offset_x, y_coord + offset_y);
    }
}

void main() {
    NR52_REG = 0x80;
    NR50_REG = 0x77;
    NR51_REG = 0xFF;

    set_sprite_data(0, 24, DuckIV);

    set_sprite_tile(4, 4);

    move_sprite(4, 100, 100);

    OBP1_REG = 0xc6;  // OBJ palette 1 data

    for (int i = 0; i < 4; i++) {
        set_sprite_prop(i, S_PALETTE);  // flip sprite horizontally
    }

    SHOW_BKG;      // Background Display: Visible
    SHOW_SPRITES;  // Sprites Display: Visible
    DISPLAY_ON;    // LCD Control: On

    uint8_t counter = 0;

    character_set_sprites(0, 2);
    character_move(0, 100, 100);

    while (CONTINUE_GAME) {
        controller_update();

        if (controller_button_pressed(J_A)) {
            counter++;
        }
        if (controller_button_pressed(J_B)) {
            counter--;
        }
        if (controller_all_pressed()) {
            printf("%u\n", counter);
            set_sprite_tile(4, counter);
        }
    }
}