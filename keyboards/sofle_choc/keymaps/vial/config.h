/* Copyright 2023 Brian Low
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 #pragma once

 // Enabling this option changes the startup behavior to listen for an
 // active USB communication to delegate which part is master and which
 // is slave. With this option enabled and theres's USB communication,
 // then that half assumes it is the master, otherwise it assumes it
 // is the slave.
 //
 // I've found this helps with some ProMicros where the slave does not boot
 #define SPLIT_USB_DETECT
 
 // Vial Support
 #define VIAL_KEYBOARD_UID {0xA7, 0xA7, 0x9C, 0x4C, 0xE0, 0xB8, 0x00, 0x8D}
 
 // The four corners
 #define VIAL_UNLOCK_COMBO_ROWS { 0, 5, 3, 8 }
 #define VIAL_UNLOCK_COMBO_COLS { 0, 0, 0, 0 }
 
 #define DYNAMIC_KEYMAP_LAYER_COUNT 4
 
 /* PS/2 Mouse support - using the right half OLED pins */
/* PS/2 Mouse support - using the right half OLED pins */
#define PS2_CLOCK_PIN D0  // Using former OLED clock pin
#define PS2_DATA_PIN D1   // Using former OLED data pin

#ifdef PS2_DRIVER_INTERRUPT

#define PS2_INT_INIT()  do {    \
    EICRA |= ((1<<ISC21) |      \
              (0<<ISC20));      \
} while (0)
#define PS2_INT_ON()  do {      \
    EIMSK |= (1<<INT2);         \
} while (0)
#define PS2_INT_OFF() do {      \
    EIMSK &= ~(1<<INT2);        \
} while (0)
#define PS2_INT_VECT   INT2_vect
#endif

// Remove PS2_USE_BUSYWAIT_INTERRUPT
 
 /* Disable OLED on right half since pins are used for trackpad */
 #ifdef OLED_ENABLE
   #define OLED_DISPLAY_128X64
   #define SPLIT_OLED_ENABLE
   #define SPLIT_TRANSPORT_MIRROR
   #define OLED_TIMEOUT 30000  // 30 seconds
 
   // Only use OLED on master side (assuming left)
   #define OLED_DISPLAY_ADDRESS 0x3C
   #undef OLED_DISPLAY_ADDRESS_RIGHT
 #endif
 
 /* Define master as left since right half uses OLED pins for trackpad */
 #define MASTER_LEFT