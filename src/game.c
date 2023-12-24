#include <gb/gb.h>

#include "game.h"
#include "../res/map.h"

uint16_t bkg_cam_old_x = 0;
uint16_t bkg_cam_old_y = 0;
uint16_t bkg_cam_x = 0;
uint16_t bkg_cam_y = 0;
uint8_t bkg_map_pos_old_x = 0;
uint8_t bkg_map_pos_old_y = 0;
uint8_t bkg_map_pos_x = 0;
uint8_t bkg_map_pos_y = 0;
int8_t bkg_scroll_x = 0;
int8_t bkg_scroll_y = 0;
uint8_t joy_pad_now = 0;
uint8_t joy_pad_old = 0;

void updateCamera() {
    bkg_scroll_x = 0;
    bkg_scroll_y = 0;
    if (joy_pad_now & J_DOWN) {
        bkg_scroll_y = 1;
        bkg_cam_y++;
    } else if (0 < bkg_cam_y && joy_pad_now & J_UP) {
        bkg_scroll_y = -1;
        bkg_cam_y--;
    }
    if (joy_pad_now & J_RIGHT) {
        bkg_scroll_x = 1;
        bkg_cam_x++;
    } else if (0 < bkg_cam_x && joy_pad_now & J_LEFT) {
        bkg_scroll_x = -1;
        bkg_cam_x--;
    }

    if (bkg_scroll_x || bkg_scroll_y) {
        scroll_bkg(bkg_scroll_x, bkg_scroll_y);
    }

    bkg_map_pos_x = (uint8_t)(bkg_cam_x >> 3u);
    if (bkg_map_pos_x != bkg_map_pos_old_x) {
        if (bkg_cam_old_x < bkg_cam_x) {
            set_bkg_submap(bkg_map_pos_x + 20u, bkg_map_pos_y, 1, 19, map_map, map_tiles_width);
        } else {
            set_bkg_submap(bkg_map_pos_x, bkg_map_pos_y, 1, 19, map_map, map_tiles_width);
        }
        bkg_map_pos_old_x = bkg_map_pos_x;
    }
    bkg_map_pos_y = (uint8_t)(bkg_cam_y >> 3u);
    if (bkg_map_pos_y != bkg_map_pos_old_y) {
        if (bkg_cam_old_y < bkg_cam_y) {
            set_bkg_submap(bkg_map_pos_x, bkg_map_pos_y + 18u, 21, 1, map_map, map_tiles_width);
        } else {
            set_bkg_submap(bkg_map_pos_x, bkg_map_pos_y, 21, 1, map_map, map_tiles_width);
        }
        bkg_map_pos_old_y = bkg_map_pos_y;
    }

    bkg_cam_old_x = SCX_REG;
    bkg_cam_old_y = SCY_REG;
}
