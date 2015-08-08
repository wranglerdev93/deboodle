#pragma once


namespace Wrangler {


	class FpsLimiter
	{
		public:
			FpsLimiter();

			void init(float maxFPS);
			void begin();
			
			//returns the fps
			float end();

			void setMaxFPS(float maxFPS);
		private:
			float _maxFPS;
			float _fps;
			float _frameTime;
			unsigned int _startTicks;

			


			void calculateFPS();
	};
}
