#include "JsonDatabaseManager.h"

JsonDatabase::JsonDatabaseManager::JsonDatabaseManager(std::string path, bool debug) {
    this->filePath = path;
    this->debug = debug;

    if (debug) {
        std::cout << "Database File: " << filePath << std::endl;
    }

    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::ofstream newFile(filePath);

        if (newFile.is_open()) {
            if (debug) {
                std::cout << "File Created: " << filePath << std::endl;
            }

            newFile << "{}" << std::endl;

            newFile.close();
        }
        else {
            if (debug) {
                std::cerr << "Hata: Dosya olusturulamadi: " << filePath << std::endl;
            }
        }
    }
}

std::string JsonDatabase::JsonDatabaseManager::getAllFileContent() {
    std::ifstream file(filePath);

    if (!file.is_open()) {
        if (debug) {
            std::cerr << "Error: File Error: " << filePath << std::endl;
        }

        return "";
    }

    file.seekg(0, std::ios::end);
    std::streampos fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    std::string fileContent(static_cast<std::size_t>(fileSize), '\0');

    file.read(&fileContent[0], fileSize);

    file.close();

    return fileContent;
}

void JsonDatabase::JsonDatabaseManager::setString(std::string key, std::string value) {
    json jsonObj = json::parse(getAllFileContent());

    jsonObj[key] = value;

    std::ofstream outputFile(filePath);
    if (outputFile.is_open()) {
        outputFile << jsonObj.dump(3) << std::endl;
        outputFile.close();

        if (this->debug) {
            std::cout << "File Updated: " << filePath << std::endl;
        }
    } else {
        if (this->debug) {
            std::cerr << "Error: File Error: " << filePath << std::endl;
        }
    }
}

void JsonDatabase::JsonDatabaseManager::setInt(std::string key, int value) {
    json jsonObj = json::parse(getAllFileContent());

    jsonObj[key] = value;

    std::ofstream outputFile(filePath);
    if (outputFile.is_open()) {
        outputFile << jsonObj.dump(3) << std::endl;
        outputFile.close();

        if (this->debug) {
            std::cout << "File Updated: " << filePath << std::endl;
        }
    }
    else {
        if (this->debug) {
            std::cerr << "Error: File Error: " << filePath << std::endl;
        }
    }
}


void JsonDatabase::JsonDatabaseManager::setBool(std::string key, bool value) {
    json jsonObj = json::parse(getAllFileContent());

    jsonObj[key] = value;

    std::ofstream outputFile(filePath);
    if (outputFile.is_open()) {
        outputFile << jsonObj.dump(3) << std::endl;
        outputFile.close();

        if (this->debug) {
            std::cout << "File Updated: " << filePath << std::endl;
        }
    }
    else {
        if (this->debug) {
            std::cerr << "Error: File Error: " << filePath << std::endl;
        }
    }
}
void JsonDatabase::JsonDatabaseManager::setDouble(std::string key, double value) {
    json jsonObj = json::parse(getAllFileContent());

    jsonObj[key] = value;

    std::ofstream outputFile(filePath);
    if (outputFile.is_open()) {
        outputFile << jsonObj.dump(3) << std::endl;
        outputFile.close();

        if (this->debug) {
            std::cout << "File Updated: " << filePath << std::endl;
        }
    }
    else {
        if (this->debug) {
            std::cerr << "Error: File Error: " << filePath << std::endl;
        }
    }
}

void JsonDatabase::JsonDatabaseManager::setFloat(std::string key, float value) {
    json jsonObj = json::parse(getAllFileContent());

    jsonObj[key] = value;

    std::ofstream outputFile(filePath);
    if (outputFile.is_open()) {
        outputFile << jsonObj.dump(3) << std::endl;
        outputFile.close();

        if (this->debug) {
            std::cout << "File Updated: " << filePath << std::endl;
        }
    }
    else {
        if (this->debug) {
            std::cerr << "Error: File Error: " << filePath << std::endl;
        }
    }
}

void JsonDatabase::JsonDatabaseManager::setObject(std::string key, json value) {
    json jsonObj = json::parse(getAllFileContent());

    jsonObj[key] = value;

    std::ofstream outputFile(filePath);
    if (outputFile.is_open()) {
        outputFile << jsonObj.dump(3) << std::endl;
        outputFile.close();

        if (this->debug) {
            std::cout << "File Updated: " << filePath << std::endl;
        }
    }
    else {
        if (this->debug) {
            std::cerr << "Error: File Error: " << filePath << std::endl;
        }
    }
}

std::string JsonDatabase::JsonDatabaseManager::getString(std::string key) {
    json jsonObj = json::parse(getAllFileContent());

    return jsonObj[key];
}

int JsonDatabase::JsonDatabaseManager::getInt(std::string key) {
    json jsonObj = json::parse(getAllFileContent());

    return jsonObj[key];
}

bool JsonDatabase::JsonDatabaseManager::getBool(std::string key) {
    json jsonObj = json::parse(getAllFileContent());

    return jsonObj[key];
}

double JsonDatabase::JsonDatabaseManager::getDouble(std::string key) {
    json jsonObj = json::parse(getAllFileContent());

    return jsonObj[key];
}

float JsonDatabase::JsonDatabaseManager::getFloat(std::string key) {
    json jsonObj = json::parse(getAllFileContent());

    return jsonObj[key];
}

json JsonDatabase::JsonDatabaseManager::getObject(std::string key) {
    json jsonObj = json::parse(getAllFileContent());

    return jsonObj[key];
}