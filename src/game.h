#ifndef GB_HARVEST_GAME_H
#define GB_HARVEST_GAME_H

#include <stdint.h>

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
 * Update the camera.
 */
void updateCamera();

#endif //GB_HARVEST_GAME_H
