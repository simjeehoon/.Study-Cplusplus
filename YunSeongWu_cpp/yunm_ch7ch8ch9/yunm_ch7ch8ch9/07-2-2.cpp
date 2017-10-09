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
	~Book()
	{
		delete title;
		delete isbn;
	}
	void ShowBookInfo()
	{
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}
};

class Ebook : public Book
{
private:
	char * DRMKey;
public:
	Ebook(char*i_title, char*i_isbn, int i_price, char*DRM)
		:Book(i_title,i_isbn,i_price)
	{
		DRMKey = new char[strlen(DRM) + 1];
		strcpy(DRMKey, DRM);
	}
	~Ebook()
	{
		delete DRMKey;
	}
	void ShowBookInfo()
	{
		Book::ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}
};
int yunm07_2_2(void)
{
	Book book("좋 cpp", "555-12354-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	Ebook ebook("좋c ebook", "555-12354-890-1", 10000, "asfgawtgwae");
	ebook.ShowBookInfo();
	return 0;
}