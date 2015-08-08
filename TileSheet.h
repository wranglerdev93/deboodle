#pragma once
#include "glTexture.h"
#include <glm/glm.hpp>
//for grids of sprites

namespace Wrangler {
	class TileSheet
	{
		public:
			TileSheet(){};
			~TileSheet (){};

			void init(GLTexture& glTexture, const glm::ivec2& tileDims)
			{
				this->texture = glTexture;
				this->dims = tileDims;
			}

			glm::vec4 getUVs(int index)
			{
				int xTile = index % dims.x;
				int yTile = index / dims.x;

				glm::vec4 uvs;

				uvs.x = xTile / (float)dims.x;
				uvs.y = yTile / (float)dims.y;
				uvs.z = 1.0f / dims.x;
				uvs.w = 1.0f / dims.y;
				return uvs;
			}

			GLTexture texture;
			glm::ivec2 dims;
	};

}
