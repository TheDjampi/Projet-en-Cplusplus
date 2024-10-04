#include"food.hpp"

std::string plat::getNomPlat()
{
    return _nomPlat;
}
bool operator==(plat p1, plat p2)
{
    return (p1.getNomPlat()==p2.getNomPlat());
}

bool operator<(plat  p1, plat  p2)
{
    return (p1.getNomPlat()<p2.getNomPlat());
}

bool operator>(plat p1, plat p2)
{
    return (p1.getNomPlat()>p2.getNomPlat());
}

void GraphFood::ajoutArret(plat const node1, plat const node2)
{
    _adj[node1].push_back(node2);
}

std::ostream& operator<<(std::ostream& flux, plat const pl)
{
    flux<<"Le nom du plat est : "<<pl._nomPlat;
    return flux;
}

void GraphFood::parcourProfondeur(plat node)
{
    _isVisited[node]=true;
    _data.push_back(node);

    for(auto str : _adj[node])
    {
        if(!_isVisited[node])
            parcourProfondeur(str);
    }
}

template<class T> bool same(std::vector<T> vec1, std::vector<T> vec2)
{

    for(int i=0; i<vec1.size(); i++)
    {
        for(int j=0; j<vec2.size(); j++){
            if(vec1[i]==vec2[j]){
                vec1.erase(vec1.begin()+i);
                vec2.erase(vec2.begin()+j);
                std::cout<<"* ";
                i--;
                j--;
                break;
            }
        }
    }
    return (vec1.size()==0 || vec2.size()==0) ? true : false;
}

void GraphFood::platDeterminate()
{  
    bool find = false;
    std::string str[10];
    std::string ing;
    std::vector<std::string> data;
    int i=0;
    std::cout<<"Entrez les ingredients du plat que vous avez consomme (separez par les espaces) : ";
    std::getline(std::cin, ing);
    std::istringstream entree(ing);
    while(entree>>str[i++]);
    for(int j=0; j<i-1; j++)
        data.push_back(str[j]);

    std::cout<<"\nLes Ingredients Que vous avez entre : \n";
    for(int i=0; i<data.size(); i++)
        std::cout<<"    *"<<data[i]<<"\n";
    for(auto node : _adj)
    {
        if(same<std::string>(node.first._ingredient, data))
        {
            std::cout<<"\nCe repas ce nomme : "<<node.first._nomPlat;
            find = true;
            break;
        }

        
        for(auto res : node.second)
        {
            if(same<std::string>(res._ingredient, data))
            {
                std::cout<<"\nCe repas ce nomme : "<<res.getNomPlat();
                find = true;
                break;
            }
        } 


    }   if(!find)
        {
            std::cout<< "repas introuvable dans la bd\n";
        }
}

void GraphFood::printGraph()
{

    for(auto node : _adj)
    {
        std::cout<<"\nLes Ingredients : \n";
        for(int i=0; i<node.first._ingredient.size(); i++)
            std::cout<<"    *"<<node.first._ingredient[i]<<"\n";
        for(auto res : node.second)
        {
            std::cout<<"\nLes Ingredients : \n";
            for(int i=0; i<res._ingredient.size(); i++)
                std::cout<<"    *"<<res._ingredient[i]<<"\n";
        }
    }
}


void GraphFood::createGraph()
{
    std::ifstream flux("Repas.txt");
    std::ifstream flux1("sauce.txt");
    std::ifstream flux2("complement.txt");
    std::ifstream flux3("viande.txt");
    std::ifstream flux5("ingredients.txt");

    std::vector<plat> res;

    std::string n1, n2, n3, n4="", n5, n6;
    while(std::getline(flux2, n1) && std::getline(flux1, n2) && std::getline(flux3, n3)
    && std::getline(flux5, n5) && std::getline(flux, n6))
    {
        int i=0;
        std::string val[40];
        std::vector<std::string> ing;
        std::istringstream entree(n5);
        while(entree>>val[i++]);
        for(int j=0; j<i-1; j++){
            ing.push_back(val[j]);
        }

        res.push_back(plat(n1, n2, n3, n4, n6, ing));
    }
    for(int j=0; j<res.size()-2; j+=2)
       ajoutArret(res[j], res[j+1]);
}

int main()
{
    GraphFood g;
    g.createGraph();
    g.platDeterminate();
}
