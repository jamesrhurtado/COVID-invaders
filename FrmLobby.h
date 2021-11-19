#pragma once
#include "FrmMain.h"

namespace FinalProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmLobby
	/// </summary>
	public ref class FrmLobby : public System::Windows::Forms::Form
	{
	public:
		FrmLobby(void)
		{
			InitializeComponent();
			g = this->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, this->ClientRectangle);
			bmpBackgroundLobb = gcnew Bitmap("images//background_lobby.jpg");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmLobby()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnLetsGo;
	private: System::Windows::Forms::Label^ lblName;
	protected:

	private:
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		Bitmap^ bmpBackgroundLobb;
		String^ PlayerName;
		int lvl;

	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtName;
	private: System::Windows::Forms::DomainUpDown^ domainUpDownLvl;



	private: System::Windows::Forms::NumericUpDown^ numericUpDownCitizens;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownVirus;




	private: System::ComponentModel::IContainer^ components;



		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmLobby::typeid));
			this->btnLetsGo = (gcnew System::Windows::Forms::Button());
			this->lblName = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->domainUpDownLvl = (gcnew System::Windows::Forms::DomainUpDown());
			this->numericUpDownCitizens = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownVirus = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCitizens))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownVirus))->BeginInit();
			this->SuspendLayout();
			// 
			// btnLetsGo
			// 
			this->btnLetsGo->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->btnLetsGo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->btnLetsGo->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnLetsGo->FlatAppearance->BorderSize = 0;
			this->btnLetsGo->Font = (gcnew System::Drawing::Font(L"Poor Richard", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLetsGo->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btnLetsGo->Location = System::Drawing::Point(913, 837);
			this->btnLetsGo->Name = L"btnLetsGo";
			this->btnLetsGo->Size = System::Drawing::Size(288, 60);
			this->btnLetsGo->TabIndex = 5;
			this->btnLetsGo->Text = L"Let\'s go!";
			this->btnLetsGo->UseVisualStyleBackColor = false;
			this->btnLetsGo->Click += gcnew System::EventHandler(this, &FrmLobby::btnLetsGo_Click);
			// 
			// lblName
			// 
			this->lblName->AutoSize = true;
			this->lblName->BackColor = System::Drawing::Color::Transparent;
			this->lblName->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblName->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lblName->Font = (gcnew System::Drawing::Font(L"Poor Richard", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblName->Location = System::Drawing::Point(874, 300);
			this->lblName->Name = L"lblName";
			this->lblName->Size = System::Drawing::Size(84, 30);
			this->lblName->TabIndex = 6;
			this->lblName->Text = L"Name :";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmLobby::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Font = (gcnew System::Drawing::Font(L"Poor Richard", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(874, 399);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(81, 30);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Level :";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label2->Font = (gcnew System::Drawing::Font(L"Poor Richard", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(874, 498);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(105, 30);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Citizens :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label3->Font = (gcnew System::Drawing::Font(L"Poor Richard", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(874, 615);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(79, 30);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Virus :";
			// 
			// txtName
			// 
			this->txtName->BackColor = System::Drawing::SystemColors::Control;
			this->txtName->Font = (gcnew System::Drawing::Font(L"Poor Richard", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtName->Location = System::Drawing::Point(1024, 302);
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(192, 30);
			this->txtName->TabIndex = 11;
			// 
			// domainUpDownLvl
			// 
			this->domainUpDownLvl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->domainUpDownLvl->Items->Add(L"Level 1");
			this->domainUpDownLvl->Items->Add(L"Level 2");
			this->domainUpDownLvl->Location = System::Drawing::Point(1024, 404);
			this->domainUpDownLvl->Name = L"domainUpDownLvl";
			this->domainUpDownLvl->ReadOnly = true;
			this->domainUpDownLvl->Size = System::Drawing::Size(192, 27);
			this->domainUpDownLvl->Sorted = true;
			this->domainUpDownLvl->TabIndex = 12;
			this->domainUpDownLvl->Text = L"(Enter level)";
			// 
			// numericUpDownCitizens
			// 
			this->numericUpDownCitizens->BackColor = System::Drawing::SystemColors::Control;
			this->numericUpDownCitizens->Font = (gcnew System::Drawing::Font(L"Poor Richard", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->numericUpDownCitizens->Location = System::Drawing::Point(1024, 501);
			this->numericUpDownCitizens->Name = L"numericUpDownCitizens";
			this->numericUpDownCitizens->Size = System::Drawing::Size(192, 30);
			this->numericUpDownCitizens->TabIndex = 15;
			// 
			// numericUpDownVirus
			// 
			this->numericUpDownVirus->BackColor = System::Drawing::SystemColors::Control;
			this->numericUpDownVirus->Font = (gcnew System::Drawing::Font(L"Poor Richard", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->numericUpDownVirus->Location = System::Drawing::Point(1024, 615);
			this->numericUpDownVirus->Name = L"numericUpDownVirus";
			this->numericUpDownVirus->Size = System::Drawing::Size(192, 30);
			this->numericUpDownVirus->TabIndex = 16;
			// 
			// FrmLobby
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1681, 1026);
			this->Controls->Add(this->numericUpDownVirus);
			this->Controls->Add(this->numericUpDownCitizens);
			this->Controls->Add(this->domainUpDownLvl);
			this->Controls->Add(this->txtName);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lblName);
			this->Controls->Add(this->btnLetsGo);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"FrmLobby";
			this->Text = L"Lobby";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCitizens))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownVirus))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnLetsGo_Click(System::Object^ sender, System::EventArgs^ e) {

		if (domainUpDownLvl->Text == "Level 1") {
			lvl = 1;
		}
		else if (domainUpDownLvl->Text == "Level 2") {
			lvl = 2;
		}
		else {
			timer1->Enabled = false;
			MessageBox::Show("Enter a level");
			return;
		}
		if (numericUpDownCitizens->Value == 0 || numericUpDownVirus->Value == 0 || txtName->Text == "") {
			timer1->Enabled = false;
			MessageBox::Show("Fill all the blank spaces");
			return;
		}
		timer1->Enabled = true;
		FrmMain^ frm = gcnew FrmMain(Convert::ToInt32(numericUpDownCitizens->Value),
			Convert::ToInt32(numericUpDownVirus->Value), PlayerName, lvl);
		//frm->assignLevel(domainUpDownLvl->Text);
		this->Visible = false;
		frm->ShowDialog();
		delete frm;
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//Clear
		buffer->Graphics->Clear(Color::White);
		//Map
		buffer->Graphics->DrawImage(bmpBackgroundLobb, 0, 0, 1570,880);
		PlayerName = txtName->Text;
		buffer->Render(g);
	}
};
}
