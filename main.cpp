#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
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

    string headerFile;
public:
    employee() {}

  //  employee(const employee &obj) {}

//    void changeheaderfile(int numrec, int RRn) {
//        emp.open("employee.txt", ios::out);
//        emp << numrec << RRn;
//
//    }

//   void search(){
//       binary_search(arr[])
//   }

};
//    employee GetEmployee(int RNN, fstream &infile) {
//        employee employee;
//        infile.seekg(RNN * 40, ios::beg);
//        infile.read((char*) &employee, sizeof employee);
//        return employee;
//    }
//
//    };
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
//void WritePrimIndex(PIndex PrmIndxArray[],int numRec,fstream&outfile) {
//    for(int i =0;i<numRec;i++){
//        outfile.write((char*)&PrmIndxArray[i].RRN,sizeof(int));
//        outfile.write(PrmIndxArray[i].ID.c_str(),13);
//    }
//}
void addemp(int num) {
    fstream emp("employee.txt", ios::out);
    employee e;
    e.primaryindex.open("p_indx.txt", ios::out);
    e.secondry.open("sec.txt",ios::out);
    PIndex *p=new PIndex[num];
    SIndex *s=new SIndex[num];

    for(int i=0;i<num;i++){
        cout << "\n employee  ID:\n";
        cin.getline(e.Employee_ID, 13);
        e.RRn=i;
        emp<<e.RRn<<",";
        emp << e.Employee_ID << ",";
        p[i].ID=e.Employee_ID;
        p[i].RRN=i;
        s[i].ID_e=e.Employee_ID;
        e.primaryindex<<p[i].RRN<<",";
        e.primaryindex << e.Employee_ID<<"$";
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
int  GetRecordRRN( int numRec, string ID) {
  //  employee e;
  //  e.emp.open("employee.txt",ios::in);
  //  e.emp.seekg(numRec, ios::beg);
    PIndex *p=new PIndex[numRec];
    int RRN = -1;
    int low = 0, mid, high = numRec - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        if (ID < p[mid].ID)
            high = mid - 1;
        else if (ID > p[mid].ID)
            low = mid + 1;
        else {
            RRN = p[mid].RRN;
          //  ID=p[mid].ID;
            break;
        }
    }

   // cout<<"Id"<<ID;
    return RRN;

}
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
        cin.getline(d.Dept_ID,30);
        dept<<d.Dept_ID<<',';
        t[i].ID=d.Dept_ID;
        t[i].RRN=i;
        d.d_index<<t[i].RRN<<",";
        d.d_index << d.Dept_ID<<"$";
        s[i].D_id=d.Dept_ID;
        d.s_index<<d.Dept_ID<<",";

        cout << "\n  Department Name:\n";
        cin.getline(d.Dept_Name,50);
        dept<<d.Dept_Name<<',';
        s[i].D_n=d.Dept_Name;
        d.s_index<<d.Dept_Name<<"$";


        cout << "\n Department manger: \n";
        cin.getline(d.Dept_Manger, 50);
        dept<<d.Dept_Manger<<'$';
    }
    dept.close();
    d.d_index.close();
    d.s_index.close();

}
int main() {
  //  employee e;
  //department d;
  // addemp(4);
 //  cout <<GetRecordRRN(4,"3");
   //adddept(1);
 // SearchById(4);

    return 0;
}
