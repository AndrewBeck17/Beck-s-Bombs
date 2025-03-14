//#include "particle.h"

class ParticleSystem {
	public:
		void add(Particle particle);
		int numParticles() const;
		void drawParticles() const;
		void moveParticles();

};
