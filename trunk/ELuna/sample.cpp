#include <stdio.h>
#include <string.h>
#include "ELuna.h"

//define a class
class CPPClass
{
public:
	CPPClass(const char* name): m_name(name){
		printf("%s Constructor!\n", name);
	}
	~CPPClass(){
		printf("%s Destructor!\n", m_name);
	}

	//define method
	void cppPrint(const char* word) {
		printf("%s: %s\n", m_name, word);
	}

	int cppSum(int a, int b){
		return a + b;
	}
private:
	const char* m_name;
};

//define function
void cppPrint(char* str) {
	printf("cppPrint: %s\n", str);
}

int cppSum(int a, int b){
	return a + b;
}

void testCPP(lua_State* L) {
	//register a class and it's constructor. indicate all constructor's param type
	ELuna::registerClass<CPPClass>(L, "CPPClass", ELuna::constructor<CPPClass, const char* >);
	//register a method
	ELuna::registerMethod<CPPClass>("cppPrint", &CPPClass::cppPrint);
	ELuna::registerMethod<CPPClass>("cppSum", &CPPClass::cppSum);

	//register a function
	ELuna::registerFunction(L, "cppPrint", &cppPrint);
	ELuna::registerFunction(L, "cppSum", &cppSum);
}

void testLua(lua_State* L) {
	//new a LuaFunction object to bind lua function. indicate return value type
	ELuna::LuaFunction<void> luaPrint(L, "luaPrint");
	ELuna::LuaFunction<int> luaSum(L, "luaSum");

	//run Luafunction's () to call lua function
	luaPrint("hello world");
	printf("luaSum: ", luaSum(1,2));
}

const char *fileName = "sample.lua";

int main()
{
	lua_State *L = ELuna::openLua();

	testCPP(L);

	ELuna::doFile(L, fileName);

	testLua(L);
	ELuna::closeLua(L);

	system("pause");
	return 0;
}