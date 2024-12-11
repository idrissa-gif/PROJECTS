#pragma once

namespace Graphic {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		MySqlConnection^ Tsqlconn = gcnew MySqlConnection();
		MySqlCommand^ Tsqlcom = gcnew MySqlCommand();
		MySqlDataAdapter^ TsqldtA = gcnew MySqlDataAdapter();
		DataTable^ Tsqldt = gcnew DataTable();
		MySqlConnection^ Ssqlconn = gcnew MySqlConnection();
		MySqlCommand^ Ssqlcom = gcnew MySqlCommand();
		MySqlDataAdapter^ SsqldtA = gcnew MySqlDataAdapter();
		DataTable^ Ssqldt = gcnew DataTable();





	private: System::Windows::Forms::Button^ btnupdatescore;
	private: System::Windows::Forms::Button^ btnreset;

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::TextBox^ hometeamtextbox;
	private: System::Windows::Forms::Label^ hometeamlabel;
	private: System::Windows::Forms::TextBox^ homegoaltextbox;
	private: System::Windows::Forms::Label^ homegoallabel;
	private: System::Windows::Forms::TextBox^ awayteamtextbox;
	private: System::Windows::Forms::Label^ awayteamlabel;
	private: System::Windows::Forms::TextBox^ awaygoaltextbox;
	private: System::Windows::Forms::Label^ awaygoallabel;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ exitbtn;







