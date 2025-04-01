CC = gcc
CFLAGS = -Wall -I../libbos2
LDFLAGS = -L../libbos2 -lbos2
TARGET = bos2-daemon
SRC = daemon.c
OBJ = $(SRC:.c=.o)
INSTALL_DIR = /usr/local/bin
CONFIG_DIR = /etc/bos2

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

install:
	mkdir -p $(CONFIG_DIR)
	cp $(TARGET) $(INSTALL_DIR)
	cp bos2.cfg $(CONFIG_DIR)

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean install
