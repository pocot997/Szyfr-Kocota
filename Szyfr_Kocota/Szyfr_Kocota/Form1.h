#pragma once

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
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
	private: System::Windows::Forms::RadioButton^ radioCpp;
	private: System::Windows::Forms::RadioButton^ radioAsm;
	private: System::Windows::Forms::Button^ buttonEncode;
	private: System::Windows::Forms::Button^ buttonDecode;
	private: System::Windows::Forms::TextBox^ cipherTextBox;
	private: System::Windows::Forms::Button^ ChessButton;

	private: System::Windows::Forms::Button^ saveFileButton;
	private: System::Windows::Forms::Button^ showFileButton;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::Label^ threadsLabel;
	private: System::Windows::Forms::TextBox^ infoTextBox;
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:

	protected:


	private:
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
			this->radioCpp = (gcnew System::Windows::Forms::RadioButton());
			this->radioAsm = (gcnew System::Windows::Forms::RadioButton());
			this->buttonEncode = (gcnew System::Windows::Forms::Button());
			this->buttonDecode = (gcnew System::Windows::Forms::Button());
			this->cipherTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ChessButton = (gcnew System::Windows::Forms::Button());
			this->saveFileButton = (gcnew System::Windows::Forms::Button());
			this->showFileButton = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->threadsLabel = (gcnew System::Windows::Forms::Label());
			this->infoTextBox = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// radioCpp
			// 
			this->radioCpp->AutoSize = true;
			this->radioCpp->Location = System::Drawing::Point(367, 84);
			this->radioCpp->Name = L"radioCpp";
			this->radioCpp->Size = System::Drawing::Size(44, 17);
			this->radioCpp->TabIndex = 0;
			this->radioCpp->TabStop = true;
			this->radioCpp->Text = L"C++";
			this->radioCpp->UseVisualStyleBackColor = true;
			this->radioCpp->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton1_CheckedChanged);
			// 
			// radioAsm
			// 
			this->radioAsm->AutoSize = true;
			this->radioAsm->Location = System::Drawing::Point(366, 109);
			this->radioAsm->Name = L"radioAsm";
			this->radioAsm->Size = System::Drawing::Size(45, 17);
			this->radioAsm->TabIndex = 1;
			this->radioAsm->TabStop = true;
			this->radioAsm->Text = L"Asm";
			this->radioAsm->UseVisualStyleBackColor = true;
			// 
			// buttonEncode
			// 
			this->buttonEncode->Location = System::Drawing::Point(417, 109);
			this->buttonEncode->Name = L"buttonEncode";
			this->buttonEncode->Size = System::Drawing::Size(75, 23);
			this->buttonEncode->TabIndex = 2;
			this->buttonEncode->Text = L"Encode";
			this->buttonEncode->UseVisualStyleBackColor = true;
			// 
			// buttonDecode
			// 
			this->buttonDecode->Location = System::Drawing::Point(417, 81);
			this->buttonDecode->Name = L"buttonDecode";
			this->buttonDecode->Size = System::Drawing::Size(75, 23);
			this->buttonDecode->TabIndex = 3;
			this->buttonDecode->Text = L"Decode";
			this->buttonDecode->UseVisualStyleBackColor = true;
			// 
			// cipherTextBox
			// 
			this->cipherTextBox->Location = System::Drawing::Point(588, 11);
			this->cipherTextBox->Multiline = true;
			this->cipherTextBox->Name = L"cipherTextBox";
			this->cipherTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->cipherTextBox->Size = System::Drawing::Size(272, 264);
			this->cipherTextBox->TabIndex = 26;
			// 
			// ChessButton
			// 
			this->ChessButton->Location = System::Drawing::Point(390, 253);
			this->ChessButton->Name = L"ChessButton";
			this->ChessButton->Size = System::Drawing::Size(96, 23);
			this->ChessButton->TabIndex = 25;
			this->ChessButton->Text = L"Open key file";
			this->ChessButton->UseVisualStyleBackColor = true;
			// 
			// saveFileButton
			// 
			this->saveFileButton->Location = System::Drawing::Point(493, 253);
			this->saveFileButton->Name = L"saveFileButton";
			this->saveFileButton->Size = System::Drawing::Size(89, 23);
			this->saveFileButton->TabIndex = 23;
			this->saveFileButton->Text = L"Save text file";
			this->saveFileButton->UseVisualStyleBackColor = true;
			// 
			// showFileButton
			// 
			this->showFileButton->Location = System::Drawing::Point(290, 253);
			this->showFileButton->Name = L"showFileButton";
			this->showFileButton->Size = System::Drawing::Size(94, 23);
			this->showFileButton->TabIndex = 22;
			this->showFileButton->Text = L"Open text file";
			this->showFileButton->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(445, 11);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 20);
			this->button1->TabIndex = 29;
			this->button1->Text = L"Set threads";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(393, 11);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 64, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(46, 20);
			this->numericUpDown1->TabIndex = 28;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// threadsLabel
			// 
			this->threadsLabel->AutoSize = true;
			this->threadsLabel->Location = System::Drawing::Point(338, 15);
			this->threadsLabel->Name = L"threadsLabel";
			this->threadsLabel->Size = System::Drawing::Size(49, 13);
			this->threadsLabel->TabIndex = 27;
			this->threadsLabel->Text = L"Threads:";
			// 
			// infoTextBox
			// 
			this->infoTextBox->Location = System::Drawing::Point(341, 37);
			this->infoTextBox->Multiline = true;
			this->infoTextBox->Name = L"infoTextBox";
			this->infoTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->infoTextBox->Size = System::Drawing::Size(179, 41);
			this->infoTextBox->TabIndex = 30;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(272, 264);
			this->textBox1->TabIndex = 31;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(873, 600);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->infoTextBox);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->threadsLabel);
			this->Controls->Add(this->cipherTextBox);
			this->Controls->Add(this->ChessButton);
			this->Controls->Add(this->saveFileButton);
			this->Controls->Add(this->showFileButton);
			this->Controls->Add(this->buttonDecode);
			this->Controls->Add(this->buttonEncode);
			this->Controls->Add(this->radioAsm);
			this->Controls->Add(this->radioCpp);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
	}
private: System::Void plainTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
	}
};
}
