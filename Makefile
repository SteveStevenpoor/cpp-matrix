BIN_NAME	= mat

SRCS		= main.cpp\
			  src/Matrix.cpp\
			  src/matrix_test.cpp

HEADERS		= include/Mat.h

OBJ			= $(SRCS:.cpp=.o)

CC			= g++ -fsanitize=address

CFLAGS		= -Iinclude

LDFLAGS		= -fsanitize=address -lgtest -pthread

all: $(BIN_NAME) clean

clean:
	@rm -rf *.o src/*.o

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@