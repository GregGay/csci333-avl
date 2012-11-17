BUILD = ../build
CPP = g++
CFLAGS = -Wall -Wextra -Werror
 
main: avl_test.cpp  AVL.o Node.o
	  $(CPP) $(CFLAGS) -o $(BUILD)/AVL avl_test.cpp AVL.o Node.o

AVL.o: AVL.h AVL.cpp
	$(CPP) $(CFLAGS) -c AVL.cpp

Node.o: Node.h Node.cpp
	$(CPP) $(CFLAGS) -c Node.cpp

clean:
	rm -f *.o;
	rm -f $(BUILD)/AVL; 
	rm -f main;
	rm -f *~;
