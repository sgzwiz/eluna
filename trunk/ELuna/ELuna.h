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
	// read a value from lua stack
	template<typename T> inline T   read(lua_State *L, int index) { printf("param type error!\n"); assert(0);};
	template<>	inline bool         read(lua_State *L, int index) { if(lua_isboolean(L, index)) return lua_toboolean(L, index) != 0; else return lua_tonumber(L, index) != 0;};
	template<>	inline char*		read(lua_State *L, int index) { return (char*)lua_tostring(L, index); };
	template<>	inline const char*	read(lua_State *L, int index) { return (const char*)lua_tostring(L, index);};
	template<>	inline char			read(lua_State *L, int index) { return (char)lua_tonumber(L, index);};
	template<>	inline unsigned char  read(lua_State *L, int index) { return (unsigned char)lua_tonumber(L, index);};
	template<>	inline short		read(lua_State *L, int index) { return (short)lua_tonumber(L, index);};
	template<>	inline unsigned short read(lua_State *L, int index) { return (unsigned short)lua_tonumber(L, index);};
	template<>	inline long			read(lua_State *L, int index) { return (long)lua_tonumber(L, index);}; 
	template<>	inline unsigned long  read(lua_State *L, int index) { return (unsigned long)lua_tonumber(L, index);};
	template<>	inline int			read(lua_State *L, int index) { return (int)lua_tonumber(L, index);};
	template<>	inline unsigned int	read(lua_State *L, int index) { return (unsigned int)lua_tonumber(L, index);};
	template<>	inline long long    read(lua_State *L, int index) { return (long long)lua_tonumber(L, index);};
	template<>  inline unsigned long long  read(lua_State *L, int index) { return (unsigned long long)lua_tonumber(L, index);};
	template<>	inline float		read(lua_State *L, int index) { return (float)lua_tonumber(L, index);};
	template<>	inline double		read(lua_State *L, int index) { return (double)lua_tonumber(L, index);};
	template<>	inline void			read(lua_State *L, int index) { return;}; 
	//template<>	table				read(lua_State *L, int index);
	template<>	inline LuaString	read(lua_State *L, int index) { LuaString ls; ls.str = (char*)lua_tolstring(L, index, &ls.len); return ls;};
	
	// push a value to lua stack
	template<typename T> inline void push(lua_State *L, T ret) { printf("return type error!\n"); assert(0);};
	template<> inline void push(lua_State *L, char ret) { lua_pushnumber(L, ret);};
	template<> inline void push(lua_State *L, unsigned char ret) { lua_pushnumber(L, ret);};
	template<> inline void push(lua_State *L, short ret) { lua_pushnumber(L, ret);};
	template<> inline void push(lua_State *L, unsigned short ret) { lua_pushnumber(L, ret);};
	template<> inline void push(lua_State *L, long ret) { lua_pushnumber(L, ret);};
	template<> inline void push(lua_State *L, unsigned long ret) { lua_pushnumber(L, ret);};
	template<> inline void push(lua_State *L, int ret) { lua_pushnumber(L, ret);};
	template<> inline void push(lua_State *L, unsigned int ret) { lua_pushnumber(L, ret);};
	template<> inline void push(lua_State *L, float ret) { lua_pushnumber(L, ret);};
	template<> inline void push(lua_State *L, double ret) { lua_pushnumber(L, ret);};
	template<> inline void push(lua_State *L, char* ret) { lua_pushstring(L, ret);};
	template<> inline void push(lua_State *L, const char* ret) { lua_pushstring(L, ret);};
	template<> inline void push(lua_State *L, bool ret) { lua_pushboolean(L, ret);};
	template<> inline void push(lua_State *L, long long ret) { return lua_pushnumber(L, (LUA_NUMBER)ret);};
	template<> inline void push(lua_State *L, unsigned long long ret) { return lua_pushnumber(L, (LUA_NUMBER)ret);};
	template<> inline void push(lua_State *L, LuaString ret) {lua_pushlstring(L, ret.str, ret.len);};

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
	#define ELUNA_READ_PARAM_LIST_1 ELUNA_READ_PARAM_LIST_0  read<P1>(L,2)
	#define ELUNA_READ_PARAM_LIST_2 ELUNA_READ_PARAM_LIST_1, read<P2>(L,3)
	#define ELUNA_READ_PARAM_LIST_3 ELUNA_READ_PARAM_LIST_2, read<P3>(L,4)
	#define ELUNA_READ_PARAM_LIST_4 ELUNA_READ_PARAM_LIST_3, read<P4>(L,5)
	#define ELUNA_READ_PARAM_LIST_5 ELUNA_READ_PARAM_LIST_4, read<P5>(L,6)
	#define ELUNA_READ_PARAM_LIST_6 ELUNA_READ_PARAM_LIST_5, read<P6>(L,7)
	#define ELUNA_READ_PARAM_LIST_7 ELUNA_READ_PARAM_LIST_6, read<P7>(L,8)
	#define ELUNA_READ_PARAM_LIST_8 ELUNA_READ_PARAM_LIST_7, read<P8>(L,9)
	#define ELUNA_READ_PARAM_LIST_9 ELUNA_READ_PARAM_LIST_8, read<P9>(L,10)

	struct GenericMethod
	{
	public:
		virtual ~GenericMethod() {};
		//int PerformCall(CHost* _host, lua_State *L, LuaCustomVariable *_lcv) const;
		//int MatchParams(lua_State *L, LuaCustomVariable *_lcv) const;
		//const char* GetVerboseName(lua_State *L) const;
	
		GenericMethod() {};
		//virtual int PerformCallV(CHost* _host, lua_State *L, LuaCustomVariable *_lcv) const;
		virtual int call(lua_State *L) { return 0;};
		virtual inline const char* getMethodName(){ return m_name;};
		//virtual inline void bindClassObj(void* obj) {};

	private:
		//bool m_IsConst; // method is const?
		//bool m_IsOperatorMethod; // was current GM binded as .Operator(XXX, &MyClass::SomeMethod) ?
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
		virtual inline const char* getMethodName(){ return m_name;};\
		virtual int call(lua_State *L)\
		{\
			lua_pushnumber(L, 0);\
			lua_rawget(L, 1); \
			T** obj = (T**)lua_touserdata(L, -1);\
			push(L, ((*obj)->*(m_func))(ELUNA_READ_PARAM_LIST_##N));\
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
			//printf("class_name1 %s, %s\n ", _name, name);
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
        lua_setglobal(L, name); // T() in lua will make a new instance.

        registerMetatable<T>(L, name);
    }

    // register the metatable without registering the class constructor
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
        return inject<T>(L, new T(read<P1>(L,1)));
    }

    template<typename T, typename P1, typename P2>
    inline int constructor(lua_State *L)
    {
        return inject<T>(L, new T(read<P1>(L,1), read<P2>(L,2)));
    }

    template<typename T, typename P1, typename P2, typename P3>
    inline int constructor(lua_State *L)
    {
        return inject<T>(L, new T(read<P1>(L,1), read<P2>(L,2), read<P3>(L,3)));
    }

	template<typename T, typename P1, typename P2, typename P3, typename P4>
	inline int constructor(lua_State *L)
	{
		return inject<T>(L, new T(read<P1>(L,1), read<P2>(L,2), read<P3>(L,3), read<P4>(L,4)));
	}

	template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5>
	inline int constructor(lua_State *L)
	{
		return inject<T>(L, new T(read<P1>(L,1), read<P2>(L,2), read<P3>(L,3), read<P4>(L,4), read<P5>(L,5)));
	}

	template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
	inline int constructor(lua_State *L)
	{
		return inject<T>(L, new T(read<P1>(L,1), read<P2>(L,2), read<P3>(L,3), read<P4>(L,4), read<P5>(L,5), read<P6>(L,6)));
	}

	template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
	inline int constructor(lua_State *L)
	{
		return inject<T>(L, new T(read<P1>(L,1), read<P2>(L,2), read<P3>(L,3), read<P4>(L,4), read<P5>(L,5), read<P6>(L,6), read<P7>(L,7)));
	}

	template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
	inline int constructor(lua_State *L)
	{
		return inject<T>(L, new T(read<P1>(L,1), read<P2>(L,2), read<P3>(L,3), read<P4>(L,4), read<P5>(L,5), read<P6>(L,6), read<P7>(L,7), read<P8>(L,8)));
	}

	template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
	inline int constructor(lua_State *L)
	{
		return inject<T>(L, new T(read<P1>(L,1), read<P2>(L,2), read<P3>(L,3), read<P4>(L,4), read<P5>(L,5), read<P6>(L,6), read<P7>(L,7), read<P8>(L,8), read<P9>(L,9)));
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
        // redirect method call to the real thing
        //int i = (int)lua_tonumber(L, lua_upvalueindex(1)); // which function?
        //lua_pushnumber(L, 0);
        //lua_gettable(L, 1); // get the class table (i.e, self)

       // T** obj = static_cast<T**>(luaL_checkudata(L, -1, ProxyClass<T>::name()));
       // lua_remove(L, -1); // remove the userdata from the stack
		GenericMethod* pMethod = (GenericMethod*)lua_touserdata(L, lua_upvalueindex(1));
		//ProxyClass* pClass = getProxyClass(ProxyClass::className<T>());
        return pMethod->call(L); // execute the thunk
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

	struct GenericFunction
	{
	public:
		virtual ~GenericFunction() {};
		//int PerformCall(CHost* _host, lua_State *L, LuaCustomVariable *_lcv) const;
		//int MatchParams(lua_State *L, LuaCustomVariable *_lcv) const;
		//const char* GetVerboseName(lua_State *L) const;
	
		GenericFunction() {};
		//virtual int PerformCallV(CHost* _host, lua_State *L, LuaCustomVariable *_lcv) const;
		virtual int call(lua_State *L) { return 0;};
		virtual inline const char* getFunctionName(){ return m_name;};
		//virtual inline void bindClassObj(void* obj) {};

	private:
		//bool m_IsConst; // method is const?
		//bool m_IsOperatorMethod; // was current GM binded as .Operator(XXX, &MyClass::SomeMethod) ?
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
		virtual inline const char* getMethodName(){ return m_name;};\
		virtual int call(lua_State *L)\
		{\
			push(L, (*m_func)(ELUNA_READ_PARAM_LIST_##N));\
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

	template<typename RL>
	inline void registerFunction(const char* name, RL (*func)())
	{
		FunctionClass0<RL>* function = new FunctionClass0<RL>(name, func);

		lua_pushstring(L, name);
		lua_pushcfunction(L, function->call);
		lua_settable(L, LUA_GLOBALSINDEX);

		pushFunction(function);
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
