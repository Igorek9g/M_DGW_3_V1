#include <Randomize.hh>
#include <G4Electron.hh>
#include <DetGeometry.hh>
#include "PrimaryGen.hh"

PrimaryGen::PrimaryGen()
{
    gun = new G4ParticleGun(1);
    G4cout<<"Primary particles generator is created successfully\t\tOK!!!"<<G4endl;
}
/*class mast : DetGeometry
{
public:
    G4ThreeVector* W= boxPos;

    //PrimaryGen()
};
*/
PrimaryGen::~PrimaryGen()
{ }



void PrimaryGen::GeneratePrimaries(G4Event* anEvent)
{
    DetGeometry get;
    G4ThreeVector* x= ;
    double RX,RY,RZ;
    getX();
    RX=getX(boxPos);


    srand(time(NULL));
    int Numb=50,R=1;
    //printf("Set number of divisions\n");
    //cin>> Numb;
    //printf("How many particles would you like to run\n");
    //G4cin>>R;
    double In[Numb][2];
    double Emax=545;
    double MC=1/511;
    // y(x)=−(x−1)^2+1
    double Xmax = Emax, X, IMax;
    for (int i=0;i<Numb;i++)
    {
        X=Xmax/Numb*i;
        In[i][0]= (1+Emax*MC)*sqrt((1+X*MC)*(1+X*MC)-(Emax-X)*(Emax - X)*MC*MC);
        if (i>0) In[i][1]=In[i-1][1]+In[i][0];
        else     In[i][1]=In[i][0];
        IMax=In[i][1];
         //G4cout<<i<<"\t"<<In[i][0]<<"\t"<<In[i][1]<<"\n";
    }
    for (int i=0;i<Numb;i++)
    {
        In[i][2]=In[i][1]/IMax;
        //cout<<In[i][2]<<endl;
    }
    G4cout<<"\n"<<IMax<<"\n\n";
    double tmp,rnd;
    int E=0;
    for (int i=0;i<R;i++)
    {
        rnd=rand()%100;
        rnd=rnd/100;
        tmp=0;
        int j=0;
        while (tmp<rnd)
        {
            tmp=In[j][2];            j++;            E=j;
        }
        //G4cout<<"tmp= "<<tmp<<" rnd1= "<<rnd<<"\tEnergy is  "<<E<<"\n";
    }

    //system ("pause");
    //return 0;
int A=0;
    double x,y,z;
while (A<500)
    {
    double rndG = rand() % 100;
    rndG = rndG / 100;
    if (rndG < 0.8) {
        G4cout << rndG << "\n";
        gun->SetParticleDefinition(G4Gamma::GammaDefinition());
        gun->SetParticleEnergy(0.661 * MeV);
        gun->SetParticlePosition(G4ThreeVector(200 * G4UniformRand() - 100 * mm, 200 * G4UniformRand() - 100 * mm,
                                               200 * G4UniformRand() - 300 * mm));
        gun->SetParticleMomentumDirection(G4ThreeVector(0, 1, 0));
        gun->GeneratePrimaryVertex(anEvent);
        A++;
    }


    gun->SetParticleDefinition(G4Electron::ElectronDefinition());
    gun->SetParticleEnergy(E * MeV);

        x=150 * (2 * G4UniformRand() - 1);
        y=150 * (2 * G4UniformRand() - 1);
        z=150 * (2 * G4UniformRand() - 1);
        while (sqrt(x*x+y*y+z*z)>=150)
        {
            x=150 * (2 * G4UniformRand() - 1);
            y=150 * (2 * G4UniformRand() - 1);
            z=150 * (2 * G4UniformRand() - 1);
            G4cout<<"X= "<<x<<" Y= "<<y<<" Z= "<<z<<"\tR= "<<sqrt(x*x+y*y*z*z)<<"\n";
        }
        gun->SetParticlePosition(get.boxPos);
    gun->SetParticlePosition(G4ThreeVector(x * mm, y - 300 * mm, z + 200 * mm));
    gun->SetParticleMomentumDirection(
            G4ThreeVector(2 * G4UniformRand() - 1, 2 * G4UniformRand() - 1, 2 * G4UniformRand() - 1));
    gun->GeneratePrimaryVertex(anEvent);
    A++;
}

}
// /run/beamOn 500