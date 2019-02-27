//
// Created by Thomas on 31/01/2019.
//

#ifndef TP_H
#define TP_H
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>

using namespace std;

void ex1_2();
void ex1_3(void);

class Point2D{
protected :
  float x,y;

public :
    Point2D():x(1),y(2){}                     //Par défaut
    Point2D(int u, int v):x(u),y(v){}         //Par initialisation
    Point2D(const Point2D &p):x(p.x),y(p.y){} //Par copie
};

class Color{
public :
    enum color{ white, yellow, orange, turquoise, violet, pink, red, green, grey, cyan, blue, brown };
protected :
    color c;
    static const char* name[];

public :
    const char* getName()const{return name[c];}
    Color():c(red){}
    Color(const color x):c(x){}
};

class SVGstream{
private:ofstream fichier;

public :SVGstream(const char* name):fichier(name, ios::out | ios::trunc){
            if(fichier){
                fichier <<  "<!doctype html><svg width=\"1000\" height=\"1000\">" << endl;
            }
        };
        ~SVGstream(){
            fichier << "</svg>";
            fichier.close();
        }
        friend SVGstream &operator <<(SVGstream &svg, const char* str){
            svg.fichier << str;
            return svg;
        };
};

class Transform{
public:
    virtual void Rotate(){};
    virtual void Translate(){};
    virtual void Scale(){};
};

class Geom2D : public Transform{

};

class FillProperty : public Color{
protected:
    Color c;
public:
    void setColor(Color col){
        c = col;
        cout << "Couleur changée"<<endl;
    }
};

class Surface : public FillProperty, public Geom2D{
public:
    virtual void info(){};
    virtual void aire(){};
};

class Disc : public Surface, public Point2D{
protected:
    double rayon;
    Point2D origine;
    Color color;
public:
    Disc(double rayon, Point2D p, Color color){
        this->rayon = rayon;
        this->origine = p;
        this->color = color;
    }
    void setRayon(double rayon){
        this->rayon=rayon;
    }
    void setOrigine(Point2D p){
        origine=p;
    }
    void setColor(Color c){
        color=c;
    }
    double getRayon(){
        return rayon;
    }
    Point2D getOrigine(){
        return origine;
    }
    Color getColor(){
        return color;
    }
    void Translate(Point2D p){
        setOrigine(p);
    }
    void Scale(int r){
        setRayon(r);
    }

};

class Rectangle : public Surface{
protected:
    double witdh;
    double height;
    Point2D origine;
    Color color;
public:
    Rectangle(double witdh, double height, Point2D p, Color color){
        this->witdh = witdh;
        this->height = height;
        this->origine = p;
        this->color = color;
    }
    void setWitdh(double witdh){
        this->witdh=witdh;
    }
    void setHeight(double height){
        this->height=height;
    }
    void setOrigine(Point2D p){
        origine=p;
    }
    void setColor(Color c){
        color=c;
    }
    double getWitdh(){
        return witdh;
    }
    double getHeight(){
        return height;
    }
    Point2D getOrigine(){
        return origine;
    }
    Color getColor(){
        return color;
    }
    void Rotate(double x){

    }
    void Translate(Point2D p){
        setOrigine(p);
    }
    void Scale(double pc){
        if(pc>0 && pc<1){
            setWitdh(witdh*pc);
            setHeight(height*pc);
        }
    }
};

class Square : public Rectangle{

};

class PointsArray : public Transform, public Point2D{
protected:
  Point2D pArray [5];

public:
  PointsArray():pArray(Point2D()){
    for(int i=0 ; i<5 ; i++){
      pArray[i] = Point2D(i,i);
    }
  }
};

class ReallocatablePoints : public PointsArray{

};


#endif //TP_H
