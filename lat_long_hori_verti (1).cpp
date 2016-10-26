#include<iostream>
#include<conio.h>
float dist1=1.41;
float dist2=1;
float pi=3.14;
float la,lo;
#include<math.h>
using namespace std;
float lati(float lat,float lon,int deg,float d)//finding latitude
{
    float R=6378.14,lat2,lon2,baring,tab[2];
    // Deg to Rad
    lat=lat*(pi/180);
    lon=lon*(pi/180);
    baring=deg*(pi/180);
    
    lat2 = ((d/R)*cos(baring))+lat;
    lon2 = (d/(R*sin(lat2))*sin(baring))+lon;
    // back to degres
    lat2 = lat2*(180/pi);
    lon2 = lon2*(180/pi);
   // Push in array and get back
   la= lat2;
   lo= lon2;
}
int lat_long(float lat1,float long1,int dist,int i1)//function for the algorithm
{
    float lat[dist][dist],lon[dist][dist],visit[dist][dist];
    int i,j,k,xf,yf,xb,yb;
    k=(dist/2);
    if(i1)//for odd numbered grid modal
    {
        lat[k][k]=lat1;
        lon[k][k]=long1;
        visit[k][k]=1;
        xf=yf=k;
        xb=yb=k;
        for(i=0;i<dist/2;i++)//computing the diagonal latitude and longitudes
        {
            lati(lat[xf][yf],lon[xf][yf],90,dist2);//calculating upper part of right diagonal
            lat[xf-1][yf]=la;
            lon[xf-1][yf]=lo;
            visit[xf-1][yf]=1;
            
            lati(lat[xb][yb],lon[xb][yb],270,dist2);//calculating lower part of rifht diagonal
            lat[xb+1][yb]=la;
            lon[xb+1][yb]=lo;
            visit[xb+1][yb]=1;
            xf-=1;
            xb+=1;
        }
    }
    else//if the even numbered grid modal
    {
        xf=yb=k-1;
        yf=xb=k;
        for(i=0;i<dist/2;i++)
        {
            if(i==0)
            { 
                lati(lat1,long1,90,1/dist2); //computing 1st upper point of right diagonal  
                lat[xf][yf]=la;
                lon[xf][yf]=lo;
                visit[xf][yf]=1;
                lati(lat1,long1,270,1/dist2);//computing 1st lower point of right diagonal
                lat[xb][yb]=la;
                lon[xb][yb]=lo;
                visit[xb][yb]=1;
            }
            else //remaining points in the right diagonal
            {
                lati(lat[xf][yf],lon[xf][yf],90,dist2);
                lat[--xf][yf]=la;
                lon[xf][yf]=lo;
                visit[xf][yf]=1;
                lati(lat[xb][yb],lon[xb][yb],270,dist2);
                lat[++xb][yb]=la;
                lon[xb][yb]=lo;
                visit[xb][yb]=1;
            }
        }
        for(i=0;i<dist;i++)
        {
                lati(lat[i][yf],lon[i][yf],0,dist2/2); 
                lat[i][yf]=la;
                lon[i][yf]=lo;
                visit[i][yf]=1;
        }
    }
        for(i=0;i<dist;i++)//computing the row wise latitude and longitude
        {
            for(j=0;j<dist;j++)
            {
                if(visit[i][j]==1)
                {
                    k=j;
                    break;
                }
            }
            for(j=k;j>0;j--)
            {
                lati(lat[i][j],lon[i][j],180,dist2);
                lat[i][j-1]=la;
                lon[i][j-1]=lo;
            }
            for(j=k;j<dist-1;j++)
            {
                lati(lat[i][j],lon[i][j],0,dist2);
                lat[i][j+1]=la;
                lon[i][j+1]=lo;
            }
        }
    cout<<"The centeral latitude and longiude for each 1X1 grid present in the "<<dist<<"X"<<dist<<"grid are:\n";
    for(i=0;i<dist;i++)
    {
     for(j=0;j<dist;j++)
      cout<<"The center of index "<<i+1<<"x"<<j+1<<" 1x1grid is ("<<lat[i][j]<<","<<lon[i][j]<<")\n";
     cout<<"\n";
    }
}
int main()
{
    float lat1,long1;
    int dist,i=1;
    cout<<"----------latitude and longitude calculation by Prasant rao Jillella SS---------\n";
    cout<<"-->Enter the latitude and longitude of the center point(in decimal):\n";
    cin>>lat1>>long1;            
    cout<<"\n-->Enter the length of the grid(km):";
    cin>>dist;
    cout<<"\n";
    cout<<"--------------------------------------------------------------------------------\n";
    if(dist%2==0)
     i=0;
    lat_long(lat1,long1,dist,i);
    cin>>i;
}
