#pragma once

namespace teacherdb {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	/// <summary>
	/// Summary for del
	/// </summary>
	public ref class del : public System::Windows::Forms::Form
	{
	public:
		del(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~del()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:



	private: System::Windows::Forms::TextBox^ tid;



	private: System::Windows::Forms::Label^ label1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tid = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(35, 64);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(248, 33);
			this->button1->TabIndex = 17;
			this->button1->Text = L"Delete";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &del::button1_Click);
			// 
			// tid
			// 
			this->tid->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tid->Location = System::Drawing::Point(134, 22);
			this->tid->Name = L"tid";
			this->tid->Size = System::Drawing::Size(149, 26);
			this->tid->TabIndex = 13;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(31, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(28, 19);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Tid";
			// 
			// del
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(297, 123);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->tid);
			this->Controls->Add(this->label1);
			this->Name = L"del";
			this->Text = L"del";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		
		StreamWriter^ outp = File::CreateText("del.txt");
		if (tid->Text == "") {
			MessageBox::Show("Enter Value Please.", "Error");
			outp->Close();
			return;
		}
		outp->WriteLine(tid->Text);
		outp->Close();
		this->Close();
	}
};
}
