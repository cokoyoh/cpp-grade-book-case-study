#include <iomanip>
#include <array>
#include <iostream>
#include <iomanip>
using namespace std;

class GradeBooK {
public:
    static const size_t students{10};

    GradeBooK(const string &name,
              const array<int, students>&gradeArray):
    courseName{name}, grades{gradeArray}{
        //code here
    }

    void setCourseName(const string &name) {
        courseName = name;
    }

    const string &getCourseName() const {
        return courseName;
    }

    void displayMessage() const {
        cout << "Welcome to grade book for\n" << getCourseName() << "!" << endl;
    }

    void processGrades() const {
        outputGrades();

        cout << setprecision(2) << fixed;
        cout << "\nClass average is " << getAverage() << endl;

        cout << "Lowest grade is " << getMinimum()
            <<"\nHighest grade is " << getMaximum()
            << endl;

        outputBarChart();
    }

    int getMinimum() const {
        int lowestGrade{100}; // assume lowest grade is 100

        for(int grade: grades) {
            if(grade < lowestGrade) {
                lowestGrade = grade;
            }
        }

        return lowestGrade;
    }

    int getMaximum() const {
        int highestGrade{100};

        for(int grade: grades) {
            if(grade > highestGrade) {
                highestGrade = grade;
            }
        }

        return highestGrade;
    }

    double getAverage() const {
        int total{0};

        for(int grade: grades) {
            total += grade;
        }

        return static_cast<double>(total)/grades.size();
    }

    void outputBarChart() const {
        cout << "\nGrade distribution: " << endl;

        // store frequency of grades in each range of 10 grades
        const size_t frequencySize{11};
        array<unsigned int, frequencySize> frequency{}; // init to 0

        for(int grade: grades) {
            frequency[grade/10]++;
        }

        for(size_t count{0}; count < frequencySize; count++) {
            if(count == 0) {
                cout << " 0-9: ";
            } else if(count == 10) {
                cout << " 100: ";
            } else {
                cout << count * 10 << "-" << (count * 10) + 9 << ": ";
            }

            for(unsigned int stars{0}; stars < frequency[count]; stars++) {
                cout << "*";
            }

            cout << endl;
        }
    }

    void outputGrades() const{
        cout << "\nThe grades are:\n\n";

        for(size_t student{0}; student < grades.size(); student++) {
            cout << "Student" << setw(2) << student + 1 << ": "
                << setw(3) << grades[student] << endl;
        }
    }

private:
    string courseName;
    array<int, students>grades;
};