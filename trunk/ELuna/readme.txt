
	ELuna is a simple library to bind C/C++ and lua, which just depends on lua library. 
It is clear and light. You can include ELuna and lua in your project to use. My original 
intention is to do some extension for Luna, so its main idea bases on luna. Users don't 
have to focus on the details of binding C++ and Lua, but use some simple API provided by 
ELuna to bind cpp class, method, function or to bind lua function, table.
	Before version 1.1, ELuna copied class's all methods to object's table when you create 
an object, that is the same as Luna. It needn't find method from metatable when you call 
cpp method, but object creation is very slow. Obviously, this way may be a good chiose when 
you call its method many times but create object rarely. In order to improve its efficiency, 
I do some adjustments in later versions. I use a new way to bind method which doesn't copy 
class's all methods to table, but register a method to class's metatable. When you call this 
method, ELuna will find this method from metatable by using "__index" metamethod. In this way, 
object creation is very fast while calling method is a little slower than before. Finally, 
how to choose between the two versions depends on your requirement.
	After many versions, ELuna has been stable at present. However, maybe there are still 
some bugs that I didn't find. Please contact me when you find any problems. Of course, ELuna 
also can't support all the features, such as binding member data and so on. The main reason 
is that they were either used rarely or implemented easily by other ways during my past project. 
For example, we can register a "get" and "set" method to take the place of binding the member 
data. If you really need these features, it is simple to add by yourself.

Attentions:
	1. Transferring or returning pointer has best efficiency, followed by reference, the 
	worst is transferring object.
	
	2. Don't transfer and return the same pointer in a registered cpp function. 
	example£º
		Test* foo(Test* p) {
			return p;      //don't transfer and return the same pointer
 	    }
		ELuna::registerClass<Test>(L, "Test", ELuna::constructor<Test>);
		ELuna::registerMethod<Test>(L, "Test", &Test::foo);

	3. Don't delete pointer which is created and returned in a registered cpp function. 
	example£º
		Test* foo() {
			Test* p = new Test(); //don't delete it by yourself
			return p;  
 	    }
		ELuna::registerClass<Test>(L, "Test", ELuna::constructor<Test>);
		ELuna::registerMethod<Test>(L, "Test", &Test::foo);