# ============================================================
# Simple Makefile for compiling a single C source file
# Author: Rudra Joshi (Learning GNU Make)
# ============================================================

# --------- VARIABLES ----------------------------------------
CC = gcc               # The compiler to use
SRC = E-1-10.c          # Source file
OUT = E-1-10           # Output executable name

# --------- DEFAULT TARGET -----------------------------------
# 'make' with no arguments will run this first target by default
all: build

# --------- BUILD RULE --------------------------------------
#-o create the output file with name followed after -o flag if not used then 
# name of bin file will be a.out as per old unix conventions which stands
# assembler output

build:
	@echo "Starting build process..."
	$(CC) $(SRC) -o $(OUT)
	@echo "Build finished. Executable created: $(OUT)"

# --------- RUN RULE -----------------------------------------
run: build
	@echo "Executing program:"
	./$(OUT)

# --------- CLEAN RULE ---------------------------------------
clean:
	@echo "Cleaning up build files..."
	rm $(OUT)
	@echo "Cleanup done."

