CC=gcc
COMPILE=$(CC) -g
CFILES=$(dir \s *.c*)
OBJECT=main.o data_funcs.o solution_funcs.o
TARGET=launch
$(TARGET):$(OBJECT)
	$(COMPILE) -o $@ $(OBJECT)
.c:.o
	$(COMPILE) -c $< -o $@
clean:
	del $(TARGET).exe $(OBJECT)