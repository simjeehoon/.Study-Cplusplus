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
		cout << "����: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "����: " << price << endl;
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
		cout << "����Ű: " << DRMKey << endl;
	}
};
int yunm07_2_2(void)
{
	Book book("�� cpp", "555-12354-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	Ebook ebook("��c ebook", "555-12354-890-1", 10000, "asfgawtgwae");
	ebook.ShowBookInfo();
	return 0;
}