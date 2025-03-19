#include <iostream>
#include "particle.h"
#include "cell.h"
#include "/public/colors.h"
using namespace std;
class ParticleSystem {
    private:
        Cell* head;
    public:
        ParticleSystem() : head(nullptr) {}
        ~ParticleSystem() {
        Cell* curr = head;
        while (curr != nullptr) {
            Cell* next = curr->next;
            delete curr;
            curr = next;
        }
    }
        void addParticle(const Particle& particle) {
            Cell* newP = new Cell(particle);
            newP->next = head;
            head = newP;
        }

        void updateDrawParticle() {
            Cell* curr = head;
            Cell* prev = nullptr;
            while (curr != nullptr) {
                auto [rows,cols] = get_terminal_size();
                curr->particle.x += curr->particle.dx;
                curr->particle.y += curr->particle.dy;
                curr->particle.lifetime--;

                if (curr->particle.x < 0) {
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
                else if (curr->particle.y < 0) {
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
                else if (curr->particle.x >= cols) {
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
                else if (curr->particle.y >= rows) {
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

                else if (curr->particle.lifetime <= 0) {
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

        void drawParticles() {
            Cell* curr = head;
            while (curr != nullptr) {
                movecursor(curr->particle.y, curr->particle.x);
                cout << "O";
                cout.flush();
                usleep(1'000'000 / 120);
                if (curr->next == nullptr) clearscreen();
                curr = curr->next;
            }
        }
};

