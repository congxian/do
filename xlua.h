#ifndef xlua_h
#define xlua_h

#include<stdio.h>

#define LUA_OK	0

#define LUA_TTHREAD	8

#define LUA_NUMTAGS	9

typedef unsigned char lu_byte;

#define cast(t,exp) ((t)(exp))

typedef struct lua_State lua_State;

typedef void* (*lua_Alloc)(void *ud,void *ptr,size_t osize,size_t nsize);

#endif
