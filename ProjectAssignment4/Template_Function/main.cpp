#include <iostream>
using namespace std;

template <class T>
T *remove(T *arr, int size, T val, int &newSize)
{
    int p = 0;
    for(int i = 0; i < size; i++)
        if(arr[i] == val)
            p++;
    newSize = size - p;
    T *newArr = new T[newSize];
    p = 0;
    for(int i = 0; i < size; i++)
        if(arr[i] != val)
            newArr[p++] = arr[i];
    return newArr;
}
int main()
{
    int newFloatSize, newLongSize, floatSize, longSize;
    float floatVal, *newFloatArr = nullptr;
    long longVal, *newLongArr = nullptr;
    // float array code:
    cout << "Type the array size of float array: ";
    cin >> floatSize;
    float *fArr = new float[floatSize];
    cout << "Type " << floatSize << " numbers to add to float array: ";
    for(int i = 0; i < floatSize; i++)
        cin >> fArr[i];
    cout << "\nType number to be deleted from float array: ";
    cin >> floatVal;
    newFloatArr = remove(fArr, floatSize, floatVal, newFloatSize);
    // checking if original array was empty, also checking if new array is empty and printing accordingly
    if(floatSize != 0)
    {
        cout << "||Printing new array after deleting {" << floatVal << "}||\n{";
        if(newFloatSize == 0)
            cout << "}" << endl;
        else
        {
            for(int i = 0; i < newFloatSize-1; i++)
                cout << newFloatArr[i] << ", ";
            cout << newFloatArr[newFloatSize-1] << "}" << endl;
        }
    }
    else
        cout << "Float Array was empty..." << endl;
    // long array code:
    cout << "\nType the array size of long array: ";
    cin >> longSize;
    long *lArr = new long[longSize];
    cout << "Type " << longSize << " numbers to add to long array: ";
    for(int i = 0; i < longSize; i++)
        cin >> lArr[i];
    cout << "\nType number to be deleted from long array: ";
    cin >> longVal;
    newLongArr = remove(lArr, longSize, longVal, newLongSize);
    // checking if original array was empty, also checking if new array is empty and printing accordingly
    if(longSize != 0)
    {
        cout << "||Printing new array after deleting {" << longVal << "}||\n{";
        if(newLongSize == 0)
            cout << "}" << endl;
        else
        {
            for(int i = 0; i < newLongSize-1; i++)
                cout << newLongArr[i] << ", ";
            cout << newLongArr[newLongSize-1] << "}" << endl;
        }
    }
    else
        cout << "Long Array was empty..." << endl;
    delete[] fArr;
    delete[] newFloatArr;
    delete[] lArr;
    delete[] newLongArr;
    return 0;
}
