#pragma once
#include "CL_CAD.h";
#include "CL_mappTBPERSONNE.h"
#include "CL_svc_gestionClient.h"
#include <iostream>

namespace EIA2MININFPOOP6 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace System::Xml;
	using namespace System::Text; // Pour utiliser la classe StringBuilder
	/// <summary>
	/// Description résumée de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}
	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_first;
	private: System::Windows::Forms::TextBox^ txt_id;
	private: System::Windows::Forms::TextBox^ txt_nom;
	private: System::Windows::Forms::Label^ lbl_id;
	private: System::Windows::Forms::Label^ lbl_nom;
	private: System::Windows::Forms::Label^ lbl_prenom;
	private: System::Windows::Forms::TextBox^ txt_prenom;
	private: System::Windows::Forms::Button^ btn_previous;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::DataGridView^ dgv_adresses;
	private: System::Windows::Forms::Label^ lbl_adresse;
	private: System::Windows::Forms::Button^ btn_nouveau;
	private: System::Windows::Forms::Button^ btn_maj;
	private: System::Windows::Forms::Button^ btn_sup;
	private: System::Windows::Forms::Button^ btn_enr;
	private: System::Windows::Forms::Label^ lbl_message;
	private: System::Windows::Forms::TextBox^ txt_message;
	private: NS_SVC::CL_svc_gestionClients^ gestionClients;
	private: DataSet^ dsPersonne;
	private: DataSet^ dsPersonneAdresses;
	private: String^ mode;
	private: int index;
	private: int rowsCount;
	private: int id;
	private: System::Windows::Forms::TextBox^ debugText;
	private: System::Windows::Forms::Label^ DebugBox;



		   /// <summary>
		   /// Variable nécessaire au concepteur.
/// </summary>
		   System::ComponentModel::Container^ components;
