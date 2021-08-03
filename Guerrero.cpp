//
//  main.cpp
//  Data Structures and Algorithms
//
//  Created by Sourav Kumar on 18/10/20.
//





#include <iostream>
using namespace std;
#include<queue>
#include<string>
#include<unordered_map>
#include<climits>


class state{
public:
    string city;
    int total_patients;
    int sixty_above_patients;
    int minimum_cost_by_road;
    state(string city, int totalPatients, int sixtyAbovePatients, int minimum_cost){
        this->city=city;
        total_patients=totalPatients;
        sixty_above_patients=sixtyAbovePatients;
        this->minimum_cost_by_road=minimum_cost;
    }
};


class comparison{
public:
    bool operator()(state s1,state s2){
        if(s1.total_patients>=1000){
            return s1.total_patients<s2.total_patients;
        }
        else{
            return s1.sixty_above_patients<s2.sixty_above_patients;
        }
    }
};



unordered_map<string, int> Cities_To_Integer(){
    unordered_map<string,int> map;
    map["delhi"]=0;
    map["srinagar"]=1;
    map["shimla"]=2;
    map["chandigarh"]=3;
    map["dehradun"]=4;
    map["jaipur"]=5;
    map["lucknow"]=6;
    map["gandhinagar"]=7;
    map["bhopal"]=8;
    map["patna"]=9;
    map["ranchi"]=10;
    map["raipur"]=11;
    map["bhubaneswar"]=12;
    map["kolkata"]=13;
    map["gangtok"]=14;
    map["itanagar"]=15;
    map["guwahati"]=16;
    map["shilong"]=17;
    map["kohima"]=18;
    map["imphal"]=19;
    map["aizawl"]=20;
    map["agartala"]=21;
    map["mumbai"]=22;
    map["panaji"]=23;
    map["hyderabad"]=24;
    map["banglore"]=25;
    map["thiruvananthapuram"]=26;
    map["chennai"]=27;
    return map;
}




int** Get_Map_Of_Cities(){
    int **input=new int*[28];
    for(int i=0;i<28;i++){
        input[i]=new int[28];
        for(int j=0;j<28;j++){
            input[i][j]=0;
        }
    }
    input[0][3]=290;
    input[0][6]=554;
    input[1][3]=553;
    input[1][2]=639;
    input[2][3]=218;
    input[2][4]=226;
    input[2][1]=639;
    input[3][1]=553;
    input[3][2]=218;
    input[3][5]=517;
    input[3][0]=290;
    input[3][6]=840;
    input[3][4]=184;
    input[4][3]=184;
    input[4][2]=226;
    input[4][6]=550;
    input[5][3]=536;
    input[5][6]=574;
    input[5][8]=594;
    input[5][7]=632;
    input[6][8]=612;
    input[6][5]=574;
    input[6][4]=553;
    input[6][9]=518;
    input[6][0]=554;
    input[6][11]=797;
    input[7][5]=632;
    input[7][8]=604;
    input[7][22]=546;
    input[8][5]=594;
    input[8][7]=604;
    input[8][22]=774;
    input[8][6]=612;
    input[8][11]=629;
    input[9][6]=518;
    input[9][10]=328;
    input[9][13]=551;
    input[10][9]=328;
    input[10][11]=569;
    input[10][13]=409;
    input[10][12]=456;
    input[11][12]=551;
    input[11][10]=569;
    input[11][8]=629;
    input[11][22]=1119;
    input[11][24]=685;
    input[12][11]=551;
    input[12][10]=456;
    input[12][10]=442;
    input[12][24]=1052;
    input[13][14]=700;
    input[13][10]=409;
    input[13][9]=551;
    input[13][12]=442;
    input[13][16]=1017;
    input[14][13]=700;
    input[15][16]=325;
    input[15][18]=322;
    input[16][13]=1017;
    input[16][15]=325;
    input[16][18]=357;
    input[16][17]=98;
    input[16][19]=489;
    input[16][21]=542;
    input[16][20]=469;
    input[17][16]=98;
    input[18][15]=330;
    input[18][16]=357;
    input[18][19]=136;
    input[19][18]=136;
    input[19][16]=489;
    input[19][20]=401;
    input[20][16]=469;
    input[20][19]=401;
    input[20][21]=336;
    input[21][16]=542;
    input[21][20]=336;
    input[22][7]=546;
    input[22][8]=774;
    input[22][11]=1119;
    input[22][24]=716;
    input[22][25]=984;
    input[22][23]=535;
    input[23][22]=535;
    input[23][25]=594;
    input[24][22]=716;
    input[24][25]=569;
    input[24][27]=627;
    input[24][11]=685;
    input[24][12]=1052;
    input[25][26]=684;
    input[25][27]=333;
    input[25][24]=569;
    input[26][25]=501;
    input[26][27]=725;
    input[27][26]=725;
    input[27][25]=333;
    input[27][24]=627;

    return input;
}



