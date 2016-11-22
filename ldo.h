#ifndef ldo_h
#define ldo_h

#include "xlua.h"


typedef void (*Pfunc)(lua_State *L,void *ud);

extern lua_State* luaD_rawrunprotected(lua_State *L,Pfunc f,void *ud);

#endif
