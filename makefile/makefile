obj=main.o add_int.o add_float.o sub_int.o sub_float.o

main:$(obj)
	gcc -o main $(obj)

$(obj):%.o:%.c
	gcc -c $< -o $@

.PHONY:clean

clean:
	rm -f $(obj) main
