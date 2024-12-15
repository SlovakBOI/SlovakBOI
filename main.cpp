#include <iostream>
#include <map>
using namespace std;

string arabicToRoman(int num){
    if(num <= 0 || num > 3999){
        return "Invalid input";
    }
    map<int, string>  romanMap{  // mapovanie arabskych na rímske cisla
        {1000, "M"}, {900, "CM"}, {500, "D"},
        {400, "CD"}, {100, "C"}, {90, "XC"},
        {50, "L"}, {40, "XL"}, {10, "X"},
        {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
    string romanNumeral = "";
    //iteracia mapy na konstrukciu dalsich rimskych cisel
    for (auto it = romanMap.rbegin(); it != romanMap.rend(); ++it) {
        while (num >= it->first) {
            romanNumeral += it->second;
            num -= it->first;
        }
    }
    return romanNumeral;
}
int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    string romanNumeral = arabicToRoman(number);
    cout << "the roman numeral is: " << romanNumeral << endl;
    return 0;
}
