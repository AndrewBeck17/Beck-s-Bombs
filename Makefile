a.out: main.o
	g++ -c -g -fsanitize=address -std=c++23 main.cc
main.o: main.cc ParticleSystem.h particle.h cell.h particleGraphic.h
	g++ -g -fsanitize=address -std=c++23 main.cc
clean:
	rm -rf a.out core *.cc
