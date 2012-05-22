#include <stdio.h>
#include <string.h>
#include "ELuna.h"

class Test
{
public:
	Test() { 
		printf(" Test0 Constructor!\n");
	}

	~Test() { printf(" Test Destructor!\n");}

	void foo0() {
		printf("foo0: \n");
	}

	void foo1(int p1) {
		printf("foo1: %d\n", p1);
	}

	void foo2(int p1, int p2) {
		printf("foo2: %d %d\n", p1, p2);
	}

	void foo3(int p1, int p2, int p3) {
		printf("foo3: %d %d %d\n", p1, p2, p3);
	}

	void foo4(int p1, int p2, int p3, int p4) {
		printf("foo4: %d %d %d %d\n", p1, p2, p3, p4);
	}

	void foo5(int p1, int p2, int p3, int p4, int p5) {
		printf("foo5: %d %d %d %d %d\n", p1, p2, p3, p4, p5);
	}

	void foo6(int p1, int p2, int p3, int p4, int p5, int p6) {
		printf("foo6: %d %d %d %d %d %d\n", p1, p2, p3, p4, p5, p6);
	}

	void foo7(int p1, int p2, int p3, int p4, int p5, int p6, int p7) {
		printf("foo7: %d %d %d %d %d %d %d\n", p1, p2, p3, p4, p5, p6, p7);
	}

	void foo8(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8) {
		printf("foo8: %d %d %d %d %d %d %d %d\n", p1, p2, p3, p4, p5, p6, p7, p8);
	}

	void foo9(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9) {
		printf("foo9: %d %d %d %d %d %d %d %d\n", p1, p2, p3, p4, p5, p6, p7, p8, p9);
	}

	int retFoo0() {
		return 0;
	}

	int retFoo1(int p1) {
		return p1;
	}

	int retFoo2(int p1, int p2) {
		return p1 + p2;
	}

	int retFoo3(int p1, int p2, int p3) {
		return p1 + p2 + p3;
	}

	int retFoo4(int p1, int p2, int p3, int p4) {
		return p1 + p2 + p3 + p4;
	}

	int retFoo5(int p1, int p2, int p3, int p4, int p5) {
		return p1 + p2 + p3 + p4 + p5;
	}

	int retFoo6(int p1, int p2, int p3, int p4, int p5, int p6) {
		return p1 + p2 + p3 + p4 + p5 + p6;
	}

	int retFoo7(int p1, int p2, int p3, int p4, int p5, int p6, int p7) {
		return p1 + p2 + p3 + p4 + p5 + p6 + p7;
	}

	int retFoo8(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8) {
		return p1 + p2 + p3 + p4 + p5 + p6 + p7 + p8;
	}

	int retFoo9(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9) {
		return p1 + p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9;
	}

	bool testBool(bool p) {
		return p;
	}

	char* testPChar(char* p) {
		return p;
	}

	const char* testPConstChar(const char* p) {
		return p;
	}

	char testChar(char p) {
		return p;
	}

	unsigned char testUChar(unsigned char p) {
		return p;
	}

	short testShort(short p) {
		return p;
	}

	unsigned short testUShort(unsigned short p) {
		return p;
	}

	long testLong(long p) {
		return p;
	}

	unsigned long testULong(unsigned long p) {
		return p;
	}

	unsigned int testUInt(unsigned int p) {
		return p;
	}

	long long testLongLong(long long p) {
		return p;
	}

	unsigned long long testULongLong(unsigned long long p) {
		return p;
	}
	
	float testFloat(float p) {
		return p;
	}

	double testDouble(double p) {
		return p;
	}
	
	ELuna::LuaString testLuaString(ELuna::LuaString p) {
		return p;
	}
private:
};

class Test1
{
public:
	Test1(int p1) { 
		printf(" Test1 Constructor! %d\n", p1);
	}

	~Test1() { printf(" Test1 Destructor!\n");}
};

class Test2
{
public:
	Test2(int p1, int p2) { 
		printf(" Test2 Constructor! %d %d\n", p1, p2);
	}

