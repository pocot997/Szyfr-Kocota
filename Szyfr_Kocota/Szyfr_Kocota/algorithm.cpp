#include "pch.h"
#include "algorithm.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace Runtime::InteropServices;
using namespace System::Diagnostics;

String^ Algorithm::file_read(System::Object^ sender, System::EventArgs^ e, int text_or_key)
{
    Stream^ my_stream;
    OpenFileDialog^ file_dialog = gcnew OpenFileDialog;
    file_dialog->Filter = "txt files (*txt)|*.txt";

    if (file_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
    {
        if ((my_stream = file_dialog->OpenFile()) != nullptr)
        {
            String^ file_name = file_dialog->InitialDirectory + file_dialog->FileName; //zczytanie nazwy pliku tekstowego
            String^ target = File::ReadAllText(file_name); //zczytanie zawartosci pliku tekstowego do zaladowanego tekstu
            const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(target)).ToPointer();
            string tmp = chars;
            Marshal::FreeHGlobal(IntPtr((void*)chars));
            if (text_or_key)
                fill_key_text(tmp);
            else
                fill_loaded_text(tmp);
            my_stream->Close();
            return target;
        }
    }
    return nullptr;
}

String^ Algorithm::convert_to_system_string_from_int(int* tab, int tab_length)
{
    string tmp ="";
    for (int i = 0; i < tab_length; i++)
    {
        tmp += to_string(tab[i]);
    }
    String^ full = gcnew String(tmp.c_str());
    return full;
}

String^ Algorithm::convert_to_system_string_from_char(char* tab, int tab_length)
{
    string tmp = "";
    for (int i = 0; i < tab_length; i++)
    {
        tmp.push_back(tab[i]);
    }
    String^ full = gcnew String(tmp.c_str());
    return full;
}

void Algorithm::fill_alphabet()
{
    char tmp = letter_A;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            alphabet[i][j] = tmp;
            if (tmp == 'Z')
                tmp = '`';
            if (tmp == 'z')
                tmp = '/';
            tmp++;
        }
    }
    alphabet[7-1][9-2] = ' ';
    alphabet[7-1][9-1] = '.';
}

void Algorithm::complete_key_xd()
{
    bool add = true;
    int j = 0;
    for (int i = 1; i < 10; i++)
    {
        add = true;
        j = 0;
        for (j; j < 9; j++)
        {
            if (key_x[j] == i)
            {
                add = false;
                break;
            }
        }
        if (add)
        {
            for (int k = 0; k < 9; k++)
            {
                if (key_x[k] == 0)
                {
                    key_x[k] = i;
                    break;
                }
            }
        }
    }
}

void Algorithm::insert_key_x(int tmp)
{
    int i = 0;
    bool good = true;
    for (i; i < 9; i++)
    {
        if (key_x[i] == tmp)
        {
            good = false;
            break;
        }
        if (key_x[i] == 0)
            break;
    }
    if (good)
    {
        key_x[i] = tmp;
    }
}

void Algorithm::fill_key_x()
{
    char xd0 = key_text[0];
    char xd1= key_text[1];
    char xd2 = key_text[2];
    for (int i = 0; i < 9; i++) //wype³nienei tablicy spacjami
        key_x[i] = 0;
    int tmp;
    for (int j = 0; j < key_length; j++)
    {
        tmp = key_text[j] / 10; //wyodrêbnienei czêœci dziesiêtnej kodu ascii znaku
        if (tmp > 9)
            tmp = tmp / 10;
        if (tmp != 0)
            insert_key_x(tmp);
        tmp = key_text[j] % 10; //wyodrêbnienei czêœci jednoœci kodu ascii znaku
        if (tmp != 0)
            insert_key_x(tmp);
        if (key_text[8] != 0) //jeœli ostatni znak nie jest zerem to koniec
            break;
    }
    complete_key_xd();
}

void Algorithm::fill_key_y()
{
    int j = 0;
    for (int i = 0; i < 9; i++)
    {
        if (key_x[i] <= 7) //kopiowanie kolejnoœci z klucza x je¿eli wartosci s¹ nie wiêksze ni¿ 7
        {
            key_y[j] = key_x[i];
            j++;
        }
    }
}

void Algorithm::shuffle_alphabet()
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            shuffled_alphabet[i][j] = alphabet[key_y[i] - 1][key_x[j] - 1];
        }
    }
    if (encrypting)
        solution_text_int = new int[loaded_length];
    else
        solution_text_char = new char[loaded_length / 2];
}

int Algorithm::find_char(char c)
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (shuffled_alphabet[i][j] == c)
            {
                return (i + 1) * 10 + (j + 1);
            }
        }
    }
    return -1 * c;
}

void Algorithm::encrypt(Object^ my_tuple)
{
    Tuple<int>^ index = (Tuple<int>^) my_tuple;
    char tmp = loaded_text[index->Item1];
    solution_text_int[index->Item1] = find_char(tmp);
}

void Algorithm::decrypt(int index, int where_decode)
{
    int y = (loaded_text[index]-'0');
    int x = (loaded_text[index+1]-'0');
    solution_text_char[where_decode] = shuffled_alphabet[y-1][x-1];
}

void Algorithm::decrypt_negative(int index, int where_decode)
{
    int y = (loaded_text[index + 1] - '0');
    int x = (loaded_text[index + 2] - '0');
    solution_text_char[where_decode] = (y * 10) + x;
}

void Algorithm::delete_additional(int where_decode)
{
    int how_many_allocated = loaded_length / 2;
    for (int i = where_decode; i < how_many_allocated; i++)
        solution_text_char[i] = '\0';
}

int Algorithm::get_loaded_length()
{
    return loaded_length;
}

int Algorithm::get_solution_int(int i)
{
    return solution_text_int[i];
}

int* Algorithm::get_solution_text_int()
{
    return solution_text_int;
}

char* Algorithm::get_solution_text_char()
{
    return solution_text_char;
}

char Algorithm::get_loaded_char(int i)
{
    return loaded_text[i];
}

int Algorithm::get_key_int(int i)
{
    return key_text[i];
}

void Algorithm::delete_everything()
{
    for (int i = 0; i < 9; i++)
    {
        delete[] alphabet[i];
        delete[] shuffled_alphabet[i];
    }
    delete[] alphabet;
    delete[] shuffled_alphabet;
    delete[] key_x;
    delete[] key_y;
    delete[] loaded_text;
    delete[] key_text;
    delete[] solution_text_int;
}

void Algorithm::set_encrypting(bool set)
{
    encrypting = set;
}

bool Algorithm::get_encrypting()
{
	return encrypting;
}

Algorithm::Algorithm()
{
    alphabet = new char* [9];
    shuffled_alphabet = new char* [9];
    for (int i = 0; i < 9; i++)
    {
        alphabet[i] = new char[7];
        shuffled_alphabet[i] = new char[7];
    }
    key_x = new int[9];
    key_y = new int[7];
    loaded_text = nullptr;
    key_text = nullptr;
    solution_text_int = nullptr;
    solution_text_char = nullptr;
}

void Algorithm::fill_loaded_text(string tmp)
{
    loaded_length = tmp.length();
    loaded_text = new char[loaded_length+1];
    strcpy(loaded_text, tmp.c_str());
}

void Algorithm::fill_key_text(string tmp)
{
    this->key_length = tmp.length();
    key_text = new char[key_length + 1];
    strcpy(key_text, tmp.c_str());
}
