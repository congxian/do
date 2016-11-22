#include<stdio.h>
#include<time.h>

#include "xlua.h"
#include "lstate.h"

typedef struct{
	unsigned char extra[29];
	lua_State l;
}LX;

typedef struct{
	LX l;
	global_State g;
}LG;

static unsigned int makeseed(){
	unsigned int h = time(NULL);
	printf(" makeseed value = %d\n",h);
}

static void preinit_thread(lua_State *L,global_State *g){
}


lua_State *lua_newstate(lua_Alloc f,void *ud){
	lua_State *L;
	global_State *g;

	LG *lg = cast(LG*,(*f)(ud,NULL,LUA_TTHREAD,sizeof(LG)));
	if(NULL == lg) return NULL;
	
	L = &lg->l.l;
	g = &lg->g;

	L->next = NULL;
	L->tt = LUA_TTHREAD;

	preinit_thread(L,g);
	g->mainthread = L;
	g->seed = makeseed();
}
