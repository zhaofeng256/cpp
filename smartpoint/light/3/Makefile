main:main.o RefBase.o
	g++ -o $@ $^
%.o:%.cpp
	g++ -o $@ -c $< -I include
clean:
	rm *.o main
