src = $(wildcard src/*.c)
obj = $(src:.c=.o)

LDFLAGS = -Wall

cktest.out: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) cktest.out
