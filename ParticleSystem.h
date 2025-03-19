#include "particle.h"
#include "cell.h"
#include "/public/colors.h"
#include <iostream>
using namespace std;

class ParticleSystem {
private:
    cell* head;
    cell* tail;

public:
    int FPS = 60;
    int amount = 0;
    ParticleSystem() : head(nullptr), tail(nullptr) {}
    ~ParticleSystem() {
        cell* temp = head;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void add(Particle particle) {
        cell* newcell = new cell(particle);
        if (!head) {
            head = tail = newcell;
        }
        else {
            tail->next = newcell;
            newcell->prev = tail;
            tail = newcell;
        }
        amount++;
    }

    void moveParticles(Particle p) {
        cell* curr = head;
        string str = "O";
        int i = 0;
        auto [rows,cols] = get_terminal_size();
        if (p.type == MovementType::STREAMER) {
 			for (i = 0; i < p.lifetime; i++) {
                p.px = p.px + p.vx;
                p.py = p.py + p.vy;

                if (p.px < 0) {
                    head = curr->next;
                    delete curr;
                    break;
                }
                if (p.py < 0) {
                    head = curr->next;
                    delete curr;
                    break;
                }
                if (p.px >= cols) {
                    head = curr->next;
                    delete curr;
                    break;
                }
                if (p.py >= rows) {
                    head = curr->next;
                    delete curr;
                    break;
                }
                movecursor(p.py, p.px);
                setbgcolor(7, 24, 86);
                setcolor(255, 0, 0);
                cout << str;
                cout.flush();
                resetcolor();
                usleep(1'000'000 / FPS);
                clearscreen();

            }
        }
    }

    int numParticles() {
        return amount;
    }

};
