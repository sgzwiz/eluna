#include <stdio.h>
//#include <vld.h>
#include <iostream>
#include <string.h>
#include "ELuna.h"

/*
class Monster {
public:
	Monster(lua_State *L) {
		printf("%s in constructor\n", name);
    }

	~Monster() {
		printf("%s in destructor\n", name);
	}

	int speak(lua_State *L) {
		const char *word = luaL_checkstring(L, 2);
		printf("speak: %s, %s\n", name, word);
		return 0;
	}

	int old;
	char name[];

	int getOld(lua_State *L) {
		printf("getOld: %s, %d\n", name, old);
	    lua_pushnumber(L, old);
		return 1;
	}

	int setOld(lua_State *L) {
	    const int value = (int)luaL_checknumber(L, 2);
		printf("setOld: %s, %d\n", name, value);
		old = value;
		return 0;
	}

	int setName(lua_State *L) {
        const char* value = luaL_checkstring(L, 2);
		printf("setName: %s, %s\n", value, name);
		strcpy(name, value);
		printf("setName end\n");
		return 0;
	}

	int getName(lua_State *L) {
		printf("getName: %s\n", name);
		lua_pushstring(L, name);
		return 1;
	}

	static const char className[];
	static const Luna<Monster>::RegType Register[];
};

const char Monster::className[] = "Monster";
const Luna<Monster>::RegType Monster::Register[] = {
    {"speak",   &Monster::speak},
    {"getOld",  &Monster::getOld},
    {"setOld",  &Monster::setOld},
    {"getName", &Monster::getName},
    {"setName", &Monster::setName},
    { 0 }
};

char *filename = "test.lua";

int main()
{
	lua_State *L = lua_open();

	luaopen_base(L);           // 加载Lua基本库
    luaL_openlibs(L);          // 加载Lua通用扩展库
    luaopen_debug(L);

    printf("Luna Register!\n");
	Luna<Monster>::Register(L);

    printf("luaL_loadfile!\n");
	if (luaL_loadfile(L, filename) || lua_pcall(L, 0, 0, 0))
    	printf("cannot run configuration file: %s", lua_tostring(L, -1));

	printf("lua executed!\n");

	lua_close(L);

} */

class Monster {
public:
	Monster(const char* value): old(1), name(value) {
		printf("%s, %s in ++constructor, he is %d years old\n", value, name, old);
    }

	~Monster() {
		printf("%s in ~~destructor, he is %d years old\n", name, old);
	}

	int speak(char* word) {
		printf("speak this : %p \n", this);
		printf("speak: %s, %s\n", name, word);
		return 0;
	}

	int speak1(char* word) {
		printf("speak~~~~~~~: %s, %s\n", name, word);
		return 0;
	}

	int old;
	const char* name;

	int getOld() {
		printf("getOld: %s, %d\n", name, old);
		return old;
	}

	int setOld(int value) {
		printf("setOld: %s, %d\n", name, value);
		old = value;
		return 0;
	}

	const char* getName() {
		return name;
	}
};

void foo() {
	printf("hello world\n");
}

void foo1(int a) {
	printf("hello world %d\n", a);
}


int initMethod(lua_State *L) {
    printf("------------start initMethod--------------\n");
	ELuna::registerClass<Monster>(L, "Monster", ELuna::constructor<Monster, char *>);
	ELuna::registerMethod<Monster>("speak", &Monster::speak);
	ELuna::registerMethod<Monster>("speak1", &Monster::speak1);
	ELuna::registerMethod<Monster>("getOld", &Monster::getOld);
	ELuna::registerMethod<Monster>("setOld", &Monster::setOld);
	ELuna::registerMethod<Monster>("getName", &Monster::getName);
	printf("------------end initMethod--------------\n");

	return 0;
}

int initFunction(lua_State *L) {
	printf("------------start initFunction--------------\n");
	ELuna::registerFunction(L, "foo", &foo);
	ELuna::registerFunction(L, "foo1", &foo1);
	printf("------------end initFunction--------------\n");

	return 0;
}

int testLuaFunction(lua_State* L) {
	ELuna::LuaFunction<int> luaFoo1(L, "luaFoo1");
	printf("Lua function run\n");
	int a = luaFoo1("testlua");
	printf("luaFoo1 result: %d\n", a);
	ELuna::LuaFunction<void> luaFoo2(L, "luaFoo2");
	printf("Lua function run\n");
	luaFoo2(1, 2);

	return 0;
}

const char *fileName = "test.lua";

int main()
{	
	lua_State *L = ELuna::openLua();

    initMethod(L);
	initFunction(L);

    printf("luaL_loadfile %s!\n", fileName);

	ELuna::doFile(L, fileName);

	printf("lua executed!\n");

	testLuaFunction(L);
	ELuna::closeLua(L);
	
	printf(" close !\n");
	system("pause");
    return 0;
}
