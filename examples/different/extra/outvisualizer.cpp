#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

void createDummyImage(const std::string& feedbackDir) {
    std::string imagePath = feedbackDir + "/teamimage.svg";

    // Create an SVG file (text-based format)
    std::ofstream imageFile(imagePath);
    if (!imageFile) {
        std::cerr << "Failed to create image file: " << imagePath << std::endl;
        return;
    }

    // Write the SVG header and a simple white square as a placeholder
    imageFile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    imageFile << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"100\" height=\"100\">\n";
    imageFile << "  <rect width=\"100\" height=\"100\" style=\"fill:white;stroke:black;stroke-width:1\" />\n";
    imageFile << "</svg>\n";

    imageFile.close();
    std::cout << "Dummy SVG image created: " << imagePath << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: visualizer <input_file> <feedback_dir>" << std::endl;
        return 1;
    }

    std::string inputFile = argv[1];
    std::string feedbackDir = argv[2];

    // Ensure the feedback directory exists
    if (!fs::exists(feedbackDir)) {
        std::cerr << "Feedback directory does not exist: " << feedbackDir << std::endl;
        return 1;
    }

    // Read the input file
    std::ifstream inputFileStream(inputFile);
    if (!inputFileStream) {
        std::cerr << "Failed to open input file: " << inputFile << std::endl;
        return 1;
    }

    std::cout << "Reading input file: " << inputFile << std::endl;
    std::string line;
    while (std::getline(inputFileStream, line)) {
        std::cout << "Input: " << line << std::endl;
    }
    inputFileStream.close();
    
    // Create a dummy SVG image in the feedback directory
    createDummyImage(feedbackDir);

    return 0;
}