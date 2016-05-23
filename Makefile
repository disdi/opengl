TARGETS := first
CFLAGS := -g -std=gnu++14 $(shell pkg-config --cflags glew glfw3)
LDFLAGS := $(shell pkg-config --libs glew glfw3)

all: $(TARGETS)

%: %.cc
	$(CXX) $(CFLAGS) $(LDFLAGS) $< -o $@

clean:
	rm -f $(TARGETS)

.PHONY: all clean
