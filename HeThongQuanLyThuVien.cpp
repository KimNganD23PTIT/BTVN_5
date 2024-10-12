#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Lớp trừu tượng Borrowable
class Borrowable {
public:
    virtual void displayInfo() const = 0; // Phương thức thuần ảo để hiển thị thông tin
    virtual string getTitle() const = 0; // Phương thức thuần ảo để lấy tiêu đề
    virtual ~Borrowable() {} // Destructor ảo
};

// Lớp Book kế thừa từ Borrowable
class Book : public Borrowable {
private:
    string title;
    string author;
    int publicationYear;

public:
    Book(const string &title, const string &author, int year)
        : title(title), author(author), publicationYear(year) {}

    void displayInfo() const override {
        cout << "Book Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publication Year: " << publicationYear << endl;
    }

    string getTitle() const override {
        return title;
    }
};

// Lớp DVD kế thừa từ Borrowable
class DVD : public Borrowable {
private:
    string title;
    string director;
    int releaseYear;

public:
    DVD(const string &title, const string &director, int year)
        : title(title), director(director), releaseYear(year) {}

    void displayInfo() const override {
        cout << "DVD Title: " << title << endl;
        cout << "Director: " << director << endl;
        cout << "Release Year: " << releaseYear << endl;
    }

    string getTitle() const override {
        return title;
    }
};

// Lớp Library quản lý các đối tượng Borrowable
class Library {
private:
    vector<Borrowable *> items; // Mảng chứa các đối tượng Borrowable

public:
    // Thêm item vào thư viện
    void addItem(Borrowable *item) {
        items.push_back(item);
    }

    // Hiển thị thông tin tất cả các item trong thư viện
    void displayAllItems() const {
        for (const auto &item : items) {
            item->displayInfo();
            cout << "-----------------------" << endl;
        }
    }

    // Hủy các đối tượng Borrowable trong thư viện
    ~Library() {
        for (auto &item : items) {
            delete item;
        }
    }
};

// Hàm main để demo chức năng của hệ thống
int main() {
    Library library;

    // Tạo các đối tượng Book và DVD
    Borrowable *book1 = new Book("The Great Gatsby", "F. Scott Fitzgerald", 1925);
    Borrowable *book2 = new Book("1984", "George Orwell", 1949);
    Borrowable *dvd1 = new DVD("Inception", "Christopher Nolan", 2010);
    Borrowable *dvd2 = new DVD("The Matrix", "The Wachowskis", 1999);

    // Thêm các đối tượng vào thư viện
    library.addItem(book1);
    library.addItem(book2);
    library.addItem(dvd1);
    library.addItem(dvd2);

    // Hiển thị thông tin tất cả các item trong thư viện
    cout << "Library Items:" << endl;
    library.displayAllItems();

    return 0;
}
