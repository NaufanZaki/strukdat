//
//  main.cpp
//  strukdat6
//
//  Created by zaki on 05/10/23.
//

#include <iostream>
using namespace std;

const int SIZE_ARR = 26;

struct HashTable
{
  string username, password;
} dataAkun[SIZE_ARR];

int hashFunction(string password)
{
    return static_cast<int>(password[0]); // Menggunakan nilai ASCII karakter pertama
}


void printAll()
{
  for (int i = 0; i < SIZE_ARR; i++)
  {
    cout << i << " [ ";
    
    // Convert and print username as ASCII
    for (char c : dataAkun[i].username)
    {
      cout << static_cast<int>(c) << " ";
    }
    
    cout << "- ";
    
    // Convert and print password as ASCII
    for (char c : dataAkun[i].password)
    {
      cout << static_cast<int>(c) << " ";
    }
    
    cout << "]" << endl;
  }
}


void menu()
{
  while (true)
  {
    int input_user;

    cout << endl;
    cout << "MENU" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. Exit" << endl << endl;

    cout << "Pilih: " << endl;
    cin >> input_user;
    cout << endl;

    if (input_user == 1)
    {
      string username, password;

      cout << "Masukkan Username: " << endl;
      cin >> username;
      cout << "Masukkan Password: " << endl;
      cin >> password;

      int index = hashFunction(password);

      if (dataAkun[index].username.empty() && dataAkun[index].password.empty())
      {
        dataAkun[index].username = username;
        dataAkun[index].password = password;
      }
      else
      {
        cout << "Akun sudah ada!" << endl;
      }
    }
    else if (input_user == 2)
    {
      cout << "Menu Login" << endl;
    }
    else if (input_user == 3)
    {
      printAll();
      break;
    }
    else
    {
      cout << "Invalid!" << endl;
    }
  }
}

int main()
{
  menu();
  return 0;
}
