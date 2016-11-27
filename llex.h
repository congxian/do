#ifndef llex_h
#define llex_h

#include "xlua.h"


typedef struct SemInfo{
}Seminfo;

typedef struct Token{
	int token;
	struct SemInfo *seminfo;
}Token;

extern void luaX_init(lua_State *L);

#endif
