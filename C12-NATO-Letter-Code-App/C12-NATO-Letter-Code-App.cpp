// C12-NATO-Letter-Code-App.cpp 

#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
// ----------------------------------------------------
struct NATO
{
    char    symbol;
    char    spelling[15];
    char    pronuntiation[20];
};
// -----------------------------------------------------

vector<NATO> makeDatabase();

// -----------------------------------------------------


int main()
{
    vector<NATO> vDB = makeDatabase();
    do
    {
        cout << "\nEnter a name [xxx to end]\n";
        string name;
        getline(cin, name);
        if (name == "xxx") break;

        for (int i = 0; i < name.length(); i++)
        {
            char c = toupper(name[i]);
            for (int j = 0; j < vDB.size(); j++)
            {
                if (c == vDB[j].symbol)
                {
                    cout << vDB[j].spelling << "\t" << vDB[j].pronuntiation << endl;
                    break;
                }
            }
        }
    } while (true);

}

vector<NATO> makeDatabase()
{
    vector<NATO> vDB;
    fstream natoFile("c:/temp/nato-letter-code.bin", ios::in | ios::binary);
    if (!natoFile)
    {
        cout << "ERROR - file not found\n";
        exit(1);
    }

    NATO n;
    while (!natoFile.eof())
    {
        natoFile.read((char*)(&n), sizeof(n));
        if (natoFile.fail()) break;
        vDB.push_back(n);
        cout << n.symbol << ", " << n.spelling << ",\t " << n.pronuntiation << endl;
    }
    natoFile.close();
    return vDB;
}
