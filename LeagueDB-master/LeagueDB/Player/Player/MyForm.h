#pragma once

namespace Player {

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
	private: System::Windows::Forms::Panel^ panel1;
		   MySqlDataReader^ TsqlRed;
	public:
		MyForm(void)
		{
			InitializeComponent();
			PlayerDatabase();
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
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ exitbtn;
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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->exitbtn = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(90, 25);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(994, 513);
			this->dataGridView1->TabIndex = 0;
			// 
			// exitbtn
			// 
			this->exitbtn->BackColor = System::Drawing::Color::Red;
			this->exitbtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exitbtn->Location = System::Drawing::Point(644, 628);
			this->exitbtn->Name = L"exitbtn";
			this->exitbtn->Size = System::Drawing::Size(128, 48);
			this->exitbtn->TabIndex = 1;
			this->exitbtn->Text = L"EXIT";
			this->exitbtn->UseVisualStyleBackColor = false;
			this->exitbtn->Click += gcnew System::EventHandler(this, &MyForm::exitbtn_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->panel1->Controls->Add(this->dataGridView1);
			this->panel1->Location = System::Drawing::Point(77, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1192, 585);
			this->panel1->TabIndex = 2;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1370, 739);
			this->Controls->Add(this->exitbtn);
			this->Controls->Add(this->panel1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name = L"MyForm";
			this->Text = L"Player Data Viewer";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void PlayerDatabase()
	{
		try
		{
			Tsqlconn->ConnectionString = "datasource = localhost; port = 3306; username = root; password = test123; database = leaguedb";
			Tsqlconn->Open();
			Tsqlcom->Connection = Tsqlconn;
			Tsqlcom->CommandText = "select * from playerdb";
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
	private: System::Void exitbtn_Click(System::Object^ sender, System::EventArgs^ e) {
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
	};
}
