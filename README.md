# C++STL库的学习<br>

&emsp;&emsp;简介：C++中STL库的学习(主要偏向竞赛方面)<br>
&emsp;&emsp;[C++ STL详解超全总结](https://blog.csdn.net/qq_50285142/article/details/114026148?ops_request_misc=&request_id=&biz_id=102&utm_term=STL&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-1-114026148.142^v68^control,201^v4^add_ask,213^v2^t3_esquery_v3&spm=1018.2226.3001.4187) (快速入门STL)
## 快速定位<br>
[主要组件](#主要组件)<br>
[详细使用](#详细使用)<br>
[相关资料](#相关资料)<br>
<br>

## 主要组件<br>
C++万能头文件：```#include<bits/stdc++.h>```

### &emsp;容器<br>

&emsp;&emsp;用来存放数据的容器<br>
<font color=#ff3333>&emsp;&emsp;注意：.end()返回的是最后一个元素的后一个位置的地址，不是最后一个元素的地址,所有容器均是如此<br></font>
&emsp;&emsp;&emsp;[string](#string) 字符串<br>
&emsp;&emsp;&emsp;[vector](#vector) 动态数组<br>
&emsp;&emsp;&emsp;deque 双端队列<br>
&emsp;&emsp;&emsp;[stack](#stack) 栈<br>
&emsp;&emsp;&emsp;[queue](#queue) 队列<br>
&emsp;&emsp;&emsp;priority_queue <br>
&emsp;&emsp;&emsp;list 链表<br>
&emsp;&emsp;&emsp;[set](#set) 集合<br>
&emsp;&emsp;&emsp;[map](#map) 映射<br>
<!-- &emsp;&emsp;&emsp;pair 二元组<br> -->

### &emsp;算法<br>

&emsp;&emsp;&emsp;sort<br>
&emsp;&emsp;&emsp;swap<br>
&emsp;&emsp;&emsp;next_permutation<br>
&emsp;&emsp;&emsp;max<br>
&emsp;&emsp;&emsp;min<br>
&emsp;&emsp;&emsp;transform<br>

### &emsp;迭代器<br>

&emsp;[快速定位](#快速定位)<br>

## 详细使用

### String<br>
&emsp;&emsp;介绍：string是一个字符串类，和char型字符串类似。在string类中包含了许多字符串处理的函数可供调用。<br>

* 实操代码详见 [String.cpp](https://github.com/LJW0401/Cpp_STL_Learn/blob/main/%E5%AE%B9%E5%99%A8/String.cpp)<br>

* 加载文件：`#include<string>`<br>

* 初始化：<br>
```C++
	//可以直接定义一个空字符串
	string str1;

	//定义内容为"123456789"的字符串
	string str2("123456789"); 
	
	//从字符串"12345"中截取从1位置开始，长度为3的字符串"234"
	string str3("12345", 1, 3);
	
	//从字符串"12345"中截取从0位置开始，长度为3的字符串，结果为"123"
	string str4("123456", 3); 
	
	//构造5个字符'2'连接而成的字符串，结果为"22222" 
	string str5(5, '2'); 
	
	//结果为"3456789"，截取第三个元素（2对应第三位）到最后
	string str6(str2, 2);
```

* 简单操作：<br>
&emsp;&emsp;字符串的赋值：```s="abcd"``` 直接等号赋值就可以了<br>
&emsp;&emsp;访问单个字符：```s[i]//返回s中的第i个字符```<br>
&emsp;&emsp;字符串比较： ```s1<s2//返回0或1``` 和数字比较大小的操作一样<br>
&emsp;&emsp;字符串的连接: ```s1+s2``` 是的直接将2个字符串相加即可，和Python一样。<br>
&emsp;&emsp;判断是否为空字符串：```s.empty()```为空则返回1<br>

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

&emsp;&emsp;[快速定位](#快速定位)<br>

### Vector<br>

&emsp;&emsp;介绍：vector为可变长数组（动态数组），定义的vector数组可以随时添加数值和删除元素.<br>

* 代码实操详见：[]()<br>

* 加载头文件：```#include<vector>```<br>

* 初始化：<br>
```C++
    //一维初始化
	vector<int>num1; //定义了一个名为num的存int数据的一维数组
	vector<double>num2;//定义了一个名为num的存double数据的一维数组
	
	//指定长度和初始值的初始化
	vector<int> v1(n);//定义一个长度为n的数组，动态定义，不指定初值默认初值为0
	vector<int> v2(n, 0);//所有的元素均为0
	//注意：指定数组长度之后（指定长度后的数组就相当于正常的数组了）
	
	//初始化中有多个元素
	vector<int> a1{1, 2, 3, 4, 5};// 数组a中有五个元素

	//拷贝初始化
	vector<int> a2(n + 1, 0);
	vector<int> b1(a2);//两个数组中的类型必须相同,a和b都是长度为n+1，所有值都为0的数组
	
	
	//二维初始化
	//定义第一维固定长度为5，第二维可变化的二维数组
	vector<int>num3[5];//定义可变长二维数组
	//注意：行是不可变的（只有5行），而列可变可以在指定行添加元素
	//第一维固定长度为5，第二维长度可以改变
	
	//行列均可变
	//初始化二维均可变长数组
	vector<vector<int>>num4;//定义一个行和列均可变的二维数组

	//行列长度均固定 n + 1行 m + 1列初始值为0
	vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
```

* 简单操作：和普通的数组一样<br>
```C++
    //智能指针操作，这种操作可以直接输出数组中的内容
    for(auto i : num)
        cout << i << " ";
```

* 方法函数<br>

|代码|含义|
|:--:|:--:|
|c.front()|返回第一个数据|
|c.pop_back()|删除最后一个数据 O(1)|
|c.push_back(element)|在尾部加一个数据 O(1)|
|c.size()|返回实际数据个数（unsigned类型） O(1)|
|c.clear()|清除元素个数 O(N),N为元素个数|
|c.resize(n,v)|改变数组大小为n,n个空间数值赋为v，如果没有默认赋值为0|
|c.insert(it,x)|向任意迭代器it插入一个元素x O(N)|
|例：c.insert(c.begin()+2,-1)|将-1插入c[2]的位置|
|c.erase(first,last)|删除[first,last)的所有元素|
|c.begin()|返回首元素的迭代器（通俗来说就是地址）|
|c.end()|返回最后一个元素后一个位置的迭代器（地址）|
|c.empty()|判断是否为空，为空返回真，反之返回假|

* 排序：<br>
```C++
sort(it_1,it_2);
sort(c.begin(),c.end());//例子，it可以随便改动
```
<br>

&emsp;&emsp;[快速定位](#快速定位)<br>

### Stack<br>


&emsp;&emsp;[快速定位](#快速定位)<br>

### Queue<br>





&emsp;&emsp;[快速定位](#快速定位)<br>

### Set<br>



&emsp;&emsp;[快速定位](#快速定位)<br>

### Map<br>



&emsp;&emsp;[快速定位](#快速定位)<br>

## 相关资料<br>

### 关于STL在算法竞赛中的运用
[STL在算法竞赛中的应用](https://www.cnblogs.com/lilpig/p/13909357.html)<br>
[算法竞赛常用STL万字总结](https://blog.csdn.net/weixin_49486457/article/details/123439229?spm=1001.2101.3001.6650.4&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-4-123439229-blog-126175583.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-4-123439229-blog-126175583.pc_relevant_multi_platform_whitelistv3&utm_relevant_index=5)<br>
[算法竞赛常用STL](https://blog.csdn.net/MaTF_/article/details/126083717?spm=1001.2101.3001.6650.8&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-8-126083717-blog-126175583.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-8-126083717-blog-126175583.pc_relevant_multi_platform_whitelistv3&utm_relevant_index=9)<br>
[C++ STL(竞赛常用部分)](https://blog.csdn.net/ccDLlyy/article/details/53264498?spm=1001.2101.3001.6650.9&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-9-53264498-blog-126175583.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-9-53264498-blog-126175583.pc_relevant_multi_platform_whitelistv3&utm_relevant_index=10)<br>

### 相关练习
[LC刷题计划](https://leetcode.cn/leetbook/read/illustration-of-algorithm/px2ds5/)

### 其他人的资料<br>
[EasySTL](https://github.com/hunterzhao/EasySTL.git) 学习STL过程，自己实现的STL代码<br>
[C++ STL详解超全总结(快速入门STL)](https://blog.csdn.net/qq_50285142/article/details/114026148?ops_request_misc=&request_id=&biz_id=102&utm_term=STL&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-1-114026148.142^v68^control,201^v4^add_ask,213^v2^t3_esquery_v3&spm=1018.2226.3001.4187)

&emsp;&emsp;[快速定位](#快速定位)<br>
