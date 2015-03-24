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
INCLUDES = -I$(HOME)/include -I$(BASE_DIR)/include

# define library paths
LFLAGS = -L$(HOME)/lib -L$(BASE_DIR)/lib

# define any libraries to link into executable
LIBS = -lqv

MV_SRCS = $(SRC_DIR)/checker.cc \
					$(SRC_DIR)/checker_builder.cc \
					$(SRC_DIR)/consts.cc \
					$(SRC_DIR)/main.cc
_MV_OBJS = $(MV_SRCS:.cc=.o)
MV_OBJS = $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(_MV_OBJS))

CL_SRCS = $(SRC_DIR)/consts.cc \
					$(SRC_DIR)/qvmovecl.cc
_CL_OBJS = $(CL_SRCS:.cc=.o)
CL_OBJS = $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(_CL_OBJS))

.PHONY: clean

all: qvmove qvmovecl

qvmove: $(MV_OBJS)
	$(CXX) $(CXXFLAGS) $(B_OPT) $(INCLUDES) -o qvmove $(MV_OBJS) $(LFLAGS) $(LIBS)

qvmovecl: $(CL_OBJS)
	$(CXX) $(CXXFLAGS) $(B_OPT) $(INCLUDES) -o qvmovecl $(CL_OBJS) $(LFLAGS) $(LIBS)

install: qvmove qvmovecl
	cp qvmove $(HOME)/bin/
	cp qvmovecl $(HOME)/bin/

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CXX) $(CXXFLAGS) $(OPT) $(INCLUDES) -c $< -o $@

$(MV_OBJS): | $(OBJ_DIR)
$(CL_OBJS): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) *~ qvmove qvmovecl $(OBJ_DIR)/*.o

