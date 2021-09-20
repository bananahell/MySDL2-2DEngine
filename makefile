#################################
##### Linux Makefile for SDL2 use
#################################

##### Compiler
COMPILER = g++
##### Remove directories
RMDIR = rm -rdf
##### Remove files
RM = rm -f

##### Automatic dependency creation
DEP_FLAGS = -M -MT $@ -MT $(BIN_PATH)/$(*F).o -MP -MF $@
##### Linked libraries
LIBS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm
##### Include path
INC_PATHS = -I$(INC_PATH) $(addprefix -I,$(SDL_INC_PATH))

##### Compile directives
FLAGS = -std=c++17 -Wall -pedantic -Wextra -Werror=init-self -O3 -mtune=native

INC_PATH = include
SRC_PATH = src
BIN_PATH = bin
DEP_PATH = dep

##### File list by type
CPP_FILES = $(wildcard $(SRC_PATH)/*.cpp)
INC_FILES = $(wildcard $(INC_PATH)/*.h)
FILE_NAMES = $(CPP_FILES:.cpp=) $(INC_FILES:.h=)
DEP_FILES = $(addprefix $(DEP_PATH)/,$(addsuffix .d,$(FILE_NAMES)))
OBJ_FILES = $(addprefix $(BIN_PATH)/,$(notdir $(CPP_FILES:.cpp=.o)))

.PHONY: cppcheck clean folders help

##### Generates object files
all: $(OBJ_FILES)

.PRECIOUS: $(BIN_PATH)/%.o
$(BIN_PATH)/%.o: $(DEP_PATH)/%.d | folders
	$(COMPILER) $(INC_PATHS) $(addprefix $(SRC_PATH)/,$(notdir $(<:.d=.cpp))) -c $(FLAGS) -o $@

##### Generates dependency files
.PRECIOUS: $(DEP_PATH)/%.d
$(DEP_PATH)/%.d: $(SRC_PATH)/%.cpp | folders
	$(COMPILER) $(INC_PATHS) $< $(DEP_FLAGS) $(FLAGS)

clean:
	-$(RMDIR) $(DEP_PATH)
	-$(RMDIR) $(BIN_PATH)
	-$(RM) $(EXEC)

##### Call for cppcheck
cppcheck:
	cppcheck --enable=all . -I./include --suppress=missingInclude --suppress=unusedFunction

folders:
	@mkdir -p $(DEP_PATH) $(BIN_PATH) $(INC_PATH) $(SRC_PATH)

##### Debugging rules
print-% : ; @echo $* = $($*)

help:
	@echo Available commands
	@echo - clean:    Cleans generated files
	@echo - cppcheck: Uses cppcheck on compiled objects
	@echo - help:     Shows help
	@echo - folders:  Generates project directories
