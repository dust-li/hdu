CC = g++
CFLAGS = -g

BUILD_DIR = build

C_SRC := $(foreach sdir, src, $(wildcard $(sdir)/*.c))
C_OBJ := $(patsubst src/%.c, $(BUILD_DIR)/%, $(C_SRC))

all: $(C_OBJ)

$(BUILD_DIR)/%: src/%.c
	$(CC) $(CFLAGS) -o $@ $^

.cpp.o:
	$(CC) $(CFLAGS) -o ./build/$@ $^

clean:
	rm build/*