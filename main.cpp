#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;
class employee {
public:
    char Employee_ID[13];
    char Employee_Dept_ID[13];
    char Employee_Name[50];
    char Employee_postion[50];
    fstream emp;
    fstream primaryindex;
    fstream secondry;
    int RRn;
public:
    employee() {}
};
struct PIndex
{
    int RRN;
    string ID;
};
struct SIndex
{
    string ID_e;
    string Id_D;
};

void addemp(int num) {
    fstream emp("employee.txt", ios::out);
    employee e;
    e.primaryindex.open("p_indx.txt", ios::out);
    e.secondry.open("sec.txt",ios::out);
    PIndex *p=new PIndex[num];
    SIndex *s=new SIndex[num];

    for(int i=0;i<num;i++){
        cout << "\n employee  ID:\n";

        cin.ignore();
        cin.getline(e.Employee_ID, 13);
        emp << e.Employee_ID << ",";
        p[i].ID=e.Employee_ID;
        e.primaryindex << e.Employee_ID;
        e.secondry<<e.Employee_ID<<",";



        cout << "\n employee Department ID:\n";
        cin.getline(e.Employee_Dept_ID, 13);
        emp << e.Employee_Dept_ID << ',';
        s[i].Id_D=e.Employee_Dept_ID;
        e.secondry<<e.Employee_Dept_ID<<"$";

        cout << "\n employee Name: \n";
        cin.getline(e.Employee_Name, 50);
        emp << e.Employee_Name << ',';

        cout << "\n employee position: \n";
        cin.getline(e.Employee_postion, 50);
        emp << e.Employee_postion << '$';




    }

    emp.close();
    e.primaryindex.close();
    e.secondry.close();
}

//void ReadPrimIndex(PIndex PrmIndxArray[],int numRec,fstream& inFile) {
//    for (int i = 0; i < numRec; i++) {
//        inFile.read((char *) &PrmIndxArray[i].RRN, sizeof(int));
//        char *tmp = new char[3];
//        inFile.read(tmp, 3);
//        //[] = 0;
//        PrmIndxArray[i].ID = tmp;
//    }
//}
//void SearchById(int numRec) {
//    fstream file, PrimIndex;
//
//    file.open("p_indx.txt", ios::in);
//   // PrimIndex.open("Primary.txt", ios::in);
//
//
//    PIndex *PrmIndxArray = new PIndex[numRec];
//    employee *emp = new employee[numRec];
//
//  ReadPrimIndex(PrmIndxArray, numRec, file);
//
//
//    //printing index files
//
//    cout << "Primary index" << endl;
//
//
//        cout << " ID:" << PrmIndxArray[numRec].ID << endl;
//
//
//     //   break;
//    }


class department{
public:
    char Dept_ID[30];
    char Dept_Name[50];
    char Dept_Manger[50];
    fstream dept;
    fstream d_index;
    fstream s_index;
};
struct dept_index
{
    int RRN;
    string ID;
};
struct dsIndex
{
    string D_n;
    string D_id;
};
void searech(string id, int numRec){
    fstream file;
    stringstream in(id);
    int c=0;
    in>>c;
    char x;
    file.open("p_indx.txt",ios::in);
    for (int i = 1; i <= numRec; ++i) {
        file>>x;
       if(c==i)
       {
           cout <<x;
       }
    }
}

