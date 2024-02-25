#include "head.h"
void draw_monster(ALLEGRO_DISPLAY *display,Monsterp upmidp,Monsterp midleftp,Monsterp midrightp,Monsterp downmidp,Monsterp catp)
{
    al_draw_bitmap(upmidp->img, upmidp->x, upmidp->y, 0);
    al_draw_bitmap(midleftp->img, midleftp->x, midleftp->y, 0);
    al_draw_bitmap(midrightp->img, midrightp->x, midrightp->y, 0);
    al_draw_bitmap(downmidp->img, downmidp->x, downmidp->y, 0);

}
