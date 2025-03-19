#pragma once
struct Cell {
	Particle particle;
	Cell* next = nullptr;
	Cell(const Particle& particle) : particle(particle), next(nullptr) {}
};
