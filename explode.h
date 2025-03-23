#pragma once
#include "particle.h"
#include "ParticleSystem.h"

//added in seperate file because of circular inclusion problems
void Particle::explode(ParticleSystem& system) {
	if (type != MovementType::FIREWORK || lifetime > 20) { //safeguard
		return; 
	}
	int numParticles = 5 + (rand() % 6); //generates between 5-10 new particles in explosion
	int velocity = (rand() % 3) + 1; //chooses generalized velocity (1-3) for both x and y direction
	float angle_per = 360.0 / numParticles; //angle between each particle around explosion radius
	float accumulated_angle = 0; //tracks how far around circle we have been
	for (int i = 0; i < numParticles; i++) {
		//uses trig functions to choose direction of particle
		float new_dx = cos(angle_per + accumulated_angle) * velocity;
		float new_dy = sin(angle_per + accumulated_angle) * velocity;

		accumulated_angle += angle_per; //adds to accumulated

		//creates new particle for explosion with a lifetime of 15 - 20 frames then adds it to system
		Particle newParticle(x,y,new_dx,new_dy,(15 + rand() % 5),MovementType::STREAMER);
		system.addParticle(newParticle);
	}
}
