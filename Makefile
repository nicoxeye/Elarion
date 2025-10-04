# mingw32-make
# === Elarion Makefile === #

CC = gcc

SRC_DIR = src

SRCS = $(wildcard $(SRC_DIR)/*.c)

TARGET = elarion

# compilator flags
CFLAGS = -Wall -Wextra -std=c17

INCLUDES = -I$(SRC_DIR)

all: $(TARGET)

# compilation of all .c files
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

# deleting system files
clean:
	del $(TARGET).exe 2>nul || rm -f $(TARGET)