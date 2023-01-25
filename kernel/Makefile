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
				 gdt.c    \
				 vga.c    \
				 error.c  \
				 detect_memory.c
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

STR_PRE_SRC        = strlen.c \
					 memcmp.c \
					 memset.c \
					 memmove.c \
					 strchr.c \
					 memcpy.c
STR_SRC_DIR        = $(SRC_DIR)string/
STR_SRC            = $(addprefix $(STR_SRC_DIR), $(STR_PRE_SRC))
STR_PRE_OBJ        = $(STR_PRE_SRC:.c=.o)
STR_OBJ_DIR        = $(STR_SRC_DIR)
STR_OBJ            = $(addprefix $(STR_OBJ_DIR), $(STR_PRE_OBJ))


STDIO_PRE_SRC        = putchar.c \
					   puts.c \
					   ft_display_char.c \
					   ft_display_decimal.c \
					   ft_display_hex.c \
					   ft_display_pointer.c \
					   ft_display_str.c \
					   ft_display_unsigned.c \
					   ft_format.c \
					   ft_handle_specifier.c \
					   ft_printf.c \
					   ft_putnbr.c
STDIO_SRC_DIR        = $(SRC_DIR)stdio/
STDIO_SRC            = $(addprefix $(STDIO_SRC_DIR), $(STDIO_PRE_SRC))
STDIO_PRE_OBJ        = $(STDIO_PRE_SRC:.c=.o)
STDIO_OBJ_DIR        = $(STDIO_SRC_DIR)
STDIO_OBJ            = $(addprefix $(STDIO_OBJ_DIR), $(STDIO_PRE_OBJ))

LIB_OBJ            = $(STR_OBJ) $(STDIO_OBJ)

LD             = linker.ld
LD_FLAGS       = -nostdlib \
				 -nodefaultlibs \
		 		 -ffreestanding

NAME           = kfs.bin
IMAGE          = kfs.iso

all: $(IMAGE)
	
$(NAME): $(AS_OBJ) $(LIB_OBJ) $(OBJ)
	$(CC) -T $(LD) -o $@ $(LD_FLAGS) $(AS_OBJ) $(OBJ) $(LIB_OBJ) -lgcc

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
	$(RM) $(LIB_OBJ)
	$(RM) $(OBJ)
	$(RM) $(AS_OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(IMAGE)
	$(RM) isodir/

re: fclean all

.PHONY: clean fclean all re
