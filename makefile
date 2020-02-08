TEST_DIR = ./tests
BUILD_DIR = ./build

OUT = ${BUILD_DIR}/chess
OBJS = $(addprefix ${BUILD_DIR}/, test.o chess.o chesspieceset.o chessboard.o chess_test.o chesspieceset_test.o chessboard_test.o)

all: chess_test

chess_test: build_deps
	g++ -g -o ${OUT} ${OBJS}

build_deps:
	+$(MAKE) -C chess
	+$(MAKE) -C tests
    
clean:
	 rm ${BUILD_DIR}/*

run: 
	./${OUT}
