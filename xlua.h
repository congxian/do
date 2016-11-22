#ifndef xlua_h
#define xlua_h

#define LUA_TTHREAD 8

typedef unsigned char lu_byte;

#define cast(t,exp) ((t)(exp))

typedef void* (*lua_Alloc)(void *ud,void *ptr,size_t osize,size_t nsize);

#endif
