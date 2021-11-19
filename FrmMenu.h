#pragma once
#include "FrmLobby.h"
#include "FrmInstructions.h"

namespace FinalProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmMenu
	/// </summary>
	public ref class FrmMenu : public System::Windows::Forms::Form
	{
	public:
		FrmMenu(void)
		{
			InitializeComponent();
			g = this->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, this->ClientRectangle);
			bmpMain = gcnew Bitmap("images//background.jpg");
			bmpLogo = gcnew Bitmap("images//logo.png");
			bmpCC = gcnew Bitmap("images//cc.png");
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmMenu()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::Button^ btnInstructions;
	private: System::Windows::Forms::Button^ btnExit;

	private:
	protected:
	private:
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		

		Bitmap^ bmpMain;
		Bitmap^ bmpLogo;
		Bitmap^ bmpCC;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ btnStartGame;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmMenu::typeid));
			this->btnInstructions = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->btnStartGame = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnInstructions
			// 
			this->btnInstructions->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->btnInstructions->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->btnInstructions->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnInstructions->FlatAppearance->BorderSize = 4;
			this->btnInstructions->Font = (gcnew System::Drawing::Font(L"Poor Richard", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnInstructions->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btnInstructions->Location = System::Drawing::Point(842, 575);
			this->btnInstructions->Name = L"btnInstructions";
			this->btnInstructions->Size = System::Drawing::Size(288, 60);
			this->btnInstructions->TabIndex = 2;
			this->btnInstructions->Text = L"How to play\?";
			this->btnInstructions->UseVisualStyleBackColor = false;
			this->btnInstructions->Click += gcnew System::EventHandler(this, &FrmMenu::btnInstructions_Click);
			// 
			// btnExit
			// 
			this->btnExit->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->btnExit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->btnExit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnExit->FlatAppearance->BorderSize = 4;
			this->btnExit->Font = (gcnew System::Drawing::Font(L"Poor Richard", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnExit->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btnExit->Location = System::Drawing::Point(842, 652);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(288, 60);
			this->btnExit->TabIndex = 3;
			this->btnExit->Text = L"Exit";
			this->btnExit->UseVisualStyleBackColor = false;
			this->btnExit->Click += gcnew System::EventHandler(this, &FrmMenu::btnExit_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmMenu::timer1_Tick);
			// 
			// btnStartGame
			// 
			this->btnStartGame->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->btnStartGame->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->btnStartGame->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnStartGame->FlatAppearance->BorderSize = 4;
			this->btnStartGame->Font = (gcnew System::Drawing::Font(L"Poor Richard", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnStartGame->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btnStartGame->Location = System::Drawing::Point(842, 493);
			this->btnStartGame->Name = L"btnStartGame";
			this->btnStartGame->Size = System::Drawing::Size(288, 60);
			this->btnStartGame->TabIndex = 4;
			this->btnStartGame->Text = L"Start";
			this->btnStartGame->UseVisualStyleBackColor = false;
			this->btnStartGame->Click += gcnew System::EventHandler(this, &FrmMenu::btnStartGame_Click);
			// 
			// FrmMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1308, 812);
			this->Controls->Add(this->btnStartGame);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnInstructions);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"FrmMenu";
			this->Text = L"COVID Invaders";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &FrmMenu::FrmMenu_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void FrmMenu_Load(System::Object^ sender, System::EventArgs^ e) {
	}

private: System::Void btnInstructions_Click(System::Object^ sender, System::EventArgs^ e) {

	FrmInstructions^ frm = gcnew FrmInstructions();
	frm->ShowDialog();
	delete frm;

}
private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e) {
	Close();
}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	buffer->Graphics->Clear(Color::White);

	//Map
	//virus
	buffer->Graphics->DrawImage(bmpMain, 0, 0, 1540, 810);
	buffer->Graphics->DrawImage(bmpLogo, 510, 170, 510, 270);
	buffer->Graphics->DrawImage(bmpCC, 670, 660, 140, 50);
	
	buffer->Render(g);
}
private: System::Void btnStartGame_Click(System::Object^ sender, System::EventArgs^ e) {
	FrmLobby^ frm = gcnew FrmLobby();
	this->Visible = false;
	frm->ShowDialog();
	this->Visible = true;
	delete frm;
}
};
}
