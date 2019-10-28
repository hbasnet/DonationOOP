CXXFLAGS += -std=c++11
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

ex: main.o login.o index.o donate.o view.o about.o
	$(CXX) $(CXXFLAGS) -o run main.o login.o index.o donate.o view.o about.o $(GTKFLAGS)
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS)
login.o: login.h login.cpp
	$(CXX) $(CXXFLAGS) -c login.cpp $(GTKFLAGS)
index.o: index.h index.cpp
	$(CXX) $(CXXFLAGS) -c index.cpp $(GTKFLAGS)
donate.o: donate.h donate.cpp
	$(CXX) $(CXXFLAGS) -c donate.cpp $(GTKFLAGS)
view.o: view.h view.cpp
	$(CXX) $(CXXFLAGS) -c view.cpp $(GTKFLAGS)
about.o: about.h about.cpp
	$(CXX) $(CXXFLAGS) -c about.cpp $(GTKFLAGS)	
	