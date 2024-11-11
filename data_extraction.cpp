#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
class LoadMnist{
    private:


    public:
    std::string training_images_filepath;
    std::string training_labels_filepath;
    std:: string testing_images_filepath;
    std::string testing_labels_filepath;

    LoadMnist( std::string training_images_filepath, std::string training_labels_filepath,
    std:: string testing_images_filepath, std::string testing_labels_filepath ){
        this->training_images_filepath = training_images_filepath;
        this->training_labels_filepath = training_labels_filepath;
        this->testing_images_filepath = testing_images_filepath;
        this->testing_labels_filepath = testing_labels_filepath; 
               }

    void read_images_label (std::string images_filepath, std::string labels_filepath ){
        
        // Open the file in binary mode
        std::ifstream file(labels_filepath, std::ios::binary);
        if (!file) {
            throw std::runtime_error("Unable to open file");
        }


        // ReRead this part //
        // Read the magic number and size
        uint32_t magic, size;
        file.read(reinterpret_cast<char*>(&magic), sizeof(magic));
        file.read(reinterpret_cast<char*>(&size), sizeof(size));

        // Convert from big-endian to host byte order if necessary
        magic = __builtin_bswap32(magic); // GCC/Clang specific for endian conversion
        size = __builtin_bswap32(size);

        // Check for magic number
        if (magic != 2049) {
            throw std::runtime_error("Magic number mismatch, expected 2049, got " + std::to_string(magic));
        }

        // Read the labels into a vector
        std::vector<uint8_t> labels(size);
        file.read(reinterpret_cast<char*>(labels.data()), size);

    // Close the file
    file.close();

    // Output for verification (optional)
    std::cout << "Number of labels read: " << labels.size() << std::endl;

    }               

};