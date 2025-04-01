CC = gcc
CFLAGS = -Wall -fPIC -I../libbos2
LDFLAGS = -shared -L../libbos2 -lbos2 -ljson-c
TARGET = libbos2-json.so
SRC = bos2_json.c
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
