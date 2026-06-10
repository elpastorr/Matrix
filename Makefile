NAME = matrix
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror

MAIN ?= 00
COMPLEX ?= 0

VALID_MAINS := 00 01 02 03 04 05 06 07 08 09 10 11 12 13 complex
ifeq ($(filter $(MAIN),$(VALID_MAINS)),)
$(error Invalid MAIN argument. Use: make MAIN=<main_number> COMPLEX=<0|1>)
endif

ifeq ($(COMPLEX),1)
CPPFLAGS += -DCOMPLEX
endif

MAIN_FILE = mains/main_$(MAIN).cpp
SRCS = srcs/Matrix.cpp srcs/Vector.cpp srcs/Complex.cpp srcs/utils.cpp $(MAIN_FILE)
OBJS = $(SRCS:.cpp=.o)
DEPS = includes/Matrix.hpp includes/Vector.hpp includes/Complex.hpp includes/utils.hpp
OBJS_CLEAN = srcs/Matrix.o srcs/Vector.o srcs/Complex.o srcs/utils.o mains/main_00.o mains/main_01.o mains/main_02.o mains/main_03.o mains/main_04.o mains/main_05.o mains/main_06.o mains/main_07.o mains/main_08.o mains/main_09.o mains/main_10.o mains/main_11.o mains/main_12.o mains/main_13.o mains/main_complex.o

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $^

%.o: %.cpp $(DEPS)
	$(CPP) $(CPPFLAGS) -I includes -c $< -o $@

clean:
	rm -f $(OBJS_CLEAN)

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
