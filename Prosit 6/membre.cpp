#include "pch.h"
#include "membre.h"

using namespace NS_Composants;

void membre::setDateEmbauche(String^ date_embauche) {
    this->date_embauche = date_embauche;
}

String^ membre::getDateEmbauche() {
    return date_embauche;
}

void membre::setAdresse(String^ adresse) {
    this->adresse_personnel = adresse;
}

String^ membre::getAdresse() {
    return adresse_personnel;
}

void membre::setIdSupHierarchique(int id_sup_hierarchique) {
    this->id_sup_hierarchique = id_sup_hierarchique;
}

void membre::setIdPersonnel(int id_Personnel) {
    this->id_personnel = id_Personnel;
}

int membre::getIdPersonnel() {
    return this->id_personnel;
}

int membre::getIdSupHierarchique() {
    return this->id_sup_hierarchique;
}



//A completer
String^ membre::Creer() {

    return "INSERT INTO Personnelle (nom, prenom, date_embauche, id_sup_hierarchique) VALUES ('" +
        this->getNom() + "', '" + this->getPrenom() + "', '" +
        Convert::ToDateTime(this->getDateEmbauche()) + "', " + this->getIdSupHierarchique() + "); "
        + "SELECT @@IDENTITY;";
}

String^ membre::Modifier() {
    // Supposons que les valeurs nécessaires sont déjà définies dans les membres de la classe.
    // Cette requête met à jour les informations d'un personnel dans la table Personnelle.

    return "UPDATE Personnelle SET nom = '" + this->getNom() +
        "', prenom = '" + this->getPrenom() +
        "', date_embauche = '" + this->getDateEmbauche() +
        "', id_sup_hierarchique = " + this->getIdSupHierarchique() +
        " WHERE id_personnel = " + this->getIdPersonnel() + ";";
}

String^ membre::Supprimer() {
    // Supposons que seul l'ID du personnel est nécessaire pour la suppression.
    // Cette requête supprime un personnel de la table Personnelle.

    return 
        "DELETE FROM Personnelle " +
        "WHERE(id_personnel = " + this->getIdPersonnel() + ");";
}

String^ membre::Afficher() {
    // Supposons que vous souhaitez simplement récupérer toutes les informations d'un personnel.
    // Cette requête sélectionne toutes les colonnes de la table Personnelle pour un personnel donné.

    return "SELECT * FROM Personnelle;";
}

