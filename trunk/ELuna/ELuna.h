// Copyright (c) 2012 rick
//
// ELuna - Extense Luna
/////////////////////////////////////////////////////////////////////


#ifndef _LUA_ELUNA_H_
#define _LUA_ELUNA_H_

#include <new>
#include <map>
#include <vector>
#include <string.h>
#include <assert.h>

extern "C" {
#include "..\lua\lua.h"
#include "..\lua\lualib.h"
#include "..\lua\lauxlib.h"
}

namespace ELuna
{

	struct LuaString
	{
		const char* str;
		size_t len;
	};

	///////////////////////////////////////////////////////////////////////////////
	// read a value from lua to cpp
	///////////////////////////////////////////////////////////////////////////////
	template<typename T> inline T   read2cpp(lua_State *L, int index) { printf("param type error!\n"); assert(0);};
	template<>	inline bool         read2cpp(lua_State *L, int index) { if(lua_isboolean(L, index)) return lua_toboolean(L, index) != 0; else return lua_tonumber(L, index) != 0;};
	template<>	inline char*		read2cpp(lua_State *L, int index) { return (char*)lua_tostring(L, index); };
	template<>	inline const char*	read2cpp(lua_State *L, int index) { return (const char*)lua_tostring(L, index);};
	template<>	inline char			read2cpp(lua_State *L, int index) { return (char)lua_tonumber(L, index);};
	template<>	inline unsigned char  read2cpp(lua_State *L, int index) { return (unsigned char)lua_tonumber(L, index);};
	template<>	inline short		read2cpp(lua_State *L, int index) { return (short)lua_tonumber(L, index);};
	template<>	inline unsigned short read2cpp(lua_State *L, int index) { return (unsigned short)lua_tonumber(L, index);};
	template<>	inline long			read2cpp(lua_State *L, int index) { return (long)lua_tonumber(L, index);}; 
	template<>	inline unsigned long  read2cpp(lua_State *L, int index) { return (unsigned long)lua_tonumber(L, index);};
	template<>	inline int			read2cpp(lua_State *L, int index) { return (int)lua_tonumber(L, index);};
	template<>	inline unsigned int	read2cpp(lua_State *L, int index) { return (unsigned int)lua_tonumber(L, index);};
	template<>	inline long long    read2cpp(lua_State *L, int index) { return (long long)lua_tonumber(L, index);};
	template<>  inline unsigned long long  read2cpp(lua_State *L, int index) { return (unsigned long long)lua_tonumber(L, index);};
	template<>	inline float		read2cpp(lua_State *L, int index) { return (float)lua_tonumber(L, index);};
	template<>	inline double		read2cpp(lua_State *L, int index) { return (double)lua_tonumber(L, index);};
	template<>	inline void			read2cpp(lua_State *L, int index) { return;}; 
	//template<>	table				read2cpp(lua_State *L, int index);
	template<>	inline LuaString	read2cpp(lua_State *L, int index) { LuaString ls; ls.str = (char*)lua_tolstring(L, index, &ls.len); return ls;};
	
	///////////////////////////////////////////////////////////////////////////////
	// push a value from cpp to lua
	///////////////////////////////////////////////////////////////////////////////
	template<typename T> inline void push2lua(lua_State *L, T ret) { printf("return type error!\n"); assert(0);};
	template<> inline void push2lua(lua_State *L, char ret) { lua_pushnumber(L, ret);};
	template<> inline void push2lua(lua_State *L, unsigned char ret) { lua_pushnumber(L, ret);};
	template<> inline void push2lua(lua_State *L, short ret) { lua_pushnumber(L, ret);};
	template<> inline void push2lua(lua_State *L, unsigned short ret) { lua_pushnumber(L, ret);};
	template<> inline void push2lua(lua_State *L, long ret) { lua_pushnumber(L, ret);};
	template<> inline void push2lua(lua_State *L, unsigned long ret) { lua_pushnumber(L, ret);};
	template<> inline void push2lua(lua_State *L, int ret) { lua_pushnumber(L, ret);};
	template<> inline void push2lua(lua_State *L, unsigned int ret) { lua_pushnumber(L, ret);};
	template<> inline void push2lua(lua_State *L, float ret) { lua_pushnumber(L, ret);};
	template<> inline void push2lua(lua_State *L, double ret) { lua_pushnumber(L, ret);};
	template<> inline void push2lua(lua_State *L, char* ret) { lua_pushstring(L, ret);};
	template<> inline void push2lua(lua_State *L, const char* ret) { lua_pushstring(L, ret);};
	template<> inline void push2lua(lua_State *L, bool ret) { lua_pushboolean(L, ret);};
	template<> inline void push2lua(lua_State *L, long long ret) { return lua_pushnumber(L, (LUA_NUMBER)ret);};
	template<> inline void push2lua(lua_State *L, unsigned long long ret) { return lua_pushnumber(L, (LUA_NUMBER)ret);};
	template<> inline void push2lua(lua_State *L, LuaString ret) {lua_pushlstring(L, ret.str, ret.len);};


