#include QMK_KEYBOARD_H
#include <stdio.h>
#ifdef OLED_ENABLE
    #include "luna.c"
#endif

// Single layout definition since using VIA
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_VOLU, KC_PGUP,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_TRNS,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_MUTE, KC_NO,      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_VOLD, KC_PGDN,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                         KC_LGUI, KC_LALT, KC_LCTL, MO(2),    KC_ENT,  KC_SPC,     MO(3),   KC_RCTL, KC_RALT, KC_RGUI
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef KEYBOARD_PET
        if (record->event.pressed) {
            oled_timer = timer_read32();
            
            // Handle sneaking state for ctrl keys
            if (keycode == KC_LCTL || keycode == KC_RCTL) {
                isSneaking = true;
                return true;
            } else if (!record->event.pressed && (keycode == KC_LCTL || keycode == KC_RCTL)) {
                isSneaking = false;
            }
        }
    #endif
    return true;
}

#ifdef OLED_ENABLE
    void suspend_power_down_user(void) {
        oled_off();
    }
#endif