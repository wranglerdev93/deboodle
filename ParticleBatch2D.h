#pragma once
#include <glm/glm.hpp>

#include <functional>
#include "glTexture.h"
#include "SpriteBatch.h"
#include "Vertex.h"
namespace Wrangler {

	

	class Particle2D
	{
		public:
			glm::vec2 position = glm::vec2(0.0f);
			glm::vec2 velocity = glm::vec2(0.0f);
			Wrangler::ColorRGBA8 color;
			float life = 0.0f;
			float width = 0.0f;
	};

	inline void defaultParticleUpdate(Particle2D& particle, float deltaTime)
	{
		particle.position += particle.velocity * deltaTime;
	}

	class ParticleBatch2D
	{
		public:
			ParticleBatch2D();
			~ParticleBatch2D();

			void init(int maxParticles, float decayRate, GLTexture texture, std::function<void(Particle2D&, float)> updateFunc = defaultParticleUpdate);

			void update(float deltaTime);

			void draw(SpriteBatch* spriteBatch);

			//will find particle in myParticles that is inactive, and make active
			void addParticle(const glm::vec2& position, const glm::vec2 velocity, const ColorRGBA8& color, float width);

		private:
			int findFreeParticle();
			float m_decayRate = 0.1f;
			std::function<void(Particle2D&, float)> m_updateFunc;	
			//Big buffer of particles
			Particle2D* m_Particles = nullptr;
			int m_maxParticles = 0;
			int m_lastFreeParticle = 0;
			GLTexture m_texture;
	};



}
