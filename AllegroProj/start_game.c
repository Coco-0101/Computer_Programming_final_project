#include "head.h"
void gamestart(ALLEGRO_SAMPLE_INSTANCE *instance_spell, ALLEGRO_SAMPLE_INSTANCE *instance_die,ALLEGRO_DISPLAY *display,ALLEGRO_FONT *font,
               Monsterp upmidp,Monsterp midleftp,Monsterp midrightp,Monsterp downmidp,Monsterp catp,
               Symbolp Horizontalp,Symbolp Verticalp,Symbolp Negative_slopep,Symbolp Positive_slopep,
               int *countp, button_iconP respawn_buttonP, button_iconP title_buttonP, int symbol_num, float timer_speed,
               int total_mon, stage_cP stage_cP, int stagenow,button_iconP volume_buttonP)
{
    *countp = 0;

    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    ALLEGRO_BITMAP* teasor1 = al_load_bitmap("./img/teasor1.png");
    ALLEGRO_BITMAP* teasor2 = al_load_bitmap("./img/teasor2.png");
    ALLEGRO_BITMAP* teasor3 = al_load_bitmap("./img/teasor3.png");
    ALLEGRO_BITMAP* deadImg = al_load_bitmap("./img/dead.png");
    ALLEGRO_BITMAP *loading = al_load_bitmap("./img/loading.png");
    ALLEGRO_BITMAP* game_BG = al_load_bitmap("./img/game_BG1.png");
    ALLEGRO_TIMER *timer = al_create_timer(timer_speed);
    ALLEGRO_COLOR color = al_map_rgb(255, 255, 255);
    ALLEGRO_FONT *font1 = al_load_font("arial.ttf", 24, 0);

    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_clear_to_color(al_map_rgb(0, 0, 0));


    switch (stagenow)
    {
    case 1:
        game_BG = al_load_bitmap("./img/game_BG1.png");
        break;
    case 2:
        game_BG = al_load_bitmap("./img/game_BG2.png");
        break;
    case 3:
        game_BG = al_load_bitmap("./img/game_BG3.png");
        break;
    case 4:
        game_BG = al_load_bitmap("./img/game_BG4.png");
        break;
    }
    catp->moncount = 5;
    int xp = 0;
    int yp = 0;
    int* x = &xp;
    int* y = &yp;

    int LW ;
    int RW ;
    int UH ;
    int DH ;

    int last_mon;
    int killed = 0;
    int start_x, start_y, end_x, end_y;
    int dis_x ;
    int dis_y = end_y-start_y;
    int num_trail_points = 0;
    TrailPoint trail[MAX_TRAIL_LENGTH];
    TrailPoint point;
// 定義是否在畫滑鼠軌跡的旗標
    bool draw_trail = false;
    bool down = true;
// 紀錄線條是哪一種
    int LineType = 0;
    int num_bar = 5;
    ALLEGRO_EVENT event;
// 開始計時器
    al_start_timer(timer);

    ALLEGRO_VERTEX prev_mouse_pos;

    al_draw_bitmap(game_BG, 0,0,0);
    draw_monster(display,upmidp,midleftp,midrightp,downmidp);

    al_flip_display();

    while (1)
    {

        al_wait_for_event(event_queue, &event);

        if (event.type == ALLEGRO_EVENT_TIMER)
        {
            if(event.timer.source == timer)
            {

                LW = WIDTH/2-al_get_bitmap_width(catp->img);
                RW = LW+al_get_bitmap_width(catp->img)+70;
                UH = HEIGHT/2-al_get_bitmap_height(catp->img);
                DH = UH+al_get_bitmap_height(catp->img)+50;

                *countp = *countp+1; // 獲取 timer 的時間


                al_draw_bitmap(game_BG, 0,0,0);

                /*===============================================我是分隔線===============================================*/


                if(*countp % 30 == 0)
                {
                    midleftp->appear =true;
                }

                if(midleftp->appear ==true)
                {
                    al_draw_bitmap(midleftp->img, midleftp->x,midleftp->y,0);

                    midleftp->img  = al_load_bitmap("./img/yagoo.png");

                    ///////////////////////////////
                    if(midleftp->symboled == false)
                    {
                        RandomSymbol(symbol_num,midleftp,9);
                    }

                    for(int i=0; i<symbol_num; i++)
                    {
                        if (midleftp->symbol[i]==2)
                        {
                            Horizontalp->x = (midleftp->x)+(i*50);
                            Horizontalp->y = midleftp->y - al_get_bitmap_height(Horizontalp->img);

                            al_draw_bitmap(Horizontalp->img, Horizontalp->x,Horizontalp->y,0);

                        }
                        if (midleftp->symbol[i]==1)
                        {

                            Verticalp->x = midleftp->x+(i*50);
                            Verticalp->y = midleftp->y - al_get_bitmap_height(Verticalp->img);

                            al_draw_bitmap(Verticalp->img, Verticalp->x,Verticalp->y,0);
                        }
                        if (midleftp->symbol[i]==3)
                        {

                            Positive_slopep->x = midleftp->x+(i*50);
                            Positive_slopep->y = midleftp->y - al_get_bitmap_height(Positive_slopep->img);

                            al_draw_bitmap(Positive_slopep->img, Positive_slopep->x,Positive_slopep->y,0);
                        }
                        if (midleftp->symbol[i]==4)
                        {
                            Negative_slopep->x = midleftp->x+(i*50);
                            Negative_slopep->y = midleftp->y - al_get_bitmap_height(Negative_slopep->img);

                            al_draw_bitmap(Negative_slopep->img, Negative_slopep->x,Negative_slopep->y,0);
                        }
                    }

                    if(*countp % 10 == 1 || *countp % 10 == 2)
                    {
                        midleftp->img  = al_load_bitmap("./img/yagoo_red.png");
                        al_draw_bitmap(midleftp->img, midleftp->x,midleftp->y,0);
                    }
                    midleftp->x = midleftp->x + (7+3*stagenow);
                }


                if(midleftp->x >= LW)
                {
                    midleftp->appear = false;
                    midleftp->x = -al_get_bitmap_width(midleftp->img);
                    catp->moncount=catp->moncount-1;
                }

                /*===============================================我是分隔線===============================================*/
                if(*countp % 60 == 0)
                {
                    midrightp->appear =true;
                }

                if(midrightp->appear ==true)
                {
                    midrightp->img  = al_load_bitmap("./img/yagoo.png");
                    al_draw_bitmap(midrightp->img, midrightp->x,midrightp->y,ALLEGRO_FLIP_HORIZONTAL);

                    if(midrightp->symboled == false)
                    {
                        RandomSymbol(symbol_num,midrightp,3);
                    }

                    for(int i=0; i<symbol_num; i++)
                    {
                        if (midrightp->symbol[i]==2)
                        {
                            Horizontalp->x = (midrightp->x)+(i*50);
                            Horizontalp->y = midrightp->y - al_get_bitmap_height(Horizontalp->img);

                            al_draw_bitmap(Horizontalp->img, Horizontalp->x,Horizontalp->y,0);

                        }
                        if (midrightp->symbol[i]==1)
                        {

                            Verticalp->x = midrightp->x+(i*50);
                            Verticalp->y = midrightp->y - al_get_bitmap_height(Verticalp->img);

                            al_draw_bitmap(Verticalp->img, Verticalp->x,Verticalp->y,0);
                        }
                        if (midrightp->symbol[i]==3)
                        {

                            Positive_slopep->x = midrightp->x+(i*50);
                            Positive_slopep->y = midrightp->y - al_get_bitmap_height(Positive_slopep->img);

                            al_draw_bitmap(Positive_slopep->img, Positive_slopep->x,Positive_slopep->y,0);
                        }
                        if (midrightp->symbol[i]==4)
                        {
                            Negative_slopep->x = midrightp->x+(i*50);
                            Negative_slopep->y = midrightp->y - al_get_bitmap_height(Negative_slopep->img);

                            al_draw_bitmap(Negative_slopep->img, Negative_slopep->x,Negative_slopep->y,0);
                        }
                    }

                    if(*countp % 10 == 1 || *countp % 10 == 2)
                    {
                        midrightp->img  = al_load_bitmap("./img/yagoo_blue.png");
                        al_draw_bitmap(midrightp->img, midrightp->x,midrightp->y,ALLEGRO_FLIP_HORIZONTAL);
                    }
                    midrightp->x = midrightp->x - (7+3*stagenow);
                }

                if(midrightp->x < RW)
                {
                    midrightp->appear = false;
                    midrightp->x =  WIDTH;
                    catp->moncount=catp->moncount-1;
                }

                /*===============================================我是分隔線===============================================*/

                if(*countp % 90 == 0)
                {
                    upmidp->appear =true;
                }

                if(upmidp->appear ==true)
                {
                    upmidp->img  = al_load_bitmap("./img/yagoo.png");
                    al_draw_bitmap(upmidp->img, upmidp->x, upmidp->y,0);
                    if(upmidp->symboled == false)
                    {
                        RandomSymbol(symbol_num,upmidp,5);
                    }

                    for(int i=0; i<symbol_num; i++)
                    {
                        if (upmidp->symbol[i]==2)
                        {
                            Horizontalp->x = (upmidp->x)+(i*50);
                            Horizontalp->y = upmidp->y - al_get_bitmap_height(Horizontalp->img);

                            al_draw_bitmap(Horizontalp->img, Horizontalp->x,Horizontalp->y,0);

                        }
                        if (upmidp->symbol[i]==1)
                        {

                            Verticalp->x = upmidp->x+(i*50);
                            Verticalp->y = upmidp->y - al_get_bitmap_height(Verticalp->img);

                            al_draw_bitmap(Verticalp->img, Verticalp->x,Verticalp->y,0);
                        }
                        if (upmidp->symbol[i]==3)
                        {

                            Positive_slopep->x = upmidp->x+(i*50);
                            Positive_slopep->y = upmidp->y - al_get_bitmap_height(Positive_slopep->img);

                            al_draw_bitmap(Positive_slopep->img, Positive_slopep->x,Positive_slopep->y,0);
                        }
                        if (upmidp->symbol[i]==4)
                        {
                            Negative_slopep->x = upmidp->x+(i*50);
                            Negative_slopep->y = upmidp->y - al_get_bitmap_height(Negative_slopep->img);

                            al_draw_bitmap(Negative_slopep->img, Negative_slopep->x,Negative_slopep->y,0);
                        }
                    }
                    if(*countp % 10 == 1 || *countp % 10 == 2)
                    {
                        upmidp->img  = al_load_bitmap("./img/yagoo_green.png");
                        al_draw_bitmap(upmidp->img, upmidp->x,upmidp->y,0);
                    }
                    upmidp->y = upmidp->y + (7+3*stagenow);
                }


                if(upmidp->y > UH)
                {
                    upmidp->appear = false;
                    upmidp->y = -al_get_bitmap_height(upmidp->img);
                    catp->moncount=catp->moncount-1;
                }

               /*===============================================我是分隔線===============================================*/

                if(*countp % 120 == 0)
                {
                    downmidp->appear =true;
                }

                if(downmidp->appear ==true)
                {

                    downmidp->img  = al_load_bitmap("./img/yagoo.png");
                    al_draw_bitmap(downmidp->img, downmidp->x, downmidp->y, ALLEGRO_FLIP_HORIZONTAL);

                    if(downmidp->symboled == false)
                    {
                        RandomSymbol(symbol_num,downmidp,7);
                    }

                    for(int i=0; i<symbol_num; i++)
                    {
                        if (downmidp->symbol[i]==2)
                        {
                            Horizontalp->x = (downmidp->x)+(i*50);
                            Horizontalp->y = downmidp->y - al_get_bitmap_height(Horizontalp->img);

                            al_draw_bitmap(Horizontalp->img, Horizontalp->x,Horizontalp->y,0);

                        }
                        if (downmidp->symbol[i]==1)
                        {

                            Verticalp->x = downmidp->x+(i*50);
                            Verticalp->y = downmidp->y - al_get_bitmap_height(Verticalp->img);

                            al_draw_bitmap(Verticalp->img, Verticalp->x,Verticalp->y,0);
                        }
                        if (downmidp->symbol[i]==3)
                        {

                            Positive_slopep->x = downmidp->x+(i*50);
                            Positive_slopep->y = downmidp->y - al_get_bitmap_height(Positive_slopep->img);

                            al_draw_bitmap(Positive_slopep->img, Positive_slopep->x,Positive_slopep->y,0);
                        }
                        if (downmidp->symbol[i]==4)
                        {
                            Negative_slopep->x = downmidp->x+(i*50);
                            Negative_slopep->y = downmidp->y - al_get_bitmap_height(Negative_slopep->img);

                            al_draw_bitmap(Negative_slopep->img, Negative_slopep->x,Negative_slopep->y,0);
                        }
                    }
                    if(*countp % 10 == 1 || *countp % 10 == 2)
                    {
                        downmidp->img  = al_load_bitmap("./img/yagoo_yellow.png");
                        al_draw_bitmap(downmidp->img, downmidp->x,downmidp->y,ALLEGRO_FLIP_HORIZONTAL);
                    }

                    downmidp->y = downmidp->y - (7+3*stagenow);
                }

                if(downmidp->y < DH)
                {
                    downmidp->appear = false;
                    downmidp->y = HEIGHT;
                    catp->moncount=catp->moncount-1;
                }
                al_draw_bitmap(catp->img, catp->x, catp->y, 0);
                for(int catheart=0; catheart<= (catp->moncount-1); catheart++)
                {
                    ALLEGRO_BITMAP* catheartimg  = al_load_bitmap("./img/heart.png");
                    al_draw_bitmap(catheartimg, catp->x+10+20*catheart,catp->y+30,0);
                }
                al_draw_textf(font1, al_map_rgb(255, 255, 255), 150, 25, ALLEGRO_ALIGN_CENTRE, "Time: %ds", *countp/15);
                last_mon = total_mon-killed;
                al_draw_textf(font1, al_map_rgb(255, 255, 255), WIDTH-150, 25, ALLEGRO_ALIGN_CENTRE, "Yagoo last: %d", last_mon);
                al_draw_textf(font1, al_map_rgb(255, 255, 255), 960, 25, ALLEGRO_ALIGN_CENTRE, "STAGE: %d", stagenow);
                al_flip_display();
            }
        }
        if(catp->moncount <= 0)
        {
            goto dead;
        }

        /*===============================================我是分隔線===============================================*/

        if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            // 記錄滑鼠最初的位置
            start_x = event.mouse.x;
            start_y = event.mouse.y;
            prev_mouse_pos.x = event.mouse.x;
            prev_mouse_pos.y = event.mouse.y;
            asd
            num_trail_points = 0;
            memset(trail, 0, sizeof(trail));
            // 設定旗標為正在畫滑鼠軌跡
            draw_trail = true;
        }
        // 當發生鼠標放開事件
        else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
        {
            // 記錄滑鼠最終的位置
            end_x = event.mouse.x;
            end_y = event.mouse.y;
            al_clear_to_color(al_map_rgb(0, 0, 0));
            draw_trail = false;
            down = false;
            // 印出滑鼠最初的位置和最終位置

            dis_x= end_x-start_x;
            dis_y= end_y-start_y;

            if (abs(dis_x)<100)
            {
                printf("vertical line \n");
                LineType = 1;
            }
            if (abs(dis_y)<100)
            {
                printf("horizontal line\n");
                LineType = 2;
            }
            if (LineType != 1 && LineType != 2)
            {
                if(dis_x*dis_y<0)
                {
                    printf("slope>0 \n");
                    LineType = 3;
                }
                if(dis_x*dis_y>0)
                {
                    printf("slope<0 \n");
                    LineType = 4;
                }
            }
            printf("\nLineType :%d\n",LineType);


        /*===================================================我是分隔線====================================================*/

            if (midleftp->appear)
            {
                if(midleftp->symbol[midleftp->now_symbol] == LineType )
                {
                    printf("Attack midleft!\n");
                    if(volume_buttonP->click)
                    {
                        al_set_sample_instance_playing(instance_spell, false);
                        al_set_sample_instance_playing(instance_spell, true);
                    }
                    midleftp->symbol[midleftp->now_symbol]=0;
                    midleftp->now_symbol++;
                    if(midleftp->symbol[midleftp->now_symbol]==0)
                    {
                        if(volume_buttonP->click)
                        {
                            al_set_sample_instance_pan(instance_die, 0);
                            al_set_sample_instance_playing(instance_die,true);
                        };
                        killed = killed +1;
                        midleftp->appear = false;
                        midleftp->symboled = false;
                        midleftp->x = -al_get_bitmap_width(midleftp->img);
                        midleftp->y = (HEIGHT - al_get_bitmap_width(midleftp->img))/ 2;
                    }
                }
            }
            if (midrightp->appear)
            {
                if(midrightp->symbol[midrightp->now_symbol] == LineType )
                {
                    printf("Attack midrightp!\n");
                    if(volume_buttonP->click)
                    {
                        al_set_sample_instance_playing(instance_spell, false);
                        al_set_sample_instance_playing(instance_spell, true);
                    }
                    midrightp->symbol[midrightp->now_symbol]=0;
                    midrightp->now_symbol++;
                    if(midrightp->symbol[midrightp->now_symbol]==0)
                    {
                        if(volume_buttonP->click)
                        {
                            al_set_sample_instance_pan(instance_die, 0);
                            al_set_sample_instance_playing(instance_die,true);
                        }
                        killed = killed +1;
                        midrightp->appear = false;
                        midrightp->symboled = false;
                        midrightp->x = WIDTH;
                        midrightp->y = (HEIGHT - al_get_bitmap_height(midrightp->img))/ 2;
                    }
                }
            }
            if (upmidp->appear)
            {
                if(upmidp->symbol[upmidp->now_symbol] == LineType )
                {
                    printf("Attack upmidp!\n");
                    if(volume_buttonP->click)
                    {
                        al_set_sample_instance_playing(instance_spell, false);
                        al_set_sample_instance_playing(instance_spell, true);
                    }

                    upmidp->symbol[upmidp->now_symbol]=0;
                    upmidp->now_symbol++;
                    if(upmidp->symbol[upmidp->now_symbol]==0)
                    {
                        if(volume_buttonP->click)
                        {
                            al_set_sample_instance_pan(instance_die, 0);
                            al_set_sample_instance_playing(instance_die,true);
                        }
                        killed = killed +1;
                        upmidp->appear = false;
                        upmidp->symboled = false;
                        upmidp->x = (WIDTH - al_get_bitmap_width(upmidp->img))/ 2;
                        upmidp->y = -al_get_bitmap_height(upmidp->img);
                    }
                }
            }
            if (downmidp->appear)
            {
                if(downmidp->symbol[downmidp->now_symbol] == LineType )
                {
                    printf("Attack downmidp!\n");
                    if(volume_buttonP->click)
                    {
                        al_set_sample_instance_playing(instance_spell, false);
                        al_set_sample_instance_playing(instance_spell, true);
                    }
                    downmidp->symbol[downmidp->now_symbol]=0;
                    downmidp->now_symbol++;
                    if(downmidp->symbol[downmidp->now_symbol]==0)
                    {
                        if(volume_buttonP->click)
                        {
                            al_set_sample_instance_pan(instance_die, 0);
                            al_set_sample_instance_playing(instance_die,true);
                        }
                        killed = killed +1;
                        downmidp->appear = false;
                        downmidp->symboled = false;
                        downmidp->x = (WIDTH - al_get_bitmap_width(downmidp->img))/ 2;
                        downmidp->y = HEIGHT;
                    }
                }
            }

    /*===================================================我是分隔線===================================================*/

            LineType=0;
            if (killed >= total_mon)
                goto clear;
        }
        // 當發生計時器事件
        else if (event.type == ALLEGRO_EVENT_TIMER)
        {
            // 當正在畫滑鼠軌跡時
            if (draw_trail)
            {
                if(*countp % 3 == 0)
                {
                    al_draw_bitmap(teasor1, catp->x+110, catp->y,0);
                }
                else if(*countp % 3 == 1)
                {
                    al_draw_bitmap(teasor2, catp->x+110, catp->y,0);
                }
                else if(*countp % 3 == 2)
                {
                    al_draw_bitmap(teasor3, catp->x+110, catp->y,0);
                }
                // 繪製滑鼠
                ALLEGRO_MOUSE_STATE mouse_state;
                al_get_mouse_state(&mouse_state);
                int x,y;
                x = prev_mouse_pos.x;
                y = prev_mouse_pos.y;
                point.x = x;
                point.y = y;
                trail[num_trail_points++] = point;
                for (int i = 1; i < num_trail_points; i++)
                {
                    al_draw_line(trail[i - 1].x, trail[i - 1].y, trail[i].x, trail[i].y, al_map_rgb(255, 255, 255), 2);
                }
                al_flip_display();
                prev_mouse_pos.x = mouse_state.x;
                prev_mouse_pos.y = mouse_state.y;
                prev_mouse_pos = (ALLEGRO_VERTEX)
                {
                    mouse_state.x, mouse_state.y, 0, 0, 0, 0
                };
            }
        }
    }
