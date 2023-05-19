
#include "controller.h"

#include <gb/gb.h>

struct controller {
    uint8_t current_value;
    uint8_t last_value;
};

static struct controller controller_1;

// controller controller_setup(){
// 	controller new_controller;

// 	new_controller.current_value = joypad();
// 	new_controller.last_value = 0;

// 	return new_controller;
// }

void controller_update() {
    controller_1.last_value = controller_1.current_value;
    controller_1.current_value = joypad();
}

uint8_t controller_all_held() { return controller_1.current_value; }
uint8_t controller_all_change() {
    return controller_1.current_value ^ controller_1.last_value;
}
uint8_t controller_all_pressed() {
    return controller_all_change() & controller_1.current_value;
}
uint8_t controller_all_released() {
    return controller_all_change() & controller_1.last_value;
}

uint8_t controller_button_held(uint8_t button_to_test) {
    return !!(controller_all_held() & button_to_test);
}
uint8_t controller_button_change(uint8_t button_to_test) {
    return !!(controller_all_change() & button_to_test);
}
uint8_t controller_button_pressed(uint8_t button_to_test) {
    return !!(controller_all_pressed() & button_to_test);
}
uint8_t controller_button_released(uint8_t button_to_test) {
    return !!(controller_all_released() & button_to_test);
}