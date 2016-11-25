#ifndef lobject_h
#define lobject_h

#include "xlua.h"

//回收结构
typedef struct GCObject GCObject;
#define CommonHeader	GCObject *next;lu_byte tt;lu_byte marked;
struct GCObject{
	CommonHeader;
};

typedef union{
	GCObject *gc;
	void *data;
	int b;
}Value;

#define TValuefields Value value_;int tt_

typedef struct lua_TValue{
	TValuefields;
}TValue;

typedef TValue *StkId;

//table
typedef struct Table{
	CommonHeader;
	struct Table *metatable;	/*元表*/
}Table;

#endif
