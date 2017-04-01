#include "object.h"

void *d_alloc(void *ud,void *ptr,size_t osize,size_t nsize){
	(void)ud;(void)osize;

	if(nsize == 0){
		free(ptr);
		return NULL;
	}else
		return realloc(ptr,nsize);
}

void doA_newstate(){
	D_State *D = do_newstate(d_alloc,NULL);
	
	if(D==NULL){
	}

	return D;
}
