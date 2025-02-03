 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
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

//Setting up what encoder rotation does. If your encoder can be pressed as a button, that function can be set in Via.


#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    static const uint8_t encoder_actions[][2] = {
        {1, 3},  // First encoder: row positions for clockwise/counterclockwise
        {6, 8}   // Second encoder: row positions for clockwise/counterclockwise
    };
    
    if (index < 2) {
        uint8_t row = encoder_actions[index][!clockwise];
        keyevent_t event = {
            .key = (keypos_t){.row = row, .col = 6},
            .pressed = true,
            .time = (timer_read() | 1)
        };
        
        action_exec(event);
        event.pressed = false;
        action_exec(event);
    }
    return true;
}
#endif