#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		   /// le contenu de cette méthode avec l'éditeur de code.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->btn_first = (gcnew System::Windows::Forms::Button());
			   this->txt_id = (gcnew System::Windows::Forms::TextBox());
			   this->txt_nom = (gcnew System::Windows::Forms::TextBox());
			   this->lbl_id = (gcnew System::Windows::Forms::Label());
			   this->lbl_nom = (gcnew System::Windows::Forms::Label());
			   this->lbl_prenom = (gcnew System::Windows::Forms::Label());
			   this->txt_prenom = (gcnew System::Windows::Forms::TextBox());
			   this->btn_previous = (gcnew System::Windows::Forms::Button());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->button3 = (gcnew System::Windows::Forms::Button());
			   this->dgv_adresses = (gcnew System::Windows::Forms::DataGridView());
			   this->lbl_adresse = (gcnew System::Windows::Forms::Label());
			   this->btn_nouveau = (gcnew System::Windows::Forms::Button());
			   this->btn_maj = (gcnew System::Windows::Forms::Button());
			   this->btn_sup = (gcnew System::Windows::Forms::Button());
			   this->btn_enr = (gcnew System::Windows::Forms::Button());
			   this->lbl_message = (gcnew System::Windows::Forms::Label());
			   this->txt_message = (gcnew System::Windows::Forms::TextBox());
			   this->debugText = (gcnew System::Windows::Forms::TextBox());
			   this->DebugBox = (gcnew System::Windows::Forms::Label());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_adresses))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // btn_first
			   // 
			   this->btn_first->Location = System::Drawing::Point(33, 242);
			   this->btn_first->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->btn_first->Name = L"btn_first";
			   this->btn_first->Size = System::Drawing::Size(60, 35);
			   this->btn_first->TabIndex = 0;
			   this->btn_first->Text = L"<<";
			   this->btn_first->UseVisualStyleBackColor = true;
			   this->btn_first->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			   // 
			   // txt_id
			   // 
			   this->txt_id->Location = System::Drawing::Point(33, 40);
			   this->txt_id->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->txt_id->Name = L"txt_id";
			   this->txt_id->ReadOnly = true;
			   this->txt_id->Size = System::Drawing::Size(265, 26);
			   this->txt_id->TabIndex = 1;
			   // 
			   // txt_nom
			   // 
			   this->txt_nom->Location = System::Drawing::Point(33, 109);
			   this->txt_nom->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->txt_nom->Name = L"txt_nom";
			   this->txt_nom->Size = System::Drawing::Size(265, 26);
			   this->txt_nom->TabIndex = 2;
			   // 
			   // lbl_id
			   // 
			   this->lbl_id->AutoSize = true;
			   this->lbl_id->Location = System::Drawing::Point(28, 15);
			   this->lbl_id->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->lbl_id->Name = L"lbl_id";
			   this->lbl_id->Size = System::Drawing::Size(23, 20);
			   this->lbl_id->TabIndex = 3;
			   this->lbl_id->Text = L"Id";
			   // 
			   // lbl_nom
			   // 
			   this->lbl_nom->AutoSize = true;
			   this->lbl_nom->Location = System::Drawing::Point(28, 85);
			   this->lbl_nom->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->lbl_nom->Name = L"lbl_nom";
			   this->lbl_nom->Size = System::Drawing::Size(42, 20);
			   this->lbl_nom->TabIndex = 4;
			   this->lbl_nom->Text = L"Nom";
			   // 
			   // lbl_prenom
			   // 
			   this->lbl_prenom->AutoSize = true;
			   this->lbl_prenom->Location = System::Drawing::Point(28, 158);
			   this->lbl_prenom->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->lbl_prenom->Name = L"lbl_prenom";
			   this->lbl_prenom->Size = System::Drawing::Size(64, 20);
			   this->lbl_prenom->TabIndex = 5;
			   this->lbl_prenom->Text = L"Prénom";
			   // 
			   // txt_prenom
			   // 
			   this->txt_prenom->Location = System::Drawing::Point(33, 183);
			   this->txt_prenom->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->txt_prenom->Name = L"txt_prenom";
			   this->txt_prenom->Size = System::Drawing::Size(265, 26);
			   this->txt_prenom->TabIndex = 6;
			   // 
			   // btn_previous
			   // 
			   this->btn_previous->Location = System::Drawing::Point(102, 242);
			   this->btn_previous->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->btn_previous->Name = L"btn_previous";
			   this->btn_previous->Size = System::Drawing::Size(60, 35);
			   this->btn_previous->TabIndex = 7;
			   this->btn_previous->Text = L"<";
			   this->btn_previous->UseVisualStyleBackColor = true;
			   this->btn_previous->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			   // 
			   // button2
			   // 
			   this->button2->Location = System::Drawing::Point(240, 242);
			   this->button2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(60, 35);
			   this->button2->TabIndex = 8;
			   this->button2->Text = L">>";
			   this->button2->UseVisualStyleBackColor = true;
			   this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			   // 
			   // button3
			   // 
			   this->button3->Location = System::Drawing::Point(171, 242);
			   this->button3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->button3->Name = L"button3";
			   this->button3->Size = System::Drawing::Size(60, 35);
			   this->button3->TabIndex = 9;
			   this->button3->Text = L">";
			   this->button3->UseVisualStyleBackColor = true;
			   this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			   // 
			   // dgv_adresses
			   // 
			   this->dgv_adresses->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dgv_adresses->Location = System::Drawing::Point(324, 37);
			   this->dgv_adresses->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->dgv_adresses->Name = L"dgv_adresses";
			   this->dgv_adresses->RowHeadersWidth = 82;
			   this->dgv_adresses->Size = System::Drawing::Size(556, 374);
			   this->dgv_adresses->TabIndex = 10;
			   // 
			   // lbl_adresse
			   // 
			   this->lbl_adresse->AutoSize = true;
			   this->lbl_adresse->Location = System::Drawing::Point(320, 12);
			   this->lbl_adresse->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->lbl_adresse->Name = L"lbl_adresse";
			   this->lbl_adresse->Size = System::Drawing::Size(76, 20);
			   this->lbl_adresse->TabIndex = 11;
			   this->lbl_adresse->Text = L"Adresses";
			   // 
			   // btn_nouveau
			   // 
			   this->btn_nouveau->Location = System::Drawing::Point(33, 286);
			   this->btn_nouveau->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->btn_nouveau->Name = L"btn_nouveau";
			   this->btn_nouveau->Size = System::Drawing::Size(129, 35);
			   this->btn_nouveau->TabIndex = 12;
			   this->btn_nouveau->Text = L"Nouveau";
			   this->btn_nouveau->UseVisualStyleBackColor = true;
			   this->btn_nouveau->Click += gcnew System::EventHandler(this, &MyForm::btn_nouveau_Click);
			   // 
			   // btn_maj
			   // 
			   this->btn_maj->Location = System::Drawing::Point(33, 331);
			   this->btn_maj->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->btn_maj->Name = L"btn_maj";
			   this->btn_maj->Size = System::Drawing::Size(129, 35);
			   this->btn_maj->TabIndex = 13;
			   this->btn_maj->Text = L"Mise à jour";
			   this->btn_maj->UseVisualStyleBackColor = true;
			   this->btn_maj->Click += gcnew System::EventHandler(this, &MyForm::btn_maj_Click);
			   // 
			   // btn_sup
			   // 
			   this->btn_sup->Location = System::Drawing::Point(33, 375);
			   this->btn_sup->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->btn_sup->Name = L"btn_sup";
			   this->btn_sup->Size = System::Drawing::Size(129, 35);
			   this->btn_sup->TabIndex = 14;
			   this->btn_sup->Text = L"Supprimer";
			   this->btn_sup->UseVisualStyleBackColor = true;
			   this->btn_sup->Click += gcnew System::EventHandler(this, &MyForm::btn_sup_Click);
			   // 
			   // btn_enr
			   // 
			   this->btn_enr->Location = System::Drawing::Point(171, 286);
			   this->btn_enr->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->btn_enr->Name = L"btn_enr";
			   this->btn_enr->Size = System::Drawing::Size(129, 125);
			   this->btn_enr->TabIndex = 15;
			   this->btn_enr->Text = L"Enregistrer";
			   this->btn_enr->UseVisualStyleBackColor = true;
			   this->btn_enr->Click += gcnew System::EventHandler(this, &MyForm::btn_enr_Click);
			   // 
			   // lbl_message
			   // 
			   this->lbl_message->AutoSize = true;
			   this->lbl_message->Location = System::Drawing::Point(28, 445);
			   this->lbl_message->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->lbl_message->Name = L"lbl_message";
			   this->lbl_message->Size = System::Drawing::Size(74, 20);
			   this->lbl_message->TabIndex = 16;
			   this->lbl_message->Text = L"Message";
			   // 
			   // txt_message
			   // 
			   this->txt_message->Location = System::Drawing::Point(33, 469);
			   this->txt_message->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->txt_message->Multiline = true;
			   this->txt_message->Name = L"txt_message";
			   this->txt_message->Size = System::Drawing::Size(846, 72);
			   this->txt_message->TabIndex = 17;
			   // 
			   // debugText
			   // 
			   this->debugText->Location = System::Drawing::Point(716, 429);
			   this->debugText->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->debugText->Name = L"debugText";
			   this->debugText->Size = System::Drawing::Size(163, 26);
			   this->debugText->TabIndex = 18;
			   // 
			   // DebugBox
			   // 
			   this->DebugBox->AutoSize = true;
			   this->DebugBox->Location = System::Drawing::Point(639, 434);
			   this->DebugBox->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->DebugBox->Name = L"DebugBox";
			   this->DebugBox->Size = System::Drawing::Size(65, 20);
			   this->DebugBox->TabIndex = 19;
			   this->DebugBox->Text = L"Debug :";
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(915, 562);
			   this->Controls->Add(this->DebugBox);
			   this->Controls->Add(this->debugText);
			   this->Controls->Add(this->txt_message);
			   this->Controls->Add(this->lbl_message);
			   this->Controls->Add(this->btn_enr);
			   this->Controls->Add(this->btn_sup);
			   this->Controls->Add(this->btn_maj);
			   this->Controls->Add(this->btn_nouveau);
			   this->Controls->Add(this->lbl_adresse);
			   this->Controls->Add(this->dgv_adresses);
			   this->Controls->Add(this->button3);
			   this->Controls->Add(this->button2);
			   this->Controls->Add(this->btn_previous);
			   this->Controls->Add(this->txt_prenom);
			   this->Controls->Add(this->lbl_prenom);
			   this->Controls->Add(this->lbl_nom);
			   this->Controls->Add(this->lbl_id);
			   this->Controls->Add(this->txt_nom);
			   this->Controls->Add(this->txt_id);
			   this->Controls->Add(this->btn_first);
			   this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			   this->Name = L"MyForm";
			   this->Text = L"MyForm";
			   this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_adresses))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->index = 0;
		this->txt_id->Text = Convert::ToString(this->dsPersonne->Tables["LesClients"]->Rows[this->index]->ItemArray[0]);
		this->txt_nom->Text = Convert::ToString(this->dsPersonne->Tables["LesClients"]->Rows[this->index]->ItemArray[1]);
		this->txt_prenom->Text = Convert::ToString(this->dsPersonne->Tables["LesClients"]->Rows[this->index]->ItemArray[2]);
		this->dsPersonneAdresses = this->gestionClients->adressesClient(Convert::ToInt32(this->txt_id->Text), "AdressesPersonnes");
		this->dgv_adresses->DataSource = this->dsPersonneAdresses;
		this->dgv_adresses->DataMember = "AdressesPersonnes";
		this->dgv_adresses->Columns["id_personne"]->Visible = false;
		this->dgv_adresses->Columns["id_adresse"]->Visible = false;
		this->txt_message->Text = "Chargement de l'enregistrement : " + (this->index + 1);
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		this->initialisationENR();
		this->txt_message->Text = "Cnx SQL SERVER ok \r\nEnregistrement chargés";
	}
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->index > 0)
		{
			this->index--;
			this->txt_id->Text = Convert::ToString(this->dsPersonne->Tables["LesClients"]->Rows[this->index]->ItemArray[0]);
			this->txt_nom->Text = Convert::ToString(this->dsPersonne->Tables["LesClients"]->Rows[this->index]->ItemArray[1]);
			this->txt_prenom->Text = Convert::ToString(this->dsPersonne->Tables["LesClients"]->Rows[this->index]->ItemArray[2]);
			this->dsPersonneAdresses = this->gestionClients->adressesClient(Convert::ToInt32(this->txt_id->Text), "AdressesPersonnes");
			this->dgv_adresses->DataSource = this->dsPersonneAdresses;
			this->dgv_adresses->DataMember = "AdressesPersonnes";
			this->dgv_adresses->Columns["id_personne"]->Visible = false;
			this->dgv_adresses->Columns["id_adresse"]->Visible = false;
			this->txt_message->Text = "Chargement de l'enregistrement : " + (this->index
				+ 1);
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->index < this->rowsCount - 1)
		{
			this->index++;
			this->txt_id->Text = Convert::ToString(this->dsPersonne->Tables["LesClients"]->Rows[this->index]->ItemArray[0]);
			this->txt_nom->Text = Convert::ToString(this->dsPersonne->Tables["LesClients"]->Rows[this->index]->ItemArray[1]);
			this->txt_prenom->Text = Convert::ToString(this->dsPersonne->Tables["LesClients"]->Rows[this->index]->ItemArray[2]);
			this->dsPersonneAdresses = this->gestionClients->adressesClient(Convert::ToInt32(this->txt_id->Text), "AdressesPersonnes");
			this->dgv_adresses->DataSource = this->dsPersonneAdresses;
			this->dgv_adresses->DataMember = "AdressesPersonnes";
			this->dgv_adresses->Columns["id_personne"]->Visible = false;
			this->dgv_adresses->Columns["id_adresse"]->Visible = false;
			this->txt_message->Text = "Chargement de l'enregistrement : " + (this->index + 1);
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->index = this->rowsCount - 1;
		this->txt_id->Text = Convert::ToString(this->dsPersonne->Tables["LesClients"]->Rows[this->index]->ItemArray[0]);
		this->txt_nom->Text = Convert::ToString(this->dsPersonne->Tables["LesClients"]->Rows[this->index]->ItemArray[1]);
		this->txt_prenom->Text = Convert::ToString(this->dsPersonne->Tables["LesClients"]->Rows[this->index]->ItemArray[2]);
		this->dsPersonneAdresses = this->gestionClients->adressesClient(Convert::ToInt32(this->txt_id->Text), "AdressesPersonnes");
		this->dgv_adresses->DataSource = this->dsPersonneAdresses;
		this->dgv_adresses->DataMember = "AdressesPersonnes";
		this->dgv_adresses->Columns["id_personne"]->Visible = false;
		this->dgv_adresses->Columns["id_adresse"]->Visible = false;
		this->txt_message->Text = "Chargement de l'enregistrement : " + (this->index + 1);
	}
	private: System::Void btn_nouveau_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->txt_id->Text = "";
		this->txt_nom->Text = "";
		this->txt_prenom->Text = "";
		this->dgv_adresses->DataSource = nullptr;
		this->dgv_adresses->Columns->Add("Adresse", "Adresse");
		this->dgv_adresses->Columns->Add("Ville", "Ville");
		this->dgv_adresses->Columns->Add("Cp", "Cp");
		this->txt_message->Text = "Veuillez saisir les renseignements avant d'enregister";
		this->mode = "nouveau";
	}
	private: System::Void btn_enr_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->mode == "nouveau")
		{
			int i;
			int ii;
			int taille = (this->dgv_adresses->RowCount - 1) * 3;
			array<String^>^ lesAdresses = gcnew array<String^>(taille);
			ii = 0;
			for (i = 0; i < taille - 1; i++)
			{
				lesAdresses[i] = Convert::ToString(this->dgv_adresses[0, ii]->Value);
				i++;
				lesAdresses[i] = Convert::ToString(this->dgv_adresses[1, ii]->Value);
				i++;
				lesAdresses[i] = Convert::ToString(this->dgv_adresses[2, ii]->Value);
				ii++;
				lesAdresses[i] = Convert::ToString(this->dgv_adresses[3, ii]->Value);
				ii++;
				lesAdresses[i] = Convert::ToString(this->dgv_adresses[4, ii]->Value);
				ii++;
				lesAdresses[i] = Convert::ToString(this->dgv_adresses[5, ii]->Value);
				ii++;
			}
			this->gestionClients->ajouter(lesAdresses);
		}
		else if (this->mode == "supprimer")
		{
			this->gestionClients->supprimer(id);
		}
		else if (this->mode == "maj")
		{
			int i;
			int ii;
			int taille = (this->dgv_adresses->RowCount - 1) * 4;
			array<String^>^ lesAdresses = gcnew array<String^>(taille);
			ii = 0;
			this->dgv_adresses->Columns["id_adresse"]->Visible = true;
			
			for (i = 0; i < taille - 1; i++)
			{
				lesAdresses[i] = Convert::ToString(this->dgv_adresses[0, ii]->Value);
				i++;
				lesAdresses[i] = Convert::ToString(this->dgv_adresses[1, ii]->Value);
				i++;
				lesAdresses[i] = Convert::ToString(this->dgv_adresses[2, ii]->Value);
				i++;
				lesAdresses[i] = Convert::ToString(this->dgv_adresses[3, ii]->Value);
				ii++;
			}

			/////////////////////////
			// Utilisation de StringBuilder pour concaténer les éléments du tableau en une seule chaîne
			StringBuilder^ resultat = gcnew StringBuilder();
			for (int i = 0; i < taille; ++i)
			{
				resultat->Append(lesAdresses[i]);
				// Ajouter une virgule et un espace si ce n'est pas le dernier élément
				if (i < taille - 1)
				{
					resultat->Append(", ");
				}
			}
			/////////////////////////
			this->debugText->Text = resultat->ToString();
			//this->gestionClients->modifier(Convert::ToInt32(this->txt_id->Text), this->txt_nom->Text, this->txt_prenom->Text, lesAdresses);
		}
		this->initialisationENR();
	}
	private: System::Void btn_sup_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->id = Convert::ToInt32(this->txt_id->Text);
		this->mode = "supprimer";
		this->txt_id->Text = "";
		this->txt_nom->Text = "";
		this->txt_prenom->Text = "";
		this->dgv_adresses->DataSource = nullptr;
		this->txt_message->Text = "L'enregistrement a été supprimer.";
	}
	private: void initialisationENR(void)
	{
		this->gestionClients = gcnew NS_SVC::CL_svc_gestionClients();
		this->dgv_adresses->Columns->Clear();
		this->dsPersonne = this->gestionClients->listeClients("LesClients");
		this->rowsCount = this->dsPersonne->Tables["LesClients"]->Rows->Count;
		this->index = 0;
		this->txt_id->Text = Convert::ToString(this->dsPersonne->Tables["LesClients"]->Rows[0]->ItemArray[0]);
		this->txt_nom->Text = Convert::ToString(this->dsPersonne->Tables["LesClients"]->Rows[0]->ItemArray[1]);
		this->txt_prenom->Text = Convert::ToString(this->dsPersonne->Tables["LesClients"]->Rows[0]->ItemArray[2]);
		this->dsPersonneAdresses = this->gestionClients->adressesClient(Convert::ToInt32(this->txt_id->Text), "AdressesPersonnes");
		this->dgv_adresses->DataSource = this->dsPersonneAdresses;
		this->dgv_adresses->DataMember = "AdressesPersonnes";
		//this->dgv_adresses->Columns["id_personne"]->Visible = false;
		//this->dgv_adresses->Columns["id_adresse"]->Visible = false;
		this->txt_message->Text = "Chargement de l'enregistrement : " + (this->index + 1);
	}
	private: System::Void btn_maj_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->mode = "maj";
		this->txt_message->Text = "Enregistrement en attente de validation";
	}
	//private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	//}
};
}