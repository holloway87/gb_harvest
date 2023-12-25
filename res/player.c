/*
tile size: 23
map size: 24x2
*/

#include <gb/cgb.h>

#include "player.h"

const unsigned char player_tiles[] = {
    0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x2d, 0x00, 0x2d, 0x00, 0x3f, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x2d, 0x00, 0x2d, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 
    0x00, 0x00, 0x1f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x2d, 0x00, 0x2d, 0x00, 0x3f, 0x00, 0x3f, 0x00, 
    0x00, 0x00, 0x80, 0x00, 0x80, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 
    0x00, 0x00, 0x1f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x3f, 0x00, 
    0x3f, 0x00, 0x79, 0x00, 0x5b, 0x00, 0x0f, 0x00, 0x07, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xc0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xf0, 0x00, 0xfc, 0x00, 0x02, 0x00, 0x00, 0x00, 
    0x3f, 0x00, 0x3f, 0x00, 0x79, 0x00, 0x5b, 0x00, 0x0f, 0x00, 0x07, 0x00, 0x01, 0x00, 0x00, 0x00, 
    0xc0, 0x00, 0xc0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xf2, 0x00, 0xfc, 0x00, 0x00, 0x00, 
    0xc0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xf0, 0x00, 0xfe, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xc0, 0x00, 0xc0, 0x00, 0xe2, 0x00, 0xf2, 0x00, 0xfe, 0x00, 0xfc, 0x00, 0xf8, 0x00, 0x00, 0x00, 
    0x79, 0x00, 0x5b, 0x00, 0x0f, 0x00, 0x07, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xe0, 0x00, 0xe0, 0x00, 0xf0, 0x00, 0xf8, 0x00, 0xfc, 0x00, 0x0e, 0x00, 0x02, 0x00, 0x00, 0x00, 
    0x3f, 0x00, 0x7f, 0x00, 0x5f, 0x00, 0x0f, 0x00, 0x07, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x3f, 0x00, 0x3f, 0x00, 0x7f, 0x00, 0x5f, 0x00, 0x07, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xc0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xf0, 0x00, 0xf2, 0x00, 0x0c, 0x00, 0x00, 0x00, 
    0x3f, 0x00, 0x3f, 0x00, 0x7f, 0x00, 0x5f, 0x00, 0x0f, 0x00, 0x07, 0x00, 0x01, 0x00, 0x00, 0x00, 
    0x7f, 0x00, 0x5f, 0x00, 0x0f, 0x00, 0x07, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

};

const unsigned short player_palettes[4] = {
    RGB8(0, 0, 0), RGB8(255, 255, 255), RGB8(0, 0, 0), RGB8(0, 0, 0), 
};

const metasprite_t player_metasprite[] = {
    // looking down, 1. frame
    {.dx = -8, .dy = 0, .dtile = 0, .props = 0},
    {.dx = 8, .dy = 0, .dtile = 1, .props = 0},
    {.dx = -8, .dy = 8, .dtile = 10, .props = 0},
    {.dx = 8, .dy = 0, .dtile = 11, .props = 0},
    METASPR_TERM,
    // looking down, 2. frame
    {.dx = -8, .dy = 0, .dtile = 2, .props = 0},
    {.dx = 8, .dy = 0, .dtile = 3, .props = 0},
    {.dx = -8, .dy = 8, .dtile = 12, .props = 0},
    {.dx = 8, .dy = 0, .dtile = 13, .props = 0},
    METASPR_TERM,
    // looking down, 3. frame
    {.dx = -8, .dy = 0, .dtile = 0, .props = 0},
    {.dx = 8, .dy = 0, .dtile = 1, .props = 0},
    {.dx = -8, .dy = 8, .dtile = 10, .props = 0},
    {.dx = 8, .dy = 0, .dtile = 11, .props = 0},
    METASPR_TERM,
    // looking down, 4. frame
    {.dx = -8, .dy = 0, .dtile = 0, .props = 0},
    {.dx = 8, .dy = 0, .dtile = 1, .props = 0},
    {.dx = -8, .dy = 8, .dtile = 10, .props = 0},
    {.dx = 8, .dy = 0, .dtile = 14, .props = 0},
    METASPR_TERM,
    // looking down, 5. frame
    {.dx = -8, .dy = 0, .dtile = 2, .props = 0},
    {.dx = 8, .dy = 0, .dtile = 4, .props = 0},
    {.dx = -8, .dy = 8, .dtile = 12, .props = 0},
    {.dx = 8, .dy = 0, .dtile = 15, .props = 0},
    METASPR_TERM,
    // looking down, 6. frame
    {.dx = -8, .dy = 0, .dtile = 5, .props = 0},
    {.dx = 8, .dy = 0, .dtile = 6, .props = 0},
    {.dx = -8, .dy = 8, .dtile = 16, .props = 0},
    {.dx = 8, .dy = 0, .dtile = 17, .props = 0},
    METASPR_TERM,
    // looking up, 1. frame
    {.dx = -8, .dy = 0, .dtile = 7, .props = 0},
    {.dx = 8, .dy = 0, .dtile = 1, .props = 0},
    {.dx = -8, .dy = 8, .dtile = 18, .props = 0},
    {.dx = 8, .dy = 0, .dtile = 11, .props = 0},
    METASPR_TERM,
    // looking up, 2. frame
    {.dx = -8, .dy = 0, .dtile = 8, .props = 0},
    {.dx = 8, .dy = 0, .dtile = 3, .props = 0},
    {.dx = -8, .dy = 8, .dtile = 19, .props = 0},
    {.dx = 8, .dy = 0, .dtile = 20, .props = 0},
    METASPR_TERM,
    // looking up, 3. frame
    {.dx = -8, .dy = 0, .dtile = 7, .props = 0},
    {.dx = 8, .dy = 0, .dtile = 1, .props = 0},
    {.dx = -8, .dy = 8, .dtile = 18, .props = 0},
    {.dx = 8, .dy = 0, .dtile = 11, .props = 0},
    METASPR_TERM,
    // looking up, 4. frame
    {.dx = -8, .dy = 0, .dtile = 7, .props = 0},
    {.dx = 8, .dy = 0, .dtile = 1, .props = 0},
    {.dx = -8, .dy = 8, .dtile = 18, .props = 0},
    {.dx = 8, .dy = 0, .dtile = 14, .props = 0},
    METASPR_TERM,
    // looking up, 5. frame
    {.dx = -8, .dy = 0, .dtile = 8, .props = 0},
    {.dx = 8, .dy = 0, .dtile = 4, .props = 0},
    {.dx = -8, .dy = 8, .dtile = 21, .props = 0},
    {.dx = 8, .dy = 0, .dtile = 15, .props = 0},
    METASPR_TERM,
    // looking up, 6. frame
    {.dx = -8, .dy = 0, .dtile = 9, .props = 0},
    {.dx = 8, .dy = 0, .dtile = 6, .props = 0},
    {.dx = -8, .dy = 8, .dtile = 22, .props = 0},
    {.dx = 8, .dy = 0, .dtile = 17, .props = 0},
    METASPR_TERM,
};

metasprite_t *player_metasprite_frame = &player_metasprite[0];