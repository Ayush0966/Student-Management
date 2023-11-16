#include <iostream>
#include <string>

using namespace std;

struct student {
    string first_name;
    string last_name;
    int roll_number;
    double cgpa;
    int course_id[10];
} students[110];

int number_of_students = 0;

void addStudentDetails() {
    cout << "---- Enter the new student details ----\n";

    cout << "Enter the Roll Number of the student\n";
    int roll_no;
    cin >> roll_no;

    for (int i = 0; i < number_of_students; i++) {
        if (students[i].roll_number == roll_no) {
            cout << "Student with the given roll number already exists in the database\n";
            return;
        }
    }

    cout << "Enter the first name of the student\n";
    cin >> students[number_of_students].first_name;

    cout << "Enter the last name of the student\n";
    cin >> students[number_of_students].last_name;

    students[number_of_students].roll_number = roll_no;

    cout << "Enter the CGPA of the student\n";
    cin >> students[number_of_students].cgpa;

    cout << "Enter the course ID of each course in which the student is enrolled in\n";
    for (int i = 0; i < 5; i++) {
        cin >> students[number_of_students].course_id[i];
    }

    number_of_students++;
}

void findStudentByRollNumber() {
    int roll_no;
    cout << "Enter the Roll Number of the student\n";
    cin >> roll_no;

    bool found = false;

    for (int i = 0; i < number_of_students; i++) {
        if (roll_no == students[i].roll_number) {
            found = true;

            cout << "The Students Details are:\n";

            cout << "The First name is " << students[i].first_name << "\n";
            cout << "The Last name is " << students[i].last_name << "\n";
            cout << "The CGPA is " << students[i].cgpa << "\n";
            cout << "The course ID of each course\n";

            for (int j = 0; j < 5; j++) {
                cout << students[i].course_id[j] << " ";
            }

            break;
        }
    }

    if (!found)
        cout << "No such student with the given roll number\n";
}

void findStudentByFirstName() {
    string firstName;
    cout << "Enter the first name of the student\n";
    cin >> firstName;

    bool found = false;

    for (int i = 0; i < number_of_students; i++) {
        if (firstName == students[i].first_name) {
            found = true;

            cout << "The Students Details are\n";

            cout << "The First name is " << students[i].first_name << "\n";
            cout << "The Last name is " << students[i].last_name << "\n";
            cout << "The CGPA is " << students[i].cgpa << "\n";
            cout << "The course ID of each course\n";

            for (int j = 0; j < 5; j++) {
                cout << students[i].course_id[j] << " ";
            }

            cout << "\n";
        }
    }

    if (!found)
        cout << "No such student with the given first name\n";
}

void findStudentByCourseId() {
    int id;
    cout << "Enter the course id\n";
    cin >> id;

    bool found = false;

    for (int i = 0; i < number_of_students; i++) {
        for (int j = 0; j < 5; j++) {
            if (id == students[i].course_id[j]) {
                found = true;

                cout << "The Students Details are\n";

                cout << "The First name is " << students[i].first_name << "\n";
                cout << "The Last name is " << students[i].last_name << "\n";
                cout << "The CGPA is " << students[i].cgpa << "\n";
                cout << "\n";
            }
        }
    }

    if (!found)
        cout << "No such students with the given course id\n";
}

void findTotalStudents() {
    cout << "The total number Students are " << number_of_students << "\n";
    cout << "You can have a maximum of 110 students in the database\n";
}

void deleteStudentByRollNumber() {
    int roll_no;
    cout << "Enter the Roll Number that you want to delete\n";
    cin >> roll_no;

    bool found = false;
    for (int i = 0; i < number_of_students; i++) {
        if (roll_no == students[i].roll_number) {
            found = true;
            for (int j = i; j < number_of_students - 1; j++) {
                students[j] = students[j + 1];
            }
            // Set the last element to a default or empty value
            students[number_of_students - 1] = {}; // This will reset the last element
            number_of_students--;
            cout << "The Roll Number is removed Successfully\n";
        }
    }

    if (found) {
        cout << "The Roll Number is removed Successfully\n";
    } else {
        cout << "Roll number not found in the database\n";
    }
}

void updateStudentDetails() {
    cout << "Enter the roll number whose details you want to update\n";
    int roll_no;
    cin >> roll_no;

    bool found = false;
    for (int i = 0; i < number_of_students; i++) {
        if (students[i].roll_number == roll_no) {
            found = true;
            cout << "1. Update first name\n"
                "2. Update last name\n"
                "3. Update roll number.\n"
                "4. Update CGPA\n"
                "5. Update courses\n";

            int choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter the new first name\n";
                    cin >> students[i].first_name;
                    break;

                case 2:
                    cout << "Enter the new last name\n";
                    cin >> students[i].last_name;
                    break;

                case 3:
                    cout << "Enter the new roll number\n";
                    cin >> students[i].roll_number;
                    break;

                case 4:
                    cout << "Enter the new CGPA\n";
                    cin >> students[i].cgpa;
                    break;

                case 5:
                    cout << "Enter the new courses \n";
                    for (int j = 0; j < 5; j++) {
                        cin >> students[i].course_id[j];
                    }
                    break;
            }
        }
    }

    if (found) {
        cout << "Details updated successfully.\n";
    } else {
        cout << "Student not found in the database.\n";
    }
}

