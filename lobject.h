#ifndef lobject_h
#define lobject_h

#include "xlua.h"

typedef struct GCObject GCObject;
#define CommonHeader	GCObject *next;lu_byte tt;lu_byte marked;
struct GCObject{
	CommonHeader;
};


#endif
