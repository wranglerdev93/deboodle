#pragma once

#include "glTexture.h"

#include <string>
#include <iostream>

namespace Wrangler {

	class ImageLoader
	{
		public:
			static GLTexture loadPNG(std::string filePath);

	};

}
