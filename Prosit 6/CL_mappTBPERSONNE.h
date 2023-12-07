#pragma once
using namespace System;
namespace NS_Composants
{
	ref class CL_mappTBPERSONNE
	{
	private:
		int id_personne;
		String^ nom;
		String^ prenom;
		int id_personnel;
		String^ adresse_personnel;
		String^ date_embauche;
		CL_mappTBPERSONNE^ sup_hier;
		int id_sup_hierarchique;
	public:
		CL_mappTBPERSONNE(void);
		String^ SELECT(void);
		String^ INSERT(void);
		String^ UPDATE(void);
		String^ DELETE(void);
		void setID(int);
		void setPrenom(String^);
		void setNom(String^);
		int getId(void);
		String^ getNom(void);
		String^ getPrenom(void);
		void setIdSupHierarchique(int);
		void setIdPersonnel(int);
		int getIdPersonnel();
		void setDateEmbauche(String^);
		String^ getDateEmbauche();
		void setAdresse(String^ adresse);
		String^ getAdresse();
		int getIdSupHierarchique();
	};
}