	///////////////////////////////////////////////////////////////////////////////
	// bind cpp method 
	///////////////////////////////////////////////////////////////////////////////
	#define ELUNA_METHODCLASSES_PARAM_LIST_0 typename T
	#define ELUNA_METHODCLASSES_PARAM_LIST_1 ELUNA_METHODCLASSES_PARAM_LIST_0, typename P1
	#define ELUNA_METHODCLASSES_PARAM_LIST_2 ELUNA_METHODCLASSES_PARAM_LIST_1, typename P2
	#define ELUNA_METHODCLASSES_PARAM_LIST_3 ELUNA_METHODCLASSES_PARAM_LIST_2, typename P3
	#define ELUNA_METHODCLASSES_PARAM_LIST_4 ELUNA_METHODCLASSES_PARAM_LIST_3, typename P4
	#define ELUNA_METHODCLASSES_PARAM_LIST_5 ELUNA_METHODCLASSES_PARAM_LIST_4, typename P5
	#define ELUNA_METHODCLASSES_PARAM_LIST_6 ELUNA_METHODCLASSES_PARAM_LIST_5, typename P6
	#define ELUNA_METHODCLASSES_PARAM_LIST_7 ELUNA_METHODCLASSES_PARAM_LIST_6, typename P7
	#define ELUNA_METHODCLASSES_PARAM_LIST_8 ELUNA_METHODCLASSES_PARAM_LIST_7, typename P8
	#define ELUNA_METHODCLASSES_PARAM_LIST_9 ELUNA_METHODCLASSES_PARAM_LIST_8, typename P9
	#define ELUNA_METHODCLASSES_SP_PARAM_LIST_0 T
	#define ELUNA_METHODCLASSES_SP_PARAM_LIST_1 ELUNA_METHODCLASSES_SP_PARAM_LIST_0, P1
	#define ELUNA_METHODCLASSES_SP_PARAM_LIST_2 ELUNA_METHODCLASSES_SP_PARAM_LIST_1, P2
	#define ELUNA_METHODCLASSES_SP_PARAM_LIST_3 ELUNA_METHODCLASSES_SP_PARAM_LIST_2, P3
	#define ELUNA_METHODCLASSES_SP_PARAM_LIST_4 ELUNA_METHODCLASSES_SP_PARAM_LIST_3, P4
	#define ELUNA_METHODCLASSES_SP_PARAM_LIST_5 ELUNA_METHODCLASSES_SP_PARAM_LIST_4, P5
	#define ELUNA_METHODCLASSES_SP_PARAM_LIST_6 ELUNA_METHODCLASSES_SP_PARAM_LIST_5, P6
	#define ELUNA_METHODCLASSES_SP_PARAM_LIST_7 ELUNA_METHODCLASSES_SP_PARAM_LIST_6, P7
	#define ELUNA_METHODCLASSES_SP_PARAM_LIST_8 ELUNA_METHODCLASSES_SP_PARAM_LIST_7, P8
	#define ELUNA_METHODCLASSES_SP_PARAM_LIST_9 ELUNA_METHODCLASSES_SP_PARAM_LIST_8, P9
	#define ELUNA_PARAM_LIST_0
	#define ELUNA_PARAM_LIST_1 ELUNA_PARAM_LIST_0  P1
	#define ELUNA_PARAM_LIST_2 ELUNA_PARAM_LIST_1, P2
	#define ELUNA_PARAM_LIST_3 ELUNA_PARAM_LIST_2, P3
	#define ELUNA_PARAM_LIST_4 ELUNA_PARAM_LIST_3, P4
	#define ELUNA_PARAM_LIST_5 ELUNA_PARAM_LIST_4, P5
	#define ELUNA_PARAM_LIST_6 ELUNA_PARAM_LIST_5, P6
	#define ELUNA_PARAM_LIST_7 ELUNA_PARAM_LIST_6, P7
	#define ELUNA_PARAM_LIST_8 ELUNA_PARAM_LIST_7, P8
	#define ELUNA_PARAM_LIST_9 ELUNA_PARAM_LIST_8, P9
	#define ELUNA_READ_PARAM_LIST_0
	#define ELUNA_READ_PARAM_LIST_1 ELUNA_READ_PARAM_LIST_0  read2cpp<P1>(L,2)
	#define ELUNA_READ_PARAM_LIST_2 ELUNA_READ_PARAM_LIST_1, read2cpp<P2>(L,3)
	#define ELUNA_READ_PARAM_LIST_3 ELUNA_READ_PARAM_LIST_2, read2cpp<P3>(L,4)
	#define ELUNA_READ_PARAM_LIST_4 ELUNA_READ_PARAM_LIST_3, read2cpp<P4>(L,5)
	#define ELUNA_READ_PARAM_LIST_5 ELUNA_READ_PARAM_LIST_4, read2cpp<P5>(L,6)
	#define ELUNA_READ_PARAM_LIST_6 ELUNA_READ_PARAM_LIST_5, read2cpp<P6>(L,7)
	#define ELUNA_READ_PARAM_LIST_7 ELUNA_READ_PARAM_LIST_6, read2cpp<P7>(L,8)
	#define ELUNA_READ_PARAM_LIST_8 ELUNA_READ_PARAM_LIST_7, read2cpp<P8>(L,9)
	#define ELUNA_READ_PARAM_LIST_9 ELUNA_READ_PARAM_LIST_8, read2cpp<P9>(L,10)

	struct GenericMethod
	{
	public:
		virtual ~GenericMethod() {};
		GenericMethod() {};

		virtual int call(lua_State *L) { return 0;};
		virtual inline const char* getMethodName(){ return m_name;};

	private:
		const char* m_name;
	};

