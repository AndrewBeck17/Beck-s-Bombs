//temp empty
#include "ParticleSystem.h"
#include "particle.h"
#include "cell.h"
#include "particleGraphic.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	srand(time(0));
	ParticleSystem ps;
	int lifetime = 100;
	clearscreen();
	show_cursor(false);

	for (int i = 0; i < 10; i++) {
		ps.addParticle(Particle(50, 30, (rand() % 2 == 0) ? 2 : -2, (rand() % 2 == 0) ? 2 : -2, lifetime, MovementType::BALLISTIC));
	}

	for (int j = 0; j < 100 ; j++) {
		ps.updateDrawParticle();
		ps.drawParticles();
		cout << endl;
	}


	clearscreen();
	show_cursor(true);

	cout << "Code is working" << endl;

	return 0;
}
