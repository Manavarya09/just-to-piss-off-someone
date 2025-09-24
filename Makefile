# Makefile for GTK Landing Page Application

# Compiler settings
CC = gcc
PROGRAM = landing_page
SOURCE = landing_page.c

# GTK flags (using pkg-config for proper linking)
GTK_CFLAGS = `pkg-config --cflags gtk+-3.0`
GTK_LIBS = `pkg-config --libs gtk+-3.0`

# Compiler flags
CFLAGS = -Wall -Wextra -O2 $(GTK_CFLAGS)
LDFLAGS = $(GTK_LIBS)

# Default target
all: $(PROGRAM)

# Build the program
$(PROGRAM): $(SOURCE)
	$(CC) $(CFLAGS) -o $(PROGRAM) $(SOURCE) $(LDFLAGS)

# Run the program
run: $(PROGRAM)
	./$(PROGRAM)

# Clean build files
clean:
	rm -f $(PROGRAM)

# Install GTK development libraries (macOS with Homebrew)
install-deps:
	@echo "Installing GTK3 development libraries..."
	brew install gtk+3 pkg-config

# Help target
help:
	@echo "Available targets:"
	@echo "  all         - Build the program (default)"
	@echo "  run         - Build and run the program"
	@echo "  clean       - Remove build files"
	@echo "  install-deps - Install GTK3 dependencies on macOS"
	@echo "  help        - Show this help message"

.PHONY: all run clean install-deps help