/*
long Get_Shortest_Path(int **network, int current_city, int destination_city, bool *visited, int *parent, int total_number_of_cities){
    visited[current_city]=true;
    if(current_city==destination_city){
        return network[parent[current_city]][current_city];
    }
    long distance=INT_MAX;
    for(int i=0;i<total_number_of_cities;i++){
        if(!visited[i]&&network[current_city][i]){
            parent[i]=current_city;
            bool *tempVisited=new bool[total_number_of_cities];
            for(int i=0;i<total_number_of_cities;i++){
                tempVisited[i]=visited[i];
            }
            int *tempParent=new int[total_number_of_cities];
            for(int i=0;i<total_number_of_cities;i++){
                tempParent[i]=parent[i];
            }
            long d=Get_Shortest_Path(network, i, destination_city, tempVisited, tempParent, total_number_of_cities);
            if(d<distance){
                distance=d;
            }
        }
    }
    return distance+network[parent[current_city]][current_city];
}
*/


/*
int Get_Minimum_Travelling_Cost(int **network, string s, unordered_map<string, int> map, int total_number_of_cities){
    bool *visited=new bool[total_number_of_cities];
    for(int i=0;i<total_number_of_cities;i++){
        visited[i]=false;
    }
    int *parent=new int[total_number_of_cities];
    for(int i=0;i<total_number_of_cities;i++){
        parent[i]=i;
    }
    int destination_city=map[s];
    int Shortest_Distance=Get_Shortest_Path(network, 0, destination_city, visited, parent, total_number_of_cities);
    int Minimum_Cost=Shortest_Distance*7;   // PER KILOMETER COST IS 7 RUPEES.
    return Minimum_Cost;
}
*/




// DIJKSTRA'S ALGORITHM

int* Shortest_Path(int **input, int v){
    bool *visited=new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    int *distance=new int[v];
    for(int i=0;i<v;i++){
        distance[i]=INT_MAX;
    }
    distance[0]=0;
    for(int i=0;i<v;i++){
        int minDistance=INT_MAX;
        int index=-1;
        for(int i=0;i<v;i++){
            if(!visited[i]&&distance[i]<minDistance){
                minDistance=distance[i];
                index=i;
            }
        }
        visited[index]=true;
        for(int i=0;i<v;i++){
            if(!visited[i]&&input[index][i]!=0&&input[index][i]+distance[index]<distance[i]){
                distance[i]=input[index][i]+distance[index];
            }
        }
    }
    return distance;
}



int* Get_Minimum_Travelling_Cost(int **network, int total_number_of_cities){
    int *distance=Shortest_Path(network, total_number_of_cities);
    for(int i=0;i<total_number_of_cities;i++){
        distance[i]*=7; // PER KILOMETER COST IS 7 RUPEES.
    }
    return distance;
}


vector<state> Prioritize_Cities(int n, int total_number_of_cities){
    priority_queue<state,vector<state>,comparison> Above_Thousand_Cases,Below_Thousand_Cases;
    string city;
    int total_patients;
    int sixty_above_patients;
    int **network=Get_Map_Of_Cities();
    unordered_map<string, int> map=Cities_To_Integer();
    int *Minimum_Cost=Get_Minimum_Travelling_Cost(network, total_number_of_cities);
    for(int i=0;i<n;i++){
     //   cout<<endl;
     //   cout<<"Enter the name of "<<i+1<<"th"<<" city: ";
        cin>>city;
     //   cout<<"Enter total number of patients: ";
        cin>>total_patients;
     //   cout<<"Enter total number of sixty above patients (by age): ";
        cin>>sixty_above_patients;
      //  int Minimum_Cost=Get_Minimum_Travelling_Cost(network, city, map, total_number_of_cities);
        int minCost=Minimum_Cost[map[city]];
        state s(city,total_patients,sixty_above_patients,minCost);
        if(total_patients>=1000)
            Above_Thousand_Cases.push(s);
        else
            Below_Thousand_Cases.push(s);
      //  cout<<endl;
    }
    vector<state> v;
    while(!Above_Thousand_Cases.empty()){
        state s=Above_Thousand_Cases.top();
        Above_Thousand_Cases.pop();
        v.push_back(s);
    }
    while(!Below_Thousand_Cases.empty()){
        state s=Below_Thousand_Cases.top();
        Below_Thousand_Cases.pop();
        v.push_back(s);
    }
    return v;
}


vector<state> take_order(int total_number_of_cities){
  //  cout<<"Enter total number of cities: ";
    int n;
    cin>>n;
    return Prioritize_Cities(n, total_number_of_cities);
}



int main(){
    vector<state> v=take_order(28);
    int length=v.size();
    cout<<endl<<endl;
    for(int i=0;i<length;i++){
        cout<<i+1<<". "<<"Name of City: "<<v.at(i).city<<endl<<"  Total Number of Patients: "<<v.at(i).total_patients<<endl<<"  Total Number of Sixty Above Patients: "<<v.at(i).sixty_above_patients<<endl<<"  Minimum Travelling Cost by Road: "<<v.at(i).minimum_cost_by_road<<endl<<endl;
    }
}


/*
10
srinagar
1500
800
shimla
1200
700
chandigarh
800
400
dehradun
1300
300
jaipur
700
500
lucknow
1700
200
gandhinagar
950
350
bhopal
650
453
patna
723
150
ranchi
1100
89
*/


// RESULT
/*
1. LUCKNOW
2. SRINAGAR
3. DEHRADUN
4. SHIMLA
5. RANCHI
6. JAIPUR
7. BHOPAL
8. CHANDIGARH
9. GANDHINAGAR
10. PATNA
*/

