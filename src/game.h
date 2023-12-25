#ifndef GB_HARVEST_GAME_H
#define GB_HARVEST_GAME_H

#include <stdint.h>

#define PLAYER_HORIZONTAL 0x1U
#define PLAYER_VERTICAL 0x2U
#define PLAYER_FRAME_CHANGE 0x4U

/**
 * Old horizontal camera position in tiles.
 */
extern uint16_t bkg_cam_old_x;

/**
 * Old vertical camera position in tiles.
 */
extern uint16_t bkg_cam_old_y;

/**
 * Horizontal camera position in tiles.
 */
extern uint16_t bkg_cam_x;

/**
 * Vertical camera position in tiles.
 */
extern uint16_t bkg_cam_y;

/**
 * Old horizontal map position in tiles.
 */
extern uint8_t bkg_map_pos_old_x;

/**
 * Old vertical map position in tiles.
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
 * Amount of horizontal background scroll.
 */
extern int8_t bkg_scroll_x;

/**
 * Amount of vertical background scroll.
 */
extern int8_t bkg_scroll_y;

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
