#include <iomanip>
#include <iostream>
#include <set>
#include <vector>
#include <utility>

using namespace std;

class ReadingManager {
public:
  ReadingManager()
      : pages_(MAX_USER_COUNT_ + 1, -1), pages_rating_(1000 + 1, 0) {}

  void Read(int user_id, int page_count) {

    if (users_.insert(user_id).second)
    {
        for (int i = 1; i <= page_count; ++i)
            ++pages_rating_[i];
    }
    else
    {
        int temp = pages_[user_id];
        if (temp != -1)
        {
            for (int i = temp + 1; i <= page_count; ++ i)
                ++pages_rating_[i];
        }
    }
    pages_[user_id] = page_count;
  }

  double Cheer(int user_id) const {

      if (users_.size() == 1 && users_.find(user_id) != users_.end()) //ЕСЛИ ПОЛЬЗОВАТЕЛЬ НА ДАННЫЙ МОМЕНТ ЕДИНСТВЕННЫЙ
          return 1;
      if (pages_[user_id] == -1)
          return 0;                                                   //ЕСЛИ ДЛЯ ПОЛЬЗОВАТЕЛЯ НЕ БЫЛО СОБЫТИЯ READ

      size_t page_rate = pages_rating_[pages_[user_id]];

      return 1 - ((page_rate * 1.0 - 1) / ((users_.size() - 1) * 1.0));
  }

private:
  // Статическое поле не принадлежит какому-то конкретному
  // объекту класса. По сути это глобальная переменная,
  // в данном случае константная.
  // Будь она публичной, к ней можно было бы обратиться снаружи
  // следующим образом: ReadingManager::MAX_USER_COUNT.
  static const int MAX_USER_COUNT_ = 100'000;

  vector<int> pages_;
  set<int> users_; // позиции в векторе sorted_users_
  vector<size_t> pages_rating_;


};


int main() {
  ReadingManager manager;

  int query_count;
  cin >> query_count;

  for (int query_id = 0; query_id < query_count; ++query_id) {
    string query_type;
    cin >> query_type;
    int user_id;
    cin >> user_id;

    if (query_type == "READ") {
      int page_count;
      cin >> page_count;
      manager.Read(user_id, page_count);
    } else if (query_type == "CHEER") {
      cout << setprecision(6) << manager.Cheer(user_id) << "\n";
    }
  }

  return 0;
}
