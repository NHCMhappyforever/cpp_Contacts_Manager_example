// NHCM contacts 1.0
// © Copyright 2024 NHCM All Rights Reserved.
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct person
{
    char name[1024];
    char phonenumber[1024];
    char address[1024];
};
struct contacts
{
    struct person contacts[1000];
    int total;
};
struct contacts contacts1;
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
        system("pause");
        system("cls");
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
    cout << "确定?(Y/N)" << endl;
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
    system("cls");
    cout << R"( _   _  _   _ _____ ___  ___                  _             _       
| \ | || | | /  __ \|  \/  |                 | |           | |      
|  \| || |_| | /  \/| .  . |   ___ ___  _ __ | |_ __ _  ___| |_ ___ 
| . ` ||  _  | |    | |\/| |  / __/ _ \| '_ \| __/ _` |/ __| __/ __|
| |\  || | | | \__/\| |  | | | (_| (_) | | | | || (_| | (__| |_\__ \
\_| \_/\_| |_/\____/\_|  |_/  \___\___/|_| |_|\__\__,_|\___|\__|___/
Version 1.0
                                                                    
                                                                    )" << "\nWelcome for using~\n" << endl;
    system("pause");
    int select = 114514;
    while (select != 0)
    {
    START:
        data.read((char*)&contacts1, sizeof(contacts1));
        system("cls");
        int options1[] = { 1, 2, 3, 4, 5, 6, 0 };
        select = input(R"( _   _  _   _ _____ ___  ___                  _             _       
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

0 退出)", "错误的操作", options1);
        switch (select)
        {
        case 0:
            goto EXIT;
            break;
        case 1:
        {
            system("cls");
            cout << "输入名字" << endl;
            cin.ignore(1024, '\n');
            char name[1024];
            cin.getline(name,1024);
            cout << "输入电话号码" << endl;
            char phoneNumber[1024];
            cin.getline(phoneNumber,1024);
            cout << "输入地址" << endl;
            char address[1024];
            cin.getline(address,1024);
            if (contacts1.total == 1000)
            {
                cout << "无法再添加联系人，因为已经达到了上限1000" << endl;
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
                            system("cls");
                            cout << "你已经添加过该联系人:" << contacts1.contacts[i].name << "\n" << endl;
                            system("pause");
                            goto START;
                        }
                    }
                    fill(contacts1.contacts[contacts1.total + 1].name, name);
                    fill(contacts1.contacts[contacts1.total + 1].phonenumber, phoneNumber);
                    fill(contacts1.contacts[contacts1.total + 1].address, address);
                    contacts1.total++;
                    save();
                    system("cls");
                    cout << "添加成功:\n名字:" << contacts1.contacts[contacts1.total].name << "\n电话号码:" << contacts1.contacts[contacts1.total].phonenumber << "\n地址:" << contacts1.contacts[contacts1.total].address << "\n" << endl;
                    system("pause");
                }
            }
            break;
        }
        case 2:
        {
            if ((string)contacts1.contacts[1].name == "")
            {
                system("cls");
                cout << "暂无联系人\n" << endl;
                system("pause");
                goto START;
            }
            system("cls");
            cin.ignore(1024, '\n');
            cout << "输入名字" << endl;
            char name[1024];
            cin.getline(name,1024);
            bool found = false;
            for (int i = 1; i <= contacts1.total; i++)
            {
                if ((string)name == (string)contacts1.contacts[i].name)
                {
                    bool found = true;
                    system("cls");
                    int options2[] = { 1, 2, 3, 0 };
                    int select2 = input("名字:" + (string)contacts1.contacts[i].name + "\n" + "电话号码:" + (string)contacts1.contacts[i].phonenumber + "\n" + "地址:" + (string)contacts1.contacts[i].address + "\n\n" + "修改什么？\n1.名字\n2.电话号码\n3.地址\n0.退出\n输入操作", "错误的操作", options2);
                    switch (select2)
                    {
                    case 1:
                    {
                        cout << "输入新名字" << endl;
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
                            cout << "修改成功:\n名字:" << contacts1.contacts[i].name << "\n电话号码:" << contacts1.contacts[i].phonenumber << "\n地址:" << contacts1.contacts[i].address << "\n" << endl;
                            system("pause");
                            goto START;
                        }
                    }
                    case 2:
                    {
                        cout << "输入新电话号码" << endl;
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
                            cout << "修改成功:\n名字:" << contacts1.contacts[i].name << "\n电话号码:" << contacts1.contacts[i].phonenumber << "\n地址:" << contacts1.contacts[i].address << "\n" << endl;
                            system("pause");
                            goto START;
                        }
                    }
                    case 3:
                    {
                        cout << "输入新地址" << endl;
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
                            cout << "修改成功:\n名字:" << contacts1.contacts[i].name << "\n电话号码:" << contacts1.contacts[i].phonenumber << "\n地址:" << contacts1.contacts[i].address << "\n" << endl;
                            system("pause");
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
                    system("cls");
                    cout << "找不到联系人\"" << name << "\"\n" << endl;
                    system("pause");
                    goto START;
                }
            }
            break;
        }
        case 3:
        {
            if (contacts1.contacts[1].name == "")
            {
                system("cls");
                cout << "暂无联系人\n" << endl;
                system("pause");
                goto START;
            }
            system("cls");
            cout << "输入名字" << endl;
            cin.ignore(1024, '\n');
            char name[1024];
            cin.getline(name,1024);
            bool found = false;
            for (int i = 1; i <= contacts1.total; i++)
            {
                if ((string)name == (string)contacts1.contacts[i].name)
                {
                    bool found = true;
                    system("cls");
                    cout << "删除联系人:\"" << contacts1.contacts[i].name << "\"\n" << endl;
                    cout << "名字:" << contacts1.contacts[i].name << "\n电话号码:" << contacts1.contacts[i].phonenumber << "\n地址:" << contacts1.contacts[i].address << "\n" << endl;
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
                    system("cls");
                    cout << "找不到联系人\"" << name << "\"\n" << endl;
                    system("pause");
                    goto START;
                }
            }
            break;
        }
        case 4:
        {
            if (contacts1.contacts[1].name == "")
            {
                system("cls");
                cout << "暂无联系人\n" << endl;
                system("pause");
                goto START;
            }
            system("cls");
            cout << "输入名字" << endl;
            char name[1024];
            cin.ignore(1024, '\n');
            cin.getline(name,1024);
            bool found = false;
            for (int i = 1; i <= contacts1.total; i++)
            {
                if ((string)name == (string)contacts1.contacts[i].name)
                {
                    bool found = true;
                    system("cls");
                    cout << "名字:" << contacts1.contacts[i].name << "\n电话号码:" << contacts1.contacts[i].phonenumber << "\n地址:" << contacts1.contacts[i].address << "\n" << endl;
                    system("pause");
                    goto START;
                }
                else
                {
                    bool found = false;
                }
                if (i == contacts1.total || found == false)
                {
                    system("cls");
                    cout << "找不到联系人\"" << name << "\"\n" << endl;
                    system("pause");
                    goto START;
                }
            }
            break;
        }
        case 5:
        {
            system("cls");
            if (contacts1.total == 0)
            {
                cout << "通讯录是空的\n" << endl;
                system("pause");
                break;
            }
            for (int i = 1; i <= contacts1.total; i++)
            {
                string showList = std::to_string(i) + ". " + contacts1.contacts[i].name + "\n电话:" + contacts1.contacts[i].phonenumber + "\n地址:" + contacts1.contacts[i].address + "\n\n";
                cout << showList;
            }
            system("pause");
            break;
        }
        case 6:
        {
            system("cls");
            cout << "这会清空你的所有信息，你确定吗?\n" << endl;
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
        default:
            break;
        };
    }
EXIT:
    data.close();
    system("cls");
    cout << R"( _   _  _   _ _____ ___  ___                  _             _       
| \ | || | | /  __ \|  \/  |                 | |           | |      
|  \| || |_| | /  \/| .  . |   ___ ___  _ __ | |_ __ _  ___| |_ ___ 
| . ` ||  _  | |    | |\/| |  / __/ _ \| '_ \| __/ _` |/ __| __/ __|
| |\  || | | | \__/\| |  | | | (_| (_) | | | | || (_| | (__| |_\__ \
\_| \_/\_| |_/\____/\_|  |_/  \___\___/|_| |_|\__\__,_|\___|\__|___/
Version 1.0
                                                                    
                                                                    )" << endl;
    system("pause");
    system("cls");
    system("exit");
    return 0;
}