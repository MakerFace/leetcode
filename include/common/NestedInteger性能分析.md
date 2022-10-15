constructor
constructor
constructor_int:1
move constructor:list move stack top
constructor_int:1 emplace 1
copy constructor:1 vector resize copy
destructor:1 remove old one
destructor:list stack pop
move constructor:list move top to stack.top
destructor:list remove top
constructor_int:2 emplace
copy constructor:1 vector resize copy
copy constructor:1 ---
copy constructor:list ---
destructor:list ---
destructor:1 ---
destructor:1 resize stop
constructor emplace null NestedInteger to stack
constructor_int:1 stack.top.emplace
move constructor:list move stack top
constructor_int:1 emplace 1
copy constructor:1 vector resize copy
destructor:1 resize(2) stop
destructor:list stack pop
move constructor:list move stack top
copy constructor:1 vector resize copy start
copy constructor:1 ---
copy constructor:list ---
copy constructor:2 ---
destructor:list ---
destructor:1 ---
destructor:1 ---
destructor:2 ---
destructor:list resize(4) stop
move constructor:list move stack top
destructor:list stack pop

------------------------------

**return copy**,使用`std::move`移动返回值减少复制构造函数

copy constructor:1
copy constructor:1
copy constructor:list
copy constructor:2
copy constructor:1
copy constructor:1
copy constructor:list
destructor:list
destructor:list
destructor:1
destructor:1
destructor:2
destructor:list
destructor:1
destructor:1

-----------------------------------

**make_pair**，使用`std::move`移动参数（不推荐在引用上执行，但是后面没用到了，所以就移动了），减少复制构造函数

copy constructor:1
copy constructor:1
copy constructor:list
copy constructor:2
copy constructor:1
copy constructor:1
copy constructor:list
destructor:list
destructor:1
destructor:1
destructor:2
destructor:list
destructor:1
destructor:1

---------------------------

**main destruct**

destructor:list
destructor:1
destructor:1
destructor:2
destructor:list
destructor:1
destructor:1

---------------------------

队列的扩张没办法不调用复制构造函数。