#include "head.h"
int main(int argc, char **argv)
{
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_FONT *font = NULL;
    ALLEGRO_BITMAP *volume_off = NULL;
    ALLEGRO_BITMAP *volume_on = NULL;
    ALLEGRO_BITMAP *startImg = NULL;
    ALLEGRO_BITMAP *menuImg = NULL;
    ALLEGRO_BITMAP* clearimg= NULL;
    ALLEGRO_BITMAP* congratulations = NULL;
    ALLEGRO_BITMAP *loading = NULL;
    ALLEGRO_EVENT event;
    ALLEGRO_EVENT_QUEUE *event_queue=NULL;

    Monster upmid,midleft,midright,downmid,cat;
    Monsterp upmidp,midleftp,midrightp,downmidp,catp;

    Symbol Horizontal,Vertical,Negative_slope,Positive_slope;
    Symbolp  Horizontalp,Verticalp,Negative_slopep,Positive_slopep;

    stage_clear stage_clear[5];
    stage_cP stage_cP = &stage_clear;

    catp = &cat;
    upmidp = &upmid;
    midleftp = &midleft;
    midrightp = &midright;
    downmidp = &downmid;

    button_icon start_button, menu_button, exit_button, score_button, volume_button, tutor_button, secret_button, back_button, respawn_button, title_button;
    button_iconP start_buttonP, menu_buttonP, exit_buttonP, score_buttonP, volume_buttonP, tutor_buttonP, secret_buttonP, back_buttonP, respawn_buttonP, title_buttonP;
    start_buttonP = &start_button;
    start_buttonP = &start_button;
    menu_buttonP = &menu_button;
    score_buttonP = &score_button;
    exit_buttonP = &exit_button;
    volume_buttonP = &volume_button;
    tutor_buttonP = &tutor_button;
    secret_buttonP = &secret_button;
    back_buttonP = &back_button;
    Horizontalp = &Horizontal;
    Verticalp = &Vertical;
    Negative_slopep = &Negative_slope;
    Positive_slopep = &Positive_slope;
    respawn_buttonP = &respawn_button;
    title_buttonP = &title_button;

    int symbol_num = 1;
    float timer_speed = 0.06;
    int total_mon = 15;
    int stagenow = 1;
    int count = 1;
    int *countp = &count;

    init();
    init_value( start_buttonP, menu_buttonP, back_buttonP, score_buttonP, volume_buttonP,
                tutor_buttonP, secret_buttonP,  exit_buttonP, respawn_buttonP, title_buttonP,
                upmidp, midleftp, midrightp, downmidp, catp, Horizontalp, Verticalp, Negative_slopep,
                Positive_slopep, stage_cP, font);

    display = al_create_display(WIDTH, HEIGHT);

   /*BACKGROUND & SOUND EFFECTS*/
    ALLEGRO_SAMPLE* background = NULL;
    background = al_load_sample("Hello.mp3"); // load the background sound file
    ALLEGRO_SAMPLE_INSTANCE *instance = al_create_sample_instance(background);
    al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());
    al_set_sample_instance_gain(instance, 0.2);
    al_play_sample_instance(instance);

    ALLEGRO_SAMPLE* spell = NULL;
    spell = al_load_sample("spell.wav");
    ALLEGRO_SAMPLE_INSTANCE *ins_spell = al_create_sample_instance(spell);
    al_set_sample_instance_playmode(ins_spell, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(ins_spell, al_get_default_mixer());

    ALLEGRO_SAMPLE* die = NULL;
    die = al_load_sample("die.wav");
    ALLEGRO_SAMPLE_INSTANCE *ins_die = al_create_sample_instance(die);
    al_set_sample_instance_playmode(ins_die, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(ins_die, al_get_default_mixer());
    al_set_sample_instance_gain(ins_die, 5);

;
    congratulations = al_load_bitmap("./img/congratulations.png");;
    loading = al_load_bitmap("./img/loading.png");
    clearimg = al_load_bitmap("./img/clear.png");
    volume_off = al_load_bitmap("./img/volume_off.png");
    volume_on = al_load_bitmap("./img/volume_on.png");

TITLE:
    startfunc(instance, display, startImg, menuImg, loading,volume_off, volume_on,
              start_buttonP, menu_buttonP, back_buttonP, score_buttonP, volume_buttonP,
              tutor_buttonP, secret_buttonP, exit_buttonP, title_buttonP, stage_cP);
    title_buttonP->click = false;
GAME:
    gamestart(ins_spell, ins_die,display, font, upmidp, midleftp, midrightp, downmidp, catp,Horizontalp,
              Verticalp, Negative_slopep, Positive_slopep, countp, respawn_buttonP, title_buttonP,symbol_num,
              timer_speed, total_mon, stage_cP, stagenow, volume_buttonP);

    if(stage_cP[stagenow].clear_stage)
    {
        al_draw_bitmap(clearimg, 0, 0, 0);
        al_flip_display();
        al_rest(2);
        stagenow=stagenow+1;
        if(stagenow ==5)
        {
            title_buttonP->click = true;
            symbol_num = 1;
            timer_speed = 0.06;
            total_mon = 15;
            stagenow = 1;
            al_draw_bitmap(congratulations, 0, 0, 0);
            al_flip_display();
            al_rest(2);
            goto TITLE;
        }
        total_mon = total_mon+10;
        symbol_num = symbol_num+1;
        goto GAME;
    }

    if (respawn_buttonP->click == true)
    {
        al_rest(0.3);
        printf("Respawn\n");
        respawn_buttonP->click = false;
        goto GAME;
    }
    if (title_buttonP->click == true)
    {
        al_rest(0.3);
        printf("Title\n");
        goto TITLE;
    }

    system("pause");
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);

    return 0;
}


void init()
{
    al_init();
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_install_mouse();
    al_init_acodec_addon();     // initialize the audio codec add-on
    al_install_audio();         // install sound driver
    al_reserve_samples(10);
}


void exit_game(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue)
{
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
    return 0;
}

