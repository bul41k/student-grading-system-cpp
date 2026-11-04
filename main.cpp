#include <iomanip>
#include <iostream>
#include <string>
using namespace std;


int main() {
    const int MAX_GRADES = 10;
    const int MIN_GRADES = 1;
    const int MAX_STUDENTS = 100;
    string studentNames[MAX_STUDENTS];
    int studentGrades[MAX_STUDENTS][MAX_GRADES];

    int studentCount = 0;
    int gradeCounts[MAX_STUDENTS] = {0};

    int choice;

    cout << fixed << setprecision(2);

    do {
        cout << "\n--- Meniu ---\n" << endl;
        cout << "1. Ivesti mokini ir jo pazymius" << endl;
        cout << "2. Perziureti visu mokiniu pazymius" << endl;
        cout << "3. Perziureti konkertaus mokinio pazymius" << endl;
        cout << "4. Atnaujinti pazymius" << endl;
        cout << "5. Apskaiciuoti mokinio vidurki" << endl;
        cout << "6. Pasalinti mokini" << endl;
        cout << "7. Iseiti" << endl;
        cout << "Pasirinkite savo veiksma (1-7)" << endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                if (studentCount >= MAX_STUDENTS) {
                    cout << "Klaida: maksimum iki 100" << endl;
                    break;
                }

                cout << "Iveskite mokinio varda" << endl;
                cin >> studentNames[studentCount];

                int numGrades;
                cout << "Kiek pazymiu norite ivesti mokiniui (1-10)" << endl;
                cin >> numGrades;

                while (numGrades < MIN_GRADES || numGrades > MAX_GRADES) {
                    cout << "Klaida reikia nuo 1 iki 10. Iveskite is naujo" << endl;
                    cin >> numGrades;
                }

                for (int j = 0; j < numGrades; j++) {
                    int grade;
                    cout << "Iveskite " << j+1 << " -aji pazymi (1-10): " << endl;
                    cin >> grade;

                    while (grade < MIN_GRADES || grade > MAX_GRADES) {
                        cout << "Klaida: pazymys turi buti nuo 1 iki 10. Iveskite is naujo: ";
                        cin >> grade;
                    }
                    studentGrades[studentCount][j] = grade;
                }
                gradeCounts[studentCount] = numGrades;
                studentCount++;
                cout << "Mokinys sekmingai pridetas!" << endl;
                break;
            }


            case 2: {
                if (studentCount == 0) {
                    cout << "Tuscias" << endl;
                    break;
                }


                cout << "\n--- Visu mokiniu pazymiai ---" << endl;

                for (int i = 0; i < studentCount; i++) {
                    cout << i + 1 << ". " << studentNames[i] << endl;


                    for (int j = 0; j < gradeCounts[i]; j++) {
                        cout << studentGrades[i][j] << " ";
                    }
                }

                cout << endl;
                break;
            }

            case 3: {

                if (studentCount == 0) {
                    cout << "Tuscias" << endl;
                    break;
                }

                cout << "Pasirinkite kokia mokinius norite patikrinti pazymius" << endl;
                for (int i = 0; i < studentCount; i++) {
                    cout << i + 1 << ". " << studentNames[i] << endl;
                }

                int choiceNumber;
                cin >> choiceNumber;

                while (choiceNumber < 1 || choiceNumber > studentCount) {
                    cout << "Parasykite dar karta" << endl;
                    cin >> choiceNumber;
                }

                int index = choiceNumber - 1;

                cout << "\nMokinys: " << studentNames[index] << endl;
                cout << "Pazymiai: ";
                for (int j = 0; j < gradeCounts[index]; j++) {
                    cout << studentGrades[index][j] << " ";
                }
                cout << endl;
                break;
            }

            /* Atnaujinti programa */
            case 4: {
                if (studentCount == 0) {
                    cout << "Tuscias" << endl;
                    break;
                }

                cout << "Pasirinkite kokia mokiniui jus norite atnaujinti pazymius" << endl;
                for (int i = 0; i < studentCount; i++) {
                    cout << i + 1 << ". " << studentNames[i] << endl;
                }

                int choiceNumber;
                int choiceGrade;
                int newGrade;

                cin >> choiceNumber;

                while (choiceNumber < 1 || choiceNumber > studentCount) {
                    cout << "Parasykite dar karta" << endl;
                    cin >> choiceNumber;
                }

                int studentIndex = choiceNumber - 1;


                cout << "Mokinys: " << studentNames[studentIndex] << endl;
                cout << "Pazymiai: ";
                for (int j = 0; j < gradeCounts[studentIndex]; j++) {
                    cout << j + 1 << ". " << studentGrades[studentIndex][j] << " ";
                }

                cin >> choiceGrade;
                while (choiceGrade < 1 || choiceGrade > gradeCounts[studentIndex]) {
                    cout << "Parasykite dar karta" << endl;
                    cin >> choiceGrade;
                }

                int gradeIndex = choiceGrade - 1;

                cout << "\nIveskite nauja pazymi (1-10): " << endl;
                cin >> newGrade;

                while (newGrade < MIN_GRADES || newGrade > MAX_GRADES) {
                    cout << "Klaida" << endl;
                    cin >> newGrade;
                }

                studentGrades[studentIndex][gradeIndex] = newGrade;

                cout << "Pazymys sekmingai atnaujintas!" << endl;

                break;

            }
            case 5: {
                if (studentCount == 0) {
                    cout << "Tuscias" << endl;
                }

                int choiceNumber;

                cout << "Pasirinktie kokio mokinio norite paskaiuoti vidurkis pazymius" << endl;
                for (int i = 0; i < studentCount; i++) {
                    cout << i + 1 << ". " << studentNames[i] << endl;
                }
                cin >> choiceNumber;

                while (choiceNumber < 1 || choiceNumber > studentCount) {
                    cout << "Parasykite dar karta" << endl;
                    cin >> choiceNumber;
                }


                int studentIndex = choiceNumber - 1;

                if (gradeCounts[studentIndex] == 0) {
                    cout << "Mokinys " << studentNames[studentIndex] << " neturi ivestu pazymius" << endl;
                    break;
                }

                int suma = 0;

                for (int j = 0; j < gradeCounts[studentIndex]; j++) {
                    suma += studentGrades[studentIndex][j];
                }

                double averageGrade = static_cast<double>(suma) / gradeCounts[studentIndex];

                cout << "\nMokinys: " << studentNames[studentIndex] << endl;
                cout << "Vidurkis pazymiai: " << averageGrade << endl;

                break;
            }
        }
    } while (choice != 7);

    return 0;

}