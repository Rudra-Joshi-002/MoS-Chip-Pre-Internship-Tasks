# Makefile for modular RPN calculator (K&R exercises 4-3 .. 4-10)
# Put this Makefile in the project root where your .c/.h files are.
# It compiles all .c files automatically, places .o files in obj/ and the binary in bin/.
# It also generates header dependency files (.d) so header edits cause recompilation.
#
#------------------Also Here are Some General Information to Make more sense of What follows-------------

# Simple explanation of this Makefile (paste these comments into your Makefile)
#
# Toolchain & flags:
# CC       - which compiler is used (gcc). Change to clang if you prefer.
# CFLAGS   - compilation flags for warnings, debug info and language standard.
# CPPFLAGS - preprocessor flags (e.g. -I. to find headers in current directory).
# LDFLAGS  - linker flags (e.g. -lm to link the math library).
#
# Directories & files:
# SRCDIR   - where source .c files live ('.' by default). Change if you use src/.
# OBJDIR   - directory to store compiled .o files (keeps root clean).
# BINDIR   - directory for the final executable(s).
# TARGET   - the final executable path (bin/calc).
#
# Automatic discovery and mapping:
# SOURCES  - finds all .c files automatically (wildcard).
# OBJECTS  - maps each source to an object file (obj/%.o).
# DEPS     - auto-generated dependency files (.d) used to rebuild objects when headers change.
#
# Default target:
# all: build - default goal; 'make' will call this.
#
# Linking rule (TARGET):
# - links all .o files into the final executable.
# - the order-only prerequisite `| $(BINDIR)` ensures the bin/ directory exists first.
#
# Compile rule (OBJDIR/%.o):
# - compiles each .c into obj/.o and generates a dependency .d file.
# - uses -MMD -MP to make a .d file so make tracks header includes.
#
# Directory rules:
# - ensure obj/ and bin/ exist before compiling/linking.
#
# Convenience targets:
# run:   builds and runs the program.
# test:  placeholder to run automated tests (customize as needed).
# clean: removes obj/ and bin/ artifacts.
# rebuild: cleans and rebuilds everything from scratch.
#
# Dependency inclusion:
# -include $(DEPS)  : if .d files exist include them; this makes header edits trigger recompiles.
#
# Notes:
# - $@ is the target name, $< is the first prerequisite, $^ is all prerequisites.
# - The pattern rule uses $(OBJDIR)/%.o : $(SRCDIR)/%.c to create objects from sources.
# - Using obj/ and bin/ keeps the repo tidy and allows incremental builds.
#
# wildcard — Make function that lists files matching a pattern.
#
# patsubst — function that rewrites filenames (src/foo.c -> obj/foo.o).
#
# In a Makefile, .PHONY is a special built-in target that tells make that the listed names 
# are not actual files, but rather labels for commands (also called phony targets).
#
# Why is this needed?
#
# When you run a command like:
#
# make clean
#
# make looks for a file named clean in the current directory.
# If it finds one, it assumes that the target is up to date and doesn’t execute the associated 
# commands — because make’s entire logic is based on file timestamps.
# To prevent this confusion, we declare:
#
# .PHONY: clean
#
#
# This tells make:
#
# Ignore any file named clean; always run the commands for this target.


# Makefile for modular RPN calculator (fixed)
CC      := gcc
CFLAGS  := -std=c11 -Wall -Wextra -g
CPPFLAGS := -I.
LDFLAGS := -lm

SRCDIR  := .
OBJDIR  := obj
BINDIR  := bin
TARGET  := $(BINDIR)/expr

SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))
DEPS := $(OBJECTS:.o=.d)

.PHONY: all build run test clean rebuild
all: build

# -- build target (explicit) --
# Build depends on the final executable target
build: $(TARGET)

# Link objects into executable. Ensure bin/ exists first (order-only prerequisite).
$(TARGET): $(OBJECTS) | $(BINDIR)
	@echo "Linking executable -> $@"
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

# Compile each .c into obj/.o and write dependency .d
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@echo "Compiling $< -> $@"
	$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -MP -c $< -o $@

# Create obj/ directory if missing
$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Create bin/ directory if missing
$(BINDIR):
	@mkdir -p $(BINDIR)

# Convenience targets
run: build
	@echo "Running $(TARGET)"
	./$(TARGET)

test: run
	# put test harness invocation here

clean:
	@echo "Cleaning build artifacts..."
	@rm -rf $(OBJDIR) $(BINDIR)
	@echo "Clean complete."

rebuild: clean all

# Include dependency files if they exist
-include $(DEPS)

# --------------- Notes for users ---------------
# - To add a new module, just create new .c and .h files in the project root; 'make' will pick them up.
# - To debug: use 'gdb bin/calc' (binary contains -g symbols).
# - If you prefer sources inside src/, change SRCDIR := src and move files into src/.
