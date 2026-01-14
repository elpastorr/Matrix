NAME = matrix
CXX = c++
CXXFLAGS = #-Wall -Wextra -std=c++98
TARGET = ex02
SRCS = Matrix.cpp Vector.cpp $(TARGET)/main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: clean all


.PHONY: all clean