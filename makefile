PROJ_NAME=instalador

C_SOURCE=$(wildcard *.c) \
	$(wildcard front/*.c)

H_SOURCE=$(wildcard *.h) \
	$(wildcard front/*.h)

OBJ=$(C_SOURCE:.c=.o)

CC_FLAGS=`pkg-config --cflags --libs gtk4`

all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	$(CC) -o $@ $^ $(CC_FLAGS)

%.o: %.c %.h
	$(CC) -o $@ $< -c $(CC_FLAGS)

instalador.o: instalador.c $(H_SOURCE)
	$(CC) -o $@ $< -c $(CC_FLAGS)

clean:
	rm -rf $(OBJ) $(PROJ_NAME)