
ARMGNU ?= arm-none-eabi

AOPS = --warn --fatal-warnings 
COPS = -Wall -Werror -O2 -nostdlib -nostartfiles -ffreestanding 



gcc : blinker01.hex blinker01.bin

all : gcc 

clean :
	rm -f *.o
	rm -f *.bin
	rm -f *.hex
	rm -f *.elf
	rm -f *.list
	rm -f *.img
	rm -f *.bc
	rm -f *.clang.opt.s

vectors.o : vectors.s
	$(ARMGNU)-as vectors.s -o vectors.o

blinker01.o : SynthOS_globals.c SynthOS_List.c SynthOS_Lock.c SynthOS_Main.c SynthOS_RoundRobinScheduler.c SynthOS_Scheduler.c SynthOS_TCB.c User_blinker01.c vectors.o
	$(ARMGNU)-gcc $(COPS) -o blinker01.o *.c vectors.o -I.

blinker01.elf : memmap vectors.o blinker01.o 
	$(ARMGNU)-ld blinker01.o -T memmap -o blinker01.elf
	$(ARMGNU)-objdump -D blinker01.elf > blinker01.list

blinker01.bin : blinker01.elf
	$(ARMGNU)-objcopy blinker01.elf -O binary blinker01.bin

blinker01.hex : blinker01.elf
	$(ARMGNU)-objcopy blinker01.elf -O ihex blinker01.hex







