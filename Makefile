NAME = matrix
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror

MAIN ?= 00
COMPLEX ?= 0

VALID_MAINS := 00 01 02 03 04 05 06 07 08 09 10 11 12 13 complex
ifeq ($(filter $(MAIN),$(VALID_MAINS)),)
$(error Invalid MAIN argument. Use: make MAIN=<main_number> COMPLEX=<0|1>)
endif

ifeq ($(COMPLEX),1)
CXXFLAGS += -DCOMPLEX
endif

TARGET = mains
MAIN_FILE = $(TARGET)/main_$(MAIN).cpp
SRCS = srcs/Matrix.cpp srcs/Vector.cpp srcs/Complex.cpp srcs/utils.cpp $(MAIN_FILE)
OBJS = $(SRCS:.cpp=.o)
DEPS = includes/Matrix.hpp includes/Vector.hpp includes/Complex.hpp includes/utils.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -I includes -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: clean all

help:
	@echo "Usage: make MAIN=<main_number> COMPLEX=<0|1>"
	@echo ""
	@echo "MAIN options: 00, 01, 02, 03, 04, 05, 06, 07, 08, 09, 10, 11, 12, 13, complex"
	@echo "COMPLEX options: 0 (use double), 1 (use Complex numbers)"
	@echo ""
	@echo "Examples:"
	@echo "  make MAIN=00 COMPLEX=0"
	@echo "  make MAIN=complex COMPLEX=1"
	@echo "  make MAIN=03              (defaults to COMPLEX=0)"

.PHONY: all clean fclean re help