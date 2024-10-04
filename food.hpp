#ifndef DEF_FOOD
#define DEF _FOOD

#include<bits/stdc++.h>
#include<iostream>

class plat;
class sauce{
    protected :

    std::string _nameSauce;

    public :
    friend class plat;
    sauce(std::string name="") : _nameSauce(name){}
    ~sauce(){}
};

class complement{
    protected :
    std::string _nameComp;

    public :
    friend class plat;
    complement(std::string name="") : _nameComp(name){}
    ~complement(){}
};

class viande{

    protected :

    std::string _nameViande;

    public :
    friend class plat;
    viande(std::string name="") : _nameViande(name){}
    ~viande(){}
};

class autre{

    protected :

    std::string _name;

    public :
    friend class plat;
    autre(std::string name="") : _name(name){}
    ~autre(){}
};

class plat{

    private:
    complement _c;
    sauce _s;
    viande _v;
    autre _a;
    std::string _nomPlat;
    std::vector<std::string> _ingredient;

    public :
    plat(std::string c, std::string s, std::string  v, std::string a, std::string nom, std::vector<std::string> vec){
        _c._nameComp=c;
        _s._nameSauce=s;
        _v._nameViande=v;
        _a._name=a;
        _nomPlat=nom;
        _ingredient=vec;
    }
    friend std::ostream& operator<<(std::ostream &flux, plat const p);
    friend bool operator==(plat, plat );
    friend bool operator<( plat, plat);
    friend bool operator>( plat,  plat);
    std::string getNomPlat();

};

class GraphFood{

    private :

    void ajoutArret(plat const, plat const);
    public :

    std::map<plat, std::vector<plat>> _adj;
    std::map<plat, bool> _isVisited;
    std::vector<plat> _data;

    void createGraph();
    void printGraph();
    void parcourProfondeur(plat);
    void platDeterminate();
};
#endif