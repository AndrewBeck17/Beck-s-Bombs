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
	int frames = 100;
	ParticleSystem bombcase, b, o, m;
	clearscreen();
	show_cursor(false);


	//bomb casing particles
	bombcase.addParticle(Particle(50, 0, 0, -1, frames - 30, MovementType::STREAMER));
	bombcase.addParticle(Particle(50, 1, 0, -1, frames - 30, MovementType::STREAMER));
	bombcase.addParticle(Particle(50, 1, 0, -1, frames - 30, MovementType::STREAMER));
	bombcase.addParticle(Particle(50, 2, 0, -1, frames - 30, MovementType::STREAMER));
	bombcase.addParticle(Particle(50, 3, 0, -1, frames - 30, MovementType::STREAMER));
	bombcase.addParticle(Particle(50, 4, 0, -1, frames - 30, MovementType::STREAMER));
	bombcase.addParticle(Particle(52, 0, 0, -1, frames - 30, MovementType::STREAMER));
	bombcase.addParticle(Particle(52, 1, 0, -1, frames - 30, MovementType::STREAMER));
	bombcase.addParticle(Particle(52, 2, 0, -1, frames - 30, MovementType::STREAMER));
	bombcase.addParticle(Particle(52, 3, 0, -1, frames - 30, MovementType::STREAMER));
	bombcase.addParticle(Particle(52, 4, 0, -1, frames - 30, MovementType::STREAMER));
	bombcase.addParticle(Particle(51, 0, 0, -1, frames - 30, MovementType::STREAMER));
	bombcase.addParticle(Particle(51, 4, 0, -1, frames - 30, MovementType::STREAMER));
	//bomb particles	
	b.addParticle(Particle(51, 1, 0, -1, frames - 30, MovementType::FIREWORK));
	b.addParticle(Particle(51, 1, 0, -1, frames - 30, MovementType::FIREWORK));
	b.addParticle(Particle(51, 1, 0, -1, frames - 30, MovementType::FIREWORK));
	b.addParticle(Particle(51, 1, 0, -1, frames - 30, MovementType::FIREWORK));
	b.addParticle(Particle(51, 1, 0, -1, frames - 30, MovementType::FIREWORK));
	o.addParticle(Particle(51, 2, 0, -1, frames - 30, MovementType::FIREWORK));
	o.addParticle(Particle(51, 2, 0, -1, frames - 30, MovementType::FIREWORK));
	o.addParticle(Particle(51, 2, 0, -1, frames - 30, MovementType::FIREWORK));
	o.addParticle(Particle(51, 2, 0, -1, frames - 30, MovementType::FIREWORK));
	o.addParticle(Particle(51, 2, 0, -1, frames - 30, MovementType::FIREWORK));
	m.addParticle(Particle(51, 3, 0, -1, frames - 30, MovementType::FIREWORK));
	m.addParticle(Particle(51, 3, 0, -1, frames - 30, MovementType::FIREWORK));
	m.addParticle(Particle(51, 3, 0, -1, frames - 30, MovementType::FIREWORK));
	m.addParticle(Particle(51, 3, 0, -1, frames - 30, MovementType::FIREWORK));
	m.addParticle(Particle(51, 3, 0, -1, frames - 30, MovementType::FIREWORK));

	for (int j = 0; j < frames; j++) {
		bombcase.updateDrawParticle();
		bombcase.drawParticles('I',255,255,255,0,0,0);
		b.updateDrawParticle();
		b.drawParticles('B',255,255,255,0,0,0);
		o.updateDrawParticle();
		o.drawParticles('O',255,255,255,0,0,0);
		m.updateDrawParticle();
		m.drawParticles('M',255,255,255,0,0,0);
	}


	clearscreen();
	show_cursor(true);

	cout << "Code is working" << endl;
}