	~Test2() { printf(" Test2 Destructor!\n");}
};

class Test3
{
public:
	Test3(int p1, int p2, int p3) { 
		printf(" Test3 Constructor! %d %d %d\n", p1, p2, p3);
	}

	~Test3() { printf(" Test3 Destructor!\n");}
};

class Test4
{
public:
	Test4(int p1, int p2, int p3, int p4) { 
		printf(" Test4 Constructor! %d %d %d %d\n", p1, p2, p3, p4);
	}

	~Test4() { printf(" Test4 Destructor!\n");}
};

class Test5
{
public:
	Test5(int p1, int p2, int p3, int p4, int p5) { 
		printf(" Test5 Constructor! %d %d %d %d %d\n", p1, p2, p3, p4, p5);
	}

	~Test5() { printf(" Test5 Destructor!\n");}
};

class Test6
{
public:
	Test6(int p1, int p2, int p3, int p4, int p5, int p6) { 
		printf(" Test6 Constructor! %d %d %d %d %d %d\n", p1, p2, p3, p4, p5, p6);
	}

	~Test6() { printf(" Test6 Destructor!\n");}
};

class Test7
{
public:
	Test7(int p1, int p2, int p3, int p4, int p5, int p6, int p7) { 
		printf(" Test7 Constructor! %d %d %d %d %d %d %d\n", p1, p2, p3, p4, p5, p6, p7);
	}

	~Test7() { printf(" Test7 Destructor!\n");}
};

class Test8
{
public:
	Test8(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8) { 
		printf(" Test8 Constructor! %d %d %d %d %d %d %d %d\n", p1, p2, p3, p4, p5, p6, p7, p8);
	}

	~Test8() { printf(" Test8 Destructor!\n");}
};

class Test9
{
public:
	Test9(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9) { 
		printf(" Test9 Constructor! %d %d %d %d %d %d %d %d %d\n", p1, p2, p3, p4, p5, p6, p7, p8, p9);
	}

	~Test9() { printf(" Test9 Destructor!\n");}
};

void foo0() {
	printf("foo0: \n");
}

void foo1(int p1) {
	printf("foo1: %d\n", p1);
}

void foo2(int p1, int p2) {
	printf("foo2: %d %d\n", p1, p2);
}

void foo3(int p1, int p2, int p3) {
	printf("foo3: %d %d %d\n", p1, p2, p3);
}

void foo4(int p1, int p2, int p3, int p4) {
	printf("foo4: %d %d %d %d\n", p1, p2, p3, p4);
}

void foo5(int p1, int p2, int p3, int p4, int p5) {
	printf("foo5: %d %d %d %d %d\n", p1, p2, p3, p4, p5);
}

void foo6(int p1, int p2, int p3, int p4, int p5, int p6) {
	printf("foo6: %d %d %d %d %d %d\n", p1, p2, p3, p4, p5, p6);
}

void foo7(int p1, int p2, int p3, int p4, int p5, int p6, int p7) {
	printf("foo7: %d %d %d %d %d %d %d\n", p1, p2, p3, p4, p5, p6, p7);
}

void foo8(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8) {
	printf("foo8: %d %d %d %d %d %d %d %d\n", p1, p2, p3, p4, p5, p6, p7, p8);
}

void foo9(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9) {
	printf("foo9: %d %d %d %d %d %d %d %d\n", p1, p2, p3, p4, p5, p6, p7, p8, p9);
}

int retFoo0() {
	return 0;
}

int retFoo1(int p1) {
	return p1;
}

int retFoo2(int p1, int p2) {
	return p1 + p2;
}

int retFoo3(int p1, int p2, int p3) {
	return p1 + p2 + p3;
}

int retFoo4(int p1, int p2, int p3, int p4) {
	return p1 + p2 + p3 + p4;
}

int retFoo5(int p1, int p2, int p3, int p4, int p5) {
	return p1 + p2 + p3 + p4 + p5;
}

int retFoo6(int p1, int p2, int p3, int p4, int p5, int p6) {
	return p1 + p2 + p3 + p4 + p5 + p6;
}

