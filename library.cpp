#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Book
{
private:
	string bookName;
	string isbn;//ISBN编号
	string publisher;//出版社
	double price;//价格
	int page;
	bool isAvailable;//是否可借阅
public:
	//默认构造函数（无参）
	Book();
	//重载构造函数，全部参数
	Book(string bName, string isbn_, string  pub, double pri, int pag, bool avail);
	//set 设置成员
	void setBookName(string name);
	void setISBN(string isbn_);
	void setPublisher(string pub);
	void setPrice(double pri);
	void setPage(int pag);
	void setAvailability(bool avail);
	//get 获取成员,const代表不修改对象
	string getBookName() const;
	string getISBN() const;
	string getPublisher() const;
	double getPrice() const;
	int getPage() const;
	bool getAvailable() const;
	//校验isbn编号是否合法
	bool checkISBNValid(string isbn);
	//打印图书信息
	void showInfo() const;
};
//默认构造函数
Book::Book()
{
	bookName = "unknown bookName";
	isbn = "000-0-00000-000-0";
	publisher = "unknown publisher";
	price = 0.0;
	page = 0;
	isAvailable = true;
}
//重载构造函数
Book::Book(string bName, string isbn_, string  pub, double pri, int pag, bool avail)
{
	bookName = bName;
	if (checkIsbnValid(isbn_))
		isbn = isbn_;
	else
		isbn = "000-0-00000-000-0";
	publisher = pub;
	price = pri;
	page = pag;
	isAvailable = avail;
}
//set函数实现
void Book::setBookName(string name) { bookName = name; }
void Book::setISBN(string isbn_) { if (checkIsbnValid(isbn_)) isbn = isbn_; }
void Book::setPublisher(string pub) { publisher = pub; }
void Book::setPrice(double pri) { price = pri; }
void Book::setPage(int pag) { page = pag; }
void Book::setAvailability(bool avail) { isAvailable = avail; }
//get函数实现
string Book::getBookName() const { return bookName; }
string Book::getISBN() const { return isbn; }
string Book::getPublisher() const { return publisher; }
double Book::getPrice() const { return price; }
int Book::getPage() const { return page; }
bool Book::getAvailable() const { return isAvailable; }
//校验isbn编号是否合法
bool Book::checkIsbnValid(string isbn) {
	return isbn.size() == 13;
}
//输出一本书的全部信息
void Book::showInfo() const {
	cout << "Book Name: " << bookName << endl;
	cout << "ISBN: " << isbn << endl;
	cout << "Publisher: " << publisher << endl;
	cout << "Price: $" << price << endl;
	cout << "Page Count: " << page << endl;
	cout << "Availability: " << (isAvailable ? "Available" : "Not Available") << endl;
}
//打印系统菜单
void showMenu() {
	cout << "\n********** Library System **********" << endl;
	cout << "1. Add Book" << endl;
	cout << "2. Show All Books" << endl;
	cout << "3. Borrow Book" << endl;
	cout << "4. Return Book" << endl;
	cout << "0. Exit" << endl;//退出系统
	cout << "please select an option: ";
}
//添加图书
void addBook(vector<Book>& booklist) {
	string name, isbn, publisher;
	double price;
	int page;
	cout << "Enter book name: ";
	cin>>name ;
	cout << "Enter ISBN (13 digits): ";
	cin >> isbn;
	cout << "Enter publisher: ";
	cin,>>publisher;
	cout << "Enter price: ";
	cin >> price;
	cout << "Enter page count: ";
	cin >> page;
	Book newBook(name, isbn, publisher, price, page, true);
	if (!newBook.checkISBNValid(isbn))
		cout << "Invalid ISBN format. Book not added.\n" << endl;"
	booklist.push_back(newBook);
	cout << "Book added successfully!\n" << endl;
}
//显示所有图书
void showAllBooks(const vector<Book>& booklist) {
	if (booklist.empty()) {
		cout << "No books in the library.\n" << endl;//暂无图书记录
		return;
	}
	for (int i = 0;i < booklist.size();i++) {
		cout << i + 1 << ".";
		booklist[i].showInfo();
	}
}