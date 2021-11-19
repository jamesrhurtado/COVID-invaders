#pragma once

namespace FinalProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmInstructions
	/// </summary>
	public ref class FrmInstructions : public System::Windows::Forms::Form
	{
	public:
		FrmInstructions(void)
		{
			InitializeComponent();
			g = this->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, this->ClientRectangle);
			bmpBackgroundIns = gcnew Bitmap("images//background_ins.jpg");

			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmInstructions()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		Bitmap^ bmpBackgroundIns;


	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ btnReturn;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmInstructions::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->btnReturn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmInstructions::timer1_Tick);
			// 
			// btnReturn
			// 
			this->btnReturn->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->btnReturn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->btnReturn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnReturn->FlatAppearance->BorderSize = 4;
			this->btnReturn->Font = (gcnew System::Drawing::Font(L"Poor Richard", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnReturn->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btnReturn->Location = System::Drawing::Point(935, 683);
			this->btnReturn->Name = L"btnReturn";
			this->btnReturn->Size = System::Drawing::Size(288, 60);
			this->btnReturn->TabIndex = 5;
			this->btnReturn->Text = L"Return";
			this->btnReturn->UseVisualStyleBackColor = false;
			this->btnReturn->Click += gcnew System::EventHandler(this, &FrmInstructions::btnReturn_Click);
			// 
			// FrmInstructions
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1275, 800);
			this->Controls->Add(this->btnReturn);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"FrmInstructions";
			this->Text = L"FrmInstructions";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &FrmInstructions::FrmInstructions_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void FrmInstructions_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//Clear
		buffer->Graphics->Clear(Color::White);
		//Map
		buffer->Graphics->DrawImage(bmpBackgroundIns, 0, 0, this->Width, this->Height);
		buffer->Render(g);
	}

	private: System::Void btnReturn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
