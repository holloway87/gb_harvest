#include <gb/gb.h>
#include <gb/metasprites.h>

#include "game.h"
#include "../res/map.h"
#include "../res/player.h"

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
uint8_t player_frame = 0;
uint8_t player_frames_cnt = 0;
uint8_t player_info = PLAYER_VERTICAL;
uint8_t player_info_old = PLAYER_VERTICAL;

void updateCamera() {
    bkg_scroll_x = 0;
    bkg_scroll_y = 0;
    if (map_height > bkg_cam_y && joy_pad_now & J_DOWN) {
        bkg_scroll_y = 1;
        bkg_cam_y++;
    } else if (0 < bkg_cam_y && joy_pad_now & J_UP) {
        bkg_scroll_y = -1;
        bkg_cam_y--;
    }
    if (map_width > bkg_cam_x && joy_pad_now & J_RIGHT) {
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
            if (bkg_map_pos_x < (map_tiles_width - 20u)) {
                set_bkg_submap(bkg_map_pos_x + 20u, bkg_map_pos_y, 1, 19, map_map, map_tiles_width);
                set_bkg_submap_attributes(bkg_map_pos_x + 20u, bkg_map_pos_y, 1, 19, map_attributes, map_tiles_width);
            }
        } else {
            set_bkg_submap(bkg_map_pos_x, bkg_map_pos_y, 1, 19, map_map, map_tiles_width);
            set_bkg_submap_attributes(bkg_map_pos_x, bkg_map_pos_y, 1, 19, map_attributes, map_tiles_width);
        }
        bkg_map_pos_old_x = bkg_map_pos_x;
    }
    bkg_map_pos_y = (uint8_t)(bkg_cam_y >> 3u);
    if (bkg_map_pos_y != bkg_map_pos_old_y) {
        if (bkg_cam_old_y < bkg_cam_y) {
            if (bkg_map_pos_y < (map_tiles_height - 18u)) {
                set_bkg_submap(bkg_map_pos_x, bkg_map_pos_y + 18u, 21, 1, map_map, map_tiles_width);
                set_bkg_submap_attributes(bkg_map_pos_x, bkg_map_pos_y + 18u, 21, 1, map_attributes, map_tiles_width);
            }
        } else {
            set_bkg_submap(bkg_map_pos_x, bkg_map_pos_y, 21, 1, map_map, map_tiles_width);
            set_bkg_submap_attributes(bkg_map_pos_x, bkg_map_pos_y, 21, 1, map_attributes, map_tiles_width);
        }
        bkg_map_pos_old_y = bkg_map_pos_y;
    }

    bkg_cam_old_x = bkg_cam_x;
    bkg_cam_old_y = bkg_cam_y;
}

void updatePlayer() {
    player_frames_cnt++;
    if (16 <= player_frames_cnt) {
        player_frame++;
        player_metasprite_frame += 5;

        if (5 < player_frame) {
            player_frame = 0;
            player_metasprite_frame -= 30;
        }

        player_info += PLAYER_FRAME_CHANGE;
        player_frames_cnt = 0;
    }

    if (joy_pad_old != joy_pad_now && joy_pad_now & J_UP && player_info & PLAYER_VERTICAL) {
        player_info -= PLAYER_VERTICAL;
        player_metasprite_frame += 30;
    } else if (joy_pad_old != joy_pad_now && (joy_pad_now & J_DOWN || !(joy_pad_now & J_UP)) && !(player_info & PLAYER_VERTICAL)) {
        player_info += PLAYER_VERTICAL;
        player_metasprite_frame -= 30;
    }
    if (joy_pad_old != joy_pad_now && joy_pad_now & J_RIGHT && !(player_info & PLAYER_HORIZONTAL)) {
        player_info += PLAYER_HORIZONTAL;
    } else if (joy_pad_old != joy_pad_now && joy_pad_now & J_LEFT && player_info & PLAYER_HORIZONTAL) {
        player_info -= PLAYER_HORIZONTAL;
    }

    if (player_info != player_info_old) {
        if (player_info & PLAYER_FRAME_CHANGE) {
            player_info -= PLAYER_FRAME_CHANGE;
        }

        if (player_info & PLAYER_HORIZONTAL) {
            move_metasprite_flipx(player_metasprite_frame, 0, 0, 0, 96, 80);
        } else {
            move_metasprite_ex(player_metasprite_frame, 0, 0, 0, 96, 80);
        }

        player_info_old = player_info;
    }
}
