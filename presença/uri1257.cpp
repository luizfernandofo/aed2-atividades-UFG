#include<iostream>
#include<string>

using namespace std;

int main(void)
{
    int n; // casos de teste
    int l; // quantidade de linhas do teste
    int hash; // hash calculado
    string str;

    cin >> n;

    while(n--)
    {
        cin >> l;
        hash = 0;
        for(int L = 0; L < l; L++)
        {
            cin >> str;
            for(int i = 0; i < str.size(); i++)
            {
                hash += ((int) str[i] - 65) + L + i;
            }
        }

        cout << hash << endl;
        
    }

    return 0;
}
