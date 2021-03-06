#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Targets:
# 	1. Precompiled file *.i
#	2. Assembly file *.asm
#	3. Object file *.o
#	4. Output executable course1.out
#
# Platform Overrides:
#      1. MSP432 - Uses Arm architecture
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST
DEBUG = VERBOSE
PROGRAM = COURSE1
# Architectures Specific Flags
LINKER_FILE = ./msp432p401r.lds
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs
# Compiler Flags and Defines
CC = gcc
LD = ld 
COMMONFLAGS = -Wall \
	      -Werror \
	      -O0 \
	      -g \
	      -std=c99
CPPFLAGS = $(INCLUDES) -D$(PLATFORM) -D$(PROGRAM) -D$(VERBOSE)

ifeq ($(PLATFORM),HOST)
	CFLAGS = $(COMMONFLAGS)
	LDFLAGS = -Wl,-Map=course1.map
	SIZE = size
else
	CC=arm-none-eabi-gcc
	LD=arm-none-eabi-ld
	ARCHFLAGS = -mcpu=$(CPU) -m$(ARCH) -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS)
	CFLAGS = $(COMMONFLAGS) $(ARCHFLAGS)
	LDFLAGS = -Wl,-Map=course1.map -T $(LINKER_FILE)
	SIZE = arm-none-eabi-size
endif

OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)
ASMS = $(SOURCES:.c=.asm)
CPPS = $(SOURCES:.c=.i)

%.i:%.c
	$(CC) -E $(CPPFLAGS) -o $@ $<

%.d:%.c
	$(CC) -M -E $< $(CPPFLAGS) -o $@

%.asm:%.i
	$(CC) -S $< $(CFLAGS) -o $@

.PHONY:compile-all
compile-all:$(OBJS)
%.o:%.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

course1.out:$(OBJS)
	$(CC) $(LDFLAGS) $(ARCHFLAGS) $(OBJS) -o $@

.PHONY:build
build: course1.out $(DEPS)
	$(SIZE) course1.out

.PHONY:clear
clear:
	rm -f $(OBJS) $(DEPS) $(ASMS) $(CPPS) course1.out course1.map
