#pragma once
#include "glTexture.h"
#include <map>
#include <string>
#include <iostream>

namespace Wrangler {
	class TextureCache
	{
		public:
			TextureCache ();
			virtual ~TextureCache ();

			GLTexture getTexture(std::string texturePath);
		private:
			std::map<std::string, GLTexture> _textureMap;
	};

}
