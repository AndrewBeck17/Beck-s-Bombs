//Part 1
/*D) A ParticleGraphics class that can change the color 
  being drawn (private member variable with getter/setter) 
  and methods for drawing a point, a rectangle, an oval, 
  a polygon, and a line. The constructor/getter/setter should 
  be written now, the other methods should be stubbed out. */

//Part 2
/*D) ParticleGraphics needs to have drawPoint(int row, int col)
  implemented so that it will draw a colored block at that point on the screen. 
  Look at the demo code in /public/particle_demo for how to draw a point.*/

//Andrew Beck

#include "/public/colors.h"

void die() {
	exit(EXIT_FAILURE);
}

class ParticleGraphics {
	private:
		//memeber variables red, green, blue
		int r, g, b;
	public:
		//constructor
		ParticleGraphics(int new_r, int new_g, int new_b) : r(new_r), g(new_g), b(new_g) {
			if (new_r < 0 || new_g < 0 || new_b < 0) die();
			if (new_r > 255 || new_g > 255 || new_b > 255) die();
		}

		//get red green or blue values
		int get_r () const {
			return r;
		}
		int get_g () const {
			return g;
		}
		int get_b () const {
			return b;
		}

		//set red green or blue values
		void set_r (int new_r) {
			if (new_r < 0) die();
			else if (new_r > 255) die();
			else r = new_r;
		}
		void set_g (int new_g) {
			if (new_g < 0) die();
			else if (new_g > 255) die();
			else g = new_g;
		}
		void set_b (int new_b) {
			if (new_b < 0) die();
			else if (new_b > 255) die();
			else b = new_b;
		}

		//draws point of (size row * size col)
		void drawPoint(int row, int col) {
			for (int i = 0; i < col; i++) {
				if (i > 0) std::cout << std::endl;
				for (int k = 0; k < row; k++) {
					setbgcolor(r,g,b);
					std::cout << " ";
				}
			}
			resetcolor();
		}

		//stubbed out...
		void drawRectangle();
		void drawOval();
		void drawPolygon();
		void drawLine();
};
