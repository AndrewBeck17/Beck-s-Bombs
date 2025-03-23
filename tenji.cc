#pragma once
#include "ParticleSystem.h"
#include "particle.h"
#include "cell.h"
#include "particleGraphic.h"
#include "explode.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


//name this whatever you want, and you can move it into and file name you want, I am just putting this in as a placeholder
void tenjis_function () { 
	//your code from main
	srand(time(0));
	int frames = 100;
	ParticleSystem ps;
	clearscreen();
	show_cursor(false);

	
	//your code from main
	for (int i = 0; i < 10; i++) {
		ps.addParticle(Particle(50, 30, (rand() % 2 == 0) ? 2 : -2, (rand() % 2 == 0) ? 2 : -2, frames, MovementType::BALLISTIC));
		}



	//your code from main
	for (int j = 0; j < frames; j++) {
		ps.updateDrawParticle();
		ps.drawParticles();
		cout << endl;
	}

	//your code from main
	clearscreen();
	show_cursor(true);

	//your code from main
	cout << "Code is working" << endl;
}
