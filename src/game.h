#ifndef GB_HARVEST_GAME_H
#define GB_HARVEST_GAME_H

#include <stdint.h>

#define CAMERA_HORIZONTAL 0x1U
#define CAMERA_VERTICAL 0x2U
#define PLAYER_HORIZONTAL 0x1U
#define PLAYER_VERTICAL 0x2U
#define PLAYER_FRAME_CHANGE 0x4U

/**
 * Information about the camera.
 *
 * Bit 1 = horizontal movement, 0 = no, 1 = yes
 * Bit 2 = vertical movement, 0 = no, 1 = yes
 */
extern uint8_t bkg_cam_info;

/**
 * Old horizontal camera position in tiles.
 */
extern uint16_t bkg_cam_old_x;

/**
 * Old vertical camera position in tiles.
 */
extern uint16_t bkg_cam_old_y;

/**
 * Scroll speed of the camera when it moves.
 */
extern uint8_t bkg_cam_scroll_speed;

/**
 * Speed of the camera after after every frame.
 *
 * It's a face value, which will be divided by 16.
 */
extern uint8_t bkg_cam_speed;

/**
 * Horizontal camera position as a face value, it needs to be divided by 16.
 */
extern uint16_t bkg_cam_x;

/**
 * Vertical camera position as a face value, it needs to be divided by 16.
 */
extern uint16_t bkg_cam_y;

/**
 * Old horizontal map position as a face value, it needs to be divided by 16.
 */
extern uint8_t bkg_map_pos_old_x;

/**
 * Old vertical map position as a face value, it needs to be divided by 16.
 */
extern uint8_t bkg_map_pos_old_y;

/**
 * Horizontal map position in tiles.
 */
extern uint8_t bkg_map_pos_x;

/**
 * Vertical map position in tiles.
 */
extern uint8_t bkg_map_pos_y;

/**
 * Absolute value of the horizontal background scroll.
 */
extern uint8_t bkg_scroll_x;

/**
 * Absolute value of the vertical background scroll.
 */
extern uint8_t bkg_scroll_y;

/**
 * The current joy pad value.
 */
extern uint8_t joy_pad_now;

/**
 * The last joy pad value.
 */
extern uint8_t joy_pad_old;

/**
 * Index of the current player frame.
 */
extern uint8_t player_frame;

/**
 * How many frames since the last animation frame change.
 */
extern uint8_t player_frames_cnt;

/**
 * Player information:
 *
 * Bit 1 = horizontal movement, 0 = left, 1 = right
 * Bit 2 = vertical movement, 0 = up, 1 = down
 */
extern uint8_t player_info;

/**
 * Player information from the last frame.
 *
 * @see player_info
 */
extern uint8_t player_info_old;

/**
 * Update the camera.
 */
void updateCamera();

/**
 * Update the player.
 */
void updatePlayer();

#endif //GB_HARVEST_GAME_H
