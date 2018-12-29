#include <iostream>
#include <fstream>
#include<iostream>
#include<math.h>
using namespace std;

ifstream input;//used to get input from user
ofstream output,output_t;
int pixels[400][400];//original canvas size
int g_shapes();//initializing function g_shapes
int makeSquare(int x,int y,int size,int grayScaleValue);//initinializing function
int makeRectangle(int x,int y,int width,int height,int grayscale);
int makeTriangle(int x,int y,int size,int grayscale);
int makeCircle(int x,int y,int radius,int grayscale);
int g_test();
int g_canvas();
string filename;
string pmgfile;
bool checkBounds(int x,int y);





int main(int argc, char *argv[]) {
    //info for reading shape.
    string shape ;
    int x;
    int y;
    int width;
    int height;
    int grayScaleValue;
    int size;
    int radius;
    string file_name;
    string img_file;

    //generating test file
    g_test();
    //code to read a file
    input.open(argv[1],ifstream::in);//opens file
    if(!input.is_open()){//if statement incase it doesnt work
        cerr<<"ERROR:could not open file.txt\n";
        exit(1);
    }

    //code to write a file
    //ofstream is used to write to a fileout
    output.open(argv[2],ofstream::out);
    if(!output.is_open()){
        cerr<<"ERROR: could not open pgm.txt\n";
        exit(1);
    }
//generates canvas as well as header
   g_canvas();

//checking for shape 
    while(input){
        input>>shape;
        //output<<shape<<" ";
        cout<<shape<<" "<<endl;
        if (shape=="square"){
            input>>x;
            cout<<x<<" ";
            input>>y;
            cout<<y<<" ";
            input>>size;
            cout<<size<<" ";
            input>>grayScaleValue;
            cout<<grayScaleValue<<endl;
            makeSquare(x,y,size,grayScaleValue);
        }
        if(shape=="circle"){
            input>>x;
            cout<<x<<" ";
            input>>y;
            cout<<y<<" ";
            input>>radius;
            cout<<radius<<" ";
            input>>grayScaleValue;
            cout<<grayScaleValue<<endl;
            makeCircle(x,y,radius,grayScaleValue);
        }
        if (shape=="triangle"){
            input>>x;
            cout<<x<<" ";
            input>>y;
            cout<<y<<" ";
            input>>size;
            cout<<size<<" ";
            input>>grayScaleValue;
            cout<<grayScaleValue<<" ";
            makeTriangle(x,y,size,grayScaleValue);

        }
        if(shape=="rectangle"){
            input>>x;
            cout<<x<<" ";
            input>>y;
            cout<<y<<" ";
            input>>width;
            cout<<width<<" " ;
            input>>height;
            cout<<height<<" ";
            input>>grayScaleValue;
            cout<<grayScaleValue<<" ";
            makeRectangle(x,y,width,height,grayScaleValue);

        }

    }

    for(int y=0;y<400;y++){
        for(int x=0;x<400;x++){
            output<<pixels[x][y]<<endl;
        }
    }
    output.close();
    output_t.close();
    input.close();




}

int g_shapes(){//function that produces random shapes.
    for(int i=0;i<1000;i++){//produces whatever random  shapes rn
         output_t << "square "<<rand()%400 <<" "<< rand()%400 <<" " <<rand()%50 << " "<< rand()%255<<endl;//values from 0 to%n
         output_t<< "rectangle "<<rand()%400<<" "<< rand()%400 << " "<<rand()%50<<" " <<rand()%50<< " "<<rand()%255<<endl;
         output_t<< "triangle "<<rand()%400<<" "<<rand()%400<<" "<<rand()%50<<" "<<rand()%255<<endl;
         output_t<<"circle "<<rand()%400<<" "<<rand()%400<<" "<<rand()%50<<" "<<rand()%255<<endl;


    }
    return 0;
}

//make square function
int makeSquare(int x,int y,int size,int grayscale){
    cout <<"make square" << endl;
    for(int a=y;a<size+ y;a++){
        for(int b=x;b<size+x;b++){
           if(!checkBounds(a,b)){
                break;
           }
            pixels[a][b]= grayscale;

        }  
    }
    return 0;
}
int makeRectangle(int x,int y,int width,int height,int grayscale){
    cout<<"making rectangles"<<endl;
    for(int a=y;a<height+y;a++){

        for(int b=x;b<width+x;b++){

            if(!checkBounds(a,b)){
                break;
            }
            pixels[a][b]=grayscale;
        }
    }
}

int makeTriangle(int x,int y,int size,int grayscale){
    cout<<"making triangles"<<" "<<endl;
    int n=size/2,f_x=x,s_x=x;
    for(int a=y;a<y+size;a++){
        for(int b=x+n;b<s_x+n+1;b++){

            if(!checkBounds(a,b)){
                break;
            }

            pixels[a][b]=grayscale;
        }
        s_x++;
        for(int b=x+n;b>f_x+n-1;b--){
            if(!checkBounds(a,b)){
                break;
            }
            pixels[a][b]=grayscale;
        }
        f_x--;
    }
}

int makeCircle(int x,int y,int radius,int grayscale){
    int center_x=x+radius, center_y=y+radius;
    for(int a=y;a<y+2*radius;a++){
            for(int b=x;b<x+2*radius;b++){
                if(!checkBounds(a,b)){
                    break;
                }
                int distance=sqrt(((b-center_x)*(b-center_x))+((a-center_y)*(a-center_y)));
                     if(distance<radius){
                        pixels[a][b]=grayscale;
                    }
            }
    }
}

bool checkBounds(int x,int y){
    if(x>=0 && y>=0 && x<400 && y<400){
        return true;
    }else{
        return false;
    }


}
int g_test(){
    output_t.open("test2.txt",ofstream::out);
    g_shapes();
    output_t.close();
}
int g_canvas(){
    //output header information

    output<<"P2"<<endl<<"400"<<" "<<"400"<<endl<<"255"<<endl;

    //generates code for canvas

    for(int y=0;y<400;y++){
        for(int x=0;x<400;x++){
            pixels[x][y] = 255;
        }
    }
}


























