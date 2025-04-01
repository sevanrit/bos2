CC = gcc
CFLAGS = -Wall -I../libbos2
LDFLAGS = -L../libbos2 -lbos2
TARGET = bos2-client
SRC = client.c
OBJ = $(SRC:.c=.o)
INSTALL_DIR = /usr/local/bin

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

install:
	cp $(TARGET) $(INSTALL_DIR)

.PHONY: all clean install
