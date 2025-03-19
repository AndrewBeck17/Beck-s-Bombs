a.out: main.cc ParticleSystem.h particle.h cell.h
	g++ -g -fsanitize=address main.cc
clean:
	rm -rf a.out core *.cc
