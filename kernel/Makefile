RM     = rm -rf

AS    = i386-elf-as
CC     = i386-elf-gcc
#-fno-rtti -nostdlib
CFLAGS = -Wall \
		 -Wextra \
		 -fno-builtin \
		 -fno-exceptions \
		 -nodefaultlibs \
		 -ffreestanding \
		 -std=gnu99

PRE_SRC        = kernel.c
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

LIBS_DIR               = lib/

LIB_STR                = $(LIBS_DIR)libstring.a
LIB_STR_PRE_SRC        = strlen.c
LIB_STR_PRE_OBJ        = $(LIB_STR_PRE_SRC:.c=.o)
LIB_STR_OBJ_DIR        = $(SRC_DIR)string/
LIB_STR_OBJ            = $(addprefix $(LIB_STR_OBJ_DIR), $(LIB_STR_PRE_OBJ))

LIBS                   = $(LIB_STR)
LIBRARIES              = -L$(LIBS_DIR) $(addprefix -l, $(LIBS))

all: kernel

kernel: $(LIB_STR) $(AS_OBJ) $(OBJ)

$(LIB_STR): $(LIB_STR_OBJ)
	ar -rcs $(LIB_STR) $(LIB_STR_OBJ)

%.o: %.s
	$(AS) $< -o $@

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) -I$(INCLUDE_DIR)

clean:
	$(RM) $(OBJ)
	$(RM) $(AS_OBJ)
	$(RM) $(LIB_STR_OBJ)

fclean: clean
	$(RM) $(LIB_STR)

re: fclean all

.PHONY: clean fclean all re
