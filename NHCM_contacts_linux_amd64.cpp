// NHCM contacts 1.2
// © Copyright 2024 NHCM All Rights Reserved.
#include<iostream>
#include<string>
#include<map>
#include<fstream>
#include<limits>
using namespace std;
struct person
{
    char name[1024];
    char phonenumber[1024];
    char address[1024];
};
struct contacts
{
    int language;
    struct person contacts[1000];
    int total;
};
struct contacts contacts1;
string show(int lang, string para)
{
    map<string, string> enus = { {"mainMenu", R"( _   _  _   _ _____ ___  ___                  _             _       
| \ | || | | /  __ \|  \/  |                 | |           | |      
|  \| || |_| | /  \/| .  . |   ___ ___  _ __ | |_ __ _  ___| |_ ___ 
| . ` ||  _  | |    | |\/| |  / __/ _ \| '_ \| __/ _` |/ __| __/ __|
| |\  || | | | \__/\| |  | | | (_| (_) | | | | || (_| | (__| |_\__ \
\_| \_/\_| |_/\____/\_|  |_/  \___\___/|_| |_|\__\__,_|\___|\__|___/
                                                                    
                                                                   
1 Add contact
2 Modify contact
3 Delete contact
4 Search contact
5 Show contacts
6 Clear contacts
7 Set language

0 Quit)"}, { "continue", "continue?(Y/N)" }, { "wrongOperation", "Wrong operation" }, { "enterName", "Enter the name" }, { "enterPhoneNumber", "Enter the phone number" }, { "enterAddress", "Enter the address" }, { "reachMax", "You cannot add any more contacts. Because the total of contacts have been reached the maximum(1000)" }, { "added", "You have already added this contact:" }, { "addedSuccessfully", "Added successfully:" }, { "noContacts", "No contacts now\n" }, { "name", "\nName:" }, { "phoneNumber", "\nPhone number:" }, { "address", "\nAddress:" }, { "modify", "Modify what?\n\n1.Name\n2.Phone number\n3.Address\n\n0.Quit" }, { "enterNewName", "Enter the new name" }, { "enterNewPhoneNumber", "Enter the new phone number" }, { "enterNewAddress", "Enter the new address" }, { "modifySuccessfully", "Modify successfully:" }, { "notFoundNoQuote", "Could not find contact" }, { "quote", "\"" }, { "deleteContactsNoQuote", "Delete contact:" }, { "noNewLineName", "Name:" }, { "clear", "This operation will clear all your contacts information. Are you SURE?\n" }, { "language", "Choose a language:\n\n1 English(US)\n2 简体中文\n\n0 Quit" } };
    map<string, string> zhcn = { {"mainMenu", R"( _   _  _   _ _____ ___  ___                  _             _       
| \ | || | | /  __ \|  \/  |                 | |           | |      
|  \| || |_| | /  \/| .  . |   ___ ___  _ __ | |_ __ _  ___| |_ ___ 
| . ` ||  _  | |    | |\/| |  / __/ _ \| '_ \| __/ _` |/ __| __/ __|
| |\  || | | | \__/\| |  | | | (_| (_) | | | | || (_| | (__| |_\__ \
\_| \_/\_| |_/\____/\_|  |_/  \___\___/|_| |_|\__\__,_|\___|\__|___/
                                                                    
                                                                   
1 添加联系人
2 修改联系人
3 删除联系人
4 查找联系人
5 展示联系人
6 清空通讯录
7 设置语言

0 退出)"}, { "continue", "确定?(Y/N)" }, { "wrongOperation", "错误的操作" }, { "enterName", "输入名字" }, { "enterPhoneNumber", "输入电话号码" }, { "enterAddress", "输入地址" }, { "reachMax", "无法再添加联系人，因为已经达到了上限(1000)" }, { "added", "你已经添加过该联系人:" }, { "addedSuccessfully", "添加成功:" }, { "noContacts", "暂无联系人\n" }, { "name", "\n名字:" }, { "phoneNumber", "\n电话号码:" }, { "address", "\n地址:" }, { "modify", "修改什么？\n\n1.名字\n2.电话号码\n3.地址\n\n0.退出" }, { "enterNewName", "输入新名字" }, { "enterNewPhoneNumber", "输入新电话号码" }, { "enterNewAddress", "输入新地址" }, { "modifySuccessfully", "修改成功:" }, { "notFoundNoQuote", "找不到联系人" }, { "quote", "\"" }, { "deleteContactsNoQuote", "删除联系人:" }, { "noNewLineName", "名字:" }, { "clear", "这会清空你的所有信息，你确定吗?\n" }, { "language", "选择语言:\n\n1 English(US)\n2 简体中文\n\n0 退出" } };
    string out;
    if (lang == 0)
    {
        out = enus[para];
    }
    else if (lang == 1)
    {
        out = zhcn[para];
    }
    else
    {
        out = enus[para];
    }
    return out;
}
void pauset() 
{
    if(contacts1.language == 1)
    {
        cin.clear();
        system("echo 请按回车键以继续...; read dummy;");
    }
    else
    {
        cin.clear();
        system("echo Press enter to continue...; read dummy;");
    }
}
void save()
{
    ofstream write;
    write.open("contacts.dat", ios::binary | ios::out);
    write.write((const char*)&contacts1, sizeof(contacts1));
    write.close();
}
void fill(char one[1024], char two[1024])
{
    for (int i = 0; i <= 1024; i++)
    {
        one[i] = two[i];
    }
}
int input(string prompt, string error, int options[10])
{
    cout << prompt << endl;
    int select;
    while (!(cin >> select))
    {
        ERROR:
        cin.clear();
        while (cin.get() != '\n')
            continue;
        cout << error << endl;
        pauset();
        system("clear");
        cout << prompt << endl;
    }
    int i = 0;
    for (i; i <= 10; i++)
    {
        bool selected = false;
        if (select == options[i])
        {
            goto END;
        }
        else
        {
            bool selected = false;
        }
        if (i == 10)
        {
            if (selected == false)
            {
                goto ERROR;
            }
        }
    }
    END:
    return select;
}
bool verify()
{
    cout << show(contacts1.language, "continue") << endl;
    string temp;
    cin >> temp;
    if (temp == "y" || temp == "Y")
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    ifstream data;
    data.open("contacts.dat", ios::binary | ios::in);
    if (data.is_open() == false)
    {
        ofstream newData;
        newData.open("contacts.dat", ios::binary | ios::out);
        newData.write((const char*)&contacts1, sizeof(contacts1));
        newData.close();
    }
    data.read((char*)&contacts1, sizeof(contacts1));
    data.close();
    system("clear");
    cout << R"( _   _  _   _ _____ ___  ___                  _             _       
| \ | || | | /  __ \|  \/  |                 | |           | |      
|  \| || |_| | /  \/| .  . |   ___ ___  _ __ | |_ __ _  ___| |_ ___ 
| . ` ||  _  | |    | |\/| |  / __/ _ \| '_ \| __/ _` |/ __| __/ __|
| |\  || | | | \__/\| |  | | | (_| (_) | | | | || (_| | (__| |_\__ \
\_| \_/\_| |_/\____/\_|  |_/  \___\___/|_| |_|\__\__,_|\___|\__|___/
Version 1.2
                                                                    
                                                                    )" << "\nWelcome for using~\n" << endl;
    pauset();
    int select = 114514;
    while (select != 0)
    {
    START:
        ifstream data;
        data.open("contacts.dat", ios::binary | ios::in);
        data.read((char*)&contacts1, sizeof(contacts1));
        data.close();
        system("clear");
        int options1[] = { 1, 2, 3, 4, 5, 6, 7, 0 };
        select = input(show(contacts1.language, "mainMenu"), show(contacts1.language, "wrongOperation"), options1);
        switch (select)
        {
        case 0:
            goto EXIT;
            break;
        case 1:
        {
            system("clear");
            cout << show(contacts1.language, "enterName") << endl;
            cin.ignore(1024, '\n');
            char name[1024];
            cin.getline(name,1024);
            cout << show(contacts1.language, "enterPhoneNumber") << endl;
            char phoneNumber[1024];
            cin.getline(phoneNumber,1024);
            cout << show(contacts1.language, "enterAddress") << endl;
            char address[1024];
            cin.getline(address,1024);
            ifstream data;
            data.open("contacts.dat", ios::binary | ios::in);
            data.read((char*)&contacts1, sizeof(contacts1));
            data.close();
            if (contacts1.total == 1000)
            {
                cout << show(contacts1.language, "reachMax") << endl;
            }
            else
            {
                if (verify() == false)
                {
                    break;
                }
                else
                {
                    for (int i = 1; i <= contacts1.total; i++)
                    {
                        if ((string)name == (string)contacts1.contacts[i].name)
                        {
                            system("clear");
                            cout << show(contacts1.language, "added") << contacts1.contacts[i].name << "\n" << endl;
                            pauset();
                            goto START;
                        }
                    }
                    fill(contacts1.contacts[contacts1.total + 1].name, name);
                    fill(contacts1.contacts[contacts1.total + 1].phonenumber, phoneNumber);
                    fill(contacts1.contacts[contacts1.total + 1].address, address);
                    contacts1.total++;
                    save();
                    system("clear");
                    cout << show(contacts1.language, "addedSuccessfully") << show(contacts1.language, "name") << contacts1.contacts[contacts1.total].name << show(contacts1.language, "phoneNumber") << contacts1.contacts[contacts1.total].phonenumber << show(contacts1.language, "address") << contacts1.contacts[contacts1.total].address << "\n" << endl;
                    pauset();
                }
            }
            break;
        }
        case 2:
        {
            ifstream data;
            data.open("contacts.dat", ios::binary | ios::in);
            data.read((char*)&contacts1, sizeof(contacts1));
            data.close();
            if ((string)contacts1.contacts[1].name == "")
            {
                system("clear");
                cout << show(contacts1.language, "noContacts") << endl;
                pauset();
                goto START;
            }
            system("clear");
            cin.ignore(1024, '\n');
            cout << show(contacts1.language, "enterName") << endl;
            char name[1024];
            cin.getline(name,1024);
            bool found = false;
            for (int i = 1; i <= contacts1.total; i++)
            {
                if ((string)name == (string)contacts1.contacts[i].name)
                {
                    bool found = true;
                    system("clear");
                    int options2[] = { 1, 2, 3, 0 };
                    int select2 = input(show(contacts1.language, "noNewLineName") + (string)contacts1.contacts[i].name + show(contacts1.language, "phoneNumber") + (string)contacts1.contacts[i].phonenumber + show(contacts1.language, "address") + (string)contacts1.contacts[i].address + "\n\n" + show(contacts1.language, "modify"), show(contacts1.language, "wrongOperation"), options2);
                    switch (select2)
                    {
                    case 1:
                    {
                        cout << show(contacts1.language, "enterNewName") << endl;
                        cin.ignore(1024, '\n');
                        char newname[1024] = {};
                        cin.getline(newname,1024);
                        if (verify() == false)
                        {
                            goto START;
                        }
                        else
                        {
                            fill(contacts1.contacts[i].name, newname);
                            save();
                            cout << show(contacts1.language, "modifySuccessfully") << show(contacts1.language, "name") << contacts1.contacts[i].name << show(contacts1.language, "phoneNumber") << contacts1.contacts[i].phonenumber << show(contacts1.language, "address") << contacts1.contacts[i].address << "\n" << endl;
                            pauset();
                            goto START;
                        }
                    }
                    case 2:
                    {
                        cout << show(contacts1.language, "enterNewPhoneNumber") << endl;
                        cin.ignore(1024, '\n');
                        char newnumber[1024] = {};
                        cin.getline(newnumber,1024);
                        if (verify() == false)
                        {
                            goto START;
                        }
                        else
                        {
                            fill(contacts1.contacts[i].name, newnumber);
                            save();
                            cout << show(contacts1.language, "modifySuccessfully") << show(contacts1.language, "name") << contacts1.contacts[i].name << show(contacts1.language, "phoneNumber") << contacts1.contacts[i].phonenumber << show(contacts1.language, "adddress") << contacts1.contacts[i].address << "\n" << endl;
                            pauset();
                            goto START;
                        }
                    }
                    case 3:
                    {
                        cout << show(contacts1.language, "enterNewAddress") << endl;
                        cin.ignore(1024, '\n');
                        char newaddress[1024] = {};
                        cin.getline(newaddress,1024);
                        if (verify() == false)
                        {
                            goto START;
                        }
                        else
                        {
                            fill(contacts1.contacts[i].name, newaddress);
                            save();
                            cout << show(contacts1.language, "modifySuccessfully") << show(contacts1.language, "name") << contacts1.contacts[i].name << show(contacts1.language, "phoneNumber") << contacts1.contacts[i].phonenumber << show(contacts1.language, "adddress") << contacts1.contacts[i].address << "\n" << endl;
                            pauset();
                            goto START;
                        }
                    }
                    case 0:
                        goto START;
                    default:
                        goto START;
                    };
                }
                else
                {
                    bool found = false;
                }
                if (i == contacts1.total || found == false)
                {
                    system("clear");
                    cout << show(contacts1.language, "notFoundNoQuote") << "\"" << name << "\"\n" << endl;
                    pauset();
                    goto START;
                }
            }
            break;
        }
        case 3:
        {
            ifstream data;
            data.open("contacts.dat", ios::binary | ios::in);
            data.read((char*)&contacts1, sizeof(contacts1));
            data.close();
            if (contacts1.contacts[1].name == "")
            {
                system("clear");
                cout << show(contacts1.language, "noContacts") << endl;
                pauset();
                goto START;
            }
            system("clear");
            cout << show(contacts1.language, "enterName") << endl;
            cin.ignore(1024, '\n');
            char name[1024];
            cin.getline(name,1024);
            bool found = false;
            for (int i = 1; i <= contacts1.total; i++)
            {
                if ((string)name == (string)contacts1.contacts[i].name)
                {
                    bool found = true;
                    system("clear");
                    cout << show(contacts1.language, "deleteContactsNoQuote") << "\"" << contacts1.contacts[i].name << "\"\n" << endl;
                    cout << show(contacts1.language, "noNewLineName") << contacts1.contacts[i].name << show(contacts1.language, "phoneNumber") << contacts1.contacts[i].phonenumber << show(contacts1.language, "address") << contacts1.contacts[i].address << "\n" << endl;
                    if (verify() == false)
                    {
                        goto START;
                    }
                    else
                    {
                        contacts1.contacts[i] = { "", "", "" };
                        contacts1.total--;
                        save();
                        goto START;
                    }
                }
                else
                {
                    bool found = false;
                }
                if (i == contacts1.total || found == false)
                {
                    system("clear");
                    cout << show(contacts1.language, "notFoundNoQuote") << "\"" << name << "\"\n" << endl;
                    pauset();
                    goto START;
                }
            }
            break;
        }
        case 4:
        {
            ifstream data;
            data.open("contacts.dat", ios::binary | ios::in);
            data.read((char*)&contacts1, sizeof(contacts1));
            data.close();
            if (contacts1.contacts[1].name == "")
            {
                system("clear");
                cout << show(contacts1.language, "noContacts") << endl;
                pauset();
                goto START;
            }
            system("clear");
            cout << show(contacts1.language, "enterName") << endl;
            char name[1024];
            cin.ignore(1024, '\n');
            cin.getline(name,1024);
            bool found = false;
            for (int i = 1; i <= contacts1.total; i++)
            {
                if ((string)name == (string)contacts1.contacts[i].name)
                {
                    bool found = true;
                    system("clear");
                    cout << show(contacts1.language, "noNewLineName") << contacts1.contacts[i].name << show(contacts1.language, "phoneNumber") << contacts1.contacts[i].phonenumber << show(contacts1.language, "address") << contacts1.contacts[i].address << "\n" << endl;
                    pauset();
                    goto START;
                }
                else
                {
                    bool found = false;
                }
                if (i == contacts1.total || found == false)
                {
                    system("clear");
                    cout << show(contacts1.language, "notFoundNoQuote") << "\"" << name << "\"\n" << endl;
                    pauset();
                    goto START;
                }
            }
            break;
        }
        case 5:
        {
            ifstream data;
            data.open("contacts.dat", ios::binary | ios::in);
            data.read((char*)&contacts1, sizeof(contacts1));
            data.close();
            system("clear");
            if (contacts1.total == 0)
            {
                cout << show(contacts1.language, "noContacts") << endl;
                pauset();
                break;
            }
            for (int i = 1; i <= contacts1.total; i++)
            {
                string showList = std::to_string(i) + ". " + contacts1.contacts[i].name + show(contacts1.language, "phoneNumber") + contacts1.contacts[i].phonenumber + show(contacts1.language, "address") + contacts1.contacts[i].address + "\n\n";
                cout << showList;
            }
            pauset();
            break;
        }
        case 6:
        {
            ifstream data;
            data.open("contacts.dat", ios::binary | ios::in);
            data.read((char*)&contacts1, sizeof(contacts1));
            data.close();
            system("clear");
            cout << show(contacts1.language, "clear") << endl;
            if (verify() == false)
            {
                goto START;
            }
            else
            {
                for (int i = 1; i <= contacts1.total; i++)
                {
                    contacts1.contacts[i] = { "", "", "" };
                    contacts1.total--;
                    save();
                }
            }
            break;
        }
        case 7:
        {
            system("clear");
            int options[] = { 1, 2, 0 };
            select = input(show(contacts1.language, "language"), show(contacts1.language, "wrongOperation"), options);
            if (select == 1)
            {
                contacts1.language = 0;
                save();
            }
            else if (select == 2)
            {
                contacts1.language = 1;
                save();
            }
            else
            {
                goto START;
            }
        }
        default:
            break;
        };
    }
    EXIT:
    system("clear");
    cout << R"( _   _  _   _ _____ ___  ___                  _             _       
| \ | || | | /  __ \|  \/  |                 | |           | |      
|  \| || |_| | /  \/| .  . |   ___ ___  _ __ | |_ __ _  ___| |_ ___ 
| . ` ||  _  | |    | |\/| |  / __/ _ \| '_ \| __/ _` |/ __| __/ __|
| |\  || | | | \__/\| |  | | | (_| (_) | | | | || (_| | (__| |_\__ \
\_| \_/\_| |_/\____/\_|  |_/  \___\___/|_| |_|\__\__,_|\___|\__|___/
Version 1.2
                                                                    
                                                                    )" << endl;
    pauset();
    system("clear");
    system("exit");
    return 0;
}
