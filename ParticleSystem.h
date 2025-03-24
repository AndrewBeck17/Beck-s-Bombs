#pragma once
#include <iostream>
#include "particle.h"
#include "cell.h"
#include "/public/colors.h"
using namespace std;
class ParticleSystem {
    private:
        Cell* head;
		int amount = 0;
    public:
        ParticleSystem() : head(nullptr) {} //constructor
        ~ParticleSystem() {
        Cell* curr = head;
        while (curr != nullptr) { //destructor
            Cell* next = curr->next;
            delete curr;
            curr = next;
        }
    }
		int numParticles() { //get number of particles in list
			return amount;
		}

        void addParticle(const Particle& particle) { //add a new particle to the list
            Cell* newP = new Cell(particle);
            newP->next = head;
            head = newP;
			amount++;
        }

        void updateDrawParticle() { //update the screen and draw the particles again
            Cell* curr = head;
            Cell* prev = nullptr;
            while (curr != nullptr) {
                auto [rows,cols] = get_terminal_size();
				curr->particle.physics(*this);	
                if (curr->particle.x < 0) { //delete if particle leaves screen
                    Cell* temp = curr;
                    curr = curr->next;
                    if (prev != nullptr) {
                        prev->next = curr;
                    }
                    else {
                        head = curr;
                    }
                    delete temp;
                }
                else if (curr->particle.y < 0) { //delete if particle leaves screen
                    Cell* temp = curr;
                    curr = curr->next;
                    if (prev != nullptr) {
                        prev->next = curr;
                    }
                    else {
                        head = curr;
                    }
                    delete temp;
                } 
                else if (curr->particle.x >= cols) { //delete if particle leaves screen
                    Cell* temp = curr;
                    curr = curr->next;
                    if (prev != nullptr) {
                        prev->next = curr;
                    }
                    else {
                        head = curr;
                    }
                    delete temp;
                }
                else if (curr->particle.y >= rows) { //delete if partricle leave screen
                    Cell* temp = curr;
                    curr = curr->next;
                    if (prev != nullptr) {
                        prev->next = curr;
                    }
                    else {
                        head = curr;
                    }
                    delete temp;
                }

                else if (curr->particle.lifetime <= 0) { //delete if particle's lifetime ends
                    Cell* temp = curr;
                    if (prev != nullptr) {
                        prev->next = curr->next;
                    }
                    else {
                        head = curr->next;
                    }
                    curr = curr->next;
                    delete temp;
                }
                else {
                    prev = curr;
                    curr = curr->next;
                }

            }
        }

		//changed function to allow inputs for particle look, particle color, and particle background color -- Andrew
        void drawParticles(char look = 'O',int r = 255, int g = 255, int b = 255, int bgr = 0, int bgg = 0, int bgb = 0, int FPS = 120) {
            Cell* curr = head;
            while (curr != nullptr) {
                movecursor(curr->particle.y, curr->particle.x);
				setcolor(r,g,b);
				setbgcolor(bgr,bgg,bgb);
                cout << look;
                cout.flush();
                usleep(1'000'000 / FPS);
                if (curr->next == nullptr) clearscreen();
                curr = curr->next;
            }
        }
};