		   MySqlDataReader^ TsqlRed;
		   MySqlDataReader^ SsqlRed;
	public:
		MyForm(void)
		{
			InitializeComponent();
			Database();
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


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnupdatescore = (gcnew System::Windows::Forms::Button());
			this->btnreset = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->hometeamtextbox = (gcnew System::Windows::Forms::TextBox());
			this->hometeamlabel = (gcnew System::Windows::Forms::Label());
			this->homegoaltextbox = (gcnew System::Windows::Forms::TextBox());
			this->homegoallabel = (gcnew System::Windows::Forms::Label());
			this->awayteamtextbox = (gcnew System::Windows::Forms::TextBox());
			this->awayteamlabel = (gcnew System::Windows::Forms::Label());
			this->awaygoaltextbox = (gcnew System::Windows::Forms::TextBox());
			this->awaygoallabel = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->exitbtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnupdatescore
			// 
			this->btnupdatescore->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnupdatescore->Location = System::Drawing::Point(491, 603);
			this->btnupdatescore->Name = L"btnupdatescore";
			this->btnupdatescore->Size = System::Drawing::Size(236, 48);
			this->btnupdatescore->TabIndex = 3;
			this->btnupdatescore->Text = L"Update Score";
			this->btnupdatescore->UseVisualStyleBackColor = true;
			this->btnupdatescore->Click += gcnew System::EventHandler(this, &MyForm::btnupdatescore_Click);
			// 
			// btnreset
			// 
			this->btnreset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnreset->Location = System::Drawing::Point(232, 603);
			this->btnreset->Name = L"btnreset";
			this->btnreset->Size = System::Drawing::Size(190, 48);
			this->btnreset->TabIndex = 4;
			this->btnreset->Text = L"Reset";
			this->btnreset->UseVisualStyleBackColor = true;
			this->btnreset->Click += gcnew System::EventHandler(this, &MyForm::btnreset_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 20);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->Size = System::Drawing::Size(517, 513);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellClick);
			// 
			// hometeamtextbox
			// 
			this->hometeamtextbox->Location = System::Drawing::Point(932, 172);
			this->hometeamtextbox->Name = L"hometeamtextbox";
			this->hometeamtextbox->Size = System::Drawing::Size(295, 20);
			this->hometeamtextbox->TabIndex = 1;
			// 
			// hometeamlabel
			// 
			this->hometeamlabel->AutoSize = true;
			this->hometeamlabel->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->hometeamlabel->Location = System::Drawing::Point(819, 178);
			this->hometeamlabel->Name = L"hometeamlabel";
			this->hometeamlabel->Size = System::Drawing::Size(74, 13);
			this->hometeamlabel->TabIndex = 2;
			this->hometeamlabel->Text = L"Home Team";
			// 
			// homegoaltextbox
			// 
			this->homegoaltextbox->Location = System::Drawing::Point(932, 232);
			this->homegoaltextbox->Name = L"homegoaltextbox";
			this->homegoaltextbox->Size = System::Drawing::Size(295, 20);
			this->homegoaltextbox->TabIndex = 3;
			// 
			// homegoallabel
			// 
			this->homegoallabel->AutoSize = true;
			this->homegoallabel->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->homegoallabel->Location = System::Drawing::Point(819, 238);
			this->homegoallabel->Name = L"homegoallabel";
			this->homegoallabel->Size = System::Drawing::Size(69, 13);
			this->homegoallabel->TabIndex = 4;
			this->homegoallabel->Text = L"Home Goal";
			// 
			// awayteamtextbox
			// 
			this->awayteamtextbox->Location = System::Drawing::Point(932, 290);
			this->awayteamtextbox->Name = L"awayteamtextbox";
			this->awayteamtextbox->Size = System::Drawing::Size(295, 20);
			this->awayteamtextbox->TabIndex = 5;
			// 
			// awayteamlabel
			// 
			this->awayteamlabel->AutoSize = true;
			this->awayteamlabel->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->awayteamlabel->Location = System::Drawing::Point(819, 296);
			this->awayteamlabel->Name = L"awayteamlabel";
			this->awayteamlabel->Size = System::Drawing::Size(72, 13);
			this->awayteamlabel->TabIndex = 6;
			this->awayteamlabel->Text = L"Away Team";
			// 
			// awaygoaltextbox
			// 
			this->awaygoaltextbox->Location = System::Drawing::Point(932, 366);
			this->awaygoaltextbox->Name = L"awaygoaltextbox";
			this->awaygoaltextbox->Size = System::Drawing::Size(295, 20);
			this->awaygoaltextbox->TabIndex = 7;
			// 
			// awaygoallabel
			// 
			this->awaygoallabel->AutoSize = true;
			this->awaygoallabel->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->awaygoallabel->Location = System::Drawing::Point(819, 372);
			this->awaygoallabel->Name = L"awaygoallabel";
			this->awaygoallabel->Size = System::Drawing::Size(67, 13);
			this->awaygoallabel->TabIndex = 8;
			this->awaygoallabel->Text = L"Away Goal";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->panel1->Controls->Add(this->awaygoallabel);
			this->panel1->Controls->Add(this->awaygoaltextbox);
			this->panel1->Controls->Add(this->awayteamlabel);
			this->panel1->Controls->Add(this->awayteamtextbox);
			this->panel1->Controls->Add(this->homegoallabel);
			this->panel1->Controls->Add(this->homegoaltextbox);
			this->panel1->Controls->Add(this->hometeamlabel);
			this->panel1->Controls->Add(this->hometeamtextbox);
			this->panel1->Controls->Add(this->dataGridView1);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1478, 585);
			this->panel1->TabIndex = 2;
			// 
			// exitbtn
			// 
			this->exitbtn->BackColor = System::Drawing::Color::Red;
			this->exitbtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exitbtn->Location = System::Drawing::Point(786, 603);
			this->exitbtn->Name = L"exitbtn";
			this->exitbtn->Size = System::Drawing::Size(143, 48);
			this->exitbtn->TabIndex = 7;
			this->exitbtn->Text = L"EXIT";
			this->exitbtn->UseVisualStyleBackColor = false;
			this->exitbtn->Click += gcnew System::EventHandler(this, &MyForm::exitbtn_Click_1);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1370, 749);
			this->Controls->Add(this->exitbtn);
			this->Controls->Add(this->btnreset);
			this->Controls->Add(this->btnupdatescore);
			this->Controls->Add(this->panel1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name = L"MyForm";
			this->Text = L"Team Data Viewer";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void RefreshDB_M()
	{
		try
		{
			Tsqlconn->ConnectionString = "datasource = localhost; port = 3306; username = root; password = test123; database = leaguedb";
			Tsqlcom->Connection = Tsqlconn;
			MySqlDataAdapter^ MsqldtA = gcnew MySqlDataAdapter("select * from fixturedb ORDER BY RAND()", Tsqlconn);
			DataTable^ Msqldt = gcnew DataTable();
			MsqldtA->Fill(Msqldt);
			dataGridView1->DataSource = Msqldt;
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message, "Data Entry Form", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	private: System::Void Database()
	{
		try
		{
			Tsqlconn->ConnectionString = "datasource = localhost; port = 3306; username = root; password = test123; database = leaguedb";
			Tsqlconn->Open();
			Tsqlcom->Connection = Tsqlconn;
			Tsqlcom->CommandText = "select * from fixturedb ORDER BY RAND()";
			TsqlRed = Tsqlcom->ExecuteReader();
			Tsqldt->Load(TsqlRed);
			TsqlRed->Close();
			Tsqlconn->Close();
			dataGridView1->DataSource = Tsqldt;
		}
		catch (MySqlException^ ex)
		{
			MessageBox::Show(ex->Message, "Data Entry Form", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}

	private: System::Void exitbtn_Click_1(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			System::Windows::Forms::DialogResult Exit;
			Exit = MessageBox::Show("Conform if you want to exit", "Exit", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
			if (Exit == System::Windows::Forms::DialogResult::Yes)
			{
				Application::Exit();
			}
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message, "Exit", MessageBoxButtons::YesNo, MessageBoxIcon::Information);
		}
	}
	private: System::Void btnupdatescore_Click(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			Tsqlconn->ConnectionString = "datasource = localhost; port = 3306; username = root; password = test123; database = leaguedb";
			Tsqlcom->Connection = Tsqlconn;
			Tsqlconn->Open();
			Ssqlconn->ConnectionString = "datasource = localhost; port = 3306; username = root; password = test123; database = leaguedb";
			Ssqlcom->Connection = Ssqlconn;
			Ssqlconn->Open();
			String^ hometeam = hometeamtextbox->Text;
			String^ homegoal = homegoaltextbox->Text;
			String^ awayteam = awayteamtextbox->Text;
			String^ awaygoal = awaygoaltextbox->Text;
			Int32 hgoal = Convert::ToInt32(homegoal);
			Int32 agoal = Convert::ToInt32(awaygoal);
			Tsqlcom->CommandText = "update fixturedb set homegoal = '" + homegoal + "', awaygoal ='" + awaygoal + "' where hometeam = '" + hometeam + "' and awayteam = '" + awayteam + "'", Tsqlconn;
			TsqlRed = Tsqlcom->ExecuteReader();
			Tsqlconn->Close();
			if (hgoal > agoal)
			{
				Ssqlcom->CommandText = "update standings set MatchPlayed = MatchPlayed + '" + 1 + "', Wins = Wins + '" + 1 + "' , Goalscored = Goalscored + '" + homegoal + "' , Goalsconceded = Goalsconceded + '" + awaygoal + "', Goaldifference = Goaldifference + '" + hgoal + "' - '" + agoal + "' , Points = Points +'" + 3 + "' where TeamName = '" + hometeam + "' ", Ssqlconn;
				SsqlRed = Ssqlcom->ExecuteReader();
				Ssqlconn->Close();
				Ssqlconn->Open();
				Ssqlcom->CommandText = "update standings set MatchPlayed = MatchPlayed + '" + 1 + "', Losses = Losses + '" + 1 + "' , Goalscored = Goalscored + '" + awaygoal + "' , Goalsconceded = Goalsconceded + '" + homegoal + "', Goaldifference = Goaldifference + '" + agoal + "' - '" + hgoal + "' where TeamName = '" + awayteam + "' ", Ssqlconn;
				SsqlRed = Ssqlcom->ExecuteReader();
				Ssqlconn->Close();
			}
			else if (hgoal < agoal)
			{
				Ssqlcom->CommandText = "update standings set MatchPlayed = MatchPlayed + '" + 1 + "', Losses = Losses + '" + 1 + "' , Goalscored = Goalscored + '" + homegoal + "' , Goalsconceded = Goalsconceded + '" + awaygoal + "', Goaldifference = Goaldifference + '" + hgoal + "' - '" + agoal + "' where TeamName = '" + hometeam + "' ", Ssqlconn;
				SsqlRed = Ssqlcom->ExecuteReader();
				Ssqlconn->Close();
				Ssqlconn->Open();
				Ssqlcom->CommandText = "update standings set MatchPlayed = MatchPlayed + '" + 1 + "', Wins = Wins + '" + 1 + "' , Goalscored = Goalscored + '" + awaygoal + "' , Goalsconceded = Goalsconceded + '" + homegoal + "', Goaldifference = Goaldifference + '" + agoal + "' - '" + hgoal + "' , Points = Points +'" + 3 + "'  where TeamName = '" + awayteam + "' ", Ssqlconn;
				SsqlRed = Ssqlcom->ExecuteReader();
				Ssqlconn->Close();
			}
			else
			{
				Ssqlcom->CommandText = "update standings set MatchPlayed = MatchPlayed + '" + 1 + "', Draws = Draws + '" + 1 + "',  Goalscored = Goalscored + '" + homegoal + "' , Goalsconceded = Goalsconceded + '" + awaygoal + "', Points = Points +'" + 1 + "' where TeamName = '" + hometeam + "' ", Ssqlconn;
				SsqlRed = Ssqlcom->ExecuteReader();
				Ssqlconn->Close();
				Ssqlconn->Open();
				Ssqlcom->CommandText = "update standings set MatchPlayed = MatchPlayed + '" + 1 + "', Wins = Wins + '" + 1 + "' ,  Goalscored = Goalscored + '" + awaygoal + "' , Goalsconceded = Goalsconceded + '" + homegoal + "',  Points = Points +'" + 1 + "'  where TeamName = '" + awayteam + "' ", Ssqlconn;
				SsqlRed = Ssqlcom->ExecuteReader();
				Ssqlconn->Close();
			}

			Database();
			RefreshDB_M();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		try
		{
			hometeamtextbox->Text = dataGridView1->SelectedRows[0]->Cells[0]->Value->ToString();
			homegoaltextbox->Text = dataGridView1->SelectedRows[0]->Cells[1]->Value->ToString();
			awayteamtextbox->Text = dataGridView1->SelectedRows[0]->Cells[2]->Value->ToString();
			awaygoaltextbox->Text = dataGridView1->SelectedRows[0]->Cells[3]->Value->ToString();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message, "Data Entry Form", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	private: System::Void btnreset_Click(System::Object^ sender, System::EventArgs^ e) {
		hometeamtextbox->Text = "";
		homegoaltextbox->Text = "";
		awayteamtextbox->Text = "";
		awaygoaltextbox->Text = "";
	}

	};
}
