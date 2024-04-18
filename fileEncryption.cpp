#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// ideas from writer Why not try a substitution cipher? 
// Or perhaps a randomly generated key? Perhaps you can look at some form of login with a username and a password?
void encryptFile (const string &inputFilePath, const string outputFilePath, int key)
{
    ifstream inputFile(inputFilePath, ios::binary);
    ofstream outputFile(outputFilePath, ios::binary);

    char ch;
    while (inputFile.get(ch))
    {
        outputFile.put(ch + key);
    }

    inputFile.close();
    outputFile.close();
}

void decryptFile(const string &inputFilePath, const string outputFilePath, int key)
{
    ifstream inputFile(inputFilePath, ios::binary);
    ofstream outputFile(outputFilePath, ios::binary);

    char ch;
    while (inputFile.get(ch))
    {
        outputFile.put(ch - key);
    }

    inputFile.close();
    outputFile.close();
}

int main()
{
    string inputFilePath, outputFilePath;
    int choice, key;

    cout << "1. Encrypt File\n"
        << "2. Decrypt File\n"
        << "Enter your choice: ";
    cin >> choice;

    cout << "Enter key (integer): ";
    cin >> key;

    cout << "Enter input file path: ";
    cin >> inputFilePath;
    cout << "Enter output file path: ";
    cin >> outputFilePath;

    if (choice == 1)
    {
        encryptFile(inputFilePath, outputFilePath, key);
    }
    else if (choice == 2)
    {
        decryptFile(inputFilePath, outputFilePath, key);
    }
    else
    {
        cout << "Invalid choice.\n";
    }


    return 0;
}