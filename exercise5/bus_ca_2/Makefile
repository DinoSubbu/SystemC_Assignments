# Universitaet Stuttgart, ES - ITI
# Modeling, Specification and Simulation SS 2014
# Feel free to modify this Makefile

# These should point to the correct SystemC directories
SYSTEMC_INCDIR = /home/dino/Install/include
SYSTEMC_LIBDIR = /home/dino/Install/lib


CXX     = g++

#CXXFLAGS = -O1 -g -Wall -Wno-reorder
CXXFLAGS = -std=c++11

INCDIR = -I. -I $(SYSTEMC_INCDIR)

LDFLAGS = -L. -L $(SYSTEMC_LIBDIR) -Wl,-rpath,$(SYSTEMC_LIBDIR)
LDLIBS = -lsystemc-d

SOURCES := $(wildcard *.cpp)
OBJECTS := $(SOURCES:.cpp=.o)

TARGET = $(notdir $(shell pwd))

$(TARGET): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(LDLIBS) -o $@ $(OBJECTS)
	@echo
	@echo "----------------------------------------"
	@echo " Compilation finished successfully!"
	@echo " Run simulation with the following command:"
	@echo " ./$@"

clean:
	-rm $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCDIR) -c -o $@ $<
