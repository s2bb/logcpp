#------------------------------------------------------------------------------
# Author:  Sebastian Bialobrzecki
# E-mail:  sbb@openmailbox.org
# Date:    01.12.2015 (DD.MM.YYYY)
# License: GNU GPL v3 or later
# Purpose: Defines Makefile for building the library project non-recursive
#------------------------------------------------------------------------------
# Define version signatures
PROJECT	=logcpp
MAJOR	=0
MINOR	=0
PATCH	=1
NAME	=lib$(PROJECT).so
VERSION_NAME	=$(NAME).$(MAJOR)
RELEASE_NAME	=$(VERSION_NAME).$(MINOR).$(PATCH)

# Define tools
CXX	=g++
RM	=rm -v
LN	=ln -s -f

# Define libraries
LIBS		=c
LIBFLAGS	=$(addprefix -l, $(LIBS))

# Define flags
CXXFLAGS	=-c -std=c++11 -Wall -O3 -fPIC $(LIBFLAGS)
LDFLAGS		=-shared -Wl,-soname=$(VERSION_NAME)

# Define project directories.
ROOT_DIR	=.
SOURCES_DIR	=$(ROOT_DIR)/src/

# Map all *.cpp names into *.o names.
OBJECTS		=$(patsubst %.cpp, %.o, $(wildcard $(SOURCES_DIR)*.cpp))

# Include all the header files
CXXFLAGS	+=$(addprefix -I, $(INCLUDE_DIR))

# all
all: $(NAME)

# Define building 
$(NAME): $(OBJECTS)
	$(CXX) $(LDFLAGS) $^ -o $(RELEASE_NAME)
	$(LN) $(RELEASE_NAME) $(VERSION_NAME)
	$(LN) $(RELEASE_NAME) $(NAME)

# Define building object files from sources.
# *.cpp -> *.o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# *.cpp *.h -> *.o
%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: all clean

# Remove all files produced by this Makefile
clean:
	$(RM) $(OBJECTS) *.so* 2> /dev/null || /bin/true
