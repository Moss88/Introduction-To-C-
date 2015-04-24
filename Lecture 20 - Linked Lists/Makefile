CC              = g++
SRC             = main.cpp list.cpp
TARGET          = test
OBJ             = $(SRC:.c=.o)
DDDEBUG         =
#------------------------------------------------------

$(TARGET): $(OBJ)
	$(CC) -g -O0 -ggdb -o $@ $(OBJ) -lm -lgomp -Wall

$(OBJ): $(SRC)
	$(CC) -g -O0 -ggdb -c $(SRC) $(DDDEBUG)

clean:
	rm -f *.o *~ $(TARGET)
