#include <iostream>
#include <list>
#include <string>
#include <ctime>

using namespace std;

class todo
{
private:
    int id;
    string description;
    bool completed;

public:
    todo()
    {
        id = 0;
        description = " ";
        completed = false;
    }

    ~todo() = default;

    int getid()
    {
        return id;
    }

    string getdescription()
    {
        return description;
    }

    bool isCompleted()
    {
        return completed;
    }

    bool create(string new_description)
    {
        id = rand() % 100 + 1; // generate random id between 1 and 100
        description = new_description;
        return true;
    }
    void setCompleted(bool val)
    {
        completed = val;
    }
};

int main()
{

    char input_option;
    int input_id;
    string description;

    string version = "v0.1.0";

    list<todo> todoitems;
    list<todo>::iterator it;

    todoitems.clear();
    srand(time(NULL));

    while (1)
    {
        system("cls");
        cout << "You are using version " << version << endl;
        for (it = todoitems.begin(); it != todoitems.end(); it++)
        {
            string completed = it->isCompleted() ? "done" : "not done";
            cout << it->getid() << " | " << it->getdescription() << " | " << completed << endl;
        }

        if (todoitems.empty())
        {
            cout << "Add to your wishlist\n";
        }
        cout<<endl;
        cout<<endl;

        cout << "[a] add new todo \n";
        cout << "[b] mark done\n";
        cout << "[q] quit\n";

        cout << "choice: ";
        cin >> input_option;

        if (input_option == 'q')
        {
            cout << "Ram Ram !";
            break;
        }
        else if (input_option == 'b')
        {
            cout << "Enter id to marks it completed\n";
            cin >> input_id;
            for (it = todoitems.begin(); it != todoitems.end(); it++)
            {
                if (input_id == it->getid())
                {
                    it->setCompleted(true);
                    break;
                }
            }
        }
        else if (input_option == 'a')
        {
            cout << "enter the description ";
            cin.clear();
            cin.ignore();
            getline(cin, description);
            todo new_item;
            new_item.create(description);
            todoitems.push_back(new_item);
        }
    }

    return 0;
}