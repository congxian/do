#ifndef lauxlib_h
#define lauxlib_h

#include "xlua.h"

typedef void* lua_func(int i);

extern lua_State* luaL_newstate();



extern void l_func(int i); 
extern void func_test(lua_func f);

#endif
