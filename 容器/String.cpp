#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
/*定义字符串*/	
	cout<<"---定义字符串---"<<endl;
	//可以直接定义一个空字符串
	string str1;
	cout<<"eg.1: "<<str1<<endl;
	
	//定义内容为"123456789"的字符串
	string str2("123456789"); 
	cout<<"eg.2: "<<str2<<endl;
	
	//从字符串"12345"中截取从1位置开始，长度为3的字符串"234"
	string str3("12345", 1, 3);
	cout<<"eg.3: "<<str3<<endl;
	
	//从字符串"12345"中截取从0位置开始，长度为3的字符串，结果为"123"
	string str4("123456", 3); 
	cout<<"eg.4: "<<str4<<endl;
	
	//构造5个字符'2'连接而成的字符串，结果为"22222" 
	string str5(5, '2'); 
	cout<<"eg.5: "<<str5<<endl;
	
	//结果为"3456789"，截取第三个元素（2对应第三位）到最后
	string str6(str2, 2);
	cout<<"eg.6: "<<str6<<endl;
	
/*函数与方法*/
	cout<<"----函数与方法---"<<endl;
	
	cout<<"\nP1-获取字符串长度"<<endl;
	cout<<"s.size()   str2的长度："<<str2.size()<<endl;
	cout<<"s.length() str2的长度："<<str2.length()<<endl;
	cout<<"string对象最多包含的字符数:"<<str2.max_size()<<endl;
	cout<<"重新分配内存之前，string对象能包含的最大字符数:"<<str2.capacity()<<endl;
	
	cout<<"\nP2-插入"<<endl;
	string str("abcd");
	cout<<"插入前:"<<str<<endl;
	str.push_back('=');//在末尾插入一个字符
	cout<<"插入'='后:"<<str<<endl;
	str.insert(str.begin()+2,'+');//在2位置插入一个字符，s.end()同理(这里的位置好像要用迭代器才行)
	cout<<"插入'+'后:"<<str<<endl;
	str.append("123");//在str字符串结尾添加"123"字符串
	cout<<"插入'123'后:"<<str<<endl;
	
	cout<<"\nP3-删除"<<endl;
	str.erase(str.begin()+2);//删除字符串中p所指的字符(这里的位置好像要用迭代器才行)
	cout<<"删除2位置后:"<<str<<endl;
	str.erase(0,1);//删除字符串中迭代器区间[first,last)上所有字符(这里的位置好像要用迭代器才行)
	cout<<"删除后:"<<str<<endl;
	str.clear();
	cout<<"清空后:"<<str<<endl;
	
	str="abcdef";
	cout<<"\nP4-字符替换"<<endl;
	str.replace(0,2,"123");//替换从0开始，长度为2的字符串为123.(这里的位置好像用数字就行)
	cout<<"替换后:"<<str<<endl;str="abcdef";
	str.replace(0,1,3,'=');//把当前字符串从索引pos开始的n个字符替换为n1个字符c
	cout<<"替换后:"<<str<<endl;
	
	str="abcdef";
	cout<<"\nP5-大小写转换"<<endl;
	transform(str.begin(),str.end(),str.begin(),::toupper);//大写
	cout<<str<<endl;
	
	cout<<"\n自由使用"<<endl;
	string s="hgafklgshfdggf";
//	sort(s.begin(),s.end());  //按ASCII码排序
	string s2="fajdfg";
	cout<<(s>s2)<<endl;
	
	char ss[]="qqqqqqqq";
	string sss=ss;
	cout<<sss<<endl;
	return 0;
}
