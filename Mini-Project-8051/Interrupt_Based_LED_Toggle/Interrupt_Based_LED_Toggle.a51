;this is assembly code for mini-project
;where we are asked to interface a push button 
;and toggle the state of a LED when push button is pressed

;---Problem Statement----
;Interface push button. Toggle LED when button is pressed. 
;Use interrupt method to detect push button event (do not poll button value).

;Here we'll connect the push button to external interrupt-0 pin
;of 8051 thus when that is pressed this cause ISR of external interrupt-0
;to be executed which toggles the state of led connected to p3.0 of controller

org 0000h
	sjmp main_prog
	
org 0003h
	sjmp button_isr
	
org 000bh
	
	main_prog:
	
		;starting the main program from 13h since no other
		;interrupts are enabled we can start from here
		;assuming crystal frequency of 12MHz

		setb p3.2 ;to set external interrupt-0 as i/p pin
		setb tcon.0 ;set edge trigerred external interrupt
		mov IE,#81h ; Enable External Interrupt-0 Interrupt from IE Reg

		setb p3.0 ;assign LED on state initially

		here: sjmp here ;after that is set keep looping and wait for interrupt to happen

org 0020h
	
	button_isr:
	
		acall delay ;call debouce delay 
	
		mov c,p3.2
	
		jc skip
	
		cpl p3.0 ;if not carry that is button pressed then toggle LED connected
	
		skip:
	
	reti
	
	delay: ;this is a delay routine of 10ms to avoid debouncing of button
		 
		 MOV R6, #10 ; debounce delay for 10ms (Xtal = 12MHz)
		 
		 THR2: 
			MOV R7, #250
		 
		 THR1: 
			NOP
			NOP
		 
		 DJNZ R7, THR1
		 
		 DJNZ R6, THR2
	 RET
	 
end
		 