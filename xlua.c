#include<stdio.h>

#include "xlua.h"
#include "lauxlib.h"

FILE *fp;

int main(int argc,char **argv){
/*	test code	*/
	int arr[10] = {0,1,2,3,4,5,6,7,8};

	printf("test\n");
	printf("%d\n",*arr);
	printf("%d\n",*(arr+1));
	printf("%d\n",*(arr+1));
	printf("%d\n",4[arr]);
	printf("%d\n",0[arr]);
	printf("%d\n",1[arr]);
	printf("%d\n",2[arr]);
	printf("test\n");

	int *array[10];

	char *aa = "this is a test\n";
	fp = fopen("run.log","wb");
	fwrite(aa,10,3,fp);
	fclose(fp);


	func_test(l_func);	


/*	正常代码	*/
	int result,status;
	
	lua_State *L = luaL_newstate();

	return 0;
}
