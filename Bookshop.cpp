#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
using namespace std;

class bookshop
{
    public:
        void control_panel();
        void add_book();
        void show_books();
        void check_book();
        void update_book();
        void delete_book();

};

void bookshop::control_panel()
{
    
    cout<<"\n\n\t Main Menu";
    cout<<"\n\n 1. Add New Book";
    cout<<"\n\n 2. display Book";
    cout<<"\n\n 3. Check Specific Book";
    cout<<"\n\n 4. Update Book";
    cout<<"\n\n 5. Delete Book";
    cout<<"\n\n 6. Exit";
}

void bookshop::add_book()
{   
    fstream file;
    
    int no_copies;
    string b_name , a_name , b_id;

    cout<<"\n\n\t Add New Book";
    cout<<"\n Book Id: ";
    cin>>b_id;
    cout<<"\n\n Book Name : ";
    cin>>b_name;
    cout<<"\n\n Author Name : ";
    cin>>a_name;
    cout<<"\n\n Number of copies : ";
    cin>>no_copies;

    file.open("D://book.txt",ios::out | ios::app);
    file<<""<<b_id<<" "<<b_name<<" "<<a_name<<" "<<no_copies<<"\n";
    file.close();
}

    void bookshop::show_books()
    {
        
        fstream file;  
        int no_copies;
        string b_name , b_id , a_name;
        cout<<"\n\n\n\t\t Show all Books\n\n";
        file.open("D://book.txt", ios::in);
        if (!file)
        {
            cout<<"\n\n File not Found...";
        }
        else
        {
            cout<<"   Book Id     Book      Author      Copies \n\n";

            file>>b_id>>b_name>>a_name>>no_copies;
            while (!file.eof())
            {
                cout<<"    "<<b_id<<"\t   "<<b_name<<"\t   "<<a_name<<"\t   "<<no_copies<<"\n\n";
                file>>b_id>>b_name>>a_name>>no_copies;
            }
            file.close();

            

            
        }
        
    }

    void bookshop::check_book()
    {
        fstream file;
        int no_copies , count=0;
        string b_id , b_name , a_name , b_idd ;
        cout<<"\n\n\t\t\t Check Specific Book";
        file.open("D://book.txt" , ios::in);
        if(!file)
        cout<<"File not found";
        else
        {
            cout<<"\n\n Book Id : ";
            cin>>b_idd;
            file>>b_id>>b_name>>a_name>>no_copies;
            while (!file.eof())
            {
                if(b_idd == b_id)
                {
                    system("cls");
                    cout<<"\n\n\t Check Specific Book";
                    cout<<"\n\n Book Id : "<<b_id;
                    cout<<"\n\n Name :"<<b_name;
                    cout<<"\n\n Author : "<<a_name;
                    cout<<"\n\n No. of copies : "<<no_copies;                  
                    count++;
                    break;
                }
            file>>b_id>>b_name>>a_name>>no_copies;
            }
                file.close();
                if (count == 0)
                {
                cout<<"\n\n Book Id not found...";
                }
        }
    }
    void bookshop::update_book()
	{
		system("cls");
		fstream file,file1;
		int no_copy,no_co,count=0;
		string b_name,b_na,a_name,a_na,b_idd,b_id;
		cout<<"\n\n\t\t\t\tUpdate Book Record";
		file1.open("D://book1.txt",ios::app|ios::out);
		file.open("D://book.txt",ios::in);
		if(!file)
		cout<<"\n\n File Openning Error...";
		else
		{
			cout<<"\n\n Book ID : ";
			cin>>b_id;
			file>>b_idd>>b_name>>a_name>>no_copy;
			while(!file.eof())
			{
				if(b_id == b_idd)
				{
					system("cls");
					cout<<"\n\n\t\t\t\tUpdate Book Record";
					cout<<"\n\n New Book Name : ";
					cin>>b_na;
					cout<<"\n\n\t\t\tAuthor Name : ";
					cin>>a_na;
					cout<<"\n\n No. of Copies : ";
					cin>>no_co;
					file1<<" "<<b_id<<" "<<b_na<<" "<<a_na<<" "<<no_co<<"\n";
					count++;
				}
				else
				file1<<" "<<b_idd<<" "<<b_name<<" "<<a_name<<" "<<no_copy<<"\n";
				file>>b_idd>>b_name>>a_name>>no_copy;
			}
			if(count == 0)
			cout<<"\n\n Book ID Not Found...";
		}
		file.close();
		file1.close();
		remove("D://book.txt");
		rename("D://book1.txt","D://book.txt");
	}

      void bookshop::delete_book()
	{
		system("cls");
		fstream file,file1;
		int no_copy,count=0;
		string b_id,b_idd,b_name,a_name;
		cout<<"\n\n\t\t\t\tDelete Book Record";
		file1.open("D://book1.txt",ios::app|ios::out);
		file.open("D://book.txt",ios::in);
		if(!file)
		cout<<"\n\n File Openning Error...";
		else
		{
			cout<<"\n\n Book ID : ";
			cin>>b_id;
			file>>b_idd>>b_name>>a_name>>no_copy;
			while(!file.eof())
			{
				if(b_id == b_idd)
				{
					system("cls");
					cout<<"\n\n\t\t\t\tDelete Book Record";
					cout<<"\n\n One Book is Deleted Successfully...";
					count++;
				}
				else
				file1<<" "<<b_idd<<" "<<b_name<<" "<<a_name<<" "<<no_copy<<"\n";
				file>>b_idd>>b_name>>a_name>>no_copy;
			}
			if(count == 0)
			cout<<"\n\n Book ID Not Found...";
		}
		file.close();
		file1.close();
		remove("D://book.txt");
		rename("D://book1.txt","D://book.txt");
	}

main ()
{
    int choice;
    char x;
    bookshop b;
    p: 
    b.control_panel();
    cout<<"\n\n Your choice : ";
    cin>>choice ;
    switch (choice)
    {
           
           
            case 1: 
                do
                {
                b.add_book();
                cout<<"\n\n Do you want to add more books? (y/n) : ";
                cin>>x;
                } while (x =='y');
                
            break;

            case 2:
                b.show_books();
            break;
            
            case 3:
                b.check_book();
            break;
            
            case 4:
                b.update_book();
            break;
            
            case 5:
                b.delete_book();
            break;
            
            case 6:            
                exit(0);
            break;

            default:
                cout<<"\n\n Invalid Value";
    }
    getch();
    goto p;
}
