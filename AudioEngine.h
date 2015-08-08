#pragma once

#include <SDL2/SDL_mixer.h>
#include <string>
#include <map>

namespace Wrangler {

	class SoundEffect
	{
	public:
		//Audio engine can use private variables
		friend class AudioEngine;

		void play(int loops = 0);
	private:
		Mix_Chunk* m_chunk = nullptr;
	};

	class Music
	{
		friend class AudioEngine;
		public:
			//@param loop: if loops == -1, loops forever
			// otherwise loops + 1 times
			void play(int loops = 0);

			//These apply to currently playing
			static void pause();
			static void stop();
			static void resume();
		private:
			Mix_Music* m_music = nullptr;
	};


	class AudioEngine
	{
	public:
		AudioEngine ();
		~AudioEngine ();

		void init();
		void destroy();

		SoundEffect loadSoundEffect(const std::string& filePath);
		Music loadMusic(const std::string& filePath);
	
	private:
		//Caches for music
		std::map<std::string, Mix_Chunk*> m_effectMap;
		//Cache for effects
		std::map<std::string, Mix_Music*> m_musicMap;
		bool m_isInitialized = false;
	};
}
