#include <iostream>
#include <fstream>
#include <cstring>
#include<stdio.h>

using namespace std;

class Book{
    
    private:
    int bookId;
    char title[20];
    float price;
    
    public:
    Book(){
        bookId=0;
        strcpy(title,"No Title");
        price=0;
    }
    
    void setBookData(){
        
        cout<<"Enter bookId, title and price : ";
        cin>>bookId;
        cin.ignore();
        cin.getline(title,19);
        cin>>price;
    }
    
    void showBookData(){
        cout<<"\nBook ID : "<<this->bookId<<endl;
        cout<<"Book Title : "<<this->title<<endl;
        cout<<"Book Price : "<<this->price<<endl;
    }
    
    int storeData();//store the data of book in a file

    void viewAllBooks(); // read all records from file and display them

    void searchBook(char *t); // search a book by id and display it
    

    void deleteBook(char *t); // delete a book by title

    void updateBook(char *t); // update a book by title
};

//storedata() function definition
int Book::storeData(){
    
    if(bookId==0 && price==0){
        cout<<"Book data not initialized"<<endl;
        return 0;
    }
    else{
    ofstream fout;
    fout.open("books.dat",ios::app | ios::binary);
    fout.write((char*)this,sizeof(*this));
    fout.close();//close krne par hi actual disk pe write hoga
    return 1;
    }
    
}


//function definition of viewAllBooks()

void Book::viewAllBooks(){
    ifstream fin;
    fin.open("books.dat",ios::in | ios::binary );
    if(!fin){
        cout<<"\n File not found"<<endl;
    }
    else{
        
        fin.read((char*) this,sizeof(*this));
        while(!fin.eof()){
            this->showBookData();
            fin.read((char*) this,sizeof(*this));
        }
    }
}


//function definition for searchBook()
void Book::searchBook(char* t){

    ifstream fin;
    fin.open("books.dat",ios::in | ios::binary );
    if(!fin){
        cout<<"\n File not found"<<endl;
        }
    else{
            bool isFound=false;
            fin.read((char*) this,sizeof(*this));
            while(!fin.eof()){
                if(strcmp(this->title,t)==0){
                    cout<<"\nBook found and Details are:"<<endl;
                    this->showBookData();
                    isFound=true;
                    break;
                }
                fin.read((char*) this,sizeof(*this));
                }
                if(!isFound){
                    cout<<"\nBook not found with the title : "<<t<<endl;
                }
                fin.close();
    }

}

// function definition for deleteBook()
void Book::deleteBook(char* t){

    ifstream fin;
    ofstream fout;

    fin.open("books.dat",ios::in | ios::binary);
    

    if(!fin){
        cout<<"\n File Not Found"<<endl;
    }
    else{
        fout.open("temp.dat",ios::out | ios::binary);
        bool isFound=false;
        fin.read((char*) this,sizeof(*this));
        while(!fin.eof()){
            if(strcmp(this->title,t)==0){
                isFound=true;
                cout<<"Book found and Deleted Successfully with title : "<<t<<endl;
            }
            else{
                fout.write((char*) this,sizeof(*this)); //write in temp file
            }
            fin.read((char*) this,sizeof(*this)); //read next

    }
    fin.close();
    fout.close();
    if(!isFound){
        cout<<"Book not found"<<endl;
    }
    remove("books.dat"); //remove file
    rename("temp.dat","books.dat"); //rename temp file to books.dat file
}

}

// function definition for updateBook()
void Book::updateBook(char* t){

    fstream file;
    file.open("books.dat",ios::in |ios::out | ios::ate | ios::binary);
    if(!file){
        cout<<"\n File Not Found"<<endl;
    }
    else{
        bool isFound=false;
        file.seekg(0); //set pointet at start
        file.read((char*) this,sizeof(*this));
        while(!file.eof()){
            if(strcmp(this->title,t)==0){
                setBookData();
                isFound=true;
                file.seekp(file.tellp()-sizeof(*this)); //move to previous position
                file.write((char*) this,sizeof(*this)); //write in temp file
                cout<<"Book found and updated Successfully with new title : "<<this->title<<endl;
            }
            file.read((char*) this,sizeof(*this)); //read next

    }
    file.close();
    if(!isFound){
        cout<<"Book not found"<<endl;
    }

}

}

//menu function

int menu(){

    int choice;
    cout<<"\n------------------Choose an option to perform any operation---------------------"<<endl;
    cout<<"\n1. Add a Book"<<endl;
    cout<<"\n2. Delete a Book"<<endl;
    cout<<"\n3. Search a Book"<<endl;
    cout<<"\n4. Update a Book"<<endl;
    cout<<"\n5. Display all Books"<<endl;
    cout<<"\n6. Exit"<<endl;
    cout<<"\nyour an option is : ";
    cin>>choice;
    return choice;
}
int main()
{

    cout<<"\n----------------------------Welcome to Our Book Management System--------------------------"<<endl;
    cout<<"---------------------------------------------------------------------------------------------"<<endl;
    while(1){
    Book b;
    char t[20];
    switch (menu())
    {
    case 1:
        b.setBookData();
        b.storeData();
        cout<<"\n Book Added Successfully"<<endl;
        break;
    
    case 2:
        cout<<"\nEnter the title of the book to delete: "<<endl;
        cin.ignore();
        cin.getline(t,19);
        b.deleteBook(t);
        break;
    case 3:
        cout<<"\nEnter the title of the book to search : "<<endl;
        cin.ignore();
        cin.getline(t,19);
        b.searchBook(t);
        break; 
    
    case 4:
        cout<<"\nEnter the title of the book to search : "<<endl;
        cin.ignore();
        cin.getline(t,19);
        b.updateBook(t);
        break;  
    
    case 5:
        b.viewAllBooks();
        break;
    
    case 6:
        cout<<"\nThank you for using the application";
        exit(0);    

    default:
        cout<<"\nInvalid Choice";
        break;
    }

}

return 0;   
}