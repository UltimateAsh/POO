#pragma once
#include "pch.h"


namespace NS_Composants {
	ref class membre : public CL_mappTBPERSONNE {
	private:
		int id_personnel;
		String^ adresse_personnel;
		String^ date_embauche;
		membre^ sup_hier;
		int id_sup_hierarchique;

	public:
		void setIdSupHierarchique(int);
		void setIdPersonnel(int);
		int getIdPersonnel();
		void setDateEmbauche(String^);
		String^ getDateEmbauche();
		void setAdresse(String^ adresse);
		String^ getAdresse();
		int getIdSupHierarchique();

		virtual String^ Creer() override;
		virtual String^ Modifier() override;
		virtual String^ Supprimer() override;
		virtual String^ Afficher() override;
	};
};
