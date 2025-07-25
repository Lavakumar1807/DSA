#include <iostream>
#include <cmath>
using namespace std;

bool isArmstrong(int number) {
    int sum = 0;
    int digits = 0;
    
    int temp = number;

    // Count number of digits
    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    temp = number;
    while (temp > 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    return sum == number;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (isArmstrong(number)){
        cout << number << " is an Armstrong number.\n";
    }
    else{
        cout << number << " is not an Armstrong number.\n";
    }
    return 0;
}

/*
   A number is called an Armstrong number if the sum of its digits raised to the power of the number of digits equals the number itself.
   153 = 1³ + 5³ + 3³ = 153
*/