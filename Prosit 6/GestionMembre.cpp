#include "pch.h"
#include "GestionMembre.h" // Assurez-vous d'inclure le bon fichier d'en-tête ici

namespace NS_SVC
{
    GestionMembre::GestionMembre(void)
    {
        this->cad = gcnew NS_Composants::CLCAD();
        this->personnel = gcnew NS_Composants::membre();
        this->adresse = gcnew NS_Composants::Adresse();
    }

    DataSet^ GestionMembre::listemembre(String^ dataTableName)
    {
        this->ds = gcnew DataSet();
        // Assurez-vous que la méthode getRows existe dans la classe CLCAD
        this->ds = this->cad->getRows(this->personnel->Afficher(), dataTableName);
        return this->ds;
    }


    void GestionMembre::ajouter(array<String^>^ lesPersonnels)
    {
        int id = this->cad->actionRowsID(this->personnel->Creer());
        this->personnel->setIdPersonnel(id);
        this->personnel->setPrenom(lesPersonnels[1]);
        this->personnel->setNom(lesPersonnels[2]);
        this->personnel->setDateEmbauche(lesPersonnels[3]);
        this->personnel->setIdSupHierarchique(Convert::ToInt32(lesPersonnels[4]));
        this->cad->actionRows(this->personnel->Modifier());
    }

    array<int>^ GestionMembre::GetAvailableIDs()
    {
        System::Collections::ArrayList^ availableIDs = gcnew System::Collections::ArrayList();

        this->ds = gcnew DataSet();
        this->ds = this->cad->getRows(this->personnel->Afficher(), "LesPersonnels");

        for each (DataRow ^ row in this->ds->Tables["LesPersonnels"]->Rows)
        {
            int id = Convert::ToInt32(row["id_personnel"]);
            availableIDs->Add(id);
        }

        return (array<int>^)availableIDs->ToArray(Type::GetType("System.Int32"));
    }


    void GestionMembre::modifier(int id, String^ nom, String^ prenom, array<String^>^ lesPersonnels)
    {
        int i;
        this->personnel->setIdPersonnel(id);
        this->personnel->setNom(nom);
        this->personnel->setPrenom(prenom);
        this->cad->actionRows(this->personnel->Modifier());
        for (i = 0; i < lesPersonnels->Length - 2; i++) // Modification de la condition ici
        {
            this->adresse->setIdAdresse(Convert::ToInt32(lesPersonnels[i])); i++;
            this->adresse->setAdresse(lesPersonnels[i]); i++;
            this->adresse->setVille(lesPersonnels[i]); i++;
            this->adresse->setCp(lesPersonnels[i]);
            this->cad->actionRows(this->adresse->UPDATE());
        }
    }

    void GestionMembre::supprimer(int id)
    {
        this->personnel->setIdPersonnel(id);
        this->cad->actionRows(this->personnel->Supprimer());
    }
}
