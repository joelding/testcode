TARGETS = varlen

all : $(TARGETS)

varlen : varlen.c
	$(CC) -o $@ $<

clean :
	rm -f $(TARGETS)
