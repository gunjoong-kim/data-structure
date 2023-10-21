CXX=c++
CXXFLAGS=-std=c++17 -Wall -Wextra -Werror
NAME=a.out

SRCS= main.cpp	\
	  BST.cpp	\
	  AVL.cpp

OBJS=$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -g -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -g -c $< -o $@

debug: $(OBJS)
	$(CXX) $(CXXFLAGS) -g -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re