all:
	@gcc main.c escola.c handle_file.c -I. -o main
run:
	./main
