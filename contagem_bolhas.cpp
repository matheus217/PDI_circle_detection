#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main() {

	Mat realce;
	auto filename = "C:\\Users\\Mathe\\OneDrive\\Área de Trabalho\\UFRN\\Processamento  digital de imagens\\bolhas.png";
	auto imagem = imread(filename, IMREAD_GRAYSCALE);

	int width, height;
	int nobjects;

	Point p,q;

	if (!imagem.data) {
		std::cout << "imagem nao carregou corretamente\n";
		return(-1);
	}

	width = imagem.cols;
	height = imagem.rows;

	std::cout << width << "X" << height << std::endl;

	p.x = 0;
	p.y = 0;
	q.x = 0;
	q.y = 0;

	for (int i = 0; i < height; i++) {
		if(imagem.at<uchar>(i, 0) == 255) {

			p.x = 0;
			p.y = i;

			floodFill(imagem, p, 0);

		}
		if (imagem.at<uchar>(i, (width - 1)) == 255) {
			q.x = width - 1;
			q.y = i;

			floodFill(imagem, q, 0);
		}
	}

	for (int j = 0; j < width; j++) {
		if (imagem.at<uchar>(0, j) == 255) {

			p.x = j;
			p.y = 0;

			floodFill(imagem, p, 0);

		}
		if (imagem.at<uchar>((height - 1), j) == 255) {
			q.x = j;
			q.y = height - 1;

			floodFill(imagem, q, 0);
		}
	}

	imshow("imagem limpa", imagem);
	waitKey();
	return 0;

}
