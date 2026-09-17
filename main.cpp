#include<iostream>
#include<string>
using namespace std;
class Book 
	//图书类Book
{
private:
	//私有成员变量
	int id;
	string name;
	string author;
	int totalNum;
	int remainNum;
public:
	//构造函数：创建对象自动调用
	Book(int i, string n, string a, int t, int r)
	{
		id = i;
		name = n;
		author = a;
		totalNum = t;
		remainNum = r;
	}
	int getID()
		//读取私有变量
	{
		return id;
	}
	string getName()
	{
		return name;
	}
	string getAuthor()
	{
		return author;
	}
	int getTotal()
	{
		return totalNum;
	}
	int getRemain()
	{
		return remainNum;
	}
	//打印图书信息
	void showInfo()
	{
		cout << "ID:" << id << endl;
		cout << "Name:" << name << endl;
		cout << "Author:" << author << endl;
		cout << "TotalNum:" << totalNum << endl;
		cout << "RemainNum:" << remainNum << endl;
	}
	//借书
	void borrowBook()
	{
		if (remainNum > 0)
		{
			remainNum--;
			cout << "Borrow success" << endl;
		}
		else
		{
			cout << "Borrow failed, no stock available" << endl;
		}
	}
	//还书
	void returnBook()
	{
		if (remainNum < totalNum)
		{
			remainNum++;
			cout << "Return success" << endl;
		}
		else
		{
			cout << "Return failed, stock is full" << endl;
		}
	}
};
int main()
{
	//创建图书对象
	Book b1(1001, "c++","San", 5, 3);
	Book b2(1002, "DataStruct","Si", 8, 6);
	//展示信息
	b1.showInfo();
	b2.showInfo();
	//测试借书
	b1.borrowBook();
	cout <<"After Borrow:"<< endl;
	b1.showInfo();
	return 0;
}