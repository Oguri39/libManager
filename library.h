#ifndef LIBRARY_H
#define LIBRARY_H
#include <iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
#include <iomanip>
using namespace std;

class library{
    public:
        char tittle[100],author[50],publisher[50],ID[10];
        int year,quantity,genre,instock,borrowed,rturn,calBrow;
        library(){
        quantity = 0;
        borrowed = 0;
        rturn = 0;
        instock = 0;
        calBrow = 0;
        }
        void getInfo();
        void getGenre();
        void menu();
        void addBook();
        void showBook();
        void showBook2();
        void booklist();
        void searchBook();
        void deleteBook();
        void editBook();
        void getBorrow();
        void getInstock();
        void borrowBook();
        void rturnBook();
        void getRturn();
        void getCal();
        int chGenre(int genre);
        int chBorrow(int borrowed);
        int chInstock(int instock);
        int chRturn(int rturn);
        int BorrowingCalculated(int calBrow);

};
#endif // LIBRARY_H
