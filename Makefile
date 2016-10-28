all:
	gcc linked_list.c -o linked_list
assembly:
	gcc -S linked_list.c -o assembly_linked_list
clean:
	rm -f linked_list
