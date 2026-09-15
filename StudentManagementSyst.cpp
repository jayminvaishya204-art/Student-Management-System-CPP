#include <iostream>
using namespace std;

void displayMenu() {
    cout << "============ Student Management System  ==============" << endl;
    cout << endl;
    cout << "1. Add Student." << endl;
    cout << "2. Display Students." << endl;
    cout << "3. Search Student." << endl;
    cout << "4. Highest score." << endl;
    cout << "5. Class Average." << endl;
    cout << "6. Exit." << endl;
    cout << endl;
}

void addStudent(string names[], int rollNo[], int marks[], int studentCount){
    if(studentCount<100){
        cout << "Enter Student's Name : " ;
        cin >> names[studentCount] ;
        cout << "Enter Student's Roll no. : ";
        cin >> rollNo[studentCount];
        cout << "Enter Student's Marks : ";
        cin >> marks[studentCount]; 
        cout << endl;
    }else{
        cout << "Database is Full!!" << endl;
        cout << endl;
    }
}

void displayStudents(string names[], int rollNo[], int marks[], int studentCount){
    for(int i=0; i<studentCount; i++){
        cout << "Name: " << names[i] << " RollNo: " << rollNo[i] << " Marks: " << marks[i] << endl;
    }
    cout << endl;
}

void searchStudent(string names[], int rollNo[], int marks[], int target, int studentCount){
    bool found = false;
    for(int i=0; i<studentCount; i++){
        if(rollNo[i] == target){
            cout << "Name : " << names[i] << " Roll no : " << rollNo[i] << "Marks : " << marks[i] << endl;
            found = true;
            break;
        }
    }
    if(!found){
        cout << "Student not Found." << endl;
    }
}

void highestScorer(string names[], int rollNo[], int marks[], int studentCount){
    int topperIndex = 0;
    if(studentCount == 0){
        cout << "No students found." << endl;
    }else{
        for(int i=1; i<studentCount; i++){
            if(marks[i]>marks[topperIndex]){
                topperIndex = i;
            }
        }
        cout << "Information about highest scorer" << endl;
        cout << "Name : " << names[topperIndex]
            << " Roll no. : " << rollNo[topperIndex]
            << " Marks : " << marks[topperIndex];         
    }
}

double classAvg(int marks[], int studentCount){
    int sum = 0;
    if(studentCount == 0){
        cout << "Student Not Found" << endl;
        return 0;
    }else{
        for(int i=0; i<studentCount; i++){
            sum+=marks[i];
        }
    }
    return sum/studentCount;
}

int main() {
    string names[100] ;
    int rollNo[100] ;
    int marks[100] ;
    int operation ;
    int studentCount = 0;
    int target ;
    do{
        displayMenu() ;
        cout << "Enter your choice(1-6) : " ;
        cin >> operation;

        switch(operation){
            case 1:
                addStudent(names, rollNo, marks, studentCount);
                if(studentCount<100){
                    studentCount++;
                }
                cout << endl;
                break;
            case 2:
                displayStudents(names, rollNo, marks, studentCount);
                cout << endl;
                break;
            case 3:
                cout << "Enter student's Roll no: ";
                cin >> target;
                searchStudent(names, rollNo, marks, target, studentCount);
                cout << endl;
                break;
            case 4:
                highestScorer(names, rollNo, marks, studentCount);
                cout << endl;
                break;
            case 5:
                cout << "Average marks of this class = " ;
                cout << classAvg(marks, studentCount) << endl;
                cout << endl;
                break;
            case 6:
                cout << "Thank you for using Student Management Student" << endl;
                cout << endl;
                break;
            default:
                cout << "Invalid choice. Try Again." << endl;
                cout << endl;
        }
    }while(operation != 6);

    return 0;
}