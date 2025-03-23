a.out: main.o
	g++ -c -g -fsanitize=address -std=c++23 main.cc
main.o: main.cc ParticleSystem.h particle.h cell.h particleGraphic.h explode.h tenji.cc beck.cc
	g++ -g -fsanitize=address -std=c++23 main.cc
clean:
	rm -rf a.out core *.cc
