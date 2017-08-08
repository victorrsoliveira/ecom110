APP = main
OBJDIR := obj
OBJFILES := main.o my_buffer.o
OBJS := $(addprefix $(OBJDIR)/,$(OBJFILES))
BINDIR := bin
SOURCES =
CFLAGS += -DDEBUG

all: $(OBJS) | $(BINDIR)
	$(CC) $(CFLAGS) $^ -o bin/main

run: all
	./main
$(OBJDIR)/%.o: %.c
	$(COMPILE.c) $(OUTPUT_OPTION) $<

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir -p $@

$(BINDIR):
	mkdir -p $@

clean:
	rm -rf obj bin
