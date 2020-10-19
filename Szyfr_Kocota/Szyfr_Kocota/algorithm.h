#pragma once
#include <string>
#include <direct.h>

using namespace std;
using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#define alphabet_width 9;
#define alphabet_height 7;
#define letter_A 'A';
#define letter_Z 'Z';
#define letter_z 'z';
#define number_0 '0';

public ref class Algorithm
{
private:
	char* loaded_text;
	int loaded_length;
	char* key_text;
	int key_length;
	int* solution_text_int;
	char* solution_text_char;
	char** alphabet;
	char** shuffled_alphabet;
	int* key_x;
	int* key_y;
	bool encrypting; // true - encrypt; false - decrypt
public:
	Algorithm(); //konstruktor inicjuj¹cy zmienne
	void fill_loaded_text(string tmp);
	void fill_key_text(string tmp);
	String^ file_read(System::Object^ sender, System::EventArgs^ e, int text_or_key); //funkcja zczytuje z pliku key_or_text=0->loaded_textt/=1->key_text
	String^ convert_to_system_string_from_int(int* tab, int tab_length); //funkcja konwertuje int* na System::String^
	String^ convert_to_system_string_from_char(char* tab, int tab_length); //funkcja konwertuje char* na System::String^
	void fill_alphabet(); //funkcja uzupe³nia tablicê z alfabetem
	void complete_key_xd(); //funkcja dope³nia klucz xcyframi, które jescze nie wyst¹pi³y
	void insert_key_x(int tmp); //funckja wpisuje podana wartoœc do klucza x
	void fill_key_x(); //funkcja usupe³nia tablice z kluczem dla osi x
	void fill_key_y(); //funkcja usupe³nia tablice z kluczem dla osi y na podstawie klucza x
	void shuffle_alphabet(); //funckja tworzy now¹ wymieszan¹ talbice z alfabetem
	int find_char(char c); //funkcja wyszukuje w alfabecie wskazany znak i zwraca jego pozycjê jako 10*y+x
	void encrypt(int index); //funkcja koduje znak o zadanym indeksie
	void decrypt(int index, int where_decode); //funkcja odkodowywuje znaki o zadanym indeksie
	void decrypt_negative(int index, int where_decode); //funkcja odkodowywuje znaki specjalne (kodowane ujemnie)
	void delete_additional(int where_decode); //funkcja zwalnia pamiêc zaalokowan¹ z ewentualnym naddatkiem
	int get_loaded_length(); //funkcja zwraca loaded_length
	int get_solution_int(int i); //funkcja zwraca int z solution_text_int o wskazanym indeksie
	int* get_solution_text_int(); //funkcja zwraca wzkaŸnik na solution_text_int
	char* get_solution_text_char(); //funkcja zwraca wzkaŸnik na solution_text_int
	char get_loaded_char(int i); //funkcja zwraca char z loaded_text o wskazanym indeksie
	int get_key_int(int i); //funkcja zwraca int z key_text o wskazanym indeksie
	void delete_everything(); //funkcja zwalna ca³¹ zaalokowan¹ pamiêæ
	void set_encrypting(bool set); //funkcja ustawia encrypting na podan¹ zmienn¹
	bool get_encrypting(); //funkcja zwraca wartoœæ miennej encrypting
};






//String^ file_read(System::Object^ sender, System::EventArgs^ e)
//{
//	Stream^ my_stream;
//	OpenFileDialog^ file_dialog = gcnew OpenFileDialog;
//	file_dialog->Filter = "txt files (*txt)|*.txt";
//
//	if (file_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
//	{
//		if ((my_stream = file_dialog->OpenFile()) != nullptr)
//		{
//			String^ file_name = file_dialog->InitialDirectory + file_dialog->FileName; //zczytanie nazwy pliku tekstowego
//			String^ target = File::ReadAllText(file_name); //zczytanie zawartosci pliku tekstowego do zaladowanego tekstu
//			my_stream->Close();
//			return target;
//		}
//	}
//	return nullptr;
//}