#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int validCount;
int invalidCount;
int unspecifiedNumCount;

char isPrime(int n);
char isSphenic(int n);
char isPerfectSquare(int n);
char isPerfectNum(int n);
char isPalindrome(int n);
bool isPerfect(int n);
int convertToBinary(int n);
void displayHeader();
void displayInvalidNumbers(vector<int> &invalidNumbers);
void storeDataFromNumbersTextFileInVector(vector<int> &numbers);
void displayNumbersAndTheirConvertedVersions(vector<int> &numbers);
void displayFrequencyOfValidNumbers(vector<int> &numbers);
void displayFooter();
int getRangeValue(vector<int> &validNumbers, int range);
vector<int> getInvalidNumbers(vector<int> &numbers);
vector<int> getValidNumbers(vector<int> &numbers);
void beginHistogram(vector<int> &numbers);
string headers[7] = {"Number", "Prime", "Perfect-Square", "Perfect-Number", "Sphenic", "Binary-Equivalent"};

int main()
{
    vector<int> numbers;
    beginHistogram(numbers);

    return 0;
}
void beginHistogram(vector<int> &numbers)
{
    displayHeader();
    storeDataFromNumbersTextFileInVector(numbers);
    displayNumbersAndTheirConvertedVersions(numbers);
    displayInvalidNumbers(numbers);
    displayFrequencyOfValidNumbers(numbers);
    displayFooter();
    
}
void displayFooter(){
    cout<<"\nAmount of students picked valid numbers: "<<validCount<<endl;
    cout<<"Amount of students picked invalid numbers: "<<invalidCount<<endl;
    cout<<"Amount of students that didn't pick a number: "<<unspecifiedNumCount<<endl;
}
void displayFrequencyOfValidNumbers(vector<int> &numbers){
    int ROW = 11, COL = 50;
    vector<int> validNumbers = getValidNumbers(numbers);
    //set<int> validNumbersSet = set<int>(validNumbers.begin(), validNumbers.end());
    
    cout<<"\n\nFrequency of valid numbers:\nA * denotes a frequency of 5 numbers and a | denotes a frequency of 1 number\n"<<endl;
    // Do i really need two sets of for loops or can i put the logic from the first loop into the second loop?
	// Modify these two for loops
	for(int start = 0; start <= 1; start++){
        for(int col = 0; col < COL; col++){
            if(start == 0 && col <= 9){
                cout<<"Range";
                col += 10;
            }else if(start == 0 && (col > COL - 19 && col <= COL - 13)){
                cout<<"Histogram";
                col += 10;
            }else if(start == 1){
                cout<<"=";
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    int begin = 1, end = 10;
    for(int i = 0; i < ROW-1; i++){
        for(int j = 0; j < COL; j++){
            //cout<<"=";
            if(j >= 0 && j < 10){
                if(i == 0){
                    cout<<begin << " to " << end<< "  ";
                }else if (i >= 1 && i <= 8){
                    cout<<begin << " to " << end << " ";
                }else{
                    cout<<begin << " to " << end;
                }
                begin += 10;
                end += 10;
                j = j + 10;
            }else if(j >= 10 && j < COL - 20 - 1){
                cout<<" ";
            }else if(j >= COL - 10 && j < COL){
                int n = getRangeValue(validNumbers, i);
                while(n != 0){
                    if(n >= 5){
                        cout << "*";
                        n -= 5;
                    }else if(n <= 4){
                        cout << "|";
                        n -= 1;
                    }
                }
                j += 10;
            }
        }
        cout<<endl;
    }


}
int getRangeValue(vector<int> &validNumbers, int range){
    sort(validNumbers.begin(), validNumbers.end());
    int value = 0;
    switch(range){
        case 0:
            value = count_if(validNumbers.begin(), validNumbers.end(), [](int n){return n >= 1 && n <= 10;});
            break;
        case 1:
            value = count_if(validNumbers.begin(), validNumbers.end(), [](int n){return n >= 11 && n <= 20;});
            break;
        case 2:
            value = count_if(validNumbers.begin(), validNumbers.end(), [](int n){return n >= 21 && n <= 30;});
            break;
        case 3:
            value = count_if(validNumbers.begin(), validNumbers.end(), [](int n){return n >= 31 && n <= 40;});
            break;
        case 4:
            value = count_if(validNumbers.begin(), validNumbers.end(), [](int n){return n >= 41 && n <= 50;});
            break;
        case 5:
            value = count_if(validNumbers.begin(), validNumbers.end(), [](int n){return n >= 51 && n <= 60;});
            break;
        case 6:
            value = count_if(validNumbers.begin(), validNumbers.end(), [](int n){return n >= 61 && n <= 70;});
            break;
        case 7:
            value = count_if(validNumbers.begin(), validNumbers.end(), [](int n){return n >= 71 && n <= 80;});
            break;
        case 8:
            value = count_if(validNumbers.begin(), validNumbers.end(), [](int n){return n >= 81 && n <= 90;});
            break;
        case 9:
            value = count_if(validNumbers.begin(), validNumbers.end(), [](int n){return n >= 91 && n <= 100;});
            break;
        default:
            break;
    }
    return value;
}
void displayInvalidNumbers(vector<int> &invalidNumbers)
{
    vector<int> invalidNums = getInvalidNumbers(invalidNumbers);
    cout << "Invalid Numbers: \n";
    for (int i = 0; i < invalidNums.size(); i++)
    {
        if (invalidNums[i] < 0 || invalidNums[i] > 100)
        {
            if (i % 5 == 0)
            {
                cout << endl;
            }
            cout << invalidNums[i] << ", ";
        }
    }
    cout << endl;
}
vector<int> getInvalidNumbers(vector<int> &numbers)
{
    vector<int> invalidNumbers;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] < 0 || numbers[i] > 100)
        {
            invalidNumbers.push_back(numbers[i]);
        }
    }
    invalidCount = invalidNumbers.size();
    return invalidNumbers;
}
vector<int> getValidNumbers(vector<int> &numbers)
{
    vector<int> validNumbers;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] >= 1 && numbers[i] <= 100)
        {
            validNumbers.push_back(numbers[i]);
        }
    }
    return validNumbers;
}
void displayHeader()
{

    for (int i = 0; i < 7; i++)
    {
        cout << headers[i] << "\t";
    }
    cout << endl;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < headers[i].length(); j++)
        {
            cout << "=";
        }
        cout << "\t";
    }
    cout << endl;
}

