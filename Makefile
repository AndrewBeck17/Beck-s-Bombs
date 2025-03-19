a.out: main.o
	g++ -c -g -fsanitize=address main.cc
main.o: main.cc ParticleSystem.h particle.h cell.h particleGraphic.h
	g++ -g -fsanitize=address main.cc
clean:
	rm -rf a.out core *.cc
