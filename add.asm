bits 32
global additionTHEBEST
global additionADD
global additionLEA
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
additionADD:
    mov eax, [esp+4]
    mov edx, [esp+8]
    add eax, edx
    ret
additionLEA:
    mov eax, [esp+4]
    mov edx, [esp+8]
    lea eax, [eax+edx]
    ret