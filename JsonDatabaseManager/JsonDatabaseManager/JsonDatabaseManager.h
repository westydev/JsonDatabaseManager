#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "../include/json.hpp"
#include <any>


using json = nlohmann::json;

namespace JsonDatabase {
	class JsonDatabaseManager {
	public:
		JsonDatabaseManager(std::string path, bool debug);
		
		std::string getAllFileContent();

		void setString(std::string key, std::string value);
		void setInt(std::string key, int value);
		void setBool(std::string key, bool value);
		void setDouble(std::string key, double value);
		void setFloat(std::string key, float value);
		void setObject(std::string key, json value);


		std::string getString(std::string key);
		int getInt(std::string key);
		bool getBool(std::string key);
		double getDouble(std::string key);
		float getFloat(std::string key);
		json getObject(std::string key);

	private:
		std::string filePath;
		bool debug;
	};
} 
