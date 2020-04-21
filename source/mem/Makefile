APP=memUT

CFLAGS=-Wall
CFLAGS+= -I ../includes
LDFLAGS=

OBJDIR := objs
objects = $(addprefix $(OBJDIR)/,IXMalloc.o memUT.o)


$(OBJDIR)/%.o : %.c
	$(COMPILE.c) $(OUTPUT_OPTION) $<

all: $(OBJDIR) $(APP)


$(APP):$(objects)
	gcc -o $(APP) $(objects) $(INCS)

$(OBJDIR):
	mkdir $(OBJDIR)

.PHONY=clean
clean: 
	rm -rf $(OBJDIR) $(APP)
