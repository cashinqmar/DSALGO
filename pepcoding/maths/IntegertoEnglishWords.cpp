#include <bits/stdc++.h>
using namespace std;

string number1(int n)
{
    switch (n)
    {
    case 1:
        return "One ";
        break;
    case 2:
        return "Two ";
        break;
    case 3:
        return "Three ";
        break;
    case 4:
        return "Four ";
        break;
    case 5:
        return "Five ";
        break;
    case 6:
        return "Six ";
        break;
    case 7:
        return "Seven ";
        break;
    case 8:
        return "Eight ";
        break;
    case 9:
        return "Nine ";
        break;
    }
    return "";
}

string number2(int n)
{
    if (n < 10)
        return number1(n);

    char ch = to_string(n)[0];
    if (n == 10)
    {
        return "Ten ";
    }
    if (n == 11)
    {
        return "Eleven ";
    }
    if (n == 12)
    {
        return "Twelve ";
    }
    if (n == 13)
    {
        return "Thirteen ";
    }
    if (n == 14)
    {
        return "Fourteen ";
    }
    if (n == 15)
    {
        return "Fifteen ";
    }
    if (n == 16)
    {
        return "Sixteen ";
    }
    if (n == 17)
    {
        return "Seventeen ";
    }
    if (n == 18)
    {
        return "Eighteen ";
    }
    if (n == 19)
    {
        return "Nineteen ";
    }

    switch (ch)
    {
    case '2':
        return "Twenty " + number1(n % 20);
        break;
    case '3':
        return "Thirty " + number1(n % 30);
        break;
    case '4':
        return "Forty " + number1(n % 40);
        break;
    case '5':
        return "Fifty " + number1(n % 50);
        break;
    case '6':
        return "Sixty " + number1(n % 60);
        break;
    case '7':
        return "Seventy " + number1(n % 70);
        break;
    case '8':
        return "Eighty " + number1(n % 80);
        break;
    case '9':
        return "Ninety " + number1(n % 90);
        break;
    }
    return "";
}

string number3(int n)
{
    if (n < 100)
        return number2(n);
    return number1(n / 100) + "Hundred " + number2(n % 100);
}

string numberToWords(int num)
{
    if (num == 0)
        return "Zero";

    string ans = "";

    int k = 0;
    while (num > 0)
    {
        string temp = number3(num % 1000);
        num = num / 1000;
        if (k == 0)
        {
            ans = temp;
        }
        if (k == 1)
        {
            if (temp != "")
                ans = temp + "Thousand " + ans;
        }
        if (k == 2)
        {
            if (temp != "")
                ans = temp + "Million " + ans;
        }
        if (k == 3)
        {
            if (temp != "")
                ans = temp + "Billion " + ans;
        }
        k++;
    }

    for (int i = ans.size() - 1; i >= 0; i--)
    {
        if (ans[i] == ' ')
            ans.pop_back();
        else
            return ans;
    }
    return ans;
}
int main()
{
    int n = 1234567891;
    cout << numberToWords(n);
}