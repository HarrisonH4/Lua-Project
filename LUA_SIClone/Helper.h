#pragma once

#include <string>
#include <functional>
#include <map>

#ifdef _WIN32
#pragma comment (lib, "../lua-5.4.4/liblua54.a")
#endif

extern "C"
{
	#include "../lua-5.4.4/include/lua.h"
	#include "../lua-5.4.4/include/lauxlib.h"
	#include "../lua-5.4.4/include/lualib.h"
}

struct Vector2
{
	int x, y;

	void FromLua(lua_State* L, const std::string& name) {
		lua_getglobal(L, name.c_str());
		if (!lua_istable(L, -1))
			assert(false);

		lua_pushstring(L, "x");
		lua_gettable(L, -2);
		x = (int)lua_tointeger(L, -1);
		lua_pop(L, 1);

		lua_pushstring(L, "y");
		lua_gettable(L, -2);
		x = (int)lua_tointeger(L, -1);
		lua_pop(L, 1);
	}
};

bool LuaOK(lua_State* L, int id);
int LuaGetInt(lua_State* L, const std::string& name);
std::string LuaGetStr(lua_State* L, const std::string& name);

