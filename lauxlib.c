#include<stdio.h>
#include<stdlib.h>

#include "xlua.h"
#include "lstate.h"
#include "lauxlib.h"


void *l_alloc(void *ud,void *ptr,size_t osize,size_t nsize){
	(void)ud;(void)osize;
	if(nsize == 0){
		free(ptr);
		printf("free ptr\n");
	}else return realloc(ptr,nsize);
}

lua_State* luaL_newstate(){
	lua_State *L = lua_newstate(l_alloc,NULL);

	if(L == NULL){
		printf("L is null\n");
	}

	return L;
}

/* test code */

void l_func(int i){
	printf("------------ the i is %d\n",i);
}

void func_test(lua_func f){
	f(1000);
	printf("-------------\n");
}
	
