#include "xlua.h"
#include "ldo.h"

lua_State  *luaD_rawrunprotected(lua_State *L,Pfunc f,void *ud){
	(*f)(L,ud);
}
