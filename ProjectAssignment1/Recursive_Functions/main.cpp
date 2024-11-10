#include <iostream>
#define SIZE 5
#define MAX 10
using namespace std;

int odd(long num)
{
    if(num % 10 == 0)
        return 0;
    if((num % 10) % 2 == 0)
        return odd(num / 10);
    else
        return odd(num / 10) + 1;
}
int largest(long num)
{
    int a, b;
    if(num == 0)
        return 0;
    a = num % 10;
    b = largest(num / 10);
    if(a>b)
        return a;
    return b;
}
int divider(int* arr, int size, long num)
{
    if(num == 0)
        return -1;
    if(size == 0)
        return 0;
    if(arr[size-1] % num == 0)
        return divider(arr, size-1, num) + 1;
    else
        return divider(arr, size-1, num);
}
bool alternating(double *arr, int size)
{
    if(size <= 1)
        return true;
    if(arr[0] == 0 || arr[1] == 0)
        return false;
    bool currentIsPositive = (arr[0] > 0);
    bool prevIsPositive = (arr[1] > 0);
    if (currentIsPositive == prevIsPositive)
        return false;
    return alternating(arr+1, size - 1);
}
void word(char* str)
{
    if(str[0] != '\0')
    {
        if(str[0] >= 'A' && str[0] <= 'Z')
            cout << str[0];
        word(str+1);
    }
}
int intersection(int *arr1, int *arr2, int size)
{
    if(size == 0)
        return 0;
    if(arr1[0] == arr2[0])
        return intersection(arr1+1, arr2+1, size-1) + 1;
    return intersection(arr1+1, arr2+1, size-1);
}
double maxElements(double *arr1, double *arr2, int size)
{
    if(size == 0)
        return 0;
    if(arr1[0] >= arr2[0])
        return maxElements(arr1+1, arr2+1, size-1) + arr1[0];
    else
        return maxElements(arr1+1, arr2+1, size-1) + arr2[0];
}
int series(int *arr, int size)
{
    if(size < 3)
        return true;
    int x = arr[0] - arr[1];
    if(arr[1] - arr[2] == x)
        return series(arr+1, size-1);
    else
        return false;
}
int main()
{
    int choice, arr[SIZE], arr2[SIZE]; // defining variables
    long num;
    double Rarr1[SIZE], Rarr2[SIZE];
    char str[MAX];
    do // do loop at least once, if choice = 9 leave loop else re-do loop
    {
        cout << "\n~~~~~Menu~~~~~" << endl;
        cout << "1.Odd\n2.Largest Digit\n3.Divider\n4.Alternating\n5.Big Letter\n6.Intersection\n7.Max Elements\n8.Series\n9.Exit" << endl; // printing menu
        cin >> choice; // receives input from user for choice
        switch (choice) // choosing a case depending on choice
        {
            case 1:// if choice is 1 then
                cout << "Type number (integer) to calculate how many odd digits: ";
                do // do at least once if num is lower/equal to 0 re-do loop
                {
                    cin >> num;
                    if(num <= 0)
                        cout << "Input error, please type a positive number: ";
                }
                while (num <= 0);
                cout << odd(num) << " odd digits in number given" << endl;
                break; // break from case
            case 2: // if choice is 2 then
                cout << "Type number (integer) to check largest digit: ";
                do // do at least once if num is lower than 0 re-do loop
                {
                    cin >> num;
                    if(num < 0)
                        cout << "Input error, please type a positive number: ";
                }
                while (num < 0);
                cout << largest(num) << " is the largest digit in this number" << endl;
                break; // break from case
            case 3: // if choice is 3 then
                cout << "Type " << SIZE << " numbers to divide (integers): ";
                for (int i = 0 ; i < SIZE; i++)
                    cin >> arr[i];
                cout << "Type divider number (integer): ";
                cin >> num;
                cout << divider(arr, SIZE, num) << " numbers from array divide without remainder for \"" << num << "\"" << endl;
                break; // break from case
            case 4: // if choice is 4 then
                cout << "Type " << SIZE << " numbers to check if alternating between positive / negative or vice versa: ";
                for (int i = 0 ; i < SIZE; i++)
                    cin >> Rarr1[i];
                if(alternating(Rarr1, SIZE))
                    cout << "1 TRUE alternating" << endl;
                else
                    cout << "0 FALSE not alternating" << endl;
                break; // break from case
            case 5: // if choice is 5 then
                cout << "Type a word (big letters will be printed): ";
                cin >> str;
                word(str);
                break; // break from case
            case 6:
                cout << "Type " << SIZE << " numbers (integers) for first group: ";
                for (int i = 0; i < SIZE; i++)
                    cin >> arr[i];
                cout << "Type " << SIZE << " numbers (integers) for second group: ";
                for (int i = 0; i < SIZE; i++)
                    cin >> arr2[i];
                cout << intersection(arr, arr2, SIZE) << " numbers that that are in the same index and equal" << endl;
                break;
            case 7:
                cout << "Type " << SIZE << " numbers for first group: ";
                for (int i = 0; i < SIZE; i++)
                    cin >> Rarr1[i];
                cout << "Type " << SIZE << " numbers for second group: ";
                for (int i = 0; i < SIZE; i++)
                    cin >> Rarr2[i];
                cout << maxElements(Rarr1, Rarr2, SIZE) << " Total of highest number of each index" << endl;
                break;
            case 8:
                cout << "Type " << SIZE << " numbers to check if a series: ";
                for (int i = 0; i < SIZE; i++)
                    cin >> arr[i];
                if(series(arr, SIZE))
                    cout << "1 TRUE" << endl;
                else
                    cout << "0 FALSE" << endl;
                break;
            case 9: // if choice is 9 then
                cout << "Goodbye" << endl; // printing
                break; // break from case
            default: // anything else then
                cout << "Not a valid choice.\nChoose again.\n"; // printing
                break; // break from case
        }
    }
    while (choice != 9); // while choice is not 6 re-do loop until choice is 6
    return 0;
}

