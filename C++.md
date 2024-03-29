


# cpp
ref
https://www.stibel.icu/md/c++/features/c14/c++-features-c14.html




# Key-Words

## inline

### 什么函数可以inline？

inline可以用来修饰virtual吗？



## explicit

用来声明类构造函数是显式调用的，而非隐式调用，可以阻止调用构造函数时进行隐式转换和赋值初始化。只可用于修饰单参构造函数，因为无参构造函数和多参构造函数本身就是显式调用的，再加上 explicit 关键字也没有什么意义。

## static

### 函数内声明静态变量

```cpp
void CustomerOpConvertPass::customerOpCvt(Operation *op) {
  static pthread_mutex_t mutex;
  static int pythonFlag = 0;
}
```

如pythonFlag这个变量，因为函数要执行多次，同时保留上次flag的记录，所以将用static修饰。写成全局变量也是可以的。


### 静态成员变量初始化
静态数据成员不能在类中初始化，一般在类外和 main() 函数之前初始化，缺省时初始化为 0。
1. 静态成员不能在类定义里边初始化，只能在 class body 外初始化。
2. static成员的所有者是类本身，但是多个对象拥有一样的静态成员。故其不能在实例化对象时通过构造函数对其进行初始化。
3. 静态成员仍然遵循 public，private，protected 访问准则。
4. 静态成员函数没有 this 指针，它不能返回非静态成员，因为除了对象会调用它外，类本身也可以调用
5. 静态成员属于全局变量，是所有实例化以后的对象所共享的，而成员的初始化你可以想象成向系统申请内存存储数据的过程，显然这种共有对象。不能在任何函数和局部作用域中初始化。

--静态成员属于全局变量，是所有实例化以后的对象所共享的，而成员的初始化你可以想象成向系统申请内存存储数据的过程，显然这种共有对象。不能在任何函数和局部作用域中初始化。--

GPT:
因为静态成员变量是类的一部分，而不是对象的一部分。因此，它的类型必须在类定义的外部进行指定。

在类内部声明静态成员变量时，只是它的声明，不分配存储空间，因此不涉及初始化。初始化工作必须在类的外部进行，通常在类的实现文件（.cpp 文件）中。此时需要指定类型，以确保编译器能够正确分配存储空间和进行相关的初始化工作。


```c++
class point{
public:
	point(){};
//	...
private:
	static int x,y;
};
int point::x = 0;
int point::y = 0;
 
int main(){
//	...
}
```

## const
### 常量指针(指向常量的指针)和指针常量
__常量指针(指向常量的指针)__
定义：具有只能够读取内存中数据，却不能够修改内存中数据的属性的指针，称为指向常量的指针，简称常量指针。


声明：`const int * p`; `int const * p`;

__指针常量__
指针常量是指指针所指向的位置不能改变，即指针本身是一个常量，但是指针所指向的内容可以改变。 `int * const p=&a`;

注：指针常量必须在声明的同时对其初始化，不允许先声明一个指针常量随后再对其赋值，这和声明一般的常量是一样的

区分，看const在*的左边还是右边，左边即为指向常量的指针，右边即为指针常量。


用const修饰的常量只能由常量指针指向，普通指针不可以指向常量。
```c++
    const int c = 1;
    //int * pc = &c; error
    const int * pc = &c;
```
## constexpr

## explicit 
explicit关键字主要是用来修饰类中的构造函数的，对于仅有一个参数或除第一个参数外其余参数均有默认值的类构造函数，尽可能使用explicit关键字修饰。因为只有一个参数或者出了第一个参数其他参数是默认参数的构造函数来说，他还有另一个名字叫做转换构造函数。

**所以explicit主要用来防止隐式转换**.因为仅含一个参数的构造函数和除了第一个参数外其余参数都有默认值的多参构造函数承担了两个角色。 第一个是成为带参数的构造函数，第二个是一个默认且隐含的类型转换操作符（就是单参数的构造函数是一种隐含的类型转换符）

