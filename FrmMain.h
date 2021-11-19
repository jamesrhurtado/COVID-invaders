#pragma once
#include "Controller.h"
#include "File.h"


namespace FinalProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmMain
	/// </summary>
	public ref class FrmMain : public System::Windows::Forms::Form
	{
	public:
		FrmMain(int nCitizens, int nVirus, String^ name, int lvl) {
			InitializeComponent();
			srand(time(NULL));
			//Buffer
			g = this->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, this->ClientRectangle);

			//Controller
			_game = new Controller(nCitizens, nVirus, lvl);

			//Bitmap
			bmpCitizen = gcnew Bitmap("images//citizen.png");
			bmpMask = gcnew Bitmap("images//mask.png");
			bmpNurse = gcnew Bitmap("images//nurse.png");
			bmpVax = gcnew Bitmap("images//vax.png");
			bmpVirus = gcnew Bitmap("images//virus.png");
			bmpMap = gcnew Bitmap("images//background_lvl1.jpg");
			bmpInfected = gcnew Bitmap("images//zombie.png");
			bmpCitizenMask = gcnew Bitmap("images//citizen_mask.png");
			bmpCitizenVax = gcnew Bitmap("images//citizen_vax.png");
			

			//time
			timeMaskGame = time(0);
			timeVaxGame = time(0);
			timeGame = time(0);

			//score
			score = 0;
			this->lvl = lvl;
			//string and data
			playerName = name;
			citizens = nCitizens;
			virus = nVirus;

			file = new File();

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmMain()
		{
			if (components)
			{
				delete components;
				delete _game, bmpCitizen, bmpMask, bmpNurse, bmpVax, bmpVirus, bmpMap;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;


		//Bitmap
		Bitmap^ bmpMask;
		Bitmap^ bmpVax;
		Bitmap^ bmpCitizen;
		Bitmap^ bmpNurse;
		Bitmap^ bmpVirus;
		Bitmap^ bmpMap;
		Bitmap^ bmpInfected;
		Bitmap^ bmpCitizenMask;
		Bitmap^ bmpCitizenVax;
		

		//Time
		time_t timeMaskGame;
		time_t timeVaxGame;
		time_t timeGame;

		//score
		int score;
		int citizens;
		int virus;
		int lvl;

		//controller
		Controller* _game;

		//additional
		String^ playerName;
		File* file;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmMain::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmMain::timer1_Tick);
			// 
			// FrmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(683, 441);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"FrmMain";
			this->Text = L"COVID invaders";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMain::FrmMain_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		
		//Clear
		buffer->Graphics->Clear(Color::White);

		//Map
		buffer->Graphics->DrawImage(bmpMap, 0, 0, this->Width, this->Height);

		//mask and vax appear each 3 and 5 seconds respectively

		
		if ((difftime(time(0), timeMaskGame)) > 3) {
			_game->addMask();
			timeMaskGame = time(0);
		}
		if ((difftime(time(0), timeVaxGame)) > 5) {
			_game->addVax();
			timeVaxGame = time(0);
		}
		
		//Sprites
		_game->drawNurse(buffer->Graphics, bmpNurse);
		_game->drawElements(buffer->Graphics, bmpMask, bmpVax);
		_game->drawVirus(buffer->Graphics, bmpVirus);
		_game->drawCitizens(buffer->Graphics, bmpCitizen, bmpInfected, bmpCitizenMask, bmpCitizenVax);

		//interaction
		_game->useElements();
		_game->infectCitizens();
		_game->spreadAmongCitizens();

		if (difftime(time(0), timeGame) >= 100 || _game->getNDeaths() >= citizens || _game->getNVaccinated() >= citizens || _game->getNVaccinated() >= (citizens -_game->getNDeaths())) {
			//fnal counting
			_game->countResults();
			score = ((_game->getNVaccinated() * 10) + (_game->getNSurvivors() * 5) - (_game->getNDeaths() * 5));
			if (_game->getNVaccinated() >= citizens) {
				timer1->Enabled = false;
				MessageBox::Show(" All citizens where vaccinated! Score: " + score);
			}
			if (_game->getNDeaths() >= citizens) {
				timer1->Enabled = false;
				MessageBox::Show(" All citizens are dead! Score:: " + score);
			}

			if (difftime(time(0), timeGame) >= 100) {
				timer1->Enabled = false;
				MessageBox::Show(" Time's  up. Score: " + score);
			}
			else if(_game->getNVaccinated() >= (citizens - _game->getNDeaths())) {
				timer1->Enabled = false;
				MessageBox::Show(" Game over. Score: " + score);
			}

			//code from the C programming language
			//array of chars
			char aux[100];
			//stores the array in aux
			sprintf(aux, "%s", playerName);
			vector<string> data;
			data.push_back(aux);
			data.push_back(std::to_string(citizens));
			data.push_back(std::to_string(virus));
			data.push_back(std::to_string(score));
			file->writeData(data);
			this->Visible = false;
		}

		//Render
		buffer->Render(g);


	}
	private: System::Void FrmMain_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		
		switch (e->KeyCode)
		{
		case Keys::A: case Keys::Left:
			_game->moveNurse(buffer->Graphics, 'A'); break;
		case Keys::D: case Keys::Right:
			_game->moveNurse(buffer->Graphics, 'D'); break;
		case Keys::W: case Keys::Up:
			_game->moveNurse(buffer->Graphics, 'W'); break;
		case Keys::S: case Keys::Down:
			_game->moveNurse(buffer->Graphics, 'S'); break;
			//press space to capture an element
		case Keys::Space:
			_game->captureElements(); break;
		}
	}
};
}
