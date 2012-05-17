print("-----------------BIG_PIG-------------------")
local monster = Monster("BIG_PIG")
print("monster: ", getmetatable(monster), monster)--, monster[0], monster.speak)

--for k, v in pairs(monster) do
    --print("self property: ", k, v)
--end

--local metatalbe = getmetatable(monster)
--for k, v in pairs(metatalbe) do
    --print("metatalbe property: ", k, v)
--end
--monster:setName("monster")
monster:speak("nice to meet you!!")
local old = monster:getOld()
print("monster old: ", old)
print("monster getName: ", monster:getName())
monster:setOld(10)
old = monster:getOld()
--print("monster old: ", old, monster, monster[0])
print("-----------------LITTLE_MONKEY-------------------")
local monster1 = Monster("LITTLE_MONKEY")
--monster1:setName("monster1")
monster1:speak("nice to meet you too!!")
local old = monster1:getOld()
print("monster1 old: ", old)
print("monster1 getName: ", monster1:getName())
monster1:setOld(5)
old = monster1:getOld()
print("--------------------test------------------------")
--print("monster1 old: ", old, monster1, monster1[0])
print("monster old: ", monster:getOld())
print("monster1 old: ", monster1:getOld())

foo()
foo1()
function luaFoo1(str)
	print("this is luaFoo1", str);
	return 1001
end

function stack2()
	a = b + c
end

function stack1()
	stack2()
end

function luaFoo2(a, b)
	print("this is luaFoo2", a + b);
	stack1()
end

print("-------------------end-----------------------")


