ifeq ($(PAYLOAD),)
$(error error: must specify PAYLOAD)
endif

SRC	= $(PAYLOAD)/$(PAYLOAD).c
OBJ	= $(PAYLOAD)/$(PAYLOAD).o
BIN	= $(PAYLOAD)/$(PAYLOAD).bin

CROSS_COMPILE ?= aarch64-linux-gnu-
CC = $(CROSS_COMPILE)gcc
OBJCOPY	= $(CROSS_COMPILE)objcopy

CFLAGS	=	-c	-O2	\
			-ffreestanding	-fno-builtin	-nostdlib	\
			-fno-stack-protector	-fno-asynchronous-unwind-tables	\
			-mgeneral-regs-only -Iinclude

OBJCOPY_FLAGS =	-O binary --only-section=.text.entry

all: $(BIN)

$(OBJ):	$(SRC)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS)	$< -o $@

$(BIN):	$(OBJ)
	@$(OBJCOPY) $(OBJCOPY_FLAGS)	$< $@
	@echo "Built payload $@"
	@rm $<

clean:
	rm -f */*.bin	
