all: chess

chess: chess.o chess_test.o
	 g++ -o chess chess.o chess_test.o

chess.o: chess.cc
	 g++ -c chess.cc

chesss_test.o: chess_test.cc
	g++ -c chess_test.cc
     
clean:
	 rm chess.o chess
