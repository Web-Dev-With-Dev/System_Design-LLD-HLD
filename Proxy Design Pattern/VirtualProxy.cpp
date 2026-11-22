#include<iostream>
using namespace std;

class IImage {
    public :
        virtual void display() = 0;
        virtual ~IImage() = default;
};

class RealImage : public IImage {
    string filename;

    public:
        RealImage(string file) {
            this->filename = file;
            cout<<"[Real Image] loading image from disk : " << filename << endl;
        }

        void display() {
            cout << "[Real Image] Displaying ..."<<endl;
        }
};

class ImageProxy : public IImage {
    RealImage* reali;
    string filename;

    public:
        ImageProxy(string file){
            this->filename = file;
            reali = nullptr;
        }

        void display() override {
            if(!reali){
                reali = new RealImage(filename);
            }
            reali->display();
        }
};

int main() {
    IImage* image1 = new ImageProxy("sample.jpg");
    image1->display();
    return 0;
}