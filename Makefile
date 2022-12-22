# Stack Sources
STNAMES = stack_functions.c
STDIR = src/Stack/
SRCST = $(addprefix $(STDIR), $(SRCNAMES))
STOBJ = $(addprefix $(BDIR), $(STNAMES:.c=.o))

# Shunting yard Sources
SHNAMES = shuntin_yard_functions.c list.c
SHDIR = src/ShuntinYard/
SRCSH = $(addprefix $(SHDIR), $(SHNAMES))
SHOBJ = $(addprefix $(BDIR), $(SHNAMES:.c=.o))

#Build dir
BDIR = ./bdir/

# Includes
SHINC = src/ShuntinYard/
STINC = src/Stack/
LIBINC = Libft/

# Name
NAME = SORTST

# LIBFT
LIBFT	=  ./Libft/libft.a


all: $(BDIR) $(NAME)

$(NAME): $(LIBFT) $(SHOBJ) $(STOBJ)
	gcc -o $(NAME) $(SHOBJ) $(STOBJ) $(LIBFT) -std=c11 -g

$(LIBFT):
	make -C ./Libft
# Make obj
$(BDIR) :
	mkdir -p $(BDIR)

$(BDIR)%.o:$(SHDIR)%.c
	gcc -I$(SHINC) -I$(STINC) -I$(LIBINC) -g -o $@ -c  $<

$(BDIR)%.o:$(STDIR)%.c
	gcc -I$(STINC) -I$(SHINC) -I$(LIBINC) -g -o $@ -c  $<

clean:
	rm -rf $(SHOBJ) $(STOBJ)

fclean:  clean
	rm -rf $(NAME)
	rm -rf $(BDIR)
	make fclean -C ./Libft

re: fclean all










