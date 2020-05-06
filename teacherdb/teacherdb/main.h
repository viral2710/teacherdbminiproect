#pragma once
#include"Header.h"
#include"insert.h"
#include"display.h"
#include"search.h"
#include"del.h"
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
namespace teacherdb {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	btree b;
	teacher t;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(46, 42);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(150, 30);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Insert";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(337, 43);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(150, 30);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Display";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(46, 147);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(150, 30);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Search";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(337, 147);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(150, 30);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Delete";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Red;
			this->label1->Location = System::Drawing::Point(161, 216);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 15);
			this->label1->TabIndex = 4;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 293);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::MyForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		teacherdb::insert f;
		cout << "0";
		f.ShowDialog();
		String^ tid; cout << "3";
		StreamReader^ r = File::OpenText("project.txt");
		cout << "4";
		tid = r->ReadLine();
		if (tid=="") {

			MessageBox::Show("Enter Value Please.", "Error");
			r->Close();
			return;
		}
		msclr::interop::marshal_context con;
		t.tid = con.marshal_as<std::string>(tid);
		t.name = con.marshal_as< std::string >(r->ReadLine());
		t.phno= con.marshal_as< std::string >(r->ReadLine());
		t.dept= con.marshal_as< std::string >(r->ReadLine());
		b.insert(t);
		if (b.error != "") {
			label1->Text = gcnew String(b.error.c_str());
		}
		r->Close();
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	teacherdb::display f;
	msclr::interop::marshal_context con;
	b.ds = 0;
	for (int i = 0; i < 1000; i++) {
		b.st[i] = "";
	}
	b.display();
	cout << "|1|";
	if (b.error != "") {
		label1->Text = gcnew String(b.error.c_str());
		return;
	}
	cout << "|2|";
	StreamWriter^ outp = File::CreateText("project.txt");
	for (int i = 0; i < b.ds; i++) {
		String^ stud = gcnew String(b.st[i].c_str());
		cout << b.st[i];
		outp->WriteLine(stud);
	}
	outp->Close();
	f.ShowDialog();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	teacherdb::del f;
	msclr::interop::marshal_context con;
	f.ShowDialog();
	String^ tid;
	StreamReader^ r = File::OpenText("del.txt");
	tid = r->ReadLine();
	if (tid == "") {
		MessageBox::Show("Enter Value Please.", "Error");
		r->Close();
		return;
	}
	t.tid = con.marshal_as<std::string>(tid);
	t.name = "";
	t.phno = "";
	t.dept = "";
	b=b.del(t);
	if (b.error != "") {
		label1->Text = gcnew String(b.error.c_str());
		r->Close();
	}
	r->Close();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	teacherdb::search f;
	msclr::interop::marshal_context con;
	f.ShowDialog();
	String^ tid;
	StreamReader^ r = File::OpenText("search.txt");
	tid = r->ReadLine();
	if (tid == "") {

		MessageBox::Show("Enter Value Please.", "Error");
		r->Close();
		return;
	}
	t.tid = con.marshal_as<std::string>(tid);
	t.name = "";
	t.phno = "";
	t.dept = "";
	b.ds = 0;
	for (int i = 0; i < 1000; i++) {
		b.st[i] = "";
	}
	b.search(t);
	if (b.error != "") {
		label1->Text = gcnew String(b.error.c_str());
		r->Close();
		return;
	}
	r->Close();
	teacherdb::display d;
	StreamWriter^ outp = File::CreateText("project.txt");
	for (int i = 0; i < b.ds; i++) {
		String^ stud = gcnew String(b.st[i].c_str());
		cout << b.st[i];
		outp->WriteLine(stud);
	}
	outp->Close();
	d.ShowDialog();

}
private: System::Void MyForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	StreamWriter^ outp = File::CreateText("db.txt");
	b.write();
	for (int i = 0; i < b.ds; i++) {
		String^ stud = gcnew String(b.st[i].c_str());
		cout << b.st[i];
		outp->WriteLine(stud);
	}
	
	outp->Close();
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	msclr::interop::marshal_context con;
	b.ds = 0;
	for (int i = 0; i < 1000; i++) {
		b.st[i] = "";
	}
	StreamReader^ r = File::OpenText("db.txt");
	int x = 0;
	String^ line;
	while ((line = r->ReadLine()) != nullptr) {
		b.st[x] = con.marshal_as<std::string>(line);
		cout << b.st[x++];
	}
	b.ds = x;
	if (x == 0) {
		
		r->Close();
		return;
		
	}
	b.read();
	
	r->Close();

}
};
}
