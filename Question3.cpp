
#include<iostream>
#include<string>

using namespace std;

//base class employee

class employee{
protected:
string name;
int empNumber;

public:
void getdata(){
    cout<<"Enter employee name:";
    cin.ignore();
    getline(cin, name);
    cout<<"Enter employee number:";
    cin>> empNumber;
}

void putdata(){
    cout<<"Name: "<< name << endl;
    cout<<"Employee Number: "<< empNumber<<endl;

}
};

class employee2: public employee{

    protected:
    double compansation; //salary/wages
    enum period {HOURLY, WEEKLY, MONTHLY};
    period payPeriod;

    public:
    void getdata(){
        employee::getdata();

        cout<<"Enter compasion(salary/wage):";
        cin>> compansation;

        int choice;
        cout<<"Enter pay period(1 = Hourly, 2 = Weekly, 3 = monthly)";
        cin>> choice;
        switch(choice){
            case 1:
            payPeriod = HOURLY;
            break;
            case 2:
            payPeriod = WEEKLY;
            break;
            case 3:
            payPeriod = MONTHLY;
            break;

        }
    }
    void putdata(){
        employee::putdata();
        cout<<"Compensation:"<<compansation<<endl;
        cout<<"Pay Period: ";

        switch(payPeriod){
            case HOURLY:
            cout<< "Hourly";
            break;
            case WEEKLY:
            cout<< "Weekly";
            break;
            case MONTHLY:
            cout<< "Monthly";
            break;

        }
        cout<<endl;
    }
};
//manager class derived from employee2
class manager: public employee2{
    string title;
    double dues;

    public:
    void getdata(){
        employee2::getdata();
        cout<<"Enter manager title: ";
        cin.ignore();
        getline(cin, title);
        cout<<"Enter golf club dues: ";
        cin>> dues;
    }
    void putdata(){
        employee2::putdata();
        cout << "Title: " << title << endl;
        cout << "Golf Club Dues: " << dues << endl;
    }
};
class scientist: public employee2{
    int pubs; //nuber of  publication
    public:
    void getdata(){

        employee2::getdata();
        cout << "Enter number of publications: ";
        cin >> pubs;
    }
    void putdata(){
        employee2::putdata();
        cout << "Publications: " << pubs << endl;
    }
};
class laborer: public employee2{

};
int main(){
     
    manager m1;
    scientist s1;
    laborer l1;

    cout << "\nEnter details for Manager:\n";
    m1.getdata();

    cout << "\nEnter details for Scientist:\n";
    s1.getdata();

    cout << "\nEnter details for Laborer:\n";
    l1.getdata();

     cout << "\n--- Employee Details ---\n";
     cout << "\nManager:\n"; m1.putdata();
    cout << "\nScientist:\n"; s1.putdata();
    cout << "\nLaborer:\n"; l1.putdata();

    return 0;
}