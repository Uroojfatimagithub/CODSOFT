#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

void displayImage(const Mat& image) {
    namedWindow("Processed Image", WINDOW_NORMAL);
    imshow("Processed Image", image);
    waitKey(0);
    destroyAllWindows();
}

void applyGrayscale(Mat& image) {
    cvtColor(image, image, COLOR_BGR2GRAY);
}

void applyBlur(Mat& image) {
    GaussianBlur(image, image, Size(5, 5), 0);
}

void applySharpen(Mat& image) {
    Mat kernel = (Mat_<float>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    filter2D(image, image, image.depth(), kernel);
}

void adjustBrightnessContrast(Mat& image, double alpha, int beta) {
    image.convertTo(image, -1, alpha, beta);
}

void cropImage(Mat& image, int x, int y, int width, int height) {
    image = image(Rect(x, y, width, height)).clone();
}

void resizeImage(Mat& image, int width, int height) {
    resize(image, image, Size(width, height));
}

void saveImage(const Mat& image, const std::string& filename) {
    imwrite(filename, image);
    std::cout << "Image saved as " << filename << std::endl;
}

int main() {
    Mat image = imread("sample.jpg");  // Replace "sample.jpg" with your image file

    if (image.empty()) {
        std::cerr << "Error loading image!" << std::endl;
        return -1;
    }

    int choice;
    do {
        std::cout << "Image Processing Tool\n";
        std::cout << "1. Display Image\n";
        std::cout << "2. Grayscale\n";
        std::cout << "3. Blur\n";
        std::cout << "4. Sharpen\n";
        std::cout << "5. Adjust Brightness and Contrast\n";
        std::cout << "6. Crop Image\n";
        std::cout << "7. Resize Image\n";
        std::cout << "8. Save Image\n";
        std::cout << "9. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                displayImage(image);
                break;
            case 2:
                applyGrayscale(image);
                break;
            case 3:
                applyBlur(image);
                break;
            case 4:
                applySharpen(image);
                break;
            case 5: {
                double alpha;
                int beta;
                std::cout << "Enter alpha (contrast adjustment factor): ";
                std::cin >> alpha;
                std::cout << "Enter beta (brightness adjustment factor): ";
                std::cin >> beta;
                adjustBrightnessContrast(image, alpha, beta);
                break;
            }
            case 6: {
                int x, y, width, height;
                std::cout << "Enter x coordinate for top-left corner: ";
                std::cin >> x;
                std::cout << "Enter y coordinate for top-left corner: ";
                std::cin >> y;
                std::cout << "Enter width: ";
                std::cin >> width;
                std::cout << "Enter height: ";
                std::cin >> height;
                cropImage(image, x, y, width, height);
                break;
            }
            case 7: {
                int newWidth, newHeight;
                std::cout << "Enter new width: ";
                std::cin >> newWidth;
                std::cout << "Enter new height: ";
                std::cin >> newHeight;
                resizeImage(image, newWidth, newHeight);
                break;
            }
            case 8: {
                std::string filename;
                std::cout << "Enter the filename to save the processed image: ";
                std::cin >> filename;
                saveImage(image, filename);
                break;
            }
            case 9:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 9);

    return 0;
}
