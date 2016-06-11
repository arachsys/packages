#ifndef luaconf_h
#define luaconf_h

#include <limits.h>
#include <stddef.h>

#define LUA_USE_POSIX
#define LUA_USE_DLOPEN
#define LUA_USE_READLINE
#define LUAI_BITSINT	32

#define LUA_ROOT	"/"
#define LUA_LDIR	LUA_ROOT "lib/lua/"
#define LUA_CDIR	LUA_ROOT "lib/lua/"
#define LUA_PATH_DEFAULT  \
		LUA_LDIR"?.lua;"  LUA_LDIR"?/init.lua;" \
		LUA_CDIR"?.lua;"  LUA_CDIR"?/init.lua;" \
		"./?.lua;" "./?/init.lua"
#define LUA_CPATH_DEFAULT \
		LUA_CDIR"?.so;" LUA_CDIR"loadall.so;" "./?.so"
#define LUA_DIRSEP	"/"

#define LUA_API		extern
#define LUALIB_API	LUA_API
#define LUAMOD_API	LUALIB_API

#define LUAI_FUNC	__attribute__((visibility("hidden"))) extern
#define LUAI_DDEC	LUAI_FUNC
#define LUAI_DDEF	/* empty */

#define l_floor(x)		(l_mathop(floor)(x))
#define lua_number2str(s,sz,n)	l_sprintf((s), sz, LUA_NUMBER_FMT, (n))
#define lua_numbertointeger(n,p) \
  ((n) >= (LUA_NUMBER)(LUA_MININTEGER) && \
   (n) < -(LUA_NUMBER)(LUA_MININTEGER) && \
      (*(p) = (LUA_INTEGER)(n), 1))

#define LUA_NUMBER	double
#define l_mathlim(n)		(DBL_##n)
#define LUAI_UACNUMBER	double
#define LUA_NUMBER_FRMLEN	""
#define LUA_NUMBER_FMT		"%.14g"
#define l_mathop(op)		op
#define lua_str2number(s,p)	strtod((s), (p))

#define LUA_INTEGER_FMT		"%" LUA_INTEGER_FRMLEN "d"
#define lua_integer2str(s,sz,n)	l_sprintf((s), sz, LUA_INTEGER_FMT, (n))
#define LUAI_UACINT		LUA_INTEGER
#define LUA_UNSIGNED		unsigned LUAI_UACINT
#define LUA_INTEGER		long long
#define LUA_INTEGER_FRMLEN	"ll"
#define LUA_MAXINTEGER		LLONG_MAX
#define LUA_MININTEGER		LLONG_MIN

#define l_sprintf(s,sz,f,i)	((void)(sz), sprintf(s,f,i))
#define lua_strx2number(s,p)		lua_str2number(s,p)
#define lua_number2strx(L,b,sz,f,n)	l_sprintf(b,sz,f,n)

#include <stdint.h>
#if defined(INTPTR_MAX)
#define LUA_KCONTEXT	intptr_t
#else
#define LUA_KCONTEXT	ptrdiff_t
#endif

#if !defined(lua_getlocaledecpoint)
#define lua_getlocaledecpoint()		(localeconv()->decimal_point[0])
#endif

#define LUAI_MAXSTACK		1000000
#define LUA_EXTRASPACE		(sizeof(void *))
#define LUA_IDSIZE	60
#define LUAL_BUFFERSIZE   ((int)(0x80 * sizeof(void*) * sizeof(lua_Integer)))

#define LUA_QL(x)	"'" x "'"
#define LUA_QS		LUA_QL("%s")

#endif
