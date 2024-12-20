OBJFILES := binary_tree_func.o in_out.o main.o differentiator.o recuresive_descent.o
FLAGS := -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

all: main.exe 

run: main.exe
	./main.exe

binary_tree_func.o: binary_tree_func.cpp
	@ g++ binary_tree_func.cpp -c $(FLAGS) -o binary_tree_func.o

differentiator.o: differentiator.cpp
	@ g++ differentiator.cpp -c $(FLAGS) -o differentiator.o

in_out.o: in_out.cpp
	@ g++ in_out.cpp -c $(FLAGS) -o in_out.o

main.o: main.cpp
	@ g++ main.cpp -c $(FLAGS) -o main.o

recuresive_descent.o: recuresive_descent.cpp
	@ g++ recuresive_descent.cpp -c $(FLAGS) -o recuresive_descent.o

main.exe : $(OBJFILES)
	@ g++ $(FLAGS) $(OBJFILES) -o main.exe
