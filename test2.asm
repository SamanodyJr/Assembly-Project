Loop: 
	slli a0, s6, 2 #multiplying by 4
	add a0, a0, s9 #adding value of a0 in s9
	lw s1, 0(a0) #loading the value from address a0 to register s1
	bne s1, s8, Exit #checks if s1 is not equal to s1, if so it jumps to exit
	addi s6, s6, 1 #increment s6 by 1
	jal x0, Loop #for looping until conditioned met 

Exit: 
	ecall #terminates 