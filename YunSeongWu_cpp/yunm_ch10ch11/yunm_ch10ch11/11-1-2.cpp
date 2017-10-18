#include <iostream>
#include <cstring>

using namespace std;

class Book
{
private:
	char * title;
	char * isbn;
	int price;
public:
	Book(char*i_title, char*i_isbn, int i_price)
		:price(i_price)
	{
		title = new char[strlen(i_title) + 1];
		strcpy(title, i_title);
		isbn = new char[strlen(i_isbn) + 1];
		strcpy(isbn, i_isbn);
	}
	Book(const Book& bb)
		:price(bb.price)
	{
		title = new char[strlen(bb.title) + 1];
		strcpy(title, bb.title);
		isbn = new char[strlen(bb.isbn) + 1];
		strcpy(isbn, bb.isbn);
	}
	~Book()
	{
		delete[] title;
		delete[] isbn;
	}
	void ShowBookInfo()
	{
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}
	Book& operator=(const Book& cp)
	{
		price = cp.price;
		delete[] title;
		delete[] isbn;
		title = new char[strlen(cp.title) + 1];
		strcpy(title, cp.title);
		isbn = new char[strlen(cp.isbn) + 1];
		strcpy(isbn, cp.isbn);
		return *this;
	}
};

class Ebook : public Book
{
private:
	char * DRMKey;
public:
	Ebook(char*i_title, char*i_isbn, int i_price, char*DRM)
		:Book(i_title, i_isbn, i_price)
	{
		DRMKey = new char[strlen(DRM) + 1];
		strcpy(DRMKey, DRM);
	}
	Ebook(const Ebook& bb)
		:Book(bb)
	{
		DRMKey = new char[strlen(bb.DRMKey) + 1];
		strcpy(DRMKey, bb.DRMKey);
	}
	~Ebook()
	{
		delete[] DRMKey;
	}
	Ebook& operator=(const Ebook& cb)
	{
		Book::operator=(cb);
		delete[] DRMKey;
		DRMKey = new char[strlen(cb.DRMKey) + 1];
		strcpy(DRMKey, cb.DRMKey);
		return *this;
	}
	void ShowBookInfo()
	{
		Book::ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}
};
int yunm11_1_2(void)
{
	Book book("좋 cpp", "555-12354-890-0", 20000);
	Book abook("a", "b", 1);
	abook = book;
	abook.ShowBookInfo();
	cout << endl;

	Ebook ebook("좋c ebook", "555-12354-890-1", 10000, "asfgawtgwae");
	Ebook xk("a", "c", 3, "asad");
	xk = ebook;
	xk.ShowBookInfo();
	return 0;
}