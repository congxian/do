#ifndef lstate_h
#define lstate_h

#include "xlua.h"
#include "lobject.h"
#include "ldo.h"


typedef struct CallInfo{
	StkId func;
	StkId top;
}CallInfo;

typedef struct{
	struct lua_State *twups;
	struct lua_State *mainthread;
	unsigned int seed;

	struct Table *mt[LUA_NUMTAGS];
}global_State;

struct lua_State{
	CommonHeader;

	StkId stack;
	StkId top;
	StkId stack_last;

	unsigned short nci;
	CallInfo *ci;
	CallInfo *base_ci;

	global_State *l_G;
};

#define G(L) (L->l_G)

extern lua_State *lua_newstate(lua_Alloc f,void *ud);

#endif
