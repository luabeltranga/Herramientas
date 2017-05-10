CXX = g++
CXXFLAGS = -fsanitize=address -fsanitize=leak -fsanitize=undefined

laplace:
	$(CXX) $(CXXFLAGS)laplace.cpp
laplace2:
	$(CXX) $(CXXFLAGS)  laplace2.cpp
laplace3:
	$(CXX) $(CXXFLAGS)  laplace3.cpp
onda:
	$(CXX) $(CXXFLAGS) onda.cpp
poisson:
	$(CXX) $(CXXFLAGS) poisson.cpp
clean:
	rm -f *.dat *.txt *.gp *.out *.gif
