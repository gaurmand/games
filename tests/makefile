BUILD_DIR = ../build
OBJS = chess_test.o chesspieceset_test.o chessboard_test.o

all: ${OBJS}

%.o : %.cc
	g++ -g -o ${BUILD_DIR}/$@ -c $<
