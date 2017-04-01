#ifndef object_h
#define object_h

typedef unsigned char d_byte;
typedef int d_int;
typedef unsigned int d_uint;
typedef double d_float;

typedef int (*d_CFunction)();

typedef struct GCObject GCObject;
#define CommonHeader	GCObject *next;d_byte tt;d_byte marked
struct GCObject{
	CommonHeader;
}; 


typedef union Value{
	GCObject *gc;
	int b;
	d_int i;
	d_float	f;
	d_CFunction cf;
	void *p;/*light user data*/
}Value;

#define TValuefield	Value value_;int tt_

typedef struct TValue{
	TValuefield;
}TValue;

typedef struct Table{
	CommonHeader;
	struct Table *metatable;
	int flags;
	unsigned int arraysize;
	TValue *array;		
}Table;

#endif
