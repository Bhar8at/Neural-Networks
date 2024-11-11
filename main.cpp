#include "data_extraction.cpp"


int main(){

    LoadMnist MnistDataset("/MNIST Dataset/train-images.idx3-ubyte", 
                           "/MNIST Dataset/train-labels.idx1-ubyte",
                           "/MNIST Dataset/t10k-images.idx1-ubyte",
                           "/MNIST Dataset/t10k-labels.idx1-ubyte");


    

}