	#define ELUNA_MAKE_METHODCLASSX(N)\
	template<typename RL, ELUNA_METHODCLASSES_PARAM_LIST_##N >\
	struct MethodClass##N : GenericMethod\
	{\
		typedef RL (T::* TFUNC)(ELUNA_PARAM_LIST_##N);\
		TFUNC m_func;\
		const char* m_name;\
		MethodClass##N( const char* name, TFUNC func):m_name(name),m_func(func) {};\
		~MethodClass##N(){ printf("method releace %s\n", m_name);};\
		virtual inline const char* getMethodName(){ return m_name;};\
		virtual int call(lua_State *L)\
		{\
			lua_pushnumber(L, 0);\
			lua_rawget(L, 1); \
			T** obj = (T**)lua_touserdata(L, -1);\
			push2lua(L, ((*obj)->*(m_func))(ELUNA_READ_PARAM_LIST_##N));\
			return 1;\
		};\
	};

	#define ELUNA_MAKE_VOID_RL_METHODCLASSX(N) \
	template<ELUNA_METHODCLASSES_PARAM_LIST_##N >\
	struct MethodClass##N<void, ELUNA_METHODCLASSES_SP_PARAM_LIST_##N> : GenericMethod\
	{\
		typedef void (T::* TFUNC)(ELUNA_PARAM_LIST_##N);\
		TFUNC m_func;\
		const char* m_name;\
		MethodClass##N( const char* name, TFUNC func):m_name(name),m_func(func) {};\
		~MethodClass##N(){ printf("method releace %s\n", m_name);};\
		virtual inline const char* getMethodName(){ return m_name;};\
		virtual int call(lua_State *L)\
		{\
			lua_pushnumber(L, 0);\
			lua_rawget(L, 1);\
			T** obj = (T**)lua_touserdata(L, -1);\
			((*obj)->*(m_func))(ELUNA_READ_PARAM_LIST_##N);\
			return 0;\
		};\
	};

	ELUNA_MAKE_METHODCLASSX(0)
	ELUNA_MAKE_METHODCLASSX(1)
	ELUNA_MAKE_METHODCLASSX(2)
	ELUNA_MAKE_METHODCLASSX(3)
	ELUNA_MAKE_METHODCLASSX(4)
	ELUNA_MAKE_METHODCLASSX(5)
	ELUNA_MAKE_METHODCLASSX(6)
	ELUNA_MAKE_METHODCLASSX(7)
	ELUNA_MAKE_METHODCLASSX(8)
	ELUNA_MAKE_METHODCLASSX(9)

	ELUNA_MAKE_VOID_RL_METHODCLASSX(0)
	ELUNA_MAKE_VOID_RL_METHODCLASSX(1)
	ELUNA_MAKE_VOID_RL_METHODCLASSX(2)
	ELUNA_MAKE_VOID_RL_METHODCLASSX(3)
	ELUNA_MAKE_VOID_RL_METHODCLASSX(4)
	ELUNA_MAKE_VOID_RL_METHODCLASSX(5)
	ELUNA_MAKE_VOID_RL_METHODCLASSX(6)
	ELUNA_MAKE_VOID_RL_METHODCLASSX(7)
	ELUNA_MAKE_VOID_RL_METHODCLASSX(8)
	ELUNA_MAKE_VOID_RL_METHODCLASSX(9)

	typedef std::vector<GenericMethod*> Method_Vector;
	
	class ProxyClass
	{
	public:
		ProxyClass(){};
		~ProxyClass() {
			printf("~~~~~~~~~ProxyClass\n");
			for (Method_Vector::iterator itr = m_methods.begin(); itr != m_methods.end(); ++itr)
			{
				printf("~~~~~~~~~~~methods %p\n", *itr);
			}
			for (Method_Vector::iterator itr = m_methods.begin(); itr != m_methods.end(); ++itr)
			{
				delete *itr;
			}
		}

		inline GenericMethod* getMethod(const int index) { return m_methods[index];};
		inline int getMethodsCount() {return m_methods.size();};
		inline void pushMethod(GenericMethod* method) { m_methods.push_back(method);};
		
		template<typename T>
		static inline const char* className(const char* name = NULL)
		{
			static const char* _name;
			if(name) _name = name;
			printf("class_name2 %s, %s\n ", _name, name);
			return _name;
		}
	private:
		Method_Vector m_methods;
	};

	typedef std::map<const char*, ProxyClass*> CPPClassesT;
	CPPClassesT m_CPPClasses;
	inline ProxyClass* getProxyClass(const char* name) { return m_CPPClasses[name];};
	inline void insertProxyClass(const char* name, ProxyClass* pClass) {m_CPPClasses.insert(std::pair<const char*, ProxyClass*>(name, pClass));};
	inline void releaseClass() {
		printf("-----releaseClass-------\n");
		for (CPPClassesT::iterator itr = m_CPPClasses.begin(); itr != m_CPPClasses.end(); ++itr) {
			printf("methods %s : %p\n", itr->first, (itr->second));
			delete (itr->second);
		}
	}

    template<typename T, typename F>
    inline void registerClass(lua_State *L, const char* name, F func) {
        printf("Register name %s Lua_State %p\n", name, L);
		ProxyClass::className<T>(name);
        ProxyClass* pClass = new ProxyClass();
		insertProxyClass(name, pClass);

        lua_pushcfunction(L, func);
        lua_setglobal(L, name); 

        registerMetatable<T>(L, name);
    }


	template<typename T>
    inline void registerMetatable(lua_State *L, const char *name) {
        printf("Register Metatable %s\n", name);
        luaL_newmetatable(L, name ); // create a metatable in the registry
        printf("RegisterMetatable %s    %s    %s    %p\n", name, ProxyClass::className<T>(), luaL_typename(L, -1), lua_topointer(L, -1));

        lua_pushstring(L, "__gc");
        lua_pushcfunction(L, &gc_obj<T>);
        lua_rawset(L, -3); // metatable["__gc"] = Luna<T>::gc_obj
        lua_pop(L, 1);
    }

	template<typename T>
	inline int constructor(lua_State *L)
	{   
		return inject<T>(L, new T());
	}

    template<typename T, typename P1>
    inline int constructor(lua_State *L)
    {   
        return inject<T>(L, new T(read2cpp<P1>(L,1)));
    }

    template<typename T, typename P1, typename P2>
    inline int constructor(lua_State *L)
    {
        return inject<T>(L, new T(read2cpp<P1>(L,1), read2cpp<P2>(L,2)));
    }

    template<typename T, typename P1, typename P2, typename P3>
    inline int constructor(lua_State *L)
    {
        return inject<T>(L, new T(read2cpp<P1>(L,1), read2cpp<P2>(L,2), read2cpp<P3>(L,3)));
    }

	template<typename T, typename P1, typename P2, typename P3, typename P4>
	inline int constructor(lua_State *L)
	{
		return inject<T>(L, new T(read2cpp<P1>(L,1), read2cpp<P2>(L,2), read2cpp<P3>(L,3), read2cpp<P4>(L,4)));
	}

	template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5>
	inline int constructor(lua_State *L)
	{
		return inject<T>(L, new T(read2cpp<P1>(L,1), read2cpp<P2>(L,2), read2cpp<P3>(L,3), read2cpp<P4>(L,4), read2cpp<P5>(L,5)));
	}

	template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
	inline int constructor(lua_State *L)
	{
		return inject<T>(L, new T(read2cpp<P1>(L,1), read2cpp<P2>(L,2), read2cpp<P3>(L,3), read2cpp<P4>(L,4), read2cpp<P5>(L,5), read2cpp<P6>(L,6)));
	}

	template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
	inline int constructor(lua_State *L)
	{
		return inject<T>(L, new T(read2cpp<P1>(L,1), read2cpp<P2>(L,2), read2cpp<P3>(L,3), read2cpp<P4>(L,4), read2cpp<P5>(L,5), read2cpp<P6>(L,6), read2cpp<P7>(L,7)));
	}

	template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
	inline int constructor(lua_State *L)
	{
		return inject<T>(L, new T(read2cpp<P1>(L,1), read2cpp<P2>(L,2), read2cpp<P3>(L,3), read2cpp<P4>(L,4), read2cpp<P5>(L,5), read2cpp<P6>(L,6), read2cpp<P7>(L,7), read2cpp<P8>(L,8)));
	}

	template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
	inline int constructor(lua_State *L)
	{
		return inject<T>(L, new T(read2cpp<P1>(L,1), read2cpp<P2>(L,2), read2cpp<P3>(L,3), read2cpp<P4>(L,4), read2cpp<P5>(L,5), read2cpp<P6>(L,6), read2cpp<P7>(L,7), read2cpp<P8>(L,8), read2cpp<P9>(L,9)));
	}

	template<typename T>
	int inject(lua_State *L, T* obj) {
		lua_newtable(L); // create a new table for the class object ('self')

		lua_pushnumber(L, 0);

		T** a = static_cast<T**>(lua_newuserdata(L, sizeof(T*))); // store a ptr to the ptr
		*a = obj; // set the ptr to the ptr to point to the ptr... >.>
		//luaL_newmetatable(L, T::className); // get (or create) the unique metatable
		const char* className = ProxyClass::className<T>();
		luaL_getmetatable(L, className);
		lua_setmetatable(L, -2); // self.metatable = uniqe_metatable

		lua_rawset(L, -3); // self[0] = obj;
		printf("inject obj  %p\n", obj);
		ProxyClass* pClass = m_CPPClasses[className];
		GenericMethod* pMethod = NULL;
		for( int i = 0; i < pClass->getMethodsCount(); ++i) {
			//printf("inject func %d : %s\n", i, pClass->getMethod(i)->getMethodName());
			//(*methodVector)[i]->bindClassObj(obj);
			pMethod = pClass->getMethod(i);
			lua_pushstring(L, pMethod->getMethodName());
			//lua_pushnumber(L, i); // let the thunk know which method we mean
			lua_pushlightuserdata(L, pMethod);
			lua_pushcclosure(L, &proxyMethodCall, 1);
			lua_rawset(L, -3); // self["function"] = thunk("function")
		}

		return 1;
	}

    inline int proxyMethodCall(lua_State *L) {
		GenericMethod* pMethod = (GenericMethod*)lua_touserdata(L, lua_upvalueindex(1));
        return pMethod->call(L); // execute method
    }

	template<typename T>
    inline int gc_obj(lua_State *L) {
        // clean up
        T** obj = static_cast<T**>(luaL_checkudata(L, -1, ProxyClass::className<T>()));
		printf("GC called: %s %p\n", ProxyClass::className<T>(), *obj);
        delete (*obj);
        return 0;
    }

	template<typename T, typename RL>
	inline void registerMethod(const char* name, RL (T::*func)())
	{
		MethodClass0<RL, T>* method = new MethodClass0<RL, T>(name, func);
		ProxyClass* pClass = getProxyClass(ProxyClass::className<T>());
		pClass->pushMethod(method);
	}

    template<typename T, typename RL, typename P1>
	inline void registerMethod(const char* name, RL (T::*func)(P1))
	{
		MethodClass1<RL, T, P1>* method = new MethodClass1<RL, T, P1>(name, func);
		ProxyClass* pClass = getProxyClass(ProxyClass::className<T>());
		pClass->pushMethod(method);
    }

	template<typename T, typename RL, typename P1, typename P2>
	inline void registerMethod(const char* name, RL (T::*func)(P1, P2))
	{
		MethodClass2<RL, T, P1, P2>* method = new MethodClass2<RL, T, P1, P2>(name, func);
		ProxyClass* pClass = getProxyClass(ProxyClass::className<T>());
		pClass->pushMethod(method);
	}

	template<typename T, typename RL, typename P1, typename P2, typename P3>
	inline void registerMethod(const char* name, RL (T::*func)(P1, P2, P3))
	{
		MethodClass3<RL, T, P1, P2, P3>* method = new MethodClass3<RL, T, P1, P2, P3>(name, func);
		ProxyClass* pClass = getProxyClass(ProxyClass::className<T>());
		pClass->pushMethod(method);
	}

	template<typename T, typename RL, typename P1, typename P2, typename P3, typename P4>
	inline void registerMethod(const char* name, RL (T::*func)(P1, P2, P3, P4))
	{
		MethodClass4<RL, T, P1, P2, P3, P4>* method = new MethodClass4<RL, T, P1, P2, P3, P4>(name, func);
		ProxyClass* pClass = getProxyClass(ProxyClass::className<T>());
		pClass->pushMethod(method);
	}

	template<typename T, typename RL, typename P1, typename P2, typename P3, typename P4, typename P5>
	inline void registerMethod(const char* name, RL (T::*func)(P1, P2, P3, P4, P5))
	{
		MethodClass5<RL, T, P1, P2, P3, P4, P5>* method = new MethodClass5<RL, T, P1, P2, P3, P4, P5>(name, func);
		ProxyClass* pClass = getProxyClass(ProxyClass::className<T>());
		pClass->pushMethod(method);
	}

	template<typename T, typename RL, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
	inline void registerMethod(const char* name, RL (T::*func)(P1, P2, P3, P4, P5, P6))
	{
		MethodClass6<RL, T, P1, P2, P3, P4, P5, P6>* method = new MethodClass6<RL, T, P1, P2, P3, P4, P5, P6>(name, func);
		ProxyClass* pClass = getProxyClass(ProxyClass::className<T>());
		pClass->pushMethod(method);
	}

	template<typename T, typename RL, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
	inline void registerMethod(const char* name, RL (T::*func)(P1, P2, P3, P4, P5, P6, P7))
	{
		MethodClass7<RL, T, P1, P2, P3, P4, P5, P6, P7>* method = new MethodClass7<RL, T, P1, P2, P3, P4, P5, P6, P7>(name, func);
		ProxyClass* pClass = getProxyClass(ProxyClass::className<T>());
		pClass->pushMethod(method);
	}

	template<typename T, typename RL, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
	inline void registerMethod(const char* name, RL (T::*func)(P1, P2, P3, P4, P5, P6, P7, P8))
	{
		MethodClass8<RL, T, P1, P2, P3, P4, P5, P6, P7, P8>* method = new MethodClass8<RL, T, P1, P2, P3, P4, P5, P6, P7, P8>(name, func);
		ProxyClass* pClass = getProxyClass(ProxyClass::className<T>());
		pClass->pushMethod(method);
	}

	template<typename T, typename RL, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
	inline void registerMethod(const char* name, RL (T::*func)(P1, P2, P3, P4, P5, P6, P7, P8, P9))
	{
		MethodClass9<RL, T, P1, P2, P3, P4, P5, P6, P7, P8, P9>* method = new MethodClass9<RL, T, P1, P2, P3, P4, P5, P6, P7, P8, P9>(name, func);
		ProxyClass* pClass = getProxyClass(ProxyClass::className<T>());
		pClass->pushMethod(method);
	}


	///////////////////////////////////////////////////////////////////////////////
	// bind cpp function 
	///////////////////////////////////////////////////////////////////////////////
	struct GenericFunction
	{
	public:
		virtual ~GenericFunction() {};
		GenericFunction() {};

		virtual int call(lua_State *L) { return 0;};
		virtual inline const char* getFunctionName(){ return m_name;};
	private:
		const char* m_name;
	};

	typedef std::vector<GenericFunction*> CPPFunctionT;
	CPPFunctionT m_CPPFunctions;
	inline void pushFunction(GenericFunction* function) { m_CPPFunctions.push_back(function);};
	inline void releaseFunction() {
		printf("-----releaseFunction-------\n");
		for (CPPFunctionT::iterator itr = m_CPPFunctions.begin(); itr != m_CPPFunctions.end(); ++itr) {
			printf("m_CPPFunctions %p\n", *itr);
			delete *itr;
		}
	}

	#define ELUNA_FUNCTIONCLASSX_PARAM_LIST_0 typename RL
	#define ELUNA_FUNCTIONCLASSX_PARAM_LIST_1 ELUNA_FUNCTIONCLASSX_PARAM_LIST_0, typename P1
	#define ELUNA_FUNCTIONCLASSX_PARAM_LIST_2 ELUNA_FUNCTIONCLASSX_PARAM_LIST_1, typename P2
	#define ELUNA_FUNCTIONCLASSX_PARAM_LIST_3 ELUNA_FUNCTIONCLASSX_PARAM_LIST_2, typename P3
	#define ELUNA_FUNCTIONCLASSX_PARAM_LIST_4 ELUNA_FUNCTIONCLASSX_PARAM_LIST_3, typename P4
	#define ELUNA_FUNCTIONCLASSX_PARAM_LIST_5 ELUNA_FUNCTIONCLASSX_PARAM_LIST_4, typename P5
	#define ELUNA_FUNCTIONCLASSX_PARAM_LIST_6 ELUNA_FUNCTIONCLASSX_PARAM_LIST_5, typename P6
	#define ELUNA_FUNCTIONCLASSX_PARAM_LIST_7 ELUNA_FUNCTIONCLASSX_PARAM_LIST_6, typename P7
	#define ELUNA_FUNCTIONCLASSX_PARAM_LIST_8 ELUNA_FUNCTIONCLASSX_PARAM_LIST_7, typename P8
	#define ELUNA_FUNCTIONCLASSX_PARAM_LIST_9 ELUNA_FUNCTIONCLASSX_PARAM_LIST_8, typename P9
	#define ELUNA_FUNCTIONCLASSX_VOID_RL_PARAM_LIST_0 
	#define ELUNA_FUNCTIONCLASSX_VOID_RL_PARAM_LIST_1 ELUNA_FUNCTIONCLASSX_VOID_RL_PARAM_LIST_0  typename P1
	#define ELUNA_FUNCTIONCLASSX_VOID_RL_PARAM_LIST_2 ELUNA_FUNCTIONCLASSX_VOID_RL_PARAM_LIST_1, typename P2
	#define ELUNA_FUNCTIONCLASSX_VOID_RL_PARAM_LIST_3 ELUNA_FUNCTIONCLASSX_VOID_RL_PARAM_LIST_2, typename P3
	#define ELUNA_FUNCTIONCLASSX_VOID_RL_PARAM_LIST_4 ELUNA_FUNCTIONCLASSX_VOID_RL_PARAM_LIST_3, typename P4
	#define ELUNA_FUNCTIONCLASSX_VOID_RL_PARAM_LIST_5 ELUNA_FUNCTIONCLASSX_VOID_RL_PARAM_LIST_4, typename P5
	#define ELUNA_FUNCTIONCLASSX_VOID_RL_PARAM_LIST_6 ELUNA_FUNCTIONCLASSX_VOID_RL_PARAM_LIST_5, typename P6
	#define ELUNA_FUNCTIONCLASSX_VOID_RL_PARAM_LIST_7 ELUNA_FUNCTIONCLASSX_VOID_RL_PARAM_LIST_6, typename P7
	#define ELUNA_FUNCTIONCLASSX_VOID_RL_PARAM_LIST_8 ELUNA_FUNCTIONCLASSX_VOID_RL_PARAM_LIST_7, typename P8
	#define ELUNA_FUNCTIONCLASSX_VOID_RL_PARAM_LIST_9 ELUNA_FUNCTIONCLASSX_VOID_RL_PARAM_LIST_8, typename P9
	#define ELUNA_FUNCTIONCLASSX_SP_PARAM_LIST_0 void
	#define ELUNA_FUNCTIONCLASSX_SP_PARAM_LIST_1 ELUNA_FUNCTIONCLASSX_SP_PARAM_LIST_0, P1
	#define ELUNA_FUNCTIONCLASSX_SP_PARAM_LIST_2 ELUNA_FUNCTIONCLASSX_SP_PARAM_LIST_1, P2
	#define ELUNA_FUNCTIONCLASSX_SP_PARAM_LIST_3 ELUNA_FUNCTIONCLASSX_SP_PARAM_LIST_2, P3
	#define ELUNA_FUNCTIONCLASSX_SP_PARAM_LIST_4 ELUNA_FUNCTIONCLASSX_SP_PARAM_LIST_3, P4
	#define ELUNA_FUNCTIONCLASSX_SP_PARAM_LIST_5 ELUNA_FUNCTIONCLASSX_SP_PARAM_LIST_4, P5
	#define ELUNA_FUNCTIONCLASSX_SP_PARAM_LIST_6 ELUNA_FUNCTIONCLASSX_SP_PARAM_LIST_5, P6
	#define ELUNA_FUNCTIONCLASSX_SP_PARAM_LIST_7 ELUNA_FUNCTIONCLASSX_SP_PARAM_LIST_6, P7
	#define ELUNA_FUNCTIONCLASSX_SP_PARAM_LIST_8 ELUNA_FUNCTIONCLASSX_SP_PARAM_LIST_7, P8
	#define ELUNA_FUNCTIONCLASSX_SP_PARAM_LIST_9 ELUNA_FUNCTIONCLASSX_SP_PARAM_LIST_8, P9
	
	#define ELUNA_MAKE_FUNCTIONCLASSX(N)\
	template<ELUNA_FUNCTIONCLASSX_PARAM_LIST_##N >\
	struct FunctionClass##N : GenericFunction\
	{\
		typedef RL (* TFUNC)(ELUNA_PARAM_LIST_##N);\
		TFUNC m_func;\
		const char* m_name;\
		FunctionClass##N( const char* name, TFUNC func):m_name(name),m_func(func) {};\
		~FunctionClass##N() { printf("function releace %s\n", m_name); };\
		virtual inline const char* getMethodName(){ return m_name;};\
		virtual int call(lua_State *L)\
		{\
			push2lua(L, (*m_func)(ELUNA_READ_PARAM_LIST_##N));\
			return 1;\
		};\
	};

	#define ELUNA_MAKE_VOID_RL_FUNCTIONCLASSX(N) \
	template<ELUNA_FUNCTIONCLASSX_VOID_RL_PARAM_LIST_##N >\
	struct FunctionClass##N<ELUNA_FUNCTIONCLASSX_SP_PARAM_LIST_##N> : GenericFunction\
	{\
		typedef void (* TFUNC)(ELUNA_PARAM_LIST_##N);\
		TFUNC m_func;\
		const char* m_name;\
		FunctionClass##N( const char* name, TFUNC func):m_name(name),m_func(func) {};\
		~FunctionClass##N() { printf("function releace %s\n", m_name); };\
		virtual inline const char* getMethodName(){ return m_name;};\
		virtual int call(lua_State *L)\
		{\
			(*m_func)(ELUNA_READ_PARAM_LIST_##N);\
			return 0;\
		};\
	};

	ELUNA_MAKE_FUNCTIONCLASSX(0)
	ELUNA_MAKE_FUNCTIONCLASSX(1)
	ELUNA_MAKE_FUNCTIONCLASSX(2)
	ELUNA_MAKE_FUNCTIONCLASSX(3)
	ELUNA_MAKE_FUNCTIONCLASSX(4)
	ELUNA_MAKE_FUNCTIONCLASSX(5)
	ELUNA_MAKE_FUNCTIONCLASSX(6)
	ELUNA_MAKE_FUNCTIONCLASSX(7)
	ELUNA_MAKE_FUNCTIONCLASSX(8)
	ELUNA_MAKE_FUNCTIONCLASSX(9)

	ELUNA_MAKE_VOID_RL_FUNCTIONCLASSX(0)
	ELUNA_MAKE_VOID_RL_FUNCTIONCLASSX(1)
	ELUNA_MAKE_VOID_RL_FUNCTIONCLASSX(2)
	ELUNA_MAKE_VOID_RL_FUNCTIONCLASSX(3)
	ELUNA_MAKE_VOID_RL_FUNCTIONCLASSX(4)
	ELUNA_MAKE_VOID_RL_FUNCTIONCLASSX(5)
	ELUNA_MAKE_VOID_RL_FUNCTIONCLASSX(6)
	ELUNA_MAKE_VOID_RL_FUNCTIONCLASSX(7)
	ELUNA_MAKE_VOID_RL_FUNCTIONCLASSX(8)
	ELUNA_MAKE_VOID_RL_FUNCTIONCLASSX(9)

	inline int proxyFunctionCall(lua_State *L) {
		GenericFunction* pFunction = (GenericFunction*)lua_touserdata(L, lua_upvalueindex(1));
		return pFunction->call(L); // execute function
	}

	template<typename RL>
	inline void registerFunction(lua_State* L, const char* name, RL (*func)())
	{
		FunctionClass0<RL>* pFunction = new FunctionClass0<RL>(name, func);

		lua_pushstring(L, name);
		lua_pushlightuserdata(L, pFunction);
		lua_pushcclosure(L, proxyFunctionCall, 1);
		lua_settable(L, LUA_GLOBALSINDEX);

		pushFunction(pFunction);
	}

	template<typename RL, typename P1>
	inline void registerFunction(lua_State* L, const char* name, RL (*func)(P1))
	{
		FunctionClass1<RL, P1>* pFunction = new FunctionClass1<RL, P1>(name, func);

		lua_pushstring(L, name);
		lua_pushlightuserdata(L, pFunction);
		lua_pushcclosure(L, proxyFunctionCall, 1);
		lua_settable(L, LUA_GLOBALSINDEX);

		pushFunction(pFunction);
	}

	template<typename RL, typename P1, typename P2>
	inline void registerFunction(lua_State* L, const char* name, RL (*func)(P1, P2))
	{
		FunctionClass2<RL, P1, P2>* pFunction = new FunctionClass2<RL, P1, P2>(name, func);

		lua_pushstring(L, name);
		lua_pushlightuserdata(L, pFunction);
		lua_pushcclosure(L, proxyFunctionCall, 1);
		lua_settable(L, LUA_GLOBALSINDEX);

		pushFunction(pFunction);
	}

	template<typename RL, typename P1, typename P2, typename P3>
	inline void registerFunction(lua_State* L, const char* name, RL (*func)(P1, P2, P3))
	{
		FunctionClass3<RL, P1, P2, P3>* pFunction = new FunctionClass3<RL, P1, P2, P3>(name, func);

		lua_pushstring(L, name);
		lua_pushlightuserdata(L, pFunction);
		lua_pushcclosure(L, proxyFunctionCall, 1);
		lua_settable(L, LUA_GLOBALSINDEX);

		pushFunction(pFunction);
	}

	template<typename RL, typename P1, typename P2, typename P3, typename P4>
	inline void registerFunction(lua_State* L, const char* name, RL (*func)(P1, P2, P3, P4))
	{
		FunctionClass4<RL, P1, P2, P3, P4>* pFunction = new FunctionClass4<RL, P1, P2, P3, P4>(name, func);

		lua_pushstring(L, name);
		lua_pushlightuserdata(L, pFunction);
		lua_pushcclosure(L, proxyFunctionCall, 1);
		lua_settable(L, LUA_GLOBALSINDEX);

		pushFunction(pFunction);
	}

	template<typename RL, typename P1, typename P2, typename P3, typename P4, typename P5>
	inline void registerFunction(lua_State* L, const char* name, RL (*func)(P1, P2, P3, P4, P5))
	{
		FunctionClass5<RL, P1, P2, P3, P4, P5>* pFunction = new FunctionClass5<RL, P1, P2, P3, P4, P5>(name, func);

		lua_pushstring(L, name);
		lua_pushlightuserdata(L, pFunction);
		lua_pushcclosure(L, proxyFunctionCall, 1);
		lua_settable(L, LUA_GLOBALSINDEX);

		pushFunction(pFunction);
	}

	template<typename RL, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
	inline void registerFunction(lua_State* L, const char* name, RL (*func)(P1, P2, P3, P4, P5, P6))
	{
		FunctionClass6<RL, P1, P2, P3, P4, P5, P6>* pFunction = new FunctionClass6<RL, P1, P2, P3, P4, P5, P6>(name, func);

		lua_pushstring(L, name);
		lua_pushlightuserdata(L, pFunction);
		lua_pushcclosure(L, proxyFunctionCall, 1);
		lua_settable(L, LUA_GLOBALSINDEX);

		pushFunction(pFunction);
	}

	template<typename RL, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
	inline void registerFunction(lua_State* L, const char* name, RL (*func)(P1, P2, P3, P4, P5, P6, P7))
	{
		FunctionClass7<RL, P1, P2, P3, P4, P5, P6, P7>* pFunction = new FunctionClass7<RL, P1, P2, P3, P4, P5, P6, P7>(name, func);

		lua_pushstring(L, name);
		lua_pushlightuserdata(L, pFunction);
		lua_pushcclosure(L, proxyFunctionCall, 1);
		lua_settable(L, LUA_GLOBALSINDEX);

		pushFunction(pFunction);
	}

	template<typename RL, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
	inline void registerFunction(lua_State* L, const char* name, RL (*func)(P1, P2, P3, P4, P5, P6, P7, P8))
	{
		FunctionClass8<RL, P1, P2, P3, P4, P5, P6, P7, P8>* pFunction = new FunctionClass8<RL, P1, P2, P3, P4, P5, P6, P7, P8>(name, func);

		lua_pushstring(L, name);
		lua_pushlightuserdata(L, pFunction);
		lua_pushcclosure(L, proxyFunctionCall, 1);
		lua_settable(L, LUA_GLOBALSINDEX);

		pushFunction(pFunction);
	}

	template<typename RL, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
	inline void registerFunction(lua_State* L, const char* name, RL (*func)(P1, P2, P3, P4, P5, P6, P7, P8, P9))
	{
		FunctionClass9<RL, P1, P2, P3, P4, P5, P6, P7, P8, P9>* pFunction = new FunctionClass9<RL, P1, P2, P3, P4, P5, P6, P7, P8, P9>(name, func);

		lua_pushstring(L, name);
		lua_pushlightuserdata(L, pFunction);
		lua_pushcclosure(L, proxyFunctionCall, 1);
		lua_settable(L, LUA_GLOBALSINDEX);

		pushFunction(pFunction);
	}

	void traceStack(lua_State* L, int n)
	{
		lua_Debug ar;
		if(lua_getstack(L, n, &ar))
		{
			lua_getinfo(L, "Sln", &ar);

			if(ar.name) {
				printf("\tstack[%d] -> %s(): entry line %d [%s : line %d]\n", n, ar.name, ar.currentline, ar.short_src, ar.linedefined);
			} else {
				printf("\tstack[%d] -> unknown: entry line %d [%s : line %d]\n", n, ar.currentline, ar.short_src, ar.linedefined);
			}

			traceStack(L, n+1);
		}
	}

	int error_log(lua_State *L)
	{
		printf("error : %s\n", lua_tostring(L, -1));

		traceStack(L, 0);

		return 0; 
	}

	///////////////////////////////////////////////////////////////////////////////
	// bind lua function 
	///////////////////////////////////////////////////////////////////////////////
	template<typename RL>
	struct LuaFunction
	{
	public:
		LuaFunction(lua_State* L, const char* funcName): m_luaState(L), m_name(funcName) {
			printf("Lua Function : %s\n", funcName);
			lua_pushstring(L, funcName);
			lua_gettable(L, LUA_GLOBALSINDEX);
			if (lua_isfunction(L, -1)) {
				m_ref = luaL_ref(L, LUA_REGISTRYINDEX);
			} else {
				printf("%s is not a lua function!\n", funcName);
				assert(0);
			}
		};
		~LuaFunction() {};

		RL operator()()
		{
			lua_pushcclosure(m_luaState, error_log, 0);
			int errLogIndex = lua_gettop(m_luaState);

			lua_rawgeti(m_luaState, LUA_REGISTRYINDEX, m_ref);
			lua_pcall(m_luaState, 0, 1, errLogIndex);

			return read2cpp<RL>(m_luaState, -1);
		}

		template<typename P1>
		RL operator()(P1 p1)
		{
			lua_pushcclosure(m_luaState, error_log, 0);
			int errLogIndex = lua_gettop(m_luaState);

			lua_rawgeti(m_luaState, LUA_REGISTRYINDEX, m_ref);
			push2lua(m_luaState, p1);
			lua_pcall(m_luaState, 1, 1, errLogIndex);

			return read2cpp<RL>(m_luaState, -1);
		}

		template<typename P1, typename P2>
		RL operator()(P1 p1, P2 p2)
		{
			lua_pushcclosure(m_luaState, error_log, 0);
			int errLogIndex = lua_gettop(m_luaState);

			lua_rawgeti(m_luaState, LUA_REGISTRYINDEX, m_ref);
			push2lua(m_luaState, p1); push2lua(m_luaState, p2);
			lua_pcall(m_luaState, 2, 1, errLogIndex);

			return read2cpp<RL>(m_luaState, -1);
		}

		template<typename P1, typename P2, typename P3>
		RL operator()(P1 p1, P2 p2, P3 p3)
		{
			lua_pushcclosure(m_luaState, error_log, 0);
			int errLogIndex = lua_gettop(m_luaState);

			lua_rawgeti(m_luaState, LUA_REGISTRYINDEX, m_ref);
			push2lua(m_luaState, p1); push2lua(m_luaState, p2); push2lua(m_luaState, p3);
			lua_pcall(m_luaState, 3, 1, errLogIndex);

			return read2cpp<RL>(m_luaState, -1);
		}

		template<typename P1, typename P2, typename P3, typename P4>
		RL operator()(P1 p1, P2 p2, P3 p3, P4 p4)
		{
			lua_pushcclosure(m_luaState, error_log, 0);
			int errLogIndex = lua_gettop(m_luaState);

			lua_rawgeti(m_luaState, LUA_REGISTRYINDEX, m_ref);
			push2lua(m_luaState, p1); push2lua(m_luaState, p2); push2lua(m_luaState, p3); push2lua(m_luaState, p4);
			lua_pcall(m_luaState, 4, 1, errLogIndex);

			return read2cpp<RL>(m_luaState, -1);
		}

		template<typename P1, typename P2, typename P3, typename P4, typename P5>
		RL operator()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
		{
			lua_pushcclosure(m_luaState, error_log, 0);
			int errLogIndex = lua_gettop(m_luaState);

			lua_rawgeti(m_luaState, LUA_REGISTRYINDEX, m_ref);
			push2lua(m_luaState, p1); push2lua(m_luaState, p2); push2lua(m_luaState, p3); push2lua(m_luaState, p4); push2lua(m_luaState, p5);
			lua_pcall(m_luaState, 5, 1, errLogIndex);

			return read2cpp<RL>(m_luaState, -1);
		}

		template<typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
		RL operator()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6)
		{
			lua_pushcclosure(m_luaState, error_log, 0);
			int errLogIndex = lua_gettop(m_luaState);

			lua_rawgeti(m_luaState, LUA_REGISTRYINDEX, m_ref);
			push2lua(m_luaState, p1); push2lua(m_luaState, p2); push2lua(m_luaState, p3); push2lua(m_luaState, p4); push2lua(m_luaState, p5); push2lua(m_luaState, p6);
			lua_pcall(m_luaState, 6, 1, errLogIndex);

			return read2cpp<RL>(m_luaState, -1);
		}

		template<typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
		RL operator()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7)
		{
			lua_pushcclosure(m_luaState, error_log, 0);
			int errLogIndex = lua_gettop(m_luaState);

			lua_rawgeti(m_luaState, LUA_REGISTRYINDEX, m_ref);
			push2lua(m_luaState, p1); push2lua(m_luaState, p2); push2lua(m_luaState, p3); push2lua(m_luaState, p4); push2lua(m_luaState, p5); push2lua(m_luaState, p6); push2lua(m_luaState, p7);
			lua_pcall(m_luaState, 7, 1, errLogIndex);

			return read2cpp<RL>(m_luaState, -1);
		}

		template<typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
		RL operator()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8)
		{
			lua_pushcclosure(m_luaState, error_log, 0);
			int errLogIndex = lua_gettop(m_luaState);

			lua_rawgeti(m_luaState, LUA_REGISTRYINDEX, m_ref);
			push2lua(m_luaState, p1); push2lua(m_luaState, p2); push2lua(m_luaState, p3); push2lua(m_luaState, p4); push2lua(m_luaState, p5); push2lua(m_luaState, p6); push2lua(m_luaState, p7); push2lua(m_luaState, p8);
			lua_pcall(m_luaState, 8, 1, errLogIndex);

			return read2cpp<RL>(m_luaState, -1);
		}

		template<typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
		RL operator()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9)
		{
			lua_pushcclosure(m_luaState, error_log, 0);
			int errLogIndex = lua_gettop(m_luaState);

			lua_rawgeti(m_luaState, LUA_REGISTRYINDEX, m_ref);
			push2lua(m_luaState, p1); push2lua(m_luaState, p2); push2lua(m_luaState, p3); push2lua(m_luaState, p4); push2lua(m_luaState, p5); push2lua(m_luaState, p6); push2lua(m_luaState, p7); push2lua(m_luaState, p8); push2lua(m_luaState, p9);
			lua_pcall(m_luaState, 9, 1, errLogIndex);

			return read2cpp<RL>(m_luaState, -1);
		}

	private:
		int m_ref;
		const char* m_name;
		lua_State* m_luaState;
	};

	template<>
	struct LuaFunction<void>
	{
	public:
		LuaFunction(lua_State* L, const char* funcName): m_luaState(L), m_name(funcName) {
			printf("Lua Function : %s\n", funcName);
			lua_pushstring(L, funcName);
			lua_gettable(L, LUA_GLOBALSINDEX);
			if (lua_isfunction(L, -1)) {
				m_ref = luaL_ref(L, LUA_REGISTRYINDEX);
			} else {
				printf("%s is not a lua function!\n", funcName);
				assert(0);
			}
		};

		~LuaFunction() {};

		void operator()()
		{
			lua_pushcclosure(m_luaState, error_log, 0);
			int errLogIndex = lua_gettop(m_luaState);

			lua_rawgeti(m_luaState, LUA_REGISTRYINDEX, m_ref);
			lua_pcall(m_luaState, 0, 1, errLogIndex);
		}

		template<typename P1>
		void operator()(P1 p1)
		{
			lua_pushcclosure(m_luaState, error_log, 0);
			int errLogIndex = lua_gettop(m_luaState);

			lua_rawgeti(m_luaState, LUA_REGISTRYINDEX, m_ref);
			push2lua(m_luaState, p1);
			lua_pcall(m_luaState, 1, 1, errLogIndex);
		}

		template<typename P1, typename P2>
		void operator()(P1 p1, P2 p2)
		{
			lua_pushcclosure(m_luaState, error_log, 0);
			int errLogIndex = lua_gettop(m_luaState);

			lua_rawgeti(m_luaState, LUA_REGISTRYINDEX, m_ref);
			push2lua(m_luaState, p1); push2lua(m_luaState, p2);
			lua_pcall(m_luaState, 2, 1, errLogIndex);
		}

		template<typename P1, typename P2, typename P3>
		void operator()(P1 p1, P2 p2, P3 p3)
		{
			lua_pushcclosure(m_luaState, error_log, 0);
			int errLogIndex = lua_gettop(m_luaState);

			lua_rawgeti(m_luaState, LUA_REGISTRYINDEX, m_ref);
			push2lua(m_luaState, p1); push2lua(m_luaState, p2); push2lua(m_luaState, p3);
			lua_pcall(m_luaState, 3, 1, errLogIndex);
		}

		template<typename P1, typename P2, typename P3, typename P4>
		void operator()(P1 p1, P2 p2, P3 p3, P4 p4)
		{
			lua_pushcclosure(m_luaState, error_log, 0);
			int errLogIndex = lua_gettop(m_luaState);

			lua_rawgeti(m_luaState, LUA_REGISTRYINDEX, m_ref);
			push2lua(m_luaState, p1); push2lua(m_luaState, p2); push2lua(m_luaState, p3); push2lua(m_luaState, p4);
			lua_pcall(m_luaState, 4, 1, errLogIndex);
		}

		template<typename P1, typename P2, typename P3, typename P4, typename P5>
		void operator()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
		{
			lua_pushcclosure(m_luaState, error_log, 0);
			int errLogIndex = lua_gettop(m_luaState);

			lua_rawgeti(m_luaState, LUA_REGISTRYINDEX, m_ref);
			push2lua(m_luaState, p1); push2lua(m_luaState, p2); push2lua(m_luaState, p3); push2lua(m_luaState, p4); push2lua(m_luaState, p5);
			lua_pcall(m_luaState, 5, 1, errLogIndex);
		}

		template<typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
		void operator()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6)
		{
			lua_pushcclosure(m_luaState, error_log, 0);
			int errLogIndex = lua_gettop(m_luaState);

			lua_rawgeti(m_luaState, LUA_REGISTRYINDEX, m_ref);
			push2lua(m_luaState, p1); push2lua(m_luaState, p2); push2lua(m_luaState, p3); push2lua(m_luaState, p4); push2lua(m_luaState, p5); push2lua(m_luaState, p6);
			lua_pcall(m_luaState, 6, 1, errLogIndex);
		}

		template<typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
		void operator()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7)
		{
			lua_pushcclosure(m_luaState, error_log, 0);
			int errLogIndex = lua_gettop(m_luaState);

			lua_rawgeti(m_luaState, LUA_REGISTRYINDEX, m_ref);
			push2lua(m_luaState, p1); push2lua(m_luaState, p2); push2lua(m_luaState, p3); push2lua(m_luaState, p4); push2lua(m_luaState, p5); push2lua(m_luaState, p6); push2lua(m_luaState, p7);
			lua_pcall(m_luaState, 7, 1, errLogIndex);
		}

		template<typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
		void operator()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8)
		{
			lua_pushcclosure(m_luaState, error_log, 0);
			int errLogIndex = lua_gettop(m_luaState);

			lua_rawgeti(m_luaState, LUA_REGISTRYINDEX, m_ref);
			push2lua(m_luaState, p1); push2lua(m_luaState, p2); push2lua(m_luaState, p3); push2lua(m_luaState, p4); push2lua(m_luaState, p5); push2lua(m_luaState, p6); push2lua(m_luaState, p7); push2lua(m_luaState, p8);
			lua_pcall(m_luaState, 8, 1, errLogIndex);
		}

		template<typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
		void operator()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9)
		{
			lua_pushcclosure(m_luaState, error_log, 0);
			int errLogIndex = lua_gettop(m_luaState);

			lua_rawgeti(m_luaState, LUA_REGISTRYINDEX, m_ref);
			push2lua(m_luaState, p1); push2lua(m_luaState, p2); push2lua(m_luaState, p3); push2lua(m_luaState, p4); push2lua(m_luaState, p5); push2lua(m_luaState, p6); push2lua(m_luaState, p7); push2lua(m_luaState, p8); push2lua(m_luaState, p9);
			lua_pcall(m_luaState, 9, 1, errLogIndex);
		}

	private:
		int m_ref;
		const char* m_name;
		lua_State* m_luaState;
	};

	void doFile(lua_State *L, const char *fileName)
	{
		lua_pushcclosure(L, error_log, 0);
		int errLogIndex = lua_gettop(L);

		if(luaL_loadfile(L, fileName) == 0)
		{
			lua_pcall(L, 0, 0, errLogIndex);
		} else {
			printf("dofile error: %s", lua_tostring(L, -1));
		}
	}

	lua_State* openLua() {
		lua_State *L = lua_open();

		luaopen_base(L);           // 加载Lua基本库
		luaL_openlibs(L);          // 加载Lua通用扩展库
		luaopen_debug(L);

		return L;
	}

	void closeLua(lua_State* L) {
		releaseClass();
		releaseFunction();
		lua_close(L);
	}

} // namespace ELuna

#endif //_LUA_ELUNA_H_
