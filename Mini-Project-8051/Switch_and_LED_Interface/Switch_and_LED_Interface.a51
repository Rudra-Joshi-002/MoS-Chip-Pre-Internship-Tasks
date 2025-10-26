;this is assembly code for mini-project
;where we are asked to interface a switch 
;and a couple of LED's whose pattern of blinking
;changes as per switch position

;---Problem Statement----
;Interface Switch and LEDs with any micro-controller. 
;Update LED pattern according to switch positions.

;We'll connect a switch to pin 0 of port-2 i.e. P2.0
;We'll connect 8 LED's to port-3 from P3.0 ton P3.7
;Based on the position of switch we'll change its
;blinking pattern

;We'll use Timer-0 as a timer for changing the state
;of LED's this timer will be Interrupt based

;when timer Over Flows ISR will be invoked and state
;p3.0 will be toggled

;while a continuous loop checks p2.0 for switch states
;and updates the p3 value accordingly
org 0000h
	sjmp main_prog

org 000Bh
	ljmp Timer_ISR ;at IVT of T0 cause jump to actual
	;ISR
	
org 0013h
	main_prog:
	;starting the main program from 13h since no other
	;interrupts are enabled we can start from here
	;I've choosen a freq=0.5Hz i.e. 1sec On and 1sec Off
	;assuming 12MHz Crystal
	;here we'll use our own delay subroutine since Timers
	;of 8051 aren't able to generate such long delays
	;and at end of delay routine we'll set TF0 flag which will
	;trigger Interrupt
	
	mov p2,#0ffh ;set port-2 as i/p port
	mov IE,#82h ; Enable Timer-0 Interrupt from IE Reg
	
	main_loop:
		mov c,p2.0	;check status of p2.0 and make decision
		jc set_high
		sjmp set_low
	
	set_high:
	
		mov p3,#00fh
		
		high_loop:
			
			lcall delay1s
			mov c,p2.0
			jnc set_low
			sjmp high_loop
		
	set_low:
		
		mov p3,#0ffh
		
		low_loop:
			
			lcall delay1s
			mov c,p2.0
			jc set_high
			sjmp low_loop
		
	
org 100h
	
	Timer_ISR:
		
		; Save registers used by the ISR
		push psw
		push acc

		; Toggle P3 
		mov a,p3 ;read current value of P3
		xrl a,#0ffh ;toogle p3 using xor
		mov p3,a ;sent to toggled values to p3

		; Clear the timer overflow flag so future interrupts can be triggered
		clr tf0

		; Restore registers
		pop acc
		pop psw

	reti                ; return from interrupt
	
	delay1s:;1sec delaygeneration assuming 12Mhz Clk
	;r7, r5 and r6 of reg-bank-0 used

		push psw

		clr psw.3 ;explicitly sets Reg-Bank to R0

		clr psw.4

		mov r7,#02

		here0:

		mov r6,#250

		here10:

		mov r5,#250

		here20:
			nop
			nop

		djnz r5,here20
		djnz r6,here10
		djnz r7,here0

		setb tf0 ;set timer-0 over-flow flag to trigger interrupt

		pop psw

	ret;for delay1s
	
end