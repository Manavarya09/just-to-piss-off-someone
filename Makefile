CC = gcc
PROGRAM = landing_page
SOURCE = landing_page.c

GTK_CFLAGS = `pkg-config --cflags gtk+-3.0`
GTK_LIBS = `pkg-config --libs gtk+-3.0`

CFLAGS = -Wall -Wextra -O2 $(GTK_CFLAGS)
LDFLAGS = $(GTK_LIBS)

all: $(PROGRAM)

$(PROGRAM): $(SOURCE)
	$(CC) $(CFLAGS) -o $(PROGRAM) $(SOURCE) $(LDFLAGS)

run: $(PROGRAM)
	./$(PROGRAM)

clean:
	rm -f $(PROGRAM)

install-deps:
	@echo "Installing GTK3 development libraries..."
	brew install gtk+3 pkg-config

help:
	@echo "Available targets:"
	@echo "  all         - Build the program (default)"
	@echo "  run         - Build and run the program"
	@echo "  clean       - Remove build files"
	@echo "  install-deps - Install GTK3 dependencies on macOS"
	@echo "  help        - Show this help message"

.PHONY: all run clean install-deps help