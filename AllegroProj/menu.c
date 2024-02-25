//#include "head.h"
//void  menufunc(button_icon start_button,button_icon class_score_button,button_icon class_avg_SD_button,button_icon rank_button,button_icon individual_avg_button,
//               button_icon new_data_button,button_icon exit_button,button_icon math_button,button_icon eng_button,button_icon sci_button,button_icon total_button,
//               button_icon exit_button2,ALLEGRO_BITMAP *menu,ALLEGRO_BITMAP *start_screen,ALLEGRO_BITMAP *start,ALLEGRO_DISPLAY *display,ALLEGRO_BITMAP *avgsd
//               ,ALLEGRO_FONT *font,ALLEGRO_FONT *fontID,ALLEGRO_BITMAP *on_button)
//{
//    ALLEGRO_EVENT event;
//    ALLEGRO_EVENT_QUEUE *event_queue=NULL;
//    event_queue = al_create_event_queue();
//    al_register_event_source(event_queue, al_get_display_event_source(display));
//    al_register_event_source(event_queue, al_get_mouse_event_source());
//    al_register_event_source(event_queue, al_get_keyboard_event_source());
//    int input=0,input1=0,input2=0,input_num=0;
//    int x,y;
//    bool redraw = true;
//    bool not_click_rank = true;
//    STU_grade grade[30];
//
//    while (true)
//    {
//        ALLEGRO_EVENT event;
//        int keyd=0,pri = 0;
//        if (redraw)
//        {
//            if(!not_click_rank)
//            {
//                redraw = false;
//                al_clear_to_color(al_map_rgb(0, 0, 0));
//                al_draw_bitmap(avgsd, 0, 0, 0);
//
//            }
//            else if(not_click_rank)
//            {
//                redraw = false;
//                al_clear_to_color(al_map_rgb(0, 0, 0));
//                al_draw_bitmap(menu, 0, 0, 0);
//            }
//            while (true)
//            {
//again:
//                al_wait_for_event(event_queue, &event);
//                //Personal average
//                if (event.type == ALLEGRO_EVENT_KEY_UP&&not_click_rank)
//                {
//                    if((event.keyboard.keycode>=27&&event.keyboard.keycode<=36)||(event.keyboard.keycode>=37&&event.keyboard.keycode<=46)||event.keyboard.keycode == 67 || event.keyboard.keycode==91)
//                    {
//                        if ( event.keyboard.keycode == 67 || event.keyboard.keycode==91)
//                        {
//                            redraw = true;
//                            if (input_num==2)
//                            {
//                                input=input1*10+input2;
//                            }
//                            else
//                            {
//                                input=input1;
//                            }
//                            printf("%d",input);
//                            float avgscore =(pg[input-1].Math+pg[input-1].English+pg[input-1].Science)/3;
//                            al_draw_textf(fontID, al_map_rgb(0, 0, 0), (WIDTH / 2)-100, 400,    ALLEGRO_ALIGN_CENTRE, "ID");
//                            al_draw_textf(fontID, al_map_rgb(0, 0, 0), (WIDTH / 2)+100, 400,    ALLEGRO_ALIGN_CENTRE, "Average score");
//                            al_draw_textf(fontID, al_map_rgb(0, 0, 0), (WIDTH / 2)-100, 80+400, ALLEGRO_ALIGN_CENTRE, "%d",pg[input-1].ID);
//                            al_draw_textf(fontID, al_map_rgb(0, 0, 0), (WIDTH / 2)+80,  80+400, ALLEGRO_ALIGN_CENTRE, "%.2f",avgscore );
//                            input1=0;
//                            input2=0;
//                            input_num=0;
//                            pri = 0;
//                            break;
//                        }
//                        if (input1==0 && event.keyboard.keycode<=36)
//                        {
//                            input1=(event.keyboard.keycode-27);
//                            keyd++;
//                        }
//                        else if(input1!=0 && event.keyboard.keycode<=36)
//                        {
//                            input2=(event.keyboard.keycode-27);
//                            input_num=2;
//                            keyd++;
//                        }
//                        else if(input1==0 && event.keyboard.keycode>36)
//                        {
//                            input1=(event.keyboard.keycode-37);
//                            keyd++;
//                        }
//                        else if(input1!=0 && event.keyboard.keycode>36)
//                        {
//                            input2=(event.keyboard.keycode-37);
//                            input_num=2;
//                            keyd++;
//                        }
//                        if(pri == 0)
//                    {
//                        al_draw_textf(fontID, al_map_rgb(0, 0, 0), 1550+9*keyd,280, ALLEGRO_ALIGN_CENTRE, " %d",input1);
//                        al_flip_display();
//                        pri++;
//                    }
//                    pri++;
//                    if(pri ==3)
//                    {
//                        al_draw_textf(fontID, al_map_rgb(0, 0, 0), 1563+9*keyd,280, ALLEGRO_ALIGN_CENTRE, " %d",input2);
//                        al_flip_display();
//                    }
//                    goto again;
//                    }
//                }
//                else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
//                {
//
//                    x = event.mouse.x;
//                    y = event.mouse.y;
//                    // 檢查用戶是否點擊了“全班成績”按鈕
//                    if (x >= class_score_button->X && x <= class_score_button->X+class_score_button->W &&y >= class_score_button->Y && y <= class_score_button->Y +class_score_button->H&&not_click_rank)
//                    {
//                        al_draw_textf(font, al_map_rgb(0, 0, 0), (WIDTH / 2.6),    100, ALLEGRO_ALIGN_CENTRE, "ID");
//                        al_draw_textf(font, al_map_rgb(0, 0, 0), (WIDTH / 2.6)+75, 100, ALLEGRO_ALIGN_CENTRE, "|");
//                        al_draw_textf(font, al_map_rgb(0, 0, 0), (WIDTH / 2.6)+150,100, ALLEGRO_ALIGN_CENTRE, "Math");
//                        al_draw_textf(font, al_map_rgb(0, 0, 0), (WIDTH / 2.6)+225,100, ALLEGRO_ALIGN_CENTRE, "|");
//                        al_draw_textf(font, al_map_rgb(0, 0, 0), (WIDTH / 2.6)+300,100, ALLEGRO_ALIGN_CENTRE, "English");
//                        al_draw_textf(font, al_map_rgb(0, 0, 0), (WIDTH / 2.6)+375,100, ALLEGRO_ALIGN_CENTRE, "|");
//                        al_draw_textf(font, al_map_rgb(0, 0, 0), (WIDTH / 2.6)+450,100, ALLEGRO_ALIGN_CENTRE, "Science");
//                        al_draw_textf(font, al_map_rgb(0, 0, 0), (WIDTH / 2)+10,   115, ALLEGRO_ALIGN_CENTRE, FRAME_LINE);
//
//                        // 執行遊戲主體
//                        for (int i = 0; i<30; i++)
//                        {
//                            al_draw_textf(font, al_map_rgb(0, 0, 0), (WIDTH / 2.6),    130+25*i, ALLEGRO_ALIGN_CENTRE, "%d",pg[i].ID);
//                            al_draw_textf(font, al_map_rgb(0, 0, 0), (WIDTH / 2.6)+75, 130+25*i, ALLEGRO_ALIGN_CENTRE, "|");
//                            al_draw_textf(font, al_map_rgb(0, 0, 0), (WIDTH / 2.6)+150,130+25*i, ALLEGRO_ALIGN_CENTRE, "%d",pg[i].Math);
//                            al_draw_textf(font, al_map_rgb(0, 0, 0), (WIDTH / 2.6)+225,130+25*i, ALLEGRO_ALIGN_CENTRE, "|");
//                            al_draw_textf(font, al_map_rgb(0, 0, 0), (WIDTH / 2.6)+300,130+25*i, ALLEGRO_ALIGN_CENTRE, "%d",pg[i].English);
//                            al_draw_textf(font, al_map_rgb(0, 0, 0), (WIDTH / 2.6)+375,130+25*i, ALLEGRO_ALIGN_CENTRE, "|");
//                            al_draw_textf(font, al_map_rgb(0, 0, 0), (WIDTH / 2.6)+450,130+25*i, ALLEGRO_ALIGN_CENTRE, "%d",pg[i].Science);
//
//                        }
//
//                    }
//                    // 檢查用戶是否點擊了“平均跟標準差”按鈕
//                    if (x>=class_avg_SD_button->X&&x<=class_avg_SD_button->X+class_avg_SD_button->W&&y>=class_avg_SD_button->Y&& y<=class_avg_SD_button->Y+class_avg_SD_button->H&&not_click_rank)
//                    // 顯示平均跟標準差菜單
//                    {
//                        float allarray[7];
//                        al_draw_textf(font, al_map_rgb(0, 0, 0),(WIDTH / 2), 250,      ALLEGRO_ALIGN_CENTRE, "Average_Math :");
//                        al_draw_textf(font, al_map_rgb(0, 0, 0),(WIDTH / 2), 250+50*1, ALLEGRO_ALIGN_CENTRE, "Average_English :");
//                        al_draw_textf(font, al_map_rgb(0, 0, 0),(WIDTH / 2), 250+50*2, ALLEGRO_ALIGN_CENTRE, "Average_Science :");
//                        al_draw_textf(font, al_map_rgb(0, 0, 0),(WIDTH / 2), 250+50*3, ALLEGRO_ALIGN_CENTRE, "Average_Total :");
//                        al_draw_textf(font, al_map_rgb(0, 0, 0),(WIDTH / 2), 250+50*4, ALLEGRO_ALIGN_CENTRE, "SD_Math :");
//                        al_draw_textf(font, al_map_rgb(0, 0, 0),(WIDTH / 2), 250+50*5, ALLEGRO_ALIGN_CENTRE, "SD_English :");
//                        al_draw_textf(font, al_map_rgb(0, 0, 0),(WIDTH / 2), 250+50*6, ALLEGRO_ALIGN_CENTRE, "SD_Science :");
//                        al_draw_textf(font, al_map_rgb(0, 0, 0),(WIDTH / 2), 250+50*7, ALLEGRO_ALIGN_CENTRE, "SD_Total :");
//                        for(int i=0 ; i<=7; i++)
//                        {
//                            allarray[i]=Class_avg_and_SD(pg,i);
//                            al_draw_textf(font, al_map_rgb(0, 0, 0),(WIDTH / 2)+120, 250+50*i, ALLEGRO_ALIGN_CENTRE, "%.2f",allarray[i]);
//                        }
//                    }
//                    // 檢查用戶是否點擊了“排名”按鈕
//                    if (x >= rank_button->X && x <=rank_button->X+rank_button->W &&y >=  rank_button->Y && y <=rank_button->Y+rank_button->H&&not_click_rank)
//                    {
//                        not_click_rank = false;
//                        al_clear_to_color(al_map_rgb(0, 0, 0));
//                        al_draw_bitmap(avgsd, 0, 0, 0);
//                        //al_get_next_event(event_queue2, &event2);
//                        al_flip_display();
//                        printf("j");
//                        goto again;
//                    }
//                    //繪製math,science,english,total選項
//                    if (x >= math_button->X && x <= math_button->X+ math_button->W && y >= math_button->Y && y <= math_button->Y+math_button->H&&!not_click_rank)
//                    {
//                        for(int i = 0; i<30 ; i++)
//                        {
//                            if  (pg[i].Math>=90)
//                            {
//                                al_draw_textf(font, al_map_rgb(0, 0, 0), WIDTH / 2,100+26*i, ALLEGRO_ALIGN_CENTRE, "ID :  %d       Ranking : A",i+1);
//                            }
//                            else if  (pg[i].Math && pg[i].Math>=80)
//                            {
//                                al_draw_textf(font, al_map_rgb(0, 0, 0), WIDTH / 2,100+26*i, ALLEGRO_ALIGN_CENTRE, "ID :  %d       Ranking : B",i+1);
//                            }
//                            else if  (pg[i].Math && pg[i].Math>=70)
//                            {
//                                al_draw_textf(font, al_map_rgb(0, 0, 0), WIDTH / 2,100+26*i, ALLEGRO_ALIGN_CENTRE, "ID :  %d       Ranking : C",i+1);
//                            }
//                            else if  (pg[i].Math && pg[i].Math>=60)
//                            {
//                                al_draw_textf(font, al_map_rgb(0, 0, 0), WIDTH / 2,100+26*i, ALLEGRO_ALIGN_CENTRE, "ID :  %d       Ranking : D",i+1);
//                            }
//                            else if  (pg[i].Math<60)
//                            {
//                                al_draw_textf(font, al_map_rgb(0, 0, 0), WIDTH / 2,100+26*i, ALLEGRO_ALIGN_CENTRE, "ID :  %d       Ranking : E",i+1);
//                            }
//                        }
//                    }
//                    if (x >= sci_button->X && x <= sci_button->X+sci_button->W && y >= sci_button->Y && y <= sci_button->Y + sci_button->H&&!not_click_rank)
//                    {
//                        for(int i = 0; i<30 ; i++)
//                        {
//                            if  (pg[i].Science>=90)
//                            {
//                                al_draw_textf(font, al_map_rgb(0, 0, 0), WIDTH / 2,100+26*i, ALLEGRO_ALIGN_CENTRE, "ID :  %d       Ranking : A",i+1);
//                            }
//                            else if  (pg[i].Science && pg[i].Science>=80)
//                            {
//                                al_draw_textf(font, al_map_rgb(0, 0, 0), WIDTH / 2,100+26*i, ALLEGRO_ALIGN_CENTRE, "ID :  %d       Ranking : B",i+1);
//                            }
//                            else if  (pg[i].Science && pg[i].Science>=70)
//                            {
//                                al_draw_textf(font, al_map_rgb(0, 0, 0), WIDTH / 2,100+26*i, ALLEGRO_ALIGN_CENTRE, "ID :  %d       Ranking : C",i+1);
//                            }
//                            else if  (pg[i].Science && pg[i].Science>=60)
//                            {
//                                al_draw_textf(font, al_map_rgb(0, 0, 0), WIDTH / 2,100+26*i, ALLEGRO_ALIGN_CENTRE, "ID :  %d       Ranking : D",i+1);
//                            }
//                            else if  (pg[i].Science<60)
//                            {
//                                al_draw_textf(font, al_map_rgb(0, 0, 0), WIDTH / 2,100+26*i, ALLEGRO_ALIGN_CENTRE, "ID :  %d       Ranking : E",i+1);
//                            }
//                        }
//                    }
//                    if (x >= eng_button->X  && x <= eng_button->X+eng_button->W && y >= eng_button->Y && y <= eng_button->Y+eng_button->H&&!not_click_rank)
//                    {
//                        for(int i = 0; i<30 ; i++)
//                        {
//                            if  (pg[i].English>=90)
//                            {
//                                al_draw_textf(font, al_map_rgb(0, 0, 0), WIDTH / 2,100+26*i, ALLEGRO_ALIGN_CENTRE, "ID :  %d       Ranking : A",i+1);
//                            }
//                            else if  (pg[i].English && pg[i].English>=80)
//                            {
//                                al_draw_textf(font, al_map_rgb(0, 0, 0), WIDTH / 2,100+26*i, ALLEGRO_ALIGN_CENTRE, "ID :  %d       Ranking : B",i+1);
//                            }
//                            else if  (pg[i].English && pg[i].English>=70)
//                            {
//                                al_draw_textf(font, al_map_rgb(0, 0, 0), WIDTH / 2,100+26*i, ALLEGRO_ALIGN_CENTRE, "ID :  %d       Ranking : C",i+1);
//                            }
//                            else if  (pg[i].English && pg[i].English>=60)
//                            {
//                                al_draw_textf(font, al_map_rgb(0, 0, 0), WIDTH / 2,100+26*i, ALLEGRO_ALIGN_CENTRE, "ID :  %d       Ranking : D",i+1);
//                            }
//                            else if  (pg[i].English<60)
//                            {
//                                al_draw_textf(font, al_map_rgb(0, 0, 0), WIDTH / 2,100+26*i, ALLEGRO_ALIGN_CENTRE, "ID :  %d       Ranking : E",i+1);
//                            }
//                        }
//                    }
//                    if (x >= total_button->X && x <=  total_button->X + total_button->W  && y >=  total_button->Y && y <=  total_button->Y+ total_button->H&&!not_click_rank)
//                    {
//                        for(int i = 0; i<30 ; i++)
//                        {
//                            if  ((pg[i].Math+pg[i].Science+pg[i].English)/3>=90)
//                            {
//                                al_draw_textf(font, al_map_rgb(0, 0, 0), WIDTH / 2,100+26*i, ALLEGRO_ALIGN_CENTRE, "ID :  %d       Ranking : A",i+1);
//                            }
//                            else if  ((pg[i].Math+pg[i].Science+pg[i].English)/3 && (pg[i].Math+pg[i].Science+pg[i].English)/3 >=80)
//                            {
//                                al_draw_textf(font, al_map_rgb(0, 0, 0), WIDTH / 2,100+26*i, ALLEGRO_ALIGN_CENTRE, "ID :  %d       Ranking : B",i+1);
//                            }
//                            else if  ((pg[i].Math+pg[i].Science+pg[i].English)/3 && (pg[i].Math+pg[i].Science+pg[i].English)/3 >=70)
//                            {
//                                al_draw_textf(font, al_map_rgb(0, 0, 0), WIDTH / 2,100+26*i, ALLEGRO_ALIGN_CENTRE, "ID :  %d       Ranking : C",i+1);
//                            }
//                            else if  ((pg[i].Math+pg[i].Science+pg[i].English)/3 && (pg[i].Math+pg[i].Science+pg[i].English)/3 >=60)
//                            {
//                                al_draw_textf(font, al_map_rgb(0, 0, 0), WIDTH / 2,100+26*i, ALLEGRO_ALIGN_CENTRE, "ID :  %d       Ranking : D",i+1);
//                            }
//                            else if  ((pg[i].Math+pg[i].Science+pg[i].English)/3 <60)
//                            {
//                                al_draw_textf(font, al_map_rgb(0, 0, 0), WIDTH / 2,100+26*i, ALLEGRO_ALIGN_CENTRE, "ID :  %d       Ranking : E",i+1);
//                            }
//                        }
//                    }
//                    if (x >=  new_data_button->X && x <=  new_data_button->X+ new_data_button->W  && y >=  new_data_button->Y && y <=  new_data_button->Y+ new_data_button->H&&not_click_rank)
//                    {
//                        generate_new_data(pg);
//                        writetxt(&grade);
//                       al_draw_textf(font, al_map_rgb(0, 0, 0), (WIDTH / 2.6),    100, ALLEGRO_ALIGN_CENTRE, "ID");
//                        al_draw_textf(font, al_map_rgb(0, 0, 0), (WIDTH / 2.6)+75, 100, ALLEGRO_ALIGN_CENTRE, "|");
//                        al_draw_textf(font, al_map_rgb(0, 0, 0), (WIDTH / 2.6)+150,100, ALLEGRO_ALIGN_CENTRE, "Math");
//                        al_draw_textf(font, al_map_rgb(0, 0, 0), (WIDTH / 2.6)+225,100, ALLEGRO_ALIGN_CENTRE, "|");
//                        al_draw_textf(font, al_map_rgb(0, 0, 0), (WIDTH / 2.6)+300,100, ALLEGRO_ALIGN_CENTRE, "English");
//                        al_draw_textf(font, al_map_rgb(0, 0, 0), (WIDTH / 2.6)+375,100, ALLEGRO_ALIGN_CENTRE, "|");
//                        al_draw_textf(font, al_map_rgb(0, 0, 0), (WIDTH / 2.6)+450,100, ALLEGRO_ALIGN_CENTRE, "Science");
//                        al_draw_textf(font, al_map_rgb(0, 0, 0), (WIDTH / 2)+10,   115, ALLEGRO_ALIGN_CENTRE, FRAME_LINE);
//                        for (int i = 0; i<30; i++)
//                        {
//                            al_draw_textf(font, al_map_rgb(0, 0, 0), (WIDTH / 2.6),    130+25*i, ALLEGRO_ALIGN_CENTRE, "%d",pg[i].ID);
//                            al_draw_textf(font, al_map_rgb(0, 0, 0), (WIDTH / 2.6)+75, 130+25*i, ALLEGRO_ALIGN_CENTRE, "|");
//                            al_draw_textf(font, al_map_rgb(0, 0, 0), (WIDTH / 2.6)+150,130+25*i, ALLEGRO_ALIGN_CENTRE, "%d",pg[i].Math);
//                            al_draw_textf(font, al_map_rgb(0, 0, 0), (WIDTH / 2.6)+225,130+25*i, ALLEGRO_ALIGN_CENTRE, "|");
//                            al_draw_textf(font, al_map_rgb(0, 0, 0), (WIDTH / 2.6)+300,130+25*i, ALLEGRO_ALIGN_CENTRE, "%d",pg[i].English);
//                            al_draw_textf(font, al_map_rgb(0, 0, 0), (WIDTH / 2.6)+375,130+25*i, ALLEGRO_ALIGN_CENTRE, "|");
//                            al_draw_textf(font, al_map_rgb(0, 0, 0), (WIDTH / 2.6)+450,130+25*i, ALLEGRO_ALIGN_CENTRE, "%d",pg[i].Science);
//
//                        }
//                    }
//                    if (x >= exit_button->X && x <= exit_button->X+exit_button->W  && y >= exit_button->Y && y <= exit_button->Y+exit_button->H&&not_click_rank)
//                    {
//
//                        exit_pg(menu,avgsd,start_screen,start,on_button,font,display,event_queue);
//                    }
//                    if (x >= exit_button2->X && x <= exit_button2->X+exit_button2->W  && y >= exit_button2->Y && y <= exit_button2->Y+exit_button2->H&&!not_click_rank)
//                    {
//                        not_click_rank=true;
//                        redraw = true;
//                        al_clear_to_color(al_map_rgb(0,0,0));
//                        al_draw_bitmap(menu, 0, 0, 0);
//                        al_flip_display();
//                        break;
//                    }
//                    // 跳出遊戲循環
//                    if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
//                    {
//                        redraw = true;
//                        break;
//                    }
//                }
//            }
//            al_flip_display();
//        }
//    }
//}
