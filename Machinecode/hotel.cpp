#include<bits/stdc++.h>
using namespace std;
// user: three types of user-> guest,receptionist and admin
class Guest{
    public:
    string name;
    string email;
    long long mobile;
    Guest(string name,string email,long long mobile){
        this->name=name;
        this->email=email;
        this->mobile=mobile;
    }

};
class Room{
    public:
    int roomno;
    string type;
    bool available;
    Room(int roomno,string type,bool available){
        this->roomno=roomno;
        this->type=type;
        this->available=true;
    }
    void bookroom(){
        available=false;
    }
    void releaseroom(){
        available=true;
    }

};
class booking{
     public:
     Guest* guest;
     Room* room;
     string checkindate;
     string checkoutdate;
     bool ispaid;
     booking(Guest* guest,Room* room,string checkindate,string checkoutdate,bool ispaid){
        this->guest=guest;
        this->room=room;
        this->checkindate=checkindate;
        this->checkoutdate=checkoutdate;
        this->ispaid=false;
     }
     void confirmbooking(){
        if(room->available){
            room->bookroom();
            cout << "Booking confirmed for " << guest->name << " in Room " << room->roomno<< endl;
        }
        else{
            cout<<"room is not available"<<endl;
        }
     }
     void cancelbooking(){
        room->releaseroom();
        cout<< "Booking is cancelled for " << guest->name <<endl;
     }

};
class Payment{
    public:
    booking* Booking;
    double amount;
    string status;
    
    Payment(booking* Booking, double amount) {
        this->Booking = Booking;
        this->amount = amount;
        this->status = "Pending";
    }
    void completepayment(){
        status="Completed";
        Booking->ispaid= true;
        cout<<"payment of $" << amount << " completed for Room " << Booking->room->roomno << endl;

        }

    };
    class Hotel {
        public:
            string name;
            vector<Room*> rooms;
            vector<booking*> bookings;
        
            Hotel(string name) {
                this->name = name;
            }
        
            void addRoom(Room* room) {
                rooms.push_back(room);
            }
        
            void checkAvailability() {
                cout << "Available Rooms: ";
                for (Room* room : rooms) {
                    if (room->available)
                        cout << room->roomno << " ";
                }
                cout << endl;
            }
        
            booking* bookRoom(Guest* guest, int roomno, string checkindate, string checkoutdate,bool ispaid) {
                for (Room* room : rooms) {
                    if (room->roomno == roomno && room->available) {
                        booking* newBooking = new booking(guest, room, checkindate, checkoutdate,ispaid);
                        newBooking->confirmbooking();
                        bookings.push_back(newBooking);
                        return newBooking;
                    }
                }
                cout << "Room not available!\n";
                return nullptr;
            }
            booking* cancelroom(Guest* guest, int roomno) {
                for (booking* b : bookings) {
                    if (b->guest == guest && b->room->roomno == roomno) {
                        b->cancelbooking();
                        return b;
                    }
                    cout << "No active booking found for Guest: " << guest->name << " in Room " << roomno << endl;
                }
                return nullptr;  
            }
            
        };

        int main() {
            // Create hotel
            Hotel myHotel("Grand Plaza");
        
            // Add rooms
            Room* room1 = new Room(101, "Deluxe",true);
            Room* room2 = new Room(102, "Suite",true);
            myHotel.addRoom(room1);
            myHotel.addRoom(room2);
        
            // Check available rooms
            myHotel.checkAvailability();
        
            // Create a guest
            Guest* guest1 = new Guest("Alice", "alice@example.com",1234567890);
        
            // Book a room
            booking* booking1 = myHotel.bookRoom(guest1, 101, "2025-02-25", "2025-02-28",false);
    
            // Complete Payment
            if (booking1) {
                Payment* payment1 = new Payment(booking1, 5000);
                payment1->completepayment();
            }
        
            // Check available rooms after booking
            booking* booking2 = myHotel.cancelroom(guest1, 102);
            myHotel.checkAvailability();
        
            return 0;
        } 
        
        