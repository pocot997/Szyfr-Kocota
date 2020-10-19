#pragma once
#include <iostream>
#include <chrono>
#include "algorithm.h"

namespace CppCLRWinformsProjekt
{
	using namespace System;
	using namespace System::IO;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace System::Collections;
	using namespace System::ComponentModel;
	using namespace System::Windows::Forms;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		private:
			Algorithm^ algorithm;
		public:
		Form1(void)
		{
			InitializeComponent();
			algorithm = gcnew Algorithm();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

		protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
		private: System::Windows::Forms::RadioButton^ radio_cpp;
		private: System::Windows::Forms::RadioButton^ radio_asm;
		private: System::Windows::Forms::Button^ button_encode;
		private: System::Windows::Forms::Button^ button_decode;
		private: System::Windows::Forms::TextBox^ text_box_right;
		private: System::Windows::Forms::Button^ button_open_key;
		private: System::Windows::Forms::Button^ button_save_text;
		private: System::Windows::Forms::Button^ button_open_text;
		private: System::Windows::Forms::NumericUpDown^ numeric_up_down_threads;
		private: System::Windows::Forms::TextBox^ text_box_middle;
		private: System::Windows::Forms::TextBox^ text_box_left;
			   String^ loaded_text;
			   String^ key_text;
			   String^ solution_text;
			   String^ alphabet;
			   bool asm_or_cpp; //0=asm, 1=cpp
			   int threads;
	private: System::Windows::Forms::Label^ label_threads;
		   /// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->radio_cpp = (gcnew System::Windows::Forms::RadioButton());
			this->radio_asm = (gcnew System::Windows::Forms::RadioButton());
			this->button_encode = (gcnew System::Windows::Forms::Button());
			this->button_decode = (gcnew System::Windows::Forms::Button());
			this->text_box_right = (gcnew System::Windows::Forms::TextBox());
			this->button_open_key = (gcnew System::Windows::Forms::Button());
			this->button_save_text = (gcnew System::Windows::Forms::Button());
			this->button_open_text = (gcnew System::Windows::Forms::Button());
			this->numeric_up_down_threads = (gcnew System::Windows::Forms::NumericUpDown());
			this->text_box_middle = (gcnew System::Windows::Forms::TextBox());
			this->text_box_left = (gcnew System::Windows::Forms::TextBox());
			this->label_threads = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_up_down_threads))->BeginInit();
			this->SuspendLayout();
			// 
			// radio_cpp
			// 
			this->radio_cpp->AutoSize = true;
			this->radio_cpp->Location = System::Drawing::Point(375, 86);
			this->radio_cpp->Name = L"radio_cpp";
			this->radio_cpp->Size = System::Drawing::Size(44, 17);
			this->radio_cpp->TabIndex = 0;
			this->radio_cpp->TabStop = true;
			this->radio_cpp->Text = L"C++";
			this->radio_cpp->UseVisualStyleBackColor = true;
			this->radio_cpp->CheckedChanged += gcnew System::EventHandler(this, &Form1::radio_cpp_CheckedChanged);
			// 
			// radio_asm
			// 
			this->radio_asm->AutoSize = true;
			this->radio_asm->Location = System::Drawing::Point(374, 111);
			this->radio_asm->Name = L"radio_asm";
			this->radio_asm->Size = System::Drawing::Size(45, 17);
			this->radio_asm->TabIndex = 1;
			this->radio_asm->TabStop = true;
			this->radio_asm->Text = L"Asm";
			this->radio_asm->UseVisualStyleBackColor = true;
			this->radio_asm->CheckedChanged += gcnew System::EventHandler(this, &Form1::radio_asm_CheckedChanged);
			// 
			// button_encode
			// 
			this->button_encode->Location = System::Drawing::Point(425, 111);
			this->button_encode->Name = L"button_encode";
			this->button_encode->Size = System::Drawing::Size(75, 23);
			this->button_encode->TabIndex = 2;
			this->button_encode->Text = L"Encode";
			this->button_encode->UseVisualStyleBackColor = true;
			this->button_encode->Click += gcnew System::EventHandler(this, &Form1::button_encode_Click);
			// 
			// button_decode
			// 
			this->button_decode->Location = System::Drawing::Point(425, 83);
			this->button_decode->Name = L"button_decode";
			this->button_decode->Size = System::Drawing::Size(75, 23);
			this->button_decode->TabIndex = 3;
			this->button_decode->Text = L"Decode";
			this->button_decode->UseVisualStyleBackColor = true;
			this->button_decode->Click += gcnew System::EventHandler(this, &Form1::button_decode_Click);
			// 
			// text_box_right
			// 
			this->text_box_right->Location = System::Drawing::Point(588, 12);
			this->text_box_right->Multiline = true;
			this->text_box_right->Name = L"text_box_right";
			this->text_box_right->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->text_box_right->Size = System::Drawing::Size(272, 272);
			this->text_box_right->TabIndex = 26;
			this->text_box_right->TextChanged += gcnew System::EventHandler(this, &Form1::text_box_right_TextChanged);
			// 
			// button_open_key
			// 
			this->button_open_key->Location = System::Drawing::Point(390, 260);
			this->button_open_key->Name = L"button_open_key";
			this->button_open_key->Size = System::Drawing::Size(96, 23);
			this->button_open_key->TabIndex = 25;
			this->button_open_key->Text = L"Open key file";
			this->button_open_key->UseVisualStyleBackColor = true;
			this->button_open_key->Click += gcnew System::EventHandler(this, &Form1::button_open_key_Click);
			// 
			// button_save_text
			// 
			this->button_save_text->Location = System::Drawing::Point(493, 260);
			this->button_save_text->Name = L"button_save_text";
			this->button_save_text->Size = System::Drawing::Size(89, 23);
			this->button_save_text->TabIndex = 23;
			this->button_save_text->Text = L"Save text file";
			this->button_save_text->UseVisualStyleBackColor = true;
			this->button_save_text->Click += gcnew System::EventHandler(this, &Form1::button_save_text_Click);
			// 
			// button_open_text
			// 
			this->button_open_text->Location = System::Drawing::Point(290, 260);
			this->button_open_text->Name = L"button_open_text";
			this->button_open_text->Size = System::Drawing::Size(94, 23);
			this->button_open_text->TabIndex = 22;
			this->button_open_text->Text = L"Open text file";
			this->button_open_text->UseVisualStyleBackColor = true;
			this->button_open_text->Click += gcnew System::EventHandler(this, &Form1::button_open_text_Click);
			// 
			// numeric_up_down_threads
			// 
			this->numeric_up_down_threads->Location = System::Drawing::Point(440, 10);
			this->numeric_up_down_threads->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1024, 0, 0, 0 });
			this->numeric_up_down_threads->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numeric_up_down_threads->Name = L"numeric_up_down_threads";
			this->numeric_up_down_threads->Size = System::Drawing::Size(46, 20);
			this->numeric_up_down_threads->TabIndex = 28;
			this->numeric_up_down_threads->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numeric_up_down_threads->ValueChanged += gcnew System::EventHandler(this, &Form1::numeric_up_down_threads_ValueChanged);
			// 
			// text_box_middle
			// 
			this->text_box_middle->Location = System::Drawing::Point(374, 36);
			this->text_box_middle->MaxLength = 42000;
			this->text_box_middle->Multiline = true;
			this->text_box_middle->Name = L"text_box_middle";
			this->text_box_middle->Size = System::Drawing::Size(126, 41);
			this->text_box_middle->TabIndex = 30;
			this->text_box_middle->TextChanged += gcnew System::EventHandler(this, &Form1::text_box_middle_TextChanged);
			// 
			// text_box_left
			// 
			this->text_box_left->Location = System::Drawing::Point(12, 12);
			this->text_box_left->MaxLength = 42000;
			this->text_box_left->Multiline = true;
			this->text_box_left->Name = L"text_box_left";
			this->text_box_left->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->text_box_left->Size = System::Drawing::Size(272, 272);
			this->text_box_left->TabIndex = 31;
			this->text_box_left->TextChanged += gcnew System::EventHandler(this, &Form1::text_box_left_TextChanged);
			// 
			// label_threads
			// 
			this->label_threads->AutoSize = true;
			this->label_threads->Location = System::Drawing::Point(385, 15);
			this->label_threads->Name = L"label_threads";
			this->label_threads->Size = System::Drawing::Size(49, 13);
			this->label_threads->TabIndex = 32;
			this->label_threads->Text = L"Threads:";
			this->label_threads->Click += gcnew System::EventHandler(this, &Form1::label_threads_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(873, 601);
			this->Controls->Add(this->label_threads);
			this->Controls->Add(this->text_box_left);
			this->Controls->Add(this->text_box_middle);
			this->Controls->Add(this->numeric_up_down_threads);
			this->Controls->Add(this->text_box_right);
			this->Controls->Add(this->button_open_key);
			this->Controls->Add(this->button_save_text);
			this->Controls->Add(this->button_open_text);
			this->Controls->Add(this->button_decode);
			this->Controls->Add(this->button_encode);
			this->Controls->Add(this->radio_asm);
			this->Controls->Add(this->radio_cpp);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_up_down_threads))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e)
		{
			algorithm->fill_alphabet();
			threads = Int32(numeric_up_down_threads->Value);
		}
		private: System::Void numeric_up_down_threads_ValueChanged(System::Object^ sender, System::EventArgs^ e)
		{
			threads = Int32(numeric_up_down_threads->Value);
		}
		private: System::Void radio_cpp_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
		{
			asm_or_cpp = true;
		}
		private: System::Void radio_asm_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
		{
			asm_or_cpp = false;
		}
		private: System::Void text_box_left_TextChanged(System::Object^ sender, System::EventArgs^ e)
		{
		}
		private: System::Void text_box_middle_TextChanged(System::Object^ sender, System::EventArgs^ e)
		{
		}
		private: System::Void text_box_right_TextChanged(System::Object^ sender, System::EventArgs^ e)
		{
		}
		private: System::Void button_set_threads_Click(System::Object^ sender, System::EventArgs^ e)
		{
		}
		private: System::Void button_decode_Click(System::Object^ sender, System::EventArgs^ e)
		{
			algorithm->set_encrypting(false);
			algorithm->fill_key_x();
			algorithm->fill_key_y();
			algorithm->shuffle_alphabet();
			int where_decode = 0;
			for (int i = 0; i < algorithm->get_loaded_length(); i+=2)
			{
				if (algorithm->get_loaded_char(i) == '-')
				{
					algorithm->decrypt_negative(i, where_decode);
					i++;
				}
				else
					algorithm->decrypt(i, where_decode);
				where_decode++;
			}
			solution_text = algorithm->convert_to_system_string_from_char(algorithm->get_solution_text_char(), algorithm->get_loaded_length()/2);
			text_box_right->Clear();
			text_box_right->Text = solution_text;

		}
		private: System::Void button_encode_Click(System::Object^ sender, System::EventArgs^ e)
		{
			algorithm->set_encrypting(true);
			algorithm->fill_key_x();
			algorithm->fill_key_y();
			algorithm->shuffle_alphabet();
			if (threads > algorithm->get_loaded_length())
				threads = algorithm->get_loaded_length();
			Generic::List<Thread^>^ thread_list = gcnew Generic::List<Thread^>();	//Lista do przechowywania aktualnie obs³ugiwanych w¹tków
			auto start = std::chrono::high_resolution_clock::now();
			int i = 0;
			for (i; i < threads; i++)
			{
				thread_list->Add(gcnew Thread(gcnew ParameterizedThreadStart(algorithm, &Algorithm::encrypt)));
				Tuple<int>^ my_first_tuple = gcnew Tuple<int> (i);
				thread_list[i]->Start(my_first_tuple);
			}
			bool ready;
			for (i; i < algorithm->get_loaded_length();i++)
			{
				ready = false;
				while (!ready)
				{
					for (int j = 0; j < threads; j++)
					{
						if (!thread_list[j]->IsAlive)
						{
							thread_list[j] = gcnew Thread(gcnew ParameterizedThreadStart(algorithm, &Algorithm::encrypt));
							Tuple<int> ^ my_second_tuple = gcnew Tuple<int> (i);
							thread_list[j]->Start(my_second_tuple);
							ready = true;
						}
						if (ready)
							break;
					}
				}
			}
			for (int i = 0; i < threads; i++)
			{
				thread_list[i]->Join();
			}
			auto stop = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
			String^ duration_s = gcnew String(to_string(duration.count()).c_str());
			text_box_middle->Text = "Czas wykonania: " + duration_s + "ms";
			solution_text = algorithm->convert_to_system_string_from_int(algorithm->get_solution_text_int(), algorithm->get_loaded_length());
			text_box_right->Clear();
			text_box_right->Text = solution_text;
		}
		private: System::Void button_open_text_Click(System::Object^ sender, System::EventArgs^ e)
		{
			loaded_text = algorithm->file_read(sender, e, 0);
			text_box_left->Clear(); //wyczyszczenie tex boxa
			text_box_left->Text = loaded_text; //wpisanie do text boxa
		}
		private: System::Void button_open_key_Click(System::Object^ sender, System::EventArgs^ e)
		{
			key_text = algorithm->file_read(sender, e, 1);
			text_box_middle->Clear(); //wyczyszczenie tex boxa
			text_box_middle->Text = key_text; //wpisanie do text boxa
		}
		private: System::Void button_save_text_Click(System::Object^ sender, System::EventArgs^ e)
		{
			File::WriteAllText("C:/Users/krzyc/OneDrive/Pulpit/szyforwanko/solution.txt",solution_text);
			//algorithm->delete_everything();
		}
		private: System::Void label_threads_Click(System::Object^ sender, System::EventArgs^ e)
		{
		}
};
}
