#ifndef lstate_h
#define lstate_h

#include "xlua.h"
#include "lobject.h"

typedef struct{
	struct lua_State *twups;
	struct lua_State *mainthread;
	unsigned int seed;
}global_State;

typedef struct lua_State{
	CommonHeader;
	global_State *l_G;
}lua_State;

#define G(L) (l->l_G)

extern lua_State *lua_newstate(lua_Alloc f,void *ud);

#endif
