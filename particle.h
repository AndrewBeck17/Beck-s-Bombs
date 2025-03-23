//Part 2
/*B) Particle class person needs to implement the physics method such that
  when moveParticles (or whatever you want to call it) is called, it will update
  the position of the particle based on its velocity. You can also add
  acceleration changing velocity or gravity if you want. */

//ANDREW BECK
#pragma once
#include "/public/colors.h"
#include "particleGraphic.h"
//#include "ParticleSystem.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

class ParticleSystem; //forward declaration (circular dependencies)

enum class MovementType { STREAMER, BALLISTIC, FIREWORK };

struct Particle {
    //member variables
    double x, y; //position
    double dx, dy; //velocity
    int lifetime; //lifetime (# of frames)
    MovementType type; //type of movement

    //6 parameter constructor
    Particle(double new_x, double new_y, double new_dx, double new_dy, int new_lifetime, MovementType new_type): x(new_x), y(new_y), dx(new_dx), dy(new_dy), lifetime(new_lifetime), type(new_type){
        if (x < 0) exit(EXIT_FAILURE);
        if (y < 0) exit(EXIT_FAILURE);
        if (lifetime < 0) exit(EXIT_FAILURE);
    }

    //updates position per unit lifetime to particle type {STREAMER, BALLISTIC, FIREWORK}
    void physics(ParticleSystem& system) {
        switch(type) {
            case MovementType::STREAMER:
                x = x + dx;
                y = y - dy;
                break;
            case MovementType::BALLISTIC:
                x = x + dx;
                y = y - dy;
                dy = dy - 0.25; //simulates gravity by subtracting 0.25 y velocity every frame
                break;
            case MovementType::FIREWORK:
                x = x + dx;
                y = y - dy;
                if (lifetime == 20) { //at lifetime 20, the firework explodes
					explode(system);
                }
                break;
        }
        lifetime--;
    }

    //draws point at location (x,y) with color (r,g,b) and a char (looks)
    void draw(int r, int g, int b, char look) {
		ParticleGraphics point(r,g,b);
		point.drawPoint(x,y,look);
	}

    
	//moved to its own file for circular inclusion issues
	void explode(ParticleSystem& system);
};
