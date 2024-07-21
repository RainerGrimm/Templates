#include <iostream>
#include <chrono>

using namespace std::literals::chrono_literals;

int main(){

  std::cout << '\n';

  constexpr auto schoolHour = 45min;

  constexpr auto shortBreak = 300s;
  constexpr auto longBreak = 0.25h;

  constexpr auto schoolWay = 15min;
  constexpr auto homework = 2h;

  constexpr auto schoolDayInSeconds = 2 * schoolWay + 6 * schoolHour + 4 * shortBreak + longBreak + homework;

  std::cout << "School day in seconds: " << schoolDayInSeconds.count() << '\n';

  constexpr std::chrono::duration<double, std::ratio<3600>> schoolDayInHours = schoolDayInSeconds;
  constexpr std::chrono::duration<double, std::ratio<60>> schoolDayInMinutes = schoolDayInSeconds;
  constexpr std::chrono::duration<double, std::ratio<1, 1000>> schoolDayInMilliseconds= schoolDayInSeconds;

  std::cout << "School day in hours: " << schoolDayInHours.count() << '\n';
  std::cout << "School day in minutes: " << schoolDayInMinutes.count() << '\n';
  std::cout << "School day in milliseconds: " << schoolDayInMilliseconds.count() << '\n';

  std::cout << '\n';

}
