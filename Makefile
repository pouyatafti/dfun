LIB=dfun

CFLAGS+=
#LDFLAGS+=--entry main
LDADD+=-lc -lm

SRCDIR=../src
TESTSRCDIR=../src/test
MAKEOBJDIR=./obj

SRCS!=find $(SRCDIR) -type f -not -path '*/test/*' -name '*.c'

TEST_SRCS!=find $(TESTSRCDIR) -type f -name '*.c'

tests: $(TEST_SRCS) all
	for t in $(TEST_SRCS); do \
		$(COMPILE.c) -I$(SRCDIR) $$t ; \
		cc -o $(.OBJDIR)/$$(basename -s .c $$t) $(.OBJDIR)/$$(basename -s .c $$t).o $(LDFLAGS) -L$(.OBJDIR) $(LDADD) -l$(LIB)  ; \
	done	

cleanall: clean
	rm -f $(.OBJDIR)/*

.include <bsd.lib.mk>
