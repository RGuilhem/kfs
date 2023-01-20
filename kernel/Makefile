RM     = rm -rf

AS    = i386-elf-as
CC    = i386-elf-gcc
VM    = qemu-system-i386
#-fno-rtti -nostdlib
CFLAGS = -Wall \
		 -Wextra \
		 -fno-builtin \
		 -fno-exceptions \
		 -nodefaultlibs \
		 -ffreestanding \
		 -std=gnu99

PRE_SRC        = kernel.c \
				 vga.c
SRC_DIR        = src/
SRC            = $(addprefix $(SRC_DIR), $(PRE_SRC))
PRE_OBJ        = $(PRE_SRC:.c=.o)
OBJ_DIR        = $(SRC_DIR)
OBJ            = $(addprefix $(OBJ_DIR), $(PRE_OBJ))
AS_FILES       = boot.s
AS_DIR         = $(SRC_DIR)
PRE_AS         = $(AS_FILES:.s=.o)
AS_OBJ         = $(addprefix $(AS_DIR), $(PRE_AS))
INCLUDE_DIR    = include/


STR_PRE_SRC        = strlen.c
STR_SRC_DIR        = $(SRC_DIR)/string/
STR_SRC            = $(addprefix $(STR_SRC_DIR), $(STR_PRE_SRC))
STR_PRE_OBJ        = $(STR_PRE_SRC:.c=.o)
STR_OBJ_DIR        = $(STR_SRC_DIR)
STR_OBJ            = $(addprefix $(STR_OBJ_DIR), $(STR_PRE_OBJ))

LD             = linker.ld
LD_FLAGS       = -nostdlib \
				 -nodefaultlibs \
		 		 -ffreestanding

NAME           = kfs.bin
IMAGE          = kfs.iso

all: $(IMAGE)
	
$(NAME): $(AS_OBJ) $(STR_OBJ) $(OBJ)
	$(CC) -T $(LD) -o $@ $(LD_FLAGS) $(AS_OBJ) $(OBJ) $(STR_OBJ) -lgcc

$(IMAGE): $(NAME)
	mkdir -p isodir/boot/grub
	cp $(NAME) isodir/boot/$(NAME)
	cp grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o $@ isodir

%.o: %.s
	$(AS) $< -o $@

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) -I$(INCLUDE_DIR)

run: $(IMAGE)
	 $(VM) -cdrom $(IMAGE)

clean:
	$(RM) $(OBJ)
	$(RM) $(AS_OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(IMAGE)
	$(RM) isodir/

re: fclean all

.PHONY: clean fclean all re