void displayAllStudents() {
    if (number_of_students == 0) {
        cout << "No students in the database." << endl;
        return;
    }

    cout << "All Student Records:\n";

    for (int i = 0; i < number_of_students; i++) {
        cout << "Student " << i + 1 << " Details:\n";
        cout << "First Name: " << students[i].first_name << "\n";
        cout << "Last Name: " << students[i].last_name << "\n";
        cout << "Roll Number: " << students[i].roll_number << "\n";
        cout << "CGPA: " << students[i].cgpa << "\n";
        cout << "Course IDs: ";
        for (int j = 0; j < 5; j++) {
            cout << students[i].course_id[j] << " ";
        }
        cout << "\n";
    }
}

void viewStudentOptions() {
    cout << "Enter your first name: ";
    string first_name;
    cin >> first_name;

    cout << "Enter your roll number: ";
    int roll_number;
    cin >> roll_number;

    bool found = false;

    for (int i = 0; i < number_of_students; i++) {
        if (first_name == students[i].first_name && roll_number == students[i].roll_number) {
            found = true;

            cout << "Welcome, " << first_name << "!\n";
            cout << "Select an option:\n";
            cout << "1. Project Deadlines\n";
            cout << "2. Quiz Dates and Time\n";
            cout << "3. Holidays\n";
            cout << "4. Time Table\n";
            cout << "5. Exit\n";

            int option;
            cin >> option;

            switch (option) {
                case 1:
                    cout << "Displaying project deadlines for " << first_name << "...\n";
                    cout << "Software Development      29-11-2023"<<endl;
                    cout << "C++                       06-11-2023"<<endl;
                    cout << "AI                        05-12-2023"<<endl;
                    // Implement the logic to show project deadlines for this student
                    break;
                case 2:
                    cout << "Displaying quiz dates and times for " << first_name << "...\n";
                    cout << "Probability    06-11-2023       10:40:00"<<endl;
                    // Implement the logic to show quiz dates and times for this student
                    break;
                case 3:
                    cout << "Displaying holidays for " << first_name << "...\n";
                    cout <<"1.Diwali"<<endl;
                    cout <<"2.Holi"<<endl;
                    cout <<"3.New Years"<<endl;
                    // Implement the logic to show holidays for this student
                    break;
                case 4:
                    cout << "Displaying Time Table for " << first_name << "...\n";
                    break;
                case 5:
                    return; // Exit this function
                default:
                    cout << "Invalid option. Please try again.\n";
            }
        }
    }

    if (!found)
        cout << "No student found with the given first name and roll number.\n";
}

void findStudentsByCourseId() {
    int id;
    cout << "Enter the course id: ";
    cin >> id;

    bool found = false;

    cout << "Students in course " << id << ":\n";

    for (int i = 0; i < number_of_students; i++) {
        for (int j = 0; j < 5; j++) {
            if (id == students[i].course_id[j]) {
                found = true;

                cout << "Student " << i + 1 << " Details:\n";
                cout << "First Name: " << students[i].first_name << "\n";
                cout << "Last Name: " << students[i].last_name << "\n";
                cout << "Roll Number: " << students[i].roll_number << "\n";
                cout << "CGPA: " << students[i].cgpa << "\n";
                cout << "Course IDs: ";
                for (int k = 0; k < 5; k++) {
                    cout << students[i].course_id[k] << " ";
                }
                cout << "\n";
            }
        }
    }

    if (!found)
        cout << "No students found in course " << id << "\n";
}

int main() {
    int choice;
    while (true) {
        cout << "----- Student Management System -----\n";
        cout << "1. Add new Student to the database\n";
        cout << "2. Search Student by Roll Number\n";
        cout << "3. Search Student by First Name\n";
        cout << "4. Search Student by Course ID\n";
        cout << "5. Count Total number of Students\n";
        cout << "6. Delete the Student by Roll Number\n";
        cout << "7. Update Student Details by Roll Number\n";
        cout << "8. Display All Student Records\n"; // Option to display all student records
        cout << "9. Student Options (based on first name and roll number)\n";
        cout << "10. Find Students by Course ID\n"; // Option to find students by course ID

        cout << "0. Exit the program\n";

        cout << "Enter your choice:";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudentDetails();
                break;
            case 2:
                findStudentByRollNumber();
                break;
            case 3:
                findStudentByFirstName();
                break;
            case 4:
                findStudentByCourseId();
                break;
            case 5:
                findTotalStudents();
                break;
            case 6:
                deleteStudentByRollNumber();
                break;
            case 7:
                updateStudentDetails();
                break;
            case 8:
                displayAllStudents();
                break;
            case 9:
                viewStudentOptions();
                break;
            case 10:
                findStudentsByCourseId();
                break;
            case 0:
                cout<< "Exiting the program \n.\n.\n.\n.\n.\n.\n";
                cout << ".... Exited The Program ....";
                exit(0);
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