clear:
    //過關
    stage_cP[stagenow].clear_stage = true;
    stage_cP[stagenow].time = (int)*countp/15;
    goto next;


dead:
    stage_cP[stagenow].clear_stage = false;
    stage_cP[stagenow].time = (int)*countp/15;
    al_draw_bitmap(deadImg, 0,0,0);
    al_draw_textf(font1, al_map_rgb(255, 255, 255), 1030, 360, ALLEGRO_ALIGN_CENTRE, "%d", *countp/15);
    al_flip_display();
    midleftp->appear = false;
    midleftp->x = -al_get_bitmap_width(midleftp->img);
    midrightp->appear = false;
    midrightp->x =  WIDTH;
    upmidp->appear = false;
    downmidp->appear = false;
    downmidp->y = HEIGHT;
    upmidp->y = -al_get_bitmap_height(upmidp->img);
    upmidp->symboled = false;
    downmidp->symboled = false;
    midleftp->symboled = false;
    midrightp->symboled = false;

    while (1)
    {
        al_wait_for_event(event_queue, &event);
        if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
        {
            *x = event.mouse.x;
            *y = event.mouse.y;
            printf("mouse x:%d y:%d\n",*x,*y);
            click_button(respawn_buttonP,loading, x, y);
            click_button(title_buttonP,loading, x, y);

            //click_button(exit_buttonP,start_buttonP->img, x, y);
            if (respawn_buttonP->click == true || title_buttonP->click == true)
            {
                break;
            }

//            if (exit_buttonP->click == true)
//            {
//                exit_game(display, event_queue);
//            }
        }
    }
next:
;

}






