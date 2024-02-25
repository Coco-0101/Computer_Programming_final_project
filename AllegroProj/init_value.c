#include "head.h"

void init_value(button_iconP start_buttonP, button_iconP menu_buttonP,button_iconP back_buttonP,button_iconP score_buttonP, button_iconP volume_buttonP,
                button_iconP tutor_buttonP,button_iconP secret_buttonP, button_iconP exit_buttonP, button_iconP respawn_buttonP, button_iconP title_buttonP,
                Monsterp upmidp,Monsterp midleftp,Monsterp midrightp,Monsterp downmidp,Monsterp catp,
                Symbolp Horizontalp,Symbolp Verticalp,Symbolp Negative_slopep,Symbolp Positive_slopep, stage_cP stage_cP,
                ALLEGRO_FONT *font)
{

    start_buttonP->X = 852;
    start_buttonP->Y = 602;
    start_buttonP->W = 219;
    start_buttonP->H = 85;
    start_buttonP->click = false;

    menu_buttonP->X = 852;
    menu_buttonP->Y = 735;
    menu_buttonP->W = 219;
    menu_buttonP->H = 85;
    menu_buttonP->click = false;


    exit_buttonP->X = 1795;
    exit_buttonP->Y = 26;
    exit_buttonP->W = 88;
    exit_buttonP->H = 91;
    exit_buttonP->click = false;

    back_buttonP->X = 1660;
    back_buttonP->Y = 36;
    back_buttonP->W = 212;
    back_buttonP->H = 118;
    back_buttonP->click = false;

    score_buttonP->X = 50;
    score_buttonP->Y = 540;
    score_buttonP->W = 423;
    score_buttonP->H = 360;
    score_buttonP->click = false;
    score_buttonP->img = al_load_bitmap("./img/score_0.png");

    volume_buttonP->X = 516;
    volume_buttonP->Y = 540;
    volume_buttonP->W = 423;
    volume_buttonP->H = 360;
    volume_buttonP->click = true;

    tutor_buttonP->X = 983;
    tutor_buttonP->Y = 540;
    tutor_buttonP->W = 423;
    tutor_buttonP->H = 360;
    tutor_buttonP->click = false;
    tutor_buttonP->img = al_load_bitmap("./img/tutorial.png");

    secret_buttonP->X = 1450;
    secret_buttonP->Y = 540;
    secret_buttonP->W = 423;
    secret_buttonP->H = 360;
    secret_buttonP->click = false;
    secret_buttonP->img = al_load_bitmap("./img/secret.png");

    respawn_buttonP->X = 567;
    respawn_buttonP->Y = 748;
    respawn_buttonP->W = 790;
    respawn_buttonP->H = 64;
    respawn_buttonP->click = false;

    title_buttonP->X = 567;
    title_buttonP->Y = 852;
    title_buttonP->W = 790;
    title_buttonP->H = 64;
    title_buttonP->click = false;

    upmidp->img  = al_load_bitmap("./img/yagoo.png");
    upmidp->x = (WIDTH - al_get_bitmap_width(upmidp->img))/ 2;
    upmidp->y = -al_get_bitmap_height(upmidp->img);
    upmidp->appear = false;
    upmidp->symboled = false;
    memset(upmidp->symbol, 0, sizeof(upmidp->symbol));


    midleftp->img  = al_load_bitmap("./img/yagoo.png");
    midleftp->x = -al_get_bitmap_width(midleftp->img);
    midleftp->y = (HEIGHT - al_get_bitmap_width(midleftp->img))/ 2;
    midleftp->appear = false;
    midleftp->moncount = 0;
    midleftp->symboled = false;
    memset(midleftp->symbol, 0, sizeof(midleftp->symbol));


    midrightp->img  = al_load_bitmap("./img/yagoo.png");
    midrightp->x = WIDTH;
    midrightp->y = (HEIGHT - al_get_bitmap_height(midrightp->img))/ 2;
    midrightp->appear = false;
    midrightp->symboled = false;
    memset(midrightp->symbol, 0, sizeof(midrightp->symbol));


    downmidp->img  = al_load_bitmap("./img/yagoo.png");
    downmidp->x = (WIDTH - al_get_bitmap_width(downmidp->img))/ 2;
    downmidp->y = HEIGHT;
    downmidp->appear = false;
    downmidp->symboled = false;
    memset(downmidp->symbol, 0, sizeof(downmidp->symbol));

    catp->img = al_load_bitmap("./img/cat.png");
    catp->x = (WIDTH - 200)/ 2;
    catp->y = (HEIGHT - 200)/ 2;
    catp->moncount = 5;


    Horizontalp->img = al_load_bitmap("./img/red_bar.png");
    Horizontalp->x = 0;
    Horizontalp->y = 0;

    Verticalp->img = al_load_bitmap("./img/yellow_bar.png");
    Verticalp->x = 0;
    Verticalp->y = 0;

    Negative_slopep->img = al_load_bitmap("./img/blue_bar.png");
    Negative_slopep->x = 0;
    Negative_slopep->y = 0;

    Positive_slopep->img = al_load_bitmap("./img/green_bar.png");
    Positive_slopep->x = 0;
    Positive_slopep->y = 0;

    for(int i=0; i<=5; i++)
    {
        stage_cP[i].time = 0;
        stage_cP[i].clear_stage = false;
    }


    font = al_load_font("arial.ttf", 20, 0);
        if (!font) {
        return -1;
    }
}
