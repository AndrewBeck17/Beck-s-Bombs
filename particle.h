//Part 2
/*B) Particle class person needs to implement the physics method such that
  when moveParticles (or whatever you want to call it) is called, it will update
  the position of the particle based on its velocity. You can also add
  acceleration changing velocity or gravity if you want. */

//ANDREW BECK
#pragma once
#include "/public/colors.h"
#include "particleGraphic.h"
#include <iostream>

//fixed some typos
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
    void physics() {
        switch(type) {
            case MovementType::STREAMER:
                x = x + dx;
                y = y + dy;
                break;
            case MovementType::BALLISTIC:
                x = x + dx;
                y = y + dy;
                dy = dy - 1;
                break;
            case MovementType::FIREWORK:
                x = x + dx;
                y = y + dy;
                if (lifetime == 0) {
					explode();
                }
                break;
        }
        lifetime--;
    }

    //stubbed out draw function
    void draw(int r, int g, int b, char look) {
		ParticleGraphics point(r,g,b);
		point.drawPoint(x,y,look);
	}

    //stubbed out explode function
	void explode(){}
	

};
