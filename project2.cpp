#include <iostream>

using namespace std;

void displayMenu()
{
    cout << "1. Add Student\n";
    cout << "2. Search By ID\n";
    cout << "3. Grades Statistics\n";
    cout << "4. Remove a Student\n";
    cout << "5. Print all Students\n";
    cout << "6. Exit the System\n";
}

void gradestats(double grade[], int n)
{
    double high = -1.0;
    double low = 101.0;
    double sum = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (grade[i] > high)
        {
            high = grade[i];
        }
        if (grade[i] < low)
        {
            low = grade[i];
        }

        sum += grade[i];
    }

    double average = sum / n;

    cout << "Highest grade: " << high << endl;
    cout << "Lowest grade: " << low << endl;
    cout << "Average grade: " << average << endl;
}

void removeStudent(int id[], string names[], double grade[], int &n, int studentId)
{
    int index = -1;

    // Find the index of the student with the given ID
    for (int i = 0; i < n; i++)
    {
        if (id[i] == studentId)
        {
            index = i;
            break;
        }
    }

    // If the student is found, remove them from the arrays
    if (index != -1)
    {
        for (int i = index; i < n - 1; i++)
        {
            id[i] = id[i + 1];
            names[i] = names[i + 1];
            grade[i] = grade[i + 1];
        }

        n--; // Decrease the count of students
        cout << "Student with ID " << studentId << " removed.\n";

    // Adjust the IDs for the students after the removed student
        for (int i = index; i < n; i++)
        {
            id[i]--; // Decrement the ID
        }
    }
    else
    {
        cout << "Student with ID " << studentId << " not found.\n";
    }
}

int main()
{
    int id[100];
    string names[100];
    double grade[100];

    int n = 0; // number of elements in array
    int search;
    int menunum;
    bool studentFound = false;

    cout << "***CSCI 1010 Student Information Management System***\n";

    do
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> menunum;

        switch (menunum)
        {
        case 1:
            cout << "Enter the student's name: ";
            cin >> names[n];
            cout << "Enter the student's grade: ";
            cin >> grade[n];
            id[n] = n + 1;
            n++;
            break;

        case 2:
            cout << "Enter the ID number: ";
            cin >> search;
            studentFound = false;

            for (int i = 0; i < n; i++)
            {
                if (id[i] == search)
                {
                    cout << "ID: " << id[i] << "\tName: " << names[i] << "\tGrade: " << grade[i] << endl;
                    studentFound = true;
                    break;
                }
            }

            if (!studentFound)
            {
                cout << "Student not found.\n";
            }
            break;

        case 3:
            gradestats(grade, n);
            break;

        case 4:
            cout << "Enter the ID number of the student to remove: ";
            cin >> search;
            removeStudent(id, names, grade, n, search);
            break;

        case 5:
            // Print all students
            for (int i = 0; i < n; i++)
            {
                cout << "ID: " << id[i] << "\tName: " << names[i] << "\tGrade: " << grade[i] << endl;
            }
            break;

        case 6:
            cout << "Exiting the System.\n";
            break;

        default:
            cout << "Please enter a valid number.\n";
        }
    } while (menunum != 6);

    return 0;
}

