/*
This program allow user to input maximum of 10 numbers and compute its sum, average, and population variance. Any numbers above 10 will be ignored
*/

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int val[10], sum = 0, count = 0, temp;
    double avg, diff[10], diffsqr[10], variance;
    string input;

    cout << "Computes statistics of a list of up to 10 numbers" << endl;
    
    //store input into a string line
    getline(cin, input);
    istringstream inputss(input);
    
    //read in numbers and the input size
    for (int i = 0; i < 10; i++) {
        if (inputss >> temp) {
            val[i] = temp;
            count++;
        }
        else {
            val[i] = 0;
        }
    }
    //check if size > 10
    if (inputss >> temp) {
        cout<< "Reached 10 values" << endl;
        count = 10;
    }

    //calc sum
    for (int i = 0; i < 10; i++) {
        sum += val[i];
    }

    //calc avg
    avg = (double)sum / count;
    cout << "The sum = " << sum << endl;
    cout << "The average = " << avg << endl;

    //calc difference each number to mean
    double sumdiff = 0;
    for (int i = 0; i < 10; i++) {
        diff[i] = val[i] - avg;
        diffsqr[i] = pow(diff[i], 2);
        sumdiff += diffsqr[i];
    }

    //calc var
    variance = sumdiff / count;
    cout << "The population variance = " << variance << endl;
    return 0;
}