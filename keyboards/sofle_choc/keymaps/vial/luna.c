
// SSD1306 OLED update loop
#ifdef OLED_ENABLE

/* timers */
uint32_t oled_timer = 0; // For OLED timeout

/* status variables */
led_t led_usb_state;

static void print_status_narrow(void) {
    // Print current layer
    oled_set_cursor(0, 2);
    oled_write("LAYER", false);
 
    oled_set_cursor(0, 3);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write("Base ", false);
            break;
        case 1:
            oled_write("Scroll", false);
            break;
        case 2:
            oled_write("Lower", false);
            break;
        case 3:
            oled_write("Raise", false);
            break;
        default:
            oled_write("Undef", false);
    }
    
    // Print "Daves kbrd" text
    oled_set_cursor(0, 6);
    oled_write("Daves", false);
    oled_set_cursor(0, 7);
    oled_write("kbrd", false);
    
    // Optional: Display lock states
    oled_set_cursor(0, 10);
    oled_write("CAPS", led_usb_state.caps_lock);
    oled_set_cursor(0, 11);
    oled_write("NUM", !(led_usb_state.num_lock));
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    led_usb_state = host_keyboard_led_state();

    // Turn off OLED after timeout
    if (timer_elapsed32(oled_timer) > 30000) {
        oled_off();
        return false;
    } else {
        oled_on();
    }
    
    oled_clear();
    print_status_narrow();

    return false;
}

#endif