#pragma once
#include "ParticleSystem.h"
#include "particle.h"
#include "cell.h"
#include "particleGraphic.h"
#include "explode.h"
#include <iostream>
#include <cstdlib>
#include <ctime>




void becks_bomb() {
	int frames = 60;
	int fps = 120;
	ParticleSystem bomb;
	ParticleGraphics graphics(255,0,0);
	//gets screen ready for particle graphic
	clearscreen();
	show_cursor(false);

	//bomb casing particles
	//note: exist for 23 frames
	bomb.addParticle(Particle(77, 0, 0, -0.25, frames-3, MovementType::BALLISTIC));
	bomb.addParticle(Particle(78, 0, 0, -0.25, frames-3, MovementType::BALLISTIC));
	bomb.addParticle(Particle(79, 0, 0, -0.25, frames-3, MovementType::BALLISTIC));
	bomb.addParticle(Particle(77, 1, 0, -0.25, frames-2, MovementType::BALLISTIC));
	bomb.addParticle(Particle(78, 1, 0, -0.25, frames-2, MovementType::BALLISTIC));
	bomb.addParticle(Particle(79, 1, 0, -0.25, frames-2, MovementType::BALLISTIC));
	bomb.addParticle(Particle(77, 2, 0, -0.25, frames-1, MovementType::BALLISTIC));
	bomb.addParticle(Particle(78, 2, 0, -0.25, frames-1, MovementType::BALLISTIC));
	bomb.addParticle(Particle(79, 2, 0, -0.25, frames-1, MovementType::BALLISTIC));
	bomb.addParticle(Particle(77, 3, 0, -0.25, frames, MovementType::BALLISTIC));
	bomb.addParticle(Particle(78, 3, 0, -0.25, frames, MovementType::BALLISTIC));
	bomb.addParticle(Particle(79, 3, 0, -0.25, frames, MovementType::BALLISTIC));

	//updates screen rapidly for appearance of movement
	for (int j = 0; j < frames; j++) {
		bomb.updateDrawParticle();
		bomb.drawParticles('o',255,255,255,0,0,0,fps);
		graphics.drawRectangle(0,90,157,2,' ');
		if (j == 23) {
			//adds firework particles when the bomb hits the ground to simulate explosion
			bomb.addParticle(Particle(77, 88, 0, 0, 21, MovementType::FIREWORK));
			bomb.addParticle(Particle(78, 88, 0, 0, 21, MovementType::FIREWORK));
			bomb.addParticle(Particle(79, 88, 0, 0, 21, MovementType::FIREWORK));
			bomb.addParticle(Particle(76, 87, 0, 0, 21, MovementType::FIREWORK));
			bomb.addParticle(Particle(80, 86, 0, 0, 21, MovementType::FIREWORK));
		}
	}

	//resets screen for future inputs
	clearscreen();
	show_cursor(true);

	cout << "Code is working" << endl;
}
