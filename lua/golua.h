#include <stdint.h>

typedef struct { void *t; void *v; } GoInterface;

#define GOLUA_DEFAULT_MSGHANDLER "golua_default_msghandler"

/* function to setup metatables, etc */
void clua_initstate(lua_State* L);
void clua_initHeeus(lua_State* L);
void clua_hide_pcall(lua_State *L);

unsigned int clua_togofunction(lua_State* L, int index);
unsigned int clua_togostruct(lua_State *L, int index);
void clua_pushcallback(lua_State* L);
void clua_pushgofunction(lua_State* L, unsigned int fid);
void clua_pushgostruct(lua_State *L, unsigned int fid);
void clua_setgostate(lua_State* L, size_t gostateindex);
int dump_chunk (lua_State *L);
int load_chunk(lua_State *L, const char *b, int size, const char* chunk_name);
size_t clua_getgostate(lua_State* L);
GoInterface clua_atpanic(lua_State* L, unsigned int panicf_id);
int clua_callluacfunc(lua_State* L, lua_CFunction f);
lua_State* clua_newstate(void* goallocf);
lua_State* clua_newstatemem(unsigned int index, unsigned int limit);
unsigned int clua_memusage(unsigned int index);
unsigned int clua_memopcounter(unsigned int index);
void clua_freestatemem(unsigned int index);
void clua_setallocf(lua_State* L, void* goallocf);

void clua_openbase(lua_State* L);
void clua_openio(lua_State* L);
void clua_openmath(lua_State* L);
void clua_openpackage(lua_State* L);
void clua_openstring(lua_State* L);
void clua_opentable(lua_State* L);
void clua_openos(lua_State* L);
void clua_sethook(lua_State* L, int n);

int clua_isgofunction(lua_State *L, int n);
int clua_isgostruct(lua_State *L, int n);

