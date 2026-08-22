#include <genesis.h>
#include "resources.h"

#define PLAYER_SPEED 4
#define ENEMY_SPEED 3
#define FIRE_RATE 30
#define MAX_LIVES 3
#define DAMAGE_PER_HIT 1
#define IFRAMES 60

typedef struct {
    fix32 x, y;
    bool active;
} Bullet;

Bullet bullets[10];
u8 bullet_count = 0;

Sprite *player;
s16 joy_val;
u16 player_hp;
u16 iframe_counter;

void handleInput() {
    joy_val = JOY_readJoypad(JOY_1);
    fix32 py = SPR_getPositionY(player);
    fix32 px = SPR_getPositionX(player);

    if (joy_val & BUTTON_UP) py -= PLAYER_SPEED;
    if (joy_val & BUTTON_DOWN) py += PLAYER_SPEED;
    if (joy_val & BUTTON_LEFT) px -= PLAYER_SPEED;
    if (joy_val & BUTTON_RIGHT) px += PLAYER_SPEED;

    if (fix32ToInt(py) < 0) py = FIX32(0);
    if (fix32ToInt(py) > 200) py = FIX32(200);
    if (fix32ToInt(px) < 0) px = FIX32(0);
    if (fix32ToInt(px) > 100) px = FIX32(100);

    SPR_setPosition(player, px, py);
    
    if (iframe_counter > 0) {
        iframe_counter--;
        SPR_setVisibility(player, (iframe_counter % 8 < 4) ? VISIBLE : HIDDEN);
    } else {
        SPR_setVisibility(player, VISIBLE);
    }
}

int main(bool hardReset) {
    SYS_enableDMACopy();
    VDP_setScreenWidth320();
    
    PAL_setPalette(PAL0, player_pal.data, DMA);
    
    player = SPR_addSprite(&spr_player, 50, 100, TILE_ATTR(PAL0, TRUE, FALSE, FALSE));
    player_hp = MAX_LIVES;
    iframe_counter = 0;
    
    while(1) {
        handleInput();
        SPR_update();
        SYS_doVBlankProcess();
    }
    return 0;
}