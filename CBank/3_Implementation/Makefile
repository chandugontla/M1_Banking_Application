# Name of the project
PROJECT_NAME = CBank

# Output directory
BUILD = build

# All source code files
SRC = src/CBank_Header.c \
CBank.c \

# All test source files
TEST_SRC = src/CBank_Header.c\
test/Test_CBank.c\
unity/unity.c\

TEST_VALGRIND = src/CBank_Header.c\
test/testCBank_1.c\
unity/unity.c\

# All include folders with header files
INC = inc/CBank_Header.h

#Library Inlcudes
#INCLUDE_LIBS = 
INCLUDE_LIBS = -lcunit

# Project Output name
PROJECT_OUTPUT = $(BUILD)/$(PROJECT_NAME).out

# Default target built
$(PROJECT_NAME):all

# Run the target even if the matching name exists
.PHONY: run clean test doc all

all: $(SRC) $(INC)
	gcc $(SRC) $(INC) -o build/CBank.out

# Call `make run` to run the application
run:$(PROJECT_NAME)
	./$(PROJECT_OUTPUT).out

# Document the code using Doxygen
doc:
	make -C ./documentation

# Build and run the unit tests
test:$(BUILD)
	gcc $(TEST_SRC) $(INC) -o build/CBank_Test.out

valgrind:$(BUILD)
	gcc $(TEST_VALGRIND) $(INC) -o build/testVal.out

# Remove all the built files, invoke by `make clean`
clean:
	rm -rf $(BUILD) $(DOCUMENTATION_OUTPUT)
	
coverage:
	gcc $(SRC) $(INC) -o build/CBank.out
	gcov -a build/CBank.out

# Create new build folder if not present
$(BUILD):
	mkdir build
