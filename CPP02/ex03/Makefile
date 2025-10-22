CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
NAME = bsp

SRC_DIR = .
OBJ_DIR = obj

SRC = main.cpp \
	  Fixed.cpp \
	  Point.cpp \
	  bsp.cpp

OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re