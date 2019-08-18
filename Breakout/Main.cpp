#include "ATimer.h"
#include "ADisplay.h"
#include "AEventQueue.h"
#include "allegro5/allegro_primitives.h"
#include "Square.h"
#include "Util.h"
#include "SMPlayer.h"

int main(int argn, char** argv)
{
	bool continue_to_play = true;
	bool draw = false;

	// Initialize the basics objects of Allegro
	Validate::object_was_initialized(al_init(), "Allegro");
	Validate::object_was_initialized(al_install_keyboard(), "Keyboard");
	Validate::object_was_initialized(al_init_primitives_addon(), "Primitives Addon");

	// Initialize the object of Allegro that had been encapsulated
	std::unique_ptr<ATimer> UPATimer = std::make_unique<ATimer>(1.0 / 14);
	std::unique_ptr<ADisplay> UPADisplay = std::make_unique<ADisplay>();
	std::unique_ptr<AEventQueue> UPAEventQueue = std::make_unique<AEventQueue>();

	// add source to event queue
	al_register_event_source(UPAEventQueue->getEventQueue(), al_get_keyboard_event_source());
	al_register_event_source(UPAEventQueue->getEventQueue(), al_get_timer_event_source(UPATimer->getTimer()));
	al_register_event_source(UPAEventQueue->getEventQueue(), al_get_display_event_source(UPADisplay->getDisplay()));

	// color
	std::shared_ptr<ALLEGRO_COLOR> SPACBlack = std::make_shared<ALLEGRO_COLOR>(al_map_rgba_f(0, 0, 0, 0));
	std::shared_ptr<ALLEGRO_COLOR> SPACWhite = std::make_shared<ALLEGRO_COLOR>(al_map_rgba_f(1, 1, 1, 1));
	std::shared_ptr<ALLEGRO_COLOR> SPACDarkGrey = std::make_shared<ALLEGRO_COLOR>(al_map_rgba_f(0.66, 0.66, 0.66, 1));

	std::unique_ptr<Square> UPSUpperLimit = std::make_unique<Square>(0, 0, Constant::SCREEN_WIDTH, Constant::BLOCK_WIDTH, SPACDarkGrey);
	std::unique_ptr<Square> UPSLeftLimit = std::make_unique<Square>(0, 0, Constant::BLOCK_WIDTH, Constant::SCREEN_HEIGHT, SPACDarkGrey);
	std::unique_ptr<Square> UPSRightLimit = std::make_unique<Square>(Constant::SCREEN_WIDTH - Constant::BLOCK_WIDTH, 0, Constant::BLOCK_WIDTH, Constant::SCREEN_HEIGHT, SPACDarkGrey);
	std::unique_ptr<SMPlayer> UPSPlayer = std::make_unique<SMPlayer>(SPACWhite);

	//captures the current event
	ALLEGRO_EVENT event;
	
	//user input
	unsigned char key[ALLEGRO_KEY_MAX];
	memset(key, 0, sizeof(key));

	UPATimer->startTimer();
	while (continue_to_play)
	{
		al_wait_for_event(UPAEventQueue->getEventQueue(), &event);

		switch (event.type)
		{
			case ALLEGRO_EVENT_TIMER:
				// exit game
				if (key[ALLEGRO_KEY_ESCAPE])
				{
					continue_to_play = false;
				}

				// Reset array of keys
				Util::reset_array_of_keys(key);

				draw = true;
				break;
			case ALLEGRO_EVENT_KEY_DOWN:
				key[event.keyboard.keycode] = Constant::KEY_SEEN | Constant::KEY_RELEASED;
				break;
			case ALLEGRO_EVENT_KEY_UP:
				key[event.keyboard.keycode] &= Constant::KEY_RELEASED;
				break;
			case ALLEGRO_EVENT_DISPLAY_CLOSE:
				continue_to_play = false;
				break;
			default:
				break;
		}

		if (draw && al_is_event_queue_empty(UPAEventQueue->getEventQueue()))
		{
			draw = false;
			al_clear_to_color(*SPACBlack);
			UPSUpperLimit->draw();
			UPSLeftLimit->draw();
			UPSRightLimit->draw();
			UPSPlayer->draw();
			al_flip_display();
		}
	}
	return 0;
}