int retFoo7(int p1, int p2, int p3, int p4, int p5, int p6, int p7) {
	return p1 + p2 + p3 + p4 + p5 + p6 + p7;
}

int retFoo8(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8) {
	return p1 + p2 + p3 + p4 + p5 + p6 + p7 + p8;
}

int retFoo9(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9) {
	return p1 + p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9;
}

void testCPP(lua_State* L) {
	//register a class and it's constructor. indicate all constructor's param type
	ELuna::registerClass<Test>(L, "Test", ELuna::constructor<Test>);
	//register a method
	ELuna::registerMethod<Test>("foo0", &Test::foo0);
	ELuna::registerMethod<Test>("foo1", &Test::foo1);
	ELuna::registerMethod<Test>("foo2", &Test::foo2);
	ELuna::registerMethod<Test>("foo3", &Test::foo3);
	ELuna::registerMethod<Test>("foo4", &Test::foo4);
	ELuna::registerMethod<Test>("foo5", &Test::foo5);
	ELuna::registerMethod<Test>("foo6", &Test::foo6);
	ELuna::registerMethod<Test>("foo7", &Test::foo7);
	ELuna::registerMethod<Test>("foo8", &Test::foo8);
	ELuna::registerMethod<Test>("foo9", &Test::foo9);

	ELuna::registerMethod<Test>("retFoo0", &Test::retFoo0);
	ELuna::registerMethod<Test>("retFoo1", &Test::retFoo1);
	ELuna::registerMethod<Test>("retFoo2", &Test::retFoo2);
	ELuna::registerMethod<Test>("retFoo3", &Test::retFoo3);
	ELuna::registerMethod<Test>("retFoo4", &Test::retFoo4);
	ELuna::registerMethod<Test>("retFoo5", &Test::retFoo5);
	ELuna::registerMethod<Test>("retFoo6", &Test::retFoo6);
	ELuna::registerMethod<Test>("retFoo7", &Test::retFoo7);
	ELuna::registerMethod<Test>("retFoo8", &Test::retFoo8);
	ELuna::registerMethod<Test>("retFoo9", &Test::retFoo9);

	//test read2cpp and push2lua
	ELuna::registerMethod<Test>("testBool", &Test::testBool);
	ELuna::registerMethod<Test>("testChar", &Test::testChar);
	ELuna::registerMethod<Test>("testDouble", &Test::testDouble);
	ELuna::registerMethod<Test>("testFloat", &Test::testFloat);
	ELuna::registerMethod<Test>("testLong", &Test::testLong);
	ELuna::registerMethod<Test>("testLongLong", &Test::testLongLong);
	ELuna::registerMethod<Test>("testLuaString", &Test::testLuaString);
	ELuna::registerMethod<Test>("testPChar", &Test::testPChar);
	ELuna::registerMethod<Test>("testPConstChar", &Test::testPConstChar);
	ELuna::registerMethod<Test>("testShort", &Test::testShort);
	ELuna::registerMethod<Test>("testUChar", &Test::testUChar);
	ELuna::registerMethod<Test>("testUInt", &Test::testUInt);
	ELuna::registerMethod<Test>("testULong", &Test::testULong);
	ELuna::registerMethod<Test>("testULongLong", &Test::testULongLong);
	ELuna::registerMethod<Test>("testUShort", &Test::testUShort);

	//register a function
	ELuna::registerFunction(L, "foo0", &foo0);
	ELuna::registerFunction(L, "foo1", &foo1);
	ELuna::registerFunction(L, "foo2", &foo2);
	ELuna::registerFunction(L, "foo3", &foo3);
	ELuna::registerFunction(L, "foo4", &foo4);
	ELuna::registerFunction(L, "foo5", &foo5);
	ELuna::registerFunction(L, "foo6", &foo6);
	ELuna::registerFunction(L, "foo7", &foo7);
	ELuna::registerFunction(L, "foo8", &foo8);
	ELuna::registerFunction(L, "foo9", &foo9);

	//test constructor
	ELuna::registerClass<Test1>(L, "Test1", ELuna::constructor<Test1, int>);
	ELuna::registerClass<Test2>(L, "Test2", ELuna::constructor<Test2, int, int>);
	ELuna::registerClass<Test3>(L, "Test3", ELuna::constructor<Test3, int, int, int>);
	ELuna::registerClass<Test4>(L, "Test4", ELuna::constructor<Test4, int, int, int, int>);
	ELuna::registerClass<Test5>(L, "Test5", ELuna::constructor<Test5, int, int, int, int, int>);
	ELuna::registerClass<Test6>(L, "Test6", ELuna::constructor<Test6, int, int, int, int, int, int>);
	ELuna::registerClass<Test7>(L, "Test7", ELuna::constructor<Test7, int, int, int, int, int, int, int>);
	ELuna::registerClass<Test8>(L, "Test8", ELuna::constructor<Test8, int, int, int, int, int, int, int, int>);
	ELuna::registerClass<Test9>(L, "Test9", ELuna::constructor<Test9, int, int, int, int, int, int, int, int, int>);
}

