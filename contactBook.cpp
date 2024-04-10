#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Things to add: phone and email validator, search for someone by phone and email too,
//                  more contact info like address

struct Contact
{
    string name;
    string phone;
    string email;
};

void addContact(vector<Contact> &contacts)
{
    Contact newContact;
    cout << "Enter name: ";
    cin >> newContact.name;
    cout << "Enter phone: ";
    cin >> newContact.phone;
    cout << "Enter email: ";
    cin >> newContact.email;
    contacts.push_back(newContact);
    cout << "Contact added.\n";
}

void displayContacts(const vector<Contact> &contacts)
{
    for (const auto &contact : contacts)
    {
        cout << "Name: " << contact.name << ", Phone: "
            << contact.phone << ", Email: " << contact.email << endl;
    }
}

void searchContact(const vector<Contact> &contacts)
{
    string searchTerm;
    cout << "Enter a name to search: ";
    cin >> searchTerm;

    bool found = false;
    for (const auto &contact : contacts)
    {
        if (contact.name == searchTerm)
        {
            cout << "Name: " << contact.name << ", Phone: "
                << contact.phone << ", Email: " << contact.email << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Contact not found.\n";
    }
}

void deleteContact(vector<Contact> &contacts)
{
    string nameToDelete;
    cout << "Enter name of contact to delete: ";
    cin >> nameToDelete;

    auto it = remove_if(contacts.begin(), contacts.end(), [&](const Contact &contact)
                            { return contact.name == nameToDelete; });

    if (it != contacts.end())
    {
        contacts.erase(it, contacts.end());
        cout << "Contact deleted.\n";
    }
    else
    {
        cout << "Contact not found.\n";
    }

}

int main()
{
    vector<Contact> contacts;
    int choice;

    do
    {
        cout << "\n1. Add Contact\n"
            << "2. Display Contacts\n"
            << "3. Search Contact\n"
            << "4. Delete Contact\n"
            << "5. Exit\n"
            << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addContact(contacts);
                break;
            case 2:
                displayContacts(contacts);
                break;
            case 3:
                searchContact(contacts);
                break;
            case 4:
                deleteContact(contacts);
                break;
            case 5:
                break;
            default:
                cout << "Invalide choice.\n";
        }

    } while (choice != 5);
    

    return 0;
}