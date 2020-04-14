.PHONY:clean all

FLAGS:=-pthread -g
all :server.c client.c
	gcc $(FLAGS) server.c -o s 
	gcc $(FLAGS) client.c -o c 

*.o:*.c
	gcc -c  $< -o $@
clean:
	rm -f *.o
