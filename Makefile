CC = gcc -g
LEX = flex
YACC = bison -y
LLIBS = 
OBJS = main.o y.tab.o lex.yy.o \
		tree.o \
		check.o \
	 	code.o instr.o generate.o 

f-- : $(OBJS) 
	$(CC) -o f-- $(OBJS) $(LLIBS) 

lex.yy.c : zb.l
	$(LEX) zb.l
lex.yy.o : lex.yy.c 

y.tab.o : y.tab.c tree.h
y.tab.c : zb.y
	$(YACC) zb.y
y.tab.h : zb.y
	$(YACC) -d zb.y

scan : scan.o lex.yy.o
	$(CC) -o scan scan.o lex.yy.o $(LLIBS)
scan.o : scan.c 

RDtree : RDtree.o lex.yy.o tree.o
	$(CC) -o RDtree.o lex.yy.o tree.o $(LLIBS)
RDtree.o : RDtree.c y.tab.h
	$(CC) -o RDtree.o RDtree.c

st.o : st.c st.h tree.h
tree.o : tree.c tree.h
check.o : check.c tree.h ST.h

main.o : main.c tree.h

clean :
	-@ mv mydefs.aux T
	-@ rm lex.yy.c y.tab.c *.o *.log *.aux
	-@ mv T mydefs.aux
realclean : clean
	-@ rm scan f--
