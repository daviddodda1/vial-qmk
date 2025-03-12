OLED_ENABLE = yes
ENCODER_ENABLE = no

CONSOLE_ENABLE = no     # Enable console for debugging
EXTRAKEY_ENABLE = yes    # Enable for media keys

VIA_ENABLE = yes
VIAL_ENABLE = yes

ENCODER_MAP_ENABLE = no
BACKLIGHT_ENABLE = no
RGBLIGHT_ENABLE = no
VIALRGB_ENABLE = no
QMK_SETTINGS = no
COMBO_ENABLE = no
KEY_OVERRIDE_ENABLE = no
RGB_MATRIX_ENABLE = no

# Enable pointer device support for trackpad
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = custom

# Required for mouse buttons
MOUSEKEY_ENABLE = yes

WPM_ENABLE = no        # WPM counter for keyboard pets
LTO_ENABLE = yes        # Save space

# Enable debugging output
CONSOLE_ENABLE = no     # Duplicate, but keeping for clarity

SRC += trackpad.c