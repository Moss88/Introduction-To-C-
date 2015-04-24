CC              = g++
SRC             = main.cpp intArray.cpp
TARGET          = test
OBJ             = $(SRC:.c=.o)
DDDEBUG         =
#------------------------------------------------------

$(TARGET): $(OBJ)
	$(CC) -O0  -g -Wall -o $@ $(OBJ)   -lm -lgomp 

$(OBJ): $(SRC)
	$(CC) -O0  -g   -c $(SRC) $(DDDEBUG)

clean:
	rm -f *.o *~ $(TARGET)
