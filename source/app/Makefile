APP=listapp
objects=IXListApp.o ../mem/IXMalloc.o


$APP: $(objects)
	gcc -o $(APP) $(objects)

$(objects): ../includes/IXMalloc.h
IXListApp.o: ../mem/IXMalloc.o



.PHONY : clean
clean:
	rm -rf $(APP) $(objects)
