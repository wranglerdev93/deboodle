#pragma once

#include <wrangler/SpriteBatch.h>
#include <wrangler/ParticleBatch2D.h>

#include <vector>

namespace Wrangler {

	class ParticleEngine2D
	{
	public:
		ParticleEngine2D();
		~ParticleEngine2D();

		void addParticleBartch(ParticleBatch2D* particleBatch);

		void update(float deltaTime);

		void draw(SpriteBatch* spriteBatch);
	
	private:
		std::vector<ParticleBatch2D*> m_Batches;

	};




}
