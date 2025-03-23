#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
vector<string> buildings;
string buildingName,commandArg2,commandArg1,floorName,roomID;
map<string,vector<string> > floors;
map<pair<string,string>, vector<string> > confRooms;
int slotSt,slotEnd;
map<string,int> booked;
map<string,vector<pair<pair<int,int>,string> > > bookedSlots;


void printBuildings(){
    for(int i=0;i<buildings.size();i++){
        cout<<buildings[i]<<" ";
    }
    cout<<endl;
}

void printFloor(string buildingName){
    cout<<"Floors in "<<buildingName<<endl;
    for(int i=0;i<floors[buildingName].size();i++){
        cout<<floors[buildingName][i]<<" ";
    }
    cout<<endl;
}

string convertToLowerCase(string buildingName){
    string building = "";
    for(int i=0;i<buildingName.length();i++){
        if(buildingName[i]>='A' and buildingName[i]<='Z')  
            buildingName[i]=buildingName[i]-'A'+'a';
    }
    return buildingName;
}



int buildingExists(string buildingName){
    for(int i=0;i<buildings.size();i++){
        if(buildings[i]==buildingName){
            return 1;
        }
    }
    return 0;
}

int floorExists(string buildingName,string floorName){
    for(int i=0;i<floors[buildingName].size();i++){
        if(floors[buildingName][i]==floorName){
            return 1;
        }
    }
    return 0;
}

int confRoomExists(string buildingName,string floorName,string roomID){
    for(int i=0;i<confRooms[mp(buildingName,floorName)].size();i++){
        if(confRooms[mp(buildingName,floorName)][i]==roomID)
            return 1;
    }
    return 0;
}
// ADD BUILDING 
void addBuilding(string buildingName){
    buildingName = convertToLowerCase(buildingName);
    if(buildingExists(buildingName)){
        cout<<"This building name already exists! Try adding another building."<<endl;
        return ;
    }
    buildings.push_back(buildingName);
    cout<<buildingName<<" added"<<endl;
}


void addFloor(string buildingName,string floorName){
    buildingName=convertToLowerCase(buildingName);
    floorName=convertToLowerCase(floorName);
    if(!buildingExists(buildingName))   {
        cout<<"Building Doesn't Exist!"<<endl;
        return ;
    }
    if(floorExists(buildingName,floorName)){
        cout<<"This floor name already exists in the building! Try adding another floor."<<endl;
        return ;
    }
    
    floors[buildingName].push_back(floorName);
    cout<<floorName<<" added on "<<buildingName<<endl;
}

void addConfRoom(string buildingName,string floorName,string roomID){
    buildingName=convertToLowerCase(buildingName);
    roomID=convertToLowerCase(roomID);
    floorName=convertToLowerCase(floorName);

    if(!buildingExists(buildingName))   {
        cout<<"Building Doesn't Exist!"<<endl;
        return ;
    }
    if(!floorExists(buildingName,floorName)){
        cout<<"Floor Doesnt Exist!"<<endl;
        return;
    }
    if(confRoomExists(buildingName,floorName,roomID)){
        cout<<"This Conf Room Already Exists"<<endl;
    }
    confRooms[mp(buildingName,floorName)].push_back(roomID);
    cout<<"CONFROOM "<<roomID<<" added on "<<floorName<<" of "<<buildingName<<endl;
}

int checkIfSlotBooked(int st,int en,string uniqueRoomID){
    while(st!=en){
        if(booked[uniqueRoomID+to_string(st)]==1)    return 1;
        st=(st+1)%24;
    }
    return 0;
}

int checkValidTime(int t){
    if(t<0 or t>23) return 0;
    
    return 1;
}

