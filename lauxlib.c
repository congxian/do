#include<stdio.h>
#include<stdlib.h>

#include "xlua.h"
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

	return L;
}
