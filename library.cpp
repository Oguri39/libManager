#include "library.h"

void library::getInfo(){
    fflush(stdin);
    cout<<"Enter book's information: "<<endl;
    cout<<"Tittle: ";cin.getline(tittle,100);
    cout<<"ID (look in the back of the book): ";cin.getline(ID,10);
    cout<<"Author: ";cin.getline(author,50);
    cout<<"Publisher: ";cin.getline(publisher,50);
    cout<<"Year: ";cin>>year;
    cout<<"Quantity: ";cin>>quantity;
    getInstock();
}
void library::getBorrow(){
    this->borrowed=chBorrow(borrowed);
}
void library::getInstock(){
    this->instock = chInstock(instock);
}
void library::getRturn(){
    this->rturn = chRturn(rturn);
}
void library::getCal(){
    this->calBrow = BorrowingCalculated(calBrow);
}
int library::BorrowingCalculated(int calBrow){
    calBrow = this->borrowed-this->rturn;
}
int library::chRturn(int rturn){
    int i;
    cout<<"Enter number of books you want to return:"<<endl;
    cin>>i;
    if(i>this->calBrow){
            cout<<"If you want to add more book for this tittle, please using [Edit book's information] in [Edit library]"<<endl;
            cout<<"Instock:            "<<this->instock<<endl;
            cout<<"Currently borrowed: "<<this->borrowed<<endl;
    }else{
            return this->rturn+i;
    }
}
int library::chInstock(int instock){
    instock=this->quantity-(this->borrowed-this->rturn);
}
int library::chBorrow(int borrowed){
    int i;
    cout<<"Enter number of books you want to borrow:"<<endl;
    cin>>i;
    if(i>this->instock){
            cout<<"Not enough book in library"<<endl;
            cout<<"Instock: "<<this->instock<<endl;
    }else{
            return this->borrowed+i;
    }
}
void library::getGenre(){
    this->genre=chGenre(genre);
}
int library::chGenre(int genre){
    int i;
    cout<<"Choose genre: "<<endl;
    cout<<"[1]Comedy   [2]Drama   [3]Cooking"<<endl;
    cout<<"[4]Medical  [5]Study   [6]Horror "<<endl;
    cout<<"Press number to choose:";
gen:{cin>>i;
    switch(i){
        case 1: {cout<<"Comedy"<<endl;
            return 1; break;}
        case 2: {cout<<"Drama"<<endl;
            return 2; break;}
        case 3: {cout<<"Cooking"<<endl;
            return 3; break;}
        case 4: {cout<<"Medical"<<endl;
            return 4; break;}
        case 5: {cout<<"Study"<<endl;
            return 5; break;}
        case 6: {cout<<"Horror"<<endl;
            return 6; break;}
        default:
            cout<<"Please enter correct option"<<endl;
            getch();
            goto gen;
    }
}
}
void library::showBook(){
    cout<<ID;
    cout<<setw(10)<<tittle;
    cout<<setw(10)<<author;
    cout<<setw(10)<<publisher;
    cout<<setw(10)<<year;
    cout<<setw(10);
    switch (genre){
        case 1: {cout<<"Comedy";break;}
        case 2: {cout<<"Drama";break;}
        case 3: {cout<<"Cooking";break;}
        case 4: {cout<<"Medical";break;}
        case 5: {cout<<"Study";break;}
        case 6: {cout<<"Horror";break;}
    }
    cout<<setw(10)<<quantity;
    cout<<setw(10)<<instock;
    cout<<setw(10)<<calBrow;
    cout<<endl;
}
void library::showBook2(){
    cout<<"ID:        "<<ID<<endl;
    cout<<"Tittle:    "<<tittle<<endl;
    cout<<"Author:    "<<author<<endl;
    cout<<"Publisher: "<<publisher<<endl;
    cout<<"Year:      "<<year<<endl;
    cout<<"Genre:     ";
    switch (genre){
        case 1: {cout<<"Comedy";break;}
        case 2: {cout<<"Drama";break;}
        case 3: {cout<<"Cooking";break;}
        case 4: {cout<<"Medical";break;}
        case 5: {cout<<"Study";break;}
        case 6: {cout<<"Horror";break;}
    }
    cout<<endl;
    cout<<"Quantity:  "<<quantity<<endl;
    cout<<"Instock:   "<<instock<<endl;
    cout<<"Borrowed:  "<<calBrow<<endl;
    cout<<endl;
}
void library::booklist(){
    system("cls");
    ifstream indata("Booksdata.txt",ios::binary);
    if(!indata){
        cout<<"File Not Found"<<endl;
    }else{
        cout<<"Book list:"<<endl;
        cout<<"ID"<<setw(10)<<"Tittle"<<setw(10)<<"Author"<<setw(10)<<"Publisher"<<setw(10)<<"Year"<<setw(10)<<"Genre"<<setw(10)<<"Quantity"<<setw(10)<<"Instock"<<setw(10)<<"Borrowed"<<endl;
        indata.read((char*)this,sizeof(*this));
        while(!indata.eof()){
        showBook();
        indata.read((char*)this,sizeof(*this));
        }
        indata.close();
        }
    cout<<"End list"<<endl;
}
void library::addBook(){
    system("cls");
    getInfo();
    getGenre();
    getInstock();
    getCal();
    ofstream outdata("Booksdata.txt",ios::app|ios::binary);
    outdata.write((char*)this,sizeof(*this));
    outdata.close();
    cout<<"Added Successfully"<<endl;
}
void library::searchBook(){
    int i,chk=0;
    char srch[100];
    system("cls");
    ifstream indata("Booksdata.txt",ios::binary);
        if(!indata){
            cout<<"Currently there is nothing in library";
            getch();
            system("cls");
            menu();
        }else{
            cout<<"[1]Search By Tittle"<<endl;
            cout<<"[2]Search By ID"<<endl;
            cout<<"Press number to select"<<endl;
            cin>>i;
            system("cls");
            fflush(stdin);
            indata.read((char*)this,sizeof(*this));
            if(i==1){
                cout<<"Enter Book's Tittle : ";
                cin.getline(srch,100);
                cout<<endl;
                while(!indata.eof()){
                    int k;
                    for(k=0;tittle[k]!='\0'&&srch[k]!='\0'&&srch[k]==tittle[k];k++);
                        if(tittle[k]=='\0'&&srch[k]=='\0'){
                            cout<<"Book Found: ";
                            showBook2();
                            chk++;
                        }
                indata.read((char*)this,sizeof(*this));
                }
            }else if(i==2){
                cout<<"Enter Book's ID : ";
                cin.getline(srch,100);
                cout<<endl;
                while(!indata.eof()){
                    int k;
                    for(k=0;tittle[k]!='\0'&&srch[k]!='\0'&&srch[k]==tittle[k];k++);
                        if(ID[k]=='\0'&&srch[k]=='\0'){
                            cout<<"Book Found: ";
                            showBook2();
                            chk++;
                        }
                indata.read((char*)this,sizeof(*this));
                }
            }else{
                chk++;
                cout<<"Please enter correct option";
                getch();
                system("cls");
                searchBook();
            }
            indata.close();
        if(chk==0){
              cout<<"No Matching Book"<<endl;
            }
        }
}
void library::deleteBook(){
    int i,chk=0;
    char srch[100];
    ifstream indatac("Booksdata.txt",ios::binary);
    system("cls");
        if(!indatac){
            cout<<"Currently there is nothing in library";
            chk++;
            getch();
            system("cls");
        }else{
            indatac.close();
            cout<<"[1]Search By Tittle"<<endl;
            cout<<"[2]Search By ID"<<endl;
            cout<<"Press number to select"<<endl;
            cin>>i;
            system("cls");
            fflush(stdin);
            ofstream clone("clone.txt",ios::app|ios::binary);
            ifstream indata("Booksdata.txt",ios::binary);
            indata.read((char*)this,sizeof(*this));
            if(i==1){
                cout<<"Enter Book's Tittle : ";
                cin.getline(srch,100);
                cout<<endl;
                while(!indata.eof()){
                    int k;
                    for(k=0;tittle[k]!='\0'&&srch[k]!='\0'&&srch[k]==tittle[k];k++);
                        if(tittle[k]=='\0'&&srch[k]=='\0'){
                            chk++;
                            showBook2();
                            indata.read((char*)this,sizeof(*this));
                        }else{
                        clone.write((char*)this,sizeof(*this));
                        indata.read((char*)this,sizeof(*this));
                        }
                }
                indata.close();
                clone.close();
                cout<<endl;
                cout<<"Do you want to remove this book?"<<endl;
                cout<<"        [1]Yes    [2]No         "<<endl;
                cout<<"Press number to select"<<endl;
                int u; cin>>u;
                switch(u){
                    case 1:{
                    remove("Booksdata.txt");
                    rename("clone.txt","Booksdata.txt");
                    cout<<"Successful remove"<<endl;
                    break;
                    }
                    case 2:{
                    remove("clone.txt");
                    break;
                    }
                }
            }else if(i==2){
                cout<<"Enter Book's ID : ";
                cin.getline(srch,100);
                cout<<endl;
                while(!indata.eof()){
                    int k;
                    for(k=0;ID[k]!='\0'&&srch[k]!='\0'&&srch[k]==ID[k];k++);
                        if(ID[k]=='\0'&&srch[k]=='\0'){
                            chk++;
                            showBook2();
                            indata.read((char*)this,sizeof(*this));
                        }else{
                        clone.write((char*)this,sizeof(*this));
                        indata.read((char*)this,sizeof(*this));
                        }
                }
                indata.close();
                clone.close();
                cout<<endl;
                cout<<"Do you want to remove this book?"<<endl;
                cout<<"        [1]Yes    [2]No         "<<endl;
                cout<<"Press number to select"<<endl;
                int u; cin>>u;
                switch(u){
                    case 1:{
                    remove("Booksdata.txt");
                    rename("clone.txt","Booksdata.txt");
                    cout<<"Successful remove"<<endl;
                    break;
                    }
                    case 2:{
                    remove("clone.txt");
                    break;
                    }
                }
            }else{
                chk++;
                cout<<"Please enter correct option";
                getch();
                system("cls");
                deleteBook();
            }
            indata.close();
        if(chk==0){
              cout<<"No Matching Book"<<endl;
        }
    }
}
void library::editBook(){
    system("cls");
    int i,chk=0;
    char srch[100];
    ifstream indatac("Booksdata.txt",ios::binary);
        if(!indatac){
            cout<<"Currently there is nothing in library";
            chk++;
            getch();
            system("cls");
        }else{
            indatac.close();
            system("cls");
            cout<<"[1]Search By Tittle"<<endl;
            cout<<"[2]Search By ID"<<endl;
            cout<<"Press number to select"<<endl;
            cin>>i;
            fflush(stdin);
            if(i==1){
                system("cls");
                cout<<"Enter Book's Tittle : ";
                cin.getline(srch,100);
                fstream indata("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
                indata.seekg(0);
                indata.read((char*)this,sizeof(*this));
                while(!indata.eof()){
                    int k;
                    for(k=0;tittle[k]!='\0'&&srch[k]!='\0'&&srch[k]==tittle[k];k++);
                    if(tittle[k]=='\0'&&srch[k]=='\0'){
                        chk++;
                        showBook2();
                        cout<<"Edit: "<<endl;
                        getInfo();
                        getGenre();
                        getInstock();
                        getCal();
                        indata.seekp(indata.tellp()-sizeof(*this));
                        indata.write((char*)this,sizeof(*this));
                        break;
                    }
                    indata.read((char*)this,sizeof(*this));
                }
                indata.close();
            }else if(i==2){
                system("cls");
                cout<<"Enter Book's ID : ";
                cin.getline(srch,100);
                fstream indata("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
                indata.seekg(0);
                indata.read((char*)this,sizeof(*this));
                while(!indata.eof()){
                    int k;
                    for(k=0;ID[k]!='\0'&&srch[k]!='\0'&&srch[k]==ID[k];k++);
                    if(ID[k]=='\0'&&srch[k]=='\0'){
                        chk++;
                        showBook2();
                        cout<<"Edit: "<<endl;
                        getInfo();
                        getGenre();
                        getInstock();
                        getCal();
                        indata.seekp(indata.tellp()-sizeof(*this));
                        indata.write((char*)this,sizeof(*this));
                        break;
                    }
                    indata.read((char*)this,sizeof(*this));
                }
            }else{
                chk++;
                cout<<"Please enter correct option";
                getch();
                system("cls");
                editBook();
                }
        if(chk==0){
            cout<<"No Matching Book"<<endl;
        }else{
            cout<<"Successful Edit"<<endl;
        }
    }
}
void library::borrowBook(){
    system("cls");
    int i,chk=0;
    char srch[100];
    ifstream indatac("Booksdata.txt",ios::binary);
        if(!indatac){
            cout<<"Currently there is nothing in library";
            chk++;
            getch();
            system("cls");
        }else{
            indatac.close();
            system("cls");
            cout<<"[1]Search By Tittle"<<endl;
            cout<<"[2]Search By ID"<<endl;
            cout<<"Press number to select"<<endl;
            cin>>i;
            fflush(stdin);
            if(i==1){
                system("cls");
                cout<<"Enter Book's Tittle : ";
                cin.getline(srch,100);
                cout<<endl;
                fstream indata("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
                indata.seekg(0);
                indata.read((char*)this,sizeof(*this));
                while(!indata.eof()){
                    int k;
                    for(k=0;tittle[k]!='\0'&&srch[k]!='\0'&&srch[k]==tittle[k];k++);
                    if(tittle[k]=='\0'&&srch[k]=='\0'){
                        chk++;
                        showBook2();
                        getBorrow();
                        getInstock();
                        getCal();
                        indata.seekp(indata.tellp()-sizeof(*this));
                        indata.write((char*)this,sizeof(*this));
                        break;
                    }
                    indata.read((char*)this,sizeof(*this));
                }
                indata.close();
            }else if(i==2){
                system("cls");
                cout<<"Enter Book's ID : ";
                cin.getline(srch,100);
                fstream indata("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
                indata.seekg(0);
                indata.read((char*)this,sizeof(*this));
                while(!indata.eof()){
                    int k;
                    for(k=0;ID[k]!='\0'&&srch[k]!='\0'&&srch[k]==ID[k];k++);
                    if(ID[k]=='\0'&&srch[k]=='\0'){
                        chk++;
                        showBook2();
                        getBorrow();
                        getInstock();
                        getCal();
                        indata.seekp(indata.tellp()-sizeof(*this));
                        indata.write((char*)this,sizeof(*this));
                        break;
                    }
                    indata.read((char*)this,sizeof(*this));
                }
            }else{
                chk++;
                cout<<"Please enter correct option";
                getch();
                system("cls");
                editBook();
                }
        if(chk==0){
            cout<<"No Matching Book"<<endl;
        }else{
            cout<<"Done!"<<endl;
        }
    }
}
void library::rturnBook(){
    system("cls");
    int i,chk=0;
    char srch[100];
    ifstream indatac("Booksdata.txt",ios::binary);
        if(!indatac){
            cout<<"Currently there is nothing in library";
            chk++;
            getch();
            system("cls");
        }else{
            indatac.close();
            system("cls");
            cout<<"[1]Search By Tittle"<<endl;
            cout<<"[2]Search By ID"<<endl;
            cout<<"Press number to select"<<endl;
            cin>>i;
            fflush(stdin);
            if(i==1){
                system("cls");
                cout<<"Enter Book's Tittle : ";
                cin.getline(srch,100);
                cout<<endl;
                fstream indata("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
                indata.seekg(0);
                indata.read((char*)this,sizeof(*this));
                while(!indata.eof()){
                    int k;
                    for(k=0;tittle[k]!='\0'&&srch[k]!='\0'&&srch[k]==tittle[k];k++);
                    if(tittle[k]=='\0'&&srch[k]=='\0'){
                        chk++;
                        showBook2();
                        getRturn();
                        getInstock();
                        getCal();
                        indata.seekp(indata.tellp()-sizeof(*this));
                        indata.write((char*)this,sizeof(*this));
                        break;
                    }
                    indata.read((char*)this,sizeof(*this));
                }
                indata.close();
            }else if(i==2){
                system("cls");
                cout<<"Enter Book's ID : ";
                cin.getline(srch,100);
                fstream indata("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
                indata.seekg(0);
                indata.read((char*)this,sizeof(*this));
                while(!indata.eof()){
                    int k;
                    for(k=0;ID[k]!='\0'&&srch[k]!='\0'&&srch[k]==ID[k];k++);
                    if(ID[k]=='\0'&&srch[k]=='\0'){
                        chk++;
                        showBook2();
                        getRturn();
                        getInstock();
                        getCal();
                        indata.seekp(indata.tellp()-sizeof(*this));
                        indata.write((char*)this,sizeof(*this));
                        break;
                    }
                    indata.read((char*)this,sizeof(*this));
                }
            }else{
                chk++;
                cout<<"Please enter correct option";
                getch();
                system("cls");
                editBook();
                }
        if(chk==0){
            cout<<"No Matching Book"<<endl;
        }else{
            cout<<"Done!"<<endl;
        }
    }
}
void library::menu(){
    cout<<"WELCOME TO LIBRARY"<<endl;
    cout<<"Menu: "<<endl;
    cout<<"    [1]List"<<endl;
    cout<<"    [2]Search"<<endl;
    cout<<"    [3]Borrow-Return"<<endl;
    cout<<"    [4]Edit library"<<endl;
    cout<<"    [0]exit"<<endl;
    cout<<"Press number to select"<<endl;
    int i;
    cin>>i;
    switch(i){
        case 1: {
            booklist();
            int i;
            cout<<"[0]return"<<endl;
            cout<<"Press number to select"<<endl;
            cin>>i;
            switch(i){
                case 0:{
                system("cls");
                menu();
                break;
                }
            }
            break;}
        case 2:{
            searchBook();
            int i;
            cout<<"[0]return"<<endl;
            cout<<"Press number to select"<<endl;
            cin>>i;
            switch(i){
                case 0:{
                system("cls");
                menu();
                break;
                }
            }
            break;}
        case 3:{
        BR:{
            int i;
            system("cls");
            cout<<"Borrow-Return Book: "<<endl;
            cout<<"    [1]Borrow book"<<endl;
            cout<<"    [2]Return book"<<endl;
            cout<<"    [0]Return     "<<endl;
            cout<<"Press number to select"<<endl;
            cin>>i;
            switch(i){
                case 1:{
                BB1:{
                    borrowBook();
                    cout<<"[1]Borrow  [0]return"<<endl;
                    cout<<"Press number to select"<<endl;
                BB2:{int j;cin>>j;
                    switch(j){
                        case 1:{
                            goto BB1;
                            break;}
                        case 0:{
                            system("cls");
                            goto BR;
                            break;}
                        default:{
                            cout<<"Please enter correct option"<<endl;
                            getch();
                            system("cls");
                            goto BB2;
                        }
                    }
                    }
                    }
                    break;
                }

                case 2:{
                RB1:{
                    rturnBook();
                    cout<<"[1]Return Book  [0]return"<<endl;
                    cout<<"Press number to select"<<endl;
                RB2:{int j;cin>>j;
                    switch(j){
                        case 1:{
                            goto RB1;
                            break;}
                        case 0:{
                            system("cls");
                            goto BR;
                            break;}
                        default:{
                            cout<<"Please enter correct option"<<endl;
                            getch();
                            system("cls");
                            goto RB2;
                        }
                    }
                    }
                    }
                    break;
                }
                case 0:{
                    system("cls");
                    menu();
                    break;
                }
                default:{
                    cout<<"Please enter correct option"<<endl;
                    getch();
                    system("cls");
                    goto BR;
                }
            }


            break;
            }
        }
        case 4:{
        EL:{
            int i;
            system("cls");
            cout<<"Edit library: "<<endl;
            cout<<"    [1]Add book"<<endl;
            cout<<"    [2]Delete book"<<endl;
            cout<<"    [3]Edit book's information"<<endl;
            cout<<"    [0]return"<<endl;
            cout<<"Press number to select"<<endl;
            cin >>i;
            switch(i){
                case 1:{
                AB1:{
                    addBook();
                    cout<<"[1]Add more  [0]return"<<endl;
                    cout<<"Press number to select"<<endl;
                AB2:{int j;cin>>j;
                    switch(j){
                        case 1:{
                            goto AB1;
                            break;}
                        case 0:{
                            system("cls");
                            goto EL;
                            break;}
                        default:{
                            cout<<"Please enter correct option"<<endl;
                            getch();
                            system("cls");
                            goto AB2;
                        }
                    }
                    }
                    }
                    break;
                    }
                case 2:{
                    deleteBook();
                    cout<<"[0]return"<<endl;
                DB:{int j;cin>>j;
                    switch (j){
                        case 0:{
                            system("cls");
                            goto EL;
                            break;
                        default:{
                            cout<<"Please enter correct option"<<endl;
                            getch();
                            system("cls");
                            goto DB;
                            }
                        }
                    }
                    }
                }
                case 3:{
                    editBook();
                    cout<<"[0]return"<<endl;
                EB:{int j;cin>>j;
                    switch (j){
                        case 0:{
                            system("cls");
                            goto EL;
                            break;
                        default:{
                            cout<<"Please enter correct option"<<endl;
                            getch();
                            system("cls");
                            goto EB;
                            }
                        }
                    }
                    }
                }
                case 0:{
                    system("cls");
                    menu();
                    break;}
                default:{
                    cout<<"Please enter correct option"<<endl;
                    getch();
                    system("cls");
                    goto EL;
                }
            }
        }
            break;
    }
        default:{
            cout<<"Please enter correct option"<<endl;
            getch();
            system("cls");
            menu();
            }
    }
}
