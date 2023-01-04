# Containers Sources
CTNAMES = stack.c queue.c
CTDIR = src/Containers/
CTCST = $(addprefix $(CTDIR), $(SRCNAMES))
CTOBJ = $(addprefix $(BDIR), $(CTNAMES:.c=.o))

# Shunting yard Sources
SHNAMES = shuntin_yard_functions.c
SHDIR = src/ShuntinYard/
SRCSH = $(addprefix $(SHDIR), $(SHNAMES))
SHOBJ = $(addprefix $(BDIR), $(SHNAMES:.c=.o))

# Sources of the parser
PRNAMES = lexer.c parser.c
PRDIR = src/Lexical_analyses/
PRCSH = $(addprefix $(PRDIR), $(PRNAMES))
PROBJ = $(addprefix $(BDIR), $(PRNAMES:.c=.o))

#Build dir
BDIR = ./bdir/

# Includes
SHINC = src/ShuntinYard/
CTINC = src/Containers/
PRINC = src/Lexical_analyses/
LIBINC = Libft/

# Name
NAME = SORTST

# LIBFT
LIBFT	=  ./Libft/libft.a


all: $(BDIR) $(NAME)

$(NAME): $(LIBFT) $(SHOBJ) $(CTOBJ) $(PROBJ)
	gcc -o $(NAME) $(SHOBJ) $(CTOBJ) $(PROBJ) $(LIBFT) -lm -std=c11 -g

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










