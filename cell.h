#pragma once
struct cell {
	Particle particle;
	cell* next = nullptr;
	cell* prev = nullptr;

	cell(Particle particle) : particle(particle), next(nullptr), prev(nullptr) {}
};
