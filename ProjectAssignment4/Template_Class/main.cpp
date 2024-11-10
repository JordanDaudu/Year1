#include <iostream>
#include "Set.h"
#include "Person.h"
#define MAX 10
using namespace std;

int main()
{
    int size;
    char name[MAX];
    long id;
    cout << "~~~Lets get arrays of all 3 kind of objects~~~" << endl;
    // getting first int array
    cout << "Type size of first whole numbers array: ";
    cin >> size;
    int *intArr1 = new int[size];
    cout << "Type " << size << " whole numbers: ";
    for(int i = 0; i < size; i++)
        cin >> intArr1[i];
    Set<int> setInt1(intArr1, size);
    // getting second int array
    cout << "Type size of second whole numbers array: ";
    cin >> size;
    int *intArr2 = new int[size];
    cout << "Type " << size << " whole numbers: ";
    for(int i = 0; i < size; i++)
        cin >> intArr2[i];
    Set<int> setInt2(intArr2, size);
    // getting first float array
    cout << "Type size of first rational numbers array: ";
    cin >> size;
    float *floatArr1 = new float[size];
    cout << "Type " << size << " rational numbers: ";
    for(int i = 0; i < size; i++)
        cin >> floatArr1[i];
    Set<float> setFloat1(floatArr1, size);
    // getting second float array
    cout << "Type size of second rational numbers array: ";
    cin >> size;
    float *floatArr2 = new float[size];
    cout << "Type " << size << " rational numbers: ";
    for(int i = 0; i < size; i++)
        cin >> floatArr2[i];
    Set<float> setFloat2(floatArr2, size);
    // getting first Person array:
    cout << "Type size of first Person array: ";
    cin >> size;
    Person *personArr1 = new Person[size];
    cout << "Lets get information on " << size << " persons: " << endl;
    for(int i = 0; i < size; i++)
    {
        cout << "Type person " << i+1 << " name and id: ";
        cin >> name >> id;
        personArr1[i].setParameters(name, id);
    }
    Set<Person> setPerson1(personArr1, size);
    // getting second person array:

    cout << "Type size of second Person array: ";
    cin >> size;
    Person *personArr2 = new Person[size];
    cout << "Lets get information on " << size << " persons: " << endl;
    for(int i = 0; i < size; i++)
    {
        cout << "Type person " << i+1 << " name and id: ";
        cin >> name >> id;
        personArr2[i].setParameters(name, id);
    }
    Set<Person> setPerson2(personArr2, size);
    // checking if sets of each object are the same
    cout << "\n||Checking sets of objects if they are the same||" << endl;
    cout << "~~~Whole numbers~~~" << endl;
    if(setInt1 == setInt2)
        cout << "TRUE, the whole numbers sets are identical" << endl;
    else
        cout << "FALSE, the whole numbers sets are not identical" << endl;
    cout << "~~~Rational numbers~~~" << endl;
    if(setFloat1 == setFloat2)
        cout << "TRUE, the rational numbers sets are identical" << endl;
    else
        cout << "FALSE, the whole numbers sets are not identical" << endl;
    cout << "~~~Persons~~~" << endl;
    if(setPerson1 == setPerson2)
        cout << "TRUE, the person sets are identical" << endl;
    else
        cout << "FALSE, the person sets are not identical" << endl;
    // getting union of sets
    cout << "\n||Union of sets||" << endl;
    cout << "~~~Whole numbers~~~" << endl;
    cout << "{" << setInt1 + setInt2 << "}" << endl;
    cout << "~~~Rational numbers~~~" << endl;
    cout << "{" << setFloat1 + setFloat2 << "}" << endl;
    cout << "~~~Persons~~~" << endl;
    cout << setPerson1 + setPerson2 << endl;
    // getting difference of sets
    cout << "||Difference of sets||" << endl;
    cout << "~~~Whole numbers~~~" << endl;
    cout << "First set - Second set: {" << setInt1 - setInt2 << "}" << endl;
    cout << "Second set - First set: {" << setInt2 - setInt1 << "}" << endl;
    cout << "~~~Rational numbers~~~" << endl;
    cout << "First set - Second set: {" << setFloat1 - setFloat2 << "}" << endl;
    cout << "Second set - First set: {" << setFloat2 - setFloat1 << "}" << endl;
    cout << "~~~Persons~~~" << endl;
    cout << "First person set - Second person set:\n" << setPerson1 - setPerson2 << endl;
    cout << "Second Person set - First person set:\n" << setPerson2 - setPerson1 << endl;
    // getting intersection of sets
    cout << "||Intersection of sets||" << endl;
    cout << "~~~Whole numbers~~~" << endl;
    cout << "{" << setInt1 * setInt2 << "}" << endl;
    cout << "~~~Rational numbers~~~" << endl;
    cout << "{" << setFloat1 * setFloat2 << "}" << endl;
    cout << "~~~Persons~~~" << endl;
    cout << setPerson1 * setPerson2 << endl;
    return 0;
}