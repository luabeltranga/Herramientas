CXX = g++
CXXFLAGS = -fsanitize=address -fsanitize=leak -fsanitize=undefined  -std=c++17	
#CXXFLAGS = -std=c++14  	

laplace:
	$(CXX) $(CXXFLAGS)laplace.cpp
laplace2: laplace2.o functions.o
	$(CXX) $(CXXFLAGS) laplace2.o functions.o
laplace2.o:laplace2.cpp
	$(CXX) $(CXXFLAGS) -c laplace2.cpp
functions.o:functions.cpp
	$(CXX) $(CXXFLAGS) -c functions.cpp	
laplace3:
	$(CXX) $(CXXFLAGS)  laplace3.cpp
onda:
	$(CXX) $(CXXFLAGS) onda.cpp
poisson: functions.o poisson.o
	$(CXX) $(CXXFLAGS) poisson.o functions.o
poisson.o:poisson.cpp
	$(CXX) $(CXXFLAGS) -c  poisson.cpp
clean:
	rm -f *.dat *.txt *.gp *.out *.gif *o
