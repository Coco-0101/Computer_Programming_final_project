#include "head.h"

void monster_run(ALLEGRO_EVENT event, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_TIMER *timer,Monsterp catp, int* countp,
                  Monsterp upmidp,Monsterp midleftp,Monsterp midrightp,Monsterp downmidp)
{
    al_wait_for_event(event_queue, &event);

    if (event.type == ALLEGRO_EVENT_TIMER)
    {
        if(event.timer.source == timer)
        {
            int LW = WIDTH/2-al_get_bitmap_width(catp->img);
            int RW = LW+al_get_bitmap_width(catp->img)+70;
            int UH = HEIGHT/2-al_get_bitmap_height(catp->img);
            int DH = UH+al_get_bitmap_height(catp->img)+50;

            *countp = *countp+1; // 獲取 timer 的時間

            midleftp->moncount = midleftp->moncount+10;
            midrightp->moncount = midrightp->moncount+10;
            upmidp->moncount = upmidp->moncount+10;
            downmidp->moncount = downmidp->moncount+10;


            al_clear_to_color(al_map_rgb(0,0,0));

            /*===============================================我是分隔線===============================================*/

            if(*countp % 30 == 0)
            {
                midleftp->appear =true;
            }

            if(midleftp->appear ==true)
            {
                midleftp->img  = al_load_bitmap("./img/yagoo.png");
                al_draw_bitmap(midleftp->img, midleftp->x,midleftp->y,0);

                if(*countp % 10 == 1 || *countp % 10 == 2)
                {
                    midleftp->img  = al_load_bitmap("./img/yagoo_red.png");
                    al_draw_bitmap(midleftp->img, midleftp->x,midleftp->y,0);
                }
                midleftp->x = midleftp->x + 10;
            }


            if(midleftp->x >= LW)
            {
                midleftp->appear = false;
                midleftp->x = -al_get_bitmap_width(midleftp->img);
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

                if(*countp % 10 == 1 || *countp % 10 == 2)
                {
                    midrightp->img  = al_load_bitmap("./img/yagoo_blue.png");
                    al_draw_bitmap(midrightp->img, midrightp->x,midrightp->y,ALLEGRO_FLIP_HORIZONTAL);
                }
                 midrightp->x = midrightp->x - 10;
            }

            if(midrightp->x < RW)
            {
                midrightp->appear = false;
                midrightp->x =  WIDTH;

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

                if(*countp % 10 == 1 || *countp % 10 == 2)
                {
                    upmidp->img  = al_load_bitmap("./img/yagoo_green.png");
                    al_draw_bitmap(upmidp->img, upmidp->x,upmidp->y,0);
                }

                upmidp->y = upmidp->y + 10;
            }


            if(upmidp->y > UH)
            {
                upmidp->appear = false;
                upmidp->y = -al_get_bitmap_height(upmidp->img);
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

                if(*countp % 10 == 1 || *countp % 10 == 2)
                {
                    downmidp->img  = al_load_bitmap("./img/yagoo_yellow.png");
                    al_draw_bitmap(downmidp->img, downmidp->x,downmidp->y,ALLEGRO_FLIP_HORIZONTAL);
                }

                downmidp->y = downmidp->y - 10;
            }

            if(downmidp->y < DH)
            {
                downmidp->appear = false;
                downmidp->y = HEIGHT;
            }


            al_draw_bitmap(catp->img, catp->x, catp->y, 0);
            al_flip_display();
        }
    }
}
