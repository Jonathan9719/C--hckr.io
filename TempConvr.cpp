#include <iostream>

using namespace std;

double CelsiusToFahrenheit(double celsius)
{
    return (celsius * 9.0 / 5.0) + 32.0;
}

double FahrenheitToCelsius(double fahrenheit)
{
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

double CelsiusToKelvin(double celsius)
{
    return  celsius + 273.15;
}

double KelvinToCelsius(double kelvin)
{
    return kelvin - 273.15;
}

int main()
{
    int choice;
    double temperature, convertedTemperature;

    cout << "Temperature Converter\n"
        << "1. Celsius to Fahrenheit\n"
        << "2. Fahrenheit to Celsius\n"
        << "3. Celsius to Kelvin\n"
        << "4. Kelvin to Celsius\n"
        << "Enter your choice (1-4): ";
    cin >> choice;

    cout << "Enter the temperature: ";
    cin >> temperature;

    switch (choice)
    {
    case 1:
        convertedTemperature = CelsiusToFahrenheit(temperature);
        break;
    case 2:
        convertedTemperature = FahrenheitToCelsius(temperature);
        break;
    case 3:
        convertedTemperature = CelsiusToKelvin(temperature);
        break;
    case 4:
        convertedTemperature = KelvinToCelsius(temperature);
        break;
    default:
        cout << "Invalid Choice!\n";
        return 1;
    }

    cout << "Converted Temperature: " << convertedTemperature << endl;

    return 0;
}