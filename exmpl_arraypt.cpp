#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

int a = 12;
void test(char**,char);

void main(){
	char *ps[4]={"sdf","adfa","safddsa","retwtrfd"}, type[5]="char";
	
	test( &(*ps),type[5]);
}

void test(char **arg, char type){
	for(int i=0;i<sizeof(arg)/sizeof(type);i++)
		cout << arg[i] << "\n";
}