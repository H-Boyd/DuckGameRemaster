#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <stdint.h>

typedef struct controller controller;
// updates the structure with the current value of the pressed buttons.
void controller_update();

// returns which buttons are currently held down,
uint8_t controller_all_held();

// returns which buttons have changed value between last and second to last call  to controller_update();
uint8_t controller_all_change();

// returns which buttons have been pressed between last and second to last call  to controller_update();
uint8_t controller_all_pressed();

// returns which buttons have been released between last and second to last call  to controller_update();
uint8_t controller_all_released();

// returns which if a button is currently held down,
uint8_t controller_button_held(uint8_t button_to_test);
// returns if a buttons has changed value between last and second to last call  to controller_update();
uint8_t controller_button_change(uint8_t button_to_test);
// returns if a buttons has been pressed between last and second to last call  to controller_update();
uint8_t controller_button_pressed(uint8_t button_to_test);
// returns if a buttons has been released between last and second to last call  to controller_update();
uint8_t controller_button_released(uint8_t button_to_test);

#endif  // CONTROLLER_H
