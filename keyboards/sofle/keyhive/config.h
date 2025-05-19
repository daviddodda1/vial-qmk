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
 
 // Layer count
 #define DYNAMIC_KEYMAP_LAYER_COUNT 4
 
 // Pointing device configuration
 #define POINTING_DEVICE_RIGHT       // Right half has the pointing device
 #define SPLIT_POINTING_ENABLE       // Enable split pointing device support
 
 // Mouse movement speed/sensitivity
 #define MOUSE_EXTENDED_REPORT       // Better resolution
 #define MOUSEKEY_INTERVAL 16        // How often cursor is updated (milliseconds)
 #define MOUSEKEY_TIME_TO_MAX 40     // How long until it reaches maximum speed
 #define MOUSEKEY_WHEEL_TIME_TO_MAX 8// How long until wheel reaches maximum speed
 #define MOUSEKEY_DELAY 100          // Delay before starting movement
 
 // Debug options - enable these for troubleshooting
 // #define DEBUG_MATRIX_SCAN_RATE
//  #define SPLIT_TRANSACTION_IDS_USER 0x10 // Add more transaction IDs if needed
 
 // Disable OLED on the right half since we're using those pins for the trackpad
 #define OLED_DISPLAY_128X64
 #define OLED_BRIGHTNESS 90
 #define OLED_TIMEOUT 30000          // Turn off OLED after 30 seconds of inactivity
 #define SPLIT_OLED_ENABLE           // Only enable OLED on left half