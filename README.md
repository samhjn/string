# C++ string类实现

> A very simple implementation of C++ string

## 许可协议 License

No License, free to use.

无许可协议，请随意使用。

## 警告 Warning

The library is a test library. It may not as efficient and safety as C++ standard library.

This is not for production systems. Please use std::string instead.

该库文件仅供测试使用。此库有可能无法达到C++标准库的效率与安全性。

它不是为生产系统设计的。请使用std::string替代它。

## 功能 Functions

1. 实现了多种构造函数

    Constructor

2. 实现了迭代器

    Iterator

3. 实现了字符串比较、字符串连接的符号重载

    Comparation, Concat, Overload

4. 通过memcpy()获得了尚可的效率

    Used memcpy() to enhance efficency

5. 部分支持iostream输入输出

    Partly support iostream operations

## 缺点 Shortcomings

1. 未实现动态容量控制

    No dynamic capacity

2. 未实现对iostream中getline()的支持

    Do not support getline()

3. 未实现find()等字符串操作

    Do not support find() etc.

## 使用 Usage

如果需要使用该库（强烈不推荐），首先执行

If you want to use this library (strongly not recommand), please execute the following command first

```bash
make string.o
```

随后在编译项目的时候，增加本库`include`与`lib`的位置参数。

Then please add the params to specify `include` and `lib` directory of the library when you compile your project.

如果仅需查看该库的运行效果，请执行

If you only need to evaluate the library, please execute the following command

```bash
make all
```

该指令会生成`test_default`与`test_origin`两个可执行文件，分别使用该库与C++标准库。

The command will generate two executable named `test_default` and `test_origin`, which uses this library and C++ standard library. 
