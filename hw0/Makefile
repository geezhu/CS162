.PHONY:all clean
all:
	make main.o map.o wc.o
%.o:%.c
	$(CC) -o $@ $^
clean:
	rm *.o

