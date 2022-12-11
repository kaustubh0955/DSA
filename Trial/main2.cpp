
#include <bits/stdc++.h>
using namespace std;
class Student
{
private:
    string name;
    float gpa;
    int rollNumber;

public:
    Student();
    void setName(string name_input);
    void setGpa(float gpa_input);
    void setRollNumber(int rollNumber_input);
    void displayStudent();
    string getName();
    float getGpa();
    int getRollNumber();
};
Student::Student()
{
    name = "abc";
    gpa = 1.0;
    rollNumber = 0;
}
void Student::setName(string name_input)
{
    name = name_input;
}
void Student::setGpa(float gpa_input)
{
    gpa = gpa_input;
}
void Student::setRollNumber(int rollNumber_input)
{
    rollNumber = rollNumber_input;
}
void Student::displayStudent()
{
    cout << "Name : " << name;
    cout << "GPA : " << gpa << endl;
    cout << "Roll Number : " << rollNumber << endl;
}
string Student::getName()
{
    return name;
}
float Student::getGpa()
{
    return gpa;
}
int Student::getRollNumber()
{
    return rollNumber;
}
#define MAX_STUDENTS 5
void executeAction(char);
int addStudent(string name_input, float gpa_input, int rollNumber_input);
void displayStudents();
void sort();
void studentsAfterGivenYear();
Student s[MAX_STUDENTS];
int currentCount = 0;
int main()
{
    char choice = 'i';
    do
    {
        cout << "\n BCSE202P \n";
        cout << "Please select an action:\n";
        cout << "\t a: add a new student\n";
        cout << "\t d: display student list\n";
        cout << "\t s: sort the students by GPA\n";
        cout << "\t n: display students enrolled after given year\n";
        cout << "\t q: quit\n";
        cin >> choice;
        cin.ignore();
        executeAction(choice);
    } while (choice != 'q');
    return 0;
}
void executeAction(char c)
{
    string name_input;
    float gpa_input;
    int rollNumber_input, result = 0;
    switch (c)
    {
    case 'a':
        cout << "Please enter student name: ";
        getline(cin, name_input);
        cout << "Please enter GPA: ";
        cin >> gpa_input;
        cin.ignore();
        cout << "Please enter roll number: ";
        cin >> rollNumber_input;
        cin.ignore();
        result = addStudent(name_input, gpa_input, rollNumber_input);
        if (result == 0)
            cout << "\nThat student is already in the list or list is full! \n\n";
        else
            cout << "\nStudent successfully added to the list! \n\n";
        break;
    case 'd':
        displayStudents();
        break;
    case 's':
        sort();
        break;
    case 'n':
        studentsAfterGivenYear();
        break;
    case 'q':
        break;
    default:
        cout << c << " is invalid input!\n";
    }
}
int addStudent(string name_input, float gpa_input, int rollNumber_input)
{
    if (currentCount < MAX_STUDENTS)
    {
        for (int i = 0; i < currentCount; i++)
            if ((s[i].getName() == name_input) && (s[i].getGpa() == gpa_input) &&
                (s[i].getRollNumber() == rollNumber_input))
                return 0;
        Student temp;
        temp.setName(name_input);
        temp.setGpa(gpa_input);
        temp.setRollNumber(rollNumber_input);
        s[currentCount] = temp;
        currentCount++;
        return 1;
    }
    return 0;
}
void displayStudents()
{
    for (int i = 0; i < currentCount; i++)
    {
        s[i].displayStudent();
        cout << endl;
    }
}
void sort()
{
    Student temp;
    int max;
    for (int i = 0; i < currentCount - 1; i++)
    {
        max = i;
        for (int j = i + 1; j < currentCount; j++)
        {
            if (s[j].getRollNumber() > s[max].getRollNumber())
                max = j;
        }
        if (max != i)
        {
            temp = s[i];
            s[i] = s[max];
            s[max] = temp;
        }
    }
    cout << endl
         << "Student list sorted! Use d option to see the sorted result." << endl;
}
void studentsAfterGivenYear()
{
    int cap;
    Student *newStudent = new Student;
    cout << "Enter the cap bound of cgpa : ";
    cin >> cap;
    for (int i = 0; i < currentCount; i++)
    {
        if (s[i].getGpa() >= cap)
        {
            newStudent->setGpa(s[i].getGpa());
            newStudent->setName(s[i].getName());
            newStudent->setRollNumber(s[i].getRollNumber());
            newStudent->displayStudent();
            cout << endl;
        }
    }
}