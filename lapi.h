#ifndef lapi_h
#define lapi_h

#define api_incr_top(L)	{L->top++;api_check(L,L->top <= L->ci->top,"stack flow");}
#define adjustresults(L,nres)	{if( (nres)==LUA_MULT && L->ci->top<L->top ) L->ci->top=L->top;}
#define api_checknelems(L,n)	api_check(L,(n)<L->top-L->ci->func,"not enough element")

#endif
