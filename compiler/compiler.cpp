#include "compiler.h"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

/** @inheritDoc */
laravel_compiler::laravel_compiler(std::string projectPath) {
    this->projectPath = std::move(projectPath);

    // Check if compiler.json file exists in the project path. If not, throw an error.
    if (std::filesystem::exists(this->projectPath + "/compiler.json")) {
        std::cout << "Compiler file exists" << std::endl;
    } else {
        std::cerr << "Compiler file does not exist" << std::endl;
        throw std::runtime_error("compiler.json file not found");
    }

    // Read the JSON file and parse it to a JSON object.
    std::ifstream file(this->projectPath + "/compiler.json");
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open compiler.json file");
    }

    json compilerJson;
    file >> compilerJson;

    // Use the parsed JSON object (compilerJson) as needed
    std::cout << "Parsed JSON: " << compilerJson.dump(4) << std::endl;
}