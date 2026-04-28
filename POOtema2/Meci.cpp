#include "Meci.h"
#include "Echipa.h"
#include <utility>
#include <iostream>
#include <cstdlib>

Meci::Meci(Echipa* gazda,Echipa* oaspete):gazda(gazda),oaspete(oaspete),golurigazda(0),golurioaspete(0),jucat(false) {}
Meci::Meci(const Meci& m):gazda(m.gazda),oaspete(m.oaspete),golurigazda(m.golurigazda),golurioaspete(m.golurioaspete),jucat(m.jucat) {}
Meci& Meci::operator=(Meci m)
{
    swap(*this,m);
    return *this;
}
void swap(Meci&m1,Meci&m2)
{
    using std::swap;
    swap(m1.gazda,m2.gazda);
    swap(m1.oaspete,m2.oaspete);
    swap(m1.golurigazda,m2.golurigazda);
    swap(m1.golurioaspete,m2.golurioaspete);
    swap(m1.jucat,m2.jucat);

}
void Meci::simuleazameci()
{
    if(gazda!=nullptr && oaspete!=nullptr && !jucat)
    {
        double performantagazda=gazda->performanta_medie();
        double performantaoaspete=oaspete->performanta_medie();
        int bonusgazda=1;
        golurigazda=rand()%3+static_cast<int>(performantagazda/50.0)+bonusgazda;
        golurioaspete=rand()%3+static_cast<int>(performantaoaspete/50.0);
        if(golurigazda<0)
            golurigazda=0;
        if(golurioaspete<0)
            golurioaspete=0;
        gazda->actualizeazastatistici(golurigazda,golurioaspete);
        oaspete->actualizeazastatistici(golurioaspete,golurigazda);
        jucat=true;
    }
}
void  Meci::afisare_program()const
{
    if(gazda!=nullptr && oaspete!=nullptr)
        std::cout<<gazda->getnume()<<" vs "<<oaspete->getnume()<<'\n';
}
void  Meci::afiseaza_rezultat()const
{
    if(gazda!=nullptr && oaspete!=nullptr)
    {
        if(jucat)
            std::cout<<gazda->getnume()<<" "<<golurigazda<<" - "<<golurioaspete<<" "<<oaspete->getnume()<<'\n';
        else
            std::cout<<gazda->getnume()<<" vs "<<oaspete->getnume()<<" (nejucat) "<<'\n';
    }
}
