//Kazi Nafisur Rahman Nafis

#include <iostream>
//24-57947-2
#include <string>
using namespace std;

// Task 1: Numeric Constant Check
void checkNumeric(string str)
{
    bool numeric = true;

    if(str.length() == 0)
        numeric = false;

    for(int i = 0; i < str.length(); i++)
    {
        int ascii = (int)str[i];

        if(ascii < 48 || ascii > 57)
        {
            numeric = false;
            break;
        }
    }

    if(numeric)
        cout << "Numeric Constant" << endl;
    else
        cout << "Not Numeric Constant" << endl;
}

// Task 2: Operator Check
void operators(string str)
{
    bool found = false;

    for(int i = 0; i < str.length(); i++)
    {
        int ascii = (int)str[i];

        switch(ascii)
        {
        case 43:
            cout << "Operator: + (Plus)" << endl;
            found = true;
            break;

        case 45:
            cout << "Operator: - (Minus)" << endl;
            found = true;
            break;

        case 42:
            cout << "Operator: * (Multiplication)" << endl;
            found = true;
            break;

        case 47:
            cout << "Operator: / (Division)" << endl;
            found = true;
            break;

        case 37:
            cout << "Operator: % (Remainder)" << endl;
            found = true;
            break;

         case 61:
            if(i + 1 < str.length() && str[i + 1] == '=')
            {
                cout << "Operator: == (Equals)" << endl;
                i++;
            }
            else
            {
                cout << "Operator: = (Assignment)" << endl;
            }

            found = true;
            break;

        }
    }

    if(!found)
    {
        cout << "No Operator Found" << endl;
    }
}

// Task 3: Comment Check
void comment(string str)
{
    int l = str.length();

    if(l < 2)
    {
        cout << "Not a Comment" << endl;
        return;
    }

    if(str[0] == '/' && str[1] == '/')
    {
        cout << "Single Line Comment" << endl;
    }
    else if(str[0] == '/' && str[1] == '*' &&
            str[l-2] == '*' && str[l-1] == '/')
    {
        cout << "Multi Line Comment" << endl;
    }
    else
    {
        cout << "Not a Comment" << endl;
    }
}

// Task 4: Identifier Check
void identifierChecker(string str)
{
    bool valid = true;

    if(str.length() == 0)
    {
        cout << "Not Valid Identifier" << endl;
        return;
    }

    if(!((str[0] >= 65 && str[0] <= 90) ||
         (str[0] >= 97 && str[0] <= 122) ||
          str[0] == 95))
    {
        valid = false;
    }

    for(int i = 1; i < str.length(); i++)
    {
        if(!((str[i] >= 65 && str[i] <= 90) ||
             (str[i] >= 97 && str[i] <= 122) ||
             (str[i] >= 48 && str[i] <= 57) ||
              str[i] == 95))
        {
            valid = false;
            break;
        }
    }

    if(valid)
        cout << "Valid Identifier" << endl;
    else
        cout << "Not Valid Identifier" << endl;
}

// Task 5: Average of Array
void findAverage()
{
    int n;
    cout<<endl;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    int sum = 0;

    cout << "Enter elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    double average = (double)sum / n;

    cout << "Average = " << average << endl;
}

// Task 6: Minimum and Maximum
void findMinMax()
{
    int n;
    cout<<endl;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int minimum = arr[0];
    int maximum = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i] < minimum)
        {
            minimum = arr[i];
        }

        if(arr[i] > maximum)
        {
            maximum = arr[i];
        }
    }

    cout << "Minimum Value = " << minimum << endl;
    cout << "Maximum Value = " << maximum << endl;
}

// Task 7: Full Name Concatenation
void concatenateName()
{
    string firstName, lastName, fullName;
    cout<<endl;
    cout << "Enter First Name: ";
    cin >> firstName;

    cout << "Enter Last Name: ";
    cin >> lastName;

    fullName = firstName + " " + lastName;

    cout << "Full Name = " << fullName << endl;
}

int main()
{
    string input;

    // Task 1
    cout << "Enter value for Numeric Check: ";
    cin >> input;
    checkNumeric(input);

    // Task 2
    cout<<endl;
    cout << "Enter expression for Operator Check: ";
    cin >> input;
    operators(input);

    // Task 3
    cin.ignore();
    cout << "Enter comment: ";
    getline(cin, input);
    comment(input);

    // Task 4
    cin.ignore();
    cout<<endl;
    cout << "Enter identifier: ";
    getline(cin, input);
    identifierChecker(input);

    // Task 5
    findAverage();

    // Task 6
    findMinMax();

    // Task 7
    concatenateName(/*24-57947-2 */);

    return 0;
}
