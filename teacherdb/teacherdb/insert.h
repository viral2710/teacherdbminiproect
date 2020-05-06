#pragma once
#include<iostream>
namespace teacherdb {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace std;
	/// <summary>
	/// Summary for insert
	/// </summary>
	public ref class insert : public System::Windows::Forms::Form
	{
	public:
		insert(void)
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
		~insert()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ tid;
	private: System::Windows::Forms::TextBox^ name;
	private: System::Windows::Forms::TextBox^ phno;
	private: System::Windows::Forms::TextBox^ dept;
	private: System::Windows::Forms::Button^ button1;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tid = (gcnew System::Windows::Forms::TextBox());
			this->name = (gcnew System::Windows::Forms::TextBox());
			this->phno = (gcnew System::Windows::Forms::TextBox());
			this->dept = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(16, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(28, 19);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Tid";
			this->label1->Click += gcnew System::EventHandler(this, &insert::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(16, 63);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 19);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Name";
			this->label2->Click += gcnew System::EventHandler(this, &insert::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(19, 95);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(70, 19);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Phone no.";
			this->label3->Click += gcnew System::EventHandler(this, &insert::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(19, 127);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(43, 19);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Dept.";
			this->label4->Click += gcnew System::EventHandler(this, &insert::label4_Click);
			// 
			// tid
			// 
			this->tid->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tid->Location = System::Drawing::Point(119, 28);
			this->tid->Name = L"tid";
			this->tid->Size = System::Drawing::Size(149, 26);
			this->tid->TabIndex = 4;
			this->tid->TextChanged += gcnew System::EventHandler(this, &insert::tid_TextChanged);
			// 
			// name
			// 
			this->name->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->name->Location = System::Drawing::Point(119, 60);
			this->name->Name = L"name";
			this->name->Size = System::Drawing::Size(149, 26);
			this->name->TabIndex = 5;
			this->name->TextChanged += gcnew System::EventHandler(this, &insert::name_TextChanged);
			// 
			// phno
			// 
			this->phno->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->phno->Location = System::Drawing::Point(119, 92);
			this->phno->Name = L"phno";
			this->phno->Size = System::Drawing::Size(149, 26);
			this->phno->TabIndex = 6;
			this->phno->TextChanged += gcnew System::EventHandler(this, &insert::phno_TextChanged);
			// 
			// dept
			// 
			this->dept->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dept->Location = System::Drawing::Point(119, 124);
			this->dept->Name = L"dept";
			this->dept->Size = System::Drawing::Size(149, 26);
			this->dept->TabIndex = 7;
			this->dept->TextChanged += gcnew System::EventHandler(this, &insert::dept_TextChanged);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(23, 161);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(245, 33);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Insert";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &insert::button1_Click);
			// 
			// insert
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(291, 196);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dept);
			this->Controls->Add(this->phno);
			this->Controls->Add(this->name);
			this->Controls->Add(this->tid);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"insert";
			this->Text = L"insert";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (tid->Text == "") {
			MessageBox::Show("Enter Value Please.", "Error");
			return;
		}
		StreamWriter^ outp = File::CreateText("project.txt");
		outp->WriteLine(tid->Text);
		outp->WriteLine(name->Text);
		outp->WriteLine(phno->Text);
		outp->WriteLine(dept->Text);
		outp->Close();
		this->Close();
	}
private: System::Void dept_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void phno_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void name_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tid_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
