#include <gb/gb.h>
#include <gb/cgb.h>

#include "game.h"
#include "../res/map.h"
#include "../res/player.h"

void main() {
    DISPLAY_ON;

    SHOW_BKG;
    SHOW_SPRITES;

    set_bkg_data(0, map_tiles_count, map_tiles);
    set_bkg_palette(0, map_palettes_cnt, map_palettes);
    set_bkg_submap(0, 0, 21, 19, map_map, map_tiles_width);
    set_bkg_submap_attributes(0, 0, 21, 19, map_attributes, map_tiles_width);

    set_sprite_data(0, player_tiles_count, player_tiles);
    move_metasprite_ex(player_metasprite_frame, 0, 0, 0, 96, 80);
    set_sprite_palette(0, player_palettes_cnt, player_palettes);

    while (1) {
        joy_pad_old = joy_pad_now;
        joy_pad_now = joypad();

        updateCamera();
        updatePlayer();

        wait_vbl_done();
    }
}
