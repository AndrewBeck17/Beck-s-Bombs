//Part 1
/*D) A ParticleGraphics class that can change the color 
  being drawn (private member variable with getter/setter) 
  and methods for drawing a point, a rectangle, an oval, 
  a polygon, and a line. The constructor/getter/setter should 
  be written now, the other methods should be stubbed out. */

//Andrew Beck

#include "die.h"

class ParticleGraphics {
	private:
		//memeber variables red, green, blue
		int r, g, b;
	public:
		//constructor
		ParticleGraphics(int new_r, int new_g, int new_b) : r(new_r), g(new_g), b(new_g) {
			if (new_r < 0 || new_g < 0 || new_b < 0) die();
		}

		//get red green or blue values
		int get_r const() {
			return r;
		}
		int get_g const() {
			return g;
		}
		int get_b const() {
			return b;
		}

		//set red green or blue values
		void set_r (int new_r) {
			if (new_r < 0) die();
			else r = new_r;
		}
		void set_g (int new_g) {
			if (new_g < 0) die();
			else g = new_g;
		}
		void set_b (int new_b) {
			if (new_b < 0) die();
			else b = new_b;
		}

		//stubbed out...
		void drawPoint();
		void drawRectangle();
		void drawOval();
		void drawPolygon();
		void drawLine();
};
