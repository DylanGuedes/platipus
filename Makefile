NAME = Platipus

SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
LIB_DIR = libs
BIN_DIR = bin

TARGET = $(BIN_DIR)/$(NAME)

CC = g++
CFLAGS = -pedantic -std=c++11 -MMD -g3 -g -fPIC\
		 -W -Wall -Wextra -Wshadow -Wcast-align -Wcast-qual -Wctor-dtor-privacy\
		 -Wdisabled-optimization -Wformat=2 -Wlogical-op -Wmissing-declarations\
		 -Wmissing-include-dirs -Wnoexcept -Woverloaded-virtual -Wredundant-decls\
		 -Wsign-promo -Wstrict-null-sentinel -Wswitch-default -Wundef\
		 -Wzero-as-null-pointer-constant -Wuseless-cast -Wnon-virtual-dtor
LIBS = -lsfml-system -lsfml-window -lsfml-graphics

SRC = ${wildcard $(SRC_DIR)/*.cpp}
OBJ = ${addprefix $(OBJ_DIR)/, ${notdir ${SRC:.cpp=.o}}}

.PHONY: clean depend dist-clean dist

all:
	@mkdir -p $(OBJ_DIR) $(BIN_DIR)
	$(MAKE) $(TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo Building $@
	@$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

$(TARGET): $(OBJ)
	@echo Building $@
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $@ $(LIBS)
	@echo Done.

clean:
	@echo Cleaning...
	@find . -name *.o -exec rm {} \;
	@find . -name *.d -exec rm {} \;
	@rm -rf *~ *.o prog out.txt

dist-clean: clean
	@rm -f $(TARGET)/$(NAME)
	@rm -rf *.tar.gz $(OBJ_DIR) $(BIN_DIR)
