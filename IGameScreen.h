#pragma once

#define SCREEN_INDEX_NO_SCREEN -1

namespace Wrangler {

	
	enum class ScreenState {
		NONE,
		RUNNING,
		EXIT_APPLICATION,
		CHANGE_NEXT,
		CHANGE_PREVIOUS
	};
	class IMainGame;
	class IGameScreen {

		public:
			friend class ScreenList;
			IGameScreen()
			{

			}

			virtual ~IGameScreen()
			{

			}

			//returns index of next or previous screen when changing
			virtual int getNextScreenIndex() const = 0;
			virtual int getPreviousScreenIndex() const = 0;

			//called at beginning and end of application
			virtual void build() = 0;
			virtual void destroy() = 0;

			//called when screen enters and exits focus
			virtual void onEntry() = 0;
			virtual void onExit() = 0;

			//called in main game loop
			virtual void update() = 0;
			virtual void draw() = 0;

			void setRunning() {
				m_currentState = ScreenState::RUNNING;
			}

			int getScreenIndex() const  { return m_screenIndex; }
			ScreenState getState() const { return m_currentState; }

			void setParentGame(IMainGame* game) { m_game = game; }
			

		protected:
			ScreenState m_currentState = ScreenState::NONE;
			IMainGame* m_game = nullptr;
			int m_screenIndex = -1;

	};






}
