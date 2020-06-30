#include "ez.h"

int main(){

	cout << "please select run mode (1 for log, 2 for replay):\n";
    char cmd;
    cin >> cmd;
    if(cmd != '1' && cmd!='2'){
        cout << "invalid option. exiting\n";
        return 1;
    }
	ofstream ofs_;
	ifstream ifs_;
	// vector<int> params;
	// vector<ucgar> ar;
	// std::vector<char> array;
	// int sizeeee;
// 
	// cv::Mat im(3, 3, CV_32F);
	Mat im = imread("../lena.jpg");
	
	// cv::Mat mew_im(3,3);
	int nr=im.rows;      
	int nc=im.cols; 
	int sizeee = nr * nc * im.channels();
	cout << "hii";
	cout << "hii";

	cout << sizeof(uchar) << endl;
	cout << "hi";
	uchar* psrc = (uchar*)im.data;
	uchar *pdst = new uchar [im.total()];
	uchar *new_pdst = new uchar [im.total()];


	//write in
	if(cmd == '1'){                                                                                                                                                                                                                           
		// Mat im = imread("../lena.jpg");
		
		// Mat outImage;
		// imshow("lena", im);

		ofs_.open("test.dat", ios::out | ios::binary);

		// Print for experiment
		// cout << sizeof(Mat);
		cout << im.type() << endl; //https://stackoverflow.com/questions/10167534/how-to-find-out-what-type-of-a-mat-object-is-with-mattype-in-opencv
		cout << im.size() << endl;
		cout << im.isContinuous() << endl;


		// char **array = new char*[im.rows];
		// for (int i=0; i<im.rows; ++i)
		// 	array[i] = new char[im.cols*im.channels()];

		// for (int i=0; i<im.ro  ws; ++i)
		// 	array[i] = im.ptr<char>(i);

		///Method 1
		// std::vector<uchar> array(im.rows*im.cols*im.channels());

		
		for(int i=0;i<nc;i++)
		{		
			const uchar* p0 = psrc + i * nr;
			uchar* p1 = pdst + i * nr;
			for(int j=0; j < nr;j++)
			{	
				*p1++ = p0[j];	
				// cout << p0[j];	
			}
		}
		ofs_.write((char*)&pdst, im.total()*sizeof(uchar)); //src, len
		

	
		///Method 2
		
		// if (im.isContinuous()) {
		// 	array.assign(im.datastart, im.dataend); // <- has problems for sub-imrix like im = big_im.row(i)
		// 	// array.assign(im.data, im.data + im.total()*im.channels());
		// } else {
		// 	for (int i = 0 ; i < im.rows ; ++i ) {
		// 		array.insert(array.end(), im.ptr<char>(i), im.ptr<char>(i)+im.cols*im.channels());
		// 	}
		// }



		// cout << ar.size();
		// cv::Mat flat = im.reshape(1, im.total()*im.channels());
		// std::vector<char> vec = im.isContinuous()? flat : flat.clone();

		// cout << vec.size() << endl;
		// for(int i = 0 ; i < vec.size() ; ++i){
		// 	cout << vec[i]; 
		// }
		// // cout << ar;
		// cout << sizeof(vector<char>) + sizeof(char)*array.size();
		// ofs_.write((char*)&vec, sizeof(vector<char>) + sizeof(char)*array.size()); //src, len	
			
	}
	else if(cmd == '2'){
		Mat imm;
		ifs_.open("test.dat", ios::in | ios::binary);
		ifs_.read((char*)&new_pdst, im.total()*sizeof(uchar));
		
	}

	waitKey(0);
	return 0;
}
