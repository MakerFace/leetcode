# Leetcode模板

1. 目录结构

![image-20221024213329264](https://raw.githubusercontent.com/MakerFace/images/main/image-20221024213329264.png)

2. 使用方法

   创建题目：`./create.sh 题号`

   ![image-20221024213421322](https://raw.githubusercontent.com/MakerFace/images/main/image-20221024213421322.png)

   在当月/当日文件夹下生成源码和输入

3. 在leetcode.cn中**复制**解决方案

4. 在vscode中输入`solution`，然后回车。

   ![image-20221024213553818](https://raw.githubusercontent.com/MakerFace/images/main/image-20221024213553818.png)

   ![image-20221024213657745](https://raw.githubusercontent.com/MakerFace/images/main/image-20221024213657745.png)

   键入`tab`可跳转到上一行，调整输入。

   > 由于我使用了clangd插件，所以不用一个个**手动导入**头文件，它会根据具体使用情况自动导入。
   >
   > 如果没有使用该插件，可以在`.vscode/cpp.json.code-snippets`自行加入`#include <bits/stdc++.h>`，自己修改author值。
   >
   > ![image-20221024214005582](https://raw.githubusercontent.com/MakerFace/images/main/image-20221024214005582.png)

5. 从文件中**按行**读取输入

   如果多个输入就再读一行。

   - vector：在`common/Vector.hpp`中实现向量方法。

     输入`auto nums = string2vector<string>(buf);`，默认模板参数是`int`，int可不加。

   - list：在`common/ListNode.hpp`中实现链表。

     输入`auto head = string2list(buf);`。

   - tree：在`common/TreeNode.hpp`中实现链表。

     输入`auto root = string2tree(buf);`。

   - graph

     输入`auto graph = string2graph(buf);`。

   输出直接使用`cout`。

   需注意

   - 指针需要解引用，例如`std::cout << *root << std::endl;`。
   - list，tree需要回收内存，`delete_list`，`delete_tree`。

   ![image-20221024213151890](https://raw.githubusercontent.com/MakerFace/images/main/image-20221024213151890.png)

6. 构建

   `./build.sh`

7. 执行

   `bin/题目`。

8. 分享给其他人

   `./export.sh`

有问题可以反馈，邮箱：chenqi@imudges.com。

