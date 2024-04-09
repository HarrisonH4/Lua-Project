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
bool LuaOK(lua_State* L, int id);
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
		y = (int)lua_tointeger(L, -1);
		lua_pop(L, 1);
	}
};

void CallVoidVoidCFunc(lua_State* L, const std::string& fname)
{
	lua_getglobal(L, fname.c_str());
	if (!lua_isfunction(L, -1))
		assert(false);
	if (!LuaOK(L, lua_pcall(L, 0, 0, 0)))
		assert(false);
}

int CallRandomNumber(lua_State* L, const std::string& fname);

void CallmoveRight(lua_State* L, const std::string& fname, float& xVal, float& frameVal);
void CallmoveLeft(lua_State* L, const std::string& fname, float& xVal, float& frameVal);


int LuaGetInt(lua_State* L, const std::string& name);
std::string LuaGetStr(lua_State* L, const std::string& name);

