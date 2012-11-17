BUILD = build
SRC = src
CPP = g++
CFLAGS = -Wall -Wextra -Werror
 
all: clean $(BUILD)/main

$(BUILD)/main:
	  cd $(SRC); $(MAKE)

clean:
	  cd $(SRC); $(MAKE) clean
