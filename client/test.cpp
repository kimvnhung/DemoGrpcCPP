#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h>

struct Person {
    std::string name;
    int age;
};

int main() {
    std::ifstream jsonFile("data.json");
    Json::CharReaderBuilder reader;
    Json::Value root;
    std::string errs;

    if (Json::parseFromStream(reader, jsonFile, &root, &errs)) {
        if (root.isArray()) {
            std::vector<Person> people;

            for (const auto& personJson : root) {
                Person person;
                person.name = personJson["name"].asString();
                person.age = personJson["age"].asInt();
                people.push_back(person);
            }

            // Print the parsed data
            for (const auto& person : people) {
                std::cout << "Name: " << person.name << ", Age: " << person.age << std::endl;
            }
        } else {
            std::cout << "JSON is not an array." << std::endl;
        }
    } else {
        std::cout << "Failed to parse JSON: " << errs << std::endl;
    }

    return 0;
}
