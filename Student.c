#include <iostream>
#include <fstream>
using namespace std;

class Student
{
    int roll;
    string name;
    float marks;

public:

    void addStudent()
    {
        ofstream file("student.txt", ios::app);

        cout<<"Enter Roll No: ";
        cin>>roll;

        cout<<"Enter Name: ";
        cin>>name;

        cout<<"Enter Marks: ";
        cin>>marks;

        file<<roll<<" "<<name<<" "<<marks<<endl;

        file.close();

        cout<<"Student Added Successfully\n";
    }


    void display()
    {
        ifstream file("student.txt");

        cout<<"\nRoll\tName\tMarks\n";

        while(file>>roll>>name>>marks)
        {
            cout<<roll<<"\t"<<name<<"\t"<<marks<<endl;
        }

        file.close();
    }


    void search()
    {
        int r;
        cout<<"Enter Roll No to search: ";
        cin>>r;

        ifstream file("student.txt");

        while(file>>roll>>name>>marks)
        {
            if(roll==r)
            {
                cout<<"Student Found\n";
                cout<<"Name: "<<name<<endl;
                cout<<"Marks: "<<marks<<endl;
                return;
            }
        }

        cout<<"Student Not Found\n";

        file.close();
    }


    void deleteStudent()
    {
        int r;

        cout<<"Enter Roll No to delete: ";
        cin>>r;

        ifstream file("student.txt");
        ofstream temp("temp.txt");


        while(file>>roll>>name>>marks)
        {
            if(roll!=r)
            {
                temp<<roll<<" "<<name<<" "<<marks<<endl;
            }
        }


        file.close();
        temp.close();

        remove("student.txt");
        rename("temp.txt","student.txt");

        cout<<"Deleted Successfully\n";
    }
};


int main()
{
    Student s;
    int choice;

    do
    {
        cout<<"\n1.Add Student";
        cout<<"\n2.Display Student";
        cout<<"\n3.Search Student";
        cout<<"\n4.Delete Student";
        cout<<"\n5.Exit";

        cout<<"\nEnter Choice:";
        cin>>choice;


        switch(choice)
        {
            case 1:
                s.addStudent();
                break;

            case 2:
                s.display();
                break;

            case 3:
                s.search();
                break;

            case 4:
                s.deleteStudent();
                break;

            case 5:
                cout<<"Exit";
                break;

            default:
                cout<<"Invalid Choice";
        }

    }while(choice!=5);


    return 0;
}
