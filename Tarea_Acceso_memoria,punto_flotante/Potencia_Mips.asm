.data
str_base: .asciiz	"Ingresar base: "
str_exp: .asciiz	"Ingresar exponente: "
str_Res: .asciiz	"El resultado es: "
str_Err: .asciiz	"Entrada no valida. Base/Exponente deben ser positivos"

.text

.globl __main

__main:
	li $v0,4
	la $a0, str_base
	syscall
	li $v0,5
	syscall
	move $s0,$v0	#Para guardar la base en S0
	
	li $v0, 4
	la $a0, str_exp
	syscall
	li $v0,5
	syscall
	move $s1, $v0	#Para guardar el exponente en S1
	
	jal potencia
	
	#Para imprimir
	li $v0, 4
	la $a0, str_Res
	syscall
	
	move $a0, $s2
	li $v0, 1
	syscall
	
	li $v0, 10
	syscall
	
#Calcula la potencia
potencia:
	bgez $s0, Base_no_negativa
	j invalid_input
	
Base_no_negativa:
	bgez $s1, Exp_no_negativo
	j invalid_input
	
Exp_no_negativo:
	li $s2, 1
	loop:
		beqz $s1, done
		mul $s2, $s2, $s0
		subi $s1, $s1, 1
		j loop
		
done:
	jr $ra
	
invalid_input:
	li $v0, 4
	la $a0, str_Err
	syscall
	j exit
	
exit:
	jr $ra
	
	
	
	
	
	
	
	
	
	