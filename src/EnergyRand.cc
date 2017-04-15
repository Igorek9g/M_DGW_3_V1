//
// Created by student on 15.04.17.
//

/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <iostream>
#include <cmath>
#include <G4SIunits.hh>
//#define Numb 20

using namespace std;
int main()
{
        srand(time(NULL));
        int Numb=20,R;
        printf("Set number of divisions\n");
        //cin>> Numb;
        printf("How many particles would you like to run\n");
        cin>>R;
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
           // cout<<i<<"\t"<<In[i][0]<<"\t"<<In[i][1]<<"\n";
        }
        for (int i=0;i<Numb;i++)
        {
            In[i][2]=In[i][1]/IMax;
            //cout<<In[i][2]<<endl;
        }

        cout<<"\n"<<IMax<<"\n\n";
        double tmp,rnd;
        int E=0;
        //printf("\ntmp\trand\tj\tE\n");
        for (int i=0;i<R;i++)
        {
            rnd=rand()%100;
            rnd=rnd/100;
            tmp=0;
            int j=0;
            while (tmp<rnd)
            {
                //cout<<tmp<<"\t"<<rnd<<"\t"<<j<<"\t"<<E<<endl;
                tmp=In[j][2];
                //cout<<" j= "<<j<<endl;
                j++;
                E=j;
                }
                //cout<<tmp<<"\t"<<rnd<<"\t"<<j<<"\t"<<E<<endl;
           // cout<<"\t"<<rnd<<"\t";
            cout<<"Energy is  "<<E<<endl;
            //printf ("we found your Energy, it's %d\n",E);
        }

        system ("pause");
        return 0;

}*/