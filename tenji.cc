#pragma once
#include "ParticleSystem.h"
#include "particle.h"
#include "cell.h"
#include "particleGraphic.h"
#include "explode.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

//generate random double between -10 and 10
double random_dbl() {
	static mt19937 rng(random_device{}());
	static uniform_int_distribution<int> distrib(-100, 100);
	return distrib(rng) / 10.0;
}

void tenjis_function() {
	//default variables
	srand(time(0));
	int frames = 110;
	int fps = 240;
	ParticleSystem ps;
	clearscreen();
	show_cursor(false);
	int c_dx = 1;
	int c_dy = 0;
	int j = 0;

	//create creeper
	ps.addParticle(Particle(1, 30, c_dx, 0, frames, MovementType::STREAMER));
	ps.addParticle(Particle(1, 31, c_dx, 0, frames, MovementType::STREAMER));
	ps.addParticle(Particle(1, 32, c_dx, 0, frames, MovementType::STREAMER));
	ps.addParticle(Particle(1, 35, c_dx, 0, frames, MovementType::STREAMER));
	ps.addParticle(Particle(1, 36, c_dx, 0, frames, MovementType::STREAMER));
	ps.addParticle(Particle(3, 30, c_dx, 0, frames, MovementType::STREAMER));
	ps.addParticle(Particle(3, 32, c_dx, 0, frames, MovementType::STREAMER));
	ps.addParticle(Particle(3, 33, c_dx, 0, frames, MovementType::STREAMER));
	ps.addParticle(Particle(3, 34, c_dx, 0, frames, MovementType::STREAMER));
	ps.addParticle(Particle(3, 35, c_dx, 0, frames, MovementType::STREAMER));
	ps.addParticle(Particle(5, 30, c_dx, 0, frames, MovementType::STREAMER));
	ps.addParticle(Particle(5, 31, c_dx, 0, frames, MovementType::STREAMER));
	ps.addParticle(Particle(5, 32, c_dx, 0, frames, MovementType::STREAMER));
	ps.addParticle(Particle(5, 35, c_dx, 0, frames, MovementType::STREAMER));
	ps.addParticle(Particle(5, 36, c_dx, 0, frames, MovementType::STREAMER));

	//creeper travels across screen
	for (int i = 0; i < frames; i++) {
		movecursor(29, j);
		cout << "HISSS...";
		j++;
		ps.updateDrawParticle();
		ps.drawParticles('O', 0, 255, 0, 0, 0, 0, fps);
	}
	//creeper explosion particles
	for (int i = 0; i < 20; i++) {
		ps.addParticle(Particle(110, 34, random_dbl(), random_dbl(), frames, MovementType::STREAMER));
	}
	//update screen and draw explosion particles
	for (int i = 0; i < frames; i++) {
		movecursor(34, 110);
		cout << "BOOM";
		ps.updateDrawParticle();
		ps.drawParticles('*', 255, 255, 255, 0, 0, 0, 240);
	}
	clearscreen();
	show_cursor(true);

	cout << "Code is working" << endl;
}
