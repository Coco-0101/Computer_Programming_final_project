#include "head.h"
void startfunc(ALLEGRO_SAMPLE_INSTANCE *instance,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *startImg, ALLEGRO_BITMAP *menuImg,ALLEGRO_BITMAP *loading,
               ALLEGRO_BITMAP *volume_off, ALLEGRO_BITMAP *volume_on, button_iconP start_buttonP, button_iconP menu_buttonP,
               button_iconP back_buttonP, button_iconP score_buttonP, button_iconP volume_buttonP, button_iconP tutor_buttonP,
               button_iconP secret_buttonP,button_iconP exit_buttonP, button_iconP title_buttonP,stage_cP stage_cP)
{
    ALLEGRO_EVENT event;
    ALLEGRO_EVENT_QUEUE *event_queue=NULL;
    startImg = al_load_bitmap("./img/start.png");
    menuImg = al_load_bitmap("./img/menu.png");
    event_queue = al_create_event_queue();
    ALLEGRO_FONT *font1 = NULL;
    font1 = al_load_font("arial.ttf", 45, 0);
    al_register_event_source(event_queue, al_get_mouse_event_source());
    if(title_buttonP->click)
    {

        goto SKIP_EVENT;
    }
    al_register_event_source(event_queue, al_get_display_event_source(display));

SKIP_EVENT:
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(startImg, 0, 0, 0);
    al_flip_display();

    int xp = 0;
    int yp = 0;
    int* x =&xp;
    int* y =&yp;

    bool click = true;
    bool *clickP = &click;
    printf("%d",menu_buttonP->click);

START:

    while (!menu_buttonP->click)
    {
        al_wait_for_event(event_queue, &event);
        if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
        {
            *x = event.mouse.x;
            *y = event.mouse.y;

            click_button(start_buttonP,startImg, x, y);
            click_button(menu_buttonP,menuImg, x, y);
            click_button(exit_buttonP,startImg, x, y);
            if (start_buttonP->click == true)
            {
                start_buttonP->click = false;
                al_draw_bitmap(loading, 0, 0, 0);
                al_flip_display();
                al_rest(0.3);
                break;
            }
            if (exit_buttonP->click == true)
            {
                exit_buttonP->click = false;
                exit_game(display, event_queue);
            }
        }
    }



MENU:

    if (menu_buttonP->click == true)
    {
        printf("volume:%d\n",volume_buttonP->click);
        if (volume_buttonP->click == false)
            al_draw_bitmap(volume_off, 640, 560, 0);
        else if(volume_buttonP->click == true)
            al_draw_bitmap(volume_on, 620, 560, 0);
        al_flip_display();
    }


    while(menu_buttonP->click)
    {
        al_wait_for_event(event_queue, &event);
        if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
        {
            *x = event.mouse.x;
            *y = event.mouse.y;
            printf("mouse x:%d y:%d\n",*x,*y);
            click_button(back_buttonP,startImg, x, y);

            click_button(score_buttonP,score_buttonP->img, x, y);
            if(score_buttonP->click)
            {
                for(int i=1; i<=4; i++)
                {
                    al_draw_textf(font1, al_map_rgb(255, 255, 255), 380+300*i,578, ALLEGRO_ALIGN_CENTRE, "Stage %d : %d s", i, stage_cP[i].time);
                }
                al_flip_display();
            }
            click_button(tutor_buttonP,tutor_buttonP->img, x, y);
            click_button(secret_buttonP,secret_buttonP->img, x, y);

            if (*x>=volume_buttonP->X && *y >= volume_buttonP->Y && *x <= (volume_buttonP->X+volume_buttonP->W) &&
                    *y<=(volume_buttonP->Y+volume_buttonP->H))
            {
                al_draw_bitmap(menuImg, 0, 0, 0);
                if (volume_buttonP->click == true) //volume_off!!!!!
                {
                    al_set_sample_instance_playing(instance, false);
                    al_draw_bitmap(volume_off, 640, 560, 0);
                }
                else if(volume_buttonP->click == false)  //volume_on!!!!!
                {

                    al_set_sample_instance_playing(instance, true);
                    al_draw_bitmap(volume_on, 620, 560, 0);
                }

                al_flip_display();
                volume_buttonP->click = !volume_buttonP->click;
                printf("Volume:%d\n",volume_buttonP->click);
                printf("Click button!\n");
            }


            if(score_buttonP->click == true || tutor_buttonP->click == true || secret_buttonP->click == true)
            {
                while(1)
                {
                    al_wait_for_event(event_queue, &event);
                    if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
                    {
                        *x = event.mouse.x;
                        *y = event.mouse.y;
                        click_button(back_buttonP,menuImg, x, y);
                        if (back_buttonP->click == true)
                        {
                            back_buttonP->click = false;
                            score_buttonP->click = false;
                            tutor_buttonP->click = false;
                            secret_buttonP->click = false;
                            goto MENU;
                        }
                    }


                }

            }
            else if (back_buttonP->click == true)
            {
                back_buttonP->click = false;
                menu_buttonP->click = false;
                goto START;
            }

        }
    }
}
