CXX = g++

FLAGS_BUILD = -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result
FLAGS_DEFAULT = -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -D=LOCAL
FLAGS_SAFE = -std=c++17 -Wshadow -Wall -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG_LOCAL -D=LOCAL
FLAGS_TOO_SAFE =-std=c++17 -Wall -Wextra -pedantic -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector

CXXFLAGS = $(FLAGS_SAFE)

# FILE := $(word 2, $(MAKECMDGOALS))
# TARGET := $(word 1, $(MAKECMDGOALS))

f = a

# CMD: make run f=a
run:
	@./$(f)

# CMD: make runf f=a
runf:
	@./$(f) < input.txt

# CMD: make check f=a
check:
	$(MAKE) $(f) -s
	@./$(f) < input.txt > output.txt
	diff --strip-trailing-cr output.txt out_ac.txt

# clean:
# find . -type f -executable -delete
