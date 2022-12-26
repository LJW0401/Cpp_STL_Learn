# C++STL库的学习<br>

&emsp;&emsp;简介：C++中STL库的学习<br>

## 快速定位<br>
[主要组件](#主要组件)<br>
[详细使用](#详细使用)<br>
[相关资料](#相关资料)<br>
<br>

## 主要组件<br>

### &emsp;容器<br>

&emsp;&emsp;用来存放数据的容器<br>
&emsp;&emsp;&emsp;[string](#string) 字符串<br>
&emsp;&emsp;&emsp;vector 动态数组<br>
&emsp;&emsp;&emsp;deque 双端队列<br>
&emsp;&emsp;&emsp;stack 栈<br>
&emsp;&emsp;&emsp;queue 队列<br>
&emsp;&emsp;&emsp;list 链表<br>
&emsp;&emsp;&emsp;set 集合<br>
&emsp;&emsp;&emsp;map 映射<br>
&emsp;&emsp;&emsp;pair 二元组<br>

### &emsp;算法<br>
### &emsp;迭代器<br>

&emsp;[快速定位](#快速定位)<br>

## 详细使用

### String
&emsp;&emsp;介绍：string是一个字符串类，和char型字符串类似。在string类中包含了许多字符串处理的函数可供调用。<br>

* 实操代码详见 [String.cpp](https://github.com/LJW0401/Cpp_STL_Learn/blob/main/%E5%AE%B9%E5%99%A8/String.cpp)<br>

* 加载文件：`#include<string>`<br>

* 简单操作：<br>
&emsp;&emsp;访问单个字符：```s[i]//返回s中的第i个字符```<br>
&emsp;&emsp;字符串比较： ```s1<s2//返回0或1``` 和数字比较大小的操作一样<br>
&emsp;&emsp;字符串的连接: ```s1+s2``` 是的直接将2个字符串相加即可，和Python一样。<br>

* 字符串的读入<br>
    1.```cin>>s``` 读入字符串，遇空格，回车结束。<br>
    2.```getline(cin,s);```读入一行字符串（包括空格），遇回车结束。<br>
    <font color=#ff3333>&emsp;&emsp;注意！！！ getline(cin,s)会获取前一个输入的换行符，需要在前面添加读取换行符的语句。如：getchar() 或 cin.get()</font><br>
    3.cin>>与cin.getline()混用<br>
    &emsp;&emsp;cin输入完后，回车，cin遇到回车结束输入，但回车还在输入流中，cin并不会清除，导致getline（）读取回车，结束。 (即上述注意点)
需要在cin后面加cin.ignore();主动删除输入流中的换行符

* 字符串的输出<br>
    &emsp;&emsp;```cin<<s<<endl;```<br>
    &emsp;&emsp;cin和cout解锁，代码如下：
    ```c++ 
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    ```
    &emsp;&emsp;对cin和cout进行解锁使cin和cout的速度几乎接近scanf和printf，避免超时。<br>
    <font color=#ff3333>&emsp;&emsp;注意：cin cout解锁使用时，不能与 scanf 、getchar, printf,cin.getline( ) 混用，一定要注意，会出错。</font><br>

* string与C语言中字符数组表示的字符串的相互转换<br>
    string转成字符数组: ```char ss[100];strcpy(ss,s.c_str());```<br>
    字符数组转成string: ```char ss[100];string s=ss;```<br>

*   >函数与方法<br>
    >>获取字符串长度:<br>
    >>|代码|含义|
    >>|:--:|:--:|
    >>|s.size()<br>s.length()|返回string对象的字符个数，他们执行效果相同。|
    <!-- >>|s.max_size()|返回string对象最多包含的字符数，超出会抛出length_error异常|
    >>|s.capacity()|重新分配内存之前，string对象能包含的最大字符数| -->

    >>插入:<br>
    >>|代码|含义|
    >>|:--:|:--:|
    >>|s.push_back()|在末尾插入|
    >>|s.insert(pos,char)|在pos位置插入char<br><font color=#ff3333>注：pos要用迭代器来标志位置</font>|
    >>|s.append(str)|在s字符串结尾添加str字符串|

    >>删除:<br>
    >>|代码|含义|
    >>|:--:|:--:|
    >>|s.erase(iterator p)|删除字符串中p所指的字符<br><font color=#ff3333>注：这里要用迭代器来标志字符位置，如果用数字的话则删除从该位置开始往后的所有字符</font>|
    >>|erase(first,last)|删除字符串中迭代器区间[first,last)上所有字符<br><font color=#ff3333>注：这里可以用数字来直接表示位置</font>|
    >>|clear()|删除字符串中所有字符|

    >>字符替换:<br>
    >>|代码|含义|
    >>|:--:|:--:|
    >>|s.replace(pos,n,str)|把当前字符串从索引pos开始的n个字符替换为str|
    >>|s.replace(pos,n,n1,c)|把当前字符串从索引pos开始的n个字符替换为n1个字符c|
    <!-- >>|s.replace(it1,it2,str)|把当前字符串[it1,it2)区间替换为str(it1 ,it2为迭代器哦)| -->

    >>大小写转换:<br>
    >>|代码|含义|
    >>|:--:|:--:|
    >>|tolower(s[i])|转换为小写|
    >>|toupper(s[i])|转换为大写|
    >>
    >><font color=#ff3333>大小写转换函数需搭配transform算法一起使用：</font><br>
    >>```transform(s.begin(),s.end(),s.begin(),::tolower);//转换小写```<br>
    >>```transform(s.begin(),s.end(),s.begin(),::toupper);//转换大写```<br>
    >>transform有4个参数，前2个指定要转换的容器的起止范围，第3个参数是结果存放容器的起始位置，第4个参数是一元运算。<br>

    >>查找:<br>
    >>|代码|含义|
    >>|:--:|:--:|
    >>|s.find(str, pos)|在当前字符串的pos索引位置(默认为0)开始，查找子串str，返回找到的位置索引，-1表示查找不到子串|
    >>|s.find(c, pos)|在当前字符串的pos索引位置(默认为0)开始，查找字符c，返回找到的位置索引，-1表示查找不到字符|
    >>|s.rfind(str, pos)|在当前字符串的pos索引位置开始，反向查找子串s，返回找到的位置索引，-1表示查找不到子串|
    >>|s.rfind(c,pos)|在当前字符串的pos索引位置开始，反向查找字符c，返回找到的位置索引，-1表示查找不到字符|
    <!-- >>|s.find_first_of(str, pos)|在字符串s的pos索引位置(默认为0)开始，查找字符串str中的字符第一次在s中出现的位置，返回找到的位置索引，-1表示查找不到字符|
    >>|s.find_first_not_of(str,pos)|在当前字符串的pos索引位置(默认为0)开始，查找第一个不位于子串s的字符，返回找到的位置索引，-1表示查找不到字符|
    >>|s.find_last_of(str, pos)|在当前字符串的pos索引位置开始，查找最后一个位于子串s的字符，返回找到的位置索引，-1表示查找不到字符|
    >>|s.find_last_not_of( str, pos)|在当前字符串的pos索引位置开始，查找最后一个不位于子串s的字符，返回找到的位置索引，-1表示查找不到子串| -->

    >>对字符串中的字符排序: ```sort(s.begin(),s.end());  //按ASCII码排序```<br>

    &emsp;[快速定位](#快速定位)<br>

## 相关资料<br>

### 其他人的资料<br>
[EasySTL](https://github.com/hunterzhao/EasySTL.git) 学习STL过程，自己实现的STL代码<br>
