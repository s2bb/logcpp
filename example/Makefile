#------------------------------------------------------------------------------
# Author:  Sebastian Bialobrzecki
# E-mail:  sbb@openmailbox.org
# Date:    01.12.2015 (DD.MM.YYYY)
# License: GNU GPL v3 or later
# Purpose: Intermediate Makefile for handy project building.
#------------------------------------------------------------------------------
# Define version signatures
PROJECT  =logcpp-test
LIB_NAME =logcpp
VERSION  =0
MINOR    =0
PATCH    =1
VERSION_NAME =$(PROJECT).$(VERSION)
RELEASE_NAME =$(VERSION_NAME).$(MINOR).$(PATCH)

# Define project directories
ROOT_DIR    =.
SOURCES_DIR =$(ROOT_DIR)/src/
LIB_DIR     =../logcpp/

# Define tools
CXX  =g++
RM   =rm -v
CD   =cd
MAKE =make

# Define flags
CXXFLAGS =-c -std=c++11 -Wall -O3 -g 
# Set -rpath, this is just for development
LDFLAGS  =-L$(LIB_DIR) -Wl,-rpath=$(LIB_DIR) -l$(LIB_NAME)

# Map all *.cpp names into *.o names.
OBJECTS   =$(patsubst %.cpp, %.o, $(wildcard $(SOURCES_DIR)*.cpp))

# Include all the header files
CXXFLAGS +=$(addprefix -I, $(INCLUDE_DIR))
CXXFLAGS +=$(addprefix -I, $(LIB_DIR))

# all
all: LIBRARY $(PROJECT)

# Define building 
$(PROJECT): $(OBJECTS)
	$(CXX) $(LDFLAGS) $^ -o $(RELEASE_NAME)

LIBRARY:
	echo "Building Lib"
	($(CD) $(LIB_DIR); $(MAKE))

# Define building object files from sources.
# *.cpp -> *.o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# *.cpp *.h -> *.o
%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: all distclean clean run LIBRARY

# Remove all files produced by this Makefile
distclean: clean
	($(CD) $(LIB_DIR); $(MAKE) clean)

clean:
	$(RM) $(OBJECTS) $(RELEASE_NAME) 2> /dev/null || /bin/true

# Run the project
run: LIBRARY $(PROJECT)
	./$(RELEASE_NAME)
