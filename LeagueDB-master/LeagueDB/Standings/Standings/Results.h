#pragma once

namespace Standings {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for Results
	/// </summary>
	public ref class Results : public System::Windows::Forms::Form
	{
	public:
		MySqlConnection^ Ssqlconn = gcnew MySqlConnection();
		MySqlCommand^ Ssqlcom = gcnew MySqlCommand();
		MySqlDataAdapter^ SsqldtA = gcnew MySqlDataAdapter();
		DataTable^ Ssqldt = gcnew DataTable();

		MySqlDataReader^ SsqlRed;
		Results(void)
		{
			InitializeComponent();
			Database();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Results()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::Info;
			this->panel1->Controls->Add(this->dataGridView1);
			this->panel1->Location = System::Drawing::Point(1, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1309, 560);
			this->panel1->TabIndex = 0;
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::Info;
			this->dataGridView1->GridColor = System::Drawing::SystemColors::Info;
			this->dataGridView1->ImeMode = System::Windows::Forms::ImeMode::On;
			this->dataGridView1->Location = System::Drawing::Point(3, 3);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(955, 366);
			this->dataGridView1->TabIndex = 0;
			// 
			// Results
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(971, 393);
			this->Controls->Add(this->panel1);
			this->Name = L"Results";
			this->Text = L"Results";
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}

#pragma endregion
	private: System::Void Database()
	{
		try
		{
			Ssqlconn->ConnectionString = "datasource = localhost; port = 3306; username = root; password = test123; database = leaguedb";
			Ssqlconn->Open();
			Ssqlcom->Connection = Ssqlconn;
			Ssqlcom->CommandText = "select * from standings ORDER BY  Points desc, Goaldifference desc, Goalscored desc , Wins desc";
			SsqlRed = Ssqlcom->ExecuteReader();
			Ssqldt->Load(SsqlRed);
			SsqlRed->Close();
			Ssqlconn->Close();
			dataGridView1->DataSource = Ssqldt;
		}
		catch (MySqlException^ ex)
		{
			MessageBox::Show(ex->Message, "Data Entry Form", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}

	};
}
