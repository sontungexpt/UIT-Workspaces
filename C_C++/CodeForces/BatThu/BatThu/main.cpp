#include <iomanip>
#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

class Animal {
  int point;
  int percent_rate;

public:
  Animal() {
    point = 0;
    percent_rate = 0;
  }

  Animal(int point, int percent_rate) {
    this->point = point;
    this->percent_rate = percent_rate;
  }

  Animal(const Animal &animal) {
    this->point = animal.point;
    this->percent_rate = animal.percent_rate;
  }

  int get_point() { return point; }

  void set_point(int new_point) { point = new_point; }

  int get_percent_rate() { return percent_rate; }

  void set_percent_rate(int new_percent_rate) {
    percent_rate = new_percent_rate;
  }

  void operator=(const Animal &animal) {
    this->point = animal.point;
    this->percent_rate = animal.percent_rate;
  }

  friend istream &operator>>(istream &is, Animal &animal) {
    // cout << "\nEnter point: ";
    is >> animal.point;
    // cout << "\nEnter percent rate: ";
    cout << "\t";
    is >> animal.percent_rate;
    return is;
  }

  friend ostream &operator<<(ostream &os, Animal &animal) {
    // os << "\nPoint: " << animal.point;
    // os << "\nEnter percent rate: " << animal.percent_rate;
    os << setw(5) << animal.point << "\t" << setw(4) << animal.percent_rate
       << endl;
    return os;
  }

  void random_point(int max, int min) {
    point = rand() % (max - min + 1) + min;
  }

  void random_percent_rate(int max, int min) {
    percent_rate = rand() % (max - min + 1) + min;
  }
};

class GameController {

  int length;
  Animal *animal_list;
  Animal **animal_list_copy_sorted;

public:
  GameController() {
    length = 0;
    animal_list = nullptr;
    animal_list_copy_sorted = nullptr;
  }

  GameController(const GameController &game_controller) {
    length = game_controller.length;
    if (animal_list != nullptr)
      delete[] animal_list;
    animal_list = new Animal[length];
    for (int i = 0; i < length; i++)
      animal_list[i] = game_controller.animal_list[i];
  }

  ~GameController() {
    if (animal_list != nullptr)
      delete[] animal_list;
    if (animal_list_copy_sorted != nullptr)
      delete[] animal_list_copy_sorted;
    length = 0;
  }

  void create_animal_list() {
    while (length > 26 or length < 1) {
      cout << "Enter the numbers of animal object (max: 26, min:1): ";
      cin >> length;
    }
    int max_point = 0;
    while (max_point < 1) {
      cout << "Enter the max point of the animal object: ";
      cin >> max_point;
    }
    srand(time(NULL));
    if (animal_list != nullptr)
      delete[] animal_list;
    animal_list = new Animal[length];
    create_animal_list_point(max_point);
    create_animal_list_rate();
  }

  void print_animal_list() const {
    if (animal_list == nullptr or length == 0)
      cout << "\nAnimal list has never been existed" << endl;
    else
      for (int i = 0; i < length; i++)
        cout << animal_list[i];
  }

  void print_animal_list_sorted_by_point() const {
    if (animal_list_copy_sorted == nullptr or length == 0)
      cout << "\nAnimal list copy has never been existed" << endl;
    else
      for (int i = 0; i < length; i++)
        cout << *animal_list_copy_sorted[i];
  }

private:
  // algorithm

  void sort_animal_list_copy() {
    if (animal_list == nullptr or length == 0)
      cout << "\nCan not sort animal list copy";
    else {
      animal_list_copy_sorted = new Animal *[length];
      for (int i = 0; i < length; i++)
        animal_list_copy_sorted[i] = &animal_list[i];

      for (int i = 0; i < length; i++)
        for (int j = i + 1; j < length; j++)
          if (animal_list_copy_sorted[i]->get_point() >
              animal_list_copy_sorted[j]->get_point()) {
            Animal *temp = animal_list_copy_sorted[i];
            animal_list_copy_sorted[i] = animal_list_copy_sorted[j];
            animal_list_copy_sorted[j] = temp;
          }
    }
  }

  void create_animal_list_point(int max_point) {
    if (animal_list == nullptr or length == 0)
      cout << "Can not create animal list point" << endl;
    else
      for (int i = 0; i < length; i++)
        this->animal_list[i].random_point(max_point, 1);
  }

