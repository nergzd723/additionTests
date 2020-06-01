all:
	nasm -felf64 add.asm
	gcc -Wall -lgcc add.o add.c -o add -g
