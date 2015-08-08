#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Wrangler {

	class Camera2D
	{
		public:
			Camera2D ();
			~Camera2D ();

			void init(int screenWidth, int screenHeight);

			void update();

			glm::vec2 convertScreenToWorld(glm::vec2 screenCoords);
			void setPosition(const glm::vec2& newPosition)
			{
				_position = newPosition;
				_needsMatrixUpdate = true;
			}

			bool isBoxInView(const glm::vec2& position, const glm::vec2 dimensions);
			void setScale( float newScale) {_scale = newScale; _needsMatrixUpdate = true;}

			float getScale() { return _scale; }
			glm::vec2 getPosition() const { return _position; }
			glm::mat4 getCameraMatrix() const { return _cameraMatrix; }

		private:
			glm::vec2 _position;
			glm::mat4 _cameraMatrix;
			float _scale;
			bool _needsMatrixUpdate;
			int _screenWidth, _screenHeight;
			glm::mat4 _orthoMatrix;

	};

}
