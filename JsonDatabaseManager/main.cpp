#include <iostream>


#include "JsonDatabaseManager/JsonDatabaseManager.h"


int main()
{

	JsonDatabase::JsonDatabaseManager databaseManager{"C:\\Rullet\\database.json", true};


	databaseManager.setString("stringField", "westy");
	databaseManager.setInt("intField", 16);
	databaseManager.setBool("booleanField", true);
	databaseManager.setDouble("doubleField", 3.14);
	databaseManager.setFloat("floatField", 3.3333333313);

	json jsonField;

	jsonField["username"] = "westydev";
	jsonField["old"] = 16;

	databaseManager.setObject("jsonField", jsonField);

	std::cout << "\nFields\n" << std::endl;

	std::cout << "String Field -> " << databaseManager.getString("stringField") << std::endl;
	std::cout << "Int Field -> " << databaseManager.getInt("intField") << std::endl;
}