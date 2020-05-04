bits 32
global go.main.additionTHEBEST
global main.additionADD
global main.additionLEA
section .text
additionTHEBEST:
    mov eax, [esp+4]
    mov edx, [esp+8]
.loop:
    inc eax
    dec edx
    cmp edx, 0
    jne .loop
    ret
main.additionADD:
    mov eax, [esp+4]
    mov edx, [esp+8]
    add eax, edx
    ret
main.additionLEA:
    mov eax, [esp+4]
    mov edx, [esp+8]
    lea eax, [eax+edx]
    ret