# Containers Sources
CTNAMES = container_functions.c
CTDIR = src/Containers/
CTCST = $(addprefix $(CTDIR), $(SRCNAMES))
CTOBJ = $(addprefix $(BDIR), $(CTNAMES:.c=.o))

# Shunting yard Sources
SHNAMES = shuntin_yard_functions.c
SHDIR = src/ShuntinYard/
SRCSH = $(addprefix $(SHDIR), $(SHNAMES))
SHOBJ = $(addprefix $(BDIR), $(SHNAMES:.c=.o))

# Sources of the parser
PRNAMES = parser.c
PRDIR = src/Parser/
PRCSH = $(addprefix $(PRDIR), $(PRNAMES))
PROBJ = $(addprefix $(BDIR), $(PRNAMES:.c=.o))

#Build dir
BDIR = ./bdir/

# Includes
SHINC = src/ShuntinYard/
CTINC = src/Containers/
PRINC = src/Parser/
LIBINC = Libft/

# Name
NAME = SORTST

# LIBFT
LIBFT	=  ./Libft/libft.a


all: $(BDIR) $(NAME)

$(NAME): $(LIBFT) $(SHOBJ) $(CTOBJ) $(PROBJ)
	gcc -o $(NAME) $(SHOBJ) $(CTOBJ) $(PROBJ) $(LIBFT) -std=c11 -g

$(LIBFT):
	make -C ./Libft
# Make obj
$(BDIR) :
	mkdir -p $(BDIR)

$(BDIR)%.o:$(SHDIR)%.c
	gcc -I$(SHINC) -I$(CTINC) -I$(LIBINC) -I$(PRINC) -g -o $@ -c  $<

$(BDIR)%.o:$(CTDIR)%.c
	gcc -I$(CTINC) -I$(SHINC) -I$(LIBINC) -I$(PRINC) -g -o $@ -c  $<

$(BDIR)%.o:$(PRDIR)%.c
	gcc -I$(CTINC) -I$(SHINC) -I$(LIBINC) -I$(PRINC) -g -o $@ -c  $<

clean:
	rm -rf $(SHOBJ) $(CTOBJ) $(PROBJ)

fclean:  clean
	rm -rf $(NAME)
	rm -rf $(BDIR)

re: fclean all