额外说一下隐式类型转换：

c++隐式类型转换是指c++自动将一种类型转换成另一种类型，是编译器的一种自主行为。

举一些类型转换的例子：


# STL
# STL Container 线程安全
__vector__



# C++11

# C++14
C++14是对C++11的补充,并没有太多新特性。
https://github.com/AnthonyCalandra/modern-cpp-features

[翻译](https://cloud.tencent.com/developer/article/1670712)

__新特性一览__

**语言新特性**
- 二进制字面值
- 泛型的Lambda表达式
- 初始化Lambda的捕获列表
- 推断返回类型
- decltype(auto)
- 放宽对常量表达式函数的约束
- 变量模板
- [[deprecated]]属性

**标准库新特性**
- 可用于标准库类型的自定义字面量
- 编译期的整型序列
- std::make_unique

# C++17
https://zhuanlan.zhihu.com/p/165640868

构造函数模板推导
结构化绑定
if-switch语句初始化
内联变量
折叠表达式
constexpr lambda表达式
namespace嵌套
__has_include预处理表达式
在lambda表达式用*this捕获对象副本
新增Attribute
字符串转换
std::variant
std::optional
std::any
std::apply
std::make_from_tuple
as_const
std::string_view
file_system
std::shared_mutex



## 语言基础
### 声明、定义和初始化

变量

1. 声明：是指出存储类型，并给存储单元指定名称。

2. 定义：是分配内存空间，还可为变量指定初始值。

3. extern 关键字：通过使用 extern 关键字声明变量名，而不是定义它。

注：

1. 声明不一定是定义：extern 声明没有分配内存空间，所以不是定义；extern 告诉编译器变量在其他地方定义了。

例如：extern int val; // 只是声明了变量 val，并没有分配内存空间，所以不是定义。

2. 定义也是声明：定义变量的时候，同时给变量指出了存储类型，并给变量的存储单元指定了名称，所以也是声明。

例如：int val; // 声明了变量 val，也会分配内存空间，所以也是定义。

3. extern 关键字标识的才是声明，其余都是定义

例如：extern int val; // 声明

int val; // 定义

4. 声明有指定初始值：如果指定了初始值，即使前面加了 extern 关键字，也是定义。

例如：extern int val = 1; // 定义

5. 一个变量的定义永远只能有一个，但是可以有多个声明。

函数

1. 函数原型（又称函数声明）：函数原型之于函数，相当于变量声明之于变量，只有函数头的就是函数原型。

例如：int function();

extern int function();

2. 函数定义：带有函数体的就是定义，

例如：int function() { return 0;}

注：

1. 函数原型的返回值类型与函数定义必须相同。

2. 函数原型的形参表的类型与顺序必须与函数定义相同，但是函数原型可以不写形参名称，即便写了形参名称也可以和原函数不一样。

3. 空形参

C 语言中：

int func(); // 表示可以有很多个参数

int func(void); // 表示没有参数

C++ 中，上述两行代码等价，且都表示没有参数。

4. 在函数被调用之前必须先有函数原型，函数定义可以放在调用函数的后面。

int func(); // 必须在调用函数的前面

int main() { int ret = func(); }

int func() { return 0;} 可以在调用函数的后

5. 函数原型描述了函数接口，即函数如何与程序的其他部分交互。参数列表指出了何种信息将被传递给函数，函数类型指出了返回值的类型。



### C++中的结构体和类有什么区别？

__C 结构体与 C++ 结构体__

C 语言中的结构体不能为空，否则会报错
C 语言中的结构体只涉及到数据结构，而不涉及到算法，也就是说在 C 中数据结构和算法是分离的。换句话说就是 C 语言中的结构体只能定义成员变量，但是不能定义成员函数（虽然可以定义函数指针，但毕竟是指针而不是函数）。然而 C++ 中结构体既可以定义成员变量又可以定义成员函数， C++ 中的结构体和类体现了数据结构和算法的结合。

__C++ 中结构体与类__

相同之处： 结构体中也可以包含函数；也可以定义 public、private、protected 数据成员；定义了结构体之后，可以用结构体名来创建对象。也就是说在 C++ 当中，结构体中可以有成员变量，可以有成员函数，可以从别的类继承，也可以被别的类继承，可以有虚函数。总的一句话：class 和 struct 的语法基本相同，从声明到使用，都很相似。
区别：对于成员访问权限和继承方式，class 中默认的是 private，而 struct 中则是 public。class 还可以用于表示模板类型，struct 则不行。
实际上C++中保留struct关键字是为了使C++编译器能够兼容C语言开发的程序

__结构体与联合体（共用体）的区别__
结构和联合都是由多个不同的数据类型成员组成, 但在任何同一时刻, 联合中只存放了一个被选中的成员（所有成员共用一块地址空间）, 而结构体的所有成员都存在（不同成员的存放地址不同）。 （在 struct 中，各成员都占有自己的内存空间，它们是同时存在的。一个 struct 变量的总长度等于所有成员长度之和。在 Union 中，所有成员不能同时占用它的内存空间，它们不能同时存在。Union 变量的长度等于最长的成员的长度。）
对联合体不同成员赋值, 将会对其它成员重写, 原来成员的值就不存在了, 而对于结构的不同成员赋值是互不影响的。
类型转换

## 宏


# 面向对象

## 构造函数

初始化子类时，会先自动调用父类的构造函数，然后才调用子类的构造函数。

析构时，按相反顺序进行。

构造函数不能声明为const
不同于其他函数，构造函数不能被声明为const。当我们创建类的一个const对象时，直到构造函数完成初始化过程，对象才真正取得其常量属性。因此，构造函数在const对象的构造过程中可以向其写值。


## 析构函数

### 为什么析构函数不能被重载？
构造函数可以被重载，析构函数不可以被重载。因为析构函数只能有一个且不带参数。

## 拷贝(复制)构造函数
```c++
class Line
{
    public:
    	Line(int len);  //构造函数
    	Line(const Line &obj);  //拷贝构造函数
    	~Line();  //  析构函数
    
    private:
    	int *ptr;
};

// 成员函数定义，包括构造函数
Line::Line(int len)
{
    cout << "调用构造函数" << endl;
    // 为指针分配内存
    ptr = new int;
    *ptr = len;
}
 
Line::Line(const Line &obj)
{
    cout << "调用拷贝构造函数并为指针 ptr 分配内存" << endl;
    ptr = new int;
    *ptr = *obj.ptr; // 拷贝值
}
 
Line::~Line(void)
{
    cout << "释放内存" << endl;
    delete ptr;
}
```

## 委托构造函数
C++11扩展了构造函数初始值功能，可以定义委托构造函数。委托构造函数使用它所属类的其他构造函数执行它自己的初始化过程。


## = default和= delete

在C++中，声明自定义的类型之后，编译器会默认生成一些成员函数，这些函数被称为默认函数。其中包括：
```c++
class A
{
    // C++03
    A();                     // 默认构造函数
    A(const A &);            // 拷贝构造函数
    ~A();                    // 析构函数
    A &operator=(const A &); // 拷贝赋值运算符

    // C++11 新增
    A(A &&);            // 移动构造函数
    A &operator=(A &&); // 移动赋值运算符
};
```


### = delete 显式删除函数
另一方面，有时候可能需要限制一些默认函数的生成。

例如：需要禁止拷贝构造函数的使用。以前通过把拷贝构造函数声明为private访问权限，这样一旦使用编译器就会报错。

而在 C++11 中，只要在函数的定义或者声明后面加上= delete就能实现这样的效果。这种方式不容易犯错，且更容易理解。

在C ++ 11之前，操作符delete 只有一个目的，即释放已动态分配的内存。而C ++ 11标准引入了此操作符的另一种用法，即：禁用成员函数的使用。这是通过附加= delete说明符到该函数声明的结尾。