  void create_animal_list_rate() {
    if (animal_list == nullptr or length == 0)
      cout << "Can not create animal list rate" << endl;
    else {
      sort_animal_list_copy();
      if (length == 1)
        animal_list_copy_sorted[0]->random_percent_rate(100, 1);
      else if (length > 1 and length <= 10) {
        int max_last_rate = floor(100 / length);
        animal_list_copy_sorted[length - 1]->random_percent_rate(max_last_rate,
                                                                 1);
        int sum_rate = animal_list_copy_sorted[length - 1]->get_percent_rate();
        for (int i = length - 2; i >= 0; i--) {
          int relative_rate = ceil(animal_list_copy_sorted[i + 1]->get_point() /
                                   animal_list_copy_sorted[i]->get_point());
          int max = animal_list_copy_sorted[i + 1]->get_percent_rate() *
                        relative_rate +
                    5;
          int min = (animal_list_copy_sorted[i + 1]->get_percent_rate() *
                         relative_rate +
                     animal_list_copy_sorted[i + 1]->get_percent_rate() + 2) /
                    2;
          animal_list_copy_sorted[i]->random_percent_rate(max, min);
          sum_rate += animal_list_copy_sorted[i]->get_percent_rate();
        }
        while (sum_rate < 100) {
          for (int i = 0; i < length; i++) {
            if (sum_rate == 100)
              break;
            animal_list_copy_sorted[i]->set_percent_rate(
                animal_list_copy_sorted[i]->get_percent_rate() + 1);
            sum_rate++;
          }
        }
        int rate_overload = sum_rate - 100;
        while (rate_overload > 0) {
          for (int i = length - 1; i >= 0; i--) {
            if (rate_overload == 0)
              break;
            if (i == length - 1) {
              if (animal_list_copy_sorted[i]->get_percent_rate() > 1) {
                animal_list_copy_sorted[i]->set_percent_rate(
                    animal_list_copy_sorted[i]->get_percent_rate() - 1);
                rate_overload--;
              } else
                continue;
            } else {
              if (animal_list_copy_sorted[i]->get_percent_rate() >
                  animal_list_copy_sorted[i + 1]->get_percent_rate() + 1) {
                animal_list_copy_sorted[i]->set_percent_rate(
                    animal_list_copy_sorted[i]->get_percent_rate() - 1);
                rate_overload--;
              } else
                continue;
            }
          }
        }
      } else {
        int max_last_rate = floor(100 / length);
        animal_list_copy_sorted[length - 1]->random_percent_rate(max_last_rate,
                                                                 1);
        int sum_rate = animal_list_copy_sorted[length - 1]->get_percent_rate();
        for (int i = length - 2; i >= 0; i--) {
          int relative_rate = ceil(animal_list_copy_sorted[i + 1]->get_point() /
                                   animal_list_copy_sorted[i]->get_point());
          int max = animal_list_copy_sorted[i + 1]->get_percent_rate() *
                        relative_rate +
                    5;
          int min = (animal_list_copy_sorted[i + 1]->get_percent_rate() *
                         relative_rate +
                     animal_list_copy_sorted[i + 1]->get_percent_rate() + 2) /
                    2;
          animal_list_copy_sorted[i]->random_percent_rate(max, min);
          sum_rate += animal_list_copy_sorted[i]->get_percent_rate();
        }
        while (sum_rate < 100) {
          for (int i = 0; i < length; i++) {
            if (sum_rate == 100)
              break;
            animal_list_copy_sorted[i]->set_percent_rate(
                animal_list_copy_sorted[i]->get_percent_rate() + 1);
            sum_rate++;
          }
        }
        int rate_overload = sum_rate - 100;
        int rate0 = 0;
        while (rate_overload > 0) {
          for (int i = length - 1; i >= 0; i--) {
            if (rate_overload == 0)
              break;
            if (i == length - 1) {
              if (animal_list_copy_sorted[i]->get_percent_rate() > 0) {
                animal_list_copy_sorted[i]->set_percent_rate(
                    animal_list_copy_sorted[i]->get_percent_rate() - 1);
                rate_overload--;
                if (animal_list_copy_sorted[i]->get_percent_rate() == 0)
                  rate0++;
              } else
                continue;
            } else {
              if (rate0 < length / 2) {
                if (animal_list_copy_sorted[i]->get_percent_rate() > 0) {
                  animal_list_copy_sorted[i]->set_percent_rate(
                      animal_list_copy_sorted[i]->get_percent_rate() - 1);
                  rate_overload--;
                  if (animal_list_copy_sorted[i]->get_percent_rate() == 0)
                    rate0++;
                } else
                  continue;
              } else {
                if (animal_list_copy_sorted[i]->get_percent_rate() >
                    animal_list_copy_sorted[i + 1]->get_percent_rate() + 1) {
                  animal_list_copy_sorted[i]->set_percent_rate(
                      animal_list_copy_sorted[i]->get_percent_rate() - 1);
                  rate_overload--;
                } else
                  continue;
              }
            }
          }
        }
      }
    }
  }

  int sum_rate() {
    int sum = 0;
    for (int i = 0; i < length; i++)
      sum += animal_list_copy_sorted[i]->get_percent_rate();
    return sum;
  }
};

int main() {
  int n;

  GameController game_controller;
  game_controller.create_animal_list();
  cout << endl << "A random list animal: " << endl;
  cout << "Point"
       << "\t"
       << "Rate" << endl;
  game_controller.print_animal_list();
  cout << endl << endl;
  cout << "A sorted list animal by point: " << endl;
  cout << "Point"
       << "\t"
       << "Rate" << endl;
  game_controller.print_animal_list_sorted_by_point();

  return 0;
}
