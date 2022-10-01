#include <iomanip>
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <numeric>
#include <string>

const int DAY = 86400;
using namespace std;

struct Reservation
{
    int time;
    string hotel_name;
    int client_id;
    int room_count;

    bool operator <(const Reservation& rhs) const
    {
        return this->time < rhs.time;
    }
};



class HotelManager {
public:
  HotelManager(): current_time(0)
  {}
  void Book(int time, string hotel_name, int client_id, int room_count)
  {
      _bookings.push_back({time, hotel_name, client_id, room_count});
      _rooms[hotel_name] += room_count;

      current_time = time;
      updateData();
  }
  int getClients(string hotel_name)
  {
      set<int> used_id;
      int current_time = this->current_time;
      int count = count_if(_bookings.begin(), _bookings.end(), [&hotel_name, &current_time, &used_id](Reservation& it) {
          return it.hotel_name == hotel_name && current_time - DAY < it.time && it.time <= current_time && used_id.insert(it.client_id).second;
      });
      return count;
  }

  int getRooms(string hotel_name)
  {
      return _rooms[hotel_name];
  }

private:

  deque<Reservation> _bookings;
  int current_time;
  map<string, int> _rooms;

  void updateData()
  {
     while (_bookings.front().time <= current_time - DAY)
     {
        _rooms[_bookings.front().hotel_name] -= _bookings.front().room_count;
        _bookings.pop_front();
     }
  }

};


int main() {
  HotelManager manager;

  int query_count;
  cin >> query_count;

  for (int query_id = 0; query_id < query_count; ++query_id) {
    string query_type;
    cin >> query_type;
    string hotel_name;

    if (query_type == "BOOK") {
      int time;
      cin >> time;
      cin >> hotel_name;
      int client_id;
      cin >> client_id;
      int room_count;
      cin >> room_count;


      manager.Book(time, hotel_name, client_id, room_count);
    } else if (query_type == "CLIENTS") {
      cin >> hotel_name;
      cout  << manager.getClients(hotel_name) << "\n";
    } else if (query_type == "ROOMS") {
      cin >> hotel_name;
      cout  << manager.getRooms(hotel_name) << "\n";
    }
  }

  return 0;
}
