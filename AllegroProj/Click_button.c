#include "head.h"

void click_button(button_iconP button, ALLEGRO_BITMAP *img, int *x, int *y)
{
    if (*x>=button->X && *y >= button->Y && *x <= (button->X+button->W) && *y<=(button->Y+button->H))
    {
        al_draw_bitmap(img, 0, 0, 0);
        al_flip_display();
        button->click = true;
        printf("Click button!\n");

    }
}