void bookSlot(int st,int en,string buildingName,string floorName,string roomID){
    if(!checkValidTime(st) || !checkValidTime(en)){
        cout<<"INVALID TIME RANGE!"<<endl;
        return;
    }
    buildingName=convertToLowerCase(buildingName);
    floorName=convertToLowerCase(floorName);
    roomID=convertToLowerCase(roomID);

    if(!buildingExists(buildingName)){
        cout<<"Building doesnt exist!"<<endl;
        return ;
    }
    if(!floorExists(buildingName,floorName)){
        cout<<"Floor doesnt exist!"<<endl;
        return ;
    }
    if(!confRoomExists(buildingName,floorName,roomID)){
        cout<<"ConfRoom doesnt exist!"<<endl;
        return ;
    }

    string uniqueRoomID=buildingName+"-"+floorName+"-"+roomID+"-";

    bookedSlots[buildingName+"-"+floorName].push_back({{st,en},roomID});

    if(checkIfSlotBooked(slotSt,slotEnd,uniqueRoomID)){
        cout<<"Slot is already booked"<<endl;
        return ;
    }
    int strt=st;
    while(st!=en){
        booked[uniqueRoomID+to_string(st)]=1;
        st=(st+1)%24;
    }
    cout<<"Congratulations! Your slot is booked from "<<strt<<" to "<<en<<endl;
}

void freeBookedSlots(int st,int en, string buildingName,string floorName,string roomID){
    auto& bookedSlot=bookedSlots[buildingName+"-"+floorName];
    vector<pair<pair<int,int>,string> >::iterator it;
    for (it=bookedSlot.begin();it!=bookedSlot.end();++it){
        if(it->first.first==st and it->first.second==en and it->second==roomID){
            bookedSlot.erase(it);
            break;
        }
    }
    
}

void cancelSlot(int st,int en,string buildingName,string floorName,string roomID){
    if(!checkValidTime(st) || !checkValidTime(en)){
        cout<<"INVALID TIME RANGE!"<<endl;
        return;
    }
    buildingName=convertToLowerCase(buildingName);
    floorName=convertToLowerCase(floorName);
    roomID=convertToLowerCase(roomID);

    if(!buildingExists(buildingName)){
        cout<<"Building doesnt exist!"<<endl;
        return ;
    }
    if(!floorExists(buildingName,floorName)){
        cout<<"Floor doesnt exist!"<<endl;
        return ;
    }
    if(!confRoomExists(buildingName,floorName,roomID)){
        cout<<"ConfRoom doesnt exist!"<<endl;
        return ;
    }

    string uniqueRoomID=buildingName+"-"+floorName+"-"+roomID+"-";
    int strt=st;
    freeBookedSlots(st,en,buildingName,floorName,roomID);
    while(st!=en){
        booked[uniqueRoomID+to_string(st)]=0;
        st=(st+1)%24;
    }
    
    cout<<"Slot from "<<strt<<" to "<<en<<" is successfully cancelled."<<endl;
}

void listBooking(string buildingName,string floorName){
    buildingName=convertToLowerCase(buildingName);
    floorName=convertToLowerCase(floorName);
    string uniqueID=buildingName+"-"+floorName;
    for(auto slot:bookedSlots[uniqueID]){
        cout<<"Booking from "<<slot.first.first<<" "
            <<slot.first.second<<" in "<<slot.second
            <<" on "<<floorName<<" of "<<buildingName<<endl;
    }
}

int main(){
    cout<<"***Conference room reservation system***"<<endl;
    while(1){
        cin>>commandArg1;
        if(commandArg1=="ADD"){
            cin>>commandArg2;
            if(commandArg2=="BUILDING"){
                cin>>buildingName;
                addBuilding(buildingName);
                // printBuildings();
            }
            else if(commandArg2=="FLOOR"){
                cin>>buildingName>>floorName;
                addFloor(buildingName,floorName);
                // printFloor(convertToLowerCase(buildingName));
            }
            else if(commandArg2=="CONFROOM"){
                cin>>buildingName>>floorName>>roomID;
                addConfRoom(buildingName,floorName,roomID);
            }
        }
        else if(commandArg1=="BOOK"){
            cin>>slotSt>>slotEnd>>buildingName>>floorName>>roomID;
            bookSlot(slotSt,slotEnd,buildingName,floorName,roomID);
        }
        else if(commandArg1=="CANCEL"){
            cin>>slotSt>>slotEnd>>buildingName>>floorName>>roomID;
            cancelSlot(slotSt,slotEnd,buildingName,floorName,roomID);
        }
        else if(commandArg1=="LIST"){
            cin>>buildingName>>floorName;
            listBooking(buildingName,floorName);
        }
        else if(commandArg1=="EXIT") return 0;
        else    cout<<"INVALID REQUEST"<<endl;
    }
}