//int GetRecordRRN(PIndex PrmIndxArray[], int numRec, string ID) {
//  int RRN = -1;
//    int low = 0, mid, high = numRec - 1;
//
//   while (low <= high) {
//      mid = (low + high) / 2;
//       if (ID < PrmIndxArray[mid].ID)
//            high = mid - 1;
//        else if (ID > PrmIndxArray[mid].ID)
//          low = mid + 1;
//      else {
//        RRN = PrmIndxArray[mid].RRN;
//          break;
//      }
//  }
//    return RRN;
//}
void adddept(int num){
    fstream dept("dept.txt", ios::out);
    department d;
    d.d_index.open("d_index",ios::out);
    d.s_index.open("sec_dept.txt",ios::out);
    dept_index *t=new dept_index[num];
    dsIndex *s=new dsIndex[num];

    for(int i=0;i<num;i++)
    {

        cout << "\n department   ID:\n";
        //cin.ignore();
        cin>>d.Dept_ID;
        //cin.getline(d.Dept_ID,30);
        dept<<d.Dept_ID<<',';
        t[i].ID=d.Dept_ID;
//        t[i].RRN=i;
//        d.d_index<<t[i].RRN<<",";
        d.d_index << d.Dept_ID;
        s[i].D_id=d.Dept_ID;
        d.s_index<<d.Dept_ID<<",";

        cout << "\n  Department Name:\n";
        //cin.ignore();
        cin>>d.Dept_Name;
        //cin.getline(d.Dept_Name,50);
        dept<<d.Dept_Name<<',';
        s[i].D_n=d.Dept_Name;
        d.s_index<<d.Dept_Name<<"$";


        cout << "\n Department manger: \n";
        cin>>d.Dept_Manger;
        //cin.getline(d.Dept_Manger, 50);
        dept<<d.Dept_Manger<<'$';
    }
    dept.close();
    d.d_index.close();
    d.s_index.close();

}
string GetEmployeeID(SIndex ScndIndxArray[], int numRec, string Dept_ID) {

//    string ID = "";
//    int low = 0, mid, high = numRec - 1;
//    while (low <= high) {
//        mid = (low + high) / 2;
//        if (Dept_ID < ScndIndxArray[mid].Id_D)
//            high = mid - 1;
//        else if (Dept_ID > ScndIndxArray[mid].Id_D)
//            low = mid + 1;
//        else {
//            ID = ScndIndxArray[mid].ID_e;
//            break;
//        }
//    }
//    return ID;
}
void screen(){
    cout<<"1-Add New Employee"<<endl;
    cout<<"2-Add New Department"<<endl;
    cout<<"3-Delete Employee(ID)"<<endl;
    cout<<"4-Delete Department(ID)"<<endl;
    cout<<"5-Print Employee(ID)"<<endl;
    cout<<"6-Print Employee(Dept_ID)"<<endl;
    cout<<"7-Print Department(ID)"<<endl;
    cout<<"8-Print Department(Name)"<<endl;
    cout<<"9-write a query"<<endl;
    cout<<"10=Exit"<<endl;
}
void ReadPrimIndex(PIndex PrmIndxArray[], int numRec, fstream& inFile) {
    for (int i = 0; i < numRec; i++)
        inFile.read((char*) &PrmIndxArray[i], sizeof PrmIndxArray[i]);
}
string binarySearch(SIndex ScndIndxArray[], int numRec, string Name) {
    string ID = "";
    int low = 0, mid, high = numRec - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        if (Name < ScndIndxArray[mid].ID_e)
            high = mid - 1;
        else if (Name > ScndIndxArray[mid].Id_D)
            low = mid + 1;
        else {
            ID = ScndIndxArray[mid].ID_e;
            break;
        }
    }
    return ID;
}
void readrecord(char id)
{
    fstream f;
    char x;
    f.open("employee.txt",ios::in);
  while (true)
    {
      if(f.fail())
      {
          break;
      }
      f>>x;
      if(x==id)
      {
          cout<<x;
          while(true){
              f>>x;
              if(x=='$')
              {
                  break;
              } else{
                  cout<<x;
              }
          }

      }
        }
  cout<<endl;
}
void readrecorddept(char id)
{
    fstream f;
    char x;
    f.open("dept.txt",ios::in);
    while (true)
    {
        if(f.fail())
        {
            break;
        }
        f>>x;
        if(x==id)
        {
            cout<<x;
            while(true){
                f>>x;
                if(x=='$')
                {
                    break;
                } else{
                    cout<<x;
                }
            }
        }
    }
    cout<<endl;
}
//void readrecorddeptname(string name)
//{
//    fstream f;
//    char x;
//    f.open("dept.txt",ios::in);
//    while (true)
//    {
//        if(f.fail())
//        {
//            break;
//        }
//        f>>x;
//        if(x==name[0])
//        {
//            cout<<x;
//            while(true){
//                f>>x;
//                if(x=='$')
//                {
//                    break;
//                } else{
//                    cout<<x;
//                }
//            }
//        }
//    }
//}
void  selectquery(string s)
{
    int index=0;
    for (int i = 0; i <s.length() ; ++i) {
        if (s[i]=='\''){
            index=i;
            break;
        }
    }
    string string1;
    for (int j = index; j <s.length()-2 ; ++j) {
        string1=string1+s[j+1];
    }
    const char *st=string1.c_str();
    readrecord(*st);
}

void  deleterecord(string id) {
    int c = 0, a = 0;
    fstream f;
    stringstream in(id);
    in >> a;
    char x;
    f.open("employee.txt", ios::out | ios::in);
    while (true) {
        if (f.fail()) {
            break;
        }
        f >> x;
        if (x == '$') {
            c++;
        }
        if (a==(c+1)) {
            f << "*"<<id;
            cout << "record deleted" << endl;
            break;

        }

    }
}
void  deleterecorddept(string id) {
    int c = 0, a = 0;
    fstream f;
    stringstream in(id);
    in >> a;
    char x;
    f.open("dept.txt", ios::out | ios::in);
    while (true) {
        if (f.fail()) {
            break;
        }
        f >> x;
        if (x == '$') {
            c++;
        }
        if (a==(c+1)) {
            f << "*"<<id;
            cout << "record deleted" << endl;
            break;

        }
    }
}
int main() {
    //addemp(2);
    //adddept(3);
    int input;
    while (true){
        screen();
        cin>>input;
        if (input==1){
            cout<<"please enter the number of employee that you will add"<<endl;
            int n;
            cin>>n;
            addemp(n);
        }else if (input==2){
            int n;
            cout<<"please enter the number of department that you will add"<<endl;
            cin>>n;
            adddept(n);
        }else if (input==3){
            string n;
            cout<<"please enter the id of employee that you will delete"<<endl;
            cin>>n;
            deleterecord(n) ;
        }else if (input==4){
            string n;
            cout<<"please enter the id of department that you will delete"<<endl;
            cin>>n;
            deleterecorddept(n) ;
        }else if (input==5){
            char n;
            cout<<"please enter the id of employee that you will print"<<endl;
            cin>>n;
            readrecord(n);
        }else if (input==6){
            break;
        }else if (input==7){
            char n;
            cout<<"please enter the id of employee that you will print"<<endl;
            cin>>n;
            readrecorddept(n);
        }else if (input==8){
            break;
        }else if (input==9){
            string st;
            cout<<"please enter the query "<<endl;
            cin>>st;
            selectquery(st);
            continue;
        }else if (input==10){
            break;
        }else{
            break;
        }
    }
    return 0;
}
