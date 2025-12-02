#include<iostream>
#include<fstream>
#include<windows.h>
#include<sstream>
using namespace std;

class Hostel{
    private:
    string Name;
    int Rent;
    int Bed;

    public:
    Hostel(string name, int rent, int bed){
        this->Name = name;
        this->Rent = rent;
        this->Bed = bed;
    }

    string getName(){
        return Name;
    }

    int getRent(){
        return Rent;
    }

    int getBed(){
        return Bed;
    }

    void reserve(){
        ifstream in("C:/Users/ayush/OneDrive/Desktop/Code Practice/C++ Projects/1. Hotel Accommodation/Hostel.txt");
        ofstream out("C:/Users/ayush/OneDrive/Desktop/Code Practice/C++ Projects/1. Hotel Accommodation/Hostel Temp.txt");

        string line;
        while(getline(in, line)){
            int pos = line.find("Bcet Boys Hostel");
            if(pos != string::npos){
                int bed = Bed-1;
                Bed = bed;

                stringstream ss;
                ss << bed;
                string strBed = ss.str();

                // Replace only the bed count after second colon
                int firstColon = line.find(':');
                int secondColon = line.find(':', firstColon + 1);
                line.replace(secondColon + 2, string::npos, strBed); // +2 to skip ": "
            }
            out << line << endl;
        }
        out.close();
        in.close();

        remove("C:/Users/ayush/OneDrive/Desktop/Code Practice/C++ Projects/1. Hotel Accommodation/Hostel.txt");
        rename("C:/Users/ayush/OneDrive/Desktop/Code Practice/C++ Projects/1. Hotel Accommodation/Hostel Temp.txt",
               "C:/Users/ayush/OneDrive/Desktop/Code Practice/C++ Projects/1. Hotel Accommodation/Hostel.txt");

        cout << "\tBed Reserved Successfully!" << endl;
    }
};

class Student{
    private:
    string Name;
    string RollNo;
    string Address;

    public:
    Student(): Name(""), RollNo(""), Address(""){}

    void setName(string name){
        Name = name;
    }

    void setRollNo(int rollNo){
        RollNo = to_string(rollNo); // Fixed conversion
    }

    void setAddress(string address){
        Address = address;
    }

    string getName(){
        return Name;
    }

    string getRollNo(){
        return RollNo;
    }

    string getAddress(){
        return Address;
    }
};

int main(){
    Hostel h("Bcet Boys Hostel", 5000, 2);

    ofstream HostelDataFile("C:/Users/ayush/OneDrive/Desktop/Code Practice/C++ Projects/1. Hotel Accommodation/Hostel.txt");
    HostelDataFile << "\t" << h.getName() << " : " << h.getRent() << " : " << h.getBed() << endl << endl;
    cout << "Hostel Data Saved" << endl;
    HostelDataFile.close();

    Student s;
    bool exit = false;

    while(!exit){
        system("cls");
        int val;
        cout << "\tWelcome To Hostel Accommodation System" << endl;
        cout << "\t**************************************" << endl;
        cout << "\t1.Reserve A Bed." << endl;
        cout << "\t2.Exit." << endl;
        cout << "\tEnter Choice: ";
        cin >> val;

        if(val == 1){
            system("cls");
            string name;
            int rollNo;
            string address;

            cin.ignore(); // clear leftover newline
            cout << "\tEnter Name of Student: ";
            getline(cin, name);
            s.setName(name);

            cout << "\tEnter RollNo of Student: ";
            cin >> rollNo;
            s.setRollNo(rollNo);

            cin.ignore(); // clear leftover newline
            cout << "\tEnter Address of Student: ";
            getline(cin, address);
            s.setAddress(address);

            if(h.getBed() > 0){
                h.reserve();
            }
            else if(h.getBed() == 0){
                cout << "\tSorry, Bed Not Available!" << endl;
            }

            ofstream StudentDataFile("C:/Users/ayush/OneDrive/Desktop/Code Practice/C++ Projects/1. Hotel Accommodation/Student.txt", ios::app);
            StudentDataFile << "\t" << s.getName() << " : " << s.getRollNo() << " : " << s.getAddress() << endl << endl;
            StudentDataFile.close();
            Sleep(5000);
        }
        else if(val == 2){
            system("cls");
            exit = true;
            cout << "Good Luck!" << endl;
            Sleep(3000);
        }
    }

    return 0;
}
