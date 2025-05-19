
// SSD1306 OLED update loop
#ifdef OLED_ENABLE

/* timers */
uint32_t oled_timer = 0; // For OLED timeout


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
    
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {

    oled_on();
    oled_clear();
    print_status_narrow();

    return false;
}

#endif