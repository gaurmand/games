TEST_DIR = ../tests
BUILD_DIR = ../build
OBJS = chess.o chesspieceset.o

all: ${OBJS}

%.o : %.cc
	g++ -g -o ${BUILD_DIR}/$@ -c $<
