#pragma once

#include <SDL2/SDL.h>
#include <GL/glew.h>

#include <GL/gl.h>
#include <string>

namespace Wrangler {
	enum windowFlags {INVISIBLE = 0x1, FULLSCREEN = 0x2, BORDERLESS = 0x4};

	class Window
	{
		public:
			Window();
			~Window();

			int create(std::string windowName, int screenWidth, int screenHeight, unsigned int currentFlags);
			int getScreenWidth() const {return _screenWidth;}
			int getScreenHeight() const {return _screenHeight;}

			void swapBuffer();
		private:
			SDL_Window* _sdlwindow;
			int _screenWidth, _screenHeight;


	};

}
