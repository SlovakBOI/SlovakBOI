#include <iostream>
#include <map>
#include <cctype>
#include <string>
using namespace std;

int romanToArabic (const string& roman){

    map<char, int> romanMap{
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
    };
    int total = 0;
    int prevValue = 0;

    //iteracia mapy na konstrukciu dalsich arabskych cisel
    for (int i = roman.size() - 1; i >= 0; i--) {
        char currentChar = toupper(roman[i]); // premena pismen na velke (pre istotu)

        if (romanMap.find(currentChar) == romanMap.end()) {
            return -1;  // ak niekto da menej (ktovie ako)
        }
        int currentValue = romanMap[currentChar];

        if (currentValue < prevValue){
            total -= currentValue;
        } else {
            total += currentValue;
        }
        prevValue = currentValue;
    }

    return total;
}
int main() {
    string romanNumeral;
    cout << "enter numeral ";
    cin >> romanNumeral;

    int arabicNumber = romanToArabic(romanNumeral);
    if (arabicNumber == -1){
        cout << "invalid numeral" << endl;
    } else {
        cout << "arabic number: " << arabicNumber << endl;
    }
    return 0;
}
