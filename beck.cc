#pragma once
#include "ParticleSystem.h"
#include "particle.h"
#include "cell.h"
#include "particleGraphic.h"
#include "explode.h"
#include <iostream>
#include <cstdlib>
#include <ctime>




void becks_bomb(int frames) { //determines how many frames the function will be ran for
	srand(time(0));
	ParticleSystem ps;
	clearscreen();
	show_cursor(false);


	
	ps.addParticle(Particle(0,20,1,0,frames - 30,MovementType::FIREWORK));
	ps.addParticle(Particle(0,20,1,0,frames - 30,MovementType::FIREWORK));
	ps.addParticle(Particle(0,20,1,0,frames - 30,MovementType::FIREWORK));
	ps.addParticle(Particle(0,20,1,0,frames - 30,MovementType::FIREWORK));
	ps.addParticle(Particle(0,20,1,0,frames - 30,MovementType::FIREWORK));

	for (int j = 0; j < frames; j++) {
		ps.updateDrawParticle();
		ps.drawParticles();
		cout << endl;
	}


	clearscreen();
	show_cursor(true);

	cout << "Code is working" << endl;
}
