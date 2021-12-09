#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
class employee{
public:
    char Employee_ID[13];
    char Employee_Dept_ID[13];
    char Employee_Name[50];
    char Employee_postion[50];
    fstream emp;
    string headerFile;
public:
    employee(){}
    employee(const employee &obj){}
    void changeheaderfile(int numrec,int RRn)
    {
        emp.open("employee.txt",ios::out);
        emp<<numrec<<RRn;

    }
    void addemp(){
        fstream emp ("employee.txt", ios::out);
        employee e;
        char more = 'n';
        do{


            cout << "\n employee  ID:\n";
            cin.getline(e.Employee_ID,13);
            emp<<e.Employee_ID<<',';

            cout << "\n employee Department ID:\n";
            cin.getline(e.Employee_Dept_ID,13);
            emp<<e.Employee_Dept_ID<<',';

            cout << "\n employee Name: \n";
            cin.getline(e.Employee_Name, 50);
            emp<<e.Employee_Name<<',';

            cout << "\n employee position: \n";
            cin.getline(e.Employee_postion,50);
            emp<<e.Employee_postion<<'$';

            cout << "Do you want to enter more employee?";
            cin >> more;
            cin.ignore();

        } while (toupper(more) == 'Y');

        emp.close();

    }
    employee GetEmployee(int RNN, fstream &infile) {
        employee employee;
        infile.seekg(RNN * 40, ios::beg);
        infile.read((char*) &employee, sizeof employee);
        return employee;
    }
};

class department{
    char Dept_ID[30];
    char Dept_Name[50];
    char Dept_Manger[50];
    fstream dept;

public:
    void adddept(){
        fstream dept("dept.txt", ios::out);
        department d;
        char more = 'n';
        do{


            cout << "\n department   ID:\n";
            cin.getline(d.Dept_ID,30);
            dept<<d.Dept_ID<<',';

            cout << "\n  Department Name:\n";
            cin.getline(d.Dept_Name,50);
            dept<<d.Dept_Name<<',';

            cout << "\n Department manger: \n";
            cin.getline(d.Dept_Manger, 50);
            dept<<d.Dept_Manger<<'$';



            cout << "Do you want to enter more department?";
            cin >> more;
            cin.ignore();

        } while (toupper(more) == 'Y');

        dept.close();

    }
};
int main() {
   // employee e;
  department d;
   // e.addemp();
   d.adddept();

    return 0;
}











