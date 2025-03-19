#include "particleGraphic.h"
#include <iostream>

using namespace std;

//DRAW POINT WORKS
/*
int main() {
	ParticleGraphics point(255, 0, 0);
	point.drawPoint(50, 50, ' ');
	return 0;
}
*/

//DRAW RECTANGLE WORKS
/*
int main() {
	ParticleGraphics point(255, 0, 0);
	point.drawRectangle(50, 50, 10, 10, ' ');
	return 0;
}
*/



#include "particle.h"
#include <iostream>

using namespace std;

int main() {
	Particle point(5, 5, 1, 1, 100, MovementType::BALLISTIC);
	for (int i = 0; i < point.lifetime; i++) {
		point.physics();
		cout << "H";
	}
	return 0;
}

