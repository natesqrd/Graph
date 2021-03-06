#include "Graph.h"
#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <chrono>

using std::string;
struct timer
{
    std::chrono::time_point<std::chrono::steady_clock> start, end;

    std::chrono::duration<float> duration;

    timer()
    {
        start = std::chrono::high_resolution_clock::now();
    }

    ~timer()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        float ns = duration.count() *1000.0f;
        std::cout << "Function took " << ns << "ms to complete\n";
    }
};
//City connections must be atleast 2. Think of them as psudo node pointers
class City
{
public:
    //array includes name of array for PNP
   /*0*/ string Menifee[6] = { "Menifee", "Sun City", "French Valley", "Murrieta", "Canyon Lake", "Wildomar" };
   /*1*/ string Murrieta[5] = { "Murrieta", "Menifee", "French Valley", "Temecula", "Wildomar" };
   /*2*/ string Temecula[4] = { "Temecula", "Murrieta", "French Valley" , "Fallbrook" };
   /*3*/ string French_Valley[4] = { "French Valley", "Menifee", "Murrieta", "Temecula" };
   /*4*/ string Wildomar[4] = { "Wildomar","Lake Elsinore", "Murrieta", "Menifee" };
   /*5*/ string Lake_Elsinore[4] = { "Lake Elsinore", "Canyon Lake", "Wildomar", "Corona" };
   /*6*/ string Sun_City[3] = {"Sun City", "Menifee", "Perris" };
   /*7*/ string Canyon_Lake[3] = { "Canyon Lake","Lake Elsinore","Menifee" };
   /*8*/ string Corona[3] = { "Corona", "Riverside", "Lake Elsinore" };
   /*9*/ string Riverside[3] = { "Riverside", "Corona", "Moreno Valley" };
   /*10*/string Moreno_Valley[3] = { "Moreno Valley", "Riverside", "Perris" };
   /*11*/string Perris[3] = { "Perris",  "Sun City", "Moreno Valley" };   
   /*12*/string Escondido[4] = { "Escondido", "Fallbrook", "San Diego", "Vista" };
   /*13*/string Fallbrook[3] = { "Fallbrook", "Escondido", "Temecula" };
   /*14*/string San_Diego[2] = { "San Diego", "Carlsbad" };
   /*15*/string Carlsbad[2] = { "Carlsbad","Vista" };
   /*16*/string Vista[2] = { "Vista", "Escondido" };

   int size() { return 17; }
};
int main()
{
    City c;
    Graph g(c.size());
    for(int i = 1; i < 6; i++)
        g.addEdge(c.Menifee[0], c.Menifee[i]); //0
    for (int i = 1; i < 5; i++)
    {
        g.addEdge(c.Murrieta[0], c.Murrieta[i]); //1
    }
    for (int i = 1; i < 4; i++)
    {
        g.addEdge(c.Temecula[0], c.Temecula[i]); //2
        g.addEdge(c.French_Valley[0], c.French_Valley[i]); //3
        g.addEdge(c.Wildomar[0], c.Wildomar[i]); //4
        g.addEdge(c.Lake_Elsinore[0], c.Lake_Elsinore[i]); //5
        g.addEdge(c.Escondido[0], c.Escondido[i]);//6
    }

    for (int i = 1; i < 3; i++)
    {
        g.addEdge(c.Sun_City[0], c.Sun_City[i]);//7
        g.addEdge(c.Canyon_Lake[0], c.Canyon_Lake[i]);//8
        g.addEdge(c.Corona[0], c.Corona[i]);//9
        g.addEdge(c.Riverside[0], c.Riverside[i]);//10
        g.addEdge(c.Moreno_Valley[0], c.Moreno_Valley[i]);//11
        g.addEdge(c.Perris[0], c.Perris[i]);//12
        g.addEdge(c.Fallbrook[0], c.Fallbrook[i]);//13
        
    }
    g.addEdge(c.San_Diego[0], c.San_Diego[1]);//14
    g.addEdge(c.Carlsbad[0], c.Carlsbad[1]);//15
    g.addEdge(c.Vista[0], c.Vista[1]);//16

    g.printGraph();
    g.depthFirstTrav(14);
    
    return 0;
}

