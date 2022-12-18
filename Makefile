# Stack Sources
STNAMES = stack_functions.cc
STDIR = src/Stack/
SRCST = $(addprefix $(STDIR), $(SRCNAMES))
STOBJ = $(addprefix $(BDIR), $(STNAMES:.cc=.o))

# Shunting yard Sources
SHNAMES = shuntin_yard_functions.cc list.cc
SHDIR = src/ShuntinYard/
SRCSH = $(addprefix $(SHDIR), $(SHNAMES))
SHOBJ = $(addprefix $(BDIR), $(SHNAMES:.cc=.o))

#Build dir
BDIR = ./bdir/

# Includes
SHINC = shuntin_yard.h
STINC = stack.h

# Name
NAME = SORTST


all: $(BDIR) $(NAME)

$(NAME): $(SHOBJ) $(STOBJ)
	gcc $(SHOBJ) $(STOBJ) -std=c11 -g -o $(NAME)

# Make obj
$(BDIR) :
	mkdir -p $(BDIR)

$(BDIR)%.o:$(SHDIR)%.cc
	gcc -I $(SHDIR)$(SHINC)  -g -o $@ -c  $<

$(BDIR)%.o:$(STDIR)%.cc
	gcc -I $(STDIR)$(SHINC)  -g -o $@ -c  $<

clean:
	rm -rf $(SHOBJ) $(STOBJ)

fclean:  clean
	rm -rf $(NAME)
	rm -rf $(BDIR)

re: fclean all










