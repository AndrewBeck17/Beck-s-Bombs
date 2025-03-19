//ANDREW BECK
#include <iostream>
//fixed some typos
enum class MovementType { STREAMER, BALLISTIC, FIREWORK }; //pre-selected movement types

struct Particle {
	//member variables
	double px, py; //position
	double vx, vy;  //velocity
	int lifetime;  //lifetime (# of frames)
	MovementType type;  //type of movement

	//6 parameter constructor
	Particle (double px, double py, double vx, double vy, int lifetime, MovementType type) : px(px), py(py), vx(vx), vy(vy), lifetime(lifetime), type(type) { 
		if (px < 0) exit(EXIT_FAILURE);
		if (py < 0) exit(EXIT_FAILURE);
		if (lifetime < 0) exit(EXIT_FAILURE);
	}

	//updates position per unit lifetime according to particle type {STREAMER, BALLISTIC, FIREWORK}
	void physics () {
		switch(type) {
			case MovementType::STREAMER:
				px = px + vx; //updates poisition every frame at velocity x
				py = py + vy;
				break;
			case MovementType::BALLISTIC:
				px = px + vx;
				py = py + vy;
				vy = vy - 1; //y velocity increases by -1 every frame to simulate gravitational acceleration
				break;
			case MovementType::FIREWORK:
				px = px + vx;
				py = py + vy;
				if (lifetime == 0) {
					explode(); //same as STREAMER but at lifetime 0 it explodies into multiple streamers
				}
				break;
		}
		lifetime--;
	}

	//stubbed out draw function...
	void draw(); 

	//stubbed out explode function...
	void explode();
};
