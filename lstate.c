#include<stdio.h>
#include<time.h>

#include "xlua.h"
#include "lstate.h"
#include "lmem.h"

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
}

static void stack_init(){
}

static void f_luaopen(lua_State *L,void *ud){
	global_State *g = G(L);

	stack_init();
	luaS_init(L);
	luaX_init(L);
}

static void preinit_thread(lua_State *L,global_State *g){
	int i;CallInfo *ci;
}

void close_state(lua_State *L){
	printf("close_state\n");
}

lua_State *lua_newstate(lua_Alloc f,void *ud){
	int i;
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

	for(i=0;i<LUA_NUMTAGS;i++)g->mt[i] = NULL;
	if(luaD_rawrunprotected(L,f_luaopen,NULL) != LUA_OK){
		close_state(L);
	}

	return L;
}
