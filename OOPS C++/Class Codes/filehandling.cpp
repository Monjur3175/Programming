#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream my_file("Example.txt", ios::out); // ios::app
    if (!my_file)
    {
        cout << "Error:Unable to open the file" << endl;
        return 1;
    }
    my_file << "Line 1" << endl;
    my_file << "Line 2" << endl;
    my_file << "Line 3" << endl;
    my_file.close();
    string line;
    if (my_file)
    {
        my_file.open("Example.txt", ios::in);
        while (!my_file.eof())
        {
            getline(my_file, line);
            cout << line << endl;
        }
    }

    my_file.close();
}