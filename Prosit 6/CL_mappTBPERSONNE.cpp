#include "CL_mappTBPERSONNE.h"
namespace NS_Composants

{
	CL_mappTBPERSONNE::CL_mappTBPERSONNE(void)
	{
		this->id_personne = -1;
		this->nom = "RIEN";
		this->prenom = "RIEN";
	}
	String^ CL_mappTBPERSONNE::SELECT(void)
	{
		return "SELECT id_personne, nom, prenom " +
			"FROM TB_PERSONNE;";
	}
	String^ CL_mappTBPERSONNE::INSERT(void)
	{
		return "INSERT INTO TB_PERSONNE " +
			"(nom, prenom, date_embauche, adresse_personnel, id_sup_hierarchique) " +
			"VALUES('" + this->getNom() + "', '" + this->getPrenom() + "', '" +
			this->getDateEmbauche() + "', '" + this->getAdresse() + "', " +
			this->getIdSupHierarchique() + "); SELECT SCOPE_IDENTITY();";
	}

	String^ CL_mappTBPERSONNE::UPDATE(void)
	{
		return "UPDATE TB_PERSONNE " +
			"SET nom = '" + this->getNom() + "', prenom = '" + this->getPrenom() + "', " +
			"date_embauche = '" + this->getDateEmbauche() + "', adresse_personnel = '" +
			this->getAdresse() + "', id_sup_hierarchique = " + this->getIdSupHierarchique() +
			" WHERE(id_personne = " + this->getId() + ");";
	}

	String^ CL_mappTBPERSONNE::DELETE(void)
	{
		return "DELETE FROM TB_ADRESSE WHERE (id_personne = " + this->getId() + "); " +
			"DELETE FROM TB_PERSONNE " +
			"WHERE(id_personne = " + this->getId() + ");";
	}

	void CL_mappTBPERSONNE::setID(int id_personne)
	{
		if (id_personne > 0)
		{
			this->id_personne = id_personne;
		}
	}
	void CL_mappTBPERSONNE::setPrenom(String^ prenom)
	{
		if (prenom != "")
		{
			this->prenom = prenom;
		}
	}
	void CL_mappTBPERSONNE::setNom(String^ nom)
	{
		if (nom != "")
		{
			this->nom = nom;
		}
	}
	int CL_mappTBPERSONNE::getId(void)
	{
		return this->id_personne;
	}
	String^ CL_mappTBPERSONNE::getNom(void)
	{
		return this->nom;
	}
	String^ CL_mappTBPERSONNE::getPrenom(void)
	{
		return this->prenom;
	}
	void CL_mappTBPERSONNE::setDateEmbauche(String^ date_embauche) {
		this->date_embauche = date_embauche;
	}

	String^ CL_mappTBPERSONNE::getDateEmbauche() {
		return date_embauche;
	}

	void CL_mappTBPERSONNE::setAdresse(String^ adresse) {
		this->adresse_personnel = adresse;
	}

	String^ CL_mappTBPERSONNE::getAdresse() {
		return adresse_personnel;
	}

	void CL_mappTBPERSONNE::setIdSupHierarchique(int id_sup_hierarchique) {
		this->id_sup_hierarchique = id_sup_hierarchique;
	}

	void CL_mappTBPERSONNE::setIdPersonnel(int id_Personnel) {
		this->id_personnel = id_Personnel;
	}

	int CL_mappTBPERSONNE::getIdPersonnel() {
		return this->id_personnel;
	}

	int CL_mappTBPERSONNE::getIdSupHierarchique() {
		return this->id_sup_hierarchique;
	}
}