ROOT_PATH 		:= ..
BUILD_PATH		:= .
SSP_ROOT		:= $(BUILD_PATH)


TARGET	:= test_main.elf

CC		:= v850-elf-gcc
LINK	:= v850-elf-gcc

OBJS	:= start.o
OBJS	+= vector.o
OBJS	+= interrupt.o
OBJS	+= interrupt_table.o
OBJS	+= timer.o
OBJS	+= chip_timer.o
OBJS	+= interrupt_asm.o
OBJS	+= main.o

OBJS 	+= ssp/kernel_cfg.o ssp/startup.o ssp/task.o ssp/task_manage.o
OBJS	+= ssp/alarm.o ssp/cyclic.o ssp/time_event.o

CFLAGS	:= -O0 -mdisable-callt -mno-app-regs -mtda=0
CFLAGS	+= -gdwarf-2  -Wno-unused-label -Wpointer-arith  -mv850e2 -Wa,-mno-bcond17 -msoft-float -Wa,-mwarn-signed-overflow -Wa,-mwarn-unsigned-overflow
CFLAGS	+= -g

LDSCRIPT = $(BUILD_PATH)/v850esfk3.ld
LDFLAGS	:= -nostdlib -T $(LDSCRIPT)

TEST_PATH := .

IFLAGS	:= -I.
#IFLAGS	+= -I./list
#IFLAGS	+= -I$(ROOT_PATH)/common
#IFLAGS	+= -I$(CPU_CONFIG_PATH)
IFLAGS	+= -I$(SSP_ROOT)/ssp
IFLAGS	+= -I$(SSP_ROOT)/include
IFLAGS	+= -I$(SSP_ROOT)/arch/V850

VPATH	:= $(ROOT_PATH)/common
VPATH	+= $(TEST_PATH)

LIBS := -lm -lgcc -lc


%.o: %.S
	$(CC) -c $(IFLAGS) $(CFLAGS) $< -o $@

%.o: %.c
	$(CC) -c $(IFLAGS) $(CFLAGS) $< -o $@

all: $(OBJS)
	$(LINK) $(CFLAGS) $(LDFLAGS) -o $(TARGET) $(OBJS) -Wl,-Map,$(TARGET).map $(LIBS)
	v850-elf-objdump -d $(TARGET) > $(TARGET).dump



clean:
	rm -f $(OBJS) $(TARGET) *.map
