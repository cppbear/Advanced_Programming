#include <iostream>
#include "Iter.h"
//#include "CacheQueue.h"
using namespace std;

int main()
{
	/*
	CacheQueue<double, 2> cache_queue;//初始化⼀个存储数据类型为double的缓存队列
	cache_queue.push(1.1);
	cache_queue.push(2.2);
	cout << cache_queue.push(3.3);//1.1被弹出，3.3被放⼊，同时返回false
	cout << cache_queue.push(4.4);//2.2被弹出，4.4被放⼊，同时返回false
	cache_queue[1] = 7.7;//4.4被修改为了7.7
	*cache_queue.begin() = 1.1;
	*/
	
	CacheQueue<int, 10> cache_queue;
	cache_queue.push(1);
	cache_queue.push(2);
	cache_queue.push(3);
	cache_queue.push(4);
	cache_queue.push(5);
	Iter<int, 10> iter = cache_queue.begin();//获得缓存队列的begin迭代器，即指向1的迭代器
	++iter;//将迭代器iter向前移动⼀个位置，当前iter指向2
	iter++;//将迭代器iter向前移动⼀个位置，当前iter指向3
	//循环打印迭代器指向数据并递增迭代器，直到迭代器指向cache_queue的end迭代器
	//结果是"3 4 5 "
	while (iter != cache_queue.end())
	{
		cout << *iter << ' ';//访问iter指向的元素
		iter++;
	}
	Iter<int, 10> second_iter(iter);//通过拷⻉构造函数创建新的迭代器对象
	Iter<int, 10> third_iter(cache_queue, 2);//创建⼀个绑定到cache_queue的迭代器，并指向数据3
	third_iter = second_iter;
	
	return 0;
}
