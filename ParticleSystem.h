#include "particle.h"
#include "ll.h"

class ParticleSystem {
	private:
		int width = 0;
		int height = 0;
		int amount = 0;

	public:
		ParticleSystem();
		~ParticleSystem();

		void add(Particle particle) {
			LL* newParticle = new LL(particle); //not working
			if (tail != nullptr) {
				tail->set_next(newParticle);
			}
			tail = newParticle;
			if (head == nullptr) {
				head = newParticle;
			}
		}	
		int numParticles() const {
			return amount;
		}
		void drawParticles() const;
		void moveParticles();

};
