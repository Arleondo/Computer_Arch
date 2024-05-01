.text
.globl __main

__main:
    li $v0, 2
    li $v1, 2
    move $t0, $a0
    move $t1, $a1
    li $t2, 32

multiplicar:
    andi $t3, $t1, 1
    beq $t3, $zero, no_resta

    addu $v0, $v0, $t0
    b no_cambio

no_resta:
    sra $t0, $t0, 1
    sra $t1, $t1, 1

no_cambio:
    sra $t0, $t0, 1
    sll $t1, $t1, 1
    subi $t2, $t2, 1
    bnez $t2, multiplicar
    jr $ra