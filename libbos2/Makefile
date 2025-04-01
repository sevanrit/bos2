CC = gcc
CFLAGS = -Wall -fPIC
LDFLAGS = -shared
TARGET = libbos2.so
SRC = bos2.c
OBJ = $(SRC:.c=.o)
INSTALL_DIR = /usr/local/lib

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

install:
	cp $(TARGET) $(INSTALL_DIR)
	ldconfig
