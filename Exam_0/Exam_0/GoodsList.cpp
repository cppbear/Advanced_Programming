#include <iostream>
#include <string>
#include "GoodsList.h"
using namespace std;

Goods::Goods(string name, int nums)
{
	this->name = name;
	this->nums = nums;
}

void Goods::show()
{
	cout << name << ',' << nums;
}

void Goods::Add(Goods* goods)
{
	nums += goods->nums;
}

int Goods::Remove(int n)
{
	if (nums > n)
	{
		nums -= n;
		return 0;
	}
	else if (nums == n)
	{
		return 1;
	}
	else
	{
		cout << "Not enough goods!\n";
		return 2;
	}
}

GoodsList::GoodsList()
{
	list = new Node;
	list->next = nullptr;
}

void GoodsList::insert(Goods* goods)
{
	Node* p;
	for (p = list; p->next; p = p->next)
	{
		if (p->next->goods->TypeOfGoods() == goods->TypeOfGoods())
		{
			p->next->goods->Add(goods);
			break;
		}
	}
	if (!p->next)
	{
		Node* q = new Node;
		q->goods = goods;
		q->next = nullptr;
		p->next = q;
	}
}

void GoodsList::remove(string name, int nums)
{
	Node* p;
	if (!list || !list->next)
	{
		cout << "Not enough goods!\n";
		return;
	}
	for (p = list; p->next; p = p->next)
	{
		if (p->next->goods->TypeOfGoods() == name)
		{
			int flag = p->next->goods->Remove(nums);
			if (flag == 1)
			{
				Node* q = p->next;
				p->next = q->next;
				delete q;
			}
			break;
		}
	}
	if (!p->next)
		cout << "Not enough goods!\n";
}

void GoodsList::show()
{
	if (!list || !list->next)
	{
		cout << endl;
		return;
	}
	Node* p;
	for (p = list->next; p->next; p = p->next)
	{
		p->goods->show();
		cout << ' ';
	}
	p->goods->show();
	cout << endl;
}

void GoodsList::sort()
{
	if (!list || !list->next)
		return;
	for (Node* p = list->next; p->next; p = p->next)
	{
		Goods* max = p->goods;
		for (Node* q = p->next; q; q = q->next)
		{
			if (q->goods->NumOfGoods() > max->NumOfGoods())
				max = q->goods;
		}
		if (max->TypeOfGoods() != p->goods->TypeOfGoods())
		{
			string tempName = p->goods->TypeOfGoods();
			p->goods->ChangeName(max->TypeOfGoods());
			max->ChangeName(tempName);
			int tempNum = p->goods->NumOfGoods();
			p->goods->ChangeNum(max->NumOfGoods());
			max->ChangeNum(tempNum);
		}
	}
}

int GoodsList::count()
{
	int res = 0;
	if (!list)
		return 0;
	for (Node* p = list->next; p; p = p->next)
		res++;
	return res;
}

void GoodsList::clear()
{
	for (Node* p = list; p->next;)
	{
		Node* q = p->next;
		p->next = q->next;
		delete q;
	}
	list = nullptr;
}
