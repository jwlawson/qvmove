NAME = qvmove

# Using cygwin -std=gnu++11 should be used rather than -std=c++11
ifeq ($(CXX),icpc)
CXXFLAGS = -std=c++11 -xhost
OPT = -O3 -ipo -no-prec-div
B_OPT = -O3 -ipo -no-prec-div
else
CXXFLAGS = -Wall -std=gnu++11 -march=native
OPT = -g -O3
B_OPT = -g -O3
endif

# Specify base directory
BASE_DIR = .

# Specify source directory
SRC_DIR = $(BASE_DIR)/src

# Specify test directory
TEST_DIR = $(BASE_DIR)/test

# define the output directory for .o
OBJ_DIR = $(BASE_DIR)/build

# define any directories containing header files
INCLUDES = -I$(HOME)/include -I$(BASE_DIR)/include -I$(BASE_DIR)/lib/include

# define library paths
LFLAGS = -L$(HOME)/lib -L$(BASE_DIR)/lib

# define any libraries to link into executable
LIBS = -lqv

SRCS = $(wildcard $(SRC_DIR)/*.cc)

_OBJS = $(SRCS:.cc=.o)
OBJS = $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(_OBJS))

MAIN = $(NAME)

.PHONY: clean

all:   $(MAIN)

$(MAIN): $(OBJS)
	$(CXX) $(CXXFLAGS) $(B_OPT) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

install:	$(MAIN)
	cp $(MAIN) $(HOME)/bin/

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CXX) $(CXXFLAGS) $(OPT) $(INCLUDES) -c $<  -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cc
	$(CXX) $(CXXFLAGS) $(OPT) $(INCLUDES) -c $<  -o $@

$(OBJS): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) *.o *~ $(MAIN) $(OBJ_DIR)/*.o
	
