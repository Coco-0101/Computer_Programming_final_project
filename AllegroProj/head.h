#ifndef Headers_H_INCLUDED
#define Headers_H_INCLUDED

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#define WIDTH 1920
#define HEIGHT 1080
#define FRAME_LINE "================================================"
#define asd printf("stop here");
#define MAX_TRAIL_LENGTH 1000

typedef struct button_icon
{
    // 定義按鈕的位置和大小
    ALLEGRO_BITMAP* img;
    int X;
    int Y;
    int W;
    int H;
    bool click;
} button_icon, *button_iconP;

typedef struct
{
    int x;
    int y;
    int symbol[6];//鬼頭上的符號，存放符號的種類
    ALLEGRO_BITMAP* img;
    int moncount;
    bool appear;
    bool symboled;
    int now_symbol;

} Monster,*Monsterp;

typedef struct
{
    bool clear_stage;
    int time;
}stage_clear, *stage_cP;

typedef struct
{
    ALLEGRO_BITMAP* img;
    int x;
    int y;
}Symbol, *Symbolp;

typedef struct
{
    int x;
    int y;
} TrailPoint;

void startfunc(ALLEGRO_SAMPLE_INSTANCE *instance,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *startImg, ALLEGRO_BITMAP *menuImg,ALLEGRO_BITMAP *loading,
               ALLEGRO_BITMAP *volume_off, ALLEGRO_BITMAP *volume_on, button_iconP start_buttonP, button_iconP menu_buttonP,
               button_iconP back_buttonP, button_iconP score_buttonP, button_iconP volume_buttonP, button_iconP tutor_buttonP,
               button_iconP secret_buttonP,button_iconP exit_buttonP, button_iconP title_buttonP,stage_cP stage_cP);

void init_value(button_iconP start_buttonP, button_iconP menu_buttonP,button_iconP back_buttonP,button_iconP score_buttonP, button_iconP volume_buttonP,
                button_iconP tutor_buttonP,button_iconP secret_buttonP, button_iconP exit_buttonp, button_iconP respawnP, button_iconP main_menuP,
                Monsterp upmidp,Monsterp midleftp,Monsterp midrightp,Monsterp downmidp,Monsterp catp,
                Symbolp Horizontalp,Symbolp Verticalp,Symbolp Negative_slopep,Symbolp Positive_slopep,  stage_cP stage_cP,
                ALLEGRO_FONT *font);

void click_button(button_icon *button, ALLEGRO_BITMAP *img, int *x, int *y);

void gamestart(ALLEGRO_SAMPLE_INSTANCE *instance_spell, ALLEGRO_SAMPLE_INSTANCE *instance_die,ALLEGRO_DISPLAY *display,ALLEGRO_FONT *font,
               Monsterp upmidp,Monsterp midleftp,Monsterp midrightp,Monsterp downmidp,Monsterp catp,
               Symbolp Horizontalp,Symbolp Verticalp,Symbolp Negative_slopep,Symbolp Positive_slopep,
               int *countp, button_iconP respawn_buttonP, button_iconP title_buttonP, int symbol_num, float timer_speed,int total_mon,  stage_cP stage_cP, int stagenow, button_iconP volume_buttonP);

void exit_game(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue);



#endif //Headers_H_INCLUDED
