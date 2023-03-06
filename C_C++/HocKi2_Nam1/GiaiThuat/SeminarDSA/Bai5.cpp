#include <map>
#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;
#define NUMBER_OF_BUCKETS 1999

int GetIntKey(string str)
{
    int sum = 0;
    for (int i = 0; i < str.length(); i++)
        sum += ((sum * 256) % NUMBER_OF_BUCKETS + (int)str[i]) % NUMBER_OF_BUCKETS;
    return sum;
}
void Input(map<string, string> &dictionary, vector<vector<string>> &table)
{
    string name_of_country;
    int number_of_edges;
    cout << "Nhap so canh cua do thi: ";
    cin >> number_of_edges;
    for (int i = 0; i < number_of_edges; i++)
    {
        cout << "Nhap ten quoc gia thu " << i + 1 << ": ";
        cin.ignore();
        getline(cin, name_of_country);
        dictionary.insert(name_of_country, name_of_country);
        int country1_index = ;
    }
}

int main()
{
    map<string, string> dictionary;

    return 0;
}