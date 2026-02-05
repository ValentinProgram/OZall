#include <iostream>
#include <string>
using namespace std;

string rubles(int n) {
    string units[] = { "", "один ", "два ", "три ", "четыре ", "пять ", "шесть ", "семь ", "восемь ", "девять " };
    string teens[] = { "десять ", "одиннадцать ", "двенадцать ", "тринадцать ", "четырнадцать ",
                      "пятнадцать ", "шестнадцать ", "семнадцать ", "восемнадцать ", "девятнадцать " };
    string tens[] = { "", "", "двадцать ", "тридцать ", "сорок ", "пятьдесят ",
                     "шестьдесят ", "семьдесят ", "восемьдесят ", "девяносто " };
    string hundreds[] = { "", "сто ", "двести ", "триста ", "четыреста ", "пятьсот ",
                         "шестьсот ", "семьсот ", "восемьсот ", "девятьсот " };

    if (n == 0) return "ноль ";
    string res = "";
    res += hundreds[n / 100];
    n %= 100;
    if (n >= 10 && n <= 19) res += teens[n - 10];
    else {
        res += tens[n / 10];
        res += units[n % 10];
    }
    return res;
}

string rub_form(int n) {
    n %= 100;
    if (n >= 11 && n <= 14) return "рублей";
    n %= 10;
    if (n == 1) return "рубль";
    if (n >= 2 && n <= 4) return "рубля";
    return "рублей";
}

string kop_form(int n) {
    n %= 100;
    if (n >= 11 && n <= 14) return "копеек";
    n %= 10;
    if (n == 1) return "копейка";
    if (n >= 2 && n <= 4) return "копейки";
    return "копеек";
}

int main() {
    setlocale(LC_ALL, "Russian");
    double sum;
    cin >> sum;

    int rub = static_cast<int>(sum);
    int kop = static_cast<int>((sum - rub) * 100 + 0.5);

    cout << rubles(rub) << rub_form(rub) << " " << rubles(kop) << kop_form(kop);
}