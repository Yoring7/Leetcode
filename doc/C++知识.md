# C++

## 数据和函数

```c++
#ifndef __COMPLEX__
#define __COMPLEX__
#include <cmath>

template<typename T>
class complex
{
private:
    T re, im;
    friend complex& __doapl(complex*, const complex&);
public:
    // inline内部函数 比较快
    complex(T r = 0, T i = 0) : re(r), im(i){}
    complex& operator += (const complex&);
    int func(const complex& param);
    T real()const	{return re;}
    T imag()const	{return im;}
    ~complex();
};

#endif
```

### 值传递和引用传递

- 尽量用引用传递，尽量用引用返回`complex& operator += (const complex&)`
- 不想被改const + &

### 相同class的各个对象互为友元

```c++
inline int func(const complex& param)
{
    return param.re + param.im;
}
```



### 构造函数可以在private中

```c++
class A
{
public:
    static A& getInstance();
    setup(){}
private:
    A();
    A(const A& rhs);
};

A& A::getInstance()
{
    static A a;
    return a;
}
```





## Class

### 



### 浅拷贝深拷贝

发生在拷贝构造函数中eg：Person(const Person &p)
浅拷贝就是将p.age之类的直接拷贝过来
而深拷贝针对在堆区开辟的内容再额外开辟堆区空间eg：height = new int (*height)

### 继承 class Son：public Base 

创建子类就会先创建父类
先构造父类，再构造子类
先析构子类，再析构父类

父类和子类中同名成员属性：直接访问就是子类的 s.age，想要拿到父类的同名：s.Base::age需要加上作用域
同名的成员函数：直接调用就是子类的 s.func()，访问父类就必须 s.Base::func()

### 多态

- 





