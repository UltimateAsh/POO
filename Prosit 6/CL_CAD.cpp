#include "CL_CAD.h"
namespace NS_Composants
{
	//Si tout ça n'est pas clair, on en reparle à mon retour. Bon courage à vous.
	CL_CAD::CL_CAD(void)
	{
		this->rq_sql = "RIEN"; //ou ""
		this->cnx = "Data Source=LAPTOP-ACHRAF;Initial Catalog=prosit;Integrated Security=True;Encrypt=False";
		this->CNX = gcnew SqlConnection(this->cnx);
		this->CMD = gcnew SqlCommand(this->rq_sql, this->CNX);
		this->CMD->CommandType = CommandType::Text;
	}


	// Méthode pour exécuter une requête SQL et retourner une valeur (typiquement un ID)
	int CL_CAD::actionRowsID(String^ rq_sql)
	{
		// Déclaration d'une variable pour stocker l'ID
		int id;

		// Appel de la méthode setSQL pour définir la requête SQL à exécuter
		this->setSQL(rq_sql);

		// Attribution de la requête SQL à la propriété CommandText de l'objet SqlCommand
		this->CMD->CommandText = this->rq_sql;

		// Ouverture de la connexion à la base de données
		this->CNX->Open();

		// Exécution de la requête SQL et récupération du résultat sous forme scalaire (une valeur unique)
		// Cette valeur est généralement utilisée pour récupérer un identifiant (ID) après une insertion
		id = Convert::ToInt32(this->CMD->ExecuteScalar());

		// Fermeture de la connexion à la base de données
		this->CNX->Close();

		// Retour de l'ID obtenu après l'exécution de la requête SQL
		return id;
	}


	// Méthode pour exécuter une requête SQL qui ne retourne pas de résultat (INSERT, UPDATE, DELETE, etc.)
	void CL_CAD::actionRows(String^ rq_sql)
	{
		// Appel de la méthode setSQL pour définir la requête SQL à exécuter
		this->setSQL(rq_sql);

		// Attribution de la requête SQL à la propriété CommandText de l'objet SqlCommand
		this->CMD->CommandText = this->rq_sql;

		// Ouverture de la connexion à la base de données
		this->CNX->Open();

		// Exécution de la requête SQL sans récupération de résultat (INSERT, UPDATE, DELETE, etc.)
		this->CMD->ExecuteNonQuery();

		// Fermeture de la connexion à la base de données
		this->CNX->Close();
	}

	// Méthode pour récupérer des données à partir de la base de données dans un DataSet
	DataSet^ CL_CAD::getRows(String^ rq_sql, String^ dataTableName)
	{
		// Appel de la méthode setSQL pour définir la requête SQL à exécuter
		this->setSQL(rq_sql);

		// Création d'un nouvel adaptateur de données SqlDataAdapter associé à l'objet SqlCommand (CMD)
		this->DA = gcnew SqlDataAdapter(this->CMD);

		// Attribution de la requête SQL à la propriété CommandText de l'objet SqlCommand
		this->CMD->CommandText = this->rq_sql;

		// Création d'un nouvel objet DataSet pour stocker les données récupérées
		this->DS = gcnew DataSet();

		// Remplissage du DataSet avec les données de la base de données en utilisant l'adaptateur de données (DataAdapter)
		// La table dans le DataSet sera nommée d'après la valeur de dataTableName
		this->DA->Fill(this->DS, dataTableName);

		// Retour du DataSet contenant les données récupérées
		return this->DS;
	}

	void CL_CAD::setSQL(String^ rq_sql)
	{
		if (rq_sql == "" || rq_sql == "RIEN")
		{
			this->rq_sql = "RIEN";
		}
		else
		{
			this->rq_sql = rq_sql;
		}
	}
}