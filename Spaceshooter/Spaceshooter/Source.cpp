#include<allegro5/allegro.h>
#include<allegro5\allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_acodec.h>
#include<list>

#include"globals.h"


bool keys[] = { false, false, false, false, false };
enum KEYS { UP, DOWN, LEFT, RIGHT, SPACE };

//globals

int main(int argc, char **argv) 
{
	//===============================================
	//SHELL VARIABLES
	//===============================================
	bool done = false;
	bool render = false;
	
	float gameTime = 0;
	int frames = 0;
	int gameFPS = 0;

	//===============================================
	//PROJECT VARIABLES
	//===============================================


	//===============================================
	//ALLEGRO VARIABLES
	//===============================================
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer;
	ALLEGRO_FONT *font18;

	//===============================================
	//ALLEGRO INIT FUNCTIONS
	//===============================================
	if (!al_init())
		return -1;
	display = al_create_display(WIDTH, HEIGHT);

	if (!display)
		return -1;
	//===============================================
	//ADDON INSTALL
	//===============================================
	al_install_keyboard();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();

	//===============================================
	//Project INIT
	//===============================================
	font18 = al_load_font("arial.ttf", 18, 0);
	//===============================================
	//TIMER INIT AND STARTUP
	//===============================================
	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / 60);

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_start_timer(timer);
	gameTime = al_current_time();
	while (!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		//===============================================
		//INPUT
		//===============================================
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = true;
				break;

				//if the down key has been pressed
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = true;
				break;

				//if the left key has been pressed
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				break;

				//if the right key has been pressed
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				break;

			
			case ALLEGRO_KEY_SPACE:
				keys[SPACE] = true;
				break;
	
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = false;
				break;

				//if the down key has been pressed
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = false;
				break;

				//if the left key has been pressed
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = false;
				break;

				//if the right key has been pressed
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = false;
				break;

			case ALLEGRO_KEY_SPACE:
				keys[SPACE] = false;
				break;

			}
		}
		//===============================================
		//GAME UPDATE
		//===============================================
		else if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			render = true;

			//update FPS=============
			frames++;
			if (al_current_time() - gameTime >= 1)
			{
				gameTime = al_current_time();
				gameFPS = frames;
				frames = 0;

			}
			//=======================
		}
		//===============================================
		//RENDA SECTIOINN video 3:37
		//===============================================
		if (render && al_is_event_queue_empty(event_queue))
		{
			render = false;
		//	al_draw_textf(font18, al_map_rgb(255, 0, 255), 5, 5, 0, "FPS: %i", gameFPS);

			//BEGIN PROJECT RENDER=================


			//FLIP BUFFER==========================
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
	}

	//===============================================
	//DESTROY PROJECT OBJECTS
	//===============================================

	//SHELL OBJECTS==================================

	al_destroy_font(font18);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}