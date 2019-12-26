#pragma once
#include <iostream>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Player.h"
#include "Utils.h"

namespace Snake {

	class Game
	{
	public:
		Game() {};
		~Game() {};

		void init();
		void render();
		void update();
		void handleEvents();
		void clean();

		bool isRunning() { return is_running; }

	private:

		SDL_Window* window = nullptr; //set window to a nullptr
		SDL_Renderer* renderer = nullptr; //set renderer to a nullptr

		Player* player = nullptr; //set player to nullptr

		int screen_w = 0; //screen width 0
		int screen_h = 0; //initial screen height 0

		bool is_running = false;

	};
};

