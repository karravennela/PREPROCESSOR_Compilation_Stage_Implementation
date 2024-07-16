preprocessor:main.o cpy_file.o dot_i.o inc_header.o rm_com.o rp_mac.o
	cc main.o cpy_file.o dot_i.o inc_header.o rm_com.o rp_mac.o -o preprocessor

main.o:main.c
	cc -c main.c
cpy_file.o:cpy_file.c
	cc -c cpy_file.c
dot_i.o:dot_i.c
	cc -c dot_i.c
inc_header.o:inc_header.c
	cc -c inc_header.c
rm_com.o:rm_com.c
	cc -c rm_com.c
rp_mac.o:rp_mac.c
	cc -c rp_mac.c
clear:
	@echo "Cleaning up..."
	@rm -v *.o
