CC = gcc
CFLAGS = -Wall -fPIC -I../libbos2
LDFLAGS = -shared -L../libbos2 -lbos2
TARGET = libbos2-text.so
SRC = bos2_text.c
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