char isPrime(int n)
{
    if (n == 1)
        return 'N';
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 'N';
    }
    return 'Y';
}
char isPerfectSquare(int n)
{
    int i = 1;
    while (i * i <= n)
    {
        if (i * i == n)
            return 'Y';
        i++;
    }
    return 'N';
}
char isPerfectNum(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
            sum += i;
    }
    if (sum == n)
        return 'Y';
    return 'N';
}
bool isPerfect(int n)
{
    if (isPrime(n) == 'N')
    {
        if (isPerfectNum(n) == 'Y')
            return true;
    }
    return false;
}
char isSphenic(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
            sum += i;
    }
    if (sum == n)
        return 'Y';
    return 'N';
}
char isPalindrome(int n)
{
    int temp = n;
    int rev = 0;
    while (temp != 0)
    {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }
    if (rev == n)
        return 'Y';
    return 'N';
}
int convertToBinary(int n)
{
    int binary = 0;
    int i = 1;
    while (n != 0)
    {
        binary += n % 2 * i;
        n /= 2;
        i *= 10;
    }
    return binary;
}
void storeDataFromNumbersTextFileInVector(vector<int> &numbers)
{
    ifstream file("numbers.txt");
    if (!file.is_open())
    {
        cout << "numbers.txt File not found" << endl;
        system("pause");
        return;
    }
    int n;
    while (file >> n)
    {
        if (n == -1)
        {
            continue;
        }
        numbers.push_back(n);
    }
}
void displayNumbersAndTheirConvertedVersions(vector<int> &numbers)
{
    int count = 0;
    int zeroCount = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        if(numbers[i] == 0){
            zeroCount++;
        }
        if ((numbers[i] >= 1) && (numbers[i] <= 100))
        {
            count++;
            cout << numbers[i] << "\t";
            cout << isPrime(numbers[i]) << "\t";
            cout << isPerfectSquare(numbers[i]) << "\t\t";
            cout << isPerfectNum(numbers[i]) << "\t\t";
            cout << isSphenic(numbers[i]) << "\t\t";
            cout << convertToBinary(numbers[i]);
            cout << endl;
        }
    }
    validCount = count;
    unspecifiedNumCount = zeroCount;
}