void testLua(lua_State* L) {
	printf("------------testLua------------\n");
	ELuna::LuaFunction<void> foo0(L, "foo0");
	ELuna::LuaFunction<void> foo1(L, "foo1");
	ELuna::LuaFunction<void> foo2(L, "foo2");
	ELuna::LuaFunction<void> foo3(L, "foo3");
	ELuna::LuaFunction<void> foo4(L, "foo4");
	ELuna::LuaFunction<void> foo5(L, "foo5");
	ELuna::LuaFunction<void> foo6(L, "foo6");
	ELuna::LuaFunction<void> foo7(L, "foo7");
	ELuna::LuaFunction<void> foo8(L, "foo8");
	ELuna::LuaFunction<void> foo9(L, "foo9");

	ELuna::LuaFunction<int> retFoo0(L, "retFoo0");
	ELuna::LuaFunction<int> retFoo1(L, "retFoo1");
	ELuna::LuaFunction<int> retFoo2(L, "retFoo2");
	ELuna::LuaFunction<int> retFoo3(L, "retFoo3");
	ELuna::LuaFunction<int> retFoo4(L, "retFoo4");
	ELuna::LuaFunction<int> retFoo5(L, "retFoo5");
	ELuna::LuaFunction<int> retFoo6(L, "retFoo6");
	ELuna::LuaFunction<int> retFoo7(L, "retFoo7");
	ELuna::LuaFunction<int> retFoo8(L, "retFoo8");
	ELuna::LuaFunction<int> retFoo9(L, "retFoo9");

	foo0();
	foo1(1);
	foo2(1,2);
	foo3(1,2,3);
	foo4(1,2,3,4);
	foo5(1,2,3,4,5);
	foo6(1,2,3,4,5,6);
	foo7(1,2,3,4,5,6,7);
	foo8(1,2,3,4,5,6,7,8);
	foo9(1,2,3,4,5,6,7,8,9);

	printf("retFoo0: %d\n", retFoo0());
	printf("retFoo1: %d\n", retFoo1(1));
	printf("retFoo2: %d\n", retFoo2(1,2));
	printf("retFoo3: %d\n", retFoo3(1,2,3));
	printf("retFoo4: %d\n", retFoo4(1,2,3,4));
	printf("retFoo5: %d\n", retFoo5(1,2,3,4,5));
	printf("retFoo6: %d\n", retFoo6(1,2,3,4,5,6));
	printf("retFoo7: %d\n", retFoo7(1,2,3,4,5,6,7));
	printf("retFoo8: %d\n", retFoo8(1,2,3,4,5,6,7,8));
	printf("retFoo9: %d\n", retFoo9(1,2,3,4,5,6,7,8,9));
}


const char *fileName = "testInterface.lua";
void main()
{
	lua_State *L = ELuna::openLua();

	testCPP(L);

	ELuna::doFile(L, fileName);

	testLua(L);
	ELuna::closeLua(L);

	system("pause");
}