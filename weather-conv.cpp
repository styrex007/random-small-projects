#include<iostream>
#include<string>
using namespace std;
int main(){
    // Temperature Conversion Program
    // This program converts the temperature between Celsius, Fahrenheit, and Kelvin.
string unit;
float temperature;
    cout << "Enter the temperature: ";
    cin >> temperature;
    cout << "Enter the unit (Celsius, Fahrenheit, Kelvin): ";
    cin >> unit;
if (unit == "Celsius" || unit == "Fahrenheit" || unit == "Kelvin") {
    if (unit == "Celsius") {
        cout << "Temperature in Fahrenheit: " << (temperature * 9/5) + 32 << endl;
        cout << "Temperature in Kelvin: " << temperature + 273.15 << endl;
    }
    if (unit == "Fahrenheit") {
        cout << "Temperature in Celsius: " << (temperature - 32) * 5/9 << endl;
        cout << "Temperature in Kelvin: " << (temperature - 32) * 5/9 + 273.15 << endl;
    }
    if (unit == "Kelvin") {
        cout << "Temperature in Celsius: " << temperature - 273.15 << endl;
        cout << "Temperature in Fahrenheit: " << (temperature - 273.15) * 9/5 + 32 << endl;
    }
}
    return 0;
}
