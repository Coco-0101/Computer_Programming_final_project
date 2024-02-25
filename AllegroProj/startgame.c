//#include "head.h"
//void startgame( ALLEGRO_FONT *font ,Monsterp upmidp, Monsterp midleftp, Monsterp midrightp, Monsterp downmidp)
//{
//    ALLEGRO_DISPLAY *display = NULL;
//    ALLEGRO_TIMER *timer = NULL;
//    ALLEGRO_EVENT event;
//    ALLEGRO_EVENT_QUEUE *event_queue=NULL;
//    display = al_create_display(WIDTH, HEIGHT);
//    event_queue = al_create_event_queue();
//    timer = al_create_timer(1.0 / 60.0);
//    al_register_event_source(event_queue, al_get_timer_event_source(timer));
//    al_register_event_source(event_queue, al_get_mouse_event_source());
//    al_register_event_source(event_queue, al_get_display_event_source(display));
//
//
//
//    al_start_timer(timer);
//    bool monsterAllClear = false;
//    while(monsterAllClear == false)
//    {
//
//        draw_mouse(display,upmidp,midleftp,midrightp,downmidp);
//    }
//}
