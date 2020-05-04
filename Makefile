all:
	nasm -felf add.asm
	gcc -Wall -lgcc -m32 add.o